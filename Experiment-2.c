#include <stdio.h>
#include <string.h>

int main() {
    char string[100], pat[20], rep[20];
    char temp[100];
    char *pos;

    printf("Enter the main string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    printf("Enter the pattern: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';

    printf("Enter the replace string: ");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep, "\n")] = '\0';

    pos = strstr(string, pat);

    if (pos == NULL) {
        printf("Pattern not found\n");
        return 0;
    }

    strncpy(temp, string, pos - string);
    temp[pos - string] = '\0';

    strcat(temp, rep);

    strcat(temp, pos + strlen(pat));

    strcpy(string, temp);

    printf("Modified string: %s\n", string);

    return 0;
}
