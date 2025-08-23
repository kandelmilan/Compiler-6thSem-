//Write a program to test whether given identifier is valid or not 
#include <stdio.h>
#include <string.h> 


int isKeyword(char word[]) {
    char *keywords[] = {
        "int","break","case","char","const","continue","while","do",
        "double","else","enum","if","float","for"
    };
    int totalKeywords = 14;

    for (int i = 0; i < totalKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1; 
    }
    return 0; 
}

int main() {
    char id[100], choice[10];
    int valid, i;

    do {
        printf("Enter an identifier: ");
        scanf("%s", id);

        valid = 1; 


        if (!((id[0] >= 'a' && id[0] <= 'z') ||
              (id[0] >= 'A' && id[0] <= 'Z') ||
              (id[0] == '_'))) {
            valid = 0;
        }


        for (i = 1; id[i] != '\0'; i++) {
            if (!((id[i] >= 'a' && id[i] <= 'z') ||
                  (id[i] >= 'A' && id[i] <= 'Z') ||
                  (id[i] >= '0' && id[i] <= '9') ||
                  (id[i] == '_'))) {
                valid = 0;
                break;
            }
        }

        // Rule 3: must not be a keyword from the list
        if (isKeyword(id)) {
            valid = 0;
            printf("Invalid identifier (keyword)\n");
        } else if (valid) {
            printf("Valid identifier\n");
        } else {
            printf("Invalid identifier\n");
        }

        // Ask user whether to continue
        printf("Do you want to test another identifier? (yes/no): ");
        scanf("%s", choice);

    } while (choice[0] == 'y' || choice[0] == 'Y');

    printf("Thank you!\n");
    return 0;
}
