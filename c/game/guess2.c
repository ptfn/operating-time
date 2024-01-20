#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    unsigned int num = rand() % 100, guess;
    scanf("%d", &guess);

    if (num == guess)
        puts("WIN");
    else
        puts("LOSE");

    return 0;
}
