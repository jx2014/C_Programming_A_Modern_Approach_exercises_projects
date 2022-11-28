#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 10

int read_line(char str[], int n);

struct part {
    unsigned int number;
    char name[NAME_LEN+1];
    int on_hand;    
} inventory[MAX_PARTS];

struct part *inventory2;

int sorted_part_numbers[MAX_PARTS]; // an array to sort the index of inventory based on sorted part numbers.

unsigned int max_parts = 2;
unsigned int num_parts = 0;  /* number of parts currently stored */

int find_part(unsigned int number);
void insert(void);
void search(void);
void update(void);
void print(struct part *inventory_list);
void sort_part_numbers(void);
void qsort_part_numbers1(void);
void qsort_part_numbers2(void);
int compare_parts1(const void *p, const void *q);
int compare_parts2(const void *p, const void *q);

/************************************************************
 * main: Prompts the user to enter an operation code,       *
 *       then calls a function to perform the requested     *
 *       action. Repeats until the user enters the          *
 *       command 'q'. Prints an error message if the user   *
 *       enters an illegal code.                            *
 * *********************************************************/

int main(void) {
    char code;

    inventory2 = malloc(max_parts * sizeof(struct part));

    if (inventory2 == NULL) {
        printf("Unable to allocate memory for inventory2.\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print(inventory2);
                      break;
            case 'a': qsort_part_numbers1(); // sort inventory in ascending order
                      break;
            case 'b': qsort_part_numbers2(); // sort inventory in descending order
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }

}

/************************************************************
 * find_part: Looks up a part number in the inventory array.*
 *            Returns the array index if the number is      *
 *            found; otherwise, return -i.                  *
 ************************************************************/
 int find_part(unsigned int number) {
    int i;
    for (i=0; i < num_parts; i++) {
        if ((inventory2+i)->number == number)
            return i;
    }
    return -1;
 }

/************************************************************
 * insert: Prompts the user for information about a new     *
 *         part and then inserts the part into the          *
 *         database. Prints an error message and returns    *
 *         prematurely if the part already exists or the    *
 *         database is full.                                *
 ************************************************************/
void insert(void) {
    long int part_number_unfiltered;
    unsigned int part_number; 
    
    if (num_parts == max_parts) { // need to allocate more memroy
        //printf("Database is full; can't add more parts.\n");
        max_parts *= 2;
        struct part *temp = realloc(inventory2, max_parts * sizeof(struct part));
        if (temp == NULL) {
            printf("Can't add any more parts due to insufficient memory.\n");
            return;
        }       
        inventory2 = temp; 
    }
    
    printf("Enter part number: ");
    scanf(" %ld", &part_number_unfiltered);

    if (part_number_unfiltered < 0) {
        printf("Part number can only be positive integers.\n");
        return;
    }
    part_number = (unsigned int) part_number_unfiltered;   

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory2[num_parts].number = part_number; // this works for malloc pointer as well.
    //(inventory2+num_parts)->number = part_number;
    printf("Enter part name: ");
    read_line((inventory2+num_parts)->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &((inventory2+num_parts)->on_hand));
    num_parts++;
}

/************************************************************
 * search: Prompts the user to enter a part number, then    *
 *         looks up the part in the database. If the part   *
 *         exists, prints the name and quantity on hand;    *
 *         if not, print an error message.                  *
 ************************************************************/
void search(void) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", (inventory2+i)->name);
        printf("Quantity on hand: %d\n", (inventory2+i)->on_hand);
    } else {
        printf("Part not found.\n");
    }
}

/************************************************************
 * update: Prompts the user to enter a part number.         *
 *         Prints an error message if the part doesn't      *
 *         exists; otherwise, prompts the user to enter     *
 *         change in quantity on hand and updates the       *
 *         database.                                        *
 ************************************************************/
void update(void) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        (inventory2+i)->on_hand += change;
    }   else {
        printf("Part no found.\n");
    }
}

/************************************************************
 * print: Prints a listing of all parts in the database,    *
 *        showing the part number, part name, and           *
 *        quantity on hand. Parts are printed in the        *
 *        order in which they were entered into the         *
 *        database.                                         *
 ************************************************************/
void print(struct part *inventory_list) {
    int i;

    printf("Part Number     Part Name           "
           "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        printf("%11d     %-20s%16d\n", (inventory2+i)->number,
        (inventory2+i)->name, (inventory2+i)->on_hand);
    }
}

/************************************************************
 * sort_part_numbers: Insert new part number into a sorted  *
 *                    array in an accending order. This     *  
 *                    array will be used to print invenotry *
 *                    sorted by part numbers.               *
 ************************************************************/
void sort_part_numbers(void) {
    int i, j, k;
    if (num_parts == 0){
        sorted_part_numbers[0] == 0;
        return;
    }

    for (i = 0; i < num_parts; i++) {
        //if (inventory[num_parts].number > inventory[sorted_part_numbers[i]].number) {
        if ((inventory+num_parts)->number > inventory[sorted_part_numbers[i]].number) {
            ;
        } else {
             for (j = num_parts; j > i; j--) {
                sorted_part_numbers[j] = sorted_part_numbers[j-1];
            }
            break;
        }
    }
    sorted_part_numbers[i] = num_parts;
}

// ch17 exercise 18, compare_parts
// sorting inventory in ascending order.
int compare_parts1(const void *p, const void *q) {
    const struct part *a = p;
    const struct part *b = q;
    return (a->number - b->number); // hopefully number are all positive.
}

// sorting inventory in descending order.
int compare_parts2(const void *p, const void *q) {
    const struct part *a = p;
    const struct part *b = q;
    return (b->number - a->number); // hopefully number are all positive.
}

// This function is to validate ch17 exercise 18, 
// compare_parts, sorting inventory in ascending order.
void qsort_part_numbers1(void) {
    qsort(inventory2, num_parts, sizeof(struct part), compare_parts1);
}

// compare_parts, sorting inventory in descending order.
void qsort_part_numbers2(void) {
    qsort(inventory2, num_parts, sizeof(struct part), compare_parts2);
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}