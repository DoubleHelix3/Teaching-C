#include <stdio.h>

/* function syntax:
ReturnType functionName(Input1Type input1Name, Input2Type input2Name, ...) {
  ...
  return ...
}
*/

// examples
int add(int x, int y) {
  return x+y;
}

int multiply(int x, int y) {
  return x*y;
}

// void means the function doesn't return anything
void printSum(int x, int y) {
  printf("x+y=%d", x+y);
}

int twice(int x) {
  return 2*x;
}

int main() {
  printf("4+5=%d\n", add(4,5)); // will print out 4+5=9
  printf("4*5%d\n", multiply(4,5)); // will print out 4*5=20
  printSum(4,5); // will print out x+y=9
  printf("%d\n", twice(4)); // will print out 8
  
  return 0;
}
