#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char OS;
#define windows (OS) 1
#define mac (OS) 2

OS getOS(int argc, char **argv) {
    if(argc == 1) return mac;
    if(!strcmp("windows", argv[1])) return windows;
    if(!strcmp("mac", argv[1])) return mac;
    return 0;
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
    
    system("cd internal && gcc -c ../main.c && gcc -o testInner testInner.c main.o");

    char *cmd = (os == windows) ? "cd internal && testInner.exe" : "./internal/testInner";
    system(cmd);

    return 0;
}