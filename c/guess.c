#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define EASY    25
#define MED     50
#define HARD    100

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void generate(int a[], int l)
{
    srand(time(0));
    for (int i = 0; i < l; i++)
        a[i] = 1 + rand() % (l * 2);
}

void sort(int a[], int l)
{
   for (int i = 0; i < l; i++)
        for (int j = 0; j < l; j++)
            if (j != (l-1))
                if (a[j] > a[j+1])
                    swap(&a[j], &a[j+1]);
}

int binsearch(int v[], int n, int x)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; 
    }
    return -1;
}

int main()
{
    int in, level, choice, chance;
    printf("Choose a difficulty level:\n1) EASY\n2) MEDIUM\n3) HARD\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: level = EASY; chance = 5; break;
        case 2: level = MED; chance = 10; break;
        case 3: level = HARD; chance = 15; break;
    default: break;
    }

    int arr[level];
    generate(arr, level);
    sort(arr, level);

    printf("START\n");

    while (0 < chance) {
        printf("%d chances left\n", chance--);
        scanf("%d", &in); 

        if (binsearch(arr, level, in) != -1) {
            printf("YOU WIN!\n");
            break;
        } 
        
        else {
            printf("No NUMBER!\n");
        }
    }
    return 0;
}