#include "stdio.h"

#define PROJECT (11)

int main(void) {

    #if (PROJECT == 1)
        // count number of digits a number contains
        int x;
        printf("Enter a number: ");
        scanf("%4d", &x);

        if ((x / 1000) >= 1)
            printf("4 digits\n");
        else if ((x / 100) >= 1)
            printf("3 digits\n");
        else if ((x / 10) >= 1)
            printf("2 digits\n");
        else if ((x / 1) >= 1 || x == 0)
            printf("1 digit\n");
        else
            printf("Invalid entry\n");
    #endif

    #if (PROJECT == 2)
        // convert 24-hour time to 12-hour time
        int h, m;
        printf("Enter a 24-hour time (hh:mm): ");
        scanf("%2d :%2d", &h, &m);
        
        if (h >= 24 || h < 0 || m >= 60 || m < 0) {
            printf("Invade time entered.\n");
            return 0;
        }

        if ( h > 11) {
            h = (h > 12) ? (h - 12) : h;
            printf("Equivalent 12-hour time: %02d:%02d PM.\n", h, m);
        } else {
            printf("Equivalent 12-hour time: %02d:%02d AM.\n", h, m);
        }

    #endif

    #if (PROJECT == 3)

        unsigned int n = 0;
        float s, v, r, f, c, r_c;
        

        printf("Enter the number of shares: ");
        scanf("%d", &n);

        printf("Enter the value per share: $");
        scanf("%f", &s);

        v = n * s;
        printf("Total value of trade is $%.2f\n", v);

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
        if (c < 39.00f) {
            c = 39.00f;
        }

        
        if ( n < 2000) {
            r_c = 33 + 0.03 * n;
        } else {
            r_c = 33 + 0.02f * ( n - 2000) + 0.03 * 2000.0f;
        }

        printf("Commission: $%5.2f\n", c);
        printf("Rival broker commission: $%5.2f\n", r_c);

    #endif

    #if (PROJECT == 4)
        int scale;
        printf("Enter a wind speed in knots: ");
        scanf("%d", &scale);

        if (scale < 1) {
            printf("Calm\n");
        } else if (scale <= 3) {
            printf("Light air\n");
        } else if (scale <= 27) {
            printf("Breeze\n");
        } else if (scale <= 47) {
            printf("Gale\n");
        } else if (scale <= 63) {
            printf("Storm\n");
        } else{
            printf("Hurricane\n");
        }
    #endif

    #if (PROJECT == 5)
        float income = 0, tax = 0;
        printf("Please enter your income: $");
        scanf("%f", &income);

        if (income > 7000) {         
            tax = tax + 230.00f + 0.06 * (income - 7000);
            income = 7000;
        }

        if (income > 5250 && income <= 7000) {
            tax = tax + 152.50f + 0.05 * (income - 5250);
            income = 5250;
        }

        if (income > 3750 && income <= 5250) {
            tax = tax + 82.50f + 0.04 * (income - 3750);
            income = 3750;
        }

        if (income > 2250 && income <= 3750) {
            tax = tax + 37.50f + 0.03 * (income - 2250);
            income = 2250;
        }

        if (income > 750 && income <= 2250) {
            tax = tax + 7.50f + 0.02 * (income - 750);
            income = 750;
        }        

        if (income <= 750) {
            tax = tax + 0.01f * income;
        }

        printf("Total tax is due: $%.2f\n", tax);

    #endif

    #if (PROJECT == 6)
        // UPC revisited. 
        // Add feature to check valid UPC entries.

        int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, c, first_sum, second_sum, total, check_digit;

        printf("Please enter the a 12-digits UPC: ");
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &c);    

        first_sum = d + i2 + i4 + j1 + j3 + j5;
        second_sum = i1 + i3 + i5 + j2 + j4;
        total = 3 * first_sum + second_sum;
        check_digit = 9 - ((total - 1) % 10);
        if (c != check_digit) {
            printf("Check digit %d does not match UPC. Invalid UPC.\n", check_digit);
        } else {
            printf("UPC is valid.\n");
        }

    #endif

    #if (PROJECT == 7)
        // find hte largest and smallest of four integers entered by the user
        int a, b, c, d, l1, s1, l2, s2, largest, smallest;
        printf("Enter four integers: ");
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (a > b) {
            l1 = a;
            s1 = b;
        } else {
            l1 = b;
            s1 = a;
        }

        if ( c > d) {
            l2 = c;
            s2 = d;
        } else {
            l2 = d;
            s2 = c;            
        }
        
        largest = (l1 > l2) ? l1 : l2;
        smallest = (s1 < s2) ? s1 : s2;

        printf("Largest: %d\n", largest);
        printf("Smallest: %d\n", smallest);
    #endif

    #if (PROJECT == 8)
        int h = 0, m = 0, user;
        int d1, d2, d3, d4, d5, d6, d7, d8;

        d1 =  8 * 60;
        d2 =  9 * 60 + 43;
        d3 = 11 * 60 + 19;
        d4 = 12 * 60 + 47;
        d5 = 2 * 60 + 12 * 60;
        d6 = 3 * 60 + 12 * 60 + 45;
        d7 = 7 * 60 + 12 * 60;
        d8 = 9 * 60 + 12 * 60 + 45;

        printf("Enter estimated departure time: ");
        scanf(" %2d :%2d", &h, &m);

        user = h * 60 + m;
        
        if ((user - d1) <= (d2 - user)) {
            printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m");
        } else if ((user - d2) <= (d3 - user)) { 
            printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m"); 
        } else if ((user - d3) <= (d4 - user)) { 
            printf("Closest departure time is 11:19 a.m., arriving at  1:31 p.m"); 
        } else if ((user - d4) <= (d5 - user)) { 
            printf("Closest departure time is 12:47 p.m., arriving at  3:00 p.m"); 
        } else if ((user - d5) <= (d6 - user)) { 
            printf("Closest departure time is  2:00 p.m., arriving at  4:08 p.m"); 
        } else if ((user - d6) <= (d7 - user)) { 
            printf("Closest departure time is  3:45 p.m., arriving at  5:55 p.m"); 
        } else if ((user - d7) <= (d8 - user)) { 
            printf("Closest departure time is  7:00 p.m., arriving at  9:20 p.m"); 
        } else {
            printf("Closest departure time is  9:45 p.m., arriving at 11:58 p.m"); 
        }
    #endif

    #if (PROJECT == 9)
        // compare two dates
        int d1, m1, y1, d2, m2, y2;
        _Bool date1_early = 0;

        printf("Enter first date (mm/dd/yy): ");
        scanf("%2d /%2d /%2d", &m1, &d1, &y1);
        printf("Enter second date (mm/dd/yy): ");
        scanf("%2d /%2d /%2d", &m2, &d2, &y2);

        if (y1 == y2) {
            if ( m1 == m2 ) {
                if ( d1 <= d2 ) {
                    date1_early = 1;
                } else {
                    date1_early = 0;
                }
            } else if ( m1 < m2 ) {
                date1_early = 1;
            } else {
                date1_early = 0;
            }
        } else if (y1 < y2) {
            date1_early = 1;
        } else {
            date1_early = 0;
        }

        if ( date1_early ) {
            printf("%02d/%02d/%02d is eariler than %02d/%02d/%02d\n", m1,d1,y1, m2,d2,y2);
        } else {
            printf("%02d/%02d/%02d is eariler than %02d/%02d/%02d\n", m2,d2,y2, m1,d1,y1);
        }
    #endif

    #if (PROJECT == 10)
        int grade, x;

        printf("Enter numerical grade: ");
        scanf("%d", &grade);
        x = grade / 10;
        if (grade > 100 || grade < 0) {
            printf("Invalid grade entered.\n");
            return 0;
        }
        switch (x) {
            case 10: // Fall through
            case 9:  printf("Letter grade: A\n"); break;
            case 8:  printf("Letter grade: B\n"); break;
            case 7:  printf("Letter grade: C\n"); break;
            case 6:  printf("Letter grade: D\n"); break;
            default: printf("Letter grade: F\n"); break;
        }
    #endif

    #if (PROJECT == 11)
        int x = 0, y = 0;
        printf("Enter a two-digit number: ");
        scanf("%2d", &x);

        y = x % 10; // get the first digit
        x = x / 10; // get the second digit

        printf("You entered the number ");
        switch (x) {
            case 0:                 
                break;
            case 1: 
                switch (y) {
                    case 0: printf("ten.\n"); return 0;
                    case 1: printf("eleven.\n"); return 0;
                    case 2: printf("twelve.\n"); return 0;
                    case 3: printf("thirteen.\n"); return 0;
                    case 4: printf("fourteen.\n"); return 0;
                    case 5: printf("fifteen.\n"); return 0;
                    case 6: printf("sixteen.\n"); return 0;
                    case 7: printf("seventeen.\n"); return 0;
                    case 8: printf("eighteen.\n"); return 0;
                    case 9: printf("nineteen.\n"); return 0;
                }
            case 2: 
                printf("twenty");                          
                break;
            case 3: 
                printf("thirty"); 
                break;
            case 4: 
                printf("fourty"); 
                break;
            case 5: 
                printf("fifty"); 
                break;
            case 6: 
                printf("sixty"); 
                break;
            case 7: 
                printf("seventy"); 
                break;
            case 8: 
                printf("eighty"); 
                break;
            case 9: 
                printf("ninety"); 
                break;
        }

        if (x != 0 ) {
            if (y == 0) {
                printf(".\n"); 
                return 0;
            } else {
                printf("-");
            }
        }

        switch (y) {
            case 0: printf("zero.\n"); break;
            case 1: printf("one.\n"); break;
            case 2: printf("two.\n"); break;
            case 3: printf("three.\n"); break;
            case 4: printf("four.\n"); break;
            case 5: printf("five.\n"); break;
            case 6: printf("six.\n"); break;
            case 7: printf("seven.\n"); break;
            case 8: printf("eight.\n"); break;
            case 9: printf("nine.\n"); break;
        }


    #endif


    return 0;
}