#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    int n;
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 1
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){randomInRange(5,25)};
    return testCases;
}

#define OUTPUT_VOID

// user functions
void printNumbers(int n);

void runUserCode(Input input) {
    printNumbers(input.n);
}

char *getCorrectPrint(Input input) {
    char *buffer = malloc(1000);
    *buffer = 0;
    char *temp = malloc(10);
    for(int i=1; i<input.n; i++) {
        sprintf(temp, "%d, ", i);
        strcat(buffer, temp);
    }
    sprintf(temp, "%d\n", input.n);
    strcat(buffer, temp);
    return buffer;
}

void printInput(Input input) {
    printf("\n   n: %d\n", input.n);
}

#include "../../../../.apex/testInner.h"
