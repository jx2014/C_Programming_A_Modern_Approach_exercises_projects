#include "stdio.h"

#define PROJECT (6)

int main(void) {
    
    #if (PROJECT == 2)
        int x, y, z;
        printf("Enter a three-digit number: ");
        scanf("%3d", &x);
        z = ( x /   1 ) % 10; // getting the first digit
        y = ( x /  10 ) % 10; // getting the second digit
        x = ( x / 100 ) % 10; // getting the third digit
        printf("The reversal is: %d%d%d\n", z, y, x);
    #endif

    #if (PROJECT == 3)
        int x, y, z;
        printf("Enter a three-digit number: ");
        scanf("%1d%1d%1d", &x, &y, &z);
        printf("The reversal is: %d%d%d\n", z, y, x);

    #endif

    #if (PROJECT == 4)
        int x, o1, o2, o3, o4, o5;
        printf("Enter a number between 0 and 32767: ");
        scanf("%d", &x);

        o1 = x % 8;
        o2 = (x / 8) % 8;
        o3 = (x / 64) % 8;
        o4 = (x / 512) % 8;
        o5 = (x / 4096) % 8;

        x = o1 + o2 * 10 + o3 * 100 + o4 * 1000 + o5 * 10000;
        printf("In octal, your number is: %05d\n", x);

    #endif

    #if (PROJECT == 5)
        int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;

        printf("Please enter the first 11 digits of a UPC: ");
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);    

        first_sum = d + i2 + i4 + j1 + j3 + j5;
        second_sum = i1 + i3 + i5 + j2 + j4;
        total = 3 * first_sum + second_sum;

        printf("Check digit: %d\n", 9 - ((total - 1) % 10));
    #endif

    #if (PROJECT == 6)
        int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, first_sum, second_sum, total;

        printf("Please enter the first 12 digits of an EAN: ");
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);        

        first_sum = i2 + i4 + i6 + i8 + i10 + i12;
        second_sum = i1 + i3 + i5 + i7 + i9 + i11;
        total = 3 * first_sum + second_sum;

        printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    #endif

    return 0;
}


