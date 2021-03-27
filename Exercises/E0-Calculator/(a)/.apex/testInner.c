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

char *getCorrectOutput(float x, float y) {
    if(y==0) {
        return "cannot divide by 0\n";
    }
    return "";
}

char *getOutput(float x, float y) {
    char *result = readFile(".apex/output.txt");
    clearFile(".apex/output.txt");
    return result;
}

float getCorrectResult(float x, float y) {
    if(y==0) {
        return 0;
    }
    return x/y;
}

// user function
float divide(float x, float y);

void test(float x, float y, char *output, char* correctOutput, float result, float correctResult, int testCaseNo, bool printInColor) {
    
    bool passed = true;

    if(printInColor)
        printf("\033[35;106m test case %d:\033[m\n", testCaseNo);
    else
        printf(" test case %d:\n", testCaseNo);

    printf(" > input: x=%f, y=%f\n", x, y);

    if(result != correctResult) {
        printf(" > your result: %f\n > correct result: %f \n\n", result, correctResult);
        passed = false;
    }

    if(strcmp(output, correctOutput)) {
        char *extraNewLine = (!strcmp(correctOutput, "")) ? "\n" : "";
        printf(" > your output: \n    %s\n > correct output: \n    %s\n%s", output, correctOutput, extraNewLine);
        passed = false;
    }

    // windows sucks
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
    int i;
    for(i=1; i<=3; i++) {
        float x = randomFloatInRange(0,100);
        float y = i==3 ? 0.0f : randomFloatInRange(0,100);
        
        freopen(".apex/output.txt", "a", stdout);
        float result = divide(x,y);
        if(os == mac)
            freopen("/dev/tty", "a", stdout);
        else if(os == windows)
            freopen("CON", "w", stdout);
        
        char *output = getOutput(x,y);
        char *correctOutput = getCorrectOutput(x,y);
        float correctResult = getCorrectResult(x,y);

        // windows sucks
        test(x, y, output, correctOutput, result, correctResult, i, os==mac);
    }

    return 0;
}