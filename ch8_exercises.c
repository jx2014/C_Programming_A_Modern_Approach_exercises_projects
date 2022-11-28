#include <stdio.h>
#include <stdbool.h>

#define EXERCISE (11)

int main(void){
    #if (EXERCISE == -2)
        int a[5] = {0, 1, 2, [0] = 99, 4, 5, 6, 7};
        for (int i = 0; i < 5; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

    #endif

    #if (EXERCISE == -1)
        int c[10] = {1, 2, 3, [8] = 8};
        for(int i = 0; i <= 10000000000; i++) {
            printf("c[%d]: %d\n", i, c[i]);
        }
    #endif

    #if (EXERCISE == 0)
        int a[100] = {99};
        printf("%d\n", a[99]);
    #endif

    #if (EXERCISE == 3)
        int weekend[7] = {true, [6] = true};
        for (int i = 0; i < 7; i++) {
            printf("%d - %d\n", i, weekend[i]);
        }
    #endif

    #if (EXERCISE == 5)
        /* Fibonacci number 0 1 1 2 3 5 8 13 ... */
        #define LENGTH (41)
        #define SIZE ((int) sizeof(fib_numbers) / sizeof(fib_numbers[0]))
        int fib_numbers[LENGTH] = {0, 1};

        for (int i = 2; i < LENGTH; i++) {
            fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];            
        }

        for (int i = 0; i < SIZE; i++) {
            printf("Series %2d: %-10d\n", i, fib_numbers[i]);
        }
    #endif

    #if (EXERCISE == 6)
    /* calculate 7 segment display
       _     0
      |_|  5 6 1
      |_|  4 3 2

    */
                                    //0 1 2 3 4 5 6
        const int segments[10][7] = {{1,1,1,1,1,1,0}, // 0
                                     {0,1,1,0,0,0,0}, // 1
                                     {1,1,0,1,1,0,1}, // 2
                                     {1,1,1,1,0,0,1}, // 3
                                     {0,1,1,0,0,1,1}, // 4
                                     {1,0,1,1,0,1,1}, // 5
                                     {1,0,1,1,1,1,1}, // 6
                                     {1,1,1,0,0,0,0}, // 7
                                     {1,1,1,1,1,1,1}, // 8
                                     {1,1,1,1,0,1,1}  // 9
                                    };
    #endif

    #if (EXERCISE == 9)
        /*  Two-dimenstional arrays of a one month hourly reading for temperature 
            Rows: days of the month, columns: hours of the day
            Calculate the average of all temperature for a month
        */
        #define DAYS (30)
        #define HOURS (24)
        int day, hr;

        float temperature_readings[DAYS][HOURS] = {0};
        float daily_average = 0, monthly_average = 0, sum_of_day = 0;

        for (day = 0; day < DAYS; day++) {
            for (hr = 0; hr < HOURS; hr++) {
                sum_of_day += temperature_readings[day][hr];
            }
            daily_average += sum_of_day / HOURS;
            sum_of_day = 0;
        }
        monthly_average = daily_average / DAYS;
    #endif

    #if (EXERCISE == 10)
        /* Chess Board Initialization
            rnbqkbnr
            pppppppp 
             . . . .
            . . . . 
             . . . .
            . . . .
            PPPPPPPP
            RNBQKBNR
        */
        char chess_board[8][8] = {{'r','n','b','q','k','b','n','r'},
                                  {'p','p','p','p','p','p','p','p'},
                                  {' ','.',' ','.',' ','.',' ','.'},
                                  {'.',' ','.',' ','.',' ','.',' '},
                                  {' ','.',' ','.',' ','.',' ','.'},
                                  {'.',' ','.',' ','.',' ','.',' '},
                                  {'P','P','P','P','P','P','P','P'},
                                  {'R','N','B','Q','K','B','N','R'}};
        for (int row = 0; row < 8; row++){
            for (int col = 0; col < 8; col++){
                printf("%c ", chess_board[row][col]);
            }
            printf("\b\n");
        }
    #endif

    #if (EXERCISE == 11)
        char checker_board[8][8] = {'0'};

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                checker_board[i][j] = (( i + j ) % 2 == 0) ? 'B' : 'R';
                printf("%c ", checker_board[i][j]);
            }
            printf("\b\n");
        }



    #endif

    return 0;
}