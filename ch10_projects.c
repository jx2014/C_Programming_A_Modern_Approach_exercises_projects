#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PROJECTS (1)

    #define STACK_SIZE 100

    /* external variables */
    char contents[STACK_SIZE];
    char output_stack;
    int top = 0;

    void stack_overflow(void) {
        printf("stack overflow.\n");
        exit(EXIT_FAILURE);
    }

    void stack_underflow(void) {
        printf("stack underflow.\n");
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

    void push(char c) {
        if (is_full()) {
            stack_overflow();
        } else {
            contents[top] = c;
            top++;
        }
    }

    void pop(void) {
        if (is_empty()) {
            stack_underflow();
        } else {            
            output_stack = contents[--top];
        }
    }

    char pop2(void) {
        if (is_empty()) {
            stack_underflow();
        } else {            
            return contents[--top];
        }
    }

    void bad_bracket(void) {
        printf("Bad bracket detected.\n");
        exit(EXIT_FAILURE);
    }

    void good_bracket(void) {
        printf("All brackets have been closed correctly.\n");
        exit(EXIT_SUCCESS);
    }

    int main(void) {
        char c;
        printf("Enter brackets. ");

        while ((c = getchar()) != '\n') {
            switch (c) {
                case '(': case '{': case '[': push(c); break;
                //case ')': pop(); if (output_stack != '(') bad_bracket(); break;
                //case '}': pop(); if (output_stack != '{') bad_bracket(); break;
                //case ']': pop(); if (output_stack != '[') bad_bracket(); break;
                case ')': if (pop2() != '(') bad_bracket(); break;
                case '}': if (pop2() != '{') bad_bracket(); break;
                case ']': if (pop2() != '[') bad_bracket(); break;                                    
            }
        }
        if (!is_empty) {
            bad_bracket();
        } else {
            good_bracket();
        }

        return 0;
    }
