#include <stdio.h>
#include <stdlib.h>

// TODO add support for different OS
int main(int argc, char **argv) {
    printf("\nOutput: \n");
    system("./a.out");
    printf("\n\nCorrect Output: \n");
    system("clang solution solution.c && ./solution");
    printf("\n\n");
}