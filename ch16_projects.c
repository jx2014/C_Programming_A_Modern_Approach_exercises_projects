#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define PROJECT (6)

#if (PROJECT == 1)

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = {
    {"United States",   1},
    {"China",           86},
    {"Argentina",       54},
    {"Russia",          7},
    {"Pakistan",        92},
};

int main(void) {
    int c_code, i, j;
    i = sizeof(country_codes) / sizeof(country_codes[0]);
    printf("Enter a dialing code: ");
    scanf(" %d", &c_code);
    for (j = 0; j < i; j++) {
        if (c_code == country_codes[j].code) {
            printf("Country is %s\n", country_codes[j].country);
            break;
        }
    }
    if (j == i) {
        printf("Unable to find the country matching this country code.\n");
    }
    return 0;
}
#endif

#if (PROJECT == 2)
    // see inventory folder
#endif

#if (PROJECT == 3)
int main(void) {

    // see see ch16\inventory\inventory_3.c

    return 0;
}
#endif

#if (PROJECT == 4)
int main(void) {

    // see ch16\inventory\inventory_4.c

    return 0;
}
#endif

#if (PROJECT == 5)
/*******************************************************
* Modified from Chapter 5 Project 8                    *
* prompt the user to enter a departure time in HH:MM   *
* search for the closest departure time in a schedule  *
* and return the estimated arrival time.               *
*******************************************************/
struct schedule {    
    int departure; // in minutes
    int arrival;
};

struct time_period {
    char *am;
    char *pm;
} am_or_pm = {.am = "am", .pm = "pm"};

void convert_time_format(struct schedule overall_schedule, \
                        int *depart_hr, int *depart_min, \
                        char **depart_p,\
                        int *arrival_hr, int *arrival_min, \
                        char **arrival_p);

#define SCHEDULES (8)

int main(void) {

    int h = 0, m = 0, i = 0, user;
    int dh, dm, ah, am;
    char *depart_period, *arrival_period;

    struct schedule overall_schedule[SCHEDULES] = {
        { 8 * 60,       10 * 60 + 16}, 
        { 9 * 60 + 43,  11 * 60 + 52}, 
        {11 * 60 + 19,  13 * 60 + 31}, 
        {12 * 60 + 47,  15 * 60 +  0}, 
        {14 * 60 +  0,  16 * 60 +  8}, 
        {15 * 60 + 45,  17 * 60 + 55}, 
        {19 * 60 +  0,  21 * 60 + 20}, 
        {21 * 60 + 45,  23 * 60 + 58},
    };

    printf("Enter estimated departure time: ");
    scanf(" %2d :%2d", &h, &m);

    user = h * 60 + m;

    for (i = 0; i < (SCHEDULES - 1); i++) {
        if ((user - overall_schedule[i].departure) <= (overall_schedule[i+1].departure - user)) {                      
            break;
        }
    }

    convert_time_format(overall_schedule[i], &dh, &dm, &depart_period, &ah, &am, &arrival_period);

    printf("Closest departure time is %02d:%02d %s, arriving at %02d:%02d %s", \
            dh, dm, depart_period, ah, am, arrival_period);
    /*
    if ((user - d1) <= (d2 - user)) {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m");
    } else if ((user - d2) <= (d3 - user)) { 
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m"); 
    } else if ((user - d3) <= (d4 - user)) { 
        printf("Closest departure time is 11:19 a.m., arriving at  1:31 p.m"); 
    } else if ((user - d4) <= (d5 - user)) { 
        printf("Closest departure time is 12:47 p.m., arriving at  3:00 p.m"); 
    } else if ((user - d5) <= (d6 - user)) { 
        printf("Closest departure time is  2:00 p.m., arriving at  4:08 p.m"); 
    } else if ((user - d6) <= (d7 - user)) { 
        printf("Closest departure time is  3:45 p.m., arriving at  5:55 p.m"); 
    } else if ((user - d7) <= (d8 - user)) { 
        printf("Closest departure time is  7:00 p.m., arriving at  9:20 p.m"); 
    } else {
        printf("Closest departure time is  9:45 p.m., arriving at 11:58 p.m"); 
    }
    */
    return 0;
}

void convert_time_format(struct schedule overall_schedule, \
                        int *depart_hr, int *depart_min, char **depart_p, \
                        int *arrival_hr, int *arrival_min, char **arrival_p) {

    *depart_p = am_or_pm.am;
    *arrival_p = am_or_pm.am;

    *depart_hr = overall_schedule.departure / 60;
    if (*depart_hr > 12) {
        *depart_hr = *depart_hr - 12;
        *depart_p = am_or_pm.pm;
    }
    *depart_min = overall_schedule.departure % 60;

    *arrival_hr = overall_schedule.arrival / 60;
    if (*arrival_hr > 12) {
        *arrival_hr = *arrival_hr - 12;
        *arrival_p = am_or_pm.pm;
    }
    *arrival_min = overall_schedule.arrival % 60;
}

#endif

#if (PROJECT == 6)

struct date { int month, day, year;} d1, d2;

// -1 if d1 is eariler than d2, +1 if later, 0 if the same
int compare_dates(struct date d1, struct date d2);

int main(void) {
/*******************************************************
* Modified from Chapter 5 Project 9                    *
* Prompt the user to enter two dates in mm/dd/yy       *
* format. Then compare the two dates and print out     *
* one date is eariler than the second date.            *
*******************************************************/

    //int d1, m1, y1, d2, m2, y2;
    struct date d1;
    struct date d2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d /%2d /%2d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d /%2d /%2d", &d2.month, &d2.day, &d2.year);

    if ( compare_dates(d1, d2) < 0) {
        printf("%02d/%02d/%02d is eariler than %02d/%02d/%02d\n", d1.month, d1.day, d1.year,\
                                                                  d2.month, d2.day, d2.year);
    } else {
        printf("%02d/%02d/%02d is eariler than %02d/%02d/%02d\n", d2.month, d2.day, d2.year, \
                                                                  d1.month, d1.day, d1.year);
    }

    return 0;
}

// compare_dates return -1 if d1 is eariler than d2, +1 if later, 0 if the same
int compare_dates(struct date d1, struct date d2) {
    int r = d1.year * 10000 + d1.month * 12 + d1.day - ( d2.year * 10000 + d2.month * 12 + d2.day );
    return r == 0 ? 0 : r / abs(r);
}

#endif

#if (PROJECT == 7)
/************************************
 *  This is a self created project  *
 *  for the purpose of exercising   *
 *  changing string pointers in     *
 *  function                        *
 * *********************************/
struct t {
    char string1[100];
    char string2[100];
} text = {.string1 = "this is string 1", .string2 = "this is string 2"};

void change_text(int i, char **p) {
    if (i == 0)
        *p = text.string1;
    else
        *p = text.string2;
}

int main(void) {
    // I want p to point to either &(text.string1), or &(text.string2)
    char *p; 
    int i = 0;

    change_text(i, &p);
    printf("i: %d, p: %s\n", i, p);

    i = 1;
    change_text(i, &p);
    printf("i: %d, p: %s\n", i, p);

    return 0;
}
#endif