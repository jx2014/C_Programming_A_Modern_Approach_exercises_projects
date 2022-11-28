#include "stdio.h"

#define SQUARE (3)

int main(void) {

    #if (SQUARE == 2)
        /* Prints a table of squares using a for statement */
        int i, n;
        printf("This program prints a table of squares.\n");
        printf("Enter number of entries in table: ");
        scanf("%d", &n);

        for (i = 1; i <= n; i++) {
            printf("%10d %10d\n", i, i * i);
        }
    #endif

    #if (SQUARE == 3)
    /* Prints a table of squares using an odd method */

    int i, n, odd, square;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    i = 1;
    odd = 3;
    for (square = 1; i < n; odd += 2) {
        printf("%10d %10d\n", i, square);
        ++i;
        square += odd;
    }

    #endif

    return 0;
}