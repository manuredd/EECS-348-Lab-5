// Manu Redd
// 3105946
// EECS 348
// Lab 05
// Oct 15 2023


#include <stdio.h>

void calculateScoringCombinations(int score) {
    printf("possible combinations of scoring plays:\n");
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
        for (int td1ptfg = 0; td1ptfg * 7 <= score; td1ptfg++) {
            for (int td = 0; td * 6 <= score; td++) {
                for (int fg = 0; fg * 3 <= score; fg++) {
                    for (int safety = 0; safety * 2 <= score; safety++) {
                        int totalScore = (td * 6) + (fg * 3) + (safety * 2) + (td2pt * 8) + (td1ptfg * 7);
                        if (totalScore == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1ptfg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        printf("Sample Output if score is %d:\n", score);
        calculateScoringCombinations(score);
    }
    return 0;
}
