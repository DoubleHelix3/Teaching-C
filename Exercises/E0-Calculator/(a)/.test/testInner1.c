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

char *correctOutput(float x, float y) {
    if(y==0) {
        return "y is 0";
    }
    return "";
}

char *userOutput(float x, float y) {
    char *result = readFile(".test/output.txt");
    clearFile(".test/output.txt");
    return result;
}

float correctResult(float x, float y) {
    if(y==0) {
        return 0;
    }
    return x/y;
}

// user function
float divide(float x, float y);

void test(float x, float y, float result, int testCaseNo) {
    char *out = userOutput(x,y);
    char *correctOut = correctOutput(x,y);
    float correctRes = correctResult(x,y);

    bool passed = true;
    printf("\033[35;106m test case %d:\033[m\n", testCaseNo);
    printf(" > input: x=%f, y=%f\n", x, y);

    if(result != correctRes) {
        printf(" > your result: %f\n > correct result: %f \n", result, correctRes);
        passed = false;
    }

    if(strcmp(out, correctOut)) {
        printf(" > your output: \n    %s\n > correct output: \n    %s\n%s", out, correctOut, 
        (*correctOut == 0) ? "" : "\n"
        );
        passed = false;
    }

    if(passed) 
        printf("\033[35;5;%dm%s\033[m", 32, "  success!");
    else 
        printf("\033[35;5;%dm%s\033[m", 31, "  failed!");
    
    printf("\n\n\n");;
}

int main() {
    printf("\n");

    int i;
    for(i=1; i<3; i++) {
        float x = randomFloatInRange(0,100); 
        float y = randomFloatInRange(0,100);
        test(x, y, divide(x,y), i);
    }

    test(randomFloatInRange(0,100), 0.0f, 0, i++);

    return 0;
}