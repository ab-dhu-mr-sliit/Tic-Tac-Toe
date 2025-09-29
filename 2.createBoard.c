#include <stdlib.h>

char **createBoard(int size) {
    // Allocate memory for row pointers
    char **board = malloc(size * sizeof(char *));
    if (board == NULL) {
        return NULL;  // Allocation failed
    }

    // Allocate memory for each row
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(char));
        if (board[i] == NULL) {
            // Free previously allocated rows if any allocation fails
            for (int j = 0; j < i; j++) {
                free(board[j]);
            }
            free(board);
            return NULL;
        }
    }

    return board;
}
