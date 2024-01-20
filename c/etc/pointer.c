#include <stdlib.h>
#include <stdio.h>

// Version 1
void fill_array(int array[], int len)
{
    for (int i = 0; i < len; i++)
        array[i] = i;
}

// Version 2
void fill_point(int *array, int len)
{
    for (int i = len; i >= 0;)
        *array++ = i--;
}

void print_array(int array[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    putchar('\n');
}

int main()
{
    /* Pointer */
    int x = 123, y, *px, **py;
    px = &x;
    y = *px;
    py = &px;

    puts("Pointer");
    printf("%d\t%p\n", *px, px);
    printf("%d\t%p\n", **py, py);

    puts("Variables");
    printf("%d\t%p\n", x, &x);
    printf("%d\t%p\n", y, &y);

    x = 0;

    printf("x %d\ny %d\npx %d\npy %d\n", x, y, *px, **py);

    /* Array and Dynamic Memory*/
    int a[5];
    int *b = malloc(5 * sizeof(int));
    int *c = malloc(5 * sizeof(int));

    fill_array(a, 5);
    fill_point(b, 5);
    fill_point(c, 5);

    *(b+10) = 111; // No Safe

    print_array(a, 5);
    print_array(b, 5);
    print_array(c, 5);

    free(b);

    char *str = malloc(5 * sizeof(char));
    char **pstr = &str;
    
    *(str+1) = 'h';
    str[0] = 'h';
    *(*pstr+1) = 108;

    puts(str);
    /*
     * Plus: return array and etc type
     * Minus: need stdlib.h
     */

}
