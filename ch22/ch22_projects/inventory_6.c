// inventory_6.c.
// Needed for Chapter 22 Project 9
// the inventory program is modified specifically for project 9.
// the new inventory_6.c saves sorted inventory list to file, 
// eliminating the sorted_part_numbers[].


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
void insert(int *num_parts, struct part inventory[]);
void search(int num_parts, struct part inventory[]);
void update(int num_parts, struct part inventory[]);
void update_price(int num_parts, struct part inventory[]);
void print(int num_parts, struct part inventory[]);
void dump(int num_parts, struct part inventory[]);
void restore(int *num_parts, struct part inventory[]);
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
    int num_parts = 0; 

    char code;
    for (;;) {
        printf("Enter operation code: "); 
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert(&num_parts, &inventory[0]);
                      break;
            case 's': search(num_parts, &inventory[0]);
                      break;
            case 'u': update(num_parts, &inventory[0]);
                      break;
            case 'P': update_price(num_parts, &inventory[0]);
                      break;
            case 'p': print(num_parts, &inventory[0]);
                      break; 
            case 'd': dump(num_parts, inventory);
                      break;
            case 'r': restore(&num_parts, inventory);
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
 *         For project 9:                                   *
 *         The inventory is inserted in ascending order.    *
 ************************************************************/
void insert(int *num_parts, struct part inventory[]) {
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

    // Finding location to insert new part in ascending order
    int i, j;
    for (i = 0; i < *num_parts; i++) {
        if (inventory[i].number <= part_number) {
            ;
        } else {
            // need to insert new part number here
            // move everything in inventory list down, starting from the last part on the list.
            for (j = *num_parts; j > i; j--) {
                //sorted_part_numbers[j] = sorted_part_numbers[j-1];
                inventory[j] = inventory[j-1];
            }
            break;
        }
    }

    inventory[i].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[i].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &(inventory[i].on_hand));
    printf("Enter price: ");
    scanf("%lf", &(inventory[i].price));
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
void print(int num_parts, struct part inventory[]) {
    int i, sorted_i;

    printf("Part Number     Part Name           "
           "Quantity on Hand               Price\n");

    for (i = 0; i < num_parts; i++) {
        printf("%11d     %-20s%16d         $%10.2f\n",      \
        inventory[i].number,                                \
        inventory[i].name,                                  \
        inventory[i].on_hand,                               \
        inventory[i].price);
    }
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
 *       overwrite, or enter a new name. The inventory     *
 *       list is stored in ascending order.                *
 /*********************************************************/
void dump(int num_parts, struct part inventory[]) {
    FILE *fp = get_file("Enter a file name to save the records: ", DUMP);
    int a;

    if ((a = fwrite(inventory, sizeof(struct part), num_parts, fp)) == num_parts)
        fprintf(stdout, "Data saved successfully.\n");
    else
        fprintf(stderr, "ERROR: records did not save properly.\n");
    fclose(fp);
}

/**************************************************************
 * restore: restore the inventory list from a file specified  *
 *          by the user. If the file does not exist, prompts  *
 *          the user to enter a new file.                     *
 *************************************************************/
void restore(int *num_parts, struct part inventory[]) {
    FILE *fp = get_file("Enter the file name to restore records: ", RESTORE);
    *num_parts = 0;
    struct part temp_part;

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