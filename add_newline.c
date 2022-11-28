/******************************************************************
* add_newline.c: Add a new line at end of each line for a .txt    *
*                file so that it can be recongized as a .srt      *
*                file.                                            *
******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char line_buffer[256];
    char output_filename[FILENAME_MAX];

    FILE *fp_input, *fp_output;

    if (argc  != 2) {
        fprintf(stderr, "Usage: add_newline.c file.srt\n");
        exit(EXIT_FAILURE);
    }

    strcpy(output_filename, argv[1]);
    strcat(output_filename, ".srt");

    if ((fp_input = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fp_output = fopen(output_filename, "w")) == NULL) {
        fprintf(stderr, "Unable to open %s\n", output_filename);
        exit(EXIT_FAILURE);
    }

    int i;
    int line_num;
    int a,b,c,d,e,f,g,h;
    int line_check;
    while (!feof(fp_input) && !ferror(fp_input)) {
        fgets(line_buffer, 256, fp_input);
        fputs(line_buffer, fp_output);
                
        fgets(line_buffer, 256, fp_input);
        if (line_buffer[29] == '\n')
            fputs(line_buffer, fp_output);
        else {
            for (i = 0; i < 29; i++)
                putc(line_buffer[i], fp_output);
            putc('\n', fp_output);
            for (i = 31; i < strlen(line_buffer); i++)
                putc(line_buffer[i], fp_output);
            putc('\n', fp_output);
            continue;
        }

        fgets(line_buffer, 256, fp_input);
        fputs(line_buffer, fp_output);
        putc('\n', fp_output);
    }

    fclose(fp_input);
    fclose(fp_output);

    return 0;
}