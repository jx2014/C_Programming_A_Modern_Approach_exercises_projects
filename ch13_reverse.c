/*
 *   Chapter 13 Project # 4
 *              reverse.exe abc def ghi
 *              returns:    ghi def abc
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char *argv[]) {
    for (int i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);        
    }
    
    return 0;
}