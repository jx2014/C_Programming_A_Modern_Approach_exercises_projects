#include "stdio.h"
#include "stdbool.h"

#define EXERCISE (11)

int main(void) {
    #if (EXERCISE == 1)
        int i, j, k;

        i = 2; j = 3;
        k = i * j == 6;
        printf("%d\n", k); // 1

        i = 5; j = 10; k = 1;
        printf("%d\n", ( k > i )< j); // 1, k > i is 0, 0 < j is true.

        i = 3; j = 2; k = 1;
        printf("%d\n", (i < j) == (j < k)); //1,  i < j is 0, j < k is 0, 0 == 0.

        i = 3; j = 4; k = 5;
        printf("%d\n", i % j + i < k ); //0 , i % j = 3, 3 + i = 6, 6 < k is 0.
    #endif

    #if (EXERCISE == 2)
        int i, j, k;

        i = 10, j = 5;
        printf("%d\n", (!i) < j); // !i is 0, 0 < 5, 1

        i = 2, j = 1;
        printf("%d\n", !!i + !j); // !!i is 1, !j is 0, 1

        i = 5, j = 0, k = -5;
        printf("%d\n", ( i && j ) || k); //5 && 0 is 0, 0 or -5 is 1, 1

        i = 1, j = 2, k = 3;
        printf("%d\n", i < j || k); //1 < 2 is 1, 1 or 3 is 1, 1

    #endif

    #if (EXERCISE == 3)
        int i, j, k;

        i = 3, j = 4, k = 5;
        printf("%d ", i < j || ++j < k); //1, i < j is 1 since its or, ++j < k is not evaluated, j remains as 4.
        printf("%d %d %d\n", i, j, k); //3, 4, 5

        i = 3, j = 4, k = 5;
        printf("%d ", i - 7 && j++ < k); //1 , -4 && 5 is 1, 1 < 5 is 1
        printf("%d %d %d\n", i, j, k); // 3, 5, 5

        i = 7, j = 8, k = 9;
        printf("%d ", (i = j) || (j = k)); //1, i = 8 since its or, (j = k) is not evaluated, j remains as 8.
        printf("%d %d %d\n", i, j, k); //8, 8, 9

        i = 3, j = 4, k = 5;
        printf("%d ", ( ++i || ++j ) && ++k); //1, i is 4, since its or, j is not evaluated, 1 && ++k is 1,
        printf("%d %d %d\n", i, j, k); //4, 4, 6

    #endif

    #if (EXERCISE == 4)
        // single statement to test if i > j reutrns 1, 
        // if i == j returns 0, 
        // if i < j, returns -1
        // right asnwer: (i > j) - (i < j)
        int i, j;
        i = 1, j = 1;
        printf("%d\n", (( i > j ) ? 1 : (( i == j ) ? 0 : -1 ))); // 0
        i = 2;
        printf("%d\n", (( i > j ) ? 1 : (( i == j ) ? 0 : -1 ))); // 1
        i = 0;
        printf("%d\n", (( i > j ) ? 1 : (( i == j ) ? 0 : -1 ))); // -1
    
    #endif

    #if (EXERCISE == 6)
        int n = 1;
        printf("enter n: ");
        scanf("%d", &n);
        if ( n == 1 - 10) { // if n = -9, 1 - 10 is evulated first, if n is -9, then if statement returns true.
            printf("something\n");
        }

    #endif

    #if (EXERCISE == 7)
        int i = 17;
        printf("%d\n", i >= 0 ? i : -i); // 17
        i = -17;
        printf("%d\n", i >= 0 ? i : -i); // 17    
    #endif

    #if (EXERCISE == 8)
        int age;
        bool teenager;

        printf("Enter age: ");
        scanf("%d", &age);
        // replace following with single statement:
        if (age >= 13)
            if (age <= 19)
                teenager = true;
            else
                teenager = false;
        else if (age < 13)
            teenager = false;
        
        teenager == true ? printf("Teenager\n") : printf("Not Teenager\n");

        teenager = ((age >= 13) && (age <= 19)) ? true : false;

        teenager == true ? printf("Teenager\n") : printf("Not Teenager\n");

    #endif

    #if (EXERCISE == 9)
        int score = 0;
        printf("Enter score 0 to 100: ");
        scanf("%d", &score);

        if (score >= 90)
            printf("A");
        else if (score >= 80)
            printf("B");
        else if (score >= 70)
            printf("C");
        else if (score >= 60)
            printf("D");
        else 
            printf("F");

        printf("\n");

        if (score < 60)
            printf("F");
        else if (score < 70)
            printf("D");
        else if (score < 80)
            printf("C");
        else if (score < 90)
            printf("B");
        else
            printf("A");
        
        printf("\n");
    #endif

    #if (EXERCISE == 10)
        int i = 1;
        switch (i % 3) {
            case 0: printf("Zero");
            case 1: printf("one");
            case 2: printf("two");
        }

    #endif

    #if (EXERCISE == 11)
        int code = 0;
        printf("Enter a three digit area code: ");
        scanf("%3d", &code);

        switch (code) {
            case 229: printf("Albany\n"); break;
            case 404: printf("Atlanta\n"); break;
            case 470: printf("Atlanta\n"); break;
            case 478: printf("Macon\n"); break;
            case 678: printf("Atlanta\n"); break;
            case 706: printf("Columbus\n"); break;
            case 762: printf("Columbus\n"); break;
            case 770: printf("Atlanta\n"); break;
            case 912: printf("Savannah\n"); break;            
            default: printf("Area code not recognized\n");
        }
    #endif

    return 0;
}
