#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    char ssn[20], name[50], dept[30], designation[30], phNo[15];
    double salary;
    struct Employee *prev, *next;
} Employee;

Employee* createEmployee() {
    Employee* e = (Employee*)malloc(sizeof(Employee));

    printf("Enter SSN: ");
    scanf("%s", e->ssn);
    printf("Enter Name: ");
    scanf("%s", e->name);
    printf("Enter Department: ");
    scanf("%s", e->dept);
    printf("Enter Designation: ");
    scanf("%s", e->designation);
    printf("Enter Salary: ");
    scanf("%lf", &e->salary);
    printf("Enter Phone Number: ");
    scanf("%s", e->phNo);

    e->prev = e->next = NULL;
    return e;
}

Employee* insertEnd(Employee* head) {
    Employee* newNode = createEmployee();
    if (!head) return newNode;

    Employee* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Employee* insertFront(Employee* head) {
    Employee* newNode = createEmployee();
    if (head)
        head->prev = newNode;

    newNode->next = head;
    return newNode;
}

Employee* deleteEnd(Employee* head) {
    if (!head) {
        printf("List is empty!\n");
        return NULL;
    }

    if (!head->next) {
        free(head);
        return NULL;
    }

    Employee* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    return head;
}

Employee* deleteFront(Employee* head) {
    if (!head) {
        printf("List is empty!\n");
        return NULL;
    }

    Employee* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

void display(Employee* head) {
    if (!head) {
        printf("List is empty!\n");
        return;
    }

    while (head) {
        printf("SSN : %s | Name : %s | Dept : %s | Designation : %s | Salary : %.2lf | Phone : %s\n",
               head->ssn, head->name, head->dept,
               head->designation, head->salary, head->phNo);
        head = head->next;
    }
}

int count(Employee* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

int main() {
    Employee* head = NULL;
    int choice;

    while (1) {
        printf("\n--- |Menu| ---\n");
        printf("1. Insert Employee at End\n");
        printf("2. Insert Employee at Front\n");
        printf("3. Display Employees\n");
        printf("4. Count Employees\n");
        printf("5. Delete Employee at End\n");
        printf("6. Delete Employee at Front\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = insertEnd(head); break;
            case 2: head = insertFront(head); break;
            case 3: display(head); break;
            case 4: printf("Total Employees: %d\n", count(head)); break;
            case 5: head = deleteEnd(head); break;
            case 6: head = deleteFront(head); break;
            case 7: printf("Exited sucessfully!!"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
