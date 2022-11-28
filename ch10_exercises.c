#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define EXERCISE (3)

#if (EXERCISE == 1)

    int a;

    void f(int b) {
        int c;      // parameter: b, variable c, a
    }

    void g(void) {
        int d;      // variable d, a
        { int e;}   // d e and a
    }
    int main(void) {
        int f;      // variable f, a
        return 0;
    }

#endif

#if (EXERCISE == 2)
    int b, c;

    void f(void) { 
        int b, d;       //b, d, c
    }

    void g(int a) {
        int c;          // para a, internal c, external b
        {
            int a, b;   // internal a, b, c, 
        }
    }

    int main(void) {
        int c, d;       // internal c, d, external b
    }


#endif

#if (EXERCISE == 3)

    int i = 0;

    int main(void) {
        int i = 1;

        for (int i = 2; i < 10; i++) {
            printf("%d\n", i);
        }

    }
#endif