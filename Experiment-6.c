#include <stdio.h>

#define MAX 10

char queue[MAX];
int front = -1;
int rear = -1;

void enqueue(char x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("Inserted: %c\n", x);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %c\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i != rear; i = (i + 1) % MAX)
        printf("%c ", queue[i]);
    printf("%c\n", queue[rear]);
}

int main() {
    int choice;
    char ch;

    while (1) {
        printf("\n--- |MENU| ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character: ");
                scanf(" %c", &ch);
                enqueue(ch);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Exited Sucessfully!");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
