#include <stdlib.h> //для функций atoi, atof, atol, itoa, ltoa
#include <stdio.h>  //для функции printf
#include <math.h>   //для функций sqrt, pow

float square(float a, float b) {
    return a / 2 * sqrt(pow(b, 2) - pow(a, 2)/4);
}

int main(int argc, char * argv[]) {
    float a = atof(argv[1]);    // перевод аргумента в float
    float b = atof(argv[2]);
    printf("Result %f\n", square(a, b));
    return 0;
}
