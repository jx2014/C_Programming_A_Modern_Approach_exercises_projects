#include "stdio.h"

#define BOOK_ANSWER (1)

int main(void) {

    #if (BOOK_ANSWER == 0)
        float v, r, f, c;

        printf("Enter value of trade: ");
        scanf("%f", &v);

        if (v < 2500) {
            r = 0.017;
            f = 30;
        } else if (v < 6250) {
            r = 0.0066;
            f = 56;
        } else if (v < 20000) {
            r = 0.0034;
            f = 76;
        } else if (v < 50000) {
            r = 0.0022;
            f = 100;
        } else if (v < 500000) {
            r = 0.0011;
            f = 155;
        } else if (v >= 500000) {
            r = 0.0009;
            f = 255;
        }

        c = v*r + f;
        if (c < 39.00f)
            c = 39.00f;

        printf("Commission: %.2f\n", c);

    #endif

    #if (BOOK_ANSWER == 1)
        float commission, value;
        _Bool flag;
        flag = 1;
        printf("%d\n", flag);
        flag = flag + 1;
        printf("%d\n", flag);


        printf("Enter value of trade: ");
        scanf("%f", &value);

        if (value < 2500) {
            commission = 30.00f + 0.17f * value;
        } else if (value < 6250) {
            commission = 56.00f + 0.0066f * value;
        } else if (value < 20000) {
            commission = 76.00f + 0.0034f * value;
        } else if (value < 50000) {
            commission = 100.00f + 0.0022f * value;
        } else if (value < 500000) {
            commission = 155.00f + 0.0011f * value;
        } else if (value >= 500000) {
            commission = 255.00f + 0.0009f * value;
        }

        if (commission < 39.00f)
            commission = 39.00f;

        printf("Commission: $%.2f\n", commission);
        
    #endif


    return 0;
}