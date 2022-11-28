// Chapter 22 Project 8
// Modify Chapter 16 Project 4, inventory_4.c, by
// adding saving and loading database

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100
typedef enum {DUMP = 0, RESTORE = 1} op_t;

struct part {
        int number;
        char name[NAME_LEN+1];
        int on_hand;
        double price;
    };

int find_part(int number, int num_parts, struct part inventory[]);
void insert(int *num_parts, int8_t sorted_part_numbers[], struct part inventory[]);
void search(int num_parts, struct part inventory[]);
void update(int num_parts, struct part inventory[]);
void update_price(int num_parts, struct part inventory[]);
void print(int8_t sorted_part_numbers[], int num_parts, struct part inventory[]);
void sort_part_numbers(int num_parts, int8_t sorted_part_numbers[], struct part inventory[]);
void dump(int num_parts, struct part inventory[], int8_t sorted_part_list[]);
void restore(int *num_parts, struct part inventory[], int8_t sorted_part_list[]);
void help(void);

/************************************************************
 * main: Prompts the user to enter an operation code,       *
 *       then calls a function to perform the requested     *
 *       action. Repeats until the user enters the          *
 *       command 'q'. Prints an error message if the user   *
 *       enters an illegal code.                            *
 * *********************************************************/

int main(void) {
    struct part inventory[MAX_PARTS];

    int8_t sorted_part_numbers[MAX_PARTS]; // an array to sort the index of inventory based on sorted part numbers.
    // initialize the sorted_part_number array
    for (int i = 0; i < MAX_PARTS; i++)
        sorted_part_numbers[i] = -1;

    int num_parts = 0; 

    char code;
    for (;;) {
        printf("Enter operation code: "); 
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert(&num_parts, sorted_part_numbers, &inventory[0]);
                      break;
            case 's': search(num_parts, &inventory[0]);
                      break;
            case 'u': update(num_parts, &inventory[0]);
                      break;
            case 'P': update_price(num_parts, &inventory[0]);
                      break;
            case 'p': print(&sorted_part_numbers[0], num_parts, &inventory[0]);
                      break; 
            case 'd': dump(num_parts, inventory, sorted_part_numbers);
                      break;
            case 'r': restore(&num_parts, inventory, sorted_part_numbers);
                      break;
            case 'h': help();
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
void insert(int *num_parts, int8_t sorted_part_numbers[], struct part inventory[]) {
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
    printf("Enter price: ");
    scanf("%lf", &(inventory[*num_parts].price));
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
 * update: Prompts the user to enter a part number.         *
 *         Prints an error message if the part doesn't      *
 *         exists; otherwise, prompts the user to enter     *
 *         change in price and updates the dateabase.       *
 ************************************************************/
void update_price(int num_parts, struct part inventory[]) {
    int i, number;
    double change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Old price for this part: $%.2f\n", inventory[i].price);
        printf("Enter change in price: $");
        scanf("%lf", &change);
        inventory[i].price += change;
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
void print(int8_t sorted_part_numbers[], int num_parts, struct part inventory[]) {
    int i, sorted_i;

    printf("Part Number     Part Name           "
           "Quantity on Hand               Price\n");

    for (i = 0; i < num_parts; i++) {
        sorted_i = sorted_part_numbers[i];
        printf("%11d     %-20s%16d         $%10.2f\n", inventory[sorted_i].number,
        inventory[sorted_i].name, inventory[sorted_i].on_hand,
        inventory[sorted_i].price);
    }
}

/************************************************************
 * sort_part_numbers: Insert new part number into a sorted  *
 *                    array in an accending order. This     *  
 *                    array will be used to print invenotry *
 *                    sorted by part numbers.               *
 ************************************************************/
void sort_part_numbers(int num_parts, int8_t sorted_part_numbers[], struct part inventory[]) {
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

/***********************************************************
 * *get_file: a function to prompt the user to enter name  *
 *            of a file to dump or restore. Also check if  *
 *            the file exists, and prompt the user of      *
 *            overwrite and whatnot.                       * 
 /*********************************************************/
FILE *get_file(char *msg, op_t operation_type) {
    FILE *fp;        
    int i;
    char file_name[FILENAME_MAX];
    char c;

    while (1) {
        printf("%s", msg);    
        scanf(" %s", file_name);

        if ((fp = fopen(file_name, "rb")) == NULL) { // file does not exists
            if (operation_type == DUMP) {
                fclose(fp);
                fp = fopen(file_name, "wb");
                return fp;
            }
            fprintf(stderr, "File does not exist, enter another name to restore.\n"); 
        } else {                                    // file already exits
            if (operation_type == RESTORE)
                return fp;
            // for saving records, we need to know if it is OK to overwrite existing file
            fclose(fp);
            printf("File already exists. Overwrite [Y/n]? ");
            scanf(" %c", &c);

            if (c == 'Y' || c == 'y') {                
                fp = fopen(file_name, "wb");
                return fp;
            } else if (c == 'N' || c == 'n') {
                //while(getc(stdin) != '\n'); // skip rest of the line.
                continue;
            }
        }
    }
}

/***********************************************************
 * dump: save the inventory list to a datafile specified by*
 *       the user. If the file exists, prompt the user of  *
 *       overwrite, or enter a new name. The               *
 *       sorted_array_numbers array is stored before the   *
 *       inventory list, which is stored in order as the   *
 *       user enters them.                                 *
 /*********************************************************/ 
void dump(int num_parts, struct part inventory[], int8_t sorted_part_list[MAX_PARTS]) {
    FILE *fp = get_file("Enter a file name to save the records: ", DUMP);
    int a, b;

    if ( (a = fwrite(sorted_part_list, sizeof(int8_t), MAX_PARTS, fp)) == MAX_PARTS &&  \
         (b = fwrite(inventory, sizeof(struct part), num_parts, fp)) == num_parts)
        fprintf(stdout, "Data saved successfully.\n");
    else
        fprintf(stderr, "ERROR: records did not save properly.\n");
    fclose(fp);
}

/***********************************************************
 * dump: restore the sorted_array_list then restores the   *
 *       inventory list from a file specified by the user. *
 *       If the file does not exist, prompts the user to   *
 *       enter a new file.                                 *
 /*********************************************************/
void restore(int *num_parts, struct part inventory[], int8_t sorted_part_list[]) {
    FILE *fp = get_file("Enter the file name to restore records: ", RESTORE);
    *num_parts = 0;
    struct part temp_part;
    int8_t temp_part_list[MAX_PARTS];

    fread(temp_part_list, sizeof(int8_t), MAX_PARTS, fp);
    if (!feof(fp) & !(ferror(fp))) {
        for (int i = 0; i < MAX_PARTS; i++)
            sorted_part_list[i] = temp_part_list[i];
    } else
        return;

    while (1) {
        fread(&temp_part, sizeof(struct part), 1, fp );
        if (feof(fp) || ferror(fp)) 
            break;
        inventory[(*num_parts)++] = temp_part;
    }
}

void help(void) {
 
    fprintf(stdout, "'i' - insert\n"    \
                    "'s' - search\n"    \
                    "'u' - update\n"    \
                    "'p' - print \n"    \
                    "'d' - dump  \n"    \
                    "'r' - restore\n"   \
                    "'h' - help  \n"    \
                    "'q' - quit  \n");    
}