#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "os.h"
#include "fileio.h"

#define outputFilePath ".internal/output.txt"

char *getPrint() {
    char *result = readFile(outputFilePath);
    clearFile(outputFilePath);
    return result;
}


// Printing in color only works on mac for now
// This is sort of a dumb way to do this, but it's fineeeee
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
    #ifndef OUTPUT_VOID
    bool isOutputCorrect = areOutputsEqual(output, correctOutput);
    passed &= isOutputCorrect;
    #endif
    bool isPrintCorrect = !strcmp(print, correctPrint);
    passed &= isPrintCorrect;

    {
        char *extraNewLine = (passed) ? "":"\n";
        if(printInColor) printf("\033[35;106m test case %d:\033[m%s", testCaseNo, extraNewLine);
        else printf(" test case %d:\n", testCaseNo);
    }

    #ifndef INPUT_VOID
    if(!passed) {
        printf(" > input: ");
        printInput(input);
    }
    #endif

    #ifndef OUTPUT_VOID
    if(!isOutputCorrect) {
        printf(" > your output: ");
        printOutput(output);
        printf("\n > correct output: ");
        printOutput(correctOutput);
        printf("\n\n");
        passed = false;
    }
    #endif

    if(!isPrintCorrect) {
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
        #ifndef INPUT_VOID
        char *correctPrint = getCorrectPrint(input);
        #else
        char *correctPrint = getCorrectPrint();
        #endif

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
        printTestCase(print, correctPrint, i+1, os==mac);
        #endif
        #endif
    }

    return 0;
}
