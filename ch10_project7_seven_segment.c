/**********************************************************************
 *                                                                    *
 * ch10_project7_seven_segment.c: a program to print out digits in    *
 *                                sevent segment display format.      *
 *                                                                    * 
 * ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIGITS (10)

void clears_digits_array();
void process_digits();
void print_digits_array();

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


// digit pos:  0    1    2    3    4    5    6    7    8    9  
//  row  col: 0000 0000 0011 1111 1112 2222 2222 2233 3333 3333
//            0123 4567 8901 2345 6789 0123 4567 8901 2345 6789 
//   0               _    _         _    _    _    _    _    _
//   1           |   _|   _|  |_|  |_   |_     |  |_|  |_|  | | 
//   2           |  |_    _|    |   _|  |_|    |  |_|   _|  |_|

char digits[3][MAX_DIGITS * 4] = {' '};


int main(void) {
    char d = ' ';
    int i, n;
    while (true) {
        i = 0;
        n = 0;
        printf("Enter a number: ");
        clears_digits_array();
        while (i < MAX_DIGITS) {
            d = getchar();            
            if (n == 0 && (d == 'q' || d == 'Q')) {
                exit(EXIT_SUCCESS);
            } else if (d >= '0' && d <= '9' ) {
                process_digits(d - '0', i);
                i++;
            } else if (d == '\n') {
                break;
            }
            n++;
        }
        if ( d != '\n') while (getchar() != '\n');         
        print_digits_array();
        
    }
    return 0;
}

void clears_digits_array(void) {
    int r = 0;
    int c = 0;
    for (; r < 3; r++) {
        for (c = 0; c < (MAX_DIGITS * 4); c++) {
            digits[r][c] = ' ';
        }
    }
}

void process_digits(int digit, int position) {
    //printf("digit entered is: %d, position: %d\n", digit, position);    
    char symbol = ' ';
    int offset = 0;
    int row = 0;
    for (int i = 0; i < 7; i++) {
        if (segments[digit][i]) {
            if ((i % 3) == 0) {
                symbol = '_';
            } else {
                symbol = '|';
            }            
            switch (i) {
                case 0: offset = 1; row = 0; break;
                case 1: offset = 2; row = 1; break;          
                case 2: offset = 2; row = 2; break;
                case 3: offset = 1; row = 2; break;
                case 4: offset = 0; row = 2; break;
                case 5: offset = 0; row = 1; break;
                case 6: offset = 1; row = 1; break;                      
            }
            digits[row][position * 4 + 1 + offset] = symbol;
        }
    }
}

void print_digits_array() {
    int row = 0;
    int pos = 0;
    for (; row < 3; row ++) {
        for (pos = 0; pos < (MAX_DIGITS * 4); pos++) {
            printf("%c", digits[row][pos]);
        }
        printf("\n");
    }
}

