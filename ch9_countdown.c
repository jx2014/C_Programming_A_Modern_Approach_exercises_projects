#include <stdio.h>
#include <windows.h>

void print_count(int n) {    
    printf("%2d", n);
}

int main(void) {
    int i;

    printf("Count down: ");
    for (i = 10; i > 0; --i) {
        print_count(i);
        Sleep(1000);
        printf("\b\b");
    }
    printf("\n");
    
    return 0;
}