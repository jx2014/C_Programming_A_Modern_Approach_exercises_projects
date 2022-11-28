#include <stdio.h>

#define BOOK_SOLUTION (1)

int main(void) {

    #if (BOOK_SOLUTION == 0)

        #define SIZE 5
        unsigned int interest, years, investment;
        float interest_array[SIZE] = {0};
        double total_investment[SIZE] = {0};
        int i;

        printf("Enter the interest rate in percentage: ");
        scanf(" %d", &interest);
        
        printf("Enter the number of years: ");
        scanf(" %d", &years);

        printf("Enter the initial investment: ");
        scanf(" %d", &investment);
        for (int d = 0; d < SIZE; d++) {
            total_investment[d] = investment;
        }

        printf("Year");
        for (i = 0; i < SIZE; i++) {
            printf("%14d%%" , interest + i);       
        }
        printf("\n");

        for (i = 0; i < years; i++) {
            printf("%4d", i+1);
            for (int d = 0; d < SIZE; d++) {
                total_investment[d] = total_investment[d] + total_investment[d] * (interest + d) / 100;
                printf("%15.2f", total_investment[d]);
            }
            printf("\n");
        }
    
    #endif

    #if (BOOK_SOLUTION == 1)
        #define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
        #define INITIAL_BALANE 100.00

    #endif

    return 0;
}