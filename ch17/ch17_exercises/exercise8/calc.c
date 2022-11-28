/************************************************************
 * calc.c: Ch17, exercise 8.                                *
 *         Modified from ch15 project2 calc, a program      *
 *         to emulate calculator using Reverse Polish       *
 *         Notation.                                        *
 * **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool is_digit(char c);
bool is_operand(char c);
void parse_expression(void);
void print_result(void);

int main(void) {

    while (true) {
        make_empty();
        printf("Enter an RPN expression: ");
        parse_expression();
    }    
    return 0;
}


bool is_digit(char c) {
    if ( c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

bool is_operand(char c) {
    if ( c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else {
        return false;
    }
}

void parse_expression(void) {
    char chars[100];
    int a, b, r;
    while (true) {
        scanf(" %s", &chars);
        if (is_digit(chars[0])) {
            r = push(atoi(chars));
        } else if (is_operand(chars[0])) {

            if (is_empty()) {
                printf("Not enough value in expression.\n");
                break;
            } else
                a = pop();
            
            if (is_empty()) {
                printf("Not enough value in expression.\n");
                break;
            } else
                b = pop();         

            switch (chars[0]) {
                case '+':
                    r = push(b + a);
                    break;
                case '-':
                    r = push(b - a);
                    break;
                case '*':
                    r = push(b * a);
                    break;
                case '/':
                    r = push(b / a);
                    break;
            }
        } else if (chars[0] == '=') {
            print_result();
            break;
        } else if (chars[0] == 'q' || chars[0] == 'Q') {
            printf("Good bye.\n");
            exit(EXIT_SUCCESS);        
        } else {
            printf("Unknown character.\n");
            break;
        }
        if (!r) { // failed to push number into new node
            printf("Failed to push item into new node");
            exit(EXIT_FAILURE);
        }
    }    
}

void print_result(void) {
    int a = pop();
    if (is_empty()) {
        printf("Value of expression: %d\n", a);
    } else {
        printf("Expresion has left over values.\n");
    }
}