void logisValidMove(FILE *fp, int row, int col) {
    if (fp != NULL) {
        fprintf(fp, "Invalid move attempted at (%d, %d)\n", row, col);
    } else {
        printf("Error: Log file is not open.\n");
    }
}