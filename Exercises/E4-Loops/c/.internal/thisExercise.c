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

#define NUM_TEST_CASES 3
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){randomInRange(1,15)};
    testCases[1] = (Input){randomInRange(15,32)};
    testCases[2] = (Input){randomInRange(-10,0)};
    return testCases;
}

typedef struct {
    int fib;
} Output;
//#define OUTPUT_VOID

bool areOutputsEqual(Output a, Output b) {
    return a.fib == b.fib;
}

// user functions
int fibonacci(int n);

Output runUserCode(Input input) {
    return (Output){fibonacci(input.n)};
}

Output getCorrectOutput(Input input) {
    int a=1;
    int b=1;
    for(int i=0; i<input.n; i++) {
        int c = a + b;
        a=b;
        b=c;
    }
    return (Output){a};
}

char *getCorrectPrint(Input input) {
    return "";
}

void printInput(Input input) {
    printf("\n   x: %d\n", input.n);
}

void printOutput(Output output) {
    printf("%d\n", output.fib);
}

#include "../../../../.apex/testInner.h"
