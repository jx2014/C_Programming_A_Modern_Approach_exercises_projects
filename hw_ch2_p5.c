#include "stdio.h"
#include "math.h"
#include "time.h"


int main() {
    clock_t start, end;

    float y, x;
    printf("Enter value of x: ");
    scanf("%f", &x);

    start = clock();
    for (int n = 0; n <= x; n++) {
        y = (((( 3 * n + 2 ) * n - 5 ) * n - 1 ) * n + 7 ) * n - 6;
    }
    end = clock();
    printf("(((( 3 * x + 2 ) * x - 5 ) * x - 1 ) * x + 7 ) * x - 6 = %.5f\n", y);
    double cpu_time_used_2 = ((double) (end - start));

    start = clock();
    for (int n = 0; n <= x; n++) {
        y = 3*pow(n, 5) + 2*pow(n, 4) - 5*pow(n, 3) - pow(n, 2) + 7 * n - 6;
    }    
    end = clock();
    printf("3x^5+2x^4-5x^3-x^2+7x-6 = %.5f\n", y);
    double cpu_time_used_1 = ((double) (end - start));

    printf("time spent 1: %.30f\n", (float)cpu_time_used_1);

    printf("time spent 2 (Horner's rule): %.30f\n", (float)cpu_time_used_2);

    return 0;
}