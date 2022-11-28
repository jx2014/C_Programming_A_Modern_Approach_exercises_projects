#define PROJECT (2)

#if (PROJECT == 1)
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    char *p, *q;
    p = setlocale(LC_ALL, NULL);
    q = setlocale(LC_ALL, "");

    if (strcmp((char *) p, (char *) q) == 0) {
        printf("Locale \"C\" is the same as locale \"\"\n");
    } else {
        printf("Locale \"C\" is not the same as locale \"\"\n");
    }

    return 0;
}

/*
// book answer
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *temp, *C_locale;

  temp = setlocale(LC_ALL, NULL);
  // "C" is the current locale by default
  if (temp == NULL) {
    printf("\"C\" locale information not available\n");
    exit(EXIT_FAILURE);
  }

  C_locale = malloc(strlen(temp) + 1);
  if (C_locale == NULL) {
    printf("Can't allocate space to store locale information\n");
    exit(EXIT_FAILURE);
  }

  strcpy(C_locale, temp);

  temp = setlocale(LC_ALL, "");
  if (temp == NULL) {
    printf("Native locale information not available\n");
    exit(EXIT_FAILURE);
  }

  if (strcmp(temp, C_locale) == 0)
    printf("Native locale is the same as the \"C\" locale\n");
  else
    printf("Native locale is not the same as the \"C\" locale\n");

  return 0;
}
*/
#endif

#if (PROJECT == 2)

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_LOCALE_STR(PROPERTY) printf("%-20.20s %10.10s\n", #PROPERTY, pLocale->PROPERTY)
#define PRINT_LOCALE_CHAR(PROPERTY) printf("%-20.20s %10d\n", #PROPERTY, pLocale->PROPERTY)

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"English_United States.1252\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *p;
    p = setlocale(LC_ALL, argv[1]);
    if (p == NULL) {
        fprintf(stderr, "Invalid locale.\n");
        exit(EXIT_FAILURE);
    }

    struct lconv *pLocale = localeconv();
    
    // printf("decimal_point %s\n", pLocale->decimal_point);
    PRINT_LOCALE_STR(decimal_point);
    PRINT_LOCALE_STR(thousands_sep);
    PRINT_LOCALE_STR(grouping);
    PRINT_LOCALE_STR(int_curr_symbol);
    PRINT_LOCALE_STR(currency_symbol);
    PRINT_LOCALE_STR(mon_decimal_point);
    PRINT_LOCALE_STR(mon_thousands_sep);
    PRINT_LOCALE_STR(mon_grouping);
    PRINT_LOCALE_STR(positive_sign);
    PRINT_LOCALE_STR(negative_sign);
    PRINT_LOCALE_CHAR(int_frac_digits);
    PRINT_LOCALE_CHAR(frac_digits);
    PRINT_LOCALE_CHAR(p_cs_precedes);
    PRINT_LOCALE_CHAR(p_sep_by_space);
    PRINT_LOCALE_CHAR(n_cs_precedes);
    PRINT_LOCALE_CHAR(n_sep_by_space);
    PRINT_LOCALE_CHAR(p_sign_posn);
    PRINT_LOCALE_CHAR(n_sign_posn);

    return 0;
}
#endif
