#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    int x;
    int y;
    float x1;
    float y1;
    float x2;
    float y2;            
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 8
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){
        randomInRange(0,100), randomInRange(0,100),
        randomFloatInRange(0.0f,100.0f), randomFloatInRange(0.0f,100.0f),
        randomFloatInRange(0.0f,100.0f), randomFloatInRange(0.0f,100.0f),
    };
    testCases[1] = (Input){
        randomInRange(-100,0), randomInRange(0,100),
        randomFloatInRange(-100.0f,0.0f), randomFloatInRange(0.0f,100.0f),
        randomFloatInRange(0.0f,100.0f), randomFloatInRange(0.0f,100.0f),
    };
    testCases[2] = (Input){
        randomInRange(-100,0), randomInRange(-100,0),
        randomFloatInRange(0.0f,100.0f), randomFloatInRange(-100.0f,0.0f),
        randomFloatInRange(0.0f,100.0f), randomFloatInRange(-100.0f,0.0f),
    };
    testCases[3] = (Input){
        0, 0,
        0.0f, 0.0f,
        randomFloatInRange(100.0f,0.0f), randomFloatInRange(-100.0f,0.0f),
    };
    testCases[4] = (Input){
        randomInRange(-100,100), randomInRange(-100,100),
        randomFloatInRange(-100.0f,0.0f), 0.0f,
        randomFloatInRange(-100.0f,0.0f), randomFloatInRange(-100.0f,0.0f),
    };
    testCases[5] = (Input){
        randomInRange(-100,100), randomInRange(-100,100),
        randomFloatInRange(-100.0f,100.0f), randomFloatInRange(-100.0f,100.0f),
        randomFloatInRange(-100.0f,100.0f), randomFloatInRange(-100.0f,100.0f),
    };
    testCases[6] = (Input){
        randomInRange(-100,100), randomInRange(-100,100),
        randomFloatInRange(-100.0f,100.0f), randomFloatInRange(-100.0f,100.0f),
        randomFloatInRange(-100.0f,100.0f), randomFloatInRange(-100.0f,100.0f),
    };
    testCases[7] = (Input){
        randomInRange(-100,100), randomInRange(-100,100),
        randomFloatInRange(-100.0f,100.0f), randomFloatInRange(-100.0f,100.0f),
        randomFloatInRange(-100.0f,100.0f), randomFloatInRange(-100.0f,100.0f),
    };
    return testCases;
}

typedef struct {
    bool negative;
    bool sameSign;
    bool sameQuadrant;
} Output;
//#define OUTPUT_VOID

bool areOutputsEqual(Output a, Output b) {
    return a.negative == b.negative && a.sameSign == b.sameSign && a.sameQuadrant == b.sameQuadrant;
}

// user functions
bool isNegative(int x);
bool areSameSign(int x, int y);
bool areSameQuadrant(float x1, float y1, float x2, float y2);

Output runUserCode(Input input) {
    return (Output){isNegative(input.x), areSameSign(input.x,input.y), 
    areSameQuadrant(input.x1, input.y1, input.x2, input.y2)};
}

Output getCorrectOutput(Input input) {
    float x1 = input.x1; float y1=input.y1; float x2=input.x2; float y2=input.y2;
    return (Output){input.x<0, (input.x<0 && input.y<0) || (input.x>0 && input.y>0) || (input.x==0 && input.y==0),
    ((x1>0 && x2>0) || (x1<0 && x2<0)) && ((y1>0 && y2>0) || (y1<0 && y2<0))};
}

char *getCorrectPrint(Input input) {
    return "";
}

void printInput(Input input) {
    printf("\n   x: %d\n   y: %d\n   point 1: (%f, %f)\n   point 2: (%f, %f)\n", 
    input.x, input.y, input.x1, input.y1, input.x2, input.y2);
}

void printOutput(Output output) {
    printf("\n   x is negative: %s\n   x and y are the same sign: %s\n   the points are in the same quadrant: %s\n", 
    output.negative ? "true" : "false", output.sameSign ? "true" : "false", output.sameQuadrant ? "true" : "false");
}

#include "../../../../.apex/testInner.h"
