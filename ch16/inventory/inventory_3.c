#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
        int number;
        char name[NAME_LEN+1];
        int on_hand;    
    };

int find_part(int number, int num_parts, struct part inventory[]);
void insert(int *num_parts, int sorted_part_numbers[], struct part inventory[]);
void search(int num_parts, struct part inventory[]);
void update(int num_parts, struct part inventory[]);
void print(int sorted_part_numbers[], int num_parts, struct part inventory[]);
void sort_part_numbers(int num_parts, int sorted_part_numbers[], struct part inventory[]);



/************************************************************
 * main: Prompts the user to enter an operation code,       *
 *       then calls a function to perform the requested     *
 *       action. Repeats until the user enters the          *
 *       command 'q'. Prints an error message if the user   *
 *       enters an illegal code.                            *
 * *********************************************************/

int main(void) {
    struct part inventory[MAX_PARTS];

    int sorted_part_numbers[MAX_PARTS]; // an array to sort the index of inventory based on sorted part numbers.

    int num_parts = 0; 

    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert(&num_parts, &sorted_part_numbers[0], &inventory[0]);
                      break;
            case 's': search(num_parts, &inventory[0]);
                      break;
            case 'u': update(num_parts, &inventory[0]);
                      break;
            case 'p': print(&sorted_part_numbers[0], num_parts, &inventory[0]);
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
 int find_part(int number, int num_parts, struct part inventory[]) {
    int i;
    for (i=0; i < num_parts; i++) {
        if (inventory[i].number == number)
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
void insert(int *num_parts, int sorted_part_numbers[], struct part inventory[]) {
    int part_number;
    
    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    
    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number, *num_parts, inventory) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    sort_part_numbers(*num_parts, sorted_part_numbers, inventory);
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &(inventory[*num_parts].on_hand));
    (*num_parts)++;
}

/************************************************************
 * search: Prompts the user to enter a part number, then    *
 *         looks up the part in the database. If the part   *
 *         exists, prints the name and quantity on hand;    *
 *         if not, print an error message.                  *
 ************************************************************/
void search(int num_parts, struct part inventory[]) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
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
void update(int num_parts, struct part inventory[]) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
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
void print(int sorted_part_numbers[], int num_parts, struct part inventory[]) {
    int i, sorted_i;

    printf("Part Number     Part Name           "
           "Quantity on Hand\n");

    for (i = 0; i < num_parts; i++) {
        sorted_i = sorted_part_numbers[i];
        printf("%11d     %-20s%16d\n", inventory[sorted_i].number,
        inventory[sorted_i].name, inventory[sorted_i].on_hand);
    }
}

/************************************************************
 * sort_part_numbers: Insert new part number into a sorted  *
 *                    array in an accending order. This     *  
 *                    array will be used to print invenotry *
 *                    sorted by part numbers.               *
 ************************************************************/
void sort_part_numbers(int num_parts, int sorted_part_numbers[], struct part inventory[]) {
    int i, j, k;
    if (num_parts == 0){
        sorted_part_numbers[0] = 0;
        return;
    }

    for (i = 0; i < num_parts; i++) {
        if (inventory[num_parts].number > inventory[sorted_part_numbers[i]].number) {
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