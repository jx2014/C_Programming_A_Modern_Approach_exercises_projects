#if 0
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#endif

#define EXERCISE (16)

#if (EXERCISE == 1)

#define CUBE(x) (x*x*x)
#define REMAINDER_OF_4(n) (n % 4)
#define PROD_LESS_THAN_100(x, y) (((x * y) < 100) ? 1 : 0)

int main(void) {

    int a = 5, b = 20;
    printf("the cube of %d is %d\n", a, CUBE(a));
    printf("the remainder of %d / 4 is %d\n", 10, REMAINDER_OF_4(10));
    printf("Product of %d and %d is less than 100: %d\n", a, a, PROD_LESS_THAN_100(a, a));
    printf("Product of %d and %d is less than 100: %d\n", a, b, PROD_LESS_THAN_100(a, b));

    return 0;
}
#endif

#if (EXERCISE == 2)

#define NELEMS(a) ((int) (sizeof(a) / sizeof(a[0])))

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    double b[] = {10.0, 12.0};
    char c[] = {'a'};

    printf("# of elements in array a is %d\n", NELEMS(a));
    printf("# of elements in array b is %d\n", NELEMS(b));
    printf("# of elements in array c is %d\n", NELEMS(c));

    return 0;
}
#endif

#if (EXERCISE == 3)

#define DOUBLE(x) 2*x

int main(void) {
    printf("value of DOUBLE(1+2) is: %d\n", DOUBLE(1+2));     // 2 * 1 + 2 = 4
    printf("value of 4 / DOUBLE(2) is: %d\n", 4 / DOUBLE(2)); // 4 / 2 * 2 = 4
    return 0;
}
#endif

#if (EXERCISE == 4)

#define AVG(x, y)   (((x) + (y)) / 2)
#define AREA(x, y)  ((x) * (y))

int main(void) {

    printf("average of %d, %d = %d\n", 10+5, 15, AVG(10 + 5, 15));
    printf("area of %d and %d = %d\n", 5, 2, AREA(5, 2));

    return 0;
}
#endif

#if (EXERCISE == 5)

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c) )

int main(void) {
    char s[10];
    int i = 0;
    strcpy(s, "abcd");
    putchar(TOUPPER(s[++i])); // ('a' <= (s[++i]) && (s[++i]) <= 'z' ? (s[++i]) - 'a' + 'A' : (s[++i]) )
                              //            b            c                d             D

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[i++])); // ('a' <= (s[i++]) && (s[i++]) <= 'z' ? (s[i++]) - 'a' + 'A' : (s[i++]) )
                              //            0                                                     1
    return 0;
}
#endif

#if (EXERCISE == 6)
// DISP(sqrt, 3.0); will expand to printf("sqrt(%g) = %g\n", 3.0 sqrt(3.0));
#define DISP(f, x)  (printf(#f"(%g) = %g\n", (x), f(x)))

// DISP2(f, x, y); will work with two arguments
#define DISP2(f, x, y)  (printf(#f"(%g, %g) or %g^%g = %g\n", \
                        (x), (y), (x), (y), f(x, y)))

int main(void) {

    DISP(sqrt, 3.0);
    DISP2(pow, 2.0, 3.0);

    return 0;
}
#endif

#if (EXERCISE == 7)

#define GENERIC_MAX(type)               \
    type type##_max(type x, type y){    \
        return x > y ? x : y;           \
    }

int main(void) {
    
    GENERIC_MAX(long) // long long_max(long x, long y) {
                      //    return x > y ? x : y; }

    // below will not work
    //GENERIC_MAX(unsigned long)  // unsigned long unsigned long_max(unsigned long x, unsigned long y) {
                                //    return x > y ? x : y; }

    // this version will work
    typedef unsigned long ULONG;
    GENERIC_MAX(ULONG)
    
    printf("%u\n", ULONG_max(100.0, 200.0));

    return 0;
}
#endif

#if (EXERCISE == 8)

#define LINE_FILE1(x, y) "Line "#x" of file: "y
#define LINE_FILE2(x, y) LINE_FILE1(x, y)

#define LINE_FILE LINE_FILE2(__LINE__, __FILE__)

int main(void) {
    const char *str = LINE_FILE;
    printf("\n*** %s ***\n\n", str);
    return 0;
}
#endif

#if (EXERCISE == 9)
#define CHECK(x, y, n)  ( (((x) >= 0 && (x) <= ((n)-1)) &&      \
                             ((y) >= 0 && (y) <= ((n)-1))) ?    \
                             1 : 0 )

#define MEDIAN(x, y, z) ( ((((x) <= (y)) && ((y) <= (z))) || (((z) <= (y)) && ((y) <= (x)))) ? (y) :      \
                         (((((y) <= (x)) && ((x) <= (z))) || (((z) <= (x)) && ((x) <= (y)))) ? (x) : (z)))

#define POLYNOMIAL(x) ( 3*(x)*(x)*(x)*(x)*(x) + \
                        2*(x)*(x)*(x)*(x) - \
                        5*(x)*(x)*(x) - \
                        (x)*(x) + 7*(x) - 6)
int main(void) {

    int x, y, n, z;

    printf("\n*********\n");

    x = 1, y = 1, n = 2;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 1\n", x, y, n, CHECK(x, y, n));
    x = 2, y = 1, n = 2;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 0\n", x, y, n, CHECK(x, y, n));
    x = 2, y = 2, n = 2;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 0\n", x, y, n, CHECK(x, y, n));
    x = 2, y = 2, n = 3;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 1\n", x, y, n, CHECK(x, y, n));
    x = -1, y = 2, n = 3;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 0\n", x, y, n, CHECK(x, y, n));
    x = 1, y = 0, n = 3;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 1\n", x, y, n, CHECK(x, y, n));
    x = 0, y = -1, n = 3;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 0\n", x, y, n, CHECK(x, y, n));
    x = 0, y = 0, n = 1;
    printf("CHECK(%2d, %2d, %2d) = %d, expected: 1\n", x, y, n, CHECK(x, y, n));

    printf("\n*********\n");

    x = 0, y = 1, z = 2;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), y);
    x = 2, y = 1, z = 0;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), y);

    x = 1, y = 0, z = 2;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), x);
    x = 1, y = 2, z = 0;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), x);

    x = 0, y = 2, z = 1;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), z);
    x = 2, y = 0, z = 0;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), z);

    
    x = 1, y = 1, z = 1;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), z);
    x = 1, y = 1, z = 2;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), y);
    x = 1, y = 2, z = 1;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), x);
    x = 2, y = 1, z = 1;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), z);
    x = 2, y = 2, z = 1;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), y);
    x = 2, y = 2, z = 2;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), z);
    x = 1, y = 2, z = 2;
    printf("MEDIAN(%d, %d, %d) = %d, expected: %d\n", x, y, z, MEDIAN(x, y, z), z);
    
    
    printf("\n*********\n");

    x = 0;
    printf("(3*(%d)**5 + 2*(%d)**4 - 5*(%d)**3 - (%d)**2 + 7*(%d) - 6) = %2d, expected: -6\n", x, x, x, x, x, POLYNOMIAL(x));
    x = 1; 
    printf("(3*(%d)**5 + 2*(%d)**4 - 5*(%d)**3 - (%d)**2 + 7*(%d) - 6) = %2d, expected:  0\n", x, x, x, x, x, POLYNOMIAL(x));

    printf("\n*********\n");

    return 0;
}
#endif

#if (EXERCISE == 10)
int main(void) {

    // following functions cannot be created by parameterized Macro
    // parameters are evaulated more than once MAX(++i, n) will evaulate ++i each time i is called. 
    // can't use pointers
    // types are not checked.

    return 0;
}
#endif

#if (EXERCISE == 11)
#define ERROR(error_msg, index) fprintf(stderr, error_msg, index)
int main(void) {

    ERROR("Range error: index = %d\n", index);

    return 0;
}
#endif

#if (EXERCISE == 12)
#define M (10)
int main(void) {

    //#if M           // ok
    //#ifdef M        // ok
    //#ifndef M       // nok
    //#if defined(M)  // ok
    //#if !defined(M) // nok


    return 0;
}
#endif

#if (EXERCISE == 13)

#define N 100
void f(void);

int main(void) {
    f();
    #ifdef N
    #undef N
    #endif
    return 0;
}

void f(void) {
    #if defined(N)
        printf("N is %d\n", N);
    #else
        printf("N is undefined\n");
    #endif
}

#endif

#if (EXERCISE == 14)
#define N (10)
#define INC(x)      (x)+1
#define SUB(x, y)   (x)-(y)
#define SQR(x)      ((x) * (x))
#define CUBE(x)     (SQR(x) * (x)) 
#define M1(x, y)    x##y
#define M2(x, y)    #x #y

int main(void) {
    int a[N], i, j, k, m;

    #ifdef N
        i = j;
    #else
        j = i;
    #endif
    
    i = 10 * INC(j);
    i = SUB(j, k);
    i = SQR(SQR(j));
    i = CUBE(j);
    i = M1(j, k);
    puts(M2(i, j));

    #undef SQR
        i = SQR(j);
    #define SQR
        i = SQR(j);
    
    return 0;
}
#endif

#if (EXERCISE == 15)

#define ENGLISH (0)
#define FRENCH (0)
#define SPANISH (1)

#if ENGLISH
    #define MESSAGE "Insert Disk 1"
#elif FRENCH
    #define MESSAGE "Inserez Le Disque 1"
#elif SPANISH
    #define MESSAGE "Inserte El Disco 1"
#else
    #define MESSAGE "No language is selected."
#endif

int main(void) {
    
    printf("%s\n", MESSAGE);

    return 0;
}
#endif

#if (EXERCISE == 16)

#define IDENT(x)    PRAGMA(ident #x)
#define PRAGMA(x)   _Pragma(#x)

int main(void) {

    IDENT(foo) // #pragma ident "foo"

    return 0;
}
#endif
