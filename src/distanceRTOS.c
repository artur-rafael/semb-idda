#include "distanceRTOS.h"

/***************************** Global Variables *****************************/

static uint32_t distance = DISTANCE_RTOS_DEFAULT_DISTANCE;

/*************************** Functions Signatures ***************************/

static void DISTANCERTOS_Task(void * pvParameters);

/****************************************************************************/
/********************************* Functions ********************************/
/****************************************************************************/

void DISTANCERTOS_Init(void) {
    xTaskCreate(DISTANCERTOS_Task, "DistanceTask", DISTANCE_RTOS_STACK_SIZE, NULL, DISTANCE_RTOS_TASK_PRIORITY, NULL);
} /* DISTANCERTOS_Init() */

uint32_t DISTANCERTOS_GetDistance(void) {
    return distance;
} /* DISTANCERTOS_GetDistance() */

/****************************************************************************/
/***************************** Static Functions *****************************/
/****************************************************************************/

static void DISTANCERTOS_Task(void * pvParameters) {
    // SW1(Distance Decrement) -> PF4
    // SW2(Distance Increment) -> PF0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0x4C4F434B;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;

    GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_DIR_MODE_IN);

    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    uint32_t portState, portOldState;

    while(true) {
        portState = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);

        if(portState != portOldState) {
            portOldState = portState;

            if ((portState & GPIO_PIN_0) == 0) {
                ++distance;
            } else if((portState & GPIO_PIN_4) == 0) {
                --distance;
            }
        }

        vTaskDelay(pdMS_TO_TICKS(DISTANCE_RTOS_TASK_DELAY));
    }
} /* DISTANCERTOS_Task() */
