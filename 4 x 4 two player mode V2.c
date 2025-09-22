#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Display board - shows two-digit numbers
char showboard_4[4][4][3] = {
    {"01", "02", "03", "04"},
    {"05", "06", "07", "08"},
    {"09", "10", "11", "12"},
    {"13", "14", "15", "16"}
};

// Internal board - stores single characters for logic
char board_4[4][4] = {
    {'1', '2', '3', '4'},
    {'5', '6', '7', '8'},
    {'9', 'A', 'B', 'C'},
    {'D', 'E', 'F', 'G'}
};

// Draw board with two-digit display - FIXED VERSION
void drawboard_4() {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        // Make sure we're using showboard_4 for display
        printf(" %s | %s | %s | %s ", showboard_4[i][0], showboard_4[i][1], showboard_4[i][2], showboard_4[i][3]);
        if (i < 3) {
            printf("\n----|----|----|----\n");
        }
    }
    printf("\n\n");
}

// Update display board based on internal board
void updateDisplayBoard_4() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_4[i][j] == 'X') {
                strcpy(showboard_4[i][j], " X");
            } else if (board_4[i][j] == 'O') {
                strcpy(showboard_4[i][j], " O");
            } else {
                // For empty positions, show the original two-digit numbers
                switch (i * 4 + j + 1) {
                    case 1: strcpy(showboard_4[i][j], "01"); break;
                    case 2: strcpy(showboard_4[i][j], "02"); break;
                    case 3: strcpy(showboard_4[i][j], "03"); break;
                    case 4: strcpy(showboard_4[i][j], "04"); break;
                    case 5: strcpy(showboard_4[i][j], "05"); break;
                    case 6: strcpy(showboard_4[i][j], "06"); break;
                    case 7: strcpy(showboard_4[i][j], "07"); break;
                    case 8: strcpy(showboard_4[i][j], "08"); break;
                    case 9: strcpy(showboard_4[i][j], "09"); break;
                    case 10: strcpy(showboard_4[i][j], "10"); break;
                    case 11: strcpy(showboard_4[i][j], "11"); break;
                    case 12: strcpy(showboard_4[i][j], "12"); break;
                    case 13: strcpy(showboard_4[i][j], "13"); break;
                    case 14: strcpy(showboard_4[i][j], "14"); break;
                    case 15: strcpy(showboard_4[i][j], "15"); break;
                    case 16: strcpy(showboard_4[i][j], "16"); break;
                }
            }
        }
    }
}

// Check for win
int checkWin_4() {
    // Check rows
    for (int i = 0; i < 4; i++) {
        if (board_4[i][0] != ' ' && 
            board_4[i][0] == board_4[i][1] && 
            board_4[i][1] == board_4[i][2] && 
            board_4[i][2] == board_4[i][3]) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 4; i++) {
        if (board_4[0][i] != ' ' && 
            board_4[0][i] == board_4[1][i] && 
            board_4[1][i] == board_4[2][i] && 
            board_4[2][i] == board_4[3][i]) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board_4[0][0] != ' ' && 
        board_4[0][0] == board_4[1][1] && 
        board_4[1][1] == board_4[2][2] && 
        board_4[2][2] == board_4[3][3]) {
        return 1;
    }
    if (board_4[0][3] != ' ' && 
        board_4[0][3] == board_4[1][2] && 
        board_4[1][2] == board_4[2][1] && 
        board_4[2][1] == board_4[3][0]) {
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw_4() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_4[i][j] != 'X' && board_4[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Find position on board based on user input (1-16)
void findPosition_4(int choice_4, int *row_4, int *col_4) {
    char target;
    if (choice_4 >= 1 && choice_4 <= 9) {
        target = '0' + choice_4;
    } else if (choice_4 >= 10 && choice_4 <= 16) {
        target = 'A' + (choice_4 - 10);
    } else {
        *row_4 = -1;
        *col_4 = -1;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board_4[i][j] == target) {
                *row_4 = i;
                *col_4 = j;
                return;
            }
        }
    }
    *row_4 = -1;
    *col_4 = -1;
}

int main() {
    int player = 1;
    int choice_4;
    int gameStatus = 0;
    char mark;
    char player1[50], player2[50];

    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    printf("\nWelcome %s (X) and %s (O) to Tic-Tac-Toe!\n", player1, player2);
    printf("Use numbers 1-16 to make your moves\n");
    Sleep(1500);

    // Initialize display board with proper two-digit numbers
    updateDisplayBoard_4();

    do {
        system("cls");
        drawboard_4();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number (1-16): ", currentPlayer);
        if (scanf("%d", &choice_4) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            Sleep(1000);
            continue;
        }
        
        while (getchar() != '\n');
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice_4 >= 1 && choice_4 <= 16) {
            int row_4, col_4;
            findPosition(choice_4, &row_4, &col_4);
            
            if (row_4 != -1 && col_4 != -1) {
                if (board_4[row_4][col_4] != 'X' && board_4[row_4][col_4] != 'O') {
                    board_4[row_4][col_4] = mark;
                    updateDisplayBoard_4();
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
            printf("Invalid input! Please enter a number between 1 and 16.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin_4();
        if (gameStatus == 0) {
            gameStatus = checkDraw_4() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
        }
        
    } while (gameStatus == 0);
    
    system("cls");
    drawboard_4();
    
    if (gameStatus == 1) {
        char *winner = (player % 2 == 0) ? player1 : player2;
        printf(" %s WINS! \n\n", winner);
    } else {
        printf("It's a DRAW!\n\n");
    }
    
    return 0;
}