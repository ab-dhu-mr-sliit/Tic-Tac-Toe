void logMode(FILE *fp, int mode) {
    if (fp != NULL) {
        fprintf(fp, "Game mode selected: %d\n", mode);
    } else {
        printf("Error: Log file is not open.\n");
    }
}