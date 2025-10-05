int trySize(FILE *fp) {
    int size;
    char input[100];

    while (1) {
        printf("Enter grid size (3 to 10): ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &size) == 1) {
            if (size >= 3 && size <= 10) {
                logSize(fp, size);
                return size;
            } else {
                printf("Invalid grid size. Try again.\n\n");
                logisValidSize(fp, size);
            }
        } else {
            printf("\nInvalid input. Please enter a number with in 3 to 10.\n\n");
        }
    }
}
