#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PROJECT (16)

int main(void){
    #if (PROJECT == 1)
        /* print repeated digits */
        bool repeat = false;
        int digit_seen[10] = {0};
        unsigned long long n;

        printf("Enter a number: ");
        scanf("%Ld", &n);

        while (n > 0) {
            digit_seen[n % 10]++;        
            if (!repeat && digit_seen[n % 10] > 1) repeat = true; 
            n /= 10;
        }

        if (repeat) {
            printf("Repeated digit(s): ");
            for (int i = 0; i < 10; i++) {
                if (digit_seen[i] > 1) printf("%d ", i);
            }
            printf("\n");
        } else
            printf("No repeated digit\n");

    #endif

    #if (PROJECT == 3)
        /* print repeated digits with a table*/
        long long n;
        while (true) {            
            int digit_seen[10] = {0};
            printf("Enter a number: ");
            scanf("%Ld", &n);

            if (n <= 0) break;

            while (n > 0) {
                digit_seen[n % 10]++;
                n /= 10;
            }

            printf("Digits:      ");
            for (int i = 0; i < 10; i++) printf("%3d ", i);
            printf("\n");
            printf("Occurrences: ");
            for (int i = 0; i < 10; i++) {
                printf("%3d ", digit_seen[i]);
            }
            printf("\n");
        }

    #endif

    #if (PROJECT == 4)
        /* reverse numbers */
        #define N (5)
        #define SIZE ((int) sizeof(a)/sizeof(a[0]))
        unsigned long long a[N];

        printf("Enter a series of numbers: ");
        for(int i = 0; i < SIZE; i++) {
            scanf(" %d", &a[i]);
        }

        printf("The reverse is: ");
        for(int i = (SIZE - 1); i >=0; i--) {
            printf("%d ", a[i]);
        }
        printf("\n");  

    #endif

    #if (PROJECT == 5)
        /* prints monthly compound interest */
    
        #define SIZE 5
        unsigned int interest, years, investment;
        float interest_array[SIZE] = {0};
        double total_investment[SIZE] = {0};
        int i;

        printf("Enter the interest rate in percentage: ");
        scanf(" %d", &interest);
        
        printf("Enter the number of years: ");
        scanf(" %d", &years);

        printf("Enter the initial investment: ");
        scanf(" %d", &investment);
        for (int d = 0; d < SIZE; d++) {
            total_investment[d] = investment;
        }

        printf("Year");
        for (i = 0; i < SIZE; i++) {
            printf("%14d%%" , interest + i);       
        }
        printf("\n");

        for (i = 0; i < years; i++) {
            printf("%4d", i + 1);
            for (int d = 0; d < SIZE; d++) {
                for (int months = 1; months <= 12; months++) {
                    total_investment[d] += total_investment[d] * ((double) (interest + d) / 12)/ 100;
                }
                printf("%15.2f", total_investment[d]);
            }
            printf("\n");
        }

    #endif

    #if (PROJECT == 6)
        /* the B1FF filter */
        #define SIZE ((int) sizeof(message) / sizeof(message[0]))
        char message[100] = {' '}, c;        
        int i = 0;
        printf("Enter a message: ");
        while ( (c = getchar()) != '\n') {
            message[i] = (( c >= 'a' && c <= 'z' ) ? toupper(c) : c);
            i++;
        }
        for (i = 0; i < SIZE; i++) {
            switch(message[i]) {
                case 'A': message[i] = '4'; break;
                case 'B': message[i] = '8'; break;
                case 'E': message[i] = '3'; break;
                case 'I': message[i] = '1'; break;
                case 'O': message[i] = '0'; break;
                case 'S': message[i] = '5'; break;
            }
        }
        printf("In B1FF-speak:   ");
        for (i = 0; i < SIZE; i++) {
            printf("%c", message[i]);
        }
        printf("!!!!!!!!!!\n");

    #endif

    #if (PROJECT == 7)
        /* prints the row and col sum for a 5x5 array */
        #define ROW_SIZE (5)
        #define COL_SIZE (5)
        long int sum_of_row[ROW_SIZE] = {0}, sum_of_col[COL_SIZE] = {0};
        long int x;
        int i;

        for (i = 0; i < ROW_SIZE; i++) {
            printf("Enter row %d: ", i + 1);
            for (int j = 0; j < COL_SIZE; j++) {
                scanf("%ld", &x);
                sum_of_row[i] += x;
                sum_of_col[j] += x;               
            }
        }
        printf("\nRow totals:    ");
        for (i = 0; i < ROW_SIZE; i++) printf("%3Ld", sum_of_row[i]);
        printf("\nColumn totals: ");
        for (i = 0; i < ROW_SIZE; i++) printf("%3Ld", sum_of_col[i]);
    #endif

    #if (PROJECT == 8)
        
        #define STUDENTS (5)
        #define QUIZS (5)
        double sum_of_row[STUDENTS] = {0}, sum_of_col[QUIZS] = {0};
        double low_score[QUIZS], high_score[QUIZS] = {0};
        double x = 0;
        int i;
        for (i = 0; i < QUIZS; i++) low_score[i] = 100;

        for (i = 0; i < STUDENTS; i++) {
            printf("Enter 5 quiz grades for student %d: ", i + 1);
            for (int j = 0; j < QUIZS; j++) {
                scanf("%lf", &x);
                sum_of_row[i] += x;
                sum_of_col[j] += x;
                low_score[j]   = (low_score[j]  > x) ? x :  low_score[j];
                high_score[j]  = (high_score[j] < x) ? x : high_score[j];
            }
        }
        printf("Student:   Average:     Total:\n");
        for (i = 0; i < STUDENTS; i++) {
            printf("%7d %10.2f %10.2f\n", i + 1, sum_of_row[i] / QUIZS, sum_of_row[i]);
        } 
        printf("\nQuiz:   Highest:   Lowest:   Average:\n");
        for (i = 0; i < QUIZS; i++) {
            printf("%5d %10.2f %9.2f %10.2f\n", i + 1, high_score[i], low_score[i], sum_of_col[i] / STUDENTS);
        }
        
        
        /* //Book answer
        #define NUM_QUIZZES  5
        #define NUM_STUDENTS 5
        int grades[NUM_STUDENTS][NUM_QUIZZES];
        int high, low, quiz, student, total;

        for (student = 0; student < NUM_STUDENTS; student++) {
            printf("Enter grades for student %d: ", student + 1);
            for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
            scanf("%d", &grades[student][quiz]);
        }

        printf("\nStudent  Total  Average\n");
        for (student = 0; student < NUM_STUDENTS; student++) {
            printf("%4d      ", student + 1);
            total = 0;
            for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
            total += grades[student][quiz];
            printf("%3d     %3d\n", total, total / NUM_QUIZZES);
        }

        printf("\nQuiz  Average  High  Low\n");
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
            printf("%3d     ", quiz + 1);
            total = 0;
            high = 0;
            low = 100;
            for (student = 0; student < NUM_STUDENTS; student++) {
                total += grades[student][quiz];
                if (grades[student][quiz] > high)
                    high = grades[student][quiz];
                if (grades[student][quiz] < low)
                    low = grades[student][quiz];
            }
            printf("%3d    %3d   %3d\n", total / NUM_STUDENTS, high, low);
        }
        */
        

    #endif
    
    #if (PROJECT == 9)
        /* Random walk over a 10x10 array */
        #define PRINT_EACH_MOVEMENT (1)
        #define ROW_SIZE 10
        #define COL_SIZE 10
        char map[ROW_SIZE][COL_SIZE];
        int available_moves = 0;
        int all_moves[4] = {-1, -1, -1, -1};
        int i = 0, x, y, xy;
        srand((unsigned) time(NULL));

        // initializing the map to '.'
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                map[row][col] = '.';
            }
        }
        
        // starting position: 
        x = rand() % 10;
        y = rand() % 10;

        while (i < 26) {
            map[x][y] = 'A' + i;
            i++;
            #if (PRINT_EACH_MOVEMENT == 1)
                // print out each movement: 
                for (int row = 0; row < ROW_SIZE; row++) {
                    for (int col = 0; col < COL_SIZE; col++) {
                        printf("%c ", map[row][col]);
                    }
                    printf("\b\n");
                }
                printf("\n");
            #endif

            // planning next move
            // test for available moves
            // 0 left, 1 right, 2 up, 3 down;
            available_moves = 0;
            if ((x - 1) >= 0 && map[x - 1][y] == '.'  ) {all_moves[available_moves]=0; available_moves++; } // can move left;
            if ((x + 1) < 10 && map[x + 1][y] == '.'  ) {all_moves[available_moves]=1; available_moves++; } // can move right;
            if ((y + 1) < 10 && map[x][y + 1] == '.'  ) {all_moves[available_moves]=2; available_moves++; } // can move up;
            if ((y - 1) >= 0 && map[x][y - 1] == '.'  ) {all_moves[available_moves]=3; available_moves++; } // can move down;
            
            // no more moves, terminate program
            if (available_moves == 0) break;

            // generating new move
            xy = rand() % available_moves; // get position from all_moves array
            switch (all_moves[xy]) {
                case 0: x--; break; // move left
                case 1: x++; break; // move right
                case 2: y++; break; // move up
                case 3: y--; break; // move down
            }

        }
        #if (PRINT_EACH_MOVEMENT == 0)
            for (int row = 0; row < ROW_SIZE; row++) {
                for (int col = 0; col < COL_SIZE; col++) {
                    printf("%c ", map[row][col]);
                }
                printf("\b\n");
            }
            printf("\n");
        #endif

    #endif

    #if (PROJECT == 10)    
        int h = 0, m = 0, user;
        int departure_hr, departure_min, arrivial_hr, arrivial_min;
        int departure[8], arrivial[8];

        departure[0] =  8 * 60 +  0;
        departure[1] =  9 * 60 + 43;
        departure[2] = 11 * 60 + 19;
        departure[3] = 12 * 60 + 47;
        departure[4] = 14 * 60 +  0;
        departure[5] = 15 * 60 + 45;
        departure[6] = 19 * 60 +  0;
        departure[7] = 21 * 60 + 45;

        arrivial[0] = 10 * 60 + 16;
        arrivial[1] = 11 * 60 + 52;
        arrivial[2] = 13 * 60 + 31;
        arrivial[3] = 15 * 60 +  0;
        arrivial[4] = 16 * 60 +  8;
        arrivial[5] = 17 * 60 + 55;
        arrivial[6] = 21 * 60 + 20;
        arrivial[7] = 11 * 60 + 58;

        printf("Enter estimated departure time: ");
        scanf(" %2d :%2d", &h, &m);

        user = h * 60 + m;
        int i = 0;
        for (; i < 7; i++) {
            if (( user - departure[i]) <= (departure[i + 1] - user)) {
               break;
            }
        }
        departure_min = departure[i] % 60;
        departure_hr = (departure[i] - departure_min) / 60;
        arrivial_min = arrivial[i] % 60;
        arrivial_hr = (arrivial[i] - arrivial_min) / 60;
        printf("Closet departure time is %02d:%02d, arriving at %02d:%02d.\n", departure_hr, departure_min,
                                                                        arrivial_hr, arrivial_min);
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

    #endif

    #if (PROJECT == 11)
        char phone_number[15], c;
        int i = 0;
        for (int i = 0; i < 15; i++) phone_number[i] = ' ';
        printf("Entere a phone number: ");
        while ((c = getchar()) != '\n') {
            
            if ((c >= 97 && c <= 122)) c = toupper(c); // convert lower case to upper case;
            
            if (c >= 65 && c <=67) { // ABC is 2
                c = '2';
            } else if ( c >= 68 && c <=70 ) { // DEF is 3
                c = '3';
            } else if ( c >= 71 && c <=73 ) { // GHI is 4
                c = '4';
            } else if ( c >= 74 && c <=76 ) { // JKL is 5
                c = '5';
            } else if ( c >= 77 && c <=79 ) { // MNO is 6
                c = '6';
            } else if ( c >= 80 && c <=83 ) { // PQRS is 7
                c = '7';
            } else if ( c >= 84 && c <=86 ) { // TUV is 8
                c = '8';
            } else if ( c >= 87 && c <=90 ) { // WXYZ is 9
                c = '9';
            }
            phone_number[i] = c;
            i++;
        }
        printf("In numeric form: ");
        for (i = 0; i < 15; i++) printf("%c", phone_number[i]);

    #endif

    #if (PROJECT == 12)
        /* Calculate the value for a word */
        char c = 0;
        int score = 0;
                             // A, B, C, D, E, F, G, H, I, J, K, L
        int score_of_letter[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1,
                            // M  N  O  P   Q  R  S  T  U  V  W  X  Y   Z 
                               3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
        
        printf("Enter a word: ");        
        while ((c = getchar()) != '\n') score += score_of_letter[toupper(c) - 'A'];
        printf("Scrabble value: %d\n", score);

    #endif

    #if (PROJECT == 13)
        // Display Last name, First initial.
        char c, firstInitial, lastname[15] = {' '};
        _Bool isFirstLetter = 0;
        int i = 0;

        printf("Enter a first name and last name: ");
        scanf(" %c", &firstInitial);
        while (getchar() != ' '); // loop through remaining of first name.
        while ((c = getchar()) != '\n') {            
            if (toupper(c) >= 'A' && toupper(c) <= 'Z') {      
                if (!isFirstLetter) {
                    c = toupper(c);       
                    isFirstLetter = 1;
                }
                lastname[i] = c;
                i++;
            }

        }
        for (int d = 0; d < i; d++) {
            printf("%c", lastname[d]);
        }
        printf(", %c.\n", toupper(firstInitial));
    #endif

    #if (PROJECT == 14)
        /* reverse words in a sentence */
        /* e.g., you can cage a swallow can't you? --> you can't swallow a cage can you?*/
        char sentence[2000] = {0}; // assuming a sentence has maximum 2000 words.
        int letter = 0, i, j;
        char c, p;
        printf("Enter a sentence: ");
        while((c = getchar()) != '\n') {
            if (c == '.' || c == '!' || c == '?') {
                p = c;
                break;
            } else {
                sentence[letter] = c;   
                letter++;
            }            
        }
        printf("Reversal of the sentence: ");
        for (letter--;letter >= 0;) {
            for (i = letter; i >= 0 && sentence[i] != ' '; i--);
            j = i - 1;
            for (i++; i <= letter; i++) {
                c = sentence[i];
                if ( c == 0 ) break;
                putchar(c);
            }
            putchar(' ');
            letter = j;
        }
        printf("\b%c", p);
    #endif

    #if (PROJECT == 15)
        /* Caesar's cipher: shifting the position of a letter by a fixed value */
        #define MESSAGE_SIZE (80)
        char c, message[MESSAGE_SIZE] = {0};
        int i = 0, shift = 0;
        bool bUpperCase = false;


        printf("Enter a message: ");
        for (i = 0; i < MESSAGE_SIZE; i++) {
            c = getchar();
            if (c == '\n') break;
            message[i] = c;
        }

        do {
            printf("Enter shift amount[1 - 25]: ");
            scanf("%d", &shift);
        } while (shift > 25 || shift < 1);

        // shift characters
        for (i = 0; i < MESSAGE_SIZE; i++) {
            c = message[i];            
            if (c >= 'a' && c <= 'z') c = (c - 'a' + shift) % 26 + 'a';
            if (c >= 'A' && c <= 'Z') c = (c - 'A' + shift) % 26 + 'A';
            message[i] = c;
        }

        printf("The encrypted message: ");
        for (i = 0; i < MESSAGE_SIZE; i++) printf("%c", message[i]);

    #endif

    #if (PROJECT == 16)
        /* anagram tester (test if two words share the exact same letters) */
        char a;
        int letter[26] = {0};
        int i = 0;
        printf("Enter first word: ");
        while ((a = getchar()) != '\n') {
            a = tolower(a);
            letter[a - 'a']++;
        }
        printf("Enter second word: ");
        while ((a = getchar()) != '\n') {
            a = tolower(a);
            letter[a - 'a']--;
        }
        for (i = 0; i < 26; i++) {
            if (letter[i] != 0) {
                printf("The words are not anagrams.\n");
                return 0;
            } 
        }
        printf("The words are anagrams.\n");
    #endif

    #if (PROJECT == 17)
        /* Magic square generator
         * The sums of all rows, columns, and diagnal are equal.
        */
        #define PRINT_EACH_MATRIX (0)
        int matrix[99][99] = {0};
        int n, x = 0, y = 0, i = 0, x0 = 0, y0 = 0;
        do {
            printf("Enter the size of a magic square[odd number from 3 to 99]: ");
            scanf(" %d", &n);
            if ( (n <= 99 && n >=3) && (((n - 1) % 2) == 0)) break;
        } while (true);        
        
        // starting position
        y = 0, x = n / 2;
        i++;
        matrix[y][x] = i; // place a 1 in the middle of row 0;
        while (i < (n * n)) {
            i++;
            x0 = x, y0 = y;
            x = ((x + 1) < n) ? (x + 1) : 0;
            y = ((y - 1) >= 0) ? (y - 1) : (n - 1);
            if (matrix[y][x] == 0) {
                ;      
            } else {
                x = x0;
                y = y0 + 1;
            }
            matrix[y][x] = i;
            #if (PRINT_EACH_MATRIX == 1)
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                        printf("%3d ", matrix[r][c]);
                    }
                    printf("\b\n");
                }
                printf("\n");
            #endif
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                x = matrix[r][c];
                printf("%3d ", x);
            }
            printf("\b\n");
        }
    #endif


    return 0;
}