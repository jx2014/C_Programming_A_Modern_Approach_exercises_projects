#define EXERCISE (4)

#if (EXERCISE == 1)
// check the support intN_t and uintN_t
#include <stdint.h>
int main(void) {
    // for windows 10 MSVC 14.33.31629
    // the followings intN_t and uintN_t are supported:
    // typedef signed char        int8_t;
    // typedef short              int16_t;
    // typedef int                int32_t;
    // typedef long long          int64_t;
    // typedef unsigned char      uint8_t;
    // typedef unsigned short     uint16_t;
    // typedef unsigned int       uint32_t;
    // typedef unsigned long long uint64_t;
    
    return 0;
}
#endif

#if (EXERCISE == 2)
//#include <stdio.h>
//#include <stdint.h>

#define INT32_C(n) (n ## L)
#define INT64_C(n) (n ## LL)
#define UINT32_C(n) (n ## LU)
#define UINT64_C(n) (n ## LLU)

// use to define a new function

int main(void) {
    long int a = INT32_C(1);
    long long int b = INT64_C(2);
    unsigned long int c = UINT32_C(1);
    unsigned long long int d = UINT64_C(2);
    return 0;
}
#endif

#if (EXERCISE == 3)

#include <inttypes.h>
#include <stdio.h>
#include <limits.h>

int main(void) {

    // (a)
    int a = 127; // original type
    printf("original type int: %d; ", a);
    printf("new type int8_t: %"PRId8 "\n", (int8_t) a); // new type is int8_t

    // (b)
    int b = 99965535;
    printf("original type int: %12.4d: ", b);
    printf("new type int32_t: %12.4"PRId32 "\n", (int32_t) b);

    // (c)
    unsigned int c = 0xffffffff;
    printf("original type unsigned int: %-6o: ", c);
    printf("new type uint16_t: %"PRIu16 "\n", (uint16_t) c);

    // (d)
    unsigned int d = 0xffffffff;
    printf("original type unsigned int: %#x: ", d);
    printf("new type uint64_t: %#"PRIx64 "\n", (uint64_t) d);

    return 0;
}
#endif

#if (EXERCISE == 4)
#include <tgmath.h>
#include <math.h>
#include <complex.h>

int main(void) {
    int i;
    float f;
    double d;
    long double ld;
    float complex fc; // uses _Complex from <tgmath.h>; expands to float _Complex fc;
    double complex dc; // uses _Complex from <tgmath.h>; expands to double _Complex dc; 
    long double complex ldc; // uses _Complex from <tgmath.h>; expands to long double _Complex ldc; 

    tan(i);     // tan(i)
    fabs(f);    // fabsf(f)
    asin(d);    // asinl(d)
    exp(ld);    // expl(ld)
    log(fc);    // clogf(fc)
    acosh(dc);  // acoshl(dc)
    nexttoward(d, ld);  // nexttowardl(d, ld);
    remainder(f, i);    // fremainderf(f, i);
    copysign(d, ld);    // copysignl(d, ld);
    carg(i);            // __carg_d(i);
    cimag(f);           // cimagf(f);


    return 0;
}
#endif
