#include <stdio.h>
#include <stdbool.h>
#include <time.h>


clock_t start, end;
double cpu_time_used;

#define EXERCISE (19)

bool Check();
int Gcd();
int DayOfYear();
int NumOfDigits();
int Digits();
int F();
void Swap();
int Maximum();
double Average();
int NumOfPositiveDigits();
float ComputeGPA();
double InnerProduct();
int EvaluatePosition();
double Median();
unsigned long long int Fact();
unsigned long long int Fact1();
int GcdR();
void Pb();


int main(void){
    #if (EXERCISE == 2)
        int x = 1, y = 1, n = 2;
        printf("x: %d, y: %d, n: %d, result: %d\n", x, y, n, Check(x, y, n));
        x = 2, y = 2, n = 2;
        printf("x: %d, y: %d, n: %d, result: %d\n", x, y, n, Check(x, y, n));
        x = 3, y = 1, n = 2;
        printf("x: %d, y: %d, n: %d, result: %d\n", x, y, n, Check(x, y, n));
        x = 1, y = 3, n = 2;
        printf("x: %d, y: %d, n: %d, result: %d\n", x, y, n, Check(x, y, n));
        x = 3, y = -1, n = 5;
        printf("x: %d, y: %d, n: %d, result: %d\n", x, y, n, Check(x, y, n));
    #endif

    #if (EXERCISE == 3)
        printf("x: %3d, y: %3d, Gcd: %3d\n", 2,  4, Gcd(2, 4));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 4,  2, Gcd(4, 2));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 11, 3, Gcd(11, 3));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 3, 11, Gcd(3, 11));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 11, 0, Gcd(11, 0));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 0, 11, Gcd(0, 11));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 270, 192, Gcd(270, 192));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 192, 270, Gcd(192, 270));
        printf("x: %3d, y: %3d, Gcd: %3d\n", -11, 22, Gcd(-11, 22));
        printf("x: %3d, y: %3d, Gcd: %3d\n", -3, -4, Gcd(-3, -4));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 11, 22, Gcd(11, 22));
        printf("x: %3d, y: %3d, Gcd: %3d\n", -3, -4, Gcd(-3, -4));
    #endif

    #if (EXERCISE == 4)
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1970, 12, 31, DayOfYear(12, 31, 1970));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1971, 12, 31, DayOfYear(12, 31, 1971));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1972, 12, 31, DayOfYear(12, 31, 1972));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1973, 12, 31, DayOfYear(12, 31, 1973));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1974, 12, 31, DayOfYear(12, 31, 1974));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1975, 12, 31, DayOfYear(12, 31, 1975));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1976, 12, 31, DayOfYear(12, 31, 1976));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1977, 12, 31, DayOfYear(12, 31, 1977));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1978, 12, 31, DayOfYear(12, 31, 1978));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1979, 12, 31, DayOfYear(12, 31, 1979));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1980, 12, 31, DayOfYear(12, 31, 1980));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 2020, 12, 31, DayOfYear(12, 31, 2020));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1970, 2, 28, DayOfYear(2, 28, 1970));
        printf("Year: %4d, Month: %2d, Day: %2d. Day of year: %3d\n", 1970, 1, 2, DayOfYear(1, 2, 1970));

    #endif

    #if (EXERCISE == 5)
        printf("Digits: %10d, Number of digits: %2d\n", 1234567890, NumOfDigits(0));
        printf("Digits: %10d, Number of digits: %2d\n", 1234567890, NumOfDigits(1));
        printf("Digits: %10d, Number of digits: %2d\n", 1234567890, NumOfDigits(11));
        printf("Digits: %10d, Number of digits: %2d\n", 1234567890, NumOfDigits(1234567890));

    #endif

    #if (EXERCISE == 6)
        printf("%2dth digit of %10d is %d\n", 0, 1234567890, Digits(1234567890, 0));
        printf("%2dth digit of %10d is %d\n", 1, 0, Digits(0, 1));
        printf("%2dth digit of %10d is %d\n", 2, 1, Digits(1, 2));
        printf("%2dth digit of %10d is %d\n", 2, 2, Digits(2, 2));
        printf("%2dth digit of %10d is %d\n", 2, 23, Digits(23, 2));
        printf("%2dth digit of %10d is %d\n", 1, 1234567890, Digits(1234567890, 1));
        printf("%2dth digit of %10d is %d\n", 2, 1234567890, Digits(1234567890, 2));
        printf("%2dth digit of %10d is %d\n", 3, 1234567890, Digits(1234567890, 3));
        printf("%2dth digit of %10d is %d\n", 4, 1234567890, Digits(1234567890, 4));
        printf("%2dth digit of %10d is %d\n", 5, 1234567890, Digits(1234567890, 5));
        printf("%2dth digit of %10d is %d\n", 6, 1234567890, Digits(1234567890, 6));
        printf("%2dth digit of %10d is %d\n", 7, 1234567890, Digits(1234567890, 7));
        printf("%2dth digit of %10d is %d\n", 8, 1234567890, Digits(1234567890, 8));
        printf("%2dth digit of %10d is %d\n", 9, 1234567890, Digits(1234567890, 9));
        printf("%2dth digit of %10d is %d\n", 10, 1234567890, Digits(1234567890, 10));
        printf("%2dth digit of %10d is %d\n", 11, 1234567890, Digits(1234567890, 11));
        printf("%2dth digit of %10d is %d\n", 12, 1234567890, Digits(1234567890, 12));


    #endif

    #if (EXERCISE == 7)
        int i;
        double x;
        i = F(83, 12);
        x = F(83, 12);
        i = F(1.2, 9.8);
        x = F(1.2, 9.8);
        F(1.2, 9.8);

    #endif

    #if (EXERCISE == 9)
        int i = 1, j = 2;
        Swap(i, j);
        printf("i = %d, j = %d\n", i, j); // i = 1, j = 2, swap unsuccessful.
        
    #endif

    #if (EXERCISE == 10)
        #define SIZE (10)
        int k = SIZE;
        int a[SIZE] = {1, -2, 3, 4, 5, 6, 7, 8, 9, -10};
        printf("Maximum: %d\n", Maximum(a, k));
        printf("Average: %.2lf\n", Average(a, k));
        printf("Number of positive digits: %d\n", NumOfPositiveDigits(a, k));
    #endif

    #if (EXERCISE == 11)
        #define SIZE (10)
        int number_of_grades = SIZE;
        char grades[SIZE] = {'A', 'B', 'C', 'D', 'F', 'F', 'F', 'F', 'D', 'A'};
        printf("Average grades is %f\n", ComputeGPA(grades, number_of_grades));

    #endif

    #if (EXERCISE == 12)
        int n = 10;
        int array_a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int array_b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        printf("%g\n", InnerProduct(array_a, array_b, n));

    #endif

    #if (EXERCISE == 13)
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
        printf("Board score is now: %d", EvaluatePosition(chess_board));
    #endif

    #if (EXERCISE == 15)
        /* Find the median of thee numbers */
        double x = 1, y = 2, z = 3;
        printf("median of %2g, %2g, %2g is: %g\n", x, y, z, Median(x, y, z));
        x = 3, y = 2, z = 1;
        printf("median of %2g, %2g, %2g is: %g\n", x, y, z, Median(x, y, z));
        x = 2, y = 3, z = 1;
        printf("median of %2g, %2g, %2g is: %g\n", x, y, z, Median(x, y, z));
        x = 2, y = 3, z = 3;        
        printf("median of %2g, %2g, %2g is: %g\n", x, y, z, Median(x, y, z));
        x = 1, y = 3, z = 2;        
        printf("median of %2g, %2g, %2g is: %g\n", x, y, z, Median(x, y, z));
    #endif

    #if (EXERCISE == 16)

        start = clock();
        int x = 2;
        printf("Factorial of %d is %Ld\n", x, Fact(x));
        x = 5;
        printf("Factorial of %d is %Ld\n", x, Fact(x));
        x = 20;
        printf("Factorial of %d is %Ld\n", x, Fact(x));
        x = 20;
        printf("Factorial of %d is %Ld\n", x, Fact(x));
        x = 100;
        printf("Factorial of %d is %llu\n", x, Fact(x));
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

        printf("Using non-recurrsive function.\n");
        start = clock();
        x = 2;
        printf("Factorial of %d is %Ld\n", x, Fact1(x));
        x = 5;
        printf("Factorial of %d is %Ld\n", x, Fact1(x));
        x = 20;
        printf("Factorial of %d is %Ld\n", x, Fact1(x));
        x = 20;
        printf("Factorial of %d is %Ld\n", x, Fact1(x));
        x = 100;
        printf("Factorial of %d is %llu\n", x, Fact1(x));
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

    #endif

    #if (EXERCISE == 18)
        start = clock();
        printf("x: %3d, y: %3d, GcdR: %3d\n", 2,  4, GcdR(2, 4));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 4,  2, GcdR(4, 2));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 11, 3, GcdR(11, 3));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 3, 11, GcdR(3, 11));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 11, 0, GcdR(11, 0));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 0, 11, GcdR(0, 11));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 270, 192, GcdR(270, 192));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 192, 270, GcdR(192, 270));
        printf("x: %3d, y: %3d, GcdR: %3d\n", -11, 22, GcdR(-11, 22));
        printf("x: %3d, y: %3d, GcdR: %3d\n", -3, -4, GcdR(-3, -4));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 11, 22, GcdR(11, 22));
        printf("x: %3d, y: %3d, GcdR: %3d\n", 1234567, 7654321, GcdR(-3, -4));
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

        start = clock();
        printf("x: %3d, y: %3d, Gcd: %3d\n", 2,  4, Gcd(2, 4));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 4,  2, Gcd(4, 2));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 11, 3, Gcd(11, 3));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 3, 11, Gcd(3, 11));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 11, 0, Gcd(11, 0));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 0, 11, Gcd(0, 11));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 270, 192, Gcd(270, 192));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 192, 270, Gcd(192, 270));
        printf("x: %3d, y: %3d, Gcd: %3d\n", -11, 22, Gcd(-11, 22));
        printf("x: %3d, y: %3d, Gcd: %3d\n", -3, -4, Gcd(-3, -4));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 11, 22, Gcd(11, 22));
        printf("x: %3d, y: %3d, Gcd: %3d\n", 1234567, 7654321, Gcd(-3, -4));
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

    #endif

    #if (EXERCISE == 19)
        long int n;
        printf("Enter an integer: ");
        scanf(" %Ld", &n);
        Pb(n);        

    #endif

    return 0;
}

bool check(int x, int y, int n) {    
    if ((0 <= x && x <= (n - 1)) && (0 <= y && y <= (n - 1)))
        return 1;
    else
        return 0;
}

int Gcd(int m, int n) {
    int gcd = 0;
    int s, l;
    s = ( n < m )? n : m; // r is the smaller of the two numbers.
    l = m + n - s; // l is the larger of the two numbers.

    while (s >= 0) {
        if (s == 0) {
            gcd = l;
            break;
        }
        gcd = s;
        s = l % s;
        l = gcd;            
        }

    return gcd;
}

int DayOfYear(int month, int day, int year) {
    bool isLeapYear = 0;
    int day_of_year = day;
    if (year < 1970) return 0;
    if (((year - 1972) % 4 ) == 0) isLeapYear = 1;
    month--;
    switch (month) {
        case 12: day_of_year += 31;
        case 11: day_of_year += 30; 
        case 10: day_of_year += 31; 
        case 9: day_of_year += 30; 
        case 8: day_of_year += 31; 
        case 7: day_of_year += 31; 
        case 6: day_of_year += 30; 
        case 5: day_of_year += 31; 
        case 4: day_of_year += 30; 
        case 3: day_of_year += 31; 
        case 2: day_of_year += (isLeapYear)? 29 : 28; 
        case 1: day_of_year += 31; 
    }
    /*
    switch (month) {
        case 1: day_of_year += 31; if (month == 1) break;
        case 2: day_of_year += (isLeapYear)? 29 : 28; if (month == 2) break;
        case 3: day_of_year += 31; if (month == 3) break;
        case 4: day_of_year += 30; if (month == 4) break;
        case 5: day_of_year += 31; if (month == 5) break;
        case 6: day_of_year += 30; if (month == 6) break;
        case 7: day_of_year += 31; if (month == 7) break;
        case 8: day_of_year += 31; if (month == 8) break;
        case 9: day_of_year += 30; if (month == 9) break;
        case 10: day_of_year += 31; if (month == 10) break;
        case 11: day_of_year += 30; if (month == 11) break;
        case 12: day_of_year += 31; if (month == 12) break;
    }
    */

   /* // book solution
        int day_of_year(int month, int day, int year)
        {
        int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day_count = 0, i;

        for (i = 1; i < month; i++)
            day_count += num_days[i-1];

        // adjust for leap years, assuming they are divisible by 4
        if (year % 4 == 0 && month > 2)
            day_count++;
        
        return day_count + day;
    */

    return day_of_year;
}

int NumOfDigits(unsigned long long int x) {
    int i = 0;
    do {
        i++;
    } while ((x = x / 10) > 0);
    return i;
}

int Digits(unsigned long long int n, int k) {
    // return Kth digit from the right
    while (n > 0) {        
        k--;
        if ( k == 0) return n % 10;
        n /= 10;
    }
    return 0;
    
    
    /*
    // book solution
    int i;

    for (i = 1; i < k; i++)
        n /= 10;

    return n % 10;
    */
}

int F(int a, int b) {
    return a + b;
}

void Swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int Maximum(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        max = (a[i] > max) ? a[i] : max;
    }
    return max;
}

double Average(int a[], int n) {
    int sum = 0;
    
    for (int i = 0; i < n; i++) sum += a[i];    
    return ((double) sum / n);
}

int NumOfPositiveDigits(int a[], int n) {
    int num = 0;
    for (int i = 0; i < n; i++) 
        num = (a[i] >= 0) ? (num + 1) : num;
    return num;
}

float ComputeGPA(char grades[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        switch (grades[i]) {
            case 'A': sum += 4; break;
            case 'B': sum += 3; break;
            case 'C': sum += 2; break;
            case 'D': sum += 1; break;
            case 'F': sum += 0; break;
        }
    }

    return ((double) sum / size);
}

double InnerProduct(int a[], int b[], int size) {
    double product = 0;
    for (int i = 0; i < size; i++) {
        product = product + a[i] * b[i];
    }
    return product;
}

int EvaluatePosition(char board[8][8]) {
    /* Q:9, R:5, B:3, N:3, P:1 */
    int board_score = 0;

    for (int row = 0; row < 8; row++){
        for (int col = 0; col < 8; col++){
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

double Median(double x, double y, double z) {
    /*
    double a[3] = {x, y, z};
    double s;

    // push the largest number to the right
    for (int i = 0; i < 2; i++) {
        s = (a[i] < a[i+1]) ? a[i] : a[i+1];
        a[i+1] = a[i] + a[i+1]  - s;
        a[i] = s;
    }
    
    // push the smallest number to the left
    for (int i = 2; i > 0 ; i--) {
        s = (a[i] < a[i-1]) ? a[i] : a[i-1];
        a[i] = a[i] + a[i-1]  - s;
        a[i-1] = s;
    }

    return a[1];
    */

    // book solution
      double result;

    if (x <= y)
        if (y <= z) result = y;
        else if (x <= z) result = z;
        else result = x;
    else {
        if (z <= y) result = y;
        else if (x <= z) result = x;
        else result = z;
    }

    return result;
}

unsigned long long int Fact(int n) {
    /* calculate factorial 1 * 2 * 3 * 4 * 5 * 6 */
    return  (n <= 1) ? 1 : n * Fact(n - 1);
}

unsigned long long int Fact1(int n) {
    /* calculate factorial 1 * 2 * 3 * 4 * 5 * 6 */
    /* non-recurrsive */
    unsigned long long int result = 1;
    for (; n > 0; n--) {
        result *= n;
    }
    return result;
}

int GcdR(int m, int n) {    
    return (n == 0) ? 1 : GcdR(n, m % n);
}

void Pb(int n) {
    // convert decimal to binary representation
    if (n != 0) {
        Pb(n / 2);
        putchar('0' + n % 2);
    }
    /*
    Pb(8) 0
        Pb(4); 0
            Pb(2); 0
                Pb(1); 1
                    Pb(0);
    1000

    Pb(9) 1
        Pb(4) 0
            Pb(2) 0
                Pb(1); 1
                    Pb(0);
    1001
    
    */
}