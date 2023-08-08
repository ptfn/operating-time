#include <stdbool.h>
#include <math.h>

#include <stdio.h>

bool narcissistic(int num)
{
    int length = (int)log10(num)+1, result = 0;
    for (int i = 0; i < length; i++)
        result += (int)pow((int)(num / pow(10, i)) % 10, length);
    return num == result;
}

int main()
{
   printf("%d\n", narcissistic(7)); 
   printf("%d\n", narcissistic(371)); 
   printf("%d\n", narcissistic(153)); 
   printf("%d\n", narcissistic(4887)); 

   return 0;
}
