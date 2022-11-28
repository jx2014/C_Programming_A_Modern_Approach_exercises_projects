#include "stdio.h"

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main() {
    float f, c;
    printf("Enter a temperature in F: ");
    scanf("%f", &f);
    c = ( f - FREEZING_PT ) * SCALE_FACTOR;
    printf("%.1f F is %.1f C", f, c);

    return 9;
}