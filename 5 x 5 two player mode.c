#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Display board - shows two-digit numbers
char showboard_5[5][5][3] = {
    {"01", "02", "03", "04", "05"},
    {"06", "07", "08", "09", "10"},
    {"11", "12", "13", "14", "15"},
    {"16", "17", "18", "19", "20"},
    {"21", "22", "23", "24", "25"}
};

// Internal board - stores single characters for logic
char board_5[5][5] = {
    {'1', '2', '3', '4', '5'},
    {'6', '7', '8', '9', 'A'},
    {'B', 'C', 'D', 'E', 'F'},
    {'G', 'H', 'I', 'J', 'K'},
    {'L', 'M', 'N', 'P', 'Q'}
};

// Draw board with two-digit display
void drawboard_5() {
    printf("\n");
    for (int i = 0; i < 5; i++) {
        // Make sure we're using showboard_5 for display
        printf(" %s | %s | %s | %s | %s ", showboard_5[i][0], showboard_5[i][1], showboard_5[i][2], showboard_5[i][3], showboard_5[i][4]);
        if (i < 4) {
            printf("\n----|----|----|----|----\n");
        }
    }
    printf("\n\n");
}

// Update display board based on internal board
void updateDisplayBoard_5() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board_5[i][j] == 'X') {
                strcpy(showboard_5[i][j], " X");
            } else if (board_5[i][j] == 'O') {
                strcpy(showboard_5[i][j], " O");
            } else {
                // For empty positions, show the original two-digit numbers
                switch (i * 5 + j + 1) {
                    case 1: strcpy(showboard_5[i][j], "01"); break;
                    case 2: strcpy(showboard_5[i][j], "02"); break;
                    case 3: strcpy(showboard_5[i][j], "03"); break;
                    case 4: strcpy(showboard_5[i][j], "04"); break;
                    case 5: strcpy(showboard_5[i][j], "05"); break;
                    case 6: strcpy(showboard_5[i][j], "06"); break;
                    case 7: strcpy(showboard_5[i][j], "07"); break;
                    case 8: strcpy(showboard_5[i][j], "08"); break;
                    case 9: strcpy(showboard_5[i][j], "09"); break;
                    case 10: strcpy(showboard_5[i][j], "10"); break;
                    case 11: strcpy(showboard_5[i][j], "11"); break;
                    case 12: strcpy(showboard_5[i][j], "12"); break;
                    case 13: strcpy(showboard_5[i][j], "13"); break;
                    case 14: strcpy(showboard_5[i][j], "14"); break;
                    case 15: strcpy(showboard_5[i][j], "15"); break;
                    case 16: strcpy(showboard_5[i][j], "16"); break;
                    case 17: strcpy(showboard_5[i][j], "17"); break;
                    case 18: strcpy(showboard_5[i][j], "18"); break;
                    case 19: strcpy(showboard_5[i][j], "19"); break;
                    case 20: strcpy(showboard_5[i][j], "20"); break;
                    case 21: strcpy(showboard_5[i][j], "21"); break;
                    case 22: strcpy(showboard_5[i][j], "22"); break;
                    case 23: strcpy(showboard_5[i][j], "23"); break;
                    case 24: strcpy(showboard_5[i][j], "24"); break;
                    case 25: strcpy(showboard_5[i][j], "25"); break;
                }
            }
        }
    }
}

// Check for win (5 in a row for 5x5 board)
int checkWin_5() {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (board_5[i][0] != ' ' && 
            board_5[i][0] == board_5[i][1] && 
            board_5[i][1] == board_5[i][2] && 
            board_5[i][2] == board_5[i][3] &&
            board_5[i][3] == board_5[i][4]) {
            return 1;
            }
        
    }
    
    // Check columns
    for (int i = 0; i < 5; i++) {
        if (board_5[0][i] != ' ' && 
            board_5[0][i] == board_5[1][i] && 
            board_5[1][i] == board_5[2][i] && 
            board_5[2][i] == board_5[3][i] &&
            board_5[3][i] == board_5[4][i]) {
            return 1;
            }
        
    }
    
    // Check diagonals (top-left to bottom-right)
    if (board_5[0][0] != ' ' && 
        board_5[0][0] == board_5[1][1] && 
        board_5[1][1] == board_5[2][2] && 
        board_5[2][2] == board_5[3][3] &&
        board_5[3][3] == board_5[4][4]){
        return 1;
    }
        
    // Check diagonals (top-right to bottom-left)
    if (board_5[4][0] != ' ' && 
        board_5[4][0] == board_5[3][1] && 
        board_5[3][1] == board_5[2][2] && 
        board_5[2][2] == board_5[1][3] &&
        board_5[1][3] == board_5[0][4]){
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw_5() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board_5[i][j] != 'X' && board_5[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Find position on board based on user input (1-25)
void findPosition_5(int choice_5, int *row_5, int *col_5) {
    char target;
    if (choice_5 >= 1 && choice_5 <= 9) {
        target = '0' + choice_5;
    } else if (choice_5 >= 10 && choice_5 <= 25) {
        // Adjusted mapping: 24 becomes Q, 25 becomes P
        if (choice_5 == 24) {
            target = 'P';
        } else if (choice_5 == 25) {
            target = 'Q';
        } else {
            target = 'A' + (choice_5 - 10);
        }
    } else {
        *row_5 = -1;
        *col_5 = -1;
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board_5[i][j] == target) {
                *row_5 = i;
                *col_5 = j;
                return;
            }
        }
    }
    *row_5 = -1;
    *col_5 = -1;
}

int main() {
    int player = 1;
    int choice_5;
    int gameStatus = 0;
    char mark;
    char player1[50], player2[50];

    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    printf("\nWelcome %s (X) and %s (O) to 5x5 Tic-Tac-Toe!\n", player1, player2);
    printf("Use numbers 1-25 to make your moves\n");
    Sleep(2500);

    // Initialize display board with proper two-digit numbers
    updateDisplayBoard_5();

    do {
        system("cls");
        drawboard_5();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number (1-25): ", currentPlayer);
        if (scanf("%d", &choice_5) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            Sleep(1000);
            continue;
        }
        
        while (getchar() != '\n');
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice_5 >= 1 && choice_5 <= 25) {
            int row_5, col_5;
            findPosition_5(choice_5, &row_5, &col_5);
            
            if (row_5 != -1 && col_5 != -1) {
                if (board_5[row_5][col_5] != 'X' && board_5[row_5][col_5] != 'O') {
                    board_5[row_5][col_5] = mark;
                    updateDisplayBoard_5();
                    player++;
                } else {
                    printf("Invalid move! That position is already taken.\n");
                    Sleep(1000);
                }
            } else {
                printf("Invalid position! Please try again.\n");
                Sleep(1000);
            }
        } else {
            printf("Invalid input! Please enter a number between 1 and 25.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin_5();
        if (gameStatus == 0) {
            gameStatus = checkDraw_5() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
        }
        
    } while (gameStatus == 0);
    
    system("cls");
    drawboard_5();
    
    if (gameStatus == 1) {
        char *winner = (player % 2 == 0) ? player1 : player2;
        printf(" %s WINS! \n", winner);
    } else {
        printf("It's a DRAW!\n");
    }
    
    return 0;
}