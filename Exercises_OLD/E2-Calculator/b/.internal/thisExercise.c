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
    testCases[0] = (Input){randomInRange(0,300), randomInRange(1,20)};
    return testCases;
}

typedef struct {
    int quotientTrunc;
    int remainder; 
} Output;
//#define OUTPUT_VOID

bool areOutputsEqual(Output a, Output b) {
    return a.quotientTrunc == b.quotientTrunc && a.remainder == b.remainder;
}

// user functions
int truncatedDivision(int x, int y);
int remainderAfterDivision(int x, int y);
void printDivisionWithRemainder(int x, int y);

Output runUserCode(Input input) {
    int x = input.x; int y = input.y;
    printDivisionWithRemainder(x,y);
    return (Output){truncatedDivision(x,y), remainderAfterDivision(x,y)};
}

Output getCorrectOutput(Input input) {
    int x = input.x; int y = input.y;
    return (Output){x/y, x%y};
}

char *getCorrectPrint(Input input) {
    int x = input.x; int y = input.y;
    char *buffer = malloc(2+3+2+2);
    sprintf(buffer, "%d r %d\n", x/y, x%y);
    return buffer;
}

void printInput(Input input) {
    printf("\n    x: %d \n    y: %d\n", input.x, input.y);
}

void printOutput(Output output) {
    printf("\n    truncated quotient: %d\n    remainder: %d\n", output.quotientTrunc, output.remainder);
}

#include "../../../../.apex/testInner.h"
