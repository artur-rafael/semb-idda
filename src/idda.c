#include <idda.h>

/***************************** Global Variables *****************************/

static int32_t temperature;
static int32_t maxTemperature = IDDA_DEFAULT_MAX_TEMP;

static int32_t distance;
static int32_t maxDistance = IDDA_DEFAULT_MAX_DIST;

static struct tm dateTime, lastAlarm;
static struct tm * dT;

static const IDDA_ParameterSetup setupDate[IDDA_DATE_TIME_PARAMETERS] = { {IDDA_DAY_DDRAM, &dateTime.tm_mday},
                                                                          {IDDA_MONTH_DDRAM, &dateTime.tm_mon},
                                                                          {IDDA_YEAR_DDRAM, &dateTime.tm_year}
                                                                        };

static const IDDA_ParameterSetup setupTime[IDDA_DATE_TIME_PARAMETERS] = { {IDDA_HOUR_DDRAM, &dateTime.tm_hour},
                                                                          {IDDA_MINUTE_DDRAM, &dateTime.tm_min},
                                                                          {IDDA_SECONDS_DDRAM, &dateTime.tm_sec}
                                                                        };

/*************************** Functions Signatures ***************************/

static void IDDA_Init(void);
static void IDDA_Task(void * pvParameters);

static void IDDA_FirstSetup(void);

static void IDDA_EditDateTimeParameters(const IDDA_ParameterSetup * setup);
static void IDDA_EditMaxParameter(int32_t * parameter, void (*printFunc)(void));

static void IDDA_PrintDateTime(const struct tm * dtTm);
static void IDDA_PrintTempDist(int32_t * temp, int32_t * dist);

static void IDDA_DisplayDateTime(uint32_t displayTimeMs);
static void IDDA_DisplayMaxTemp(void);
static void IDDA_DisplayMaxDist(void);
static void IDDA_DisplayLastAlarm(void);

static void IDDA_SetLastAlarm(void);

/****************************************************************************/
/********************************* Functions ********************************/
/****************************************************************************/

void IDDA() {
    IDDA_Init();
} /* IDDA() */

/****************************************************************************/
/***************************** Static Functions *****************************/
/****************************************************************************/

static void IDDA_Init(void) {
    LED_Init();

    WAITRTOS_Init();
    RTCRTOS_Init();
    I2CRTOS_Init(I2C2);
    TMP101RTOS_Init();

    xTaskCreate(IDDA_Task, "IDDATask", IDDA_STACK_SIZE, NULL, IDDA_TASK_PRIORITY, NULL);

    DISTANCERTOS_Init();

    KEYPADRTOS_Init();
    LCDRTOS_Init();
} /* IDDA_Init() */

static void IDDA_Task(void * pvParameters) {
    IDDA_FirstSetup();

    uint32_t event = KEYPAD_NO_EVENT;

    while(true) {
        temperature = (int32_t) TMP101RTOS_GetTemperature();
        distance = DISTANCERTOS_GetDistance();
        IDDA_PrintTempDist(&temperature, &distance);

        if(temperature >= maxTemperature || distance <= maxDistance) {
            LED_SetColor(RED);
            IDDA_SetLastAlarm();
        } else {
            LED_SetColor(OFF);
        }

        if(!KEYPADRTOS_GetEvent(&event, IDDA_DISPLAY_UPDATE_MS))
            continue;

        switch(event) {
             case IDDA_DATE_SETUP:
                 LED_SetColor(BLUE);
                 IDDA_EditDateTimeParameters(setupDate);
                 LED_SetColor(OFF);
                 break;
             case IDDA_TIME_SETUP:
                 LED_SetColor(GREEN);
                 IDDA_EditDateTimeParameters(setupTime);
                 LED_SetColor(OFF);
                 break;
             case IDDA_TEMP_LIMIT:
                 LED_SetColor(WHITE);
                 IDDA_EditMaxParameter(&maxTemperature, &IDDA_DisplayMaxTemp);
                 LED_SetColor(OFF);
                 break;
             case IDDA_DIST_LIMIT:
                 LED_SetColor(YELLOW);
                 IDDA_EditMaxParameter(&maxDistance, &IDDA_DisplayMaxDist);
                 LED_SetColor(OFF);
                 break;
             case IDDA_SHOW_LAST_ALARM:
                 IDDA_DisplayLastAlarm();
                 break;
             case IDDA_SHOW_TIME:
                 IDDA_DisplayDateTime(IDDA_TIME_DATE_DISPLAY_MS);
                 break;
             default:
                 break;
        }
    }
} /* IDDA_Task() */

static void IDDA_FirstSetup(void) {
    uint32_t event = KEYPAD_NO_EVENT;
    bool setupDone = false;

    while(!setupDone) {
        dT = RTCRTOS_GetDateAndTime();
        IDDA_DisplayDateTime(0);

        if(!KEYPADRTOS_GetEvent(&event, IDDA_DISPLAY_UPDATE_MS))
            continue;

        switch(event) {
            case IDDA_DATE_SETUP:
                LED_SetColor(BLUE);
                IDDA_EditDateTimeParameters(setupDate);
                LED_SetColor(OFF);
                break;
            case IDDA_TIME_SETUP:
                LED_SetColor(GREEN);
                IDDA_EditDateTimeParameters(setupTime);
                LED_SetColor(OFF);
                break;
            case IDDA_START_OPERATION:
                setupDone = true;
            default:
                break;
        }
    }
} /* IDDA_FirstSetup() */

static void IDDA_EditDateTimeParameters(const IDDA_ParameterSetup * setup) {
    dT = RTCRTOS_GetDateAndTime();
    IDDA_PrintDateTime(dT);
    memcpy(&dateTime, dT, sizeof(struct tm));

    LCDRTOS_SetCursor(setup[0].ddram);
    LCDRTOS_Cursor(CURSOR_ON);

    uint32_t event = KEYPAD_NO_EVENT;
    int8_t parameter = 0;
    bool done = false;

    while(!done) {
        KEYPADRTOS_GetEvent(&event, IDDA_HOLD_UPDATE_MS);

        switch(event) {
            case IDDA_L:
                if(--parameter == -1)
                    parameter = IDDA_DATE_TIME_PARAMETERS - 1;
                break;
            case IDDA_R:
                if(++parameter == IDDA_DATE_TIME_PARAMETERS)
                    parameter = 0;
                break;
            case IDDA_INC_HOLD:
            case IDDA_INC:
                ++*setup[parameter].parameterValue;
                break;
            case IDDA_DEC_HOLD:
            case IDDA_DEC:
                --*setup[parameter].parameterValue;
                break;
            case IDDA_ENTER:
                done = true;
                break;
            default:
                break;
        }

        if(event != IDDA_INC_HOLD && event != IDDA_DEC_HOLD)
            event = KEYPAD_NO_EVENT;

        mktime(&dateTime);
        IDDA_PrintDateTime(&dateTime);
        LCDRTOS_SetCursor(setup[parameter].ddram);
    }

    RTCRTOS_SetDateAndTime(&dateTime);
    LCDRTOS_Cursor(CURSOR_OFF);
} /* IDDA_EditParameters() */

static void IDDA_EditMaxParameter(int32_t * parameter, void (*printFunc)(void)) {
    uint32_t event = KEYPAD_NO_EVENT;
    bool done = false;

    printFunc();
    LCDRTOS_Cursor(CURSOR_ON);

    while(!done) {
        KEYPADRTOS_GetEvent(&event, portMAX_DELAY);

        switch(event) {
            case IDDA_INC:
            case IDDA_INC_HOLD:
                ++*parameter;
                break;
            case IDDA_DEC:
            case IDDA_DEC_HOLD:
                --*parameter;
                break;
            case IDDA_ENTER:
                done = true;
                break;
            default:
                break;
        }

        printFunc();
    }
    LCDRTOS_Cursor(CURSOR_OFF);
} /* IDDA_EditMaxTemp() */

static void IDDA_PrintDateTime(const struct tm * dtTm) {
    LCDRTOS_Clear();
    LCDRTOS_Home();
    LCDRTOS_Printf("%02d-%02d-%04d  %02d:%02d:%02d", dtTm->tm_mday,
                                                     dtTm->tm_mon + 1,
                                                     dtTm->tm_year + 1900,
                                                     dtTm->tm_hour,
                                                     dtTm->tm_min,
                                                     dtTm->tm_sec);
} /* IDDA_PrintDateTime() */

static void IDDA_PrintTempDist(int32_t * temp, int32_t * dist) {
    LCDRTOS_Clear();
    LCDRTOS_Home();
    LCDRTOS_CenteredPrintf("%02d%cC %02dcm", *temp, IDDA_DEGREE_SYMBOL, *dist);
} /* IDDA_PrintTempDist() */

static void IDDA_DisplayDateTime(uint32_t displayTimeMs) {
    uint32_t timeStamp = WAITRTOS_Elapsed(0);
    uint32_t event;

    while(WAITRTOS_Elapsed(timeStamp) <= displayTimeMs) {
        dT = RTCRTOS_GetDateAndTime();
        IDDA_PrintDateTime(dT);
        vTaskDelay(IDDA_DISPLAY_UPDATE_MS);
    }

    while(KEYPADRTOS_GetEvent(&event, 0));
} /* IDDA_DisplayDateTime() */

static void IDDA_DisplayMaxTemp(void) {
    LCDRTOS_Clear();
    LCDRTOS_Home();
    LCDRTOS_CenteredPrintf("%02d%cC", maxTemperature, IDDA_DEGREE_SYMBOL);
    LCDRTOS_SetCursor(IDDA_MAX_TEMP_DDRAM);
} /* IDDA_DisplayMaxTemp() */

static void IDDA_DisplayMaxDist(void) {
    LCDRTOS_Clear();
    LCDRTOS_Home();
    LCDRTOS_CenteredPrintf("%02dcm", maxDistance);
    LCDRTOS_SetCursor(IDDA_MAX_DIST_DDRAM);
} /* IDDA_DisplayMaxDist() */

static void IDDA_DisplayLastAlarm(void) {
    uint32_t event;
    LCDRTOS_Clear();

    //TODO: Implement EEPROM
    IDDA_PrintDateTime(&lastAlarm);

    vTaskDelay(IDDA_TIME_DATE_DISPLAY_MS);
    while(KEYPADRTOS_GetEvent(&event, 0) == true);
} /* IDDA_DisplayLastAlarm() */

static void IDDA_SetLastAlarm(void) {
    //TODO: Implement EEPROM

    dT = RTCRTOS_GetDateAndTime();
    memcpy(&lastAlarm, dT, sizeof(struct tm));
} /* IDDA_SetLastAlarm() */
