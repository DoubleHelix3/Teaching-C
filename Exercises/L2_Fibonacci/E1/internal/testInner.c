#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "main.h"

int correctFunction(int n) {
    int a = 1;
    int b = 1;
    for(int i=1; i<n; i++) {
        int c = a+b;
        a=b;
        b=c;
    }

    return a;
}



int random(int min, int max) {
    return rand()%(max-min+1) + min;
}

int main(int argc, char **argv) {
    srand(time(0));

    bool works = true;
    for(int i=1; i<=3; i++) {
        printf("\ntest %d\n", i);
        int input = random(1,40);
        printf("input: %d\n", input);
        int output = fibonacci(input);
        int correct = correctFunction(input);
        printf("your output: %d\n", output);
        printf("correct output: %d\n", correct);
        works &= output == correct;
    }

    if(works) printf("\nsuccess!\n\n");
    else printf("\nwrong!\n\n");
    return 0;
}