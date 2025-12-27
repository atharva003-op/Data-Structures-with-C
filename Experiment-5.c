#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct Stack {
    int top;
    int *arr;
};

struct Stack* createStack() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    s->arr = (int*)malloc(MAX * sizeof(int));
    return s;
}

void push(struct Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

int evaluatePostfix(char exp[]) {
    int i, a, b;
    struct Stack *s = createStack();

    for (i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            push(s, exp[i] - '0');
        } 
        else {
            if (s->top < 1) {
                printf("Error: Invalid postfix expression (insufficient operands)\n");
                free(s->arr);
                free(s);
                return -1;
            }

            a = pop(s);
            b = pop(s);

            switch (exp[i]) {
                case '+': push(s, b + a); break;
                case '-': push(s, b - a); break;
                case '*': push(s, b * a); break;
                case '/': 
                    if (a == 0) {
                        printf("Error: Division by zero\n");
                        free(s->arr);
                        free(s);
                        return -1;
                    }
                    push(s, b / a);
                    break;
                case '%': push(s, b % a); break;
                case '^': push(s, pow(b, a)); break;
                default:
                    printf("Error: Invalid operator\n");
                    free(s->arr);
                    free(s);
                    return -1;
            }
        }
    }

    if (s->top != 0) {
        printf("Error: Invalid postfix expression\n");
        free(s->arr);
        free(s);
        return -1;
    }

    a = pop(s);
    free(s->arr);
    free(s);
    return a;
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int choice, n, result;
    char postfix[MAX];

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Tower of Hanoi\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                result = evaluatePostfix(postfix);
                if (result != -1)
                    printf("Result = %d\n", result);
                break;

            case 2:
                printf("Enter number of disks: ");
                scanf("%d", &n);
                towerOfHanoi(n, 'A', 'C', 'B');
                break;

            case 3:
                printf("Program exited.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
