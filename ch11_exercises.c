#include <stdio.h>
#include <stdbool.h>

#define EXERCISE (0)

void set_new_value(int *value);
void *f(void);
void *pf(void);
int g_i;
int *gp_i;

int main(void) {

    #if (EXERCISE == 0)
    // pointer exercise
        int i = 0;
        int *v = &i;
        int *vv;
        int a = 0;

        printf("a: %d\n", a);

        void increase_by_one(int* num) {
            *num++;
            (*num)++;
        }
        increase_by_one(&a);
        printf("a: %d\n", a);

        void set_new_value(int *value) {
            int new_value = 333;
            *value = new_value;
        }

        void *f(void) {
            g_i = 123;
            return &g_i;
        }

        void *pf(void) {
            int i = 131;
            gp_i = &i;
            return gp_i;
        }


        printf("old i: %d\n", i);
        set_new_value(&i);
        printf("new i: %d\n", i);

        printf("old *v: %d\n", *v);
        v = f();
        printf("new *v: %d\n", *v);

        vv = pf();
        printf("new *vv: %d\n", *vv);

        printf("Address of g_i in content of v: %p\n", v);
        printf("Address of &g_i: %p\n", &g_i);


    #endif

    #if (EXERCISE == 3)
        void avg_sum(double a[], int n, double *avg, double *sum) {
            int i;
            *sum = 0.0;
            for (i = 0; i < n; i++) {
                *sum += a[i];                
            }
            *avg = *sum / n;
        }

        double num_array[] = {1, 2, 3, 4, 5};
        int n = sizeof(num_array)/sizeof(double);
        double average_value, total;
        avg_sum(num_array, n, &average_value, &total);
        printf("average is: %f total is: %f n is: %d\n", average_value, total, n);

    #endif

    #if (EXERCISE == 4)
        int a = 1, b = 2;
        void swap(int *p, int *q) {
            int temp;
            temp = *p;
            *p = *q;
            *q = temp;            
        }

        printf("Before swap.\na: %d, b: %d\n", a, b);
        swap(&a, &b);
        printf("After swap.\na: %d, b: %d\n", a, b);

    #endif

    #if (EXERCISE == 5)
        /* split total seconds into hours, minutes, and seconds*/
        void split_time(long total_sec, int *hr, int *min, int *sec) {            
            *hr = total_sec / 3600;
            *min = (total_sec - *hr * 3600) / 60;
            *sec = total_sec - *hr * 3600 - *min * 60;

            printf("Total seconds: %d, %d:%d:%d\n", total_sec, *hr, *min, *sec);
        }

        int h=0, m=0, s=0;

        split_time(3601, &h, &m, &s);
        split_time(3600, &h, &m, &s);
        split_time(3599, &h, &m, &s);
        split_time(61, &h, &m, &s);
        split_time(60, &h, &m, &s);
        split_time(59, &h, &m, &s);
        split_time(1, &h, &m, &s);
        split_time(0, &h, &m, &s);
        split_time(-1, &h, &m, &s);      

    #endif

    #if (EXERCISE == 6)
        /* Find the two largest numbers from an array of size n*/

        void find_two_largest(int a[], int n, int *largest, int *second_largest) {
            
            if (a[1] > a[0]) {
                *largest = a[1];
                *second_largest = a[0];
            } else {
                *largest = a[0];
                *second_largest = a[1];
            }

            for (int i=2; i<n; i++) {
                if (*largest == a[i]) {
                    continue;
                } else if (*largest > a[i]) {                    
                    *second_largest = (*second_largest > a[i] ? *second_largest : a[i]);
                } else {
                    *second_largest = *largest;
                    *largest = a[i];                    
                }
            }

            printf("Largest: %d, second largest: %d\n", *largest, *second_largest);
        }

        int largest = 0, second_largest = 0;

        int a[5] = {1,2,3,4,5};
        find_two_largest(a, 5, &largest, &second_largest);
        int b[5] = {5,2,3,4,5};
        find_two_largest(b, 5, &largest, &second_largest);
        int c[5] = {6,2,3,4,5};
        find_two_largest(c, 5, &largest, &second_largest);
        int d[5] = {1,8,3,4,5};
        find_two_largest(d, 5, &largest, &second_largest);
        int e[5] = {5,4,3,2,1};
        find_two_largest(e, 5, &largest, &second_largest);

    #endif

    #if (EXERCISE == 7)

        int month, day;

        void split_date(int day_of_years, int year, int *month, int *day) {
            bool isLeap = false;
            int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            *month = 0;
            *day = 0;
            int total_days = 0;
            // determine leap year
            if ((year % 4 == 0) && (year % 100 != 0)) {
                isLeap = true;
            } else if ((year % 100 == 0) && (year % 400 == 0)) {
                isLeap = true;
            }
            
            if (isLeap) {
                days[2] = 29;
            }

            while (total_days < day_of_years) {
                *month = *month + 1;
                total_days = total_days + days[*month];                
            }

            *day = day_of_years - (total_days - days[*month]);
        }

        int year = 2020;
        split_date(31, year, &month, &day);
        printf("day_of_years %d, year %d: month: %d, day: %d\n", 31, year, month, day);
        split_date(1, year, &month, &day);
        printf("day_of_years %d, year %d: month: %d, day: %d\n", 1, year, month, day);
        split_date(58, year, &month, &day);
        printf("day_of_years %d, year %d: month: %d, day: %d\n", 58, year, month, day);
        split_date(59, year, &month, &day);
        printf("day_of_years %d, year %d: month: %d, day: %d\n", 59, year, month, day);
        split_date(366, year, &month, &day);
        printf("day_of_years %d, year %d: month: %d, day: %d\n", 366, year, month, day);
    #endif

    #if (EXERCISE == 8)
    // return a pointer to the largest element of array a[n]
    int *find_largest(int a[], int n) {
        int *largest;
        largest = &a[n-1];

        while (n > 0) {
            n--;
            if (*largest < a[n-1]) {
                largest = &a[n-1];
            }
        }
        return largest;
    }
    int n = 10;
    int a[10] = {0, 1, 2, 3, 11, 5, 6, 7, 8, 9};
    int *largest;

    largest = find_largest(a, n);
    printf("largest value is: %d\n", *largest);


    #endif

return 0;
}



