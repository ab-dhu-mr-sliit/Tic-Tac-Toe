void logWins(FILE *fp, char symbols) {
    if (fp != NULL) {
        fprintf(fp, "\nPlayer %c wins the game!\n", symbols);
    } else {
        printf("Error: Log file is not open.\n");
    }
}