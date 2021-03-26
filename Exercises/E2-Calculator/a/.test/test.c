#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *defaultExecutable(OS os) {
    char *name = "a";

    char *result = malloc(50);
    *result = 0;
    if(os == windows) {
        strcat(result, name);
        strcat(result, ".exe");
    }
    
    if(os == mac) {
        strcat(result, "./");
        strcat(result, name);
        strcat(result, ".out");
    }

    return result;
}

char *executable(OS os, char *name) {
    char *result = malloc(50);
    *result = 0;
    if(os == windows) {
        strcat(result, name);
        strcat(result, ".exe");
    }
    
    if(os == mac) {
        strcat(result, "./");
        strcat(result, name);
    }

    return result;
}

char *defaultCompiler(OS os) {
    return (os == windows) ? "gcc" : "clang";
}

// =====================================================

#include <time.h>

void setRandomSeed() {
    srand(time(0));
}

int randomInRange(int min, int max) {
    return rand()%(max-min+1) + min;
}

// =====================================================

char *readOutputFile() {
    FILE *fp;
    char *buff = malloc(255);
    *buff = 0;

    fp = fopen(".test/output.txt", "r");

    fgets(buff, 255, (FILE*)fp);
    printf("%s\n", buff );

    fclose(fp);
    return buff;
}

// =====================================================

int main() {
    OS os = getOS();
    if(!os) return 1;

    char *cmd = malloc(100);
    *cmd = 0;
    sprintf(cmd, "%s > .test/output.txt", defaultExecutable(os));

    printf("\nyour output: \n");
    system(cmd);
    
    char *output = readOutputFile();
    
    *cmd = 0;
    char *comp = defaultCompiler(os);
    sprintf(cmd, "%s -c main.c && %s -o temp .test/testInner.c main.o && ", comp, comp);
    concat(cmd, executable(os, "temp"));
    char *inputToTest = malloc(50);
    sprintf(inputToTest, " \"%s\"", output);
    concat(cmd, inputToTest);
    system(cmd);
    
    return 0;
}