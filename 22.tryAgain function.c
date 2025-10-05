int tryMode(FILE *fp) {
    int mode;
    char input[100];
    while (1) {
        printf("Select Game Mode:\n\n");
        printf("1. Two-Player (User vs User)\n");
        printf("2. User vs Computer\n");
        printf("3. Multi-Player (3 Players)\n\n");
        printf("Enter your choice (1-3): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &mode) == 1){
            if (mode >= 1 && mode <= 3) {
                logMode(fp, mode);
                return mode;
            } else {
                printf("Invalid mode selected. Try again.\n\n");
                logisValidMode(fp, mode);
            } 
        }
        else {
            printf("\nInvalid input. Please enter a number.\n\n");
        }
    }   
}
