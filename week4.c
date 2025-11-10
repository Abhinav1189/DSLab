#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100
int st[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top < MAX_SIZE - 1) {
        st[++top] = value;
    }
}

int pop() {
    if (top != -1) {
        return st[top--];
    }
    return -1; // Indicate stack underflow
}

int evaluatepostfixExp(char exp[]) {
    int i = 0, op1, op2, value;

    while (exp[i] != '\0' && exp[i] != '\n') {
        if (isdigit(exp[i])) {
            int digit = exp[i] - '0';
            push(digit);
        } else if (exp[i] == ' ' || exp[i] == '\t') {
            // Ignore spaces and tabs
        } else {
            op2 = pop();
            op1 = pop();
            switch (exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': value = op1 / op2; break;
                case '%': value = op1 % op2; break;
                default:
                    printf("\nInvalid operator: %c\n", exp[i]);
                    return 0;
            }
            push(value);
        }
        i++;
    }
    return pop();
}

int main() {
    char expression[100];
    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    int result = evaluatepostfixExp(expression);
    printf("Result = %d\n", result);
    return 0;
}

