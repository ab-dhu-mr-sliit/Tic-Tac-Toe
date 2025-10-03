#include <stdlib.h>

void freeBoard(char **board, int size) {
    // Free each row
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }

    // Free the array of row pointers
    free(board);
}
