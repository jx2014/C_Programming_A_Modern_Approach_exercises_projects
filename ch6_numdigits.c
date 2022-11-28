/* 
 * Count the number of digits with a given number 
*/
#include "stdio.h"

#define BOOK_ANSWER (0)

int main(void) {
    #if (BOOK_ANSWER == 0)
        int x, n = 1;

        printf("Enter a number: ");
        scanf("%d", &x);

        while ( (x / 10) >= 1 ) {
            n++;
            x = x / 10;
        }; 

        printf("%d digits.\n", n);
    #endif

    #if (BOOK_ANSWER == 1)
        int digits = 0, n;
        printf("Enter a none negative integer: ");
        scanf("%d", &n);

        do {
            n /= 10;
            digits++;
        } while (n > 0);
        printf("The number has %d digit(s).\n", digits);

    #endif



    return 0;
}