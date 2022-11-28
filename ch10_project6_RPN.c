/************************************************************
 *                                                          *
 * ch10_project6_RPN.c: a program to emulate calculator     *
 *                      using Reverse Polish Notation       *
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
void parse_expression(void);
void print_result(void);


int main(void) {    

    while (true) {
        printf("Enter an RPN expression: ");
        parse_expression();
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

void parse_expression(void) {
    char ch = 0;
    int top_stack = 0;
    while (true) {            
        scanf(" %c", &ch);
        //printf("%c\n", ch);
        if (is_digit(ch)) {
            push(get_digit(ch));
        } else if (is_operand(ch)) {
            pop();
            top_stack = output_stack;
            pop();
            switch (ch) {
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
        } else if (ch == '=') {
            print_result();
            break;
        } else {
            exit(EXIT_SUCCESS);
        }     
    }
}

void print_result(void) {
    pop();
    if (is_empty()) {
        printf("Value of expression: %d\n", output_stack);
    } else {
        stack_underflow();
    }
}