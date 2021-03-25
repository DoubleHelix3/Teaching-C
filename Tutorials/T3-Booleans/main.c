#include <stdio.h>
// for booleans
#include <stdbool.h>

// 0 means false
// 1 means true
// any other integer means true

void groundWet(bool isRaining) {
  if(isRaining) {
    printf("the ground is wet!\n");
  }
}

void ageRestriction(int age) {
  // < means less than
  // <= means less than or equal to 
  if(age < 18) {
    printf("you're a child that can't do much");
  } else if(age < 21) {
    printf("you're an adult, but can't drink!");
  } else if (age > 0) {
    printf("wow you're an adult who can drink");
  } else {
    printf("how tf do you have a negative age");
  }
}

void printQuotient(float x, float y) {
  // == means equal to
  if(y==0.0f) {
    printf("cannot divide by 0\n");
  } else {
    printf("x/y=%f\n", x/y);
  }
}

bool isInQuadrantI(int x, int y) {
  // && means and
  return x>0 && y>0;
}

bool areSameSign(int x, int y) {
  bool areBothPositive = x>0 && y>0;
  bool areBothNegative = x<0 && y<0;
  bool areBothZero = x==0 && y==0;
  // || means or
  return areBothPositive || areBothNegative || areBothZero;
}

void groundDry(bool isRaining) {
  // ! means not
  if(!isRaining) {
    printf("ground is dry!\n");
  }
}

int main() {
  groundWet(false);
  groundWet(true);
  groundDry(false);
  groundDry(true);
  
  ageRestriction(5);
  ageRestriction(19);
  ageRestriction(24);
  ageRestriction(-1);
  
  printQuotient(3.0f, 2.0f);
  printQuotient(1.0f, 0.0f);
  
  printf("%d\n%d\n", areSameSign(2,4), areSameSign(-1,2));
  
  return 0;
}
