#include "stdio.h"
#include "time.h"

#define EXERCISE (13)

int main(void) {

    #if (EXERCISE == -1)
        // find prime numbers from 1 to 1000
        _Bool prime = 1;
        int number_of_primes = 0;
        for (int n = 2; n <= 1000000; n++) {
            prime = 1; // reset prime flag
            for (int d = 2; d <= (n/2); d++ ){
                if ( n % d == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime) {
                number_of_primes++;
                //printf("%d\n", n);
            }
        }
        printf("Total number of primes: %d\n", number_of_primes);


    #endif

    #if (EXERCISE == 0)
        for (int i = 10; i > 0; i--) {
            printf("T minus %d and counting.\n", i);
        }
    #endif

    #if (EXERCISE == 1)
        int i = 1;
        while (i <= 128) {
            printf("%d ", i); // 1 2 4 8 ... 128
            i *= 2;
        }
    #endif

    #if (EXERCISE == 2)
        int i = 9384;
        do {
            printf("%d ", i); // 9384 938 93 9
            i /= 10;
        } while (i > 0);
    #endif

    #if (EXERCISE == 3)
        int i, j;
        for (i = 5, j = i - 1; i > 0 || j > 0; --i, j = i - 1) {
            printf("%d ", i);
            // i 5, j 4, 
            // i 4, j 3,
            // i 3, j 2, 
            // i 2, j 1,
            // i 1, j 0,
            // 5 4 3 2 1
        }
    #endif

    #if (EXERCISE == 4)
        int i;
        for (i = 0; i < 10; i++)
            printf("%d ", i); // 0 1 2 3 ... 9
        printf("\n");
        for (i = 0; i < 10; ++i)
            printf("%d ", i); // 0 1 2 3 ... 9
        printf("\n");
        for (i = 0; i++ < 10; )
            printf("%d ", i); // 1 2 3 ... 10
        printf("\n");
        for (i = 0; ++i < 10; )
            printf("%d ", i); // 1 2 3 ... 9
        printf("\n");

    #endif

    #if (EXERCISE == 5)
        int i = 10;
        while (i < 10) {
            printf("%d ", i); // nothing gets printed
            i++;
        }

        printf("\n");
        i = 10;
        for (; i < 10;) {
            printf("%d ", i); // nothing gets printed
            i++;
        }

        printf("\n");
        i = 10;
        do {
            printf("%d ", i); // 10
            i++;
        } while (i < 10);
    #endif

    #if (EXERCISE == 6)
        int i = 1;
        while (i <= 128) {
            printf("%d ", i); // 1 2 4 8 ... 128
            i *= 2;
        }
        printf("\n");
        for (i = 1; i <= 128; i *= 2) {
            printf("%d ", i);
        }
        printf("\n");
    #endif

    #if (EXERCISE == 7)
        int i = 9384;
        do {
            printf("%d ", i); // 9384 938 93 9
            i /= 10;
        } while (i > 0);
        printf("\n");
        for (i = 9384; i > 0; i /= 10) {
            printf("%d ", i);
        }
        printf("\n");     
    #endif

    #if (EXERCISE == 8)
        for (int i = 10; i >= 1; i /= 2) {
            printf("%d ", i++); // 10, 5, 3, 2, 1, 1, 1 ...
        }
        printf("\n");

    #endif

    #if (EXERCISE == 9)
        int i = 10;
        while ( i >= 1 ) {
            printf("%d ", i++);
            i /= 2;
        }

    #endif

    #if (EXERCISE == 10)
        int i = 0;
        while (i < 10) {            
            i++;
            if (i == 5) {
                printf("_ ");
                continue;
            }
            printf("%d ", i); // 1 2 3 4 ___ 6 7 8 9 10
        }
        printf("\n");
        
        i = 0;
        while (i < 10) {            
            i++;
            if (i == 5) {     
                printf("_ ");           
                goto SKIP;
            }            
            printf("%d ", i); // 1 2 3 4 _ 6 7 8 9 10
            SKIP: ;
        }
        printf("\n");
    #endif

    #if (EXERCISE == 11)
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            if (i % 2) // skip odd numbers (not dividble by 2)
                continue;
            sum += i; // sum = 2 + 4 + 6 + 8 = 20
        }
        printf("%d\n", sum);
    #endif

    #if (EXERCISE == 12)
        _Bool prime = 1;
        int number_of_primes = 0;
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        for (int n = 2; n <= 1000000; n++) {
            prime = 1; // reset prime flag
            for (int d = 2; (d * d) <= n; d++ ){ // much more efficient way to test prime numbers
            //for (int d = 2;  d <= (n / 2); d++ ){
                if ( n % d == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime) {
                number_of_primes++;
                //printf("%d\n", n);
            }
        }
        printf("Total number of primes: %d\n", number_of_primes);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%.10f seconds.\n", cpu_time_used);

    #endif

    #if (EXERCISE == 13)
        int n, m = 10;
        for (n = 0; m > 0; n++) {
            m /= 2;
        }
        printf("n: %d m: %d\n", n, m);
        printf("\n");

        m = 10;
        for (n = 0; m > 0; n++, m /= 2);
        printf("n: %d m: %d\n", n, m);
    #endif

    return 0;
}