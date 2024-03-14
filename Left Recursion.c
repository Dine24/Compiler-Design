#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 10 // Maximum number of productions
#define MAX_LEN 20  // Maximum length of a production

void eliminateLeftRecursion(char productions[MAX_PROD][MAX_LEN], int numProd) {
    char alpha[MAX_PROD][MAX_LEN], beta[MAX_PROD][MAX_LEN];
    int alphaCount = 0, betaCount = 0;
    int i, j;

    for (i = 0; i < numProd; i++) {
        if (productions[i][0] == productions[i][3]) {
            strcpy(alpha[alphaCount], &productions[i][4]);
            alpha[alphaCount][strlen(alpha[alphaCount]) - 1] = '\0'; // Remove the right recursion
            alphaCount++;
        } else {
            strcpy(beta[betaCount], productions[i]);
            betaCount++;
        }
    }

    if (alphaCount == 0) {
        printf("No left recursion found.\n");
        return;
    }

    printf("Transformed productions:\n");
    for (i = 0; i < betaCount; i++) {
        printf("%s\n", beta[i]);
        for (j = 0; j < alphaCount; j++) {
            printf("%s%s'\n", beta[i], alpha[j]);
        }
    }
    // Add epsilon production for the non-terminal symbols
    for (i = 0; i < alphaCount; i++) {
        printf("%s' -> epsilon\n", alpha[i]);
    }
}

int main() {
    int numProd, i;
    char productions[MAX_PROD][MAX_LEN];

    printf("Enter the number of productions: ");
    scanf("%d", &numProd);

    printf("Enter the production rules:\n");
    for (i = 0; i < numProd; i++) {
        scanf("%s", productions[i]);
    }

    eliminateLeftRecursion(productions, numProd);

    return 0;
}
