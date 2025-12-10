#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DAYS_IN_WEEK 7
#define NAME_MAX 20         // including '\0'
#define DESC_MAX 100        // including '\0'

// ----------------- Struct -----------------
typedef struct {
    char *name;        // Name of the day
    int date;          // Date of the day
    char *description; // Description of the activity
} Day;

// ----------------- Utility Functions -----------------

// Flush remaining characters on the current input line
void flush_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard
    }
}

// Read a line safely into buffer, strip trailing '\n' if present
// Returns 1 on success, 0 on EOF/error
int read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) {
        return 0; // EOF or error
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0'; // remove newline
    } else {
        // input longer than buffer, flush rest of line
        flush_line();
    }
    return 1;
}

// Safe malloc with error handling (for Test Case 6)
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Read a non-empty string with max length check
void read_nonempty_string(const char *prompt, char *dest, size_t maxLen) {
    char buffer[512];

    while (1) {
        printf("%s", prompt);
        if (!read_line(buffer, sizeof(buffer))) {
            fprintf(stderr, "Error reading input. Please try again.\n");
            continue;
        }

        if (buffer[0] == '\0') {
            printf("Input cannot be empty. Please re-enter.\n");
            continue;
        }

        if (strlen(buffer) >= maxLen) {
            printf("Input too long (max %zu characters). Please re-enter.\n", maxLen - 1);
            continue;
        }

        strcpy(dest, buffer);
        break;
    }
}

// Read and validate date as integer in reasonable range (1–31)
int read_valid_date(const char *prompt) {
    char buffer[128];
    char *endptr;
    long value;

    while (1) {
        printf("%s", prompt);
        if (!read_line(buffer, sizeof(buffer))) {
            fprintf(stderr, "Error reading input. Please try again.\n");
            continue;
        }

        if (buffer[0] == '\0') {
            printf("Date cannot be empty. Please re-enter.\n");
            continue;
        }

        value = strtol(buffer, &endptr, 10);

        // Check if conversion failed or extra non-space characters exist
        if (endptr == buffer) {
            printf("Invalid input: please enter an integer value for date.\n");
            continue;
        }
        while (*endptr != '\0') {
            if (!isspace((unsigned char)*endptr)) {
                printf("Invalid input: extra non-numeric characters detected.\n");
                goto invalid;
            }
            endptr++;
        }

        if (value < 1 || value > 31) {
            printf("Invalid date: please enter a value between 1 and 31.\n");
            continue;
        }

        return (int)value;

    invalid:
        continue;
    }
}

// ----------------- Core Functions -----------------

void create(Day *week, int size) {
    for (int i = 0; i < size; i++) {
        week[i].name = (char *)safe_malloc(NAME_MAX * sizeof(char));
        week[i].description = (char *)safe_malloc(DESC_MAX * sizeof(char));
    }
}

void read_week(Day *week, int size) {
    for (int i = 0; i < size; i++) {
        printf("\n--- Enter details for day %d ---\n", i + 1);

        // Name (non-empty, length-limited; can include special chars)
        read_nonempty_string("Enter name of the day: ", week[i].name, NAME_MAX);

        // Date (validated integer)
        week[i].date = read_valid_date("Enter date (1-31): ");

        // Description (non-empty, length-limited)
        read_nonempty_string("Enter description: ", week[i].description, DESC_MAX);
    }
}

void display(const Day *week, int size) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Day: %s, Date: %d, Activity: %s\n",
               week[i].name, week[i].date, week[i].description);
    }
}

// ----------------- main -----------------

int main(void) {
    int size = DAYS_IN_WEEK;
    Day *week = (Day *)safe_malloc(size * sizeof(Day)); // Check allocation

    create(week, size);   // Allocate memory for names & descriptions
    read_week(week, size); // Read validated data from user
    display(week, size);  // Display the week's activities

    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        free(week[i].name);
        free(week[i].description);
    }
    free(week);

    return 0;
}
