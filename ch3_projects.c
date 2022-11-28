#include "stdio.h"

#define PROJECT (6)

int main (void) {

    #if (PROJECT == 0)
        printf("%5d,%-5d,%-5d", 123, 123, 123);
    #endif

    #if (PROJECT == 1)
        int m, d, y;
        printf("Enter a date (mm/dd/yyyy): ");
        scanf("%2d/%2d/%4d", &m, &d, &y);
        printf("You entered the date: %4d%.2d%02d", y, m, d);
    #endif

    #if (PROJECT == 2)
        int item_num, m, d, y;
        item_num = 0, m = 1, d = 1, y = 1900;
        float item_price = 0.0f;

        printf("Enter item number: ");
        scanf("%d", &item_num);
        printf("Enter item price: ");
        scanf("%f", &item_price);
        printf("Enter purchase date (mm/dd/yyyy): ");
        scanf("%2d/%2d/%4d", &m, &d, &y);

        printf("\n");
        printf("Item \t\t\tUnit\t\t\tPurchase\n");
        printf("     \t\t\tPrice\t\t\tDate\n");
        printf("%-5d\t\t\t$%7.2f\t\t%-.2d/%.2d/%4d", item_num, item_price, m, d, y);   
    #endif

    #if (PROJECT == 3)
        int prefix, group, publisher, item_num, check;
        printf("Enter ISBN (978-0-393-97950-3): ");
        scanf("%d-%d-%d-%d-%d", &prefix, &group, &publisher, &item_num, &check);
        printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n",
        prefix, group, publisher,item_num, check);
    #endif

    #if (PROJECT == 5)
        int r11, r12, r13, r14;
        int r21, r22, r23, r24;
        int r31, r32, r33, r34;
        int r41, r42, r43, r44;

        printf("Enter the numbers from 1 to 16 in any order: ");
        scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &r11, &r12, &r13, &r14, 
                                                  &r21, &r22, &r23, &r24, 
                                                  &r31, &r32, &r33, &r34,
                                                  &r41, &r42, &r43, &r44);
        
        printf("\n");
        printf("               %5d %5d %5d %5d\n", r11, r12, r13, r14);
        printf("               %5d %5d %5d %5d\n", r21, r22, r23, r24);
        printf("               %5d %5d %5d %5d\n", r31, r32, r33, r34);
        printf("               %5d %5d %5d %5d\n", r41, r42, r43, r44);
        printf("\n");
        
        printf("Row sums:      %5d %5d %5d %5d\n", r11+r12+r13+r14, r21+r22+r23+r24, r31+r32+r33+r34, r41+r42+r43+r44);
        printf("Column sums:   %5d %5d %5d %5d\n", r11+r21+r31+r41, r12+r22+r32+r42, r13+r23+r33+r43, r14+r24+r34+r44);
        printf("Diagonal sums: %5d %5d\n", r11+r22+r33+r44, r41+r32+r23+r14);
    #endif

    #if (PROJECT == 6)
        int num1=0, denom1=0, num2=0, denom2=0, result_num=0, result_denom=0;

        printf("Enter two fraction numbers (1/3+3/2): ");
        scanf("%d / %d + %d / %d", &num1, &denom1, &num2, &denom2);

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

    #endif


    return 0;
}