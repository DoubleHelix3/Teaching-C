#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../../../.apex/random.h"

#define outputFilePath ".internal/output.txt"

typedef struct {
    double triangleBase;
    double triangleHeight;
    double circleRadius;
    double ellipseA;
    double ellipseB;
    double sphereRadius;
} Input;
//#define INPUT_VOID

#define NUM_TEST_CASES 1
Input *generateTestCases() {
    setRandomSeed();
    Input *testCases = malloc(NUM_TEST_CASES*sizeof(Input));
    testCases[0] = (Input){
        randomDoubleInRange(0.0,100.0), randomDoubleInRange(0.0,100.0),
        randomDoubleInRange(0.0,100.0),
        randomDoubleInRange(0.0,100.0), randomDoubleInRange(0.0,100.0),
        randomDoubleInRange(0.0,100.0)
    };

    if(testCases[0].ellipseB > testCases[0].ellipseA) {
        double aOld = testCases[0].ellipseA;
        testCases[0].ellipseA = testCases[0].ellipseB;
        testCases[0].ellipseB = aOld;
    }
    
    return testCases;
}

typedef struct {
    double triangleArea;
    double circumference;
    double circleArea;
    double ellipseArea;
    double sphereVolume;
} Output;
//#define OUTPUT_VOID

bool areOutputsEqual(Output a, Output b) {
    return a.triangleArea==b.triangleArea && 
    a.circumference==b.circumference && a.circleArea==b.circleArea && 
    a.ellipseArea==b.ellipseArea && 
    a.sphereVolume==b.sphereVolume;
}

// user functions
double triangleArea(double base, double height);
double circumference(double radius);
double circleArea(double radius);
double ellipseArea(double semiMajorAxis, double semiMinorAxis);
double sphereVolume(double radius);

Output runUserCode(Input input) {
    return (Output) {
    triangleArea(input.triangleBase, input.triangleHeight),
    circumference(input.circleRadius),
    circleArea(input.circleRadius),
    ellipseArea(input.ellipseA, input.ellipseB),
    sphereVolume(input.sphereRadius)
    };
}

#define PI 3.14159265358979323846
Output getCorrectOutput(Input input) {
    return (Output) {
    0.5*input.triangleBase*input.triangleHeight,
    2*PI*input.circleRadius,
    PI*input.circleRadius*input.circleRadius,
    PI*input.ellipseA*input.ellipseB,
    (4.0/3.0)*PI*input.sphereRadius*input.sphereRadius*input.sphereRadius
    };
}

char *getCorrectPrint(Input input) {
    return "";
}

void printInput(Input input) {
    printf("\n    triangle base and height: %f, %f\n", input.triangleBase, input.triangleHeight);
    printf("    radius of circle: %f\n", input.circleRadius);
    printf("    ellipse semi-major and semi-minor axis: %f, %f\n", input.ellipseA, input.ellipseB);
    printf("    radius of sphere: %f\n", input.sphereRadius);
}

void printOutput(Output output) {
    printf("\n    area of triangle: %f\n", output.triangleArea);
    printf("    circumference and area of circle: %f, %f\n", output.circumference, output.circleArea);
    printf("    area of ellipse: %f\n", output.ellipseArea);
    printf("    volume of sphere: %f\n", output.sphereVolume);
}

#include "../../../../.apex/testInner.h"
