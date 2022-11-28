#define PROJECT (4)

#if (PROJECT == 1)
// Modify quadratic.c of section 27.4
// a) Have the user enters the coefficients of the polynomial, a, b, and c
// b) Have the program test the discriminant before displaying the values of the roots
//    If the discriminant is negative, have the program display the roots in the same way
//    as before. If it's nonnegative, the the program display the roots as real numbers 
//    (without the imaginary part). E.g., x^2 + x - 2 = 0, the output would be:
//    root1 = 1, root2 = -2;
// c) Modify the program so that it displays a complex number with a negative imaginary part
//    as a - bi instead of a + -bi. E.g., 

#include <tgmath.h>
#include <complex.h>
#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("Enter the cofficient (a, b, c) for ax^2 + bx + c: ");   // part a
    scanf("%lf %lf %lf", &a, &b, &c);

    double discriminant = b * b - 4 * a * c; 
    double complex discriminant_sqrt = csqrt(discriminant);
    double complex root1 = (-b + discriminant_sqrt) / (2 * a);
    double complex root2 = (-b - discriminant_sqrt) / (2 * a);

    printf("root1 = %g", creal(root1));
    // part b and c
    discriminant >= 0 ? printf("\n") :  cimag(root1) > 0 ?                       \
                                        printf(" + %gi\n",      cimag(root1)):   \
                                        printf(" - %gi\n", -1 * cimag(root1));
    
    printf("root2 = %g", creal(root2));
    // double complex result    =    (cimag(root2));
    // double complex resultabs = abs(cimag(root2));
    discriminant >= 0 ? printf("\n") :  cimag(root2) > 0 ?                      \
                                        printf(" + %gi\n",      cimag(root2)):  \
                                        printf(" - %gi\n", -1 * cimag(root2));


    return 0;
}
#endif

#if (PROJECT == 2)
// convert Cartesian to Polar
// User enters a and b, and the program will display r and θ.

#include <stdio.h>
#include <tgmath.h>
#include <complex.h>

#define M_PI 3.14159265358979323846


int main(void) {
    double a, b;
    printf("Enter 'a' and 'b' on a Cartesian coordinate: ");
    scanf("%lf %lf", &a, &b);
    // double r = csqrt(a*a + b*b);    
    // double θ = atan2(b, a) / M_PI * 180;    
    double r = fabs(a + b * I);
    double θ = carg(a + b * I);
    printf("In polar coordinate: %.4f ∠%.4f° %.4f rad\n", r, θ / M_PI * 180, θ);

    return 0;
}
#endif

#if (PROJECT == 3)
// convert Polar to Cartesian
// User enters r and theta, and the program will display r and theta

#include <stdio.h>
#include <tgmath.h>
// #include <complex.h>

#define M_PI 3.14159265358979323846

int main(void) {
    double r, θ;
    printf("Enter 'r' and 'θ°' on a Polar coordinate: ");
    scanf("%lf %lf", &r, &θ);
    θ *= M_PI / 180;
    double x = r * cos(θ);
    double y = r * sin(θ);
    printf("In Cartesian coordinate: %.4f %c %.4fi\n",      fabs(x),   \
                                    signbit(y) ? '-' : '+', fabs(y));


    return 0;
}
#endif

#if (PROJECT == 4)
// Displays the nth roots of unity given a positive integer n.
// nth roots of unity is given by e^(2piik/n), k is an integer between 0 to n - 1

#include <stdio.h>
#include <tgmath.h>
//#include <complex.h>

#define M_PI 3.14159265358979323846

int main(void) {
    int k, n;
    double complex r;

    printf("Enter nth root: ");
    scanf("%d", &n);
    printf("The nth root unity are:\n");
    for (k = 0; k < n; k++) {
        r = exp(2 * M_PI * k * I / n);
        printf("k=%-3d: %7.4f %7.4fi, %7.4f ∠%9.4f° %7.4f rad\n", k, creal(r), cimag(r), fabs(r), carg(r) / M_PI * 180, carg(r));
    }

    printf("\n");

    return 0;
}
#endif
