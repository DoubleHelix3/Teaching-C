#include <stdio.h>

int main(int argc, char **argv) {
    int prev2 = 1;
    int prev1 = 1;
    for(int i=0; i<40; i++) {
        printf("%d\n", prev2);
        int c = prev1+prev2;
        prev2=prev1;
        prev1=c;
    }
}