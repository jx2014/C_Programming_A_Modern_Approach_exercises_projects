
#include <stdio.h>


#define SECTION3P1 (1)
#define SECTION3P2 (2)

#ifndef SECTION_CHOOSE
#define SECTION_CHOOSE (SECTION3P2)
#endif

int main(void) {

    #if (SECTION_CHOOSE == SECTION3P1)
    int i;
    float x;

    i = 40;
    x = 839.21f;

    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);

    // Alert(bell)      \a
    // Backspace        \b
    // New line         \n
    // Horizontal tab   \t
    printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
    printf("\"Hello!\"\n");
    printf("\\\\\\\n");
    printf("\a\a\a\a\a");
    #endif
    
    #if (SECTION_CHOOSE == SECTION3P2)
    int i, j;
    float x, y;

    printf("Enter four digits, seperate each with a comma:\ndecimal, decimal, float, float: ");
    scanf("%d,%d,%f,%f", &i, &j, &x, &y);
    printf("i: %p, j: %d, x: %f, y: %f\n", &i, j, x, y);
    #endif

    return 0;
}