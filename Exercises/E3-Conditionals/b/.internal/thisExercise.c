#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    bool a;
    bool b;       
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 4
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){false, false};
    testCases[1] = (Input){false, true};
    testCases[2] = (Input){true, false};
    testCases[3] = (Input){true, true};
    return testCases;
}

typedef struct {
    bool xor;
    bool nand;
    bool implies;
} Output;
//#define OUTPUT_VOID

bool areOutputsEqual(Output a, Output b) {
    return a.xor == b.xor && a.nand == b.nand && a.implies == b.implies ;
}

// user functions
bool xor(bool a, bool b);
bool nand(bool a, bool b);
bool implies(bool a, bool b);

Output runUserCode(Input input) {
    bool a = input.a; bool b = input.b;
    return (Output){xor(a,b), nand(a,b), implies(a,b)};
}

Output getCorrectOutput(Input input) {
    bool a = input.a; bool b = input.b;
    return (Output){(a&&!b) || (!a&&b), !(a&&b), !a||b};
}

char *getCorrectPrint(Input input) {
    return "";
}

void printInput(Input input) {
    printf("\n   a: %s\n   b: %s\n", input.a ? "true" : "false", input.b ? "true" : "false");
}

void printOutput(Output output) {
    printf("\n   a xor b: %s\n   a nand b: %s\n   a=>b: %s\n", 
    output.xor ? "true" : "false", output.nand ? "true" : "false", output.implies ? "true" : "false");
}

#include "../../../../.apex/testInner.h"
