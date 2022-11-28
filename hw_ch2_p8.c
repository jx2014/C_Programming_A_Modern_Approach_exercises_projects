/*
 *  calculate 3 months load balance.
 */

#include "stdio.h"

int main() {
    float loan_amount = 0;
    float interest_rate = 0;
    float payment = 0;
    float interest_monthly;

    printf("Enter total loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter total interest rate: ");
    scanf("%f", &interest_rate);
    interest_monthly = (interest_rate / 12) / 100;
    
    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    for (int i = 1; i <= 12; i++) {
        loan_amount = loan_amount * ( 1 + interest_monthly ) - payment;
        printf("Balance remaining after #%.2d payment: $%.2f\n", i, loan_amount);
    }





    return 0;
}
