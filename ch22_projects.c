#define PROJECT (19)

#if (PROJECT == 1)
// Expand canopen.c in Section 22.2 so that the user may put any number of file
// names on the command line:
// canopen foo bar baz

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int i = 1;

    if (argc < 2) {
        printf("usage: canopen filename1, filename2, filename3, ... filenameN\n");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("\"%10.10s\" can't be opened\n", argv[i]);
            continue;
        }

        printf("\"%10.10s\" can be opened\n", argv[i]);
        fclose(fp);
    }

    return 0;
}
#endif

#if (PROJECT == 2)
// This program converts all letters in a file to upper case. (Characters other than letters will not 
// be changed.) The program should obtain the file name from the command line and write its output to 
// stdout.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: convert.exe input_file.txt\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Unable to open \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int c;

    while ((c = getc(fp)) != EOF) {
        if (putc(toupper(c), stdout) == EOF)
            break;
    }
    fclose(fp);

    return 0;
}
#endif

#if (PROJECT == 3)
// This program concatenates any number of files by writting them to standard output,
// one after the other, with no break between files. For example, the following 
// command will display the files f1.c, f2.c, and f3.c on the screen:
// fcat.exe f1.c f2.c f3.c
// fcat.exe will issue an error message if any file can't be opened. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[256];

    if (argc < 2) {
        printf("Usage: fcat.exe f1.c f2.c f3.c ... fN.c\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) != NULL) {
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                fputs(buffer, stdout);
                memset(buffer, 0, sizeof(buffer));
            }
            printf("\n");
        } else {
            // unable to open file
            fprintf(stdout, "Unable to open file: %s\n", argv[i]);
        }
    }
    return 0;
}
#endif

#if (PROJECT == 4)
// (a) counts the number of characters in a text file.
// (b) counts the number of words in a text file. (A "word" is any sequence of non-white-space
//     characters.)
// (c) counts the number of lines in a text file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch, ch2;
    int num_chars = 0;
    int num_words = 0;
    int num_lines = 0;

    if (argc != 2) {
        printf("Usage: count.exe file.txt\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    ch = getc(fp);
    ch2 = ch;
    while (1) {
        if (ch == ' ') {
            if (ch2 != ' ')
                num_words++;
        } else if (ch == '\n' || ch == EOF) {
            num_lines++;
            if (ch2 != ' ' && ch2 != '\n' && ch2 != EOF)
                num_words++;
        } else
            num_chars++;
        
        if (ch == EOF)
            break;

        ch2 = ch;
        ch = getc(fp);
    }

    printf("Number of characters: %d\nNumber of words: %d\nNumber of lines: %d\n", \
            num_chars, num_words, num_lines);
    return 0;
}
#endif

#if (PROJECT == 5)
// xor encryption 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG (1)


// flexible array member
typedef struct chars {
    size_t len;
    char str[];
} chars;

void get_opt(int argc, char *argv[], int *idx_input, int *idx_output);
void flexible_read_input(FILE *fp, chars *user_input );

int main(int argc, char *argv[]) {
    int idx_input_file = 0, idx_output_file = 0;

    get_opt(argc, argv, &idx_input_file, &idx_output_file);

    FILE *input_fp, *output_fp;
    char c;    
    int i = 0;

    input_fp = fopen(argv[idx_input_file], "rb");
    output_fp = fopen(argv[idx_output_file], "wb");

    if (input_fp == NULL || output_fp == NULL) {        
        fprintf(stderr, "Unable to open file: %s\n", \
            (input_fp == NULL ? argv[idx_input_file] : argv[idx_output_file]));
        exit(EXIT_FAILURE)                ;
    }

    chars *keys = calloc(sizeof(chars) + 5, sizeof(char));
    if (keys == NULL) {
        free(keys);
        exit(EXIT_FAILURE);
    }
    keys->len = 5;
    printf("Enter the keys to encrypt file: ");
    flexible_read_input(stdin, keys);

    while(!feof(input_fp) && !ferror(input_fp)) {
        c = fgetc(input_fp);
        fputc(c ^ keys->str[i++ % strlen(keys->str)], output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
    
    return 0;
}

void get_opt(int argc, char *argv[], int *idx_input_file, int *idx_output_file) {    
    if (argc == 5) {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], "-i")) {
                *idx_input_file = ++i;
            }

            if (!strcmp(argv[i], "-o")) {
                *idx_output_file = ++i;
            }
        }
    }

    if (*idx_input_file == 0 || *idx_output_file == 0 || argc != 5) {
        fprintf(stderr, "Missing or incorrect arguments:\nUsage: xor.exe -i input_file.txt -o output_file.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    #if DEBUG
    fprintf(stdout, "Input file is: %s\n", argv[*idx_input_file]);
    fprintf(stdout, "Output file is: %s\n", argv[*idx_output_file]);
    #endif

}

void flexible_read_input(FILE *fp, chars *user_input ) {    
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != '\n') {
        user_input->str[i++] = c;
        if (i >= user_input->len - 1) {                
            chars *temp = realloc(user_input, sizeof(chars) + user_input->len + 5);            
            if (temp == NULL) {
                printf("Fail to obtain all user input.\n");
                free(temp);
                break;
            }            
            user_input = temp;
            user_input->len += 5;
        }
    }
    user_input->str[i] = '\0';
}
#endif

#if (PROJECT == 6)
// display the contents of a file as bytes and as characters.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch, col_bytes = 10, offset = 0, col = 0, i = 0;
    unsigned char *characters;
    

    printf("How many bytes to display per column (minimum is 8)? ");
    scanf("%d", &col_bytes);
    if (col_bytes < 8)
        col_bytes = 8;

    characters = malloc(col_bytes);
    if (characters == NULL) {
        exit(EXIT_FAILURE);
    }
    
    if (argc != 2) {
        fprintf(stderr, "Usage: display.exe filename.txt\n");
        exit(EXIT_FAILURE);
    }
    
    if ( (fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    //fprintf(stdout, "Offset              Bytes              Characters\n");
    //fprintf(stdout, "------  -----------------------------  ----------\n");
    fprintf(stdout, "\nBytes per row: %d.\n", col_bytes);
    fprintf(stdout, "Offset  ");
    
    for (i = 0; i < ((col_bytes * 3 - 1) - 5) / 2; i++)
        fprintf(stdout, " ");
    fprintf(stdout, "Bytes");
    for (i += 4; i < (col_bytes * 3 - 1); i++)
        fprintf(stdout, " ");    
    fprintf(stdout, " Characters\n");

    fprintf(stdout, "------  ");
    for (i = 0; i < (col_bytes * 3 - 1); i++)
        fprintf(stdout, "-");
    fprintf(stdout, "  ");
    for (i = 0; i < col_bytes; i++)
        fprintf(stdout, "-");
    fprintf(stdout, "\n");


    for (offset = 0; ;offset+=col_bytes) {
        i = fread(characters, 1, col_bytes, fp);
        if (i == 0)
            break;

        fprintf(stdout, "%6d  ", offset);
        
        for (col = 0; col < i; col++)            
            fprintf(stdout, "%.2X ", characters[col]);
        
        for (; col < col_bytes; col++)
            fprintf(stdout, "   ");
        fprintf(stdout, " ");
        for (col = 0; col < i; col++) {
            if (isprint(characters[col]))
                fprintf(stdout, "%c", characters[col]);
            else
                fprintf(stdout, ".");
        }
        fprintf(stdout, "\n");
    }

    fclose(fp);

    return 0;
}

#endif

#if (PROJECT == 7)
// Rn-length encoding
// Given a file with following content:
// 46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20
// After encoding:
// 01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20
//
// Usage: compress_file.exe original_file.txt
// will output the compressed version to original_file.txt.rle
//
// To decompress: compress_file.exe original_file.txt.rle
// will output the de-compressed version to original_file.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef WIN32
#define WIN32
#endif

// for WIN32 only
#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#elif LINUX
#include <unistd.h>
#endif

#define COMPRESSION_FILE_EXTENSION ".rle"

typedef enum {DECOMPRESS = 0, COMPRESS} compression_t;
typedef enum {false = 0, true} bool;

/* Based on file extension, determains the mode of operaiton: to compress or to decompress */
compression_t test_for_operation(char *file_name);

/* Test if file exists*/
bool file_exists(char *file_name);

void terminate(FILE *fp, char *fmt, ...);
void compress(FILE *original_fp, FILE *output_fp);
void decompress(FILE *original_fp, FILE *output_fp);

int main(int argc, char *argv[]) {

    char output_file[FILENAME_MAX];
    FILE *input_fp, *output_fp;

    if (argc != 2) {
        terminate(stderr, "Usage:\nTo compress: compress_file.exe original_file.txt\n"          \
                          "will output the compressed version to original_file.txt.rle\n\n"     \
                          "To decompress: compress_file.exe original_file.txt.rle\n"            \
                          "will output the de-compressed version to original_file.txt\n");
    }

    if (strlen(argv[1]) > (FILENAME_MAX - 4)) {
        terminate(stderr, "Unable to create output file: file name exceeds limit.");
    }
    strcat(output_file, argv[1]);

    if (test_for_operation(argv[1]) == COMPRESS) {
        strcat(output_file, COMPRESSION_FILE_EXTENSION);
    } else {
        output_file[strlen(output_file) - strlen(COMPRESSION_FILE_EXTENSION)] = '\0';
    }

    if (file_exists(output_file)) {
        terminate(stderr, "Output file, %s, already exists. Remove it and try again.", output_file);
    } else if ((output_fp = fopen(output_file, "wb")) == NULL) {
        terminate(stderr, "Unable to create output file, %s.", output_file);
    }

    if (!file_exists(argv[1])) {
        terminate(stderr, "Input file, %s, does not exist.", argv[1]);
    } else if ((input_fp = fopen(argv[1], "rb")) == NULL) {
        terminate(stderr, "Unable to open input file, %s.", argv[1]);
    }

    if (test_for_operation(argv[1]) == COMPRESS) {
        compress(input_fp, output_fp);
    } else {
        decompress(input_fp, output_fp);
    }
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}


compression_t test_for_operation(char *file_name) {
    if (strlen(file_name) > strlen(COMPRESSION_FILE_EXTENSION) &&                       \
        strcmp(file_name + (strlen(file_name) - strlen(COMPRESSION_FILE_EXTENSION)),    \
               COMPRESSION_FILE_EXTENSION) == 0)
        return DECOMPRESS;
    return COMPRESS;
}

void terminate(FILE *fp, char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(fp, fmt, args);
    fprintf(fp, "\n");
    va_end(args);
    exit(EXIT_FAILURE);
}

bool file_exists(char *file_name) {
    if (access(file_name, F_OK) == 0) {
        return true;
    } else {
        return false;
    }
}

void compress(FILE *original_fp, FILE *output_fp) {    
    int c;
    unsigned char ch[2] = {0, 0};

    while ((c = getc(original_fp))) {
        if (c == ch[1] && ch[0] < 255) {
            ch[0]++;
        } else {
            if (ch[0] > 0) {
                fwrite(ch, 1, 2,output_fp);
            }
            if (c == EOF)
                break;
            ch[0] = 1;
            ch[1] = c;
        }
    }
}

void decompress(FILE *original_fp, FILE *output_fp) {
    unsigned char ch[2] = {0, 0};    
    while (fread(ch, 1, 2, original_fp) == 2) {
        for (; (int) ch[0] > 0; ch[0]--) {
            putc(ch[1], output_fp);
        }
    }
}

#endif

#if (PROJECT == 8)
int main(void) {
    // see \ch22\ch22_projects\inventory_5.c
    return 0;
}
#endif

#if (PROJECT == 9)
// the inventory program is modified specifically for project 9,
// see \ch22\ch22_projects\inventory_6.c
// the new inventory_6.c saves sorted inventory list to file, eliminating the sorted_part_numbers[] array.

int main(void) {
    // main program for Chapter 22 Project 9 see
    // \ch22\ch22_projects\project_9_merge_inventory.c
    return 0;
}
#endif

#if (PROJECT == 10)
// chapter 22 project 10, modify the inventory2.c from Section 17.5 by adding dump, and restore operations.
int main(void) {
    // see \ch22\ch22_projects\project_10_inventory_linked_list.c

    return 0;
}
#endif

#if (PROJECT == 11)
// get dates from command line
// get_date.exe 9-13-2010
// get_date.exe 9/13/2010
// and print out
// September 13, 2010

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    if (argc != 2) {
        fprintf(stderr, "Usage: get_date.exe 9-13-2010 or get_date.exe 9/13/2010\n");
        exit(EXIT_FAILURE);
    }
    int month, day, year;
    if (sscanf(argv[1], "%d -%d -%d", &month, &day, &year) == 3)
        ;
    else if (sscanf(argv[1], "%d /%d /%d", &month, &day, &year) == 3)
        ;
    else {
        fprintf(stderr, "Bad date format.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%s %d, %d\n", months[month-1], day, year);
    return 0;
}
#endif

#if (PROJECT == 12)
// modify chapter 3 project 2
// reads data from a file and prints it out:
// File content:
// 583, 13.5, 10/24/2005
// 3912, 599.99, 7/27/2008
//
// Output of the program
// Item         Unit       Purchase
//              Price      Date
// 583          $  13.50   10/24/2022
// 3912         $ 599.99   7/27/2008

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE (80)

int main(int argc, char *argv[]) {
    FILE *fp;
    int item, month, day, year;
    double price;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: get_data.exe item_list.txt\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Item       Unit       Purchase\n");
    fprintf(stdout, "           Price      Date\n");
    
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        sscanf(buffer, "%d, %lf, %d/%d/%d", &item, &price, &month, &day, &year);
        fprintf(stdout, "%-10d $%7.2lf   %d/%d/%d\n", item, price, month, day, year);
    }
    return 0;
}
#endif

#if (PROJECT == 13)
// modify Project 8 from Chapter 5 (Project 10 from Chapter 8)
// The departure and arrival times come from a file
// flights.dat
// 8:00 10:16
// 9:43 11:52
// 
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE (80)

int main(int argc, char *argv[]) {
    FILE *fp;
    int h = 0, m = 0, user;
    int departure_hr, departure_min, arrivial_hr, arrivial_min;
    int departure[8], arrivial[8];
    int i = 0, a_hr, a_min, d_hr, d_min;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: flight.exe flights.dat\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (sscanf(buffer, "%d:%d %d:%d", &d_hr, &d_min, &a_hr, &a_min) != 4)
            break;
        departure[i] = d_hr * 60 + d_min;
        arrivial[i++] = a_hr * 60 + a_min;
    }

    /*
    departure[0] =  8 * 60 +  0;
    departure[1] =  9 * 60 + 43;
    departure[2] = 11 * 60 + 19;
    departure[3] = 12 * 60 + 47;
    departure[4] = 14 * 60 +  0;
    departure[5] = 15 * 60 + 45;
    departure[6] = 19 * 60 +  0;
    departure[7] = 21 * 60 + 45;

    arrivial[0] = 10 * 60 + 16;
    arrivial[1] = 11 * 60 + 52;
    arrivial[2] = 13 * 60 + 31;
    arrivial[3] = 15 * 60 +  0;
    arrivial[4] = 16 * 60 +  8;
    arrivial[5] = 17 * 60 + 55;
    arrivial[6] = 21 * 60 + 20;
    arrivial[7] = 11 * 60 + 58;
    */

    printf("Enter estimated departure time: ");
    scanf(" %2d :%2d", &h, &m);

    user = h * 60 + m;
    
    for (i = 0; i < 7; i++) {
        if (( user - departure[i]) <= (departure[i + 1] - user)) {
        break;
        }
    }
    departure_min = departure[i] % 60;
    departure_hr = (departure[i] - departure_min) / 60;
    arrivial_min = arrivial[i] % 60;
    arrivial_hr = (arrivial[i] - arrivial_min) / 60;
    printf("Closet departure time is %02d:%02d, arriving at %02d:%02d.\n", departure_hr, departure_min,
                                                                    arrivial_hr, arrivial_min);
    return 0;
}
#endif

#if (PROJECT == 14)
// Modify from Program 15 from chapter 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true} bool;
#define MESSAGE_SIZE (80)

int main(void) {
    /* Caesar's cipher: shifting the position of a letter by a fixed value */
    char c;
    int i = 0, shift = 0;
    bool bUpperCase = false;
    char file_name[FILENAME_MAX];   

    FILE *fp_in, *fp_out;

    fprintf(stdout, "Enter a file name to encrypt: ");
    scanf(" %s", file_name);

    if ((fp_in = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    strcat(file_name, ".enc");
    
    if ((fp_out = fopen(file_name, "w")) == NULL) {
        fprintf(stderr, "Unable to crate file %s.\n", file_name);
        exit(EXIT_FAILURE);
    }

    /*
    printf("Enter a message: ");
    for (i = 0; i < MESSAGE_SIZE; i++) {
        c = getchar();
        if (c == '\n') break;
        message[i] = c;
    }
    */

    do {
        printf("Enter shift amount[1 - 25]: ");
        scanf("%d", &shift);
    } while (shift > 25 || shift < 1);

    // shift characters
    /*    
    for (i = 0; i < MESSAGE_SIZE; i++) {
        c = message[i];            
        if (c >= 'a' && c <= 'z') c = (c - 'a' + shift) % 26 + 'a';
        if (c >= 'A' && c <= 'Z') c = (c - 'A' + shift) % 26 + 'A';
        message[i] = c;
    }

    printf("The encrypted message: ");
    for (i = 0; i < MESSAGE_SIZE; i++) printf("%c", message[i]);
    */
    while ((c = getc(fp_in)) != EOF) {
        if (c >= 'a' && c <= 'z') c = (c - 'a' + shift) % 26 + 'a';
        if (c >= 'A' && c <= 'Z') c = (c - 'A' + shift) % 26 + 'A';
        putc(c, fp_out);
    }
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
#endif

#if (PROJECT == 15)
// modify justify.c from Section 15.3 so that it reads from one text file
// and writes to another. The program will obtain the names of both files
// from the command line
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // see
    // ch22/justify.c
    // ch22/line.c
    // ch22/word.c
    
    return 0;
}
#endif

#if (PROJECT == 16)
//  Chapter 22 Project 16
//  Modify fcopy.c so that it uses fread and fwrite to 
//  copy data in bloks of 512bytes.

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* fcopy.c (Chapter 22, page 568) */
/* Copies a file */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BUFFER_SIZE (512)

int main(int argc, char *argv[])
{
  FILE *source_fp, *dest_fp;
  int8_t buffer[BUFFER_SIZE];  
  int bytes;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if ((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }


  while (!feof(source_fp) && !ferror(source_fp)) {
    bytes = fread(buffer, sizeof(int8_t),512, source_fp);
    fwrite(buffer, sizeof(int8_t), bytes, dest_fp);
  }

  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}

#endif

#if (PROJECT == 17)
// Read from a file a list of phone numbers mixed with differnet
// characters. Assume each phone number is 10 digits. Display
// each phone number in a standard format.
//
// input digits
// 404.817.6900
// (215) 686-1776
// 312-746-6000
// 877 275 5273
// 6173434200
//
// output 
// (404) 817-6900
// (2l5) 686-1776
// (312) 746-6000
// (877) 275-5273
// (617) 343-4200

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define VALID_PHONE_DIGITS (10)

int main(int argc, char *argv[]) {
    FILE *fp;
    int c, count_digits = 0;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: getphone.exe phonebook.txt\n");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = getc(fp)) != EOF) {
        if (isdigit(c)) {            
            count_digits++;
            if (count_digits == 1)
                putc('(', stdout);
            putc(c, stdout);
            switch (count_digits) {
                case 3:
                    fprintf(stdout, ") ");
                    break;
                case 6:
                    fprintf(stdout, "-");
                    break;
            }
        } else if (c == '\n') {
            if (count_digits != VALID_PHONE_DIGITS)
                fprintf(stdout, " INVALID PHONE NUMBER.");
            putc('\n', stdout);
            count_digits = 0;
        }
        if (count_digits > VALID_PHONE_DIGITS) {
            while ((c = getc(fp)) != '\n' && c != EOF)
                ;
            fprintf(stdout, " INVALID PHONE NUMBER.\n");
            count_digits = 0;
        }
    }

    return 0;
}
#endif

#if (PROJECT == 18)
// read integers from a text file and print out the min, max, average, and median value.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int read_digit(FILE *fp);

int main(int argc, char *argv[]) {
    size_t array_size = 10;
    FILE *fp;
    int temp_num, num_digits = 0, i, j, sum = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: get_int.exe integers.txt\n");
        exit(EXIT_FAILURE);        
    }

    int *array = malloc(sizeof(int) * array_size);
    if (array == NULL) {
        fprintf(stderr, "Unable to allocate memory to array.\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(!feof(fp) && !ferror(fp)) {
        temp_num = read_digit(fp);
        if ((num_digits + 1) >= array_size) {
            array_size += 10;
            int *temp = realloc(array, sizeof(int) * array_size);
            if (temp == NULL) {
                array_size -= 10;
                break;
            }
            array = temp;
        }

        for (i = 0; i < num_digits; i++) {
            if (array[i] > temp_num) {
                for (j = num_digits; j > i; j--)
                    array[j] = array[j-1];
                break;
            }
        }
        array[i] = temp_num;
        sum += temp_num;
        num_digits++;        
    }

    printf("min: %d, max: %d, med: %d, avg: %d",                         \
        array[0], array[num_digits-1],                                  \
        (num_digits % 2 == 0) ?                                         \
            (array[num_digits/2] + array[num_digits/2]) / 2 :       \
            array[num_digits/2]                                     \
        ,sum / num_digits);

    return 0;
}

int read_digit(FILE *fp) {
    int c;
    int num = 0;
    while ((c = getc(fp)) == ' ' || c == '\n' || isalpha(c) || ispunct(c))
        ;
    while (isdigit(c)) {        
        num = num * 10 + (c - '0');
        c = getc(fp);        
    }

    return num;
}

#endif

#if (PROJECT == 19)
// convert text file with Windows EOL to Unix EOL
// convert text file with Unix EOL to Windows EOL
// Windows EOL is represeted with '\x0d\x0a'
// Unix EOL is '\x0a'
// Windows EOF is '\x1a', Unix does not have EOF
// marker.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true} bool;

int main(int argc, char *argv[]) {
    FILE *fp_input, *fp_output;
    bool bWIN2UNIX = false;
    bool bUNIX2WIN = false;

    int c, d;

    if (argc != 4) {
        fprintf(stderr, "Usage: convert_eol.exe win2unix input_file.txt output_file.txt or\n" \
                        "       convert_eol.exe unix2win input_file.txt output_file.txt\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "win2unix") == 0) {
        bWIN2UNIX = true;
        bUNIX2WIN = false;
    } else if (strcmp(argv[1], "unix2win") == 0) {
        bWIN2UNIX = false;
        bUNIX2WIN = true;
    } else {
        fprintf(stderr, "Unknown mode of operation.\n");
        fprintf(stderr, "Usage: convert_eol.exe win2unix input_file.txt output_file.txt or\n" \
                        "       convert_eol.exe unix2win input_file.txt output_file.txt\n");
        exit(EXIT_FAILURE);
    }


    if ((fp_input = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Unable to open file: %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((fp_output = fopen(argv[3], "wb")) == NULL) {
        fclose(fp_input);
        fprintf(stderr, "Unable to create file: %s.\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    if (bWIN2UNIX) {
        while ((c = getc(fp_input)) != EOF) {
            if (c == '\x0d') {
                if ((d = getc(fp_input)) == '\x0a') {
                    putc(d, fp_output);
                } else {
                    putc(c, fp_output);
                    putc(d, fp_output);
                }
            } else {
                putc(c, fp_output);
            }
        }
    } else if (bUNIX2WIN) {
        while ((c = getc(fp_input)) != EOF) {
            if (c == '\x0a') {
                putc('\x0d', fp_output);
                putc(c, fp_output);
            } else {
                putc(c, fp_output);
            }
        }
    }
    fclose(fp_input);
    fclose(fp_output);

    return 0;
}
#endif