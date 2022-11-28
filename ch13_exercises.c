#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define EXERCISE (18)

#if (EXERCISE == 1)
int main(void) {

    printf("%c", '\n'); // ok, '\n' is character of length 1
    printf("%c", "\n"); // ok "\n" is character of length 2 "\n\0"
    //printf("%s", 2'\n'); // ok
    printf("%s", "\n"); // ok
    //printf('\n');       // ok
    printf("\n");       // ok
    putchar('\n');      // ok
    //putchar("\n");      // nok
    //puts('\n');         // nok, needs \0
    puts("\n");         // ok
    puts("");           // ok

    return 0;
}  
#endif


#if (EXERCISE == 2)
int main(void) {
    char *p = "abc";
    //putchar(p);     // nok, p is a pointer char. 
    putchar(*p);    // ok, a
    puts(p);        // ok, abc
    //puts(*p);       // nok, puts expect a pointer and will search until '\0' is found

    return 0;
}
#endif

#if (EXERCISE == 3)
int main(void) {
    // enter 123abc34 56def78
    // i:123
    // s:abc34
    // j:56
    int i, j;
    char s[10];

    printf("enter something: ");
    scanf("%d%s%d", &i, s, &j);

    return 0;
}
#endif

#if (EXERCISE == 4)
int main(void) {
    
    #define N (5)
    char user_input[N];
    int n;

    // read_line to skip white space before beginning to store input characters
    int read_line_a(char str[], int n) {
        int ch, i = 0;
        
        while ((ch = getchar()) != '\n') {
            if (ch == ' ') continue;
            if (i < n)
                str[i++] = ch;
        }
        str[i] = '\0';  // string termination
        return i;       // number of characters stored.
    }

    // stop reading at the first white space.
    int read_line_b(char str[], int n) {
        int ch, i = 0;
        
        while ((ch = getchar()) != '\n' && !isspace(ch)) {            
            if (i < n)
                str[i++] = ch;
        }
        str[i] = '\0';  // string termination
        return i;       // number of characters stored.
    }

    // stop reading at the first new-line character, then stores the new-line character in the string
    int read_line_c(char str[], int n) {
        int ch, i = 0;
        
        do {
            ch = getchar();
            if (i < n)
                str[i++] = ch;
        } while (ch != '\n');
        str[i] = '\0';  // string termination
        return i;       // number of characters stored.
    }

    // book solution
    int read_line_d(char str[], int n)
    {
        int ch, i;

        for (i = 0; i < n; i++) {
            ch = getchar();
            if (ch == '\n')
                break;
            str[i] = ch;
        }
        str[i] = '\0';
        return i;
    }

    printf("Enter some strings no more than %d characters: ", N);
    n = read_line_d(user_input, N);
 
    printf("%d characters entered\n%s\n", n, user_input);

    return 0;
}
#endif

#if (EXERCISE == 5)
int main(void) {

    // p309. using array subscripting to capitalize all letters in a null-terminated string.
    char user_str[] = "abcdefg 1234567 xyzuvw?";

    void capitalize_str(char s[]) {
        for (int i = 0; s[i] != '\0'; i++) {
            s[i] = toupper(s[i]);
        }
    }

    // using poitner arithmetic 

    void capitalize_str_2(char s[]) {
        char *c;
        for (c = s; *c != '\0'; c++) {
            *c = toupper(*c);
        }
    }

    printf("Before: %s\n", user_str);
    capitalize_str_2(user_str);
    printf("After: %s\n", user_str);


    return 0;
}
#endif

#if (EXERCISE == 6)
int main(void) {
    // replace foo with xxx
    // "food fool" will become "xxxd xxxl"

    char user_str[] = "a fool is a food but food is not a fool.";

    void censor(char s[]) {
        char *c;
        for (c = s; *c != '\0'; c++) {
            if (*c == 'f' && *(++c) == 'o' && *(++c) == 'o') {
                *c = *(c-1) = *(c-2) = 'x';                        
            }
        }
    }            

    printf("Before: %s\n", user_str);
    censor(user_str);
    printf("After: %s\n", user_str);

    return 0;
}
#endif

#if (EXERCISE == 7)
int main(void) {

    char str1[] = "an array of characters";
    char str2[] = "an array of characters";
    char str3[] = "an array of characters";
    char str4[] = "an array of characters"; 

    *str1 = 0;
    str2[0] = '\0';
    strcpy(str3, "");
    strcat(str4, ""); // this is not equivalent as the other 3
    return 0;
}
#endif

#if (EXERCISE == 8)
int main(void) {
    char str[100];

    strcpy(str, "tire-bouchon"); // str1 is "tire-bouchon\0"
    printf("%s\n", str);
    strcpy(&str[4], "d-or-wi");  // str2 is "tired-or-wi\0"
    printf("%s\n", str);
    strcat(str, "red?");         // str3 is "tired-or-wired?\0"
    printf("%s\n", str);
    
    return 0;
}
#endif

#if (EXERCISE == 9)
int main(void) {
    char s1[100], s2[100], s3[] = "abc";

    strcpy(s1, "computer");
    strcpy(s2, "science");

    if (strcmp(s1, s2) < 0)
        strcat(s1, s2); // s1: computerscience
    else
        strcat(s2, s1); // s2: sciencecomputer
    s1[strlen(s1) - 6] = '\0'; // computerscience\0
                              // computers\0
    printf("%d\n", strlen(s3));
    printf("s1: %s", s1);
    
    return 0;
}
#endif

#if (EXERCISE == 10)
int main(void) {
    // creates an identical copy of a string
    char *original_str = "this is the strong.";
    char *q2;
    char target_str[100];

    char *duplicate(const char *p) {
        char *q; // q is pointer type with no allocated space to store strings.
        strcpy(q, p); 
        return q; // wrong, func returns address of local variable
    }

    q2 = duplicate(original_str);
    target_str[0] = original_str;

    return 0;
}
#endif


#if (EXERCISE == 11)
int main(void) {
    // strcmp written using pointer arithemtic 
    // original version in Q & A (pg. 306)
    char *a = "string a";
    char *b = "string b";
    char *c = "string a";
    int i, j, k;

    int strcmp(char *s, char *t) {        
        for (;(*s == *t); s++, t++) {
            if (*s == '\0') {
                return 0;
            }            
        } 
        return *s - *t;
    }

    i = strcmp(a, b);
    j = strcmp(a, c);
    k = strcmp(b, c);

    return 0;
}
#endif

#if (EXERCISE == 12)
int main(void) {
    char *file_name = "readmetxt1234567890txtlog";
    char ext[100];

    void get_extension(const char *file_name, char *extension) {
        const char *p;
        int i = strlen(file_name);
        for (p = &file_name[i]; *p != '.'; p--);
        
        if ( (p - file_name) < i ) {
            strcpy(extension, &file_name[(p - file_name) + 1]);
        }
    }
    get_extension(file_name, ext);
    
    printf("File extension is \"%s\".\n", ext);

    return 0;
}
#endif

#if (EXERCISE == 13)
int main(void) {
    char *domain_url = "knking.com";
    char index_url[1000];

    // function to add "https://www."" and "/index.html" to domain name
    void build_index_url(const char *domain, char *index_url) {
        strcpy(index_url, "htts://www.");
        strcat(index_url, domain_url);
        strcat(index_url, "/index.html");
    }

    build_index_url(domain_url, index_url);

    printf("index url for domain: \"%s\" is \"%s\".\n", domain_url, index_url);

    return 0;
}
#endif

#if (EXERCISE == 14)
int main(void) {
    char s[] = "Hsjodi", *p;
    for (p = s; *p; p++) { //               H s j o d i
        --*p;              // *p = *p - 1;  G r i n c h
    }
    puts(s);

    return 0;
}
#endif

#if (EXERCISE == 15)
int main(void) {

    int f(char *s, char *t) {
        char *p1, *p2;

        for (p1 = s; *p1; p1++) {            // d
            for (p2 = t; *p2; p2++) {        // c
                if (*p1 == *p2) break;
            }
            if (*p2 == '\0') break;
        }
        return p1 - s;
    }

    printf("%d\n", f("abcd", "babc")); // 3
    printf("%d\n", f("abcd", "bcd"));  // 0
    // in general f returns the index of first character in s that does not present in t.

    return 0;
}
#endif

#if (EXERCISE == 16)
int main(void) {
    // condensing count_space from 13.4 using technique found in 13.6, i.e., replace for loop with while loop.

    // original count_spaces in 13.4
    int count_spaces(const char s[]) {
        int count = 0, i;
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ')
                count++;
        }
        return count;
    }

    // condensed version using idioms from 13.6
    int count_spaces2(const char *s) {
        int count = 0;
        while (*s) {
            if (*s++ == ' ') // test for *s == ' ', then s++ at end of loop;
                count++;            
        }
        return count;
    }

    char *some_string = " this is a string with 6 spaces. ";

    printf("%d\n%d\n", count_spaces(some_string), count_spaces2(some_string));

    return 0;
}
#endif

#if (EXERCISE == 17)
int main(void) {

    // method 1
    bool test_extension_1(const char *file_name,
                        const char *extension) {
        
        const char *p, *q;
        p = &file_name[strlen(file_name) - 1];
        q = &extension[strlen(extension) - 1];        

        while (p >= file_name && q >= extension && *p != '.') {
            if (toupper(*p) != toupper(*q)) {
                return false;
            }
            p--; 
            q--;
        }
        return (*p == '.' && (q + 1) == extension) ? true : false;
    }

    printf("%d\n", test_extension_1("memo.txt", "TXT"));
    printf("%d\n", test_extension_1("memo.log", "TXT"));
    printf("%d\n", test_extension_1("memo.logtxt", "TXT"));
    printf("%d\n", test_extension_1("memo.logtxt", "memo.logtxt"));
    printf("%d\n", test_extension_1("memo.logtxt", ""));
    printf("%d\n", test_extension_1("memo", ""));

    // method 2
    bool test_extension_2(const char *file_name,
                        const char *extension) {
        
        const char *p, *q;
        p = file_name;
        q = extension;

        while (*p != '.') {
            p++;
        }
        
        for (p++; *p && *q; p++, q++) {
            if (toupper(*p) != toupper(*q)) {
                return false;
            }            
        }
        return (*p == *q);
    }

    printf("Method 2\n");

    printf("%d\n", test_extension_2("memo.txt", "TXT"));
    printf("%d\n", test_extension_2("memo.log", "TXT"));
    printf("%d\n", test_extension_2("memo.logtxt", "TXT"));
    printf("%d\n", test_extension_2("memo.logtxt", "memo.logtxt"));
    printf("%d\n", test_extension_2("memo.logtxt", ""));
    printf("%d\n", test_extension_2("memo", ""));
    return 0;
}
#endif

#if (EXERCISE == 18)
int main(void) {
    // turn "http://www.knking.com/index.html" to 
    //      "http://www.knking.com"
    void remove_filename(char *url) {        
        for (; *url; url++) {
            if (*url == '/' && *(url - 1) == '/') {
                while (*(url++)) {                    
                    if (*url == '/') {
                        *url = '\0';
                        return;
                    }                    
                }
            }
        }

    }

    char some_url[] = "http://www.knking.com/index.html";    
    
    printf("Before: %s\n", some_url);
    remove_filename(some_url);
    printf("After: %s\n", some_url);

    return 0;
}
#endif
