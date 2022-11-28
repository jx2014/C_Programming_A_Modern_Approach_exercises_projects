#include "stdio.h"

#define PROJECT (12)

int main(void) {
    #if (PROJECT == 1)
        float x, large = 0;
        while (1) {
            printf("Enter a number: ");
            scanf("%f", &x);
            large = (large > x) ? large : x;
            if (x <= 0) {
                printf("The largest number entered was %g\n", large);
                return 0;
            }
        }
    #endif

    #if (PROJECT == 2)
        int m, n, GCD = 0;
        printf("Enter two integers: ");
        scanf("%d %d", &m, &n);

        /*        
        GCD = (m == 0) ? n : m;

        for (int i = 1; i <= m && i <= n; i++) {
            if (((m % i) == 0) && ((n % i) == 0)) {
                GCD = i;
            }
        }
        */

       /* //based on book
        int s, l;
        s = ( n < m )? n : m; // r is the smaller of the two numbers.
        l = ( n < m )? m : n; // l is the larger of the two numbers.

        while (s >= 0) {
            if (s == 0) {
                GCD = l;
                break;
            }
            GCD = s;
            s = l % s;
            l = GCD;            
        }
        */

        // book answer
        int remainder;
        while (n != 0) {
            remainder = m % n;
            m = n;
            n = remainder;
        }
        GCD = m;

        printf("Greatest comon divisor: %d\n", GCD);
    #endif

    #if (PROJECT == 3)
        int n, d, x, y, r;
        printf("Enter a fraction: ");
        scanf("%d /%d", &n, &d);
        x = n;
        y = d;

        while (x > 0) {
            r = y % x;
            y = x;
            x = r;
        }
        // the GCD is y

        printf("The reduced form is: %d/%d", n/y, d/y);


    #endif

    #if (PROJECT == 4)
        while (1) {
            float v, r, f, c;

            printf("Enter value of trade: ");
            scanf("%f", &v);
            if (v <= 0) {
                return 0;
            }

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
        }

    #endif

    #if (PROJECT == 5)
        // reverse a number
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);
        printf("The reverse is: ");
        while ( n > 0) {
            printf("%d", n % 10);
            n /= 10;
        }
        printf("\n");
    #endif

    #if (PROJECT == 6)
        // Prints all even squares uo to the number, n.
        int n, s, i;

        printf("Enter a number: ");
        scanf("%d", &n);

        for (i = 2, s = 0; s < n; i++) {
            if ( i % 2 != 0) continue; // skip for odd number
            s = i * i;
            printf("%d\n", s);
        }
    #endif

    #if (PROJECT == 7)
        /* Prints a table of squares using an odd method */

        int i, n, square, odd;
        printf("This program prints a table of squares.\n");
        printf("Enter number of entries in table: ");
        scanf("%d", &n);

        square = 1;
        odd = 1;
        for (i = 1; i <= n; i++) {            
            printf("%10d %10d %10d\n", i, odd, square);
            odd = odd + 2;            
            square = square + odd;
        }
    #endif

    #if (PROJECT == 8)
        int days, offset;

        while (days < 28 || days > 31) {
            printf("Enter number of days in the month: ");
            scanf("%d", &days);
        }

        while (offset < 1 || offset > 7) {
            printf("Enter starting day of the week (1=Sun, 7=Sat): ");
            scanf("%d", &offset);
        }

        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        /*
        for ( int i = ( 2 - offset ); i <= days; i++) {            
            if ( i > 0)
                printf("%3d ", i);
            else
                printf("    ");

            if ( (i + offset - 1) % 7 == 0 && i != 0)
                printf("\n");
        }      
        */
        for ( int i = 1; i < offset; i++ ) printf("    ");
        for ( int i = 1; i <= days; i++ ) {
            printf("%3d ", i);
            if ( (offset + i - 1) % 7 == 0 ) printf("\n");
        }

    #endif

    #if (PROJECT == 9)
        float loan_amount = 0;
        float interest_rate = 0;
        float payment = 0;
        float interest_monthly;
        unsigned int num_payments = 0;

        printf("Enter total loan amount: ");
        scanf("%f", &loan_amount);
        
        printf("Enter total interest rate: ");
        scanf("%f", &interest_rate);
        interest_monthly = (interest_rate / 12) / 100;
        
        printf("Enter monthly payment: ");
        scanf("%f", &payment);

        while (num_payments <= 0) {
            printf("Enter number of payments: ");
            scanf("%d", &num_payments);
        }

        for (int i = 1; i <= num_payments; i++) {
            loan_amount = loan_amount * ( 1 + interest_monthly ) - payment;
            printf("Balance remaining after #%.2d payment: $%.2f\n", i, loan_amount);
        }
    #endif

    #if (PROJECT == 10)
        // compare two dates
        int d=1, m=1, y=1, ed=99, em=99, ey=99;
        _Bool invalid_entry = 1, end = 0;
        while (1) {
            invalid_entry = 1;
            while ( invalid_entry && !end ) {
                printf("Enter first date (mm/dd/yy): ");
                scanf("%2d /%2d /%2d", &m, &d, &y);
                invalid_entry = 0;
                end = 0;
                if ( d == 0 && m == 0 && y == 0) end = 1;
                if ( m < 0 || m > 12 ) invalid_entry = 1;
                if ( d < 0 || d > 31 ) invalid_entry = 1;
                if ( y < 0 ) invalid_entry = 1;                
            }
            if (end == 1)  break;
            if (y == ey) {
                if ( m == em ) {
                    if ( d < ed ) {
                        ed = d;
                    }
                } else if ( m < em ) {
                    em = m;
                    ed = d;
                }
            } else if (y < ey) {
                ey = y;
                em = m;
                ed = d;
            }
        }
        printf("%02d/%02d/%02d is the earliest date.\n", em, ed, ey);
    #endif

    #if (PROJECT == 11)
        unsigned int n;
        double f = 1;
        double e = 1.0f;
        printf("Enter an interger to approximate e: ");
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            f = i * f;
            e = e + 1 / f;
        }
        printf("e is approxiamted to be %.20f\n", e);
    #endif

    #if (PROJECT == 12)
        float p;
        double f = 1, t = 1;
        double e = 1.0f;
        printf("Enter a small number as the precision for the approximation of e: ");
        scanf("%f", &p);

        for (int i = 1; t >= p; i++) {
            f = i * f;
            t = 1 / f;
            e = e + t;
        }
        printf("e is approxiamted to be %.20f\n", e);

    #endif

    return 0;
}