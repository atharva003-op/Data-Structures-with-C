#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term {
    int c, x, y, z;
    struct Term *next;
} Term;

Term* newTerm(int c, int x, int y, int z) {
    Term *t = (Term*)malloc(sizeof(Term));
    t->c = c;
    t->x = x;
    t->y = y;
    t->z = z;
    t->next = t;   
    return t;
}

void insert(Term **head, int c, int x, int y, int z) {
    Term *t = newTerm(c, x, y, z);

    if (*head == NULL) {
        *head = t;
        return;
    }

    Term *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = t;
    t->next = *head;
}

double evaluate(Term *head, double x, double y, double z) {
    double sum = 0;
    if (!head) return sum;

    Term *temp = head;
    do {
        sum += temp->c * pow(x, temp->x) * pow(y, temp->y) * pow(z, temp->z);
        temp = temp->next;
    } while (temp != head);

    return sum;
}

Term* add(Term *p1, Term *p2) {
    if (!p1) return p2;
    if (!p2) return p1;

    Term *sum = NULL;
    Term *t1 = p1, *t2 = p2;

    do {
        insert(&sum, t1->c + t2->c, t1->x, t1->y, t1->z);
        t1 = t1->next;
        t2 = t2->next;
    } while (t1 != p1 && t2 != p2);

    return sum;
}

void display(Term *head) {
    if (!head) {
        printf("0\n");
        return;
    }

    Term *temp = head;
    do {
        printf("%+dx^%dy^%dz ", temp->c, temp->x, temp->y, temp->z);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Term *p1 = NULL, *p2 = NULL, *sum = NULL;
    int n, c, x, y, z;
    double vx, vy, vz;

    printf("Enter number of terms for POLY1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &c, &x, &y, &z);
        insert(&p1, c, x, y, z);
    }

    printf("Enter number of terms for POLY2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &c, &x, &y, &z);
        insert(&p2, c, x, y, z);
    }

    sum = add(p1, p2);

    printf("Enter x y z to evaluate POLY1: ");
    scanf("%lf %lf %lf", &vx, &vy, &vz);
    printf("POLY1 = %lf\n", evaluate(p1, vx, vy, vz));

    printf("POLYSUM = ");
    display(sum);

    return 0;
}
