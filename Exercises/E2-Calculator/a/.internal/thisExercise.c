#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    int x;
    int y;
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 1
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){randomInRange(0,100), randomInRange(0,100)};
    return testCases;
}

typedef struct {
    int sum;
    int difference;
    int product;  
} Output;
//#define OUTPUT_VOID

bool areOutputsEqual(Output a, Output b) {
    return a.sum == b.sum && a.difference == b.difference && a.product == b.product;
}

// user functions
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);

Output runUserCode(Input input) {
    int x = input.x; int y = input.y;
    return (Output){add(x,y), subtract(x,y), multiply(x,y)};
}

Output getCorrectOutput(Input input) {
    int x = input.x; int y = input.y;
    return (Output){x+y, x-y, x*y};
}

char *getCorrectPrint(Input input) {
    return "";
}

void printInput(Input input) {
    printf("\n   x: %d \n   y: %d\n", input.x, input.y);
}

void printOutput(Output output) {
    printf("\n   sum: %d\n   difference: %d\n   product: %d\n", output.sum, output.difference, output.product);
}

#include "../../../../.apex/testInner.h"
