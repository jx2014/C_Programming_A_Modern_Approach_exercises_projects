#include "stdio.h"

#define PI 3.1415926f
#define SCALE_FACTOR (4.0f/3.0f)

int main() {
    float r = 1.0, v = 0.0;
    printf("Enter radius in mm to calculate volume: ");
    scanf("%f", &r);
    v = SCALE_FACTOR * PI * r * r * r;
    printf("Volumn is %.2f cubic mm\n", v);

    return 0;
}
