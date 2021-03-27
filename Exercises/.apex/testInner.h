#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "os.h"

#define outputFilePath ".internal/output.txt"

/*
#include <time.h>
void setRandomSeed() {srand(time(0));}
int randomInRange(int min, int max) {return rand()%(max-min+1) + min;}
float randomFloatInRange(float min, float max) {
    return (float)rand()/(float)(RAND_MAX/(max-min)) + min;
}

typedef struct {
    float x;
    float y;
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 3
Input *generateTestCases() {
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){randomFloatInRange(0,100), randomFloatInRange(0,100)};
    testCases[1] = (Input){randomFloatInRange(0,100), randomFloatInRange(0,100)};
    testCases[2] = (Input){0.0f                     , randomFloatInRange(0,100)};
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
*/

// Printing in color only works on mac for now
#ifndef INPUT_VOID
#ifndef OUTPUT_VOID
void printTestCase(Input input, Output output, Output correctOutput, char *print, char* correctPrint, int testCaseNo, bool printInColor) {
#else
void printTestCase(Input input, char *print, char* correctPrint, int testCaseNo, bool printInColor) {
#endif
#else
#ifndef OUTPUT_VOID
void printTestCase(Output output, Output correctOutput, char *print, char* correctPrint, int testCaseNo, bool printInColor) {
#else
void printTestCase(char *print, char* correctPrint, int testCaseNo, bool printInColor) {
#endif
#endif

    bool passed = true;

    if(printInColor)
        printf("\033[35;106m test case %d:\033[m\n", testCaseNo);
    else
        printf(" test case %d:\n", testCaseNo);

    #ifndef INPUT_VOID
    printf(" > input: ");
    printInput(input);
    #endif

    #ifndef OUTPUT_VOID
    if(output != correctOutput) {
        printf(" > your output: ");
        printOutput(output);
        printf("\n > correct output: ");
        printOutput(correctOutput);
        printf("\n\n");
        passed = false;
    }
    #endif

    if(strcmp(print, correctPrint)) {
        char *extraNewLine = (!strcmp(correctPrint, "")) ? "\n" : "";
        printf(" > what you printed: \n    %s\n > what you should've printed: \n    %s\n%s", print, correctPrint, extraNewLine);
        passed = false;
    }

    if(printInColor) {
        if(passed) printf("\033[35;5;%dm%s\033[m", 32, "  success!");
        else printf("\033[35;5;%dm%s\033[m", 31, "  failed!");
    } else {
        if(passed) printf("  success!");
        else printf("  failed!");
    }

    printf("\n\n\n");;
}

int main() {
    OS os = getOS();

    #ifndef INPUT_VOID
    Input* testCases = generateTestCases();
    #endif

    printf("\n");
    for(int i=0; i<NUM_TEST_CASES; i++) {
        #ifndef INPUT_VOID
        Input input = testCases[i];
        #endif

        freopen(outputFilePath, "a", stdout);
        
        #ifndef INPUT_VOID
        #ifndef OUTPUT_VOID
        Output output = runUserCode(input);
        #else
        runUserCode(input);
        #endif
        #else
        #ifndef OUTPUT_VOID
        Output output = runUserCode();
        #else
        runUserCode();
        #endif
        #endif

        if(os == mac)
            freopen("/dev/tty", "a", stdout);
        else if(os == windows)
            freopen("CON", "w", stdout);

        #ifndef INPUT_VOID
        #ifndef OUTPUT_VOID
        Output correctOutput = getCorrectOutput(input);
        #else
        getCorrectOutput(input);
        #endif
        #else
        #ifndef OUTPUT_VOID
        Output correctOutput = getCorrectOutput();
        #endif
        #endif

        char *print = getPrint();
        char *correctPrint = getCorrectPrint(input);
        
        #ifndef INPUT_VOID
        #ifndef OUTPUT_VOID
        printTestCase(input, output, correctOutput, print, correctPrint, i+1, os==mac);
        #else
        printTestCase(input, print, correctPrint,  i+1, os==mac) {
        #endif
        #else
        #ifndef OUTPUT_VOID
        printTestCase(output, correctOutput, print, correctPrint, i+1, os==mac) {
        #else
        printTestCase(print, correctPrint, i+1, os==mac) {
        #endif
        #endif
    }

    return 0;
}
