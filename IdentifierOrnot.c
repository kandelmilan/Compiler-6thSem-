#include <stdio.h>
#include <string.h>
#include <ctype.h> // for isalpha, isdigit

// Function to check if a word is a C keyword
int isKeyword(char word[])
{
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"};
    int totalKeywords = 32; // total keywords in the array

    for (int i = 0; i < totalKeywords; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1; // it's a keyword
    }
    return 0; // not a keyword
}

int main()
{
    char id[100], choice[10];
    int valid, i;

    do
    {
        printf("Enter an identifier: ");
        scanf("%s", id);

        valid = 1;

        // Rule 1: first character must be a letter or underscore
        if (!(isalpha(id[0]) || id[0] == '_'))
        {
            valid = 0;
        }

        // Rule 2: remaining characters must be letters, digits, or underscore
        for (i = 1; id[i] != '\0'; i++)
        {
            if (!(isalnum(id[i]) || id[i] == '_'))
            {
                valid = 0;
                break;
            }
        }

        // Rule 3: must not be a keyword
        if (isKeyword(id))
        {
            valid = 0;
            printf("Invalid identifier (keyword)\n");
        }
        else if (valid)
        {
            printf("Valid identifier\n");
        }
        else
        {
            printf("Invalid identifier\n");
        }

        // Ask user whether to continue
        printf("Do you want to test another identifier? (yes/no): ");
        scanf("%s", choice);

    } while (choice[0] == 'y' || choice[0] == 'N');

    printf("Thank you!\n");
    return 0;
}
