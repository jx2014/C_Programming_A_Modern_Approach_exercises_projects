#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PROJECT (8)

void SelectionSort();
double IncomeTax();
void GenerateRandomWalk();
void PrintArray();
void ReadWords();
bool IsEqualArray();
void CreateMagicSquare();
void PrintMagicSquare();
long int CalPolynomial();
long long int CalPower();
int RollDice();
bool PlayGame();


int main(void) {

    #if (PROJECT == 1)
        #define SIZE (10)
        int a[SIZE] = {0};
        printf("Enter 10 numbers for selection sort: ");
        for (int i = 0; i < SIZE; i++) {
            scanf(" %d", &a[i]);
        }
        SelectionSort(a, SIZE);
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    #endif

    #if (PROJECT == 2)
        /* income tax calculator from project 5 of chapter 5 */
        int income = 0;
        double tax = 0;
        printf("Please enter your income: ");
        scanf(" %d", &income);
        tax = IncomeTax(income);
        printf("You owe %.2f\n", tax);

    #endif

    #if (PROJECT == 3)
        char map[10][10] = {' '};
        GenerateRandomWalk(map);
        PrintArray(map);
    #endif

    #if (PROJECT == 4)
        /* anagram tester (test if two words share the exact same letters) */
        int word1[26] = {0};
        int word2[26] = {0};
        printf("Please enter a word: ");
        ReadWords(word1);
        printf("Please enter a word: ");
        ReadWords(word2);
        if (IsEqualArray(word1, word2)) printf("Two words are anagram.\n");
        else printf("The two words are not anagram.\n");

    #endif

    #if (PROJECT == 5)
        /* create a magic square where sum of all rows, columns, and diagnals are equal */
        int n;
        int matrix[99][99] = {0};
        do {
            printf("Enter the size of a magic square[odd number from 3 to 99 only]: ");
            scanf(" %d", &n);
            if ( (n <= 99 && n >=3) && (((n - 1) % 2) == 0)) break;
        } while (true);
        CreateMagicSquare(n, matrix);
        PrintMagicSquare(n, matrix);
    #endif

    #if (PROJECT == 6)
        /* compute polynomial */
        int x;
        long int y;
        printf("Enter a number for x: ");
        scanf(" %d", &x);
        y = CalPolynomial(x);
        printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %ld\n", y);

    #endif

    #if (PROJECT == 7)
        /* compute power */
        int x, n;
        while (true) {
            printf("Enter x^n: ");
            scanf(" %d ^ %d", &x, &n);
            while (getchar() != '\n');
            printf("%d^%d = %ld\n", x, n, CalPower(x, n));
        }

    #endif

    #if (PROJECT == 8)
        /* Game of craps! */
        char c;
        bool Win = false;
        srand((unsigned) time(NULL));
        while (true) { 
            if (PlayGame()) printf("You win\n");
            else printf("You lose!\n");
            printf("\nPlay again? ");
            scanf(" %c", &c);
            if (toupper(c) != 'Y') return 0;            
        }
    #endif

    return 0;
}

void SelectionSort(int a[], int size){
    if (size > 1) {
        int small;
        for (int i = 0; i < (size - 1); i++) {
            small = (a[i] > a[i + 1]) ? a[i + 1] : a[i];
            a[i + 1] = a[i] + a[i + 1] - small;
            a[i] = small;
        }
        SelectionSort(a, size - 1);
    }
};

double IncomeTax(int income) {
    double tax;
    if (income > 7000) {         
        tax = tax + 230.00f + 0.06 * (income - 7000);
        income = 7000;
    }

    if (income > 5250 && income <= 7000) {
        tax = tax + 152.50f + 0.05 * (income - 5250);
        income = 5250;
    }

    if (income > 3750 && income <= 5250) {
        tax = tax + 82.50f + 0.04 * (income - 3750);
        income = 3750;
    }

    if (income > 2250 && income <= 3750) {
        tax = tax + 37.50f + 0.03 * (income - 2250);
        income = 2250;
    }

    if (income > 750 && income <= 2250) {
        tax = tax + 7.50f + 0.02 * (income - 750);
        income = 750;
    }        

    if (income <= 750) {
        tax = tax + 0.01f * income;
    }
    return tax;
}

void GenerateRandomWalk(char walk[10][10]) {
    #define ROW_SIZE 10
    #define COL_SIZE 10
    int available_moves = 0;
    int all_moves[4] = {-1, -1, -1, -1};
    int i = 0, x, y, xy;
    srand((unsigned) time(NULL));

    // initializing the map to '.'
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            walk[row][col] = '.';
        }
    }
    
    // starting position: 
    x = rand() % 10;
    y = rand() % 10;

    while (i < 26) {
        walk[x][y] = 'A' + i;
        i++;

        // planning next move
        // test for available moves
        // 0 left, 1 right, 2 up, 3 down;
        available_moves = 0;
        if ((x - 1) >= 0 && walk[x - 1][y] == '.'  ) {all_moves[available_moves]=0; available_moves++; } // can move left;
        if ((x + 1) < 10 && walk[x + 1][y] == '.'  ) {all_moves[available_moves]=1; available_moves++; } // can move right;
        if ((y + 1) < 10 && walk[x][y + 1] == '.'  ) {all_moves[available_moves]=2; available_moves++; } // can move up;
        if ((y - 1) >= 0 && walk[x][y - 1] == '.'  ) {all_moves[available_moves]=3; available_moves++; } // can move down;
        
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

}

void PrintArray(char walk[10][10]) {
    int size = 10;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%c ", walk[row][col]);
        }
        printf("\b\n");
    }
    printf("\n");
}

void ReadWords(int word_count[26]) {
    char c;   
    for (int i = 0; i < 26; i++) word_count[i] = 0;// initialize 
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        word_count[c - 'A']++;
    }
}

bool IsEqualArray(int word_count1[26], int word_count2[26]) {
    for (int i = 0; i < 26; i++) {
        if (word_count1[i] != word_count2[i]) return 0;    
    }
    return 1;
}

void CreateMagicSquare(int n, int magic_square[99][99]) {
    int x = n / 2, y = 0, i = 1, x0 = 0, y0 = 0;        
    magic_square[y][x] = i; // place a 1 in the middle of row 0;
    while (i < (n * n)) {
        i++;
        x0 = x, y0 = y;
        x = ((x + 1) < n) ? (x + 1) : 0;
        y = ((y - 1) >= 0) ? (y - 1) : (n - 1);
        if (magic_square[y][x] == 0) {
            ;      
        } else {
            x = x0;
            y = y0 + 1;
        }
        magic_square[y][x] = i;
    }

}

void PrintMagicSquare(int n, int magic_square[99][99]) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%3d ", magic_square[r][c]);
        }
        printf("\b\n");
    }
}

long int CalPolynomial(int x) {
    /* 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 */
    return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

long long int CalPower(int x, int n) {    
    if (n == 1) return x;
    if (n == 0) return 1;
    if ((n % 2) == 0) {
        return CalPower(x * x, n / 2);
        /* CalPower(2, 4)
            CalPower(4, 2) 
                CalPower(16, 1)
                    16
        */
    } else {
        return x * CalPower(x, (n - 1));
        /* CalPower(2, 5)
            2 * CalPower(2, 4)
                    CalPower(4, 2)
                        CalPower(16, 1)
                        16
        
        */
    }
   
}

int RollDice(void) {
    int d1, d2;
    d1 = (rand() % 6) + 1;
    d2 = (rand() % 6) + 1;
    printf("You rolled %d + %d = %2d.\n", d1, d2, d1 + d2);
    return d1 + d2;
}

bool PlayGame(void) {
    int sum, point;
    bool isFirstRoll = true;
    while (true) {
        if (isFirstRoll) {
            sum = RollDice();
            isFirstRoll = false;
            if (sum == 7 || sum == 11) return true; // win
            else if (sum == 2 || sum == 3 || sum == 12) return false; // lose
            else {point = sum; printf("Your point is %d\n", point);}
        } else {
            sum = RollDice();
            if (sum == 7 ) return false; // lose
            else if (sum == point) return true; // win
        }

    }

}