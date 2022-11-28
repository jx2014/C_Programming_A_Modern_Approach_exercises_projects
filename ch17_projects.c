#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define PROJECT (7)

#if (PROJECT == 1)
// See ch17\ch17_projects\project1\inventory.c
#endif

#if (PROJECT == 2)
// See ch17\ch17_projects\project1\inventory.c
#endif

#if (PROJECT == 3)
// See ch17\ch17_projects\project3\inventory2.c
#endif

#if (PROJECT == 4)
// See ch17\ch17_projects\project4\justify.c
#endif


/******************************************************************
* Ch17 Project 5: Prompt the users to enter a word of maximum of  *
*                 20 characters. Store each word in a dynamically *
*                 allocated string. Then sort the list and print  *
*                 it out in a sorted order.                       *
******************************************************************/
#if (PROJECT == 5)

void read_line(char* word);
void merge_sort(char **unsorted_array, size_t left, size_t right, int (*cmp)(const char *, const char *));

#define MAX_WORD_LEN (20)

int main(void) {
    char word[MAX_WORD_LEN+1];
    size_t num_words = 1, cur_words = 0;    
    char (**tmp);
    char (**word_list);

    // creating a list of pointers to words. 
    word_list = calloc(num_words, sizeof(char *));    
    // word_list = calloc(num_words, sizeof(char[MAX_WORD_LEN+1]));
    if (word_list == NULL) {
        printf("Failed to allocate memory for word_list.\n");
        return 1;
    }

    while (1) {         
        printf("[%2d] Enter word: ", cur_words);
        read_line(word);
        if (word[0] == '\0') {
            printf("Sort word list here.\n");
            // Project 5 uses merge_sort
            merge_sort(word_list, 0, cur_words-1, strcmp);
            break;
        }            
        
        // allocating memory for each word on the list
        (word_list[cur_words]) = malloc(strlen(word) * sizeof(char));
        if (word_list[cur_words] == NULL) break;        
        strcpy(word_list[cur_words], word);
        cur_words++;
        
        if (cur_words >= num_words) {
            num_words += 1;
            // allocating memory to include more pointers to the word
            tmp = realloc(word_list, num_words * sizeof(char *));
            if (*tmp == NULL) {
                printf("Failed to expand word list.\n");
            } else {
                word_list = tmp;
            }
        }
        
    }

    // print out the sorted word list:
    for (int i = 0; i < cur_words; i++) {
        printf("[%2d] %s\n", i, word_list[i]);
    }
    printf("\n");
    
    return 0;
}

void read_line(char* word) {
    char c;
    int i;
    for (i = 0, c = getchar(); i < MAX_WORD_LEN && c != '\n'; i++) {        
        word[i] = c;
        c = getchar();
    }
    word[i] = '\0';
}

void merge_sort(char **unsorted_array, size_t left, size_t right, int (*cmp)(const char *, const char *)) {
    // left and right are adjacent cells.
    // this is the atomic level merging. 
    char *temp;
    if ((left + 1) == right) {
        //if((unsorted_array[left] - unsorted_array[right]) < 0.0000001)
        if ((*cmp)(unsorted_array[left], unsorted_array[right]) < 0)
            return;
        else {             
            temp = unsorted_array[left];
            unsorted_array[left] = unsorted_array[right];
            unsorted_array[right] = temp;
            return;
        }
    } else if (left >= right) {
        // single element, nothing to do here
        return;
    }
    

    int mid = (left + right) / 2;

    merge_sort(unsorted_array, left, mid, (*cmp));
    merge_sort(unsorted_array, mid+1, right, (*cmp));
    // merge
    // always starting comparing mid+1 with left element
    // there will always be an extra element from left to mid than mid+1 to right.
    int i, k;
    // comparing right element one at a time with left element. 
    // i is the index of right element.
    for (i = mid + 1; i <= right; i++) {
        // increment the element from the left starting at index 'left'
        for (; left <= right; left++) {            
            //if ((unsorted_array[i] - unsorted_array[left]) < 0.0000001) {    
            if ((*cmp)(unsorted_array[i], unsorted_array[left]) < 0) {           
                temp = unsorted_array[i];
                // shifting all elements left side of index mid to the right.
                // starting at the element next to the right element. k = i - 1, then k = i - 2, k = i - 3, etc. 
                // until k reaches index left.
                for (k = i - 1; k >= left && k >= 0; k--) {
                    unsorted_array[k+1] = unsorted_array[k];
                }
                // putting the right element to the left side at index 'left'
                unsorted_array[left] = temp;
                break;
            }
        }
    }
}
#endif

/******************************************************************
* Ch17 Project 6: Just like Project 5, but uses qsort to sort     *
*                 the list of strings (words).                    *
******************************************************************/
#if (PROJECT == 6)
    
void read_line(char* word);
int strcpy2 (const void * a, const void * b);

#define MAX_WORD_LEN (20)

int main(void) {
    char word[MAX_WORD_LEN+1];
    size_t num_words = 1, cur_words = 0;    
    char (*tmp)[MAX_WORD_LEN+1];
    char (*word_list)[MAX_WORD_LEN+1];
    // word_list2 and tmp2 will work with quicksort. 
    char **word_list2, **tmp2;

    // creating a list of pointers to words. 
    // word_list = calloc(num_words, sizeof(char *));    
    word_list = calloc(num_words, sizeof(char[MAX_WORD_LEN+1]));
    word_list2 = calloc(num_words, sizeof(char *));
    if (word_list == NULL || word_list2 == NULL) {
        printf("Failed to allocate memory for word_list.\n");
        return 1;
    }

    while (1) {         
        printf("[%2d] Enter word: ", cur_words);
        read_line(word);
        if (word[0] == '\0') {
            printf("Sort word list here.\n");
            // Project 6 uses qsort
            char *values[] = {"zzzzzzzzzzzzz", "abcdefghijklmnoquridasdf", "cbcadsfadfsadfhlsahfdsafhsafjdsfsafsadfdsaf" };
            qsort(values, 3, sizeof(char *), strcpy2);

            // qsort can work with word_list2, but not the word_list.
            qsort(word_list2, cur_words, sizeof(char *), strcpy2);
            break;
        }            
        
        // allocating memory for each word on the list
        word_list2[cur_words] = malloc(sizeof(char) * (MAX_WORD_LEN+1));
        strcpy(word_list2[cur_words], word);
        strcpy(word_list[cur_words], word);
        cur_words++;
        
        if (cur_words >= num_words) {
            num_words += 1;
            // allocating memory to include more pointers of words with size of MAX_WORD_LEN
            // on the list.            
            tmp = realloc(word_list, num_words * sizeof(char[MAX_WORD_LEN+1]));
            tmp2 = realloc(word_list2, num_words * sizeof(char*));
            if (*tmp == NULL || tmp2 == NULL) {
                printf("Failed to expand word list.\n");
            } else {
                word_list = tmp;
                word_list2 = tmp2;
            }
        }
        
    }

    // print out the sorted word list:
    for (int i = 0; i < cur_words; i++) {
        printf("[%2d] %s\n", i, word_list2[i]);
    }
    printf("\n");
    
    return 0;
}

void read_line(char* word) {
    char c;
    int i;
    for (i = 0, c = getchar(); i < MAX_WORD_LEN && c != '\n'; i++) {        
        word[i] = c;
        c = getchar();
    }
    word[i] = '\0';
}

int strcpy2 (const void * a, const void * b) {
    const char *aa = *(const char **) a;
    const char *bb = *(const char **) b;
    return strcmp(aa, bb);
    // better, use return strcmp( *(const char **) a, *(const char **) b);
}

#endif

/******************************************************************
* Ch17 Project 7: Modify the remind2.c program of Section 17.2    *
*                 so that each element of the reminders array is  *
*                 a pointer to a vstring structure (ref: 17.9)    *
*                 rather than a pointer to an ordinary string.    *
******************************************************************/
#if (PROJECT == 7)

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind2.c (Chapter 17, page 418) */
/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */


struct vstring {
    int len;
    char chars[];
};

int read_line(char str[], int n);
void read_line2(struct vstring** vstr);

#define BUFFER_SIZE (10)

int main(void)
{
  char *reminders[MAX_REMIND];
  char day_str[3]; //, msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0;
  // assign memory to store the addrss of (struct vstring)
  struct vstring **vstr = malloc(sizeof(struct vstring*));
  if (vstr == NULL) return 1;

  for (;;) {
    // assign memory to store the content of vstring and # of characters
    // equal to the size of BUFFER_SIZE.
    *vstr = malloc(sizeof(struct vstring) + BUFFER_SIZE);
    if (*vstr == NULL) break;

    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    //read_line(msg_str, MSG_LEN);
    read_line2(vstr);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];

    //reminders[i] = malloc(2 + strlen(msg_str) + 1);
    reminders[i] = malloc(2 + ((*vstr)->len) + 1);
    if (reminders[i] == NULL) {
      printf("-- No space left --\n");
      break;
    }

    strcpy(reminders[i], day_str);
    strcat(reminders[i], (*vstr)->chars);
    free((*vstr));

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

void read_line2(struct vstring** vstr)
{
  int ch, i = 0;
  // create a temporary variable to store the same memroy as vstr.
  struct vstring **tmp = vstr; 
  int num_chars = 10;
  
  while ((ch = getchar()) != '\n') {
    if (i >= num_chars) {
        num_chars += BUFFER_SIZE;
        // increase the vstring size for temp variable to store more characters.
        *tmp = realloc(*vstr, sizeof(struct vstring) + num_chars);
        if (*tmp == NULL) {
            // get rid of the remainding of user input incase it fails to 
            // to read the rest of the strings.
            while ((ch = getchar()) != '\n');
            break;
        } else {
            // if memory allocation is a success, 
            // then assign vstr to this new memory location. 
            vstr = tmp;
        }
    }    
    *((*vstr)->chars + i++) = ch;
  }
  *((*vstr)->chars + i) = '\0';
  ((*vstr)->len) = i - 1;

}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}

#endif

/******************************************************************
* project 99: Project 99 is modified version of Project 5, where  *
*             project 5 specifics the max word length to be 20    *
*             and less; project 99 uses dynamically allocated     *
*             array to store strings of any length.               *
******************************************************************/
#if (PROJECT == 99)

void read_line_dynamic(char **word);
void merge_sort(char **unsorted_array, size_t left, size_t right, int (*cmp)(const char *, const char *));

#define MAX_WORD_LEN 20;

int main(void) {
    char *word;
    size_t num_words = 1, cur_words = 0;    
    char **word_list, **tmp;

    // creating a list of pointers to words. 
    word_list = calloc(num_words, sizeof(char *));
    if (word_list == NULL) {
        printf("Failed to allocate memory for word_list.\n");
        return 1;
    }

    while (1) {         
        printf("[%2d] Enter word: ", cur_words);
        //read_line(word);
        read_line_dynamic(&word);
        if (word[0] == '\0') {
            printf("Sort word list here.\n");
            // Project 5 uses merge_sort
            merge_sort(word_list, 0, cur_words-1, strcmp);
            // Project 6 uses qsort
            qsort(word_list, cur_words, sizeof(char *), strcmp);
            break;
        }            
        
        // allocating memory for each word on the list
        (word_list[cur_words]) = malloc(strlen(word) * sizeof(char));
        if (word_list[cur_words] == NULL) break;        
        strcpy(word_list[cur_words], word);
        cur_words++;
        
        if (cur_words >= num_words) {
            num_words += 1;
            // allocating memory to include more pointers of words
            // on the list.            
            tmp = realloc(word_list, num_words * sizeof(char *));
            if (tmp == NULL) {
                printf("Failed to expand word list.\n");
            } else {
                word_list = tmp;
            }
        }
        
    }

    // print out the sorted word list:
    for (int i = 0; i < cur_words; i++) {
        printf("[%2d] %s\n", i, word_list[i]);
    }
    printf("\n");
    
    return 0;
}

void read_line_dynamic(char **word) {
    char c, *temp_word;
    int i;
    temp_word = malloc(sizeof(char)); // allocate memory for one character
    *word = temp_word;
    for (i = 0, c = getchar(); c != '\n'; i++) {              
        temp_word[i] = c;
        *word = realloc(temp_word, i+2); // always need an extra character for '\0'
        if (*word == NULL) {
            return;
        }
        temp_word = *word;
        c = getchar();

    }
    temp_word[i] = '\0';
    *word = temp_word;
}

void merge_sort(char **unsorted_array, size_t left, size_t right, int (*cmp)(const char *, const char *)) {
    // left and right are adjacent cells.
    // this is the atomic level merging. 
    char *temp;
    if ((left + 1) == right) {
        //if((unsorted_array[left] - unsorted_array[right]) < 0.0000001)
        if ((*cmp)(unsorted_array[left], unsorted_array[right]) < 0)
            return;
        else {             
            temp = unsorted_array[left];
            unsorted_array[left] = unsorted_array[right];
            unsorted_array[right] = temp;
            return;
        }
    } else if (left >= right) {
        // single element, nothing to do here
        return;
    }
    
    int mid = (left + right) / 2;

    merge_sort(unsorted_array, left, mid, (*cmp));
    merge_sort(unsorted_array, mid+1, right, (*cmp));
    // merge
    // always starting comparing mid+1 with left element
    // there will always be an extra element from left to mid than mid+1 to right.
    int i, k;
    // comparing right element one at a time with left element. 
    // i is the index of right element.
    for (i = mid + 1; i <= right; i++) {
        // increment the element from the left starting at index 'left'
        for (; left <= right; left++) {            
            //if ((unsorted_array[i] - unsorted_array[left]) < 0.0000001) {    
            if ((*cmp)(unsorted_array[i], unsorted_array[left]) < 0) {           
                temp = unsorted_array[i];
                // shifting all elements left side of index mid to the right.
                // starting at the element next to the right element. k = i - 1, then k = i - 2, k = i - 3, etc. 
                // until k reaches index left.
                for (k = i - 1; k >= left && k >= 0; k--) {
                    unsorted_array[k+1] = unsorted_array[k];
                }
                // putting the right element to the left side at index 'left'
                unsorted_array[left] = temp;
                break;
            }
        }
    }
}

#endif
