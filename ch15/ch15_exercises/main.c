/********************************
 * Exercise 5 from chapter 15   *
 * ******************************/

#include <stdio.h>
#include "f1.h"

int main(void) {

    printf("\n************************\n");
    printf("calling f1() from main():\n");        
    f1(13);

    printf("\n************************\n");
    printf("calling f3() from main():\n");
    f3();

    return 0;
}


/*************************************************************************************
 *                                                                                   *
 * Questions for Exercise 6:                                                         *
 *  a) Which files need to be compiled when the program is built the first time?     *
 *     main.c, f1.c, f2.c                                                            *
 *     .\mingw32-make                                                                *
 *     gcc -c main.c                                                                 *
 *     gcc -c f1.c                                                                   *
 *     gcc -c f2.c                                                                   *
 *     gcc -o demo main.o f1.o f2.o                                                  *
 *                                                                                   *
 *  b) if f1.c is changed, which files need to be recompiled?                        *
 *     f1.c               // f2.c will not be recompiled.                            *
 *                        // even when f2.c calls function from f1.c                 *
 *                        // as long as the definition in f1.h does not change,      *
 *                        // f2.c will not recompile.                                *
 *     .\mingw32-make                                                                *
 *     gcc -c f1.c                                                                   *
 *     gcc -o demo main.o f1.o f2.o                                                  *
 *                                                                                   *
 *  c) if f1.h is changed, which files need to be recompiled?                        * 
 *     f1.c, main.c                                                                  *
 *                                                                                   * 
 *  d) if f2.h is changed, which files need to be recompiled?                        * 
 *     f2.c                                                            *
 *                                                                                   *   
 * ***********************************************************************************/

