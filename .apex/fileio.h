#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILEIO 0

char *readFile(char *filePath) {
    FILE *f = fopen(filePath, "rt");
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = (char *) malloc(length + 1);
    buffer[length] = '\0';
    fread(buffer, 1, length, f);
    fclose(f);
    return buffer;
}

void clearFile(char *filePath) {
    FILE *fp = fopen(filePath, "w");
    fclose(fp);
}