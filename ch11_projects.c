#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
//#include <time.h>
//#include <ctype.h>

#define PROJECT (4)

int main(void) {
    #if (PROJECT == 1)
        /*
        *  Input dollar amount, automatically reutrn
        *  smaller bills of $20, $10, $5, $1
        */

        void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
            *twenties = dollars / 20;
            *tens = (dollars - *twenties * 20) / 10;
            *fives  = (dollars - *twenties * 20 - *tens * 10) / 5;
            *ones  = (dollars - *twenties * 20 - *tens * 10 - *fives * 5) / 1;
        }

        unsigned int t = 0;
        unsigned int bill_20, bill_10, bill_5, bill_1;

        printf("Enter total amount $ ");
        scanf("%d", &t);

        pay_amount(t, &bill_20, &bill_10, &bill_5, &bill_1);

        printf("$20 .. %d\n", bill_20);
        printf("$10 .. %d\n", bill_10);
        printf(" $5 .. %d\n", bill_5);
        printf(" $1 .. %d\n", bill_1);

    #endif

    #if (PROJECT == 2)

        int h = 0, m = 0, total_desired_mins;
        printf("Enter estimated departure time (hh:mm): ");
        scanf(" %2d :%2d", &h, &m);

        total_desired_mins = h * 60 + m;

        void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {            
            int d1, d2, d3, d4, d5, d6, d7, d8;

            d1 =  8 * 60;
            d2 =  9 * 60 + 43;
            d3 = 11 * 60 + 19;
            d4 = 12 * 60 + 47;
            d5 = 2 * 60 + 12 * 60;
            d6 = 3 * 60 + 12 * 60 + 45;
            d7 = 7 * 60 + 12 * 60;
            d8 = 9 * 60 + 12 * 60 + 45;        
        
            if ((desired_time - d1) <= (d2 - desired_time)) {
                *departure_time = d1;
                *arrival_time = 10 * 60 + 16;
            } else if ((desired_time - d2) <= (d3 - desired_time)) {
                *departure_time = 9 * 60 + 43;
                *arrival_time = 11 * 60 + 52;              
                // printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m"); 
            } else if ((desired_time - d3) <= (d4 - desired_time)) {
                *departure_time = 11 * 60 + 19;
                *arrival_time = 13 * 60 + 31;
                //printf("Closest departure time is 11:19 a.m., arriving at  1:31 p.m"); 
            } else if ((desired_time - d4) <= (d5 - desired_time)) {
                *departure_time = 12 * 60 + 47;
                *arrival_time = 15 * 60;
                //printf("Closest departure time is 12:47 p.m., arriving at  3:00 p.m"); 
            } else if ((desired_time - d5) <= (d6 - desired_time)) {
                *departure_time = 14 * 60;
                *arrival_time = 16 * 60 + 8;
                //printf("Closest departure time is  2:00 p.m., arriving at  4:08 p.m"); 
            } else if ((desired_time - d6) <= (d7 - desired_time)) { 
                *departure_time = 15 * 60 + 45;
                *arrival_time = 17 * 60 + 55;
                //printf("Closest departure time is  3:45 p.m., arriving at  5:55 p.m"); 
            } else if ((desired_time - d7) <= (d8 - desired_time)) { 
                *departure_time = 19 * 60;
                *arrival_time = 21 * 60 + 20;
                //printf("Closest departure time is  7:00 p.m., arriving at  9:20 p.m"); 
            } else {
                *departure_time = 21 * 60 + 45;
                *arrival_time = 23 * 60 + 58;
                //printf("Closest departure time is  9:45 p.m., arriving at 11:58 p.m"); 
            }
        }

        void get_time(int total_minutes, int *hr, int *min) {
            *hr = total_minutes / 60;
            *min = total_minutes - *hr * 60;
        }

        int total_depart_mins, total_arrival_mins;
        int depart_hr, depart_min, arriv_hr, arriv_min;

        find_closest_flight(total_desired_mins, &total_depart_mins, &total_arrival_mins);
        get_time(total_depart_mins, &depart_hr, &depart_min);
        get_time(total_arrival_mins, &arriv_hr, &arriv_min);

        printf("Closest departure time is  %02d:%02d, arriving at %02d:%02d", depart_hr, depart_min, arriv_hr, arriv_min);
    #endif

    #if (PROJECT == 3)
        // Using Euler's method to find GCD of a fraction number
        int n, d, x, y;

        printf("Enter a fraction: ");
        scanf("%d /%d", &n, &d);

        void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
            int r, a, b;
            a = numerator;
            b = denominator;

            while (b != 0) {
                r = a % b;
                a = b;
                b = r;
            }            
            // the GCD is a
            *reduced_numerator = numerator / a;
            *reduced_denominator = denominator / a;
        }
        reduce(n, d, &x, &y);
        printf("The reduced form is: %d/%d", x, y);

    #endif

    #if (PROJECT == 4)
    // see ch11_project4_pocker.c

    #endif



    return 0;
}