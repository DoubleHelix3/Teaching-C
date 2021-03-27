#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILEIO 0

char *readFile(char *filePath) {
    FILE* filePointer;
    int bufferLength = 500;
    char *buffer = malloc(500);
    *buffer = 0;

    filePointer = fopen(filePath, "r");

    while(fgets(buffer, bufferLength, filePointer));

    fclose(filePointer);
    return buffer;
}

void clearFile(char *filePath) {
    FILE *fp = fopen(filePath, "w");
    fclose(fp);
}