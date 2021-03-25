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
    return (os == windows) ? "a.exe" : "./a.out";
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

#define printB(x) strcat(printBuffer, x)
void correctMain(char *printBuffer) {
    printB("Hello World!");
}

int main() {
    OS os = getOS();
    if(!os) return 1;

    char *cmd = malloc(50);
    *cmd = 0;
    sprintf(cmd, "%s > .test/output.txt", defaultExecutable(os));

    printf("\nyour output: ");
    system(cmd);

    char *output = readOutputFile();
    
    char *correct = malloc(1000);
    *correct = 0;
    correctMain(correct);
    
    if(!strcmp(output, correct)) {
        printf("\nsuccess!\n\n");
    } else {
        printf("\ncorrect output: %s\n", correct);
        printf("\nwrong!\n\n");
    }

    return 0;
}