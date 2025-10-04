void logdisplayBoard(FILE *fp, char **board, int size) {
    if (fp != NULL) {
        fprintf(fp, "\nCurrent Board State:\n\n");
        for(int i = 0; i < size; i++){
        fprintf(fp, "   %d", i);
        }
        fprintf(fp, "\n\n");
        for (int i = 0; i < size; i++) {
        fprintf(fp, "%d  ", i);
            // Print each row
            for (int j = 0; j < size; j++) {
                fprintf(fp, " %c ", board[i][j]);
                if (j < size - 1) fprintf(fp, "|");
            }
            fprintf(fp, "\n");
            fprintf(fp, "   ");

        // Print horizontal separator between rows
            if (i < size - 1) {
                for (int j = 0; j < size; j++) {
                    fprintf(fp, "---");
                if (j < size - 1) fprintf(fp, "+");
                }
                fprintf(fp, "\n");
            }
        }
        fprintf(fp, "\n");
    }
     else {
        printf("Error: Log file is not open.\n");
    }
}
