#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROD 10
#define MAX_LEN 20

char production[MAX_PROD][MAX_LEN];
int num_prod;

void eliminateLeftRecursion() {
    int i, j;
    char alpha[MAX_LEN], beta[MAX_LEN];

    for (i = 0; i < num_prod; i++) {
        for (j = 0; j < i; j++) {
            if (production[i][0] == production[j][0]) {
                strcpy(alpha, "");
                strcpy(beta, "");

                int k = 3;
                while (production[i][k] != '|' && production[i][k] != '\0') {
                    strncat(alpha, &production[i][k], 1);
                    k++;
                }

                k = 3;
                while (production[j][k] != '|' && production[j][k] != '\0') {
                    strncat(beta, &production[j][k], 1);
                    k++;
                }

                printf("%c -> %s%s'\n", production[i][0], beta, production[i][0]);
                printf("%c' -> %s%s' | e\n", production[i][0], alpha, production[i][0]);
            }
            else {
                printf("%s\n", production[i]);
            }
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &num_prod);

    printf("Enter the productions:\n");
    int i;
    for (i = 0; i < num_prod; i++) {
        scanf("%s", production[i]);
    }

    printf("Productions after eliminating left recursion:\n");
    eliminateLeftRecursion();

    return 0;
}

