#include <stdio.h>

int main()
{
    /* Version 1 */
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

    /* Version 2 */
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc);

    printf("%.0f\n", nc);
    
    return 0;
}