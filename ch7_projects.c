#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define PROJECT (13)

int main(void){
    #if (PROJECT == 1)
        /* Prints the square for a number */

        int n;
        printf("This program prints a table of squares.\n");
        printf("Enter number of entries in table: ");
        scanf("%d", &n);
        
        printf("%u %d\n", n * n, n * n);

    #endif

    #if (PROJECT == 2)
       /* Prints a table of squares using an odd method */

        int i, n, odd, square;
        printf("This program prints a table of squares.\n");
        printf("Enter number of entries in table: ");
        scanf("%d", &n);
        getchar(); // remove new-line character following number of entries.

        i = 1;
        odd = 3;
        for (square = 1; i <= n; odd += 2) {
            printf("%10d %10d\n", i, square);
            if (i % 24 == 0) {
                printf("Press Enter to continue ...");
                getchar();
            }
            ++i;
            square += odd;
        }


    #endif

    #if (PROJECT == 3)
        double sum = 0, d = 1;

        printf("This program sums a series of double integers.\n");
        printf("Enter integers (0 to terminate): ");    
        while (d != 0) {
            scanf("%lf", &d);
            sum += d;
        }
        printf("The sum is: %f\n", sum);

    #endif

    #if (PROJECT == 4)
        char c = 0;

        printf("Entere a phone number: ");
        while (c != '\n') {
            c = getchar();
            
            if ((c >= 97 && c <= 122)) c -= 32; // convert lower case to upper case;
            
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
            putchar(c);
        }
        putchar('\n');

    #endif

    #if (PROJECT == 5)
        char c = 0;
        int score = 0;
        
        printf("Enter a word: ");
        
        while ( (c = getchar()) != '\n') {
            switch(toupper(c)) {
                case 'A': case 'E': case 'I':
                case 'L': case 'N': case 'O':
                case 'R': case 'S': case 'T': case 'U':
                    score += 1; break;
                case 'D': case 'G':
                    score += 2; break;
                case 'B': case 'C': case 'M': case 'P':
                    score += 3; break;
                case 'F': case 'H': case 'V': case 'W': case 'Y':
                    score += 4; break;
                case 'K':
                    score += 5; break;
                case 'J': case 'X':
                    score += 8; break;
                case 'Q': case 'Z':
                    score += 10; break;
            }
        }
        printf("Scrabble value: %d\n", score);

    #endif

    #if (PROJECT == 6)
        printf("sizeof(char): %Ld\n", sizeof(char));
        printf("sizeof(int): %Ld\n", sizeof(int));        
        printf("sizeof(short): %Ld\n", sizeof(short));
        printf("sizeof(long): %Ld\n", sizeof(long));
        printf("sizeof(long long): %Ld\n", sizeof(long long));
        printf("sizeof(unsigned long long): %Ld\n", sizeof(unsigned long long));
        printf("sizeof(float): %Ld\n", sizeof(float));
        printf("sizeof(double): %Ld\n", sizeof(double));
        printf("sizeof(long double): %Ld\n", sizeof(long double));

        /*
        sizeof(char): 1
        sizeof(int): 4
        sizeof(short): 2
        sizeof(long): 4
        sizeof(long long): 8
        sizeof(unsigned long long): 8
        sizeof(float): 4
        sizeof(double): 8
        sizeof(long double): 16
        */

    #endif
    
    #if (PROJECT == 7)
        // fraction calculation
        int num1=0, denom1=0, num2=0, denom2=0, result_num=0, result_denom=0;
        char operator;

        printf("Enter two fraction numbers (1/3+3/2): ");
        scanf("%d / %d %c %d / %d", &num1, &denom1, &operator, &num2, &denom2);

        switch (operator) {
            case '+':
                result_denom = denom1 * denom2;
                result_num = num1 * denom2 + num2 * denom1;
                break;
            case '-':
                result_denom = denom1 * denom2;
                result_num = num1 * denom2 - num2 * denom1;
                break;
            case '*':
                result_denom = denom1 * denom2;
                result_num = num1 * num2;
                break;
            case '/':
                result_denom = denom1 * num2;
                result_num = num1 * denom2;
                break;
        }

        printf("result is: %d/%d", result_num, result_denom);
        // reduce to lower terms
        int smaller_num = (result_num<result_denom) ? result_num : result_denom;
        for (int n = 2; n <= smaller_num; n++) {
            if (result_num % n == 0 && result_denom % n == 0) {
                result_num = result_num / n;
                result_denom = result_denom / n;
                n--; // need to retest the same n for the next round.
            }
        }
        
        // special handling of various forms of fraction
        if (result_denom == 1 || result_num == 0) {
            printf(" (%d)\n", result_num);
        } else if (result_num > result_denom) {
            int whole_int = result_num / result_denom;
            result_num = result_num - whole_int * result_denom;
            printf(" (%d %d/%d)\n", whole_int, result_num, result_denom);
        } else {
            printf(" (%d/%d)\n", result_num, result_denom);
        } 

    #endif

    #if (PROJECT == 8)
        int h = 0, m = 0, user;
        int d1, d2, d3, d4, d5, d6, d7, d8;
        char p;

        d1 =  8 * 60;
        d2 =  9 * 60 + 43;
        d3 = 11 * 60 + 19;
        d4 = 12 * 60 + 47;
        d5 = 2 * 60 + 12 * 60;
        d6 = 3 * 60 + 12 * 60 + 45;
        d7 = 7 * 60 + 12 * 60;
        d8 = 9 * 60 + 12 * 60 + 45;

        printf("Enter estimated departure time: ");
        scanf(" %2d :%2d %c", &h, &m, &p);

        p = toupper(p);
        h %= 12;
        if (p == 'A') {
            ;
        } else if (p == 'P') {
            ;
            h += 12;
        } else {
            printf("Need to input 'AM' or 'PM'.\n");
            return 0;
        }
        user = h * 60 + m;

        
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
    #endif

    #if (PROJECT == 9)
        // convert 12 hour time to 24 hour time
        int hr = -1, min;
        char p;
        while (hr >= 24 || hr < 0 || min < 0 || min >= 60) {            
            printf("Enter a 12-hour time: ");
            scanf("%d :%d %c", &hr, &min, &p);
            while (getchar() != '\n');
            p = toupper(p);
        }
        
        hr = (p == 'P') ? hr % 12 + 12 : hr % 12;

        printf("Equivalent 24-hour time: %02d:%02d\n", hr, min);
    #endif

    #if (PROJECT == 10)
        // count number of vowels in a sentence
        char c;
        int n = 0;
        printf("Enter a sentence: ");
        while ((c = getchar()) != '\n') {
            c = toupper(c);        
            switch(c) {
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    n++;       
            }
        }

        printf("Your sentence contains %d vowel(s).\n", n);

    #endif
    
    #if (PROJECT == 11)
        // Display Last name, First initial.
        char c, firstInitial;
        _Bool isFirstLetter = 0;

        printf("Enter a first name and last name: ");
        scanf(" %c", &firstInitial);
        while ((c = getchar()) != ' '); // loop through remaining of first name.
        while ((c = getchar()) != '\n') {
            if (toupper(c) >= 'A' && toupper(c) <= 'Z') {      
                if (!isFirstLetter) {
                    c = toupper(c);       
                    isFirstLetter = 1;
                }
                putchar(c);
            }
        }
        printf(", %c.\n", toupper(firstInitial));
    #endif

    #if (PROJECT == 12)
        // evaluates an expression
        // 1+2.5*3 = 10.5
        char c = 0;
        float n = 0, total = 0;

        printf("Enter an expression: ");
        scanf(" %f", &total);
        while( (c = getchar()) != '\n') {      
            if (c == ' ') {
                while ((c = getchar()) == ' '); // remove white space
            }
            scanf(" %f", &n);
            switch(c) {
                case '+':
                    total = total + n;
                    break;
                case '-':
                    total = total - n;
                    break;
                case '*':
                    total = total * n;
                    break;
                case '/':
                    total = total / n;
                    break;
            }
        }
        printf("Value of expression: %f\n", total);

    
    #endif

    #if (PROJECT == 13)
        // calculate average word length
        int nWord = 0, nLetter = 0;
        char c;
        printf("Enter a sentence: ");
        // works but ugly
        scanf(" %c", &c); 
        nLetter = 1; // the very first letter.
        while (( c = getchar() ) != '\n') {
            if (toupper(c) <= 'Z' && toupper(c) >= 'A') nLetter++;
            if (c == ' ') {
                nWord++;
                while((c = getchar()) == ' ');
                if (toupper(c) <= 'Z' && toupper(c) >= 'A') nLetter++;
                if (c == '\n') { // reached the end of sentence
                    nWord--; 
                    break; 
                }
            }
        }
        nWord++;
        printf("Average word size is %.2f\n", (float) nLetter / nWord);
    
    #endif

    #if (PROJECT == 14)
        // calculate square root using Newton's method
        double x, y, w; 
        printf("Enter a positive number: ");
        scanf("%lf", &x);
        w = x * 0.25 + 1; 
        do {
            y = w;            
            w = (w + x / w) / 2;
        } while ( fabs(y - w) > ( y * 0.00001) );
        
        printf("%f\n", w);
    #endif

    #if (PROJECT == 15)
        int x;
        long double f = 1;
        printf("Enter a positive integer: ");
        scanf(" %d", &x);

        for (; x >= 1; x--) {
            f *= x;
        }

        printf("Factorial is: short) %ud\n", (short) f);
        printf("Factorial is: (int) %d\n", (int) f);
        printf("Factorial is: (long) %ld\n", (long) f);
        printf("Factorial is: (long long) %lld\n", (long long) f);
        printf("Factorial is: (unsigned long long) %lld\n", (unsigned long long) f);
        printf("Factorial is: (float) %f\n", (float) f);
        printf("Factorial is: (double) %g\n", (double) f);
        printf("Factorial is: (long double) %Lf\n", f);
    
    #endif

    return 0;
}