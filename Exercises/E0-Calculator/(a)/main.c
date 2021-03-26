#include <stdio.h>

float divide(float x, float y) {
    if(y==0) {
        printf("y is 0\n");
        return 0.0f;
    }

    return x/y;
}