#ifndef _LIB_H_
#define _LIB_H_

#include "lib.h"

int open_file(char* name);
void close_file(int fd);
int fork(void);
void exec(char* name);
void waitu(int pid);
void run_task(char* task_name);

#endif