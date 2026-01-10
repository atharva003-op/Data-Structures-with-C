#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int date;
    char *activity;
} Day;

void read(Day *week, int size) {
    for (int i = 0; i < size; i++) {
        week[i].name = (char *)malloc(20 * sizeof(char));
        week[i].activity = (char *)malloc(100 * sizeof(char));

        printf("\nEnter name of day %d: ", i + 1);
        scanf("%s", week[i].name);

        do {
            printf("Enter date (positive number): ");
            scanf("%d", &week[i].date);
        } while (week[i].date <= 0);

        printf("Enter description: ");
        scanf(" %[^\n]", week[i].activity);
    }
}

void display(Day *week, int size) {
    printf("\n--- Week's Activity Details ---\n");
    for (int i = 0; i < size; i++) {
        printf("Day: %s | Date: %d | Activity: %s\n",
             week[i].name, week[i].date, week[i].activity);
    }
}

int main() {
    int size = 7;
    Day *week = (Day *)malloc(size * sizeof(Day));

    read(week, size);
    display(week, size);

    for (int i = 0; i < size; i++) {
        free(week[i].name);
        free(week[i].activity);
    }
    free(week);
    return 0;
}
