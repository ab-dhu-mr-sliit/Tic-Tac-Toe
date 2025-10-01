#include <stdio.h>

void displayBoard(char **board, int size) {
    puts(" ");
    printf(" ");
    for(int i = 0; i < size; i++){
        printf("   %d", i);
    }
    printf("\n\n");
    for (int i = 0; i < size; i++) {
        printf("%d  ", i);
        // Print each row
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]);
            if (j < size - 1) printf("|");
        }
        printf("\n");
        printf("   ");

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
