
#include "stdio.h"

#define EXERCISE (5)

int main(void) {

    #if (EXERCISE == 1)
        printf("%6d, %4d\n", 86, 1040);
        printf("%12.5e\n", 30.253);
        printf("%.4f\n", 83.162);
        printf("%-99.10g\n", .0000009979);
    #endif

    #if (EXERCISE == 2)
        float x = 12.3333f;
        printf("%-8.1e\n", x);
        printf("%20.6e\n", x);
        printf("%-8.3f\n", x);
        printf("%6.0f\n", x);
    #endif

    #if (EXERCISE == 3)
        

        //"%d" is equivalent to " %d"
        int a;   
        printf("%%d: ");
        scanf("%d", &a);
        printf("%d\n", a);

        printf(" %%d: ");
        scanf(" %d", &a);
        printf("%d\n", a);
        

        //"%d-%d-%d" is NOT equivalent to "%d -%d -%d"
        /*
        int b, c, d;
        printf("%%d-%%d-%%d: ");
        scanf("%d-%d-%d", &b, &c, &d);
        printf("%d %d %d\n", b, c, d);

        printf("%%d -%%d -%%d: ");
        scanf("%d -%d -%d", &b, &c, &d);
        printf("%d %d %d\n", b, c, d);
        */
        

        // "%f" is NOT equivalent to "%f "
        /*
        float e;
        printf("%%f: ");
        scanf("%f", &e);
        printf("%f\n", e);

        printf("%%f :");
        scanf("%f ", &e);
        printf("%f\n", e);
        */

        // "%f,%f" is equivalent to "%f, %f"
        /*
        float f;
        printf("%%f,%%f: ");
        scanf("%f,%f", &e, &f);
        printf("%f %f\n", e, f);

        printf("%%f, %%f: ");
        scanf("%f, %f", &e, &f);
        printf("%f %f\n", e, f);
        */
    #endif

    #if (EXERCISE == 4)
        int i = 0, j = 0;
        float x = 0;

        printf("Enter three digits: ");
        scanf("%d%f%d", &i, &x, &j);
        printf("%d, %f, %d\n", i, x, j);
    #endif

    #if (EXERCISE == 5)
        float i = 0, j = 0;
        int x = 0;

        printf("Enter three digits: ");
        scanf("%f%d%f", &i, &x, &j);
        printf("%f, %d, %f\n", i, x, j);
    #endif



    return 0;
}