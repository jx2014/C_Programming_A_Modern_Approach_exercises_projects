#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define PROJECT (18)

int read_line(char str[], int n);

#if (PROJECT == 1)
int main(void) {
    // Find largest and smallest words entered by user
    // program will stop if user enters a four letter words

    char smallest[100], largest[100];
    char temp[100];
    smallest[0] = largest[0] = '\0';

    while (strlen(temp) != 4) {
        printf("Enter word: ");                
        scanf("%100s", temp);
        // initialize string
        if (smallest[0] == '\0')
            strcpy(smallest, temp);        
        if (strcmp(temp, largest) > 0) {
            strcpy(largest, temp);            
        } else if (strcmp(temp, smallest) < 0) {
            strcpy(smallest, temp);
        }

    }

    printf("\nSmallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}

// book answer
#define WORD_LEN 20

void read_line(char str[], int n);

int main(void)
{
  char smallest_word[WORD_LEN+1],
       largest_word[WORD_LEN+1],
       current_word[WORD_LEN+1];

  printf("Enter word: ");
  read_line(current_word, WORD_LEN);
  strcpy(smallest_word, strcpy(largest_word, current_word));

  while (strlen(current_word) != 4) {
    printf("Enter word: ");
    read_line(current_word, WORD_LEN);
    if (strcmp(current_word, smallest_word) < 0)
      strcpy(smallest_word, current_word);
    if (strcmp(current_word, largest_word) > 0)
      strcpy(largest_word, current_word);
  }

  printf("\nSmallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);

  return 0;
}

void read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
}

#endif

#if (PROJECT == 2)
int main(void) {
    // improving remind.c by
    // a) Print an error msg and ignore a reminder if the corresponding date is
    //    negative or larger than 31.
    // b) Allow the user to enter a day, a 24-hour time, and a reminder. The 
    //    printed reminder list is sorted by day, then by time.
    // c) Print a one-year reminder list. Require the user to enter days in the
    //    the form month/day.

    #define MAX_REMIND 50 /* maximum number of reminders */
    #define MSG_LEN 60 /* max length of reminder message */

    int read_line(char str[], int n) {
        int ch, i = 0;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (i < n) {
                str[i++] = ch;
            }
        }
        str[i] = '\0';
        
        return i;
    }

    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[12], msg_str[MSG_LEN+1];
    int mon, day, hour, i, j, num_remind = 0;

    for (;;) {        

        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter date time (mm/dd HH) and reminder: ");
        scanf("%2d/%2d %2d", &mon, &day, &hour);
        if (day == 0 || mon == 0 )
            break;
        if (mon > 12 || mon < 1) {
            printf("Month must be a number between 1 and 12\n");
            while (getchar() != '\n');
            continue;
        }
        if (hour > 23 || hour < 0) {
            printf("Hour must be a number between 0 and 23\n");
            while (getchar() != '\n');
            continue;
        }
        switch (mon) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (day > 31 || day < 1) {
                    printf("Day must be a number between 1 and 31 for selected month.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            case 2:
                if (day > 28 || day < 1) {   
                    printf("Day must be a number between 1 and 28 for Feburary.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;   
            case 4: case 6: case 9: case 11:
                if (day > 30 || day < 1) {
                    printf("Day must be a number between 1 and 30 for selected month.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;            
        }
        
        
        sprintf(day_str, "%02d  %02d   %02d", mon, day, hour);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);
        
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMon Day Hour Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}
#endif

#if (PROJECT == 3)

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    // rewrite 8.2 deal.c
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *rank_code[] = {"2", "3", "4", "5", "6", "7", "8",
                              "9", "10", "Jack", "Queen", "King", "Ace"};
    const char *suit_code[] = {"Club", "Diamond", "Heart", "Spade"};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:\n\n");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS; // picks a random suit
        rank = rand() % NUM_RANKS; // picks a random rank
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%5s of %-8s\n", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}

#endif

#if (PROJECT == 4)
int main(void) {
    // see reverse.c

    return 0;
}
#endif

#if (PROJECT == 5)
int main(void) {
    // see sum.c


    return 0;
}
#endif

#if (PROJECT == 6)
int main(void) {
    // see planet.c

    return 0;
}
#endif

#if (PROJECT == 7)
int main(void) {
    int x = 0, y = 0;

    char *single_digit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *ten_to_nineteen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *twenty_to_ninety[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        
    printf("Enter a two-digit number: ");
    scanf("%2d", &x);

    printf("You entered the number ");

    if ( x <= 9) {
        printf("%s.\n", *(single_digit + x));
    } else if (x <= 20) {
        printf("%s.\n", *(ten_to_nineteen + x % 10));
    } else if (x % 10 == 0){
        printf("%s.\n", *(twenty_to_ninety + x / 10));
    } else {
        printf("%s-%s.\n", twenty_to_ninety[x / 10], *(single_digit + x % 10));
    }

    return 0;
}
#endif

#if (PROJECT == 8)
int main(void) {
    // Original project 5 from chapter 7
    // 
    char word[100] = {};
    printf("Enter a word: ");
    scanf("%s", word);

    int compute_scrabble_value(const char *word) {
        int score = 0;
        
        for (; *word; word++) {
            switch(toupper(*word)) {        
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
        return score;
    }

    printf("Scrabble value: %d\n", compute_scrabble_value(word));
    return 0;
}
#endif

#if (PROJECT == 9)
int main(void) {
    // Original project 10 from chapter 7
    // count number of vowels in a sentence
    int compute_vowel_count(const char *sentence) {
        int n = 0;
        for (; *sentence; sentence++) {            
            switch(toupper(*sentence)) {
                case 'A': case 'E': case 'I': case 'O': case 'U':
                n++;
            }
         }
        return n;
    }

    char s[1000] = {};
    int n = 0;
    printf("Enter a sentence: ");
    read_line(s, 1000);    
    printf("Your sentence contains %d vowel(s).\n", compute_vowel_count(s));

    return 0;
}
#endif

#if (PROJECT == 10)
int main(void) {
    // Original project 11 from chapter 7
    // Display Last name, First initial.
    
    void reverse_name(char *name) {
        char c[101];
        char *p, f[3] = {0, '.', 0};
                
        // get first initial by removing white spaces from the beginning.
        for (p = name; *p && *p == ' '; p++);
        
        f[0] = toupper(*p); // f now points to the first initial;

        while (*p != '\0' && *p != ' ') p++; // loop through the remainder of first name till a white space.

        strcpy(name, ++p);
        strcat(name, ", ");
        strcat(name, f);
    }   

    char name[100] = {};

    printf("Enter a first name and last name: ");
    read_line(name, 101);
    reverse_name(name);
    printf("%s\n", name);
 

    return 0;
}
#endif

#if (PROJECT == 11)
int main(void) {
    // Original project 13 from chapter 7
    // calculate average word length
    double compute_average_word_length(const char *word) {
        int nWord = 0, nLetter = 0;
        bool isEndofWord = true;

        while(*word) {
            if (toupper(*word) >= 'A' && toupper(*word) <= 'Z') {
                nLetter++;
                if (isEndofWord)
                    isEndofWord = false;
            }
            else if (*word == ' ' && !isEndofWord) {
                nWord++;
                isEndofWord = true;
            }
            word++;
        }
        nWord++;
        return (double) nLetter / nWord;
    }
    
    double l;
    char sentence[1000];
    printf("Enter a sentence: ");
    read_line(sentence, 1001);
    l = compute_average_word_length(sentence);
   
    printf("Average word size is %.2f\n", l);

    return 0;
}
#endif

#if (PROJECT == 12)
int main(void) {
    // Original project 14 from chapter 8; and project 5 from chapter 12
    /* reverse words in a sentence */
    /* e.g., you can cage a swallow can't you? --> you can't swallow a cage can you?*/
    
    #define SENTENCE_LEN (30)
    #define WORD_LEN (20)

    char sentence[SENTENCE_LEN][WORD_LEN] = {0}; 
    int word = 1, whitespace = 0, letter = 0;
    char c;
    printf("Enter a sentence: ");
    while((c = getchar()) != '\n') {
        if (c == '.' || c == '!' || c == '?') {
            sentence[0][0] = c;
            break;            
        } else if (c == ' ') {
            word++;
            letter = 0;
        } else {
            sentence[word][letter] = c;   
            letter++;
        }            
    }
    printf("Reversal of the sentence: ");
    for (;word > 0; word--) {
        for (int i = 0; ;i++) {
            c = sentence[word][i];
            if ( c == 0 ) break;
            putchar(c);
        }
        putchar(' ');
    }
    printf("\b%c", sentence[word][0]);


    return 0;
}
#endif

#if (PROJECT == 13)
int main(void) {
    // Original project 15 from chapter 8
    /* Caesar's cipher: shifting the position of a letter by a fixed value */
    void encript(char *msg, int shift) {
        // shift characters        
        for (; *msg; msg++) {                        
            if (*msg >= 'a' && *msg <= 'z') *msg = (*msg - 'a' + shift) % 26 + 'a';
            if (*msg >= 'A' && *msg <= 'Z') *msg = (*msg - 'A' + shift) % 26 + 'A';
        }
    }
    
    #define MESSAGE_SIZE (80)
    char message[MESSAGE_SIZE + 1] = {0};
    int shift = 0;

    printf("Enter a message: ");
    read_line(message, MESSAGE_SIZE + 1);

    do {
        printf("Enter shift amount[1 - 25]: ");
        scanf("%d", &shift);
    } while (shift > 25 || shift < 1);
    
    encript(message, shift);
    printf("The encrypted message: %s\n", message);

    return 0;
}
#endif

#if (PROJECT == 14)
int main(void) {
    // Original project 16 from chapter 8
    /* anagram tester (test if two words share the exact same letters) */
    bool are_anagram(const char *word1, const char *word2) {
        const char *p;
        int letter[26] = {0};
        int i = 0;

        for (p = word1; *p; p++) {            
            letter[tolower(*p) - 'a']++;
        }

        for (p = word2; *p; p++) {            
            letter[tolower(*p) - 'a']--;
        }   

        for (i = 0; i < 26; i++) {
            if (letter[i] != 0) {
                return false;
            } 
        }

        return true;
    }
    char k[5] = {};
    char word1[100], word2[100];

    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2); 
    strcpy(k, are_anagram(word1, word2) ? " " : " not ");
    printf("The two words are%sanagrams.\n", k);

    return 0;
}
#endif

#if (PROJECT == 15)
int main(void) {
    // Original project 6 from chapter 10
    // see ch13_project15_RPN.c


    return 0;
}
#endif

#if (PROJECT == 16)
int main(void) {
    // Original Project 1 from chapter 12
    // Reverse of a input string
    void reverse(char *msg) {
        char *p, *q, temp;
        // setting p to the last valid character of msg
        for (p = msg; *p; p++) {
            ;
        }
        p--;
        // reverse the string
        for (q = msg; p > q; p--, q++) {
            temp = *q;            
            *q = *p;
            *p = temp;
        }

    }

    #define N 10 
    char sentence[N] = {0};
    int letter = 0;
    char c;
    
    // using pointer arithmetic
    char *p;
    p = &sentence[0];
    printf("\nEnter a sentence: ");
    read_line(sentence, N);
    reverse(sentence);
    printf("Reversal of the sentence: %s\n", sentence);



    return 0;
}
#endif

#if (PROJECT == 17)
int main(void) {
    // Original project 2 from chapter 12
    // determien if the sentence is palindrome (the letters are the same from left to right)
    // "He lived as a devil, eh?" is Palidrome.
    bool is_palindrome(const char *msg) {
        const char *p, *q;
                
        // setting q to the end of msg
        for (q = msg; *q; q++);

        // checking if sentence is palindrome.
        for (p = msg, q--; q > p; p++, q--) {
            // skipping all non-letter characters
            while ( !((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) && *q)
                q--;
            while ( !((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && *p)
                p++;            

            if (toupper(*q) != toupper(*p)) {
                return false;                
            }
        }
        return true;
    }
    
    #define N (100) 
    char sentence[N] = {0};
    bool palindrome = true;

    printf("Enter a sentence: ");
    read_line(sentence, N);


    if (is_palindrome(sentence)) {
        printf("Palindrome.\n");  
    } else {
        printf("Not a palindrome.\n");
    }


    return 0;
}
#endif

#if (PROJECT == 18)
int main(void) {
    // Date parser
    // input 2/17/2011 will return February 17, 2011

    int m, d, y;
    char *month[] = {"", "Janurary", "February", "March", "April", "May", "June", 
                   "July", "Auguest", "September", "October", "November", "December"};

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &m, &d, &y);
    printf("You entered date %s %d, %d.\n", *(month + m), d, y);
    
    return 0;
}
#endif

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';  // string termination
    return i;       // number of characters stored.
}

