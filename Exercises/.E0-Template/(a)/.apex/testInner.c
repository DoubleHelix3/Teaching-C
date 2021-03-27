#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "os.h"
#include "fileio.h"

#include <time.h>
void setRandomSeed() {srand(time(0));}
int randomInRange(int min, int max) {return rand()%(max-min+1) + min;}
float randomFloatInRange(float min, float max) {
    return (float)rand()/(float)(RAND_MAX/(max-min)) + min;
}

// user function
float divide(float x, float y);

typedef struct {
    float x;
    float y;
} Input;
//#define INPUT_VOID

typedef float Output;
//#define OUTPUT_VOID

Output getOutput(Input input) {
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
    char *result = readFile(".apex/output.txt");
    clearFile(".apex/output.txt");
    return result;
}

void printInput(Input input) {
    printf("x=%f, y=%f\n", input.x, input.y);
}

void printOutput(Output output) {
    printf("%f", (float) output);
}

void printTestCase(Input input, Output output, Output correctOutput, char *print, char* correctPrint, int testCaseNo, bool printInColor) {
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

    printf("\n");
    for(int i=1; i<=3; i++) {
        float x = randomFloatInRange(0,100);
        float y = i==3 ? 0.0f : randomFloatInRange(0,100);
        Input input = {x,y};

        freopen(".apex/output.txt", "a", stdout);
        Output output = getOutput(input);
        if(os == mac)
            freopen("/dev/tty", "a", stdout);
        else if(os == windows)
            freopen("CON", "w", stdout);

        Output correctOutput = getCorrectOutput(input);
        char *print = getPrint();
        char *correctPrint = getCorrectPrint(input);
        
        // windows sucks
        printTestCase(input, output, correctOutput, print, correctPrint, i, os==mac);
    }

    return 0;
}