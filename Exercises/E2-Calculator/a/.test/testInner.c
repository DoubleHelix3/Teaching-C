#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

typedef char OS;
#define windows (OS) 1
#define mac (OS) 2

OS getOS() {
    #ifdef _WIN32
        return windows;
    #elif __APPLE__
        return mac;
    #else
        return 0;
        printf("YOUR OS IS NOT SUPPORTED\n")
    #endif
}

// =====================================================

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
    int old_stdout = dup(1);
    FILE *fp1 = freopen(".test/output.txt", "a+", stdout);
    int sumOut = add(x,y);
    int diffOut = subtract(x,y);
    int multOut = multiply(x,y);
    {
        OS os = getOS();
        if(os == windows) freopen("CON", "w", stdout); 
        else {
            fclose(stdout);
            FILE *fp2 = fdopen(old_stdout, "w");
            *stdout = *fp2;                       // Unreliable!

        }
    }
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