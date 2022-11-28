#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT2.h"


/******************************************************************
* Ch19 Project 2: This project modifies the Project 6 from        *
*                 Chapter 10. Implementing stackADT with RPN      *
*                 calculator.                                     *
******************************************************************/

#define INITIAL_STACK_SIZE (10)
#define LINE_LENGTH (100)

void stack_underflow(void);
int read_line(char str[], int n);
int evaluate_RPN_expression(const char *expression, Stack s);
bool is_digit(char c);
bool is_operand(char c);
Item get_digit(char c);

int main(void) {

    int result;
    char expression[LINE_LENGTH];
    printf("Enter a RPN expression: ");
    read_line(expression, LINE_LENGTH);

    Stack calculator_stack = create(INITIAL_STACK_SIZE);

    result = evaluate_RPN_expression(expression, calculator_stack);

    printf("Result is: %d\n", result);

    return 0;
}

int evaluate_RPN_expression(const char *expression, Stack s) {
    const char *p;
    Item num;

    for (p = expression; *p; p++) {
        if (is_digit(*p)) {
            // need a loop to get all the digits before hitting white space
            num = 0;
            while (is_digit(*p)){
                num = num*10 + get_digit(*p);
                p++;
            }
            push(s, num);
        } 
        
        if (is_operand(*p)) {
            switch (*p) {
                case '+':
                    push(s, pop(s) + pop(s));
                    break;
                case '-':
                    push(s, pop(s) - pop(s));
                    break;
                case '*':
                    push(s, pop(s) * pop(s));
                    break;
                case '/':
                    push(s, pop(s) / pop(s));
                    break;
            }
        } else if (*p == '=') {            
            num = pop(s);
            if (is_empty(s)) {
                return num;
            } else {
                stack_underflow();
            }
        } else if (*p == ' ')
            continue;
        else
            exit(EXIT_SUCCESS);
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';  // string termination
    return i;       // number of characters stored.
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

Item get_digit(char c) {
    return c - '0';
}

void stack_underflow(void) {
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}