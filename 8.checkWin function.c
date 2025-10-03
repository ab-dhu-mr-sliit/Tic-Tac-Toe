int checkWin(char **board, int size, char symbol) {
    int i, j;

    // Check rows
    for (i = 0; i < size; i++) {
        int rowWin = 1;
        for (j = 0; j < size; j++) {
            if (board[i][j] != symbol) {
                rowWin = 0;
                break;
            }
        }
        if (rowWin) return 1;
    }

    // Check columns
    for (j = 0; j < size; j++) {
        int colWin = 1;
        for (i = 0; i < size; i++) {
            if (board[i][j] != symbol) {
                colWin = 0;
                break;
            }
        }
        if (colWin) return 1;
    }

    // Check main diagonal (top-left to bottom-right)
    int diag1Win = 1;
    for (i = 0; i < size; i++) {
        if (board[i][i] != symbol) {
            diag1Win = 0;
            break;
        }
    }
    if (diag1Win) return 1;

    // Check anti-diagonal (top-right to bottom-left)
    int diag2Win = 1;
    for (i = 0; i < size; i++) {
        if (board[i][size - 1 - i] != symbol) {
            diag2Win = 0;
            break;
        }
    }
    if (diag2Win) return 1;

    // No win found
    return 0;
}