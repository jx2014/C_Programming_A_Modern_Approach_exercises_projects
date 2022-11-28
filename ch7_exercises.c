#include <stdio.h>

#define EXERCISE (15)

int main(void) {
    #if (EXERCISE == 0)
        int i = -10;
        unsigned int u = 10;
        int U = 10;

        printf("i (%d) < u (%d): %d\n", i, u, i < u);
        printf("i (%d) < U (%d): %d\n", i, U, i < U);

        u = -10;
        printf("%ud\n", u);
        printf("int i = -10\n");
        printf(" %%d of i: %d\n", i);
        printf("%%ud of i: %ud\n", i);

        float f, frac_part;
        f = 123.456;
        frac_part = f - (int)f;
        printf("%d  %g\n", (int)f, frac_part);

        float quotient;
        int dividend = 7, divisor = 3;
        quotient = dividend / divisor;
        printf("%f\n", quotient);

        quotient = (float) dividend / divisor;
        printf("After cast: %f\n", quotient);

        long I;
        short int j = 16960;
        I = j * j;
        printf("I = j * j is: %ld\n", I);

        printf("Size of int: %zu\n", sizeof(int));

    #endif

    #if (EXERCISE == 1)
        printf("%d\n", 077);   // 63
        printf("%d\n", 0x77);  // 119
        printf("%d\n", 0xABC); // 2748    
    #endif

    #if (EXERCISE == 2)
        printf("%f\n", 010E2);
        printf("%f\n", 32.1E+5);
        //printf("%d\n", 0790);
        //printf("%d\n", 100_000);
        printf("%f\n", 3.978e-2);
    
    #endif

    #if (EXERCISE == 3)
        short unsigned int a = 1;
        //short float b = 1.2;
        long double c = 2.3;
        unsigned long d = 3.4;
        printf("%d %Lf %ld", a, c, d);
    
    #endif

    #if (EXERCISE == 5)
        char a, b, c, d;
        a = 'A';
        b = 0b1000001;
        c = 0101;
        d = 0x41;
        printf("%d\n", a);
        printf("%d\n", b);
        printf("%d\n", c);
        printf("%d\n", d);
    
    #endif

    #if (EXERCISE == 6)
        char days_of_month = 31;
        short int days_of_year = 365;
        short int mins_of_day = 3600;
        int secs_of_day = 216000;

        printf("%d\n", days_of_month);
        printf("%d\n", days_of_year);
        printf("%d\n", mins_of_day);
        printf("%d\n", secs_of_day);
    #endif

    #if (EXERCISE == 7)
        printf("backspace%c\\b\n", '\10');
        printf("tab %c \\t\n", '\11');
        printf("newline\\n%cafter newline\\n\n", '\12');
        printf("1234567\n1234567%c4321abc <-after CR\n", '\15');
    #endif

    #if (EXERCISE == 8)
        printf("backspace%c\\b\n", '\x08');
        printf("tab%c\\t\n", '\x09');
        printf("newline\\n%cafter newline\\n\n", '\x0a');
        printf("1234567\n1234567%c4321abc <-after CR\n", '\x0d');

    #endif

    #if (EXERCISE == 9)
        int i = 10, j = 10;
        printf("%d\n", i / j + 'a');

    #endif

    #if (EXERCISE == 10)
        int i = 1;
        long j = 1;
        unsigned k = 1;
        printf("%d\n", i + (int)j * k); // i + (int)j * k is type unsigned int.
    #endif

    #if (EXERCISE == 11)
        int i = 1;
        float f = 1;
        double d = 1;

        printf("%f\n", i * f / d);
    #endif

    #if (EXERCISE == 12)
        int i = 1;
        float f = 1.0f;
        double d = 2.0;
        d = i + f;
        printf("%f", d);
    #endif

    #if (EXERCISE == 13)
        char c = '\1'; // 1
        short s = 2;
        int i = -3;
        long m = 5;
        float f = 6.5f;
        double d = 7.5;
        printf("%d\n", c * i); // (a) 1 * -3 = -3, type int
        printf("%ld\n", s + m); // (b) 2 + 5 = 7, type long int
        printf("%f\n", f / c); // (c) 6.5 / 1 = 6.5, type int
        printf("%f\n", d / s); // (d) 7.5 / 2 = 3.75, type double
        printf("%f\n", f - d); // (e) 6.5 - 7.5 = -1.0, type double
        printf("%d\n", (int) f); // (f) 6, type int

    #endif

    #if (EXERCISE == 14)
        float f = 4294967296.4294967296, frac_part;
        frac_part = f - (int) f; // will not always work since it converts 10000.0 to 1.0E4
        printf("%f\n", frac_part);

    #endif

    #if (EXERCISE == 15)
        typedef char Int8;
        typedef short int Int16;
        typedef int Int32;
    #endif

    return 0;
}