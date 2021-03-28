#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

#define INPUT_VOID

#define NUM_TEST_CASES 1

#define OUTPUT_VOID

// user functions
void hello();

void runUserCode() {
    hello();
}

char *getCorrectPrint() {
    return "Hello World!\n";
}

#include "../../../../.apex/testInner.h"
