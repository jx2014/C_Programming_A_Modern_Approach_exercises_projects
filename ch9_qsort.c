#include <stdio.h>
#include <stdbool.h>

#define SIZE (7)

void QuickSort(int input_array[], int idx_low, int idx_high) {
    int temp, original_idx_high_pos = idx_high;
    bool fill_left_hole = true;    

    temp = input_array[idx_low];

    if (idx_low >= idx_high) return;

    while (idx_low < idx_high) {        
        if (fill_left_hole) {
            if (input_array[idx_high] < temp) {
                input_array[idx_low] = input_array[idx_high];
                fill_left_hole = false;
                idx_low++;
            } else {
                idx_high--;
            }
        } else {
            if (input_array[idx_low] > temp) {
                input_array[idx_high] = input_array[idx_low];
                fill_left_hole = true;
                idx_high--;
            } else {
                idx_low++;
            }
        }

    }
    input_array[idx_low] = temp;
    QuickSort(input_array, 0, idx_low - 1);
    QuickSort(input_array, idx_low + 1, original_idx_high_pos);
}


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