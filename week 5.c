#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    
    }
}

// Pop function
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1; // Stack empty
}

// Peek function
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1; // Stack empty
}

// Function to define operator precedence
int precedence(char op) {
    switch (op) {
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Infix to postfix conversion function
void infix_to_postfix(char infix[], char postfix[]) {
    int i, k = 0;
    char symbol;
    int len = strlen(infix);

    for (i = 0; i < len; i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            // If operand, add to postfix expression
            postfix[k++] = symbol;
        } else if (symbol == '(') {
            // Push '(' onto stack
            push(symbol);
        } else if (symbol == ')') {
            // Pop until '(' is found
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        } else if (isoperator(symbol)) {
            // Pop operators with higher or equal precedence
            while (top != -1 && precedence(peek()) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }
    // Pop all remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';  // Null terminate string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

