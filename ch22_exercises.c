#define EXERCISE (15)

#if (EXERCISE == 0)
/* Find_int exercise, page 565 */

#include <stdio.h>
#define FP_ERROR_OPEN_FILE (-1)
#define FP_ERROR_READ (-2)
#define FP_ERROR_INT_NOT_FOUND (-3)

int find_int(const char *filename) {
    FILE *fp = fopen(filename, "r");
    int n;
    if (fp == NULL)
        return FP_ERROR_OPEN_FILE;

    while (fscanf(fp, "%d", &n) != 1) {
        if (ferror(fp)) {
            fclose(fp);
            return FP_ERROR_READ;
        }
        if (feof(fp)) {
            fclose(fp);
            return FP_ERROR_INT_NOT_FOUND;
        }
        fscanf(fp, "%*[^\n]"); // skip rest of lines
    }
    fclose(fp);
    return n;
}

int main(void) {
    const char* file_name = "test_input.txt";
    int n;
    n = find_int(file_name);

    int icount = 0;
    for(icount=1; icount <= 20; icount+=5)
        ;
    return 0;
}
#endif


#if (EXERCISE == 1)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 2)
int main(void) {
    // 'rb+'（a) A databse management system opens a file containing records to be updated.
    // 'a'  (b) A mail program opens a file of saved messages so that it can add additional messages to the end.
    // 'rb' (c) A graphics program opens a file containing a picture to be displayed on the screen.
    // 'r'  (d) All OS command interpreter opens a "shell script" or "batch file" containing commands to be executed.
    return 0;
}
#endif

#if (EXERCISE == 3)
#include <stdio.h>

int main(void) {
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        // ... read characters until end-of-file
    }
    fclose(fp);

    return 0;
}
#endif

#if (EXERCISE == 4)
#include <stdio.h>

int main(void) {
    printf("%#012.5g\n", 83.7361f);     //  00000083.736
    printf("%#012.5g\n", 29748.6607f);  //  00000029748.
    printf("%#012.5g\n", 1054932234.0); //  07670176412.
    printf("%#012.5g\n", 0.0000235218); //  00.000023522
    return 0;
}
#endif

#if (EXERCISE == 5)
#include <stdio.h>

int main(void) {

    int x = 1, y = 1234, z = 12345;
    printf("|%.4d|%04d|%.4d|\n", x, x, x); // 
    printf("|%.4d|%04d|%.4d|\n", y, y, y); // 
    printf("|%.4d|%04d|%.4d|\n", z, z, z); // 

    return 0;
}
#endif

#if (EXERCISE == 6)
// A single call of printf to print out a result based on 
// a condition without using the if statement.

#include <stdio.h>

int main(void) {

    int widget = 1;
    int widgets = 2;

    printf(((widget > 1) ? "%d widgets\n" : "%d widget\n"), widget);
    printf(((widgets > 1) ? "%d widgets\n" : "%d widget\n"), widgets);

    return 0;
}
#endif

#if (EXERCISE == 7)

#include <stdio.h>

int main(void) {
    int n = 0, i = 0, j = 0;
    float x = 0;
    char buf[80];

    while (1) {

        printf("Enter some digits:\n");
        n = scanf("%d%f%d", &i, &x, &j);
        //fflush(stdin);
        scanf("%[^\n]", buf);
    }
    // (a) 10 20 30         i = 10, x = 20, j = 30, n = 3
    // (b) 1.0 2.0 3.0      i = 1,  x = .0, j = 2,  n = 3
    // (c) 0.1 0.2 0.3      i = 0,  x = .1, j = 0,  n = 3
    // (d) .1 .2 .3         i = 0, n = 0
    
    return 0;
}
#endif

#if (EXERCISE == 8)
#include <stdio.h>

int main(void) {
    char a[3] = {'a', 'a', 'a'}, b[3] = {'b', 'b', 'b'};

    while(1) {

        printf("Enter character A:");
        scanf(" %c", a);                // stores only in a[0]
        printf("Enter character B:");
        scanf("%1s", b);                // stores in b[0], '\n' in b[1]
        fflush(stdin);
    }

    return 0;
}
#endif


#if (EXERCISE == 9)
int main(void) {

    // getch() is not a valid way of reading one character from stdin.

    return 0;
}
#endif

#if (EXERCISE == 10)
// fcopy.c
// include error checking when writting to file

#include <stdio.h>
#include <stdlib.h>
// add error checking for fcopy.c

int main(int argc, char *argv[]) {

    FILE *source_fp, *dest_fp;
    int ch;
    int *i;
    int x = 100;

    i = &x;

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
        exit(EXIT_FAILURE);
    }

    /*
    while ((ch = getc(source_fp)) != EOF) {
        putc(ch, dest_fp);
        if (ferror(dest_fp) || ferror(source_fp)) {
            fprintf(stderr, "Write error occured for %s.\n", argv[2]);
            exit(EXIT_FAILURE);
        }                 
    }
    */

    // book answer
    while ((ch = getc(source_fp)) != EOF) {
        if (putc(ch, dest_fp) == EOF) {
            fprintf(stderr, "Error during writing; copy terminated\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}
#endif

#if (EXERCISE == 11)
// fcopy.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *source_fp, *dest_fp;
    int ch;
    int *i;
    int x = 100;

    i = &x;

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
        exit(EXIT_FAILURE);
    }

    x = 0;
    while (ch = getc(source_fp) != EOF) {
        printf("%n %c ", x, ch);
        putc(ch, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}
#endif

#if (EXERCISE == 12)

#include <stdio.h>

int count_periods(const char *filename) {
    FILE *fp;
    int n = 0;
    char c;

    if ((fp = fopen(filename, "r")) != NULL) {
        while ((c = fgetc(fp)) != EOF)
            if (c == '.')
                n++;
        fclose(fp);
    }
    return n;
}

int main(void) {

    printf("There are %d periods in file: \"%s\".\n", count_periods("ch22_exercises.c"), "ch22_exercises.c");

    return 0;
}
#endif

#if (EXERCISE == 13)
// count the length of line n in the text file.

#include <stdio.h>

int line_length(const char *filename, int n) {
    FILE *fp;
    int len = 0;
    char c;

    if ((fp = fopen(filename, "r")) != NULL) {
        for (; n > 0; n--) {
            while ( ((c = fgetc(fp)) != '\n') && (c != EOF)) {
                if (n == 1) {
                    len++;
                }
            }
        }        
    }
    return len;
}

int main(void) {
    int n;
    char * filename = "ch22_exercises.c";
    printf("Enter line number: ");
    scanf(" %d", &n);

    printf("There are %d characters for line %d in file: \"%s\".\n", line_length(filename, n), n, filename);

    return 0;
}
#endif

#if (EXERCISE == 14)
// writting alternative version of fgets() and fputs()
#include <stdio.h>

char *fgets2(char * restrict s, int n, FILE * restrict stream);
int fputs2(const char * restrict s, FILE * restrict stream);

/* book answer */
char *fget_string(char *s, int n, FILE *stream);
int fput_string(const char *s, FILE *stream);


int main(void) {


    return 0;
}

char *fgets2(char * restrict s, int n, FILE * restrict stream) {
    int i;
    
    if (feof(stream) || ferror(stream)) {
        return NULL;
    }
    
    for (i = 0; i < n; i++) {
        if ((s[i]  = getc(stream)) != EOF) {
            if (s[i] == '\n')
                return s;
        } else {
            break;
        }
    }
    s[i-1] = '\0';
    return s;
}

int fputs2(const char * restrict s, FILE * restrict stream) {
    int i = 0;
    while (s[i] != '\0' && !feof(stream) && !ferror(stream))
        putc(s[i++], stream);
    if (i == 0)
        return EOF;
    return i;    
}

/* book answer */
char *fget_string(char *s, int n, FILE *stream)
{
  int ch, len = 0;

  while (len < n - 1) {
    if ((ch = getc(stream)) == EOF) {
      if (len == 0 || ferror(stream))
        return NULL;
      break;
    }
    s[len++] = ch;
    if (ch == '\n')
      break;
  }

  s[len] = '\0';
  return s;
}

int fput_string(const char *s, FILE *stream)
{
  while (*s != '\0') {
    if (putc(*s, stream) == EOF)
      return EOF;
    s++;
  }

  return 0;
}

#endif

#if (EXERCISE == 15)
// Write calls of fseek that perform the following file-positioning operations on a binary file
// whose data is arranged in 64-byte 'records.' Use fp as the file pointer in each case.
// a) Move to the beginning of record n. (Assume that the first record in the file is record 0.)
// b) Move to the beginning of the last record in the file.
// c) Move forward one record.
// d) Move backward two records.

#include <stdio.h>

typedef struct data_s {
    size_t x;
    size_t y;
    size_t z;
    size_t w;
    size_t xx;
    size_t yy;
    size_t zz;
    size_t ww;    
} data_t;

int main(void) {
    data_t some_data_record = {.x = 0x1A, .y = 0x2A, .z = 0x3A, .w = 0x4A, .xx = 0x5A, .yy = 0x6A, .zz = 0x7A, .ww = 0x8A};

    FILE *fp = fopen("testfile.bin", "wb");

    for (int i = 0; i < 6 && !ferror(fp); i++) {
        if ((fwrite(&some_data_record, sizeof(data_t), 1, fp)) != 1)
            break;
        some_data_record.x  += 1;
        some_data_record.y  += 1;
        some_data_record.z  += 1;
        some_data_record.w  += 1;
        some_data_record.xx += 1;
        some_data_record.yy += 1;
        some_data_record.zz += 1;
        some_data_record.ww += 1;        
    }

    fclose(fp);

    fp = fopen("testfile.bin", "rb");
    data_t read_data;
    while (!feof(fp) && !ferror(fp)) {
        fread(&read_data, sizeof(read_data), 1, fp);
    }

    /*
    #define SEEK_CUR    1
    #define SEEK_END    2
    #define SEEK_SET    0
    */
    // move to beginning of record of nth block (first block is n = 1):
    int n = 2;
    fseek(fp, (n - 1) * sizeof(read_data), SEEK_SET);
    fread(&read_data, sizeof(read_data), 1, fp);

    // move to beginning of last record
    fseek(fp, (long) (-1 * sizeof(read_data)), SEEK_END);

    // move forward one record
    fseek(fp, sizeof(read_data), SEEK_CUR);

    // move backward one record
    fseek(fp, (long) (-2 * sizeof(read_data)), SEEK_CUR);

    return 0;
}
#endif

#if (EXERCISE == 16)
// Use sscanf to extracts digit from string "sales rank#989"
// "sales rank#24,675", or "sales rank#1,232,230"

#include <stdio.h>

int main(void) {

    char *str = "sales rank#998";
    char *str2 = "sales rank#1,234,232";
    char sales_rank[256];

    sscanf(str, "sales rank#%s", sales_rank);


    return 0;
}
#endif
