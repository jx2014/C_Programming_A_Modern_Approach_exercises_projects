#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

/* prototypes */
void InitializeNumberGenerator(void);
int ChooseNewSecretNumber();
void ReadGuesses();

int main(void) {
    char command;
    int secret_number;
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    InitializeNumberGenerator();

    do {
        secret_number = ChooseNewSecretNumber();
        printf("A new number has been chosen.\n");
        ReadGuesses(secret_number);
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'y' || command == 'Y');

    return 0;
}

void InitializeNumberGenerator(void) {
    srand((unsigned) time(NULL));
}

int ChooseNewSecretNumber(void) {
    return rand() % MAX_NUMBER + 1;
}

void ReadGuesses(int secret_number) {
    int guess, num_guess = 0;
    for (;;) {
        num_guess++;
        printf("Enter guess: ");
        scanf(" %d", &guess);
        if (guess == secret_number) {
            printf("You won in %d guesses!\n\n", num_guess);
            return ;
        } else if ( guess < secret_number) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }
    }
}