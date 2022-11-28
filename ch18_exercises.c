#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define EXERCISE (15)

#if (EXERCISE == 1)
int main(void) {
    //a) static char **lookup(int level);
    // storage class: static, internal linkage
    // type qualifier: none
    // type specifier: char **, pointer to character array
    // declarators: lookup() function that takes an integer as argument, and returns a pointer to a character array. 
    // initializers: none

    //b) volatile unsigned long io_flags;
    // storage class: auto
    // type qualifier: volatile
    // type specifier: unsigned long
    // declarators: unsigned long io_flags
    // initializers: none

    //c) extern char *file_name[MAX_FILES], path[];
    // storage class: extern
    // type qualifier: none
    // type specificer: char
    // declarators: an array of MAX_FILES number of pointers, a character array: path[]
    // initializers: none

    //d) static const char token_buf[] = "";
    // storage class: extern
    // type qualifier: const
    // type specifier: char 
    // declarators: a character array
    // initializers: ""

    return 0;
}
#endif

#if (EXERCISE == 2)
int main(void) {
    // a) which storage class is used primarily to indicate that a variable or function can be shared by several files?
    //      extern
    // b) suppose that a variable x is to be shared by several functions in one file but hidden from functions in other files.
    //    which storage class should x be declared to have?
    //      static
    // c) which storage classes can affect the storage duration of a variable?
    //      static abd extern
    
    return 0;
}
#endif

#if (EXERCISE == 3)
int main(void) {
    extern float a; // auto storage duration, file scope, external linkage

    void f(register double b) { // b is register, block scope, no linkage
        static int c; // c is static, block scope, no linkage, retains its value after f is finished.
        auto char d; // auto, block scope, no linkage, d loses its value after f is finished.
    }

    return 0;
}
#endif

#if (EXERCISE == 4)
int main(void) {

    int f(int i) {
        static int j = 0;
        return i * j++;
    }
    // 1st j = 0 f(10) = 0
    // 2nd j = 1 f(10) = 10
    // 3rd j = 2 f(10) = 20
    // 4th j = 3 f(10) = 30
    // 5th j = 4 f(10) = 40
    // 6th j = 5 f(10) = 50

    return 0;
}
#endif

#if (EXERCISE == 5)
int main(void) {
    // a) Every variable with static storage duration has file scope. False, not if the variable is created inside a function block.
    // b) Every variable declared inside a function has no linkage. False, extern int a; where a can be defined in other files, external linkage.
    // c) Every variable with internal linkage has static storage duration. True.
    // d) Every parameter has block scope. True.

    return 0;
}
#endif

#if (EXERCISE == 6)

void print_error(const char *message);

int main(void) {
    print_error("error message 1.");
    print_error("error message 2.");
    print_error("error message 3.");
    print_error("error message 4.");
    print_error("error message 5.");

    return 0;
}

void print_error(const char *message) {
    static int n = 1;
    printf("Error %d: %s\n", n++, message);

}
#endif

#if (EXERCISE == 7)

int i = 20;
int j = 30;
const int const_i = 10;
const int *p_const_a = &i;
const int *p_const_b = &const_i;
int *const p_const_d = &j;

// error thrown by compiler
// int *p_const_c = &const_i;



int main(void) {
     // error by compiler
     // *p_const_a = 21;

     // error by compiler
     // p_const_d = &i;

    return 0;
}
#endif

#if (EXERCISE == 8)
int main(void) {
    
    char (*x[10]) (int); // array of 10 pointers to functions; each pointer is a function that takes an 
                         // int argument, returns a character.
    
    int (*x(int))[5]; // pointer to a function x, that takes one int argument
                      // and returns an array of 5 integers.

    float *(*x(void))(int); // x is a function that takes no argument, that returns a pointer to a function
                            // with an int argument that retruns a pointer to a float value.

    void (*x(int, void (*y)(int)))(int); // A pointer to function x, that takes an int, and
                                         // a void function y, which takes int as argument but no return values. 
                                         // Function x returns a pointer to a function with an int argument but'
                                         // no return value. 

    return 0;
}
#endif

#if (EXERCISE == 9)

// Exercise 9.a
#define FUNCTION_CHAR(NUM)           \
        char fn_char_##NUM(int x) {  \
            printf("fn_char_" #NUM ", x is: %d\n", x); \
            return 'a' - 1 + NUM;              \
        }

// expands to: 
// char fn_char_1(int x) { printf("fn_char_" "1" ", x is: %d\n", x); return 'a' - 1 + 1; };
FUNCTION_CHAR(1);
FUNCTION_CHAR(2);
FUNCTION_CHAR(3);
FUNCTION_CHAR(4);
FUNCTION_CHAR(5);
FUNCTION_CHAR(6);
FUNCTION_CHAR(7);
FUNCTION_CHAR(8);
FUNCTION_CHAR(9);
FUNCTION_CHAR(10);

// (a) char (*x[10])(int);
char (*x_a[10])(int);

typedef char a_Fn(int);
typedef a_Fn *a_Fn_ptr;
typedef a_Fn_ptr a_Fn_ptr_array[10];
a_Fn_ptr_array x_a_t;

// Exercise 9.b

void exercise_b(int (*x_b(int))[5], int n) {
    x_b(n);
}

// (b) int (*x_b(int))[5]
// x_b is a pointer to a function that takes one int argument, and returns 
// a pointer to an interger array of 5 elements. 
typedef int b_Array[5];
typedef b_Array *b_Array_ptr;

int array[5];

b_Array_ptr fn_array(int n) {
    for (int i = 0; i < 5; i++) {
        array[i] = n + i;
        printf("array[%d] = %d\n", i, n+i);
    }
    return &array;
};

int (*fn_array2(int n))[5] {
    for (int i = 0; i < 5; i++) {
        array[i] = n + i;
        printf("array2[%d] = %d\n", i, n+i);
    }
    return &array;
}

// Exercise 9.c
// float *(*x(void))(int); 
// x is a pointer to a function takes no argunment but returns a pointer to a second function;
// this second function takes one int as argument and returns a pointer to a float value.
float fy;
float *inner_x(int y) {
    fy = (float) y;
    return &fy;
}

float *(*x_c(void))(int) {
    return &(inner_x);
}

typedef float *Fn_c(int);
typedef Fn_c *Fn_c_ptr;


Fn_c_ptr x_2c(void) {
    return &(inner_x);
}

// Exercise 9.d
// void (*x(int, void (*y)(int)))(int);

typedef void Fn_d(int);
typedef Fn_d *Fn_d_ptr;
typedef void Fn_d_inner(int);

void Fn_d_y(int x) {
    printf("x is: %d\n", x);
}

void Fn_d_y2(int x) {
    printf("x + 10 is: %d\n", x+10);
}

Fn_d_ptr x_d(int a, Fn_d_inner y) {
    (*y)(a);
}

int main(void) {
    
    // exercise a)
    x_a[0] = fn_char_1;
    x_a[1] = fn_char_2;
    x_a[2] = fn_char_3;
    x_a[3] = fn_char_4;
    x_a[4] = fn_char_5;
    x_a[5] = fn_char_6;
    x_a[6] = fn_char_7;
    x_a[7] = fn_char_8;
    x_a[8] = fn_char_9;
    x_a[9] = fn_char_10;

    (*x_a[0])(1); // same as fn_char_1(1)
    (*x_a[0])(2); // same as fn_char_1(2)
    (*x_a[1])(3); // same as fn_char_2(3)
    (*x_a[2])(4); // same as fn_char_3(4)

    // exericse a, using typedef
    printf("\nUsing typedef.\n");
    x_a_t[0] = fn_char_1;
    x_a_t[1] = fn_char_2;
    x_a_t[2] = fn_char_3;
    x_a_t[3] = fn_char_4;
    x_a_t[4] = fn_char_5;
    x_a_t[5] = fn_char_6;
    x_a_t[6] = fn_char_7;
    x_a_t[7] = fn_char_8;
    x_a_t[8] = fn_char_9;
    x_a_t[9] = fn_char_10;

    (*x_a_t[0])(1); // same as fn_char_1(1)
    (*x_a_t[0])(2); // same as fn_char_1(2)
    (*x_a_t[1])(3); // same as fn_char_2(3)
    (*x_a_t[2])(4); // same as fn_char_3(4)

    // exercise b)
    fn_array(123);
    fn_array2(124);

    // exercise c)
    float *c;
    c = (*(x_c()))(5); // *c and fy is 5
    *(x_2c())(112); // fy now is 112

    // exercise d)
    x_d(123, Fn_d_y);
    x_d(123, Fn_d_y2);

    return 0;
}

#endif

#if (EXERCISE == 10)
// a) p is a pointer to a function with a character pointer argument that returns a character pointer.
char *((*p)(char)); // book answer: char *(*p)(char);
typedef char *Fn_a;
char *a;
Fn_a test_fn_a(char c) {  
    a = &c;
    return a;
}

// b) test_fn_b is a function with two arguments: p, a pointer to a structure with tag t, and n, a long integer.
//    test_fn_b returns a pointer to a function that has no arguments and returns nothing.
struct t {
    int value;
};

struct t t_test = {.value = 1};

void dummy_fn(void) {
    printf("This is a dummy function that takes no argument and returns nothing.\n");
}
typedef void Fn_b(void);
typedef Fn_b *Fn_b_ptr;

Fn_b_ptr test_fn_b(struct t *p, long n) {
    printf("test_fn_b n: %ld\n", n);
    printf("test_fn_b st->value: %d\n", p->value);

    return &dummy_fn;
}

// without using typedef
// book answer: 
// void *dummy_f(struct t *p, long n)(void);
void (*dummy_f(struct t *p, long n))(void) {
    printf("ptr_to_dummy_f n: %ld\n", n);
    printf("ptr_to_dummy_f st->value: %d\n", p->value);
    return &dummy_fn;
}

void (*(*ptr_to_dummy_f)(struct t*, long))(void) = &dummy_f;

// c) a is an array of four pointers to functions that have no arguments and return nothing. The elements
//    of a initially point to functions named insert, search, update, and print.

void insert(void) {printf("Called insert()\n");};
void search(void) {printf("Called search()\n");};
void update(void) {printf("Called update()\n");};
void print(void) {printf("Called print()\n");};

// book answer:
// void (*fn_c[])(void) = {insert, search, update, print};
void (*fn_c[4])(void);
typedef void Fn_c_t(void);
typedef Fn_c_t *Fn_c_ptr_t;
typedef Fn_c_ptr_t Fn_c_ptr_array_t[4];

// d) fn_d is an array of 10 pointers to functions with two int arguments that return structures with tag t.
struct t t2 = {.value=0};
struct t Fn_d_tester(int a, int b) {
    struct t t_test = {.value = a+b};
    return t_test;
}

// book answer:
// struct t (*fn_d[10])(int, int);
struct t (*fn_d[10])(int, int);

typedef struct t Fn_d(int, int);
typedef Fn_d *Fn_d_ptr;
typedef Fn_d_ptr Fn_d_ptr_array[10];


int main(void) {
    // test for exercise a)
    test_fn_a('X'); // *a is also  X.    

    // test for exercise b)
    void * dummy_fn_ptr;
    void (*dummy_fn_ptr2)(void);
    dummy_fn_ptr = test_fn_b(&t_test, 123);
    dummy_fn_ptr2 = ptr_to_dummy_f(&t_test, 12345);
    ((void (*)(void)) dummy_fn_ptr)();  // will execute dummy_fn() and prints out a line to stdout.
    dummy_fn_ptr2();  // will execute dummy_fn() and prints out a line to stdout.

    // test for exercise c)
    // void (*fn_c[4])(void) = {insert, search, update, print};
    fn_c[0] = insert;
    fn_c[1] = search;
    fn_c[2] = update;
    fn_c[3] = print;

    (*fn_c[0])(); // same as insert();
    (*fn_c[1])(); // same as search();
    // also leagel
    fn_c[2](); // same as update();
    fn_c[3](); // same as print();
    // using typedef
    printf("\nUsing typedef:\n");
    Fn_c_ptr_array_t fn_c_t = {insert, search, update, print};
    fn_c_t[0]();
    fn_c_t[1]();
    fn_c_t[2]();
    fn_c_t[3]();

    // test for example d
    struct t test_t;
    printf("\nExercise d)\n");
    for (int i = 1; i <= 10; i++) {
        fn_d[i-1] = Fn_d_tester;
        test_t = (*fn_d[i-1])(i, i);
        printf("*(fn_d)[%d](%d, %d) -- test_t.value: %d\n", i-1, i,i,test_t.value);
    }

    // using typedef
    Fn_d_ptr_array fn_d_t = {
        Fn_d_tester, 
        Fn_d_tester,
        Fn_d_tester, 
        Fn_d_tester, 
        Fn_d_tester, 
        Fn_d_tester, 
        Fn_d_tester, 
        Fn_d_tester, 
        Fn_d_tester, 
        Fn_d_tester, 
    };

    printf("\nTest with typedef.\n");
    for (int i = 1; i <= 10; i++) {
        test_t = (*fn_d_t[i-1])(i, i);
        printf("*(fn_d_t)[%d](%d, %d) -- test_t.value: %d\n", i-1, i,i,test_t.value);
    }

    return 0;
}
#endif

#if (EXERCISE == 11)

int some_test_array[10];

// int f(int)[]; this is illegal, since function can't return arrays
// this is legal, pointer to a function that takes an int argument, and returns
// pointer to an integer array.
int (*f(int n))[]{
    for (int i = 0; i < n; i++) {
        some_test_array[i] = i;
    }
    return &some_test_array;
}

int test_fn(int x) {    
    return (float) x+3;
}
// int g(int)(int); this is illegal, since function can't return functions
// This is legal, pointer to a function that takes (int) argument, and returns
// a pointer to a function that takes (int) argument and returns an int.
int (*g(int y))(int) {
    printf("g(y): %d\n", y);
    return &test_fn;
}

typedef int Fn_b (int);
typedef Fn_b *Fn_b_ptr;

// int a[10](int); this is illegal, since array can't be functions.
// This is legal, an array of function pointers; each pointer points to a 
// function that takes (int) argument and returns an int.
int (*a[10])(int);

typedef int Fn_c (int);
typedef Fn_c *Fn_c_ptr;
typedef Fn_c_ptr Fn_c_ptr_array[10];

int main(void) {
    
    // testing int (*f(int n))[]
    f(9);

    // testing for int (*g(int))(int)
    Fn_b_ptr p;
    void *q;
    (*g(5))(20); // print out g(y): 5, and return 23
    p = g(97); // print out g(y): 97
    q = g(98); // print out g(y): 98

    p(123); // 123 + 3 = 126
    ((int (*)(int)) q)(20); // 20 + 3 = 23

    // testing for (int) (*a[10])(int)
    Fn_c_ptr_array w = {test_fn, test_fn, test_fn, test_fn, test_fn, \
                        test_fn, test_fn, test_fn, test_fn, test_fn};

    (w[0])(10); // returns 13;

    a[0] = test_fn;
    a[1] = test_fn;
    a[2] = test_fn;

    a[0](123); // returns 126;

    return 0;
}
#endif

#if (EXERCISE == 12)
// f is a pointer of a function that takes two arguments.
// First argument is a pointer to a function that takes long integer and returns a float;
// second argument is a character.
// f returns a pointer to a function that takes a double digit and returns an int.

float test_fn_inner(long x) {
    printf("This is the inner function - (%%ld): %ld, (%%.3f): %.3f\n", x, (float) x);
    return (float) x;
}

int test_fn_outter(double x) {
    printf("This is the outter function - (%%.3lf): %.3lf, (%%d): %d\n", x, (int) x);
    return (int) x;
}

int (*f(float (*) (long), char *)) (double);
int (*f(float (*inner_f) (long), char *c)) (double) {    
    float x = (*inner_f)((long) c[0]);
    printf("This is the f function - c: %s, x: %.3f\n", c, x);
    return &test_fn_outter;
}

typedef int Fn(double);
typedef Fn *Fn_ptr;

int main(void) {
    Fn_ptr test_fn;
    test_fn = f(test_fn_inner, "abcdefg");
    test_fn(123);    

    return 0;
}



#endif

#if (EXERCISE == 13)
#define PI (3.1415926)

int main(void) {
    
    char c = 65; // legal
    //static int i = 5, j = i * i; // illegal,  the initializer for a variable with static storage 
                                 // duration must be a constant expression, and i * i doesn't qualify.
    double d = 2 * PI; // legal
    double angles[] = {0, PI / 2, PI, 3 * PI / 2};

    printf("%d %d\n", i, j);

    return 0;
}
#endif

#if (EXERCISE == 14)
int main(void) {
    /*
        What kind of variables cannot be initialized?

        (a) Array variables
        (b) Enumeration variables
        (c) Structure variables
        (d) Union variables
        (e) None of the above <---
    */

    return 0;
}
#endif

#if (EXERCISE == 15)
int main(void) {
    /*
        What property of a variable determines whether or not it has
        a default initial value?
        (a) Storage duration <--- Variables with static storage duration are initialized
                                  to zero by default; variables with automatic storage 
                                  duration have no default initial value.
        (b) Scope
        (c) Linkage
        (d) Type

    */

    return 0;
}
#endif
