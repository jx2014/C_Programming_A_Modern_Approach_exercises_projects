#define PROJECT (7)

#if (PROJECT == 1)
// Solve the roots of the equation ax^2+bx+c=0 using
// quadratic equation: x = {-b +/- sqrt(b^2-4ac)} / 2a
// prompt the user to enter vlaues for a, b, and c.

#include <math.h>
#include <stdio.h>

int main(void) {
    double a, b, c;
    double x1, x2;
    printf("Enter the cofficient for a, b, and c to solve ax^+bx+c=0: ");
    scanf(" %lf %lf %lf", &a, &b, &c);

    if ((b*b - 4 * a * c) < 0)
        fprintf(stdout, "Roots ar complex numbers\n");
    else {
        x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
        x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;
        fprintf(stdout, "x1 = %12.6lf\nx2 = %12.6lf\n", x1, x2);
    }

    return 0;
}
#endif

#if (PROJECT == 2)
// copies a text file from stdin to stdout, removing all
// white-space characters fro mthe beginning of each line.
// a line consisting entirely of white-space characters
// will not be copied.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int c;
    char *white_spaces = " \t\f\v\r\n";
    // book answer, use isspace(c) instead of white_spaces.
    int print_new_line = 0;

    while ((c = fgetc(stdin)) != EOF) {
        // book answer: if(!isspace(c))
        if (!isspace(c)) {
        // if (!strchr(white_spaces, c)) {
            putc(c, stdout);
            print_new_line = 1;
        }
        else if (c == '\n') {
            if (print_new_line) {
                putc(c, stdout);
                print_new_line = 0;
            }
            else
                continue;
        }
    }

    return 0;
}
#endif

#if (PROJECT == 3)
// copies a text file from stdin to stdout, captalizing
// the first letter of each word.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int c;
    bool was_space = true;

    while((c = getc(stdin)) != EOF) {
        if (isspace(c) || strchr("(:", c)) {
            was_space = true;
        } else if (isalpha(c)) {
            if (was_space) {
                c = toupper(c);
                was_space = false;
            }
        } else {
            was_space = false;
        }
        putc(c, stdout);
    }


    return 0;
}
#endif

#if (PROJECT == 4)
// Prompts the user to enter a series of words
// seperated by a single space. Then print out 
// each word in reverse order by using strtok.

#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[256];
    char *words[128];
    int i = 0;
    char *p;
    fprintf(stdout, "Enter a series of words separated by a single space: ");    
    fgets(buffer, 256, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    p = strtok(buffer, " ");
    while (p != NULL) {        
        words[i++] = p;
        p = strtok(NULL, " ");
    }
    
    for (i-=1; i >= 0; i--) {
        fprintf(stdout, "%s ", words[i]);
    }
    fprintf(stdout, "\n");

    return 0;
}
#endif

#if (PROJECT == 5)
// calculate compond interest rate
#include <stdio.h>
#include <math.h>

int main(void) {
    double base;
    long double rate;
    int years;

    fprintf(stdout, "Enter the amount of deposit, interest rate, and years of investment: ");
    scanf("%lf %Lf %d", &base, &rate, &years);

    fprintf(stdout, "Total amount is: $%.2Lf\n", base * expl(years * rate));
    return 0;
}
#endif

#if (PROJECT == 6)
// Copies a text file from stdin to stdout, replacing each 
// control character (other than '\n') by a question mark.

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;

    while ((c = fgetc(stdin)) != EOF) {
        if (iscntrl(c) && c != '\n')
            fputc('?', stdout);
        else
            fputc(c, stdout);
    }

    return 0;
}
#endif

#if (PROJECT == 7)
// count the number of sentences in a text file, obtained from stdin.
// each sentence is assumed to ends with a ., ?, or ! followed by a 
// white-space character, including \n.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int c;
    int count = 0;

    while ((c = getc(stdin)) != EOF) {
        if (strchr(".?!", c)) {
            c = getc(stdin);
            if (isspace(c) || c == -1)
                count++;
        }
    }

    fprintf(stdout, "Count of sentences: %d\n", count);

    return 0;
}
#endif