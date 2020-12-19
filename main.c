#include "FreeRTOS.h"
#include "task.h"

#include "idda.h"

int main(void) {
    IDDA();
    vTaskStartScheduler();
	return 0;
} /* main() */

//*****************************************************************************
//
// This hook is called by FreeRTOS when an stack overflow error is detected.
//
//*****************************************************************************
void vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName) {
    //
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    //
    (void) pxTask;
    (void) pcTaskName;

    while(1);
}
