/************************************************************
 * calc.c: Modified from ch10_project6_RPN, a program       *
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

int a, b;

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
    while (true) {            
        scanf(" %s", &chars);
        if (is_digit(chars[0])) {
            push(atoi(chars));               
        } else if (is_operand(chars[0])) {
            a = pop();
            b = pop();
            switch (chars[0]) {
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
            }
        } else if (chars[0] == '=') {
            print_result();
            break;
        } else {
            exit(EXIT_SUCCESS);
        }     
    }
}

void print_result(void) {
    a = pop();
    if (is_empty()) {
        printf("Value of expression: %d\n", a);
    } else {
        printf("Not enough operands in expression.\n");
        exit(EXIT_FAILURE);
    }
}