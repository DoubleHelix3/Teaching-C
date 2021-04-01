#include <stdio.h>

// while loop
void printNums1() {
    int i=1;
    while(i<=100) {
        printf("%d\n", i);
        i++;
    }
}

// for loop
void printNums2() {
    for(int i=0; i<=100; i++) {
        printf("%d\n", i);
    }
}

// recursive solution
void printNums3(int i, int n) {
    if(i>n) {
        return;
    }
    printf("%d\n", i);
    printNums3(i+1, n);
}

int main() {
    printNums1();
    printNums2();
    printNums3(1,100);
    return 0;
}
