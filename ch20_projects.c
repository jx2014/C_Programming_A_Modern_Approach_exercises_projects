#define PROJECT (1)

#if (PROJECT == 1)

#include <stdio.h>

struct float_s{
    unsigned int frac: 23;
    unsigned int exp:   8;
    unsigned int sign:  1;
};

union float_u {
    float float_num;
    struct float_s s_float;
};

int main(void) {

    union float_u float_union;
    float_union.float_num = -2.0f; // expect sign 1, exp 128, frac 0
    return 0;
}
#endif
