#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

void setRandomSeed() {
    srand(time(0));
}

int randomInRange(int min, int max) {
    return rand()%(max-min+1) + min;
}

// =====================================================

char *readOutputFile() {
    FILE* filePointer;
    int bufferLength = 500;
    char *buffer = malloc(500);

    filePointer = fopen(".test/output.txt", "r");

    while(fgets(buffer, bufferLength, filePointer));

    fclose(filePointer);
    return buffer;
}

// =====================================================

void sayHello();

#define printb(x) strcat(printBuffer, x);
void correct(char *printBuffer) {
    printb("Hello World!\n");
}

int main() {
    // change standard out to output.txt
    freopen(".test/output.txt", "a+", stdout); 
    sayHello();
    freopen("CON", "w", stdout); 

    char *output = readOutputFile();

    char *correctOut = malloc(1000);
    *correctOut = 0;
    correct(correctOut);
    
    if(!strcmp(output, correctOut)) {
        printf("\noutput: \n%s", output);
        printf("\nsuccess!\n\n");
    } else {
        printf("\nyour output: \n%s", output);
        printf("\ncorrect output: \n%s", correctOut);
        printf("\nwrong!\n\n");
    }

    return 0;
}