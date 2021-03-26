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

char *rm(OS os) {
    return (os == windows) ? "del" : "rm";
}

char *defaultCompiler(OS os) {
    return (os == windows) ? "gcc" : "clang";
}

int main() {
    OS os = getOS();
    if(!os) return 1;
    
    char *cmd = malloc(200);
    *cmd = 0;
    strcat(cmd, "echo s > .test/output.txt");
    system(cmd);

    *cmd = 0;
    char *comp = defaultCompiler(os);
    sprintf(cmd, "%s -c main.c && %s -o temp .test/testInner.c main.o && ", comp, comp);
    strcat(cmd, executable(os, "temp"));
    system(cmd);

    *cmd = 0;
    sprintf(cmd, "%s main.o && %s temp.exe", rm(os), rm(os));
    system(cmd);

    return 0;
}