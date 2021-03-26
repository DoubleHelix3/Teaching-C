
char *readFile(char *filePath) {
    FILE* filePointer;
    int bufferLength = 500;
    char *buffer = malloc(500);

    filePointer = fopen(filePath, "r");

    while(fgets(buffer, bufferLength, filePointer));

    fclose(filePointer);
    return buffer;
}