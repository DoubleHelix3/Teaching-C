#include <stdio.h>

int main(int argc, char **argv) {
    int a = 1;
    int b = 1;
    for(int i=0; i<40; i++) {
        printf("%d\n", a);
        int c = a+b;
        a=b;
        b=c;
    }
}