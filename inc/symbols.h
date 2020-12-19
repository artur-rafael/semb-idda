#ifndef __SYMBOLS_H__
#define __SYMBOLS_H__

#include <stdint.h>

#include "wait.h"
#include "waitRTOS.h"

void IntSysTickHandler(void);

void xWaitMicro(uint32_t wait);
void xWaitMs(uint32_t time);
uint32_t xWaitElapsed(uint32_t time);

void * xMalloc(size_t size);
void xFree(void * ptr);

#endif /* __SYMBOLS_H__ */
