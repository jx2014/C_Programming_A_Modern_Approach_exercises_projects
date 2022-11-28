#define EXERCISE (0)

#if (EXERCISE == 0)
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

int findMax(int *vals, int n) {
    int i, max;
    max = *vals++;

    return max;
}

#define MAX_BYTES 128

int main(void) {
    /*
    int some_array[] = {89, 1, 2, 3, 4, 5, 6};
    int a;
    a = some_array[13];
    a = findMax(some_array, 6);
    */

    setlocale(LC_ALL, "English_United States.1252");
    printf("测试 一二三四五六七八九十，壹贰叁肆伍陆柒捌玖拾\n");

    setlocale(LC_ALL, "");
    printf("测试 一二三四五六七八九十，壹贰叁肆伍陆柒捌玖拾\n");

    setlocale(LC_ALL, "en_US");
    printf("测试 一二三四五六七八九十，壹贰叁肆伍陆柒捌玖拾\n");

    // setlocale(LC_ALL, "English_United States.1252");

    char test[] = "żółtego";

    struct lconv *locale;
    

    locale = localeconv();
    printf("%s ", locale->currency_symbol);
    printf("%s\n", locale->int_curr_symbol);

    mblen(NULL, 0);
    printf("%s, %d\n", test, mblen(test, MAX_BYTES));
    // (wchar_t *) _wsetlocale(0, L"de-DE");

    setlocale(LC_ALL, "en_US.utf8");
    printf("zß水🍌\n");




    return 0;
}
#endif


#if (EXERCISE == 1)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 2)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 3)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 4)
#include <stdio.h>
#include <wchar.h>

int main(void) {
    char *str = "d \xe9j \xe0à vu";
    //unsigned char c[] = "笑";
    //char *str = "a \xe0 à";
    printf("%s\n", str);
    //printf("%c\n", c);
    printf("\xe7\xac\x91\n");
    printf("\xe9\n");
    printf("\xe0\n");
    unsigned char a_p[] = "à";
    unsigned char a[] = "a";
    short unsigned int u[] = u"This is a UTF-16 string.";
          unsigned int U[] = U"This is a UTF-16 string.";
    printf("%s %s\n", a ,a_p);
    printf("\x61\xc3\xa0\n");
    printf("%s\n%s\n", u, U);

    return 0;
}
#endif

#if (EXERCISE == 5)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 6)
/* Trigraph exercise */
// Need to compile with gcc -trigraphs .\ch25_exercises.c -o ch25_exercises.exe

??=include <stdio.h>
??=include <ctype.h>

??=define KEY 'a'

int main(void) ??<
    char orig_char, new_char;


    while ((orig_char = getchar()) != '\n') ??<
        new_char = orig_char ^ KEY;
        if (isprint(orig_char) && isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    ??>

    return 0;
??>
#endif
