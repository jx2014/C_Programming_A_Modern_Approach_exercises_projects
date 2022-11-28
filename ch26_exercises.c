#define EXERCISE (13)


#if (EXERCISE == 0)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct city_info {
    char *city;
    int miles;
};

int compare_cities(const void *key_ptr, const void *element_ptr) {
    return strcmp((char *) key_ptr, ((struct city_info *) element_ptr)->city);
}

void exit_msg(void) {
    printf("clean up!\n");
}

void test(int num) {
    if (num == 0)
        printf("num is 0\n");
    else
        exit(1);
}

int main(void) {
    atexit(exit_msg);
    int a;
    char city_name[81];
    struct city_info *ptr;
    const struct city_info mileage[] ={
        {"Berlin",   3965}, {"CalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcuttaCalcutta", 7918}
    };
    printf("Enter city name: ");
    scanf("%80[^\n]", city_name);
    printf("Enter a digit: ");
    scanf("%d", &a);
    test(a);
    ptr = bsearch(city_name, mileage, sizeof(mileage) / sizeof(mileage[0]),
                                      sizeof(mileage[0]), compare_cities);
    
    printf("Just before return 0\n");
    return 0;
}
#endif

#if (EXERCISE == 1)
// Using variable argument to find maximum int

#include <stdio.h>
#include <stdarg.h>

// usage: find_max(3, 0, 10, 11) will return 10
int find_max(int n, ...) {
    va_list ap;
    int i, cur, max;
    va_start(ap, n);
    max = va_arg(ap, int);

    for (i = 1; i < n; i++) {
        cur = va_arg(ap, int);
        if (cur > max)
            max = cur;
    }
    va_end(ap);
    return max;
}

// usage: find_max(5, 10, 3, 2, 3, 7, 0) will return the largest number that is bigger than 5,
//        which is 10
int find_max2(int n, ...) {
    va_list ap;
    int cur, max;
    va_start(ap, n);
    cur = va_arg(ap, int);

    while (cur != 0) {        
        if (cur >= n)
            n = cur;
        cur = va_arg(ap, int);
    }
    va_end(ap);
    return n;
}

int main(void) {
    int a = find_max(7, 1, 10, 3, 2, 3, 7, 0);
    int b = find_max2(11, 10, 3, 2, 3, 7, 0);
    int c = find_max2(0, 10, 3, 2, 3, 7, 0);
    int d = find_max2(10, 10, 3, 2, 3, 7, 0);
    int e = find_max2(7, 10, 3, 2, 3, 7, 0);
    int f = find_max2(7, 10, 3, 2, 99, 7, 0);

    printf("%d %d\n", a, b);
    return 0;
}
#endif

#if (EXERCISE == 2)
// simplified version of printf, where only %d are accepted.

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void printd(const char *s, ...) {
    va_list ap;
    int d, i;

    va_start(ap, s);
    while (*s != '\0') {
        if (*s == '%') {
            if (*(++s) == 'd') {
                d = va_arg(ap, int);
                if (d == 0) {
                    putchar('0');
                    s++;
                    continue;
                } else if (d < 0) {
                    putchar('-');
                    d = -d;
                }
                for (i = 1; d >= i; i*=10)
                    ;
                i /= 10;
                while (i >= 1) {                                        
                    putchar((d / i) + '0');
                    d = d - ((d / i) * i);
                    i /= 10;
                }
            }
        } else if (*s == '\0') {
            break;
        } else {
            putchar(*s);
        }
        s++;
    }
    va_end(ap);
}

int main(void) {

    printd("numbers %d, %d, %d, %d, %d\n", 1000, 0, 1, 99999, 7);
    printd("numbers %d, %d, %d\n", -1, -10, 1234);

    return 0;
}
#endif

#if (EXERCISE == 3)
// Extend exercise 2 to include string specifier %s

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void printf2(const char *s, ...) {
    va_list ap;
    int d, i;
    char *str;

    va_start(ap, s);
    while (*s != '\0') {
        if (*s == '%') {
            if (*(++s) == 'd') {
                d = va_arg(ap, int);
                if (d == 0) {
                    putchar('0');
                    s++;
                    continue;
                } else if (d < 0) {
                    putchar('-');
                    d = -d;
                }
                for (i = 1; d >= i; i*=10)
                    ;
                i /= 10;
                while (i >= 1) {                                        
                    putchar((d / i) + '0');
                    d = d - ((d / i) * i);
                    i /= 10;
                }
            } else if (*s == 's') {
                str = va_arg(ap, char *);
                for(; *str != '\0'; str++)
                    putchar(*str);
            }
        } else if (*s == '\0') {
            break;
        } else {
            putchar(*s);
        }
        s++;
    }
    va_end(ap);
}

int main(void) {

    printf2("numbers %d, %d, %d, %d, %d\n", 1000, 0, 1, 99999, 7);
    printf2("numbers %d, %d, %d\n", -1, -10, 1234);
    printf2("%s %s %d\n", "abc", "def", 123);

    return 0;
}
#endif

#if (EXERCISE == 4)
#include <stdio.h>
#include <stdarg.h>

void display(int n, ...) {
    va_list ap;
    char *p;
    va_start(ap, n);
    for (;n > 0; n--) {
        p = va_arg(ap, char *);
        fputs(p, stdout);
        putchar(' ');
    }

    va_end(ap);
}

int main(void) {

    display(4, "abc", "d", "efg", "hijklm nop");

    return 0;
}
#endif

#if (EXERCISE == 5)
// concante a string with dynamical memory alloation.
// the last argument must be a null pointer '\0'

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char * vstrcat(const char * first, ...) {
    va_list ap, ap2;
    char *p, *q;
    int i = 0;
    va_start(ap, first);
    va_copy(ap2, ap);
    p = (char *) first;
    while (*p != '\0') {
        i += strlen(p);
        p = va_arg(ap, char *);
    }
    va_end(ap);
    q = malloc(sizeof(char) * i + 1);
    if (q == NULL)
        exit(EXIT_FAILURE);
    *q = '\0';
    p = (char *) first;
    while (*p != '\0') {
        strcat(q, p);        
        p = va_arg(ap2, char *);
    }    
    va_end(ap2);
    return q;
}

int main(void) {
    char *str;
    str = vstrcat("abc", "defg", "hijklm", "nop", "  hahaha ", "");
    printf("%s\n", str);

    return 0;
}
#endif

#if (EXERCISE == 6)
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// given 5 pairs of int and char*
// max_pair(5, 180, "Seinfeld", 180, "I love Lucy", 
//              39, "The Honeymooners", 210, "All in the Family",
//              86, "The Sopranos")
// The function will return "All in the Family"
char *max_pair(int num_pairs, ...) {
    va_list ap;
    char *str;
    int cur, max;
    va_start(ap, num_pairs);
    max = va_arg(ap, int);
    str = va_arg(ap, char *);
    for (int i = 1; i < num_pairs; i++) {
        cur = va_arg(ap, int);
        if (cur > max) {
            max = cur;
            str = va_arg(ap, char *);
        } else {
            va_arg(ap, char*);
        }
    }
    va_end(ap);
    return str;
}

int main(void) {
    char *str;

    str = max_pair(6, 180, "Seinfeld", 180, "I love Lucy",                     \
                       39, "The Honeymooners", 179, "All in the Family",       \
                       86, "The Sopranos", 87, "abc");
    printf("%s\n", str);

    return 0;
}
#endif

#if (EXERCISE == 7)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {

    long int value;
    char *p = "123";
    int err = ERANGE;

    // convert 1st 10 characters from a string to long integer.
    // value = 123456789
    value = strtol(p, &p, 10);
    int errn1, errn2, errn3;
    errn1 = errno;


    return 0;
}
#endif

#if (EXERCISE == 8)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int a[] = {7, 11, 15, 19};

    n = a[rand() % 4];

    return 0;
}
#endif

#if (EXERCISE == 9)
#include <stdio.h>
#include <stdlib.h>

// returns a random value between 0.0 and 1.0
double random(void) {
    // return ((double) (rand() % 10)) / 10;q
    // book answer
    return (double) rand() / (RAND_MAX + 1);
}

int main(void) {

    double a;
    a = random();

    return 0;
}
#endif

#if (EXERCISE == 10)
// turns following calls to strtol, strtol, and stroll, respectively.
// atoi(str), atol(str), atoll(str)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    char *p1, *p2, *p3;
    int a = atoi("2147483647");
    int a2 = (int) strtol("2147483647", &p1, 10);

    long b = atol("2147483647L");
    long b2 = strtol("2147483647", &p2, 10);

    long long c = atoll("9223372036854775807");
    long long c2 = strtoll("9223372036854775807", &p3, 10);

    return 0;
}
#endif

#if (EXERCISE == 11)
// bsearch works with sorted array, under some condidtions
// it may work with partially sorted array.
#include <stdio.h>
#include <stdlib.h>

// for binary search, if a - b, then the array is sorted in assending order.
int comp(const void *a, const void *b) {
    return (*(int*)a - *(int *)b);
}

int main(void) {
    int *p, *q;
    int key1 = 99;
    int key2 = 2;
    int some_array[] =  { 7,  3,  2, 1, 30, 5, 6, 20, 99, 39, 0};

    // The binary search may still work when the array isn't sorted in asending order.
    p = bsearch(&key1, some_array,  sizeof(some_array)/sizeof(int),  \
               sizeof(int), comp);
    
    q = bsearch(&key2, some_array,  sizeof(some_array)/sizeof(int),  \
               sizeof(int), comp);

    return 0;
}
#endif

#if (EXERCISE == 12)
#include <stdio.h>
#include <time.h>

// returns a time_t value representing 12:00 am on the first day of a given year
time_t first_day(int year) {
    struct tm a = {.tm_year = year - 1900, \
                   .tm_mday = 1,    \
                   .tm_mon  = 0,    \
                   .tm_hour = 0,    \
                   .tm_min  = 0,    \
                   .tm_sec  = 0,    };
    return mktime(&a);    
}

int main(void) {

    time_t t = first_day(2022);
    struct tm local_time = *localtime(&t);
    printf("%s\n", ctime(&t));

    return 0;
}
#endif

#if (EXERCISE == 13)
// use strftime to create date and time formats in the following three forms:
// a) YYYY-DDD, DDD is a number between 001 and 366
// b) YYYY-Www-D, ww is a number between 01 and 53, D is a digit between 1 and 7 (beginning with Monday and ends with Sun-day)
// c) YYYY-MM-DDThh:mm:ss

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    struct tm user_time = { .tm_year = 2022 - 1900, \
                            .tm_mday = 2,    \
                            .tm_mon  = 0,    \
                            .tm_hour = 0,    \
                            .tm_min  = 0,    \
                            .tm_sec  = 0,    };
    time_t t = mktime(&user_time);
    printf("%s\n", ctime(&t));
    int a;
    char *stime;
    stime = malloc(sizeof(char) * 20);
    // YYYY-DDD, DDD is a number between 001 and 366
    a = strftime(stime, 20, "%Y-%j", &user_time);
    printf("%2d, %s\n", a, stime);

    // YYYY-Www-D, ww is a number between 01 and 53, D is a digit between 1 and 7 (beginning with Monday and ends with Sun-day)
    // note, ISO-8061 is not supported: %V and %u
    a = strftime(stime, 20, "%Y-W%W-%w", &user_time);
    printf("%2d, %s\n", a, stime);

    // YYYY-MM-DDThh:mm:ss
    a = strftime(stime, 20, "%Y-%m-%d %H:%M:%S", &user_time);
    printf("%2d, %s\n", a, stime);

    free(stime);
    return 0;
}
#endif

#if (EXERCISE == 14)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 15)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 16)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 17)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 18)
int main(void) {


    return 0;
}
#endif