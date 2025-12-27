#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

struct Stack {
    int top;
    unsigned capacity;
    char array[MAX];
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("Pushed to stack: %c\n", item);
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = stack->top; i >= 0; i--)
        printf("%c\n", stack->array[i]);
}

bool isPalindrome(char str[], struct Stack* stack) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }

    for (int i = 0; i < length; i++) {
        if (str[i] != pop(stack))
            return false;
    }

    return true;
}

int main() {
    struct Stack* stack = createStack(MAX);
    int choice;
    char item;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Display top element\n");
        printf("4. Display all stack elements\n");
        printf("5. Check if a number is a palindrome\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push: ");
                scanf(" %c", &item); // Note the space before %c
                push(stack, item);
                break;
            case 2:
                item = pop(stack);
                if (item != -1)
                    printf("Popped from stack: %c\n", item);
                break;
            case 3:
                item = peek(stack);
                if (item != -1)
                    printf("Top element is: %c\n", item);
                break;
            case 4:
                display(stack);
                break;
            case 5: {
                char number[100];
                printf("Enter a number: ");
                scanf("%s", number);
                if (isPalindrome(number, stack))
                    printf("The number is a palindrome.\n");
                else
                    printf("The number is not a palindrome.\n");
                break;
            }
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
