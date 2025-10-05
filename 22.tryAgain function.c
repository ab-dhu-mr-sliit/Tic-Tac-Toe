void tryAgain() {
    printf("Press 0 play again or any other key to exit: ");
    int playAgain;
    scanf("%d", &playAgain);
    if (playAgain == 0) {
        system(CLEAR);
        main(); // Restart the game
    }
    else {
        printf("Exiting the game. Goodbye!\n");
    }
}