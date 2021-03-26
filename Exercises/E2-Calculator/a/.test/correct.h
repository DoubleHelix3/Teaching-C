#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printb(x) strcat(printBuffer, x);

void correctMain(char *printBuffer) {
    printb("Hello World!\n");
}