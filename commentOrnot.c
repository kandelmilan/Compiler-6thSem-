#include <stdio.h>

int main() {
    char line[200], choice[10];
    int i;

    do {
        printf("Enter a line: ");

       
        for (i = 0; i < 199; i++) {
            line[i] = getchar();
        }


        if (line[0] == '/' && line[1] == '/')
            printf("Single-line comment\n");
        else if (line[0] == '/' && line[1] == '*')
            printf("Multi-line comment\n");
        else
            printf("Not a comment\n");


        printf("Do you want to exit? (yes/no): ");
        for (i = 0; i < 9; i++) {
            choice[i] = getchar();
            if (choice[i] == '\n') {
                choice[i] = '\0';
                break;
            }
        }

    } while (choice[0] == 'n' || choice[0] == 'N');

    printf("Thank you!\n");
    return 0;
}
