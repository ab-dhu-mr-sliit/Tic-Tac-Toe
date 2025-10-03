void generateRandomMove(char **board, int size, int *row, int *col) {
    // Seed the random number generator (only once in main)
    // srand(time(NULL)); ← Do this in main(), not here
    printf("Computer's thinking...\n");
    SLEEP(1000);       // Pause for 1 second to simulate thinking

    while (1) {
        int r = rand() % size;
        int c = rand() % size;

        if (board[r][c] == ' ') {
            *row = r;
            *col = c;
            break;
        }
    }
    system(CLEAR); // Clear the console (Windows-specific)
}
