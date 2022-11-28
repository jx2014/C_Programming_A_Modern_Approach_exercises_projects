#define EXERCISE (13)

#if (EXERCISE == 0)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    int a;
    char *p;
    // printf("enter a digit: ");
    // scanf(" %d", &a);
    // printf("%d divid by zero is: %d", a, a/0);

    char str[] = " April  28,1998";
    char str2[] = " Thisisanotherstring 1998 28 April";
    p = strtok(str, " \t");     // p poinst to A in April
                                // str now becomes " April\0 28,1998\0"
    
    p = strtok(NULL, " \t,");   // p points to 2 in 28
                                // str now becomes " April\0 28\01998\0"
    
    p = strtok(str2, "s");      // p becomes "Th", and str2 becomes
                                // " Thi/0isanotherstring 1998 28 April"

    /*
    p = strtok(NULL, " \t");    // p points to 1 in 1998
                                // str now becomes " April\0 28\01998\0"
    */

     return 0;
}
#endif

#if (EXERCISE == 1)
#include <stdio.h>
#include <math.h>

// round a floating-point number x to n digits after the decimal point.
// round_nearest(3.14159, 3) would return 3.142
double round_nearest(double x, int n) {
    double E = pow(10.0, n);
    return (x * E) < 0.0 ? ceil(x * E - 0.5) / E : floor(x * E + 0.5) / E;
}

int main(void) {
    double result;

    result = round_nearest(3.14159, 3);         // expect 3.142
    result = round_nearest(-3.14159, 3);        // expect -3.142


    return 0;
}
#endif

#if (EXERCISE == 2)
#include <math.h>
// Evaluate polynomial using Horner's Rule:
// 4X^3 + 7x^2 + 5x + 3 can be written as:
// ((4x + 7)x + 5)x + 3
// uses double fma(double x, double y, double z); 
// where fma(a, b, c) is the same as a * b + c;

double evaluate_polynomial(double a[], int n, double x) {
    /*
        A = fma(a[n], x, a[n-1]) //(4x + 7)
        A = fma(A, x, a[n-2])   // (Ax + 5)
        A = fma(A, x, a[n-3])   // (Bx + 3)
    */
    double A;

    A = fma(a[n-1], x, a[n-2]);
    n -= 2;
    while (n > 0) {
        A = fma(A, x, a[--n]);
    }
    
    return A;
}

int main(void) {
    double a[]={3, 5, 7, 4};
    double y;
    y = evaluate_polynomial(a, 4, 3);

    return 0;
}
#endif

#if (EXERCISE == 3)
#include <math.h>

int main(void) {

    return 0;
}
#endif

#if (EXERCISE == 4)
// check an input string has the syntax of a C identifier
// that consists of letters, digits, and underscores, with 
// a letter or underscore at the beginning.

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool valid_identifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }

    for (int i = 1; i < strlen(str); i++)  {
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }

    return true;
}

int main(void) {
    bool a;
    a = valid_identifier("a");          // true
    a = valid_identifier("1");          // false
    a = valid_identifier("123");        // false
    a = valid_identifier("_abc");       // true
    a = valid_identifier("_123abc");    // true
    a = valid_identifier(".123abc");    // false
    a = valid_identifier("=123abc");    // false
    a = valid_identifier("_12-3abc");   // false
    a = valid_identifier("_12=3abc");   // false
    a = valid_identifier("_12_3abc");   // true

    int _abc;
    // int 123; // invalid id
    int _12abc;
    // int abc-cbc; // invalid id
    int abc123;
    // int abc_123-123; // invalid id

    return 0;
}
#endif

#if (EXERCISE == 5)
// check if a string contains only hexdigits 0 to 9, a to f.

#include <ctype.h>
#include <string.h>
int hex2int_single(char c) {
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else if ((c >= 'A' && c <= 'F')) {
        return c - 'A' + 10;
    } else if ((c >= '0' && c <= '9')){
        return c - '0';
    }
    return -1;
}

long int hex2int(char *hexstr) {
    long int x = 0;
    long int m = 1;
    for (int i = strlen(hexstr) - 1; i >= 0 ; i--) {
        if (isxdigit(hexstr[i])) {
            x = x + hex2int_single(hexstr[i]) * m;
            m *= 16;
        } else
            return -1;
    }
    return x;
}

int main(void) {
    long int x;
    x = hex2int("123");
    x = hex2int("f");
    x = hex2int("abc");
    x = hex2int("dEf");
    x = hex2int("dxf");

    return 0;
}
#endif

#if (EXERCISE == 6)
// Indicate which function would be the best to use:
// memcpy, memmove, strcpy, or strncpy.
// All indicated action is to be performed by a single
// function call.

#include <string.h>

int main(void) {
    char s1[6] = {'a', 'b', 'c', 'd', '\0'};

    // a) Moving all elements of an array "down" one position in order to leave room
    //    for a new element in position 0. -> memmove
    memmove(s1 + 1, s1, strlen(s1));
    s1[0] = '*';
    // b) Deleting the first character in a null-terminated string by moving all other
    //    characters back on position.     -> memmove (can't use strcpy due to overlaps)
    memmove(s1, s1+1, strlen(s1));

    // c) Copying a string into a character array that may not be large enough to hold
    //    it. If the array is too small assume that the string is to be truncated; no     
    //    null character is necessary at the end. -> strncpy
    char *s2 = "ABCDEFGHIJKLMNOP";
    strncpy(s1, s2, 6);

    // d) Copying the contents of one array variable into another. -> memcpy    
    memcpy(s1, "0123456789", 6);



    return 0;
}
#endif

#if (EXERCISE == 7)
// Practice using strchr to searching all characters in a string.
// Is it possible to use strrchr to reversly search all characters in a string.
// No, strrchr cannot search all characters in reverse order. 
#include <string.h>

int main(void) {
    char *str = "The following form is an example of badly formatted string.";
    char *p;

    p = strchr(str, 'f');   // p points to following form ...
    while (p != NULL) {
        p = strchr(p + 1, 'f'); // p points to form is an ....
    }                           // and repeats until p is 0x0

    p = strrchr(str, 'f');  // p points to formated string...
    p = strrchr(str + (str - p), 'f');
    return 0;
}
#endif

#if (EXERCISE == 8)
#include <string.h>

// numchar returns the number of times the character 
// ch occurs in the string s.
int numchar(const char *s, char ch) {
    int n = 0;
    s = strchr(s, ch);
    while (s != NULL) {
        n++;
        s = strchar(s + 1, ch);
    }
    return n;
}

int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 9)
// repalce the following test condition with a single call of strchr
// if (ch == 'a' || ch == 'b' || ch == 'c' ) ...
// if (srchr("abc", ch)) ...

#include <string.h>

int main(void) {
    if (strchr("abc", ch) != NULL) {
        // ...
    }


    return 0;
}
#endif

#if (EXERCISE == 10)
// Replace the test condition in the following if statement by a single call of strstr:
// if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0) || strcmp(str, "baz") == 0) ...

#include <string.h>

int main(void) {
    char *str = "bar";

    if (strstr("foo bar baz", str) != NULL) {
        ;
    }

    return 0;
}
#endif

#if (EXERCISE == 11)
// Use a call of memset that replaces the last n characters in a
// null-terminated string s with ! characters.
#include <string.h>

int main(void) {
    char s[] = "abcdefghijklmno";
    int n = 5;

    memset(s + strlen(s) - n, '!', n);


    return 0;
}
#endif

#if (EXERCISE == 12)

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// returns a pointer to a copy of s stored in memory obtained 
// by calling malloc. 
void *strdup2(char *s) {
    char *p = malloc(strlen(s) + 1);
    if (p == NULL)
        return NULL;
    strcpy(p, s);
    return p;
}

// similar to strcmp, but ignore cases;
// identical to stricmp()
int stricmp2(char *str1, char *str2) {
    int result;
    size_t i = 0;
    while ( ((result = (tolower(str1[i]) - tolower(str2[i]))) == 0) && (str1[i++] != '\0')) {
        ;
    }
    return result > 0 ? 1 : (result < 0 ? -1: 0);
}

// similar to strlwr(s)
// Converts upper-case letters in s to lower case. returns s.
char * strlwr2(char *s) {
    size_t i = 0;
    while (*(s + i) != '\0') {
        *(s+i) = tolower(*(s+i));
        i++;
    }
    
    return s;
}

// similar to strrev(s)
// reverse the characters in s, except null character, returns s.
char * strrev2(char * s) {
    for (int i = 0; i < (strlen(s) - i - 1); i++) {
        if (*(s + i) == *(s + strlen(s) - i - 1))
            continue;
        *(s + i) = *(s + i) ^ *(s + strlen(s) - i - 1);
        *(s + strlen(s) - i - 1) = *(s + i) ^ *(s + strlen(s) - i - 1);
        *(s + i) = *(s + i) ^ *(s + strlen(s) - i - 1);
    }
    return s;
}

// similar to strset(s, ch);
// fill string s with character ch, returns s;
char * strset2(char *s, char ch) {
    size_t i = 0;
    while (*(s + i) != '\0') {
        *(s + i) = ch;
        i++;
    }
    return s;
}

int main(void) {
    char *str = "abcdefg";
    char *p = strdup2(str);

    char *str2 = "AbcdefG";
    int i = stricmp2(str, str2);

    char str3[] = "AbCd eFgHi!!@Test 123 tEsT !!!?";
    char *str4;
    str4 = strlwr2(str3);
    str4 = strlwr(str3); // original

    strcpy(str3, "AbCd eFgHi!!@Test 123 tEsT !!!?");
    str4 = strrev2(str3);

    char * str5;
    str5 = strset2(str3, '\0');

    return 0;
}
#endif

#if (EXERCISE == 13)
#include <string.h>

// Use strtok to write a function that count words.
// Returns the number of words in the string sentence, where a "word" is 
// any sequence of non-white-space characters.
int count_words(char *sentence) {
    int n = 0;
    char *white_spaces = " \t\f\v\r\n";
    char *p;
    p = strtok(sentence, white_spaces);
    while (p != NULL) {
        n++;
        p = strtok(NULL, white_spaces);
    }
    return n;
}

int main(void) {
    char sentence[] = "This is a    sentence\nA\rsecond\fsentence, is it? yes, it is.";
    char *p;
    int n = count_words(sentence);

    return 0;
}
#endif
