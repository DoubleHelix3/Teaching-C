#include <stdlib.h>
#include <time.h>
void setRandomSeed() {srand(time(0));}
int randomInRange(int min, int max) {return rand()%(max-min+1) + min;}
float randomFloatInRange(float min, float max) {
    return (float)rand()/(float)(RAND_MAX/(max-min)) + min;
}