#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char USN[15], Name[50], Programme[50], PhNo[15];
    int Sem;
    struct Student *next;
} Student;

Student* createStudent() {
    Student *s = (Student*)malloc(sizeof(Student));

    printf("Enter USN: ");
    scanf("%s", s->USN);
    printf("Enter Name: ");
    scanf("%s", s->Name);
    printf("Enter Programme: ");
    scanf("%s", s->Programme);
    printf("Enter Semester: ");
    scanf("%d", &s->Sem);
    printf("Enter Phone Number: ");
    scanf("%s", s->PhNo);

    s->next = NULL;
    return s;
}

void insertFront(Student **head) {
    Student *s = createStudent();
    s->next = *head;
    *head = s;
}

void insertEnd(Student **head) {
    Student *s = createStudent();

    if (*head == NULL) {
        *head = s;
        return;
    }

    Student *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = s;
}

void deleteFront(Student **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Student *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteEnd(Student **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Student *temp = *head;
    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void display(Student *head) {
    int count = 0;

    if (!head) {
        printf("List is empty\n");
        return;
    }

    while (head) {
        printf("USN : %s | Name : %s | Prog : %s | Sem : %d | Phone : %s\n",
               head->USN, head->Name, head->Programme, head->Sem, head->PhNo);
        head = head->next;
        count++;
    }
    printf("Total Students: %d\n", count);
}

int main() {
    Student *head = NULL;
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert Front\n");
        printf("2. Display\n");
        printf("3. Insert End\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFront(&head); break;
            case 2: display(head); break;
            case 3: insertEnd(&head); break;
            case 4: deleteFront(&head); break;
            case 5: deleteEnd(&head); break;
            case 6: printf("Exited program sucessfully!!"); return 0;
            default: printf("Invalid choice\n");
        }
    }
}
