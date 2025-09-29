#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  

int main() {
    int mode, size;

    // Seed random number generator for computer moves
    srand(time(NULL));

    printf("Welcome to Tic-Tac-Toe!\n\n");
    printf("Select Game Mode:\n\n");
    printf("1. Two-Player (User vs User)\n");
    printf("2. User vs Computer\n");
    printf("3. Multi-Player (3 Players)\n");
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &mode);

    if (mode < 1 || mode > 3) {
        printf("Invalid mode selected. Exiting...\n");
        return 1;
    }

    printf("\nEnter grid size (3 to 10): ");
    scanf("%d", &size);
    puts(" ");
    if (size < 3 || size > 10) {
        printf("Invalid grid size. Exiting...\n");
        return 1;
    }

    // Create and initialize board
    char **board = createBoard(size);
    if (board == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    initializeBoard(board, size);

    // Open log file
    FILE *fp = fopen("game_log.txt", "w");
    fprintf(fp, "Log file opened successfully.\n\n");
    if (fp == NULL) {
        printf("Failed to open log file.\n");
        freeBoard(board, size);
        return 1;
    }

    if (mode == 1) {
        // Two-player mode
        char symbols[2] = {'X', 'O'};
        int currentTurn = 0;

        while (1) {
            printf("%d x %d Grid\n", size, size);
            displayBoard(board, size);
            getValidMove(board, size, symbols[currentTurn], fp);

            if (checkWin(board, size, symbols[currentTurn])) {
                displayBoard(board, size);
                printf("\nPlayer %c wins!\n", symbols[currentTurn]);
                logWins(fp, symbols[currentTurn]);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                printf("\nIt's a draw!\n");
                break;
            }
            system("cls"); // Clear the console (Windows-specific)
            currentTurn = switchPlayer(currentTurn, 2);
        }

    } else if (mode == 2) {
        // User vs Computer
        char userSymbol = 'X';
        char computerSymbol = 'O';
        int row, col;

        while (1) {
            printf("%d x %d Grid\n", size, size);
            displayBoard(board, size);
            getValidMove(board, size, userSymbol, fp);

            if (checkWin(board, size, userSymbol)) {
                displayBoard(board, size);
                printf("\nYou win!\n");
                logWins(fp, userSymbol);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                printf("\nIt's a draw!\n");
                break;
            }
            generateRandomMove(board, size, &row, &col);
            board[row][col] = computerSymbol;
            printf("\nComputer placed at (%d, %d)\n", row, col);
            logMove(fp, computerSymbol, row, col);

            if (checkWin(board, size, computerSymbol)) {
                displayBoard(board, size);
                printf("\nComputer wins!\n");
                logWins(fp, computerSymbol);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                printf("\nIt's a draw!\n");
                break;
            }
        }

    } else {
        // Multi-player mode
        char symbols[3] = {'X', 'Y', 'Z'};
        int currentTurn = 0;

        while (1) {
            printf("%d x %d Grid\n", size, size);
            displayBoard(board, size);
            printf("\nPlayer %c's turn.\n", symbols[currentTurn]);
            getValidMove(board, size, symbols[currentTurn], fp);

            if (checkWin(board, size, symbols[currentTurn])) {
                displayBoard(board, size);
                printf("\nPlayer %c wins!\n", symbols[currentTurn]);
                logWins(fp, symbols[currentTurn]);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                printf("\nIt's a draw!\n");
                break;
            }
            system("cls"); // Clear the console (Windows-specific)
            currentTurn = switchPlayer(currentTurn, 3);
        }
    }

    fclose(fp);
    freeBoard(board, size);
    printf("Thanks for playing!\n");
    return 0;
}