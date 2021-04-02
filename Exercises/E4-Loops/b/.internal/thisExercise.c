#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    char *str;
    int n;
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 1
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    char *strs[2];
    strs[0] = "helloooo";
    strs[1] = "echooo";
    testCases[0] = (Input) {strs[randomInRange(0,1)], randomInRange(3,10)};
    return testCases;
}

#define OUTPUT_VOID

// user functions
void echo(char *str, int n);

void runUserCode(Input input) {
    echo(input.str, input.n);
}

char *getCorrectPrint(Input input) {
    char *buffer = malloc(1000);
    *buffer = 0;
    for(int i=0; i<input.n-1; i++) {
        strcat(buffer, input.str);
        strcat(buffer, " ");
    }
    strcat(buffer, input.str);
    strcat(buffer, "\n");
    return buffer;
}

void printInput(Input input) {
    printf("\n   string: %s\n   echo number: %d\n", input.str, input.n);
}

#include "../../../../.apex/testInner.h"
