#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define print(x) strcat(printBuffer, x)
void correctProgram(char *printBuffer) {
    print("Hello World!");
}

typedef char OS;
#define windows (OS) 1
#define mac (OS) 2

OS getOS(int argc, char **argv) {
    if(argc == 1) return mac;
    if(!strcmp("windows", argv[1])) return windows;
    if(!strcmp("mac", argv[1])) return mac;
    return 0;
}

char *readFile() {
    FILE *fp;
    char *buff = malloc(255);
    *buff = 0;

    fp = fopen("internal/output.txt", "r");

    fgets(buff, 255, (FILE*)fp);
    printf("%s\n", buff );

    fclose(fp);
    return buff;
}

int random(int min, int max) {
    return rand()%(max-min+1) + min;
}

int main(int argc, char **argv) {
    OS os = getOS(argc, argv);
    if(!os) {
        printf("NOT A VALID OS");
        return 1;
    }

    char *executable = (os == windows) ? "a.exe" : "./a.out";

    char *cmd = malloc(50);
    *cmd = 0;
    sprintf(cmd, "%s > internal/output.txt", executable);

    printf("\nyour output: ");
    system(cmd);

    char *output = readFile();
    
    char *correct = malloc(500);
    *correct = 0;
    correctProgram(correct);
    
    if(!strcmp(output, correct)) {
        printf("\nsuccess!\n\n");
    } else {
        printf("\ncorrect output: %s\n", correct);
        printf("\nwrong!\n\n");
    }

    return 0;
}