/***************************************
 *                                     * 
 *  fib    find nth fibonacci sequence * 
 *         fib.exe 3                   *
 *         3                           *
 **************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 1) {
        return EXIT_FAILURE;
    }
    char *p;
    unsigned long n = strtoul(argv[1], &p, 10);
    unsigned long long j = 0, k = 1, s;

    if (n == 0)
        s = 0;
    else if (n == 1)
        s = 1;
    else {
        for (int i = 2; i <= n; i++) {
            s = j + k;
            j = k;
            k = s;
        }
    }

    printf("The Fibonacci sequency of %d is %llu\n", n, s);

}