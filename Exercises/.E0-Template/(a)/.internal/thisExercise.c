#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../.apex/fileio.h"
#include "../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    float x;
    float y;
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 3
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){randomFloatInRange(0,100), randomFloatInRange(0,100)};
    testCases[1] = (Input){randomFloatInRange(0,100), randomFloatInRange(0,100)};
    testCases[2] = (Input){0.0f                     , randomFloatInRange(0,100)};
    return testCases;
}

typedef float Output;
//#define OUTPUT_VOID

// user functions
float divide(float x, float y);

Output runUserCode(Input input) {
    return divide(input.x, input.y);
}

Output getCorrectOutput(Input input) {
    if(input.y==0) {
        return 0;
    }
    return input.x/input.y;
}

char *getCorrectPrint(Input input) {
    if(input.x==0) {
        return "cannot divide by 0\n";
    }
    return "";
}

char *getPrint() {
    char *result = readFile(outputFilePath);
    clearFile(outputFilePath);
    return result;
}

void printInput(Input input) {
    printf("x=%f, y=%f\n", input.x, input.y);
}

void printOutput(Output output) {
    printf("%f", (float) output);
}

#include "../../../.apex/testInner.h"
