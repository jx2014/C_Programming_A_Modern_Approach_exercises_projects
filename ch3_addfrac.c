/* Adds two fractions */

#include "stdio.h"

int main(void) {
    int num1=0, denom1=0, num2=0, denom2=0, result_num=0, result_denom=0;

    printf("Enter a fraction number: ");
    scanf("%d / %d", &num1, &denom1);
    printf("Enter a second fraction number: ");
    scanf("%d / %d", &num2, &denom2);

    result_denom = denom1 * denom2;
    result_num = num1 * denom2 + num2 * denom1;
    
    int smaller_num = (result_num<result_denom) ? result_num : result_denom;

    printf("result is: %d/%d", result_num, result_denom);

    // reduce to lower terms
    for (int n = 2; n <= smaller_num; n++) {
        if (result_num % n == 0 && result_denom % n == 0) {
            result_num = result_num / n;
            result_denom = result_denom / n;
        }
    }

    // special handling of various forms of fraction
    if (result_denom == 1 || result_num == 0) {
        printf(" (%d)\n", result_num);
    } else if (result_num > result_denom) {
        int whole_int = result_num / result_denom;
        result_num = result_num - whole_int * result_denom;
        printf(" (%d %d/%d)\n", whole_int, result_num, result_denom);
    } else {
        printf(" (%d/%d)\n", result_num, result_denom);
    } 

    return 0;
}