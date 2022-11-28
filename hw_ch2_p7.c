/*
 *  Input dollar amount, automatically reutrn
 *  smaller bills of $20, $10, $5, $1
 */
#include "stdio.h"

int main() {
    unsigned int t = 0;
    unsigned int bill_20, bill_10, bill_5, bill_1;

    printf("Enter total amount $");
    scanf("%d", &t);

    bill_20 = t / 20;
    bill_10 = (t - bill_20 * 20) / 10;
    bill_5  = (t - bill_20 * 20 - bill_10 * 10) / 5;
    bill_1  = (t - bill_20 * 20 - bill_10 * 10 - bill_5 * 5) / 1;

    printf("$20 .. %d\n", bill_20);
    printf("$10 .. %d\n", bill_10);
    printf(" $5 .. %d\n", bill_5);
    printf(" $1 .. %d\n", bill_1);


    return 0;
}
