void exitGame(FILE *fp) {
    int exitz;
    printf("press E for exit the game\n");
    scanf(" %c", &exitz);
    if (exitz == 'E' || exitz == 'e') {
        printf("Exiting the game. Goodbye!\n");
        fprintf(fp, "\nGame exited by user.\n");
        fclose(fp);
        exit(0);
    }
}
