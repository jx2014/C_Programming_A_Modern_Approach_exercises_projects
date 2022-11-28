#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EXERCISE (18)

int main(void) {

    #if (EXERCISE == 0)
        // pointer exercise
        #define NUM_ROWS (3)
        #define NUM_COLS (4)
        #define NUM_DIMS (5)
        int a[NUM_ROWS][NUM_COLS][NUM_DIMS];    

        void f(int m, int n) {
            int a[m][n], (*p)[m];
            p = a;
        }
        f(3,4);
        
        // using a single pointer *p to assign value to all elements within an array.
        int *p, i = 1;
        for (p = &(a[0][0][0]); p <= &(a[NUM_ROWS-1][NUM_COLS-1][NUM_DIMS-1]); p++) {
            *p = i;
            i++;
        }

        // assign values to a particular row
        int A = 0, B = 1, C = 2;
        int *pr;

        for (pr = a[A][B]; pr < a[A][B] + NUM_DIMS; pr++) {
            *pr = 999;
        }

        // assign values to a single cell with increment from top row.
        int (*prr)[NUM_COLS][NUM_DIMS];
        for (prr = &(a[0]); prr <= &(a[NUM_ROWS-1]); prr++) {
            (*prr)[B][C] = 666;
        }

        // asign values to a particular column for a 2d array.
        int b[NUM_ROWS][NUM_COLS];
        int (*q)[NUM_COLS];
        for (q = &b[0]; q < &b[NUM_ROWS]; q++) {
            (*q)[1] = 999;
        }


        printf("%d\n", *p);
    #endif

    #if (EXERCISE == 1)
        //         0   1   2   3   4  5   6   7
        int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
        int *p = &a[1], *q = &a[5];

        printf("*(p + 3) is %d\n", *(p + 3));   // 14
        printf("*(q - 3) is %d\n", *(q - 3));   // 34
        printf("(q - p) is %d\n", (q - p));    // (5 - 1) = 4
        // p < q is true
        // *p < *q is false
    #endif

    #if (EXERCISE == 2)
        //         0   1   2   3   4  5   6   7
        int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
        int *low = &a[0], *high = &a[7], *middle;

        middle = ((high - low) / 2) + low;
    #endif

    #if (EXERCISE == 3)
        // reverse an array
        #define N 10
        int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *p = &a[0], *q = &a[N-1], temp;

        while (p < q) {
            temp = *p;
            *p++ = *q;
            *q-- = temp;
        }

    #endif

    #if (EXERCISE == 4)

        #define STACK_SIZE 100

        /* external variables */
        char contents[STACK_SIZE];
        char output_stack;
        //int top = 0;
        char *top_ptr;

        void make_empty(void) {
            //top = 0;
            top_ptr = &contents[0];
        }

        bool is_empty(void) {
            //return (top == 0);
            return (top_ptr == &contents[0]);
        }

        bool is_full(void) {
            //return top == STACK_SIZE;
            return top_ptr > &contents[STACK_SIZE - 1];
        }

    #endif

    #if (EXERCISE == 5)
        int a[5] = {1, 2, 3, 4, 5};
        int *p;
        p = a;

        p == a[0]; // incorrect, comparing pointer w/ integer
        p == &a[0]; // correct, result is 1, or true, both have the same address
        *p == a[0]; // correct, result is 1, or true, both have the same value
        p[0] == a[0]; // correct, result is 1, or true, both have the same value
    #endif

    #if (EXERCISE == 6)
        // re-write func sum_array with pointer arithmetic without the use of i and []
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int sum_array(const int a[], int n){
            int i, sum = 0;            
            for (i = 0; i < n; i++) {
                sum += a[i];
            }
            return sum;
        }

        int sum_array2(const int *p, int n) {
            int sum = 0;
            for (n=n-1; n >= 0; n--) {
                sum += *p;                
                p++;
            }
            return sum;
        }

        // book answer
        int sum_array3(const int a[], int n) {
            const int *p;
            int sum = 0;
            for (p = a; p < a + n; p++) {
                sum += *p;
            }
            return sum;
        }
        int x, y, z;
        x = sum_array(a, 10);
        y = sum_array2(a, 10);
        z = sum_array3(a, 10);
        printf("x: %d, y: %d, z: %d\n", x, y, z);

    #endif

    #if (EXERCISE == 7)
        // search item from an array
        #define N 6
        int a[N] = {1,2,3,4,5,6};
        bool result;

        bool search(const int a[], int n, int key) {
            const int *p;
            for (p = a; p < a + n; p++) {
                if (*p == key) return 1;
            }
            return 0;
        }
        result = search(a, N, 3);
        printf("%d\n", result);
    #endif

    #if (EXERCISE == 8)
        // rewrite the following function to use pointer arithmetic instead of array subscripting.
        #define N 10
        int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        void store_zeros(int a[], int n) {
            int i;
            for (i = 0; i < n; i++) {
                a[i] = 0;
            }
        }
        store_zeros(a, N);

        int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        void store_zeros2(int a[], int n) {
            int *p;
            for (p = a; p < a + n; p++) {
                *p = 0;
            }
        }
        store_zeros2(a, N);
        store_zeros2(b, N);


    #endif

    #if (EXERCISE == 9)
        // return the inner product of two arrays:
        // e.g, a[0] * b[0] + a[1] * b[1] + .... a[N-1] * b[N-1]
        #define N 10
        double a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        double b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        double result;

        double inner_product(const double *a, const double *b, int n) {
            const double *p, *q;
            double result = 0;
            for (p = a, q = b; p < a + n; p++, q++) {
                result += *p * *q;
            }
            return result;
        }

        result = inner_product(a, b, N);
    #endif

    #if (EXERCISE == 10)
        // find_middle fucntion from 11.5 using pointer arithmetic
        #define N 10
        int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *p, *q;

        // original funciton from 11.5
        int *find_middle(int a[], int n) {
            return &a[n/2];
        }
        p = find_middle(a, N);


        // using pointer arithmetic
        int *find_middle2(int a[], int n) {
            return a + n/2;
        }
        q = find_middle2(a, N);
    #endif

    #if (EXERCISE == 11)
        // find_largest function with pointer arithmetic
        // original function from exercise 11.8
        #define N 10
        int A[N] = {220, 300, 2, 3, 11, 5, 6, 7, 8, 199};
        int *largest;

        int *find_largest(int a[], int n) {
            int *p;
            p = &a[n-1];

            while (n > 0) {
                n--;
                if (*p < a[n-1]) {
                    p = &a[n-1];
                }
            }
            return p;
        }

        largest = find_largest(A, N);
        printf("largest value is: %d\n", *largest);

        // same function using pointer arithmetic
        int *find_largest2(int a[], int n) {
            int *p;
            for (p = a; n > 1;) {            
                n--;
                if (*p < *(a + n)) {
                    p = a + n;
                }
            }
            return p;
        }

        largest = find_largest2(A, N);
        printf("largest value from 'find_largest2' is: %d\n", *largest);

    #endif

    #if (EXERCISE == 12)

        #define N 10
        int A[N] = {220, 300, 2, 3, 11, 5, 6, 7, 8, 199};
        int p, q;

        void find_two_largest(int *a, int n, int *largest, int*second_largest) {
            //const int *L, *l; 
            
            if (*(a) > *(a + 1)) {
                largest = a;
                second_largest = a + 1;
            } else {
                largest = a + 1;
                second_largest = a;
            }
            
            for (; n > 2;) {
                n--;                
                if (*largest == *(a + n)) {
                    continue;
                } else if (*largest > *(a + n)) {                    
                    second_largest = (*second_largest > *(a + n) ? second_largest : a + n);
                } else {
                    second_largest = largest;
                    largest = a + n;                    
                }
            }
            printf("Largest: %d, second largest: %d\n", *largest, *second_largest);

        }

        find_two_largest(A, N, &p, &q);    
        int a[5] = {1,2,3,4,5};
        find_two_largest(a, 5, &p, &q);
        int b[5] = {5,2,3,4,5};
        find_two_largest(b, 5, &p, &q);
        int c[5] = {6,2,3,4,5};
        find_two_largest(c, 5, &p, &q);
        int d[5] = {1,8,3,4,5};
        find_two_largest(d, 5, &p, &q);
        int e[5] = {5,4,3,2,1};
        find_two_largest(e, 5, &p, &q);
    #endif

    #if (EXERCISE == 13)
        // original program from section 8.2
        // create identiy matrix
        void print_n_by_n_matrix(double *a, int n) {
            double *p;
            int i = 1;
            for (p = a; p < a + n * n; p++) {
                printf(" %2.0f", *p);
                if (i % n == 0) {
                    printf("\n");
                }
                i++;
            }
        }

        #define N 10
        double ident[N][N];
        int row, col;
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (row == col) {
                    ident[row][col] = 1.0;
                } else {
                    ident[row][col] = 0.0;
                }
            }
        }

        print_n_by_n_matrix(&ident[0][0], N);
        
        // above program with pointer arithmetic
        double ident2[N][N];
        double *p;
        int i = 0;
        for (p = ident2[0]; p < &ident2[0][0] + N * N; p++) {                        
            *p = (i % (N + 1) == 0 ? 1 : 0);
            i = (i % (N + 1) == 0 ? 1 : i + 1);
        }
        printf("\n\nAgain with pointer arithmetic:\n\n");
        print_n_by_n_matrix(&ident2[0][0], N);

        // book answer
        double ident3[N][N], *q;
        int num_zeros = N;
        for (q = &ident3[0][0]; q <= &ident3[N-1][N-1]; q++) {
            if (num_zeros == N) {
                *q = 1.0;
                num_zeros = 0;
            } else {
                *q = 0.0;
                num_zeros++;
            }
        }

        printf("\n\nWith pointer arithmetic from the book:\n\n");
        print_n_by_n_matrix(&ident3[0][0], N);

    #endif

    #if (EXERCISE == 14)
        // search for temperature from a matrix of a week worth of hourly temperature 
        int temperature[7][24], *p;
        time_t t;
        int a;

        srand((unsigned) time(&t));

        for (p = &temperature[0][0]; p < &temperature[0][0] + 7 * 24; p++) {
            a = rand() % 10;            
            *p = a + 25;
        }

        // search for temperature temperature
        int temp = 34;
        bool tempExist = false;

        bool search(const int a[], int n, int key) {
            const int *p;
            for (p = a; p < a + n; p++) {
                if (*p == key) return 1;
            }
            return 0;
        }
        tempExist = search(&temperature[0][0], 7 * 24, temp);
        printf("%d\n", tempExist);
    #endif

    #if (EXERCISE == 15)
        // prints out all temperature stored in day 'i' (row i)
        int temperature[7][24], *p;
        time_t t;
        int a;
              
        // populating temperature array with randomly generated temperatures.
        srand((unsigned) time(&t));
        for (p = &temperature[0][0]; p < &temperature[0][0] + 7 * 24; p++) {
            a = rand() % 10;            
            *p = a + 25;
        }

        // print out row i of temperature array
        int i = 3;
        for (p = &temperature[i][0]; p < &temperature[i][24]; p++) {
            printf("%d ", *p);
        }
        printf("\n");
        // book answer:
        for (p = temperature[i]; p < temperature[i] + 24; p++) {
            printf("%d ", *p);
        }
    #endif

    #if (EXERCISE == 16)
        // use find_largest to print out the highest temperature of each day

        int temperature[7][24], *p;
        time_t t;
        int a;
                
        // populating temperature array with randomly generated temperatures.
        srand((unsigned) time(&t));
        for (p = &temperature[0][0]; p < &temperature[0][0] + 7 * 24; p++) {
            a = rand() % 10;            
            *p = a + 25;
        }

        int *find_largest2(int a[], int n, int *idx) {
            int *p;            
            for (p = a; n > 1;) {            
                n--;
                if (*p < *(a + n)) {
                    p = a + n;
                    *idx = n;
                }
            }
            return p;
        }

        int (*d)[24], *hTemp, day;
        for (d = &temperature[0]; d < &temperature[0] + 7; d++) {
            hTemp = find_largest2(d[0], 24, &day); 
            printf("Day: %2d, highest temperature: %dC\n", day, *hTemp);
        }
        printf("Godo bye\n");
    #endif

    #if (EXERCISE == 17)
        // sum two dimensional arrays using pointer arithmetic
        // original function using array subscripting
        #define LEN 10
        #define N 10
        int a[N][LEN], sum;

        // initialize array a
        //int *p;
        //for (p = a[0]; p < (a[0] + N * LEN); p++) {
        //    *p = 1;
        //}

        int sum_two_dimensional_array(const int a[][LEN], int n) {
            int i, j, s = 0;
            for (i = 0; i < n; i++) {
                for (j = 0; j < LEN; j++) {
                    s += a[i][j];
                }
            }
            return s;
        }

        sum = sum_two_dimensional_array(a, N);
        printf("sum:  %d\n", sum);

        // using pointer arithmetic, remove i and j        
        int sum_two_dimensional_array2(const int a[][LEN], int n) {
            int s = 0;
            const int *p;
            for (p = &a[0][0]; p < (&a[0][0] + n * LEN); p++) {
                s += *p;
            }
            return s;
        }        

        sum = sum_two_dimensional_array2(a, N);
        printf("sum2: %d\n", sum);
    #endif

    #if (EXERCISE == 18)
        // re-write function from chapter 9, exercise 13 using pointer arithmetic.
        #define N 8

        // generating a chess board:
        char chess_board[N][N] = {  {'r','n','b','q','k','b','n','r'},
                                    {'p','p','p','p','p','p','p','p'},
                                    {' ','.',' ','.',' ','.',' ','.'},
                                    {'.',' ','.',' ','.',' ','.',' '},
                                    {' ','.',' ','.',' ','.',' ','.'},
                                    {'.',' ','.',' ','.',' ','.',' '},
                                    {'P','P','P','P','P','P','P','P'},
                                    {'R','N','B','Q','K','B','N','R'}};
        char *p;
        int i = 1;
        for (p = &chess_board[0][0]; p < &chess_board[0][0] + N * N; p++, i++) {
            printf("%c ", *p);
            if (i % N == 0) {
                printf("\n");
            }
        }
        /*
        // equivalent of using array subscripting
        for (int row = 0; row < N; row++){
            for (int col = 0; col < N; col++){
                printf("%c ", chess_board[row][col]);
            }
            printf("\b\n");
        }
        */
        
        // original function using array subscripting
        int EvaluatePosition(char board[N][N]) {
            /* Q:9, R:5, B:3, N:3, P:1 */
            int board_score = 0;
            for (int row = 0; row < N; row++){
                for (int col = 0; col < N; col++){
                    switch(board[row][col]) {
                        case 'Q': board_score += 9; break;
                        case 'R': board_score += 5; break;
                        case 'B': case 'N': board_score += 3; break;
                        case 'P': board_score += 1; break;
                        case 'q': board_score -= 9; break;
                        case 'r': board_score -= 5; break;
                        case 'b': case 'n': board_score -= 3; break;
                        case 'p': board_score -= 1; break;
                    }
                }        
            }    
            return board_score;
        }

        printf("Board score is now: %d\n", EvaluatePosition(chess_board));

        int NewEvaluatePosition(char board[N][N]) {
            /* Q:9, R:5, B:3, N:3, P:1 */
            int board_score = 0;
            char *p;
            for (p = &board[0][0]; p < &board[0][0] + N * N; p++) {
                switch(*p) {
                    case 'Q': board_score += 9; break;
                    case 'R': board_score += 5; break;
                    case 'B': case 'N': board_score += 3; break;
                    case 'P': board_score += 1; break;
                    case 'q': board_score -= 9; break;
                    case 'r': board_score -= 5; break;
                    case 'b': case 'n': board_score -= 3; break;
                    case 'p': board_score -= 1; break;
                }
            }
            return board_score;
        }
        printf("Board score is now: %d\n", NewEvaluatePosition(chess_board));



    #endif

    return 0;
}