int main() {
    int mode, size;
    // Open log file
    FILE *fp = fopen("tic tac toe V7.txt", "w");
    if (fp == NULL) {
        printf("Failed to open log file.\n");
        return 1;
    }
    fprintf(fp, "Log file opened successfully.\n\n");
    fprintf(fp, "Welcome to Tic-Tac-Toe!\n\n");
    fprintf(fp, "In this version  \n1. tryAgain function\n2. exit function\n");
    
    printf("Welcome to Tic-Tac-Toe!\n\n");
    exitGame(fp);
    mode = tryMode(fp);
    exitGame(fp);
    size = trySize(fp);
    
    // Create and initialize board
    char **board = createBoard(size);
    if (board == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    initializeBoard(board, size);
    
    if (mode == 1) {
        // Two-player mode
        char symbols[2] = {'X', 'O'};
        int currentTurn = 0;
        
        while (1) {
            printf("%d x %d Grid (Two-Player)\n", size, size);
            displayBoard(board, size);
            logdisplayBoard(fp, board, size);
            getValidMove(board, size, symbols[currentTurn], fp);
            
            if (checkWin(board, size, symbols[currentTurn])) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nPlayer %c wins!\n", symbols[currentTurn]);
                logWins(fp, symbols[currentTurn]);
                break;
            }
            
            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nIt's a draw!\n");
                break;
            }
            system(CLEAR); // Clear the console (Windows-specific)
            currentTurn = switchPlayer(currentTurn, 2);
        }
        
    } else if (mode == 2) {
        // User vs Computer
        char userSymbol = 'X';
        char computerSymbol = 'O';
        int row, col;
        
        // Seed random number generator for computer moves
        srand(time(NULL));
        while (1) {
            printf("%d x %d Grid (User vs Computer)\n", size, size);
            displayBoard(board, size);
            logdisplayBoard(fp, board, size);
            getValidMove(board, size, userSymbol, fp);

            if (checkWin(board, size, userSymbol)) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nYou win!\n");
                logWins(fp, userSymbol);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nIt's a draw!\n");
                break;
            }
            generateRandomMove(board, size, &row, &col);
            board[row][col] = computerSymbol;
            printf("\nComputer placed at (%d, %d)\n", row, col);
            logMove(fp, computerSymbol, row, col);

            if (checkWin(board, size, computerSymbol)) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nComputer wins!\n");
                logComputerWin(fp);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nIt's a draw!\n");
                break;
            }
        }

    } else {
        // Multi-player mode
        char symbols[3] = {'X', 'O', 'Z'};
        int currentTurn = 0;

        while (1) {
            printf("%d x %d Grid (Multi-Player)\n", size, size);
            displayBoard(board, size);
            logdisplayBoard(fp, board, size);
            printf("\nPlayer %c's turn.\n", symbols[currentTurn]);
            getValidMove(board, size, symbols[currentTurn], fp);

            if (checkWin(board, size, symbols[currentTurn])) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nPlayer %c wins!\n", symbols[currentTurn]);
                logWins(fp, symbols[currentTurn]);
                break;
            }

            if (isBoardFull(board, size)) {
                displayBoard(board, size);
                logdisplayBoard(fp, board, size);
                printf("\nIt's a draw!\n");
                break;
            }
            system(CLEAR); // Clear the console (Windows-specific)
            currentTurn = switchPlayer(currentTurn, 3);
        }
    }

    fprintf(fp, "\nGame Over. Closing log file.\n");
    fclose(fp);
    freeBoard(board, size);
    printf("Thanks for playing!\n");
    tryAgain();
    system(PAUSE);
    return 0;
}
