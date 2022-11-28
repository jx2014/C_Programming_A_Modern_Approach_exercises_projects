/***********************************************
 * lcm.c find the least common multipler       *
 *       of two digits x1, and x2.             *
 *       Find integer a and b such that        *
 *       a * x1 = b * x2                       *
 *                                             *
 *       Generial algorithm:                   *
 *       For b from 1 to 100, find             *
 *       a = b * x2/x1 where a is closest      *
 *       to an integer value.                  *
 ***********************************************/ 

#include <stdio.h>
#include <math.h>
#define B_MAX (100)

int main(void) {
    double x1, x2, x, a_temp, err = 0.5, err1, err2;
    int a, b, b_temp;
    

    printf(" Enter x1 and x2: ");
    scanf("%lf %lf", &x1, &x2);
    x = x2/x1;

    for (b_temp = 1; b_temp <= B_MAX; b_temp++) {
        a_temp = b_temp * x;

        err1 = ceil(a_temp) - a_temp;
        err2 = a_temp - floor(a_temp);
        if ( err1 < err || err2 < err) { // found a potential integer a
            if (err1 < err2) {
                a = ceil(a_temp);
                err = err1;
            } else {
                a = floor(a_temp);
                err = err2;
            }
            b = b_temp;
        }
    }

    printf("  a * x1 = %3d * %-10.3f = %-10.3f\n", a, x1, a*x1);
    printf("  b * x2 = %3d * %-10.3f = %-10.3f\n", b, x2, b*x2);
}