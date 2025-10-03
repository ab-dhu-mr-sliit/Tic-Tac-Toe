int isBoardFull(char **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Found an empty cell → board is not full
            }
        }
    }
    return 1;  // No empty cells → board is full
}