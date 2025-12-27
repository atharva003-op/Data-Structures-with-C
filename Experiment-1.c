#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int date;
    char *description;
} Day;

void read(Day *week, int size) {
    for (int i = 0; i < size; i++) {
        week[i].name = (char *)malloc(20 * sizeof(char));
        week[i].description = (char *)malloc(100 * sizeof(char));

        printf("\nEnter name of day %d: ", i + 1);
        scanf("%19s", week[i].name);

        while (1) {
            printf("Enter date (positive number): ");
            if (scanf("%d", &week[i].date) != 1 || week[i].date <= 0) {
                printf("Invalid date! Please enter a positive number.\n");
                while (getchar() != '\n');  // clear input buffer
            } else {
                break;
            }
        }

        printf("Enter description: ");
        scanf(" %[^\n]", week[i].description);
    }
}

void display(Day *week, int size) {
    printf("\n--- Week's Activity Details ---\n");
    for (int i = 0; i < size; i++) {
        printf("Day: %s | Date: %d | Activity: %s\n",
               week[i].name, week[i].date, week[i].description);
    }
}

int main() {
    int size = 7;
    Day *week = (Day *)malloc(size * sizeof(Day));

    read(week, size);
    display(week, size);

    for (int i = 0; i < size; i++) {
        free(week[i].name);
        free(week[i].description);
    }
    free(week);

    return 0;
}
