#define PROJECT (6)

#if (PROJECT == 1)
// calls rand 1000 times, ten print the low-order bit of each value it returns (0 if return value is even, 1 if it's odd)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 1000;

    while (n-- > 0) {
        printf("%d", (rand() & 1));
        //if (n % 100 == 0)
        //    printf("\n");
    }
    printf("\n");
    n = 1000;
    while (n-- > 0) {
        printf("%d", (rand() / (RAND_MAX / 2 + 1)));
        //if (n % 100 == 0)
        //    printf("\n");
    }
    return 0;
}
#endif

#if (PROJECT == 2)
#include <stdio.h>
#include <stdlib.h>

void exit_fcn1(void) {
    printf("That's all ");
}

void exit_fcn2(void){
    printf("folks!\n");
}

int main(void) {

    atexit(exit_fcn2);
    atexit(exit_fcn1);
    
    printf("Hello world!\n\n");

    return 0;
}
#endif

#if (PROJECT == 3)
// timing qsort for an array of 1000, 10,000, and 100,000 integers.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <intrin.h> // use __rdtsc to track cpu ticks
#include <stdint.h> 

#define ARRAY_SIZE_1 (  1000)
#define ARRAY_SIZE_2 ( 10000)
#define ARRAY_SIZE_3 (100000)

static inline uint64_t readRTSC() {
    return __rdtsc();
}

int int_comp(const void *a, const void *b) {
    return (*((int *) a) - *((int *) b));
}

int main(void) {
    int array_1[ARRAY_SIZE_1];
    int array_2[ARRAY_SIZE_2];
    int array_3[ARRAY_SIZE_3];
    int n;
    
    srand((unsigned int) time(NULL));
    for (int i = 0; i < ARRAY_SIZE_3; i++) {
        n = (rand() / (RAND_MAX / ARRAY_SIZE_3 + 1));
        if (i < ARRAY_SIZE_1)
            array_1[i] = n;
        if (i < ARRAY_SIZE_2)
            array_2[i] = n;
        array_3[i] = n;
    }

    //time_t t_0 = time(NULL);
    clock_t ct0 = clock();
    uint64_t  t0 = readRTSC();
    qsort(array_1, ARRAY_SIZE_1, sizeof(int), int_comp);
    printf("Int array of %10d size takes %10e msec to sort.\n", ARRAY_SIZE_1, ((clock() - ct0) / (double) CLOCKS_PER_SEC) * 1000);
    printf("Int array of %10d size takes %10lld CPU ticks to sort.\n", ARRAY_SIZE_1, (readRTSC() - t0));
    
    ct0 = clock();
    t0 = readRTSC();
    qsort(array_2, ARRAY_SIZE_2, sizeof(int), int_comp);
    printf("Int array of %10d size takes %10e msec to sort.\n", ARRAY_SIZE_2, ((clock() - ct0) / (double) CLOCKS_PER_SEC) * 1000);
    printf("Int array of %10d size takes %10lld CPU ticks to sort.\n", ARRAY_SIZE_2, (readRTSC() - t0));
    
    ct0 = clock();
    t0 = readRTSC();
    qsort(array_3, ARRAY_SIZE_3, sizeof(int), int_comp);
    printf("Int array of %10d size takes %10e msec to sort.\n", ARRAY_SIZE_3, ((clock() - ct0) / (double) CLOCKS_PER_SEC) * 1000);
    printf("Int array of %10d size takes %10lld CPU ticks to sort.\n", ARRAY_SIZE_3, (readRTSC() - t0));
    

    return 0;
}
#endif

#if (PROJECT == 4)
// prompt the user to enter a date (Month, Day, Year)
// and an integer n, then prints out the date that's n days later.
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    struct tm date;
    printf("Enter mm-dd-yyyy: ");
    scanf(" %d-%d-%d", &date.tm_mon, &date.tm_mday, &date.tm_year);
    date.tm_hour = date.tm_min = date.tm_sec = 0;
    date.tm_isdst = 0;
    date.tm_year -= 1900;
    date.tm_mon -= 1;

    mktime(&date);
    char date_str[20];
    
    strftime(date_str, 20, "%Y-%m-%d", &date);
    if (date_str == NULL)
        printf("Incorrect datetime format.\n");
    printf("Enter the number of days after %s: ", date_str);
    scanf("%d", &n);
    
    date.tm_mday += n;
    mktime(&date);
    strftime(date_str, 20, "%Y-%m-%d", &date);
    printf("New date is %s\n", date_str);

    return 0;
}
#endif

#if (PROJECT == 5)
// prompts the user to enter two dates, print the difference between
// two dates. 

#include <stdio.h>
#include <time.h>

int main(void) {
    struct tm date1, date2;
    printf("Enter date 1 (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &date1.tm_mon, &date1.tm_mday, &date1.tm_year);
    date1.tm_hour = date1.tm_min = date1.tm_sec = 0;        
    date1.tm_isdst = 0;
    date1.tm_mon += 1;
    date1.tm_year -= 1900; 
    
    printf("Enter date 2 (mm-dd-yyyy): ");
    scanf("%d-%d-%d", &date2.tm_mon, &date2.tm_mday, &date2.tm_year);
    date2.tm_hour = date2.tm_min = date2.tm_sec = 0;
    date2.tm_isdst = 0;
    date2.tm_mon += 1;
    date2.tm_year -= 1900;

    double diff_days = difftime(mktime(&date1), mktime(&date2)) / (3600 * 24);

    printf("Difference: %.1lf days", diff_days);
    


    return 0;
}
#endif

#if (PROJECT == 6)

#include <stdio.h>
// #include <stdlib.h>
#include <time.h>

int main(void) {
    time_t ct = time(NULL);
    struct tm *st;
    st = localtime(&ct);
    char time_str[100];
    // Sunday, June 3, 2007 05:48p.
    strftime(time_str, 100, "%A, %B %d, %Y %I:%m", st);
    printf("%s", time_str);
    printf("%s\n", st->tm_hour > 12 ? "p":"");

    // Sun, 3 Jun 07 17:48
    strftime(time_str, 100, "%a, %d %b %y, %H:%m\n", st);
    printf("%s", time_str);

    // 06/03/07 5:48:34 PM
    strftime(time_str, 100, "%x", st);
    printf("%s %d:%d:%d %s\n", time_str,                                \
                    st->tm_hour > 12 ? st->tm_hour - 12 : st->tm_hour,  \
                    st->tm_min, st->tm_sec,                             \
                    st->tm_hour > 12 ? "PM" : "AM");

    return 0;
}
#endif