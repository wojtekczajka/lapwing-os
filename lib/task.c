#include "task.h"

void run_task(char* task_name) {
    int fd = open_file(task_name);
    close_file(fd);
    int pid = fork();
    if (pid == 0) 
        exec(task_name);
    else 
        waitu(pid);
}