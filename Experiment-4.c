#include <stdio.h>
#include <ctype.h>

#define MAX 100

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1, i = 0, k = 0;

    while (infix[i] != '\0') {

        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
    
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--; 
        }
        
        else {
            while (top != -1 && priority(infix[i]) <= priority(stack[top]))
                postfix[k++] = stack[top--];
            stack[++top] = infix[i];
        }
        i++;
    }

    while (top != -1)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
