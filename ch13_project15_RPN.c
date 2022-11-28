/************************************************************
 *                                                          *
 * Orignal: ch10_project6_RPN.c                             *
 * ch13_project15_RPN.c: a program to emulate calculator    *
 *                       using Reverse Polish Notation      *
 *                                                          * 
 * **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10

/* external variables */
int rpn[STACK_SIZE] = {0};
int output_stack;
int top = 0;

void stack_overflow(void);
void stack_underflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
void pop(void);
bool is_digit(char c);
bool is_operand(char c);
int get_digit(char c);
//void parse_expression(void);
//void print_result(void);
int evaluate_RPN_expression(const char *expression);
int read_line(char str[], int n);

int main(void) {    
    char RPN_expression[100];
    int result;

    while (true) {
        printf("Enter an RPN expression: ");
        read_line(RPN_expression, 101);
        result = evaluate_RPN_expression(RPN_expression);
        printf("Value of expression: %d\n", result);
        make_empty();
    }    
    return 0;
}

void stack_overflow(void) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return (top == 0);
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full()) {
        stack_overflow();
    } else {
        rpn[top] = i;
        top++;
    }
}

void pop(void) {
    if (is_empty()) {
        stack_underflow();
    } else {            
        output_stack = rpn[--top];
    }
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

int get_digit(char c) {
    return c - '0';
}

int evaluate_RPN_expression(const char *expression) {
    const char *p;
    int top_stack = 0;    

    for (p = expression; *p; p++) {
        if (is_digit(*p)) {
            push(get_digit(*p));
        } else if (is_operand(*p)) {
            pop();
            top_stack = output_stack;
            pop();
            switch (*p) {
                case '+':
                    push(output_stack + top_stack);
                    break;
                case '-':
                    push(output_stack - top_stack);
                    break;
                case '*':
                    push(output_stack * top_stack);
                    break;
                case '/':
                    push(output_stack / top_stack);
                    break;
            }
        } else if (*p == '=') {            
            pop();
            if (is_empty()) {
                return output_stack;
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