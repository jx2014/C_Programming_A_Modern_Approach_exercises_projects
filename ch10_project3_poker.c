#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define NUM_RANKS 13
// #define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/* external variables */
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

void read_cards();
void analyze_hand();
void print_result(void);
void sort_rank();

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly                                       *
 *       Store cards in a 5 x 2 arrays                    *
 * ********************************************************/
int main(void) {
    // int num_in_ranks[NUM_RANKS] = {0};
    // int num_in_suit[NUM_SUITS] = {0};
    int hand[NUM_CARDS][2];


    while (true) {
        read_cards(hand);        
        analyze_hand(hand);
        print_result();
    }
    return 0;
}

/*********************************************************
 * read_cards: Reads the cards into the external         *
 *             variables num_in_rank and num_in_suit;    *
 *             checks for bad cards and duplicate cards. *
 * *******************************************************/
void read_cards(int hand[][2]) {
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    bool card_exists;
    int cards_read = 0;
    int i;

    /*
    for (rank = 0; rank < NUM_RANKS; rank++) {
        hand[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++) {
            card_exists[rank][suit] = false;
        }
    }

    for (suit = 0; suit < NUM_SUITS; suit++) {
        num_in_suit[suit] = 0;
    }
    */

   // initialize hand
   for (i = 0; i < NUM_CARDS; i++) {
       hand[i][0] = 0;
       hand[i][1] = 0;
   }

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n') {
            if (ch != ' ') bad_card = true;
        }

        card_exists = false;
        for (i = 0; i < cards_read; i++) {
            if ((hand[i][0] == rank) && (hand[i][1] == suit)) {
                card_exists = true;
                break;
            }
        }


        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else if (card_exists) {
            printf("Duplicate card; ignored.\n");
        } else {
           hand[cards_read][0] = rank;
           hand[cards_read][1] = suit;
           cards_read++;
        }
    }
}

/**********************************************************
 * analyze_hand: determines whether the hand contains a   *
 *               straight, a flush, four-of-a kind,       *
 *               and/or three-of-a-kind; determins the    *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 * ********************************************************/
void analyze_hand(int hand[][2]) {
    int num_consec = 0;
    int rank, suit;
    int i = 0;
    int j = 0;
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    /* check for flush */
    for (i = 0; i < (NUM_CARDS - 1); i++) {
        if(hand[i][1] != hand[i+1][1]) {
            flush = false;
        }
    }

    /* check for straight */
    sort_rank(hand);
    for (i = 0; i < (NUM_CARDS - 1); i++) {
        if (hand[i+1][0] - hand[i][0] != 1) {
            straight = false;
            break;
        }
    }

    /*  The ranks are already sorted from the smallest to 
        the largest. */
    // Check for 4-of-a-kind
    for (rank = 0; rank < (NUM_CARDS - 3); rank++) {
        if (hand[rank][0] == hand[rank+1][0] && 
            hand[rank+1][0] == hand[rank+2][0] && 
            hand[rank+2][0] == hand[rank+3][0]) {
            four = true;
            return;
        }
    }
    // Check for 3-of-a-kind
    for (rank = 0; rank < (NUM_CARDS - 2); rank++) {
        if (hand[rank][0] == hand[rank+1][0] && 
            hand[rank+1][0] == hand[rank+2][0]) {
            three = true;
            return;
        }
    }
    // Check for pairs    
    for (rank = 0; rank < (NUM_CARDS - 1); rank++) {
        for (j = (rank + 1); j < NUM_CARDS; j++ ){
            if (hand[rank][0] == hand[j][0]) {
                pairs++;
            }
        }
    }

    // book answer
    /* check for 4-of-a-kind, 3-of-a-kind, and pairs by
    looking for "runs" of cards with identical ranks */
    int card = 0;
    int run = 0;
    while (card < NUM_CARDS) {
    rank = hand[card][0];
    run = 0;
    do {
      run++;
      card++;
    } while (card < NUM_CARDS && hand[card][0] == rank);
    switch (run) {
      case 2: pairs++;      break;
      case 3: three = true; break;
      case 4: four = true;  break;
    }
  }

}

/*********************************************************
 * print_result: Prints the classification of the hand,  *
 *               based on the values of the external     *
 *               variables straight, flush, four, three, *
 *               and pairs.                              * 
 * *******************************************************/
void print_result(void) {
    if (straight && flush) printf("Straight flush");
    else if (four)         printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush)        printf("Flush");
    else if (straight)     printf("Straight");
    else if (three)        printf("Three of a kind");
    else if (pairs == 2)   printf("Two pairs");
    else if (pairs == 1)   printf("Pairs");
    else                   printf("High card");

    printf("\n\n");
}

/*********************************************
 * sort_rank: Sort hand array from lowerest  *
 *            to highest by rank, or by suit *
 *********************************************/
void sort_rank(int hand[][2]) {
    //if (sort_rank == NULL) sort_rank = true;

    for (int j = 0; j < NUM_CARDS; j++) {
        int temp_rank = hand[0][0];
        int temp_suit = hand[0][1];
        for (int i = 0; i < (NUM_CARDS-1); i++) {
            if (temp_rank > hand[i+1][0]) {
                hand[i][0] = hand[i+1][0];
                hand[i][1] = hand[i+1][1];
                hand[i+1][0] = temp_rank;
                hand[i+1][1] = temp_suit;
            } else {
                temp_rank = hand[i+1][0];
                temp_suit = hand[i+1][1];
            }
        }
    }

    // book answer
    /* sort cards by rank */
    int card = 0;
    int pass = 0;
    int rank, suit;
    for (pass = 1; pass < NUM_CARDS; pass++)
    for (card = 0; card < NUM_CARDS - pass; card++) {
      rank = hand[card][RANK];
      suit = hand[card][SUIT];
      if (hand[card+1][RANK] < rank) {
        hand[card][RANK] = hand[card+1][RANK];
        hand[card][SUIT] = hand[card+1][SUIT];
        hand[card+1][RANK] = rank;
        hand[card+1][SUIT] = suit;
      }
    }
}