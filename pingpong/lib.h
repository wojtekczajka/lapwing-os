#ifndef _LIB_H_
#define _LIB_H_

#include "stdint.h"

int printf(const char* format, ...);
void sleepu(uint64_t ticks);
void run_task(char* task_name);

#endif