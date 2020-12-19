#ifndef __IDDA_H__
#define __IDDA_H__

#include <stdbool.h>

#include "led.h"

#include "rtcRTOS.h"
#include "waitRTOS.h"
#include "keypadRTOS.h"
#include "lcdRTOS.h"
#include "i2cRTOS.h"
#include "tmp101RTOS.h"

#include "distanceRTOS.h"

#define IDDA_STACK_SIZE             (configMINIMAL_STACK_SIZE * 2)
#define IDDA_TASK_PRIORITY          (tskIDLE_PRIORITY + 1)

#define IDDA_DISPLAY_UPDATE_MS      pdMS_TO_TICKS(250)

#define IDDA_HOLD_UPDATE_MS         pdMS_TO_TICKS(100)

#define IDDA_DATE_TIME_PARAMETERS   3

#define IDDA_DEGREE_SYMBOL          0xDF

#define IDDA_TIME_DATE_DISPLAY_MS   5000

#define IDDA_DEFAULT_MAX_TEMP       26
#define IDDA_DEFAULT_MAX_DIST       10

#define IDDA_DAY_DDRAM              1
#define IDDA_MONTH_DDRAM            4
#define IDDA_YEAR_DDRAM             9

#define IDDA_HOUR_DDRAM             13
#define IDDA_MINUTE_DDRAM           16
#define IDDA_SECONDS_DDRAM          19

#define IDDA_MAX_TEMP_DDRAM         9
#define IDDA_MAX_DIST_DDRAM         9

#define IDDA_L                      KEYPAD_3_PRESS
#define IDDA_R                      KEYPAD_F_PRESS

#define IDDA_INC                    KEYPAD_2_PRESS
#define IDDA_INC_HOLD               KEYPAD_2_HOLD
#define IDDA_INC_RELEASE            KEYPAD_2_RELEASE

#define IDDA_DEC                    KEYPAD_1_PRESS
#define IDDA_DEC_HOLD               KEYPAD_1_HOLD
#define IDDA_DEC_RELEASE            KEYPAD_1_RELEASE

#define IDDA_ENTER                  KEYPAD_E_PRESS

#define IDDA_DATE_SETUP             KEYPAD_7_PRESS
#define IDDA_TIME_SETUP             KEYPAD_8_PRESS
#define IDDA_DIST_LIMIT             KEYPAD_9_PRESS
#define IDDA_TEMP_LIMIT             KEYPAD_D_PRESS

#define IDDA_START_OPERATION        KEYPAD_A_PRESS
#define IDDA_SHOW_LAST_ALARM        KEYPAD_B_PRESS
#define IDDA_SHOW_TIME              KEYPAD_C_PRESS

typedef struct {
    uint8_t ddram;
    int * parameterValue;
} IDDA_ParameterSetup;

void IDDA(void);

#endif /* __IDDA_H__ */
