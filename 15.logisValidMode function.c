void logisValidMode(FILE *fp, int mode) {
    if (fp != NULL) {
        fprintf(fp, "Invalid game mode selected: %d\nExiting", mode);
    } else {
        printf("Error: Log file is not open.\n");
    }
}