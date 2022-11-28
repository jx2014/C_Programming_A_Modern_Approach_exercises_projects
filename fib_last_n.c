/***************************************
 *                                     * 
 *  fib    find the last digit of      *
 *         nth fibonacci sequence      * 
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
    int j = 0, k = 1, s;
    
    for (int i = 1; i <= n; i++) {
        s = (j + k) % 10;
        j = k;
        k = s;
        printf("The last digit of %3d ... %d\n", i, s);
    }    

}