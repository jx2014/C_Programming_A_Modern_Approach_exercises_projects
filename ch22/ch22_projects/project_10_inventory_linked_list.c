/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory2.c (Chapter 17, page 434) */
/* Maintains a parts database (linked list version) */
/* Project 3, Chapter 17, add option 'e' to erase a part */
/* Project 10, Chapter 22, add 'd' and 'r' to dump and restore database to external file*/

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
typedef enum {DUMP = 0, RESTORE = 1} op_t;

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;   /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);
void dump(void);
void restore(void);
void help(void);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
        case 'i': insert();
                    break;
        case 'e': erase();
                    break;
        case 's': search();
                    break;
        case 'u': update();
                    break;
        case 'p': print();
                    break;
        case 'd': dump();
                    break;
        case 'r': restore();
                    break;
        case 'h': help();
                    break;
        case 'q': return 0;

      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            list. Returns a pointer to the node         *
 *            containing the part number; if the part     *
 *            number is not found, returns NULL.          *
 **********************************************************/
struct part *find_part(int number)
{
  struct part *p;

  for (p = inventory;
       p != NULL && number > p->number;
       p = p->next)
    ;
  if (p != NULL && number == p->number)
    return p;
  return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       *
 *         returns prematurely if the part already exists *
 *         or space could not be allocated for the part.  *
 **********************************************************/
void insert(void)
{
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         If the part number exists,    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Part numbers will appear in   *
 *        ascending order.                                *
 **********************************************************/
void print(void)
{
  struct part *p;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d       %-25s%11d\n", p->number, p->name,
           p->on_hand);
}

/**********************************************************
 * erase: Prompt the user for a part number, if the part  *
 *        number exists, redirect the 'next' pointer      *
 *        from the previous part number, free the memory  *
 *        of the part number.                             *
 **********************************************************/
void erase(void) {
  int part_number;  
  struct part *temp, *p = inventory;

  if (p == NULL) {
    printf("Empty database, nothing to erase.\n");
    return;
  }

  printf("Enter a part number to erase: ");
  scanf("%d", &part_number);
  
  // first item in inventory needs to be erased.
  if (p->number == part_number) {
    temp = p;
    inventory = p->next;
  } else {
    for (; p->next != NULL && p->next->number != part_number; p = p->next)
      ;

    if (p->next == NULL) { // part_number does not exist in database
      printf("Part number does not exist.\n");
      return;
    }
    temp = p->next;
    p->next = temp->next;
  }
  free(temp);
  return;
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
void dump() {
    FILE *fp = get_file("Enter a file name to save the records: ", DUMP);
    int a = 0;
    struct part *temp;

    // saving smallest part number first.
    for (temp = inventory; temp != NULL; temp = temp->next) {
        a += fwrite(&temp->number,  sizeof(temp->number), 1, fp);
        a += fwrite(&temp->name,    sizeof(temp->name), 1, fp);
        a += fwrite(&temp->on_hand, sizeof(temp->on_hand), 1, fp);
    }

    fprintf(stdout, "Saved %d records\n", a / 3);
    fclose(fp);
}

/**************************************************************
 * restore: restore the inventory list from a file specified  *
 *          by the user. If the file does not exist, prompts  *
 *          the user to enter a new file.                     *
 *************************************************************/
void restore() {
    FILE *fp = get_file("Enter the file name to restore records: ", RESTORE);
    struct part *temp = NULL, *cur = NULL;
    int a;

    // free current inventory list:
    for (temp = inventory; temp != NULL; temp = inventory) {
        inventory = inventory->next;
        free(temp);
    }

    while(!feof(fp) && !ferror(fp)) {
        temp = malloc(sizeof(struct part));
        if (temp == NULL){
            fprintf(stderr, "Unable to allocate memory for additional records.\n");
            return;
        }
        temp->next = NULL;
        a = 0;
        a += fread(&temp->number,  sizeof(temp->number), 1, fp);
        a += fread(&temp->name,    sizeof(temp->name), 1, fp);
        a += fread(&temp->on_hand, sizeof(temp->on_hand), 1, fp);
        
        if (a == 3) {
            if (inventory == NULL) {
                inventory = temp;
                cur = temp;
            } else {
                cur->next = temp;
                cur = temp;
            }
        } else {
            break;
        }   
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