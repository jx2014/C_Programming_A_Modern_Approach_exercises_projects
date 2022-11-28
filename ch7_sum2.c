#include <stdio.h>

int main(void) {
    short int sum = 0, d = 1;

    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");    
    while (d != 0) {
        scanf("%hd", &d);
        sum += d;
    }
    printf("The sum is: %d\n", sum);


    return 0;
}