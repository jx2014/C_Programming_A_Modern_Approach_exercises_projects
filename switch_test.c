#include <stdio.h>

int main(void) {
    int i;
    printf("Enter i: ");
    scanf("%d", &i);

    switch (i) {
        case 0:
            printf("0 ");
        case 1:
            printf("1 ");
        case 2:
            printf("2\n");
            break;
        case 3:
            printf("3\n");
            break;
        case 4:
            printf("4 ");
        default:
            printf("end\n");
    }
    
    // 
    // if i == 0
    // 0
    //


    return 0;
}