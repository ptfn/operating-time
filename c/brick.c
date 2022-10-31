#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char * argv[]) {
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float c = atof(argv[3]);

    float p = atof(argv[4]);
    float s = atof(argv[5]);

    bool enter = false;

    if (((p >= a) && (s >= b)) || ((p >= b) && (s >= a))) {enter = true;}
    else if (((p >= b) && (s >= c)) || ((p >= c) && (s >= b))) {enter = true;}
    else if (((p >= a) && (s >= c)) || ((p >= c) && (s >= a))) {enter = true;}
    else {enter = false;}

    if (enter) {printf("Yes\n");} 
    else {printf("No\n");}

    getchar();
    return 0;
}