#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // usleep
#include <unistd.h>  // linux


/*     Board setup     */
char **createBoard(int size);
void initializeBoard(char **board, int size);
void displayBoard(char **board, int size);
void freeBoard(char **board, int size);

/*     Player moves     */
int tryMode(FILE *fp);
int trySize(FILE *fp);
void tryAgain();
void getValidMove(char **board, int size, char symbol, FILE *fp);
void generateRandomMove(char **board, int size, int *row, int *col);
int back_M(FILE *fp);
int back_S(FILE *fp);

/*     Game logic     */
int checkWin(char **board, int size, char symbol);
int isBoardFull(char **board, int size);
int switchPlayer(int currentTurn, int totalPlayers);

/*     logFile     */
void logdisplayBoard(FILE *fp, char **board, int size);
void logMove(FILE *fp, char player, int row, int col);
void logMode(FILE *fp, int mode);
void logSize(FILE *fp, int size);
void logisValidMode(FILE *fp, int mode);
void logisValidSize(FILE *fp, int size);
void logisValidMove(FILE *fp, int row, int col);
void logWins(FILE *fp, char symbols);
void logComputerWin(FILE *fp);
void logRoles(FILE *fp, char roles[], char symbols[]);
void logmodeReseclect(FILE *fp);
void logsizeReselect(FILE *fp);


int main() {
    int mode, size;

    // Seed random number generator for computer moves
    srand(time(NULL));

    // Open log file
    FILE *fp = fopen("Tic-Tac-Toe_linux.txt", "w");  // file
    if (fp == NULL) { /* check log file is open*/
        printf("Failed to open log file.\n");
        return 1;
    }
    fprintf(fp, "Log file opened successfully.\n\n"); // file
    fprintf(fp, "Welcome to Tic-Tac-Toe!\n\n");  // file
    
    printf("Welcome to Tic-Tac-Toe!\n\n"); 

    reMode:
    mode = tryMode(fp);
    if(back_M(fp)){
        goto reMode;
    }
    
    reSize:
    size = trySize(fp);
    switch(back_S(fp)){
        case 1:
        goto reMode;
        break;

        case 2:
        goto reSize;
        break;
    }
    
    // Create and initialize board
    char **board = createBoard(size);
    if (board == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    initializeBoard(board, size); // this function allocated the every cell is empty cell
    
    if (mode == 1) {
        // Two-player mode
        char symbols[2] = {'X', 'O'};
        int currentTurn = 0;
        
        while (1) {
            printf("%d x %d Grid (Two-Player)\n", size, size);
            displayBoard(board, size); // initial or updated board in terminal
            logdisplayBoard(fp, board, size);  // initial or updated board in file
            getValidMove(board, size, symbols[currentTurn], fp); // check row and column are valid if that is correct place the user symbol in that position (row, column)
            
            if (checkWin(board, size, symbols[currentTurn])) { // check winnig condition
                displayBoard(board, size); // final board in the terminal
                logdisplayBoard(fp, board, size); // final board in the file
                printf("\nPlayer %c wins!\n", symbols[currentTurn]); // winning message in the terminal
                logWins(fp, symbols[currentTurn]);  // winnig message in the file
                break;
            }
            
            if (isBoardFull(board, size)) { // check draw condition
                displayBoard(board, size); // final board in the terminal
                logdisplayBoard(fp, board, size); //  final board in the file
                printf("\nIt's a draw!\n"); // draw messsage in the terminal
                fprintf(fp, "\nIt's a draw!\n"); // draw messsage in the file
                break;
            }
            currentTurn = switchPlayer(currentTurn, 2); // for next turn 
        }
        
    } else if (mode == 2) {
        // User vs Computer
        char userSymbol = 'X';
        char computerSymbol = 'O';
        int row, col;
        
        while (1) {
            printf("%d x %d Grid (User vs Computer)\n", size, size);
            displayBoard(board, size); // initial or updated board in terminal
            logdisplayBoard(fp, board, size);  // initial or updated board in file 

            // user turn

            getValidMove(board, size, userSymbol, fp); // check row and column are valid if that is correct place the user symbol in that position (row, column)

            if (checkWin(board, size, userSymbol)) { // check winning condition
                displayBoard(board, size); // final board in the terminal
                logdisplayBoard(fp, board, size); // final board in the file
                printf("\nYou win!\n"); // winning message in the terminal
                logWins(fp, userSymbol);// winning messge in the file
                break;
            }

            if (isBoardFull(board, size)) { // check draw condition
                displayBoard(board, size); // final board in the terminal
                logdisplayBoard(fp, board, size);// final board in the file
                printf("\nIt's a draw!\n"); // draw message 
                fprintf(fp, "\nIt's a draw!\n"); // draw message in terminal
                break;
            }

            // computer turn

            generateRandomMove(board, size, &row, &col); // this function out row and col
            board[row][col] = computerSymbol; // in here we use that row and col
            printf("\nComputer placed at (%d, %d)\n", row, col); // print the move in terminal
            logMove(fp, computerSymbol, row, col); // print the computer move in file

            if (checkWin(board, size, userSymbol)) { // check winnig conditions
                displayBoard(board, size); // final board in the terminal
                logdisplayBoard(fp, board, size); // final board in the file
                printf("\nComputer win!\n"); // winning message in the terminal
                logComputerWin(fp);// winning messge in the file
                break;
            }

            if (isBoardFull(board, size)) { // check draw condition
                displayBoard(board, size); // final board in the terminal
                logdisplayBoard(fp, board, size);// final board in the file
                printf("\nIt's a draw!\n"); // draw message 
                fprintf(fp, "\nIt's a draw!\n"); // draw message in terminal
                break;
            }
        }

    } else {
        // Multi-player mode
        char symbols[3] = {'X', 'O', 'Z'};
        int currentTurn = 0;
        char roles[3]; // 'H' for Human, 'C' for Computer

        // Prompt user to select role for each player
        for (int i = 0; i < 3; i++) {
            printf("Select role for Player %c (H for Human, C for Computer): ", symbols[i]);
            scanf(" %c", &roles[i]);
            while (roles[i] != 'H' && roles[i] != 'C' && roles[i] != 'h' && roles[i] != 'c') {
                printf("Invalid input. Enter H or C: ");
                scanf(" %c", &roles[i]);
            }
        }
        logRoles(fp, roles, symbols); // this function prints who is human and how is computer 

        while (1) {
            printf("%d x %d Grid (Multi-Player)\n", size, size);
            displayBoard(board, size); // initiale or updated board in terminal 
            logdisplayBoard(fp, board, size); // initiale or updated board in fle
            printf("\nPlayer %c's turn.\n", symbols[currentTurn]);

            if (roles[currentTurn] == 'H' || roles[currentTurn] == 'h') { // for human
                getValidMove(board, size, symbols[currentTurn], fp); // check row and column are valid if that is correct place the user symbol in that position (row, column)
            } else {
                int row, col;
                generateRandomMove(board, size, &row, &col); // this function out row and col
                board[row][col] = symbols[currentTurn];  // we use that row and col here
                printf("\nComputer Player %c placed at (%d, %d)\n", symbols[currentTurn], row, col);
                logMove(fp, symbols[currentTurn], row, col); // print the move in file
            }

            if (checkWin(board, size, symbols[currentTurn])) { // check winning condition
                displayBoard(board, size); // final board in terminal
                logdisplayBoard(fp, board, size); // final board in file
                printf("\nPlayer %c wins!\n", symbols[currentTurn]);  // win message in terminal
                logWins(fp, symbols[currentTurn]); // win message in file
                break;
            }

            if (isBoardFull(board, size)) { // check draw
                displayBoard(board, size); // final board in terminal
                logdisplayBoard(fp, board, size); // final board in file
                printf("\nIt's a draw!\n"); // draw message in terminal
                fprintf(fp,"\nIt's a draw!\n"); // draw message in file
                break;
            }

            currentTurn = switchPlayer(currentTurn, 3); // for next player turn
        }
    }

    fprintf(fp, "\nGame Over. Closing log file.\n");
    fclose(fp); // file close 
    freeBoard(board, size);
    printf("Thanks for playing!\n");
    tryAgain();  // if user press 0 game is restart form the beginning
    return 0;
}

/*                Board setup               */
/* ---------------------------------------- */ 

char **createBoard(int size) { 
    // it create board based on user input (using memory allocation)
    
    // Allocate memory for row pointers
    char **board = malloc(size * sizeof(char *));
    if (board == NULL) {
        return NULL;  // Allocation failed
    }

    // Allocate memory for each row
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(char));
        if (board[i] == NULL) {
            // Free previously allocated rows if any allocation fails
            for (int j = 0; j < i; j++) {
                free(board[j]);
            }
            free(board);
            return NULL;
        }
    }

    return board;
}

void initializeBoard(char **board, int size) {
    for (int i = 0; i < size; i++) {  // for row
        for (int j = 0; j < size; j++) {  // for column
            board[i][j] = ' ';  // Empty cell
        }
    }
}

void displayBoard(char **board, int size) {
    puts(" "); // for a new line
    printf(" "); // a space to allocate the right position for column numbers
    for(int i = 0; i < size; i++){  // it prints column numbers
        printf("   %d", i);
    }
    printf("\n\n");
    for (int i = 0; i < size; i++) { 
        printf("%d  ", i); // this is print row number
        // Print each row
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]);
            if (j < size - 1) printf("|"); // for sperate every column
        }
        printf("\n");
        printf("   ");

        // Print horizontal separator between rows
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                printf("---");  // for sperate every row
                if (j < size - 1) printf("+");
            }
            printf("\n");
        }
    }
}

void freeBoard(char **board, int size) {
    // Free each row
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }

    // Free the array of row pointers
    free(board);
}

/*              Player moves                */
/* ---------------------------------------- */
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
                printf("Invalid mode selected. Try again.\n\n");   /* if user enter invalid (less then or more then)input */
                logisValidMode(fp, mode); // it print in the file invalid input for mode and mention that number
            } 
        }
        else {
            printf("\nInvalid input. Please enter a number.\n\n");   /* if user enter non-Numerics input */
        }
    }   
}

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
                printf("Invalid grid size. Try again.\n\n"); /* if user enter more then or less then grid size limit */
                logisValidSize(fp, size);// it print in the file invalid input for size and mention the number 
            }
        } else {
            printf("\nInvalid input. Please enter a number with in 3 to 10.\n\n"); /* if user enter non-Numeric input*/
        }
    }
}

void tryAgain() {
    printf("Press 0 to play again or Enter to exit: ");
    char playAgain[3];
    fgets(playAgain, sizeof(playAgain), stdin);

    if (playAgain == 0) {
        main(); // Restart the game
    }
    else if (playAgain == "\n"){
        while (getchar() != '\n'); // Clear remaining input
        printf("Exiting the game. Goodbye!\n");
    }
}

void getValidMove(char **board, int size, char symbol, FILE *fp) {   
    // check row and column are valid if that is correct place the user symbol in that position (row, column)
    int row, col;  // user inputs

    while (1) {

        printf("\nPlayer %c, enter your move (row and column between 0 and %d) ", symbol, size - 1);
        puts(" ");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);

        // Check if input is within bounds
        if (row < 0 || row >= size || col < 0 || col >= size) {
            printf("Invalid position! Please enter values between 0 and %d.\n", size - 1);
            logisValidMove(fp, row, col);
            continue;
        }

        // Check if cell is already occupied
        if (board[row][col] != ' ') {
            printf("Cell already taken! Choose another.\n");
            fprintf(fp,"Cell already taken! Choose another.\n");
            continue;
        }
        // Save Move in logFile
        logMove(fp, symbol, row, col); // print the users move in file

        // Valid move
        board[row][col] = symbol; //place the user symbol in that position (row, column)
        break;
    }
}

void generateRandomMove(char **board, int size, int *row, int *col) {

    printf("Computer's thinking...\n");
    usleep((1000) * 1000);     // Pause for 1 second to simulate thinking

    while (1) {  // while(1) means always true
        int r = rand() % size;   // generate random number for row (between 0 to size) 
        int c = rand() % size;   // generate random number for column (between 0 to size) 

        if (board[r][c] == ' ') {   // check that cell is empty
            *row = r;  // *row is output paramete. so, we can use this out of this function 
            *col = c;  // *col is output paramete. so, we can use this out of this function 
            break;
        }
    }
}

int back_M(FILE *fp){
    char back;
    printf("Press M for reselect the mode\nPress E for exit the game\n");
    scanf("%c", &back);
    while (getchar() != '\n'); // Clear input buffer

    if (back == 'M' || back == 'm') {
        logmodeReseclect(fp);
        return 1;
    }

    else if (back == 'E' || back == 'e') {
        printf("Exiting the game. Goodbye!\n");
        fprintf(fp, "\nGame exited by user.\n");
        fclose(fp);
        exit(0);
    }
    return 0;
}

int back_S(FILE *fp){
    char back;
    printf("Press M for reselect the mode\nPress S for reselect the grid size\nPress E for exit the game\n");
    scanf("%c", &back);
    while (getchar() != '\n'); // Clear input buffer

    if (back == 'M' || back == 'm') {
        logmodeReseclect(fp);
        return 1;
    }

    else if (back == 'S' || back == 's') {
        logsizeReselect(fp);
        return 2;
    }

    else if (back == 'E' || back == 'e') {
        printf("Exiting the game. Goodbye!\n");
        fprintf(fp, "\nGame exited by user.\n");
        fclose(fp);
        exit(0);
    }

    return 0;
}

/*               Game logic                 */
/* ---------------------------------------- */
int checkWin(char **board, int size, char symbol) {
    int i, j;

    // Check rows
    for (i = 0; i < size; i++) {
        int rowWin = 1;
        for (j = 0; j < size; j++) {
            if (board[i][j] != symbol) {
                rowWin = 0;  // if in the row that is specific symbol isn't full rowWin is turn into zero
                break;
            }
        }
        if (rowWin) return 1;
    }

    // Check columns
    for (j = 0; j < size; j++) {
        int colWin = 1;
        for (i = 0; i < size; i++) {
            if (board[i][j] != symbol) {
                colWin = 0;  // if in the column that is specific symbol isn't full colWin is turn into zero
                break;
            }
        }
        if (colWin) return 1;
    }

    // Check main diagonal (top-left to bottom-right)
    int diag1Win = 1;
    for (i = 0; i < size; i++) {
        if (board[i][i] != symbol) {
            diag1Win = 0;  // if in the diagonal that is specific symbol isn't full diag1Win is turn into zero
            break;
        }
    }
    if (diag1Win) return 1;

    // Check anti-diagonal (top-right to bottom-left)
    int diag2Win = 1;
    for (i = 0; i < size; i++) {
        if (board[i][size - 1 - i] != symbol) {
            diag2Win = 0; // if in the diagonal that is specific symbol isn't full diag2Win is turn into zero
            break;
        }
    }
    if (diag2Win) return 1;

    // No win found
    return 0;
}

int isBoardFull(char **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Found an empty cell → board is not full
            }
        }
    }
    return 1;  // No empty cells → board is full
}

int switchPlayer(int currentTurn, int totalPlayers) {
    return (currentTurn + 1) % totalPlayers;
}

/*                 logFile                  */
/* ---------------------------------------- */

void logdisplayBoard(FILE *fp, char **board, int size) {
    if (fp != NULL) {
        fprintf(fp, "\nCurrent Board State:\n\n");
        for(int i = 0; i < size; i++){
        fprintf(fp, "   %d", i);
        }
        fprintf(fp, "\n\n");
        for (int i = 0; i < size; i++) {
        fprintf(fp, "%d  ", i);
            // Print each row
            for (int j = 0; j < size; j++) {
                fprintf(fp, " %c ", board[i][j]);
                if (j < size - 1) fprintf(fp, "|");
            }
            fprintf(fp, "\n");
            fprintf(fp, "   ");

        // Print horizontal separator between rows
            if (i < size - 1) {
                for (int j = 0; j < size; j++) {
                    fprintf(fp, "---");
                if (j < size - 1) fprintf(fp, "+");
                }
                fprintf(fp, "\n");
            }
        }
        fprintf(fp, "\n");
    }
     else {
        printf("Error: Log file is not open.\n");
    }
}

void logMove(FILE *fp, char symbol, int row, int col) {
    if (fp != NULL) {
        fprintf(fp, "Player %c moved to (%d, %d)\n", symbol, row, col);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logisValidMove(FILE *fp, int row, int col) {
    // it print in the file invalid input for row or column and mention that inputs
    if (fp != NULL) {
        fprintf(fp, "Invalid move attempted at (%d, %d)\n", row, col);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logMode(FILE *fp, int mode) {
    if (fp != NULL) {
        fprintf(fp, "\nGame mode selected: %d\n", mode);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logisValidMode(FILE *fp, int mode) { 
    // it print in the file invalid input for mode and mention that input
    if (fp != NULL) {
        fprintf(fp, "Invalid game mode selected: %d\n", mode);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logSize(FILE *fp, int size) {
    if (fp != NULL) {
        fprintf(fp, "\nGrid size selected: %d\n", size);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logisValidSize(FILE *fp, int size) { 
    // it print in the file invalid input for grid size and mention that input
    if (fp != NULL) {
        fprintf(fp, "Invalid grid size selected: %d\n", size);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logWins(FILE *fp, char symbols) {
    if (fp != NULL) {
        fprintf(fp, "\nPlayer %c wins the game!\n", symbols);
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logComputerWin(FILE *fp) {
    if (fp != NULL) {
        fprintf(fp, "\nComputer wins the game!\n");
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logRoles(FILE *fp, char roles[], char symbols[]) { 
    // this is only for multy player mode
    if (fp != NULL) {
        fprintf(fp, "\nPlayer Roles:\n");
        for (int i = 0; i < 3; i++) {
            fprintf(fp, "Player %c: %s\n", symbols[i], (roles[i] == 'H' || roles[i] == 'h') ? "Human" : "Computer");
        }
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logmodeReseclect(FILE *fp) {
    if (fp != NULL) {
        fprintf(fp, "\nUser reselected the game mode.\n");
    } else {
        printf("Error: Log file is not open.\n");
    }
}

void logsizeReselect(FILE *fp) {
    if (fp != NULL) {
        fprintf(fp, "\nUser reselected the grid size.\n");
    } else {
        printf("Error: Log file is not open.\n");
    }
}