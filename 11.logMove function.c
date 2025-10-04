void logMove(FILE *fp, char symbol, int row, int col) {
    if (fp != NULL) {
        fprintf(fp, "Player %c moved to (%d, %d)\n", symbol, row, col);
    } else {
        printf("Error: Log file is not open.\n");
    }
}