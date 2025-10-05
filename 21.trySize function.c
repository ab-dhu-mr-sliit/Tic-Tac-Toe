int trySize(FILE *fp) {
    int size;
    while (1) {
        printf("\nEnter grid size (3 to 10): ");
        scanf("%d", &size);
        logSize(fp, size);
        if (size >= 3 && size <= 10) {
            return size;
        } else {
            printf("Invalid grid size. Try again.\n");
            logisValidSize(fp, size);
        }
    }
}