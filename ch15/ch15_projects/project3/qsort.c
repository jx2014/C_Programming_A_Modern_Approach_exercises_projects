#include <stdio.h>
#include <stdbool.h>
#include "quicksort.h"

#define SIZE (7)

int main(void) {
    int a[SIZE] = {12, 3, 6, 18, 7, 15, 10};
    
    printf("Enter %d numbers: ", SIZE);    
    for (int i = 0; i < SIZE; i++) scanf("%d", &a[i]);    
    QuickSort(a, 0, SIZE - 1);
    printf("\nIn sorted order: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}