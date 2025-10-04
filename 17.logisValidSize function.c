void logisValidSize(FILE *fp, int size) {
    if (fp != NULL) {
        fprintf(fp, "Invalid grid size selected: %d\nExiting", size);
    } else {
        printf("Error: Log file is not open.\n");
    }
}