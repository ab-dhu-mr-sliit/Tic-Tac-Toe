#include <stdio.h>

void displayBoard(char **board, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        // Print each row
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]);
            if (j < size - 1) printf("|");
        }
        printf("\n");

        // Print horizontal separator between rows
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                printf("---");
                if (j < size - 1) printf("+");
            }
            printf("\n");
        }
    }
}