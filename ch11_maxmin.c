#include <stdio.h>

#define ARRAY_SIZE (10)

void max_min(int a[], int n, int *max, int *min);

int main(void) {
    int num_array[ARRAY_SIZE];
    int array_size = ARRAY_SIZE;
    int big = 0, small = 0;

    printf("Enter %d numbers: ", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf(" %d", &num_array[i]);
    }
    max_min(num_array, ARRAY_SIZE, &big, &small);
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);


    return 0;
}

void max_min(int a[], int n, int *pmax, int *pmin) {
    *pmin = a[0];
    *pmax = a[0];
    for (int i = 1; i < n; i++) {
        if (*pmax < a[i]) {
            *pmax = a[i];
        } else if (*pmin > a[i]) {
            *pmin = a[i];
        }
    }
}