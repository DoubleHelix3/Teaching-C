#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define print(x) strcat(printBuffer, x)
void correctProgram(char *printBuffer) {
    print("Hello World!");
}



typedef char OS;
#define windows (OS) 1
#define mac (OS) 2

OS getOS(int argc, char **argv) {
    if(argc == 1) return mac;
    if(!strcmp("windows", *argv)) return windows;
    if(!strcmp("windows", *argv)) return mac;
    return 0;
}

char *readFile() {
    FILE *fp;
    char *buff = malloc(255);

    fp = fopen("internal/output.txt", "r");

    fgets(buff, 255, (FILE*)fp);
    printf("%s\n", buff );

    fclose(fp);
    return buff;
}

int random(int min, int max) {
    return rand()%(max-min) + min;
}

int main(int argc, char **argv) {
    OS os = getOS(argc, argv);
    if(!os) {
        printf("Not a valid os");
        return 1;
    }

    char *executable = (os == windows) ? "a.exe" : "./a.out";

    char *cmd = malloc(50);
    sprintf(cmd, "%s > internal/output.txt", executable);

    printf("\nyour output:\n");
    system(cmd);

    char *output = readFile();
    
    char *correct = malloc(500);
    *correct = 0;
    correctProgram(correct);
    
    if(!strcmp(output, correct)) {
        printf("\nSuccess!\n\n");
    } else {
        printf("\ncorrect output: \n%s\n", correct);
        printf("\nWrong!\n\n");
    }

    return 0;
}