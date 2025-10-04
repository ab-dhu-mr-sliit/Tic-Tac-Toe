void logComputerWin(FILE *fp) {
    if (fp != NULL) {
        fprintf(fp, "\nComputer wins the game!\n");
    } else {
        printf("Error: Log file is not open.\n");
    }
}