#include <stdio.h>

// Define all possibile scoring plays and assign point values to them
int plays[] = {8, 7, 6, 3, 2};
char *playNames[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};

// Recursive function that finds all possible combinations of plays to reach a provided score
void findCombinations(int score, int index, int combination[]) {
    // Base case: if score is 0, print the current combination
    if (score == 0) {
        for (int i = 0; i < 5; i++) {
            if (combination[i] > 0) {
                printf("%d %s%s", combination[i], playNames[i], (i < 4) ? ", " : "");
            }
        }
        printf("\n");
        return;
    }

    // If score is negative or there are no more plays to try: return
    if (score < 0 || index >= 5) {
        return;
    }

    // Include current play and recurse the function
    combination[index]++;
    findCombinations(score - plays[index], index, combination);

    combination[index]--;  // Backtrack

    // Recurse using the next play
    findCombinations(score, index + 1, combination);
}

int main() {
    // handles user i/o and begins the recursion
    int score;

    while (1) {
        printf("Enter a possible NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score < 2) {
            break;
        }

        int combination[5] = {0};  // Store counts of each play
        printf("Combinations to achieve %d points:\n", score);
        findCombinations(score, 0, combination);
    }

    return 0;
}