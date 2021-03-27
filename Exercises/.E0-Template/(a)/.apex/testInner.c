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

typedef float Output;

void printInput(Input input) {
    printf("x=%f, y=%f\n", input.x, input.y);
}

void printOutput(Output output) {
    printf("%f", (float) output);
}

char *getCorrectOutput(Input input) {
    if(input.x==0) {
        return "cannot divide by 0\n";
    }
    return "";
}

char *getOutput() {
    char *result = readFile(".apex/output.txt");
    clearFile(".apex/output.txt");
    return result;
}

Output getResult(Input input) {
    return divide(input.x, input.y);
}

Output getCorrectResult(Input input) {
    if(input.y==0) {
        return 0;
    }
    return input.x/input.y;
}

void test(Input input, char *output, char* correctOutput, Output result, Output correctResult, int testCaseNo, bool printInColor) {
    
    bool passed = true;

    if(printInColor)
        printf("\033[35;106m test case %d:\033[m\n", testCaseNo);
    else
        printf(" test case %d:\n", testCaseNo);

    printf(" > input: ");
    printInput(input);

    if(result != correctResult) {
        printf(" > your result: ");
        printOutput(result);
        printf("\n > correct result: ");
        printOutput(correctResult);
        printf("\n\n");
        passed = false;
    }

    if(strcmp(output, correctOutput)) {
        char *extraNewLine = (!strcmp(correctOutput, "")) ? "\n" : "";
        printf(" > your output: \n    %s\n > correct output: \n    %s\n%s", output, correctOutput, extraNewLine);
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
        Output result = getResult(input);
        if(os == mac)
            freopen("/dev/tty", "a", stdout);
        else if(os == windows)
            freopen("CON", "w", stdout);
        
        char *output = getOutput();
        char *correctOutput = getCorrectOutput(input);
        Output correctResult = getCorrectResult(input);

        // windows sucks
        test(input, output, correctOutput, result, correctResult, i, os==mac);
    }

    return 0;
}