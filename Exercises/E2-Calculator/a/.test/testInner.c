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

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);

int main() {
    setRandomSeed();

    int x = randomInRange(1,100);
    int y = randomInRange(1,100);

    // change standard out to output.txt
    freopen(".test/output.txt", "a+", stdout);
    int sumOut = add(x,y);
    int diffOut = subtract(x,y);
    int multOut = multiply(x,y);
    freopen("CON", "w", stdout); 

    //char *output = readOutputFile();

    //char *correctOut = malloc(1000);
    //*correctOut = 0;
    //correct(correctOut);
    
    printf("\ninput: \nx=%d\ny=%d\n", x, y);

    if(sumOut == x+y && diffOut == x-y && multOut == x*y) {
        printf("\noutput: \nx+y=%d\nx-y=%d\nx*y=%d\n", sumOut, diffOut, multOut);
        printf("\nsuccess!\n\n");
    } else {
        printf("\nyour output: \nx+y=%d\nx-y=%d\nx*y=%d\n", sumOut, diffOut, multOut);
        printf("\ncorrect output: \nx+y=%d\nx-y=%d\nx*y=%d\n", x+y, x-y, x*y);
        printf("\nwrong!\n\n");
    }

    return 0;
}