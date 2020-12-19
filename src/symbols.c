#include "symbols.h"

extern void xPortSysTickHandler(void);

void IntSysTickHandler(void) {
    xPortSysTickHandler();
} /* IntSysTickHandler() */

void xWaitMicro(uint32_t wait) {
    WAITRTOS_ChronoMicro(wait);
} /* xWaitMicro() */

void xWaitMs(uint32_t time) {
    WAITRTOS_Ms(time);
} /* xWaitMs() */

uint32_t xWaitElapsed(uint32_t time) {
    return WAITRTOS_Elapsed(pdMS_TO_TICKS(time));
} /* xWaitElapsed() */

void * xMalloc(size_t size) {
    return pvPortMalloc(size);
} /* xMalloc() */

void xFree(void * ptr) {
    vPortFree(ptr);
} /* xFree() */
