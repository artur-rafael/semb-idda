#ifndef __DISTANCE_RTOS_H__
#define __DISTANCE_RTOS_H__

#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "FreeRTOS.h"
#include "task.h"

#define DISTANCE_RTOS_STACK_SIZE        (configMINIMAL_STACK_SIZE * 2)
#define DISTANCE_RTOS_TASK_PRIORITY     (tskIDLE_PRIORITY + 1)

#define DISTANCE_RTOS_TASK_DELAY        50

#define DISTANCE_RTOS_DEFAULT_DISTANCE  20

void DISTANCERTOS_Init(void);
uint32_t DISTANCERTOS_GetDistance(void);

#endif /* __DISTANCE_RTOS_H__ */
