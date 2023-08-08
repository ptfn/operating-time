#include <stdlib.h>
#include <stdio.h>

void print_array(size_t n, int arr[n]) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void sort_array(size_t n, int arr[n]) {
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0, k = 1; j < n-1; j++, k = 1) {
            if (!(arr[j]&1)) {continue;}
            if (!(arr[j+k]&1)) {while (!(arr[j+k]&1) && j+k < n) k++;}
            if (arr[j] > arr[j+k] && j+k < n) {
                int temp = arr[j];
                arr[j] = arr[j+k];
                arr[j+k] = temp;
            }
        }
}

int main(void)
{
    sort_array(6, (int[]){5, 3, 2, 8, 1, 4});
    sort_array(5, (int[]){5, 3, 1, 8, 0});
    sort_array(0, (int[]){});
    sort_array(2, (int[]){7, 1});
    sort_array(10, (int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

    return 0;
}
