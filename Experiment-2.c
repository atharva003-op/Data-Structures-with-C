#include <stdio.h>

void readString(char s[])
{
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n')
        s[i++] = ch;
    s[i] = '\0';
}

void replacePattern(char str[], char pat[], char rep[])
{
    char res[100];
    int i = 0, j = 0, k, found = 0;
    int patLen = 0;

    while (pat[patLen] != '\0')
        patLen++;

    while (str[i] != '\0')
    {
        k = 0;

        while (pat[k] != '\0' && str[i + k] == pat[k])
            k++;

        if (pat[k] == '\0')
        {
            found = 1;
            k = 0;
            while (rep[k] != '\0')
                res[j++] = rep[k++];
            i += patLen;
        }
        else
        {
            res[j++] = str[i++];
        }
    }

    res[j] = '\0';

    if (found)
        printf("Modified String: %s\n", res);
    else
        printf("Pattern not found\n");
}

int main()
{
    char STR[100], PAT[50], REP[50];

    printf("Enter main string: ");
    readString(STR);

    printf("Enter pattern: ");
    readString(PAT);

    printf("Enter replacement: ");
    readString(REP);

    replacePattern(STR, PAT, REP);
    return 0;
}
