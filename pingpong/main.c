#include "lib.h"

int main(void) {
    int counter = 0;
    printf("PINGPONG process started...\n");
    while (counter != 10) {
        if (counter % 2)
            run_task("PONG");
        else
            run_task("PING");
        ++counter;
    }
    printf("PINGPONG process stoped...\n");
    return 0;
}