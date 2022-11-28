/*
 *   Chapter 13 Project # 5
 *              sum.exe     12 3 27
 *              returns:    42
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    
    printf("sum: %d", sum);
}