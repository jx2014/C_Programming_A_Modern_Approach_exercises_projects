#define EXERCISE (5)

#if (EXERCISE == 0)

// #define NDEBUG
#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <setjmp.h>
#include <errno.h>

void handler(int SIG);
void raise_sig(void);

jmp_buf env;

void f1(void);
void f2(void);

int main(void) {
    int i = 2;    
    // assert(0 <= i && i < 10);

    // testing for error handling
    /*
    void (*orig_handler)(int);

    printf("Installing handler for signal %d\n", SIGINT);
    orig_handler = signal(SIGINT, handler);
    raise_sig();

    printf("Changing handler to SIG_IGN\n");
    signal(SIGINT, SIG_IGN);
    raise_sig();

    printf("Restoring original handler\n");
    signal(SIGINT, orig_handler);
    raise_sig();

    // if the original handler for SIGINT is SIG_IGN, we will see below message printed.
    // if the original handler for SIGINT is SIG_DFL, program will termiante before below message is printed.
    printf("Program terminates normally\n");
    */

    // Testing for setjmp and long_jmp
    int n = setjmp(env);
    if (n == 0)
        printf("setjmp returned 0\n");    
    else if (n == 2) {
        printf("setjmp returns 2\n");
    } else {
        printf("Program terminates: longjmp called\n");
        return 0;
    }

    f1();
    printf("Program terminates normally\n");
        
    return 0;
}

void f1(void) {
    printf("f1 begins\n");
    f2();
    printf("f1 returns\n");
}

void f2(void) {
    printf("f2 begins\n");
    longjmp(env, 0); // longjmp will cause setjmp to return the value of the second argument, if argument is 0, setjmp will return 1.
    printf("f2 returns\n");
}

void handler(int sig) {
    printf("Handler called for signal %d\n", sig);
}

void raise_sig(void) {
    raise(SIGINT);
}

#endif

#if (EXERCISE == 1)
int main(void) {
    // assert is best suited to catch problem that should never occur if the program is correct.
    // because assert needs to know the type of problems to occur before hand.
    // example of problems that are beyond the contrl of the program:
    // 1) hardware issues
    // 2) problems from external programs 
    // 3)


    return 0;
}
#endif

#if (EXERCISE == 2)
// write a call to assert that causes a program to terminate if a varaible named top
// has the value NULL

#include <assert.h>
#include <stdio.h>

int main(void) {
    int some_number = 0;
    int * top = &some_number;

    assert(top != NULL);

    printf("top is not NULL.\n");

    top = NULL;

    assert(top != NULL);

    printf("Program did not terminate because of assert.\n");

    return 0;
}
#endif

#if (EXERCISE == 3)

int main(void) {
    // see ch24\ch24_exercises\ch24_exercise3.c
    //     ch24\ch24_exercises\stackADT2_exercise3.c

    return 0;
}
#endif

#if (EXERCISE == 4)


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


// try_math_fcn is a wrapper function that calls a match function
// with double argument and returns a doulbe argument if math 
// function call success, it returns the value.
// if not, then perror to print out an error message.
double try_math_fcn(double (*f)(double), double x, char *msg);

// Use a macro that has the same effect as try_math_fcn, but builds
// the error message from the function's name.
#define TRY_MATCH_FCN(f, x) try_math_fcn(f, x, "Error in call of "#f)

int main(void) {
    double y;

    y = try_math_fcn(sqrt, 3, "Error in call of sqrt");
    //y = try_math_fcn(sqrt, -3, "Error in call of sqrt");
    y = TRY_MATCH_FCN(sqrt, 3);
    //y = TRY_MATCH_FCN(sqrt, -3);
    y = TRY_MATCH_FCN(sqrt, -0.3);

    printf("End of the program is no error occurs\n");
    return 0;
}

double try_math_fcn(double (*f)(double), double x, char *msg) {
    double y;
    errno = 0;
    y = (*f)(x);    
    if (errno != 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return y;
}


#endif

#if (EXERCISE == 5)

int main(void) {
    // see ch24\ch24_exercises\ch24_exercise5.c
    

    return 0;
}
#endif
