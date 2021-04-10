#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    int age;       
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 7
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){2};
    testCases[1] = (Input){14};
    testCases[1] = (Input){17};
    testCases[2] = (Input){20};
    testCases[3] = (Input){42};
    testCases[3] = (Input){64 };    
    testCases[4] = (Input){-1};
    testCases[5] = (Input){420};
    return testCases;
}

#define OUTPUT_VOID

// user functions
void printLegalActivities(int age);
void printLifeStage(int age);

void runUserCode(Input input) {
    printLifeStage(input.age);
    printLegalActivities(input.age);
}

char *getCorrectPrint(Input input) {
    int age = input.age;
    if(age<0) return "How are you a negative age?\nHow are you a negative age?\n";
    if(age>120) 
    return "How are you older than the oldest person alive!\nHow are you older than the oldest person alive!\n";
    
    char *printBuffer = malloc(50);
    *printBuffer = 0;
    if(age<3) strcat(printBuffer, "You are a baby owo\n");
    else if(age<13) strcat(printBuffer, "You are a child :)\n");
    else if(age<20) strcat(printBuffer, "You are a teenager\n");
    else if(age<49) strcat(printBuffer, "You are an adult! -.-\n");
    if(age>49) strcat(printBuffer, "You are old :(\n");

    if(age>=16) strcat(printBuffer, "You can drive!\n");
    if(age>=18) strcat(printBuffer, "You can vote!\n");
    if(age>=21) strcat(printBuffer, "You can drink!\n");
    
    return printBuffer;
}

void printInput(Input input) {
    printf("%d\n", input.age);
}

#include "../../../../.apex/testInner.h"
