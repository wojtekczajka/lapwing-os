#include "debug.h"
#include "file.h"
#include "print.h"

void EMain(void) {
    init_fs();
    ASSERT(load_file("KERNEL.BIN", 0x200000) == 0);
    ASSERT(load_file("USER.BIN", 0x30000) == 0);
}
