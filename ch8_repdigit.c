#include <stdio.h>
#include <stdbool.h>

int main(void) {
    /* 
    int digit[10] = {0};
    int num, x;

    printf("Enter a digit: ");
    scanf(" %d", &x);
    do {
        num = x % 10;
        x = x / 10;
        digit[num]++;
        if (digit[num] > 1) {
            printf("Duplicate digits\n");
            return 0;
        }
    } while ( x > 0);
    printf("There are no duplicate digits\n");
    */

    /* Book solution */
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            break;
        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");
    return 0;
}