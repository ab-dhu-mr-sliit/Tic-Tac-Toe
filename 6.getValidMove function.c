#include <stdio.h>

void getValidMove(char **board, int size, char symbol, FILE *fp) {
    int row, col;

    while (1) {
        printf("\nPlayer %c, enter your move (row and column between 0 and %d) ", symbol, size - 1);
        puts(" ");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);

        // Check if input is within bounds
        if (row < 0 || row >= size || col < 0 || col >= size) {
            printf("Invalid position! Please enter values between 0 and %d.\n", size - 1);
            logisValidMove(fp, row, col);
            continue;
        }

        // Check if cell is already occupied
        if (board[row][col] != ' ') {
            printf("Cell already taken! Choose another.\n");
            continue;
        }
        // Save Move in logFile
        logMove(fp, symbol, row, col);

        // Valid move
        board[row][col] = symbol;
        break;
    }
}