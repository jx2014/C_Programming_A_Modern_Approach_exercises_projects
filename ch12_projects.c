#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
//#include <stdlib.h>
//#include <time.h>
//#include <ctype.h>

#define PROJECT (1)

int main(void) {
    #if (PROJECT == 1)
        // Reverse of a input string       
        #define N 10 
        char sentence[N] = {0};
        int letter = 0;
        char c;
        printf("Enter a sentence: ");
        while(((c = getchar()) != '\n') && (letter < N)) {
            sentence[letter] = c;   
            letter++;                        
        }
        // clear the rest of the input until newline 
        if (c != '\n') {
            while (getchar() != '\n');
        }
        printf("Reversal of the sentence: ");
        letter = (letter >= N ? N - 1 : letter);
        for (;letter >= 0; letter--) {
            putchar(sentence[letter]);
        }
        printf("\n");

        // using pointer arithmetic
        char *p;
        p = &sentence[0];
        printf("\nEnter a sentence: ");
        while(((c = getchar()) != '\n') && (p < &sentence[N])) {
            *p = c;   
            p++;                        
        }
        // clear the rest of the input until newline
        if (c != '\n') {
            while (getchar() != '\n');
        }
        
        printf("Reversal of the sentence: ");
        for (; p > &sentence[0];) {
            p--;
            putchar(*p);
        }
        printf("\n");

        // Book answer:
        /*
        #define MSG_LEN 80     // maximum length of message

        char msg[MSG_LEN];
        int i;

        printf("Enter a message: ");
        for (i = 0; i < MSG_LEN; i++) {
            msg[i] = getchar();
            if (msg[i] == '\n')
            break;
        }

        printf("Reversal is: ");
        for (i--; i >= 0; i--)
            putchar(msg[i]);
        putchar('\n');

        char *p;

        printf("Enter a message: ");
        for (p = &msg[0]; p < &msg[MSG_LEN]; p++) {
            *p = getchar();
            if (*p == '\n')
            break;
        }

        printf("Reversal is: ");
        for (p--; p >= &msg[0]; p--)
            putchar(*p);
        putchar('\n');
        */
            
    #endif

    #if (PROJECT == 2)
        // determien if the sentence is palindrome (the letters are the same from left to right)
        // "He lived as a devil, eh?" is Palidrome.
        
        #define N (100) 
        char sentence[N] = {0};
        bool palindrome = true;
        /*                
        char c;
        int letter = 0, i = 0;
        printf("Enter a sentence: ");
        while(((c = getchar()) != '\n') && (i < N)) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                sentence[letter] = toupper(c);
                letter++;
            }
            i++;
        }
        // clear the rest of the input until newline        
        if (c != '\n') {
            while (getchar() != '\n');
        }
        // checking if sentence is palindrome.
        for (i = 0, letter--; i < letter; i++, letter--) {
            if (sentence[i] != sentence[letter]) {                
                palindrome = false;
                break;     
            }
        }

        */
        // ############### With Pointer Arithmetic #####################
        char *p, *q;
        printf("Enter a sentence: ");
        q = &sentence[0];
        p = q;
        while(((*q = getchar()) != '\n') && (q < &sentence[0] + N)) {
            if ((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) {
                *p = toupper(*q);
                p++;
            }
            q++;
        }
        // clear the rest of the input until newline        
        if (*q != '\n') {
            while (getchar() != '\n');
        }
        // checking if sentence is palindrome.
        for (q = &sentence[0], p--; q < p; q++, p--) {
            if (*q != *p) {
                palindrome = false;
                break;
            }
        }

        if (palindrome) {
            printf("Palindrome.\n");  
        } else {
            printf("Not a palindrome.\n");
        }
    #endif

    #if (PROJECT == 3)        
        #define MSG_LEN 100
        char msg[MSG_LEN];
        char *p;
        // original book answer 
        /*
        printf("Enter a message: ");
        for (p = &msg[0]; p < &msg[MSG_LEN]; p++) {
            *p = getchar();
            if (*p == '\n')
            break;
        }

        printf("Reversal is: ");
        for (p--; p >= &msg[0]; p--)
            putchar(*p);
        putchar('\n');
        */

        // simplified with the fact that array name can be used as a pointer
        printf("Enter a message: ");
        for (p = msg; p < msg + MSG_LEN; p++) {
            *p = getchar();
            if (*p == '\n')
            break;
        }

        printf("Reversal is: ");
        for (p--; p >= msg; p--)
            putchar(*p);
        putchar('\n');
    #endif

    #if (PROJECT == 4)
        // simplify 2(b) by taking the fact that an array name can be used as a pointer.
        #define N (100) 
        char sentence[N] = {0};
        bool palindrome = true;
        char *p, *q;
        printf("Enter a sentence: ");
        q = sentence;
        p = q;
        while(((*q = getchar()) != '\n') && (q < sentence + N)) {
            if ((*q >= 'A' && *q <= 'Z') || (*q >= 'a' && *q <= 'z')) {
                *p = toupper(*q);
                p++;
            }
            q++;
        }
        // clear the rest of the input until newline        
        if (*q != '\n') {
            while (getchar() != '\n');
        }
        // checking if sentence is palindrome.
        for (q = sentence, p--; q < p; q++, p--) {
            if (*q != *p) {
                palindrome = false;
                break;
            }
        }

        if (palindrome) {
            printf("Palindrome.\n");  
        } else {
            printf("Not a palindrome.\n");
        }
    #endif

    #if (PROJECT == 5)
        // Chapter 8, Project 14 with pointer arithmetic
        // reverse words in a sentence.
        // e.g., you can cage a swallow can't you? --> you can't swallow a cage can you?
        #define WORDS (1000)
        #define LETTERS (100)
        char sentence[WORDS][LETTERS] = {0}, (*p)[LETTERS], *q; // assuming a sentence has maximum 1000 words, with maximum 100 letters in each word        
        char c;
        printf("Enter a sentence: ");
        
        for (p = sentence; p < sentence + WORDS; p++) {
            for (q = p[0]; q < p[0] + LETTERS; q++) {
                *q = getchar();
                if (*q == '.' || *q == '!' || *q == '?') {
                    c = *q;
                    *q = '\n'; // end of sentence 
                    break;
                } else if (*q == ' ') {                    
                    break;
                }
            }
            if (*q == '\n') {
                *q = ' ';
                break;
            }

        }

        printf("Reversal of the sentence: ");
        for (;p >= sentence; p--) {
            for (q = p[0]; q < p[0] + LETTERS; q++) {
                putchar(*q);
                if (*q == ' ') {
                    break;
                }
            }

        }

        
        printf("\b%c", c);

    #endif

    #if (PROJECT ==6)
        // qsort.c from Section 9.6 using pointer arithmetic
        #define SIZE (7)

        void  QuickSort(int input_array[], int* low, int* high) {
            int temp;            
            bool fill_left_hole = true;
            int *original_high = high;    

            temp = *low;

            if (low >= high) return;

            while (low < high) {        
                if (fill_left_hole) {
                    if (*high < temp) {
                        *low = *high;
                        fill_left_hole = false;
                        low++;
                    } else {
                        high--;
                    }
                } else {
                    if (*low > temp) {
                        *high = *low;
                        fill_left_hole = true;
                        high--;
                    } else {
                        low++;
                    }
                }

            }
            *low = temp;
            QuickSort(input_array, input_array, low - 1);
            QuickSort(input_array, low + 1, original_high);
        }

        int a[SIZE] = {12, 3, 6, 18, 7, 15, 10};
    
        printf("Enter %d numbers: ", SIZE);    
        for (int i = 0; i < SIZE; i++) scanf("%d", &a[i]);    
        QuickSort(a, a, a + SIZE - 1);
        printf("\nIn sorted order: ");
        for (int i = 0; i < SIZE; i++) printf("%d ", a[i]);
        printf("\n");

    #endif

    #if (PROJECT == 7)
        // maxmin.c from Section 11.4 using pointer arithmetic

        #define ARRAY_SIZE (10)

        int num_array[ARRAY_SIZE];
        int array_size = ARRAY_SIZE;
        int big = 0, small = 0;

        void max_min(int a[], int n, int *pmax, int *pmin) {
            *pmin = a[0];
            *pmax = a[0];
            int *p; 
            
            for (p = a; p < a + n; p++) {
                if (*pmax < *p) {
                    *pmax = *p;
                } else if (*pmin > *p) {
                    *pmin = *p;
                }
            }
        }

        printf("Enter %d numbers: ", ARRAY_SIZE);
        int *i;
        for (i = num_array; i < num_array + ARRAY_SIZE; i++) {
            scanf(" %d", i);
        }
        max_min(num_array, i - num_array, &big, &small);
        printf("Largest: %d\n", big);
        printf("Smallest: %d\n", small);





    #endif


    return 0;
}