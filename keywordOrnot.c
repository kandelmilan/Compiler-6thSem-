
#include <stdio.h>
#include <string.h>

int main() {
    char word[50];
    char choice;
    int i, isKeyword;

    // List of C keywords
    const char *keywords[] = {
       "int","break","case","char","const","continue","while","do",
        "double","else","enum","if","float","for"
    };
    int keywordCount = 15;

    do {
        printf("Enter a word: ");
        scanf("%s", word);

        isKeyword = 0;
        for (i = 0; i < keywordCount; i++) {
            if (strcmp(word, keywords[i]) == 0) {
                isKeyword = 1;
                break;
            }
        }

        if (isKeyword)
            printf("'%s' is a C keyword.\n", word);
        else
            printf("'%s' is NOT a C keyword.\n", word);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program ended.\n");
    return 0;
}