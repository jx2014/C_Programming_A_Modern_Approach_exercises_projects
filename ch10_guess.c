#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

/* external variable */
int secret_number;

/* prototypes */
void InitializeNumberGenerator(void);
void ChooseNewSecretNumber(void);
void ReadGuesses(void);

int main(void) {
    char command;
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    InitializeNumberGenerator();

    do {
        ChooseNewSecretNumber();
        printf("A new number has been chosen.\n");
        ReadGuesses();
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'y' || command == 'Y');

    return 0;
}

void InitializeNumberGenerator(void) {
    srand((unsigned) time(NULL));
}

void ChooseNewSecretNumber(void) {
    secret_number = rand() % MAX_NUMBER + 1;
}

void ReadGuesses(void) {
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