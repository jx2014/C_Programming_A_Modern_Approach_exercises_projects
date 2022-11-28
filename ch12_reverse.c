#include <stdio.h>

#define N 10

int main(void){
    int a[N], *p;
    printf("Enter %d numbers: ", N);
    for(p = a; p < (a + N); p++) {
        scanf(" %d", p);
    }

    printf("The reverse is: ");
    for(--p; p >= a; --p) {
        printf("%d ", *p);
    }
    printf("\n");   

    return 0;
}

/*
reverse.c from chapter 8 using array subscrition

#include <stdio.h>

#define N 10

int main(void){
    int a[N];
    printf("Enter a series of numbers: ");
    for(int i = 0; i < N; i++) {
        scanf(" %d", &a[i]);
    }

    printf("The reverse is: ");
    for(int i = (N - 1); i >=0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");   

    return 0;
}
*/