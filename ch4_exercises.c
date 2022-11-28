#include "stdio.h"

#define EXERCISE (15)

int main(void) {

    #if (EXERCISE == 0)
        int i = 1, k = 0;
        printf("i: %d, k: %d\n", i, k); // i = 1, k = 0
        k = i++ + 2; // k = 1 + 2 = 3, then i = i + 1 = 2
        printf("i: %d, k: %d\n", i, k); // i = 2, k = 3

        i = 1, k = 0;
        printf("i: %d, k: %d\n", i, k); // i = 1, k = 0
        k = ++i + 2; // i = i + 1 = 2, then k = 2 + 2 = 4
        printf("i: %d, k: %d\n", i, k); // i = 2, k = 4
    #endif

    #if (EXERCISE == 1)
        int i, j, k;
        i = 5, j = 3;
        printf("%d %d\n", i / j, i % j); // 1 2
        i = 2, j = 3;
        printf("%d\n", (i + 10) % j ); // 0
        i = 7, j = 8, k = 9;
        printf("%d\n", (i + 10) % k / j); // 1; 17 % 9 = 8, 8 / 8 = 1
        i = 1, j = 2, k = 3;
        printf("%d\n", (i + 5) % (j + 2) / k); // 0; 6 % 4 = 2, 2 / 3 = 0
    #endif

    #if (EXERCISE == 2)
        int i = 8, j = 4;
        printf("%d %d\n", (2 + (-i) / j ), (2 - (i / j)) ); // 2 + (-8) / 4 = 2 - 2 = 0; 2 - (8 / 4) = 0
        printf("%d %d\n", (2 * (-i) / j ), (2 * -(i / j)) ); // 2 * (-8) / 4 = -16 / 4 = -4; 2 * -(8 / 4) = -4
        printf("%d %d\n", (-2 * (-i) / j ), (-2 * -(i / j)) ); // -2 * (-8) / 4 = 16 / 4 = 4; -2 * -(8 / 4) = 4
        // (-i)/j = (-1 * i) / j = -1 * (i / j) = -(i/j)
    #endif

    #if (EXERCISE == 3)
        printf("%d %d %d %d\n", 8/5, -8/5, 8/-5, -8/-5); // 1, -1, -1, 1
        printf("%d %d %d %d\n", 8%5, -8%5, 8%-5, -8%-5); // 3, -3, 3, -3, sign of result follows the sign of left operand's.
    #endif

    #if (EXERCISE == 7)
        // UPS check digit
        int total = 111;
        for (total = 0; total < 101; total++) {
            printf("%d ", total);
            printf("%d ", 9 - ((total - 1) % 10)); // 9 - (10 - 1) % 10 = 9 - 9 % 10 = 9 - 9 = 0
            printf("%d ", 10 - (total % 10)); // 10 - (10 % 10) = 10 - 0 = 10
            printf("%d \n", (10 - (total % 10)) % 10); // (10 - 10 % 10) % 10 = (10 - 0) % 10 = 0
        }
    #endif

    #if (EXERCISE == 9)
        int i, j, k;
        i = 7, j = 8;
        i *= j + 1;
        printf("%d %d\n", i, j); // i=63 j=8; i = 7 * (8 + 1) = 63

        i = j = k = 1;
        i += j += k;
        printf("%d %d %d\n", i, j, k); // i=3 j=2 k=1; j = j + k = 1 + 1 = 2, i = i + j = 1 + 2 = 3, k = 1

        i = 1, j = 2, k = 3;
        i -= j -= k;
        printf("%d %d %d\n", i, j, k); // i=2 j=-1 k=3; j = 2 - 3 = -1, i = 1 - -1 = 2

        i = 2, j = 1, k = 0;
        i *= j *= k;
        printf("%d %d %d\n", i, j, k); // i=0 j=0 k=0; j = 1 * 0 = 0, i = 2 * 0 = 0
    #endif

    #if (EXERCISE == 10)
        int i, j;
        i = 6;
        j = i += i;
        printf("%d %d\n", i, j); // i = 6 + 6 = 12; j = i = 12; 12 12

        i = 5;
        j = (i -= 2) + 1;
        printf("%d %d\n", i, j); // i = 5 - 2 = 3, j = 3 + 1 = 4; 3 4

        i = 7;
        j = 6 + (i = 2.5);
        printf("%d %d\n", i, j); // i = 2, j = 6 + 2 = 8; 2 8

        //i = 2, j = 8;
        //j = (i = 6) + (j = 3); // illegal operation
        //printf("%d %d\n", i, j); // i = 6, j = 6 + 3 = 9; 6 9
    #endif

    #if (EXERCISE == 11)
        int i, j, k;
        i = 1;
        printf("%d ", i++ - 1); // i = 1, 1 - 1 = 0, 0
        printf("%d\n", i);      // i = 1 + 1 = 2, 2

        i = 10, j = 5;
        printf("%d ", i++ - ++j); // 10 - 6 = 4, 4
        printf("%d %d\n", i, j); // 11 6

        i = 7, j = 8;
        printf("%d ", i++ - --j); // 7 - 7 = 0, 0
        printf("%d %d\n", i, j); // 8, 7

        i = 3, j = 4, k = 5;
        printf("%d ", i++ - j++ + --k); //3 - 4 + (5 - 1) = 3, 3
        printf("%d %d %d\n", i, j, k); // 4, 5, 4
    #endif

    #if (EXERCISE == 12)
        int i, j;
        i = 5;
        j = ++i * 3 - 2; // j = (5 + 1) * 3 - 2 = 16
        printf("%d %d\n", i, j); // 6, 16

        i = 5;
        j = 3 - 2 * i++; // j = 3 - 2 * 5 = -7
        printf("%d %d\n", i, j); // 6, -7

        i = 7;
        j = 3 * i-- + 2; // j = 3 * 7 + 2 = 23, i = 6
        printf("%d %d\n", i, j); // 6, 23

        i = 7;
        j = 3 + --i * 2; // j = 3 + 6 * 2 = 15
        printf("%d %d\n", i, j); // 6, 15
    #endif

    #if (EXERCISE == 13)
        // ++i is equivalent to i += 1;
        int i = 1, k = 0;
        printf("i: %d, k: %d\n", i, k); // i = 1, k = 0
        k = i++ + 2; // k = 1 + 2 = 3, then i = i + 1 = 2
        printf("i: %d, k: %d\n", i, k); // i = 2, k = 3

        i = 1, k = 0;
        printf("i: %d, k: %d\n", i, k); // i = 1, k = 0
        k = ++i + 2; // i = i + 1 = 2, then k = 2 + 2 = 4
        printf("i: %d, k: %d\n", i, k); // i = 2, k = 4

        i = 1, k = 0;
        printf("i: %d, k: %d\n", i, k); // i = 1, k = 0
        k = (i += 1) + 2; // i = i + 1 = 2, then k = 2 + 2 = 4,
        printf("i: %d, k: %d\n", i, k); // i = 2, k = 4
    #endif

    #if (EXERCISE == 14)
        int a=1, b=2, c=3, d=4, e=5;

        printf("%d\n", a * b - c * d + e); // 1 * 2 - 3 * 4 + 5 = 2 - 12 + 5 = -10 + 5 = -5
        printf("%d\n", e / a % c / b); // 5 / 1 % 3 / 2 = 5 % 3 / 2 = 2 / 2 = 1
        printf("%d\n", - a - b + c - + d); // - 1 - 2 + 3 - + 4 = -4
        printf("%d\n", e * - b / c - d); // 5 * -2 / 3 - 4 = -10 / 3 - 4 = -3 -4 = -7
    #endif

    #if (EXERCISE == 15)
        int i = 1, j = 2, k = 0;
        i += j;
        printf("%d %d\n", i, j); // i = 1 + 2 = 3; 3, 2

        i = 1, j = 2;
        i--;
        printf("%d %d\n", i, j); // 0, 2

        i = 1, j = 2;
        k = i * j / i;
        printf("%d %d\n", i, j); // 1, 2

        k = i % ++j;
        k--;
        printf("%d %d\n", i, j); // 1, 3
    #endif


    return 0;
}