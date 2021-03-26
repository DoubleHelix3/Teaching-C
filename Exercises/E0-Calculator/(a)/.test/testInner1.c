#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "os.h"
#include "fileio.h"

#include <time.h>
void setRandomSeed() {srand(time(0));}
int randomInRange(int min, int max) {return rand()%(max-min+1) + min;}
float randomFloatInRange(float min, float max) {
    return (float)rand()/(float)(RAND_MAX/(max-min)) + min;
}

void putRandomInputIn(float *x, float *y) {
    *x = randomFloatInRange(0,100);
    *y = randomFloatInRange(0,100);
}

char *correctOutput(float x, float y) {
    if(y==0) {
        return "y is 0";
    }
    return "";
}

char *userOutput(float x, float y) {
    return "ooga";
}

float correctResult(float x, float y) {
    if(y==0) {
        return 0;
    }
    return x/y;
}

// user function
float divide(float x, float y);

int main() {
    float x; float y;
    putRandomInputIn(&x, &y);
    char *out = userOutput(x,y);
    char *correctOut = correctOutput(x,y);
    float result = divide(x,y);
    float correctRes = correctResult(x,y);

    

    return 0;
}