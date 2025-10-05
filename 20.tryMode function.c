int tryMode(FILE *fp) {
    int mode;
    while (1) {
        printf("Select Game Mode:\n\n");
        printf("1. Two-Player (User vs User)\n");
        printf("2. User vs Computer\n");
        printf("3. Multi-Player (3 Players)\n\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &mode);
        logMode(fp, mode);

        if (mode >= 1 && mode <= 3) {
            return mode;
        } else {
            printf("Invalid mode selected. Try again.\n\n");
            logisValidMode(fp, mode);
        }
    }
}