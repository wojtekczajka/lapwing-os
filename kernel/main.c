#include "file.h"
#include "memory.h"
#include "print.h"
#include "process.h"
#include "syscall.h"
#include "trap.h"

extern char bss_start;
extern char bss_end;

void KMain(void) {
    uint64_t size = (uint64_t)&bss_end - (uint64_t)&bss_start;
    memset(&bss_start, 0, size);

    init_idt();
    init_memory();
    init_kvm();
    init_system_call();
    init_fs();
    init_process();
}