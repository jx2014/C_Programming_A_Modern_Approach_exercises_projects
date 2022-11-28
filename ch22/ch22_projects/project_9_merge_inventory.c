/******************************************************************
* Project 9: Merge two databses saved by inventory_6.exe. If      *
*            both databases have the same part number and same    *
*            part number, then combine their inventory qty. If    *
*            they have different part names, print out an error   *
*            message. The merge program assumes the parts in the  *
*            inventory file are in sorted order. The merge        *
*            result is also sorted in ascending order by the      *
*            part number.                                         *
******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
        int number;
        char name[NAME_LEN+1];
        int on_hand;
        double price;
};

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2, *fp3;
    FILE *fp[3];
    char *fp_op[] = {"rb", "rb", "wb"};

    size_t num_parts = 0, max_parts = 10;
    int i;
    struct part *inventory;
    struct part temp1, temp2;

    if (argc != 4) {
        fprintf(stderr, "Usage: merge_inventory.exe database1 database2 mergedfile\n");
        exit(EXIT_FAILURE);
    }

    int bad_file_operation = 0;
    for (i = 0; i < 3; i++) {
        if ((fp[i] = fopen(argv[i+1], fp_op[i])) == NULL) {
            fprintf(stderr, "Failed to open %s\n", argv[i+1]);            
            bad_file_operation = 1;
        }
    }
    if (bad_file_operation) {
        for (i = 0; i < 3; i++) {
            fclose(fp[i]);
        }
        exit(EXIT_FAILURE);
    }


    /*
    if (((fp1 = fopen(argv[1], "rb")) == NULL) || ((fp2 = fopen(argv[2], "rb")) == NULL) || ((fp3 = fopen(argv[3], "wb")) == NULL)) {
        if (fp1 == NULL)
            fprintf(stderr, "Failed to open %s\n", argv[1]);
        if (fp2 == NULL)
            fprintf(stderr, "Failed to open %s\n", argv[2]);
        if (fp3 == NULL)
            fprintf(stderr, "Failed to open %s\n", argv[3]);
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        exit(EXIT_FAILURE);
    }
    */

    int a, b;
    a = fread(&temp1, sizeof(struct part), 1, fp[0]);
    b = fread(&temp2, sizeof(struct part), 1, fp[1]);

    while (!feof(fp[0]) || !feof(fp[1])){
        if ((a == 1) && (b == 1)) {         // both database files contain valid data.
            if (temp1.number < temp2.number) {
                fwrite(&temp1, sizeof(struct part), 1, fp[2]);
                a = fread(&temp1, sizeof(struct part), 1, fp[0]);
                continue;
            } else if (temp1.number > temp2.number) {
                fwrite(&temp2, sizeof(struct part), 1, fp[2]);
                b = fread(&temp2, sizeof(struct part), 1, fp[1]);
                continue;
            } else {
                if (strcmp(temp1.name, temp2.name) == 0) {
                    temp1.on_hand += temp2.on_hand;
                    temp1.price = (temp1.price + temp2.price) / 2;
                    fwrite(&temp1, sizeof(struct part), 1, fp[2]);
                } else {
                    fprintf(stderr, "Part #%d has two different names: %s and %s.\n",       \
                            temp1.number, temp1.name, temp2.name);
                }
            }
        } else if ((a == 1) && (b != 1)) { // only database temp1 contains valid data
            fwrite(&temp1, sizeof(struct part), 1, fp[2]);
        } else if ((a != 1) && (b == 1)) { // only database temp2 contains valid data.
            fwrite(&temp2, sizeof(struct part), 1, fp[2]);
        }
        a = fread(&temp1, sizeof(struct part), 1, fp[0]);
        b = fread(&temp2, sizeof(struct part), 1, fp[1]);
    }

    return 0;
}
