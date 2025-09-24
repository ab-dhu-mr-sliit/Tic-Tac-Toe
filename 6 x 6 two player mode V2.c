#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Display board - shows two-digit numbers
char showboard_6[6][6][3] = {
    {"01", "02", "03", "04", "05", "06"},
    {"07", "08", "09", "10", "11", "12"},
    {"13", "14", "15", "16", "17", "18"},
    {"19", "20", "21", "22", "23", "24"},
    {"25", "26", "27", "28", "29", "30"},
    {"31", "32", "33", "34", "35", "36"}
};

// Internal board - stores single characters for logic
char board_6[6][6] = {
    {'1', '2', '3', '4', '5', '6'},
    {'7', '8', '9', 'A', 'B', 'C'},
    {'D', 'E', 'F', 'G', 'H', 'I'},
    {'J', 'K', 'L', 'M', 'N', 'P'},  // Skip O
    {'Q', 'R', 'S', 'T', 'U', 'V'},
    {'W', 'Y', 'Z', '[', ']', ','}   // Skip O and use other characters
};

// Draw board with two-digit display
void drawboard_6() {
    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf(" %s | %s | %s | %s | %s | %s ", 
               showboard_6[i][0], showboard_6[i][1], showboard_6[i][2], 
               showboard_6[i][3], showboard_6[i][4], showboard_6[i][5]);
        if (i < 5) {
            printf("\n----|----|----|----|----|----\n");
        }
    }
    printf("\n\n");
}

// Update display board based on internal board
void updateDisplayBoard_6() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (board_6[i][j] == 'X') {
                strcpy(showboard_6[i][j], " X");
            } else if (board_6[i][j] == 'O') {
                strcpy(showboard_6[i][j], " O");
            } else {
                // For empty positions, show the original two-digit numbers
                switch(i * 6 + j + 1){
                    case 1: strcpy(showboard_6[i][j], "01"); break;
                    case 2: strcpy(showboard_6[i][j], "02"); break;
                    case 3: strcpy(showboard_6[i][j], "03"); break;
                    case 4: strcpy(showboard_6[i][j], "04"); break;
                    case 5: strcpy(showboard_6[i][j], "05"); break;
                    case 6: strcpy(showboard_6[i][j], "06"); break;
                    case 7: strcpy(showboard_6[i][j], "07"); break;
                    case 8: strcpy(showboard_6[i][j], "08"); break;
                    case 9: strcpy(showboard_6[i][j], "09"); break;
                    case 10: strcpy(showboard_6[i][j], "10"); break;
                    case 11: strcpy(showboard_6[i][j], "11"); break;
                    case 12: strcpy(showboard_6[i][j], "12"); break;
                    case 13: strcpy(showboard_6[i][j], "13"); break;
                    case 14: strcpy(showboard_6[i][j], "14"); break;
                    case 15: strcpy(showboard_6[i][j], "15"); break;
                    case 16: strcpy(showboard_6[i][j], "16"); break;
                    case 17: strcpy(showboard_6[i][j], "17"); break;
                    case 18: strcpy(showboard_6[i][j], "18"); break;
                    case 19: strcpy(showboard_6[i][j], "19"); break;
                    case 20: strcpy(showboard_6[i][j], "20"); break;
                    case 21: strcpy(showboard_6[i][j], "21"); break;
                    case 22: strcpy(showboard_6[i][j], "22"); break;
                    case 23: strcpy(showboard_6[i][j], "23"); break;
                    case 24: strcpy(showboard_6[i][j], "24"); break;
                    case 25: strcpy(showboard_6[i][j], "25"); break;
                    case 26: strcpy(showboard_6[i][j], "26"); break;
                    case 27: strcpy(showboard_6[i][j], "27"); break;
                    case 28: strcpy(showboard_6[i][j], "28"); break;
                    case 29: strcpy(showboard_6[i][j], "29"); break;
                    case 30: strcpy(showboard_6[i][j], "30"); break;
                    case 31: strcpy(showboard_6[i][j], "31"); break;
                    case 32: strcpy(showboard_6[i][j], "32"); break;
                    case 33: strcpy(showboard_6[i][j], "33"); break;
                    case 34: strcpy(showboard_6[i][j], "34"); break;
                    case 35: strcpy(showboard_6[i][j], "35"); break;
                    case 36: strcpy(showboard_6[i][j], "36"); break;
                }
            }
        }
    }
}

// Check for win (5 in a row for 6x6 board)
int checkWin_6() {
    // Check rows
    for (int i = 0; i < 6; i++) {
        if (board_6[i][0] != ' ' && 
            board_6[i][0] == board_6[i][1] && 
            board_6[i][1] == board_6[i][2] && 
            board_6[i][2] == board_6[i][3] &&
            board_6[i][3] == board_6[i][4] &&
            board_6[i][4] == board_6[i][5]) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 6; i++) {
        if (board_6[0][i] != ' ' && 
            board_6[0][i] == board_6[1][i] && 
            board_6[1][i] == board_6[2][i] && 
            board_6[2][i] == board_6[3][i] &&
            board_6[3][i] == board_6[4][i] &&
            board_6[4][i] == board_6[5][i]) {
            return 1;
        }
    }
    
    // Check diagonals (top-left to bottom-right)
    if (board_6[0][0] != ' ' && 
        board_6[0][0] == board_6[1][1] && 
        board_6[1][1] == board_6[2][2] && 
        board_6[2][2] == board_6[3][3] &&
        board_6[3][3] == board_6[4][4] &&
        board_6[4][4] == board_6[5][5]) {
        return 1;
    }
    
        
    // Check diagonals (top-right to bottom-left)
    if (board_6[5][0] != ' ' && 
        board_6[5][0] == board_6[4][1] && 
        board_6[4][1] == board_6[3][2] && 
        board_6[3][2] == board_6[2][3] &&
        board_6[2][3] == board_6[1][4] &&
        board_6[1][4] == board_6[5][5]) {
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (board_6[i][j] != 'X' && board_6[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Find position on board based on user input (1-36)
void findPosition_6(int choice_6, int *row_6, int *col_6) {
    char target;
    if (choice_6 >= 1 && choice_6 <= 9) {
        target = '0' + choice_6;
    } else if (choice_6 >= 10 && choice_6 <= 23) {
        target = 'A' + (choice_6 - 10);
    } else if (choice_6 >= 24 && choice_6 <= 36 ){
        switch(choice_6) {
            case 24: target = 'P'; break;
            case 25: target = 'Q'; break;
            case 26: target = 'R'; break;
            case 27: target = 'S'; break;
            case 28: target = 'T'; break;
            case 29: target = 'U'; break;
            case 30: target = 'V'; break;
            case 31: target = 'W'; break;
            case 32: target = 'Y'; break;
            case 33: target = 'Z'; break;
            case 34: target = '['; break;
            case 35: target = ']'; break;
            case 36: target = ','; break;
        }
    } else {
        *row_6 = -1;
        *col_6 = -1;
        return;
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (board_6[i][j] == target) {
                *row_6 = i;
                *col_6 = j;
                return;
            }
        }
    }
    *row_6 = -1;
    *col_6 = -1;
}

int main() {
    int player = 1;
    int choice_6;
    int gameStatus = 0;
    char mark;
    char player1[50], player2[50];

    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    printf("\nWelcome %s (X) and %s (O) to 6x6 Tic-Tac-Toe!\n", player1, player2);
    printf("Use numbers 1-36 to make your moves. \n");
    Sleep(2500);

    // Initialize display board with proper two-digit numbers
    updateDisplayBoard_6();

    do {
        system("cls");
        drawboard_6();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number (1-36): ", currentPlayer);
        if (scanf("%d", &choice_6) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            Sleep(1000);
            continue;
        }
        
        while (getchar() != '\n');
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice_6 >= 1 && choice_6 <= 36) {
            int row_6, col_6;
            findPosition_6(choice_6, &row_6, &col_6);
            
            if (row_6 != -1 && col_6 != -1) {
                if (board_6[row_6][col_6] != 'X' && board_6[row_6][col_6] != 'O') {
                    board_6[row_6][col_6] = mark;
                    updateDisplayBoard_6();
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
            printf("Invalid input! Please enter a number between 1 and 36.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin_6();
        if (gameStatus == 0) {
            gameStatus = checkDraw() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
        }
        
    } while (gameStatus == 0);
    
    system("cls");
    drawboard_6();
    
    if (gameStatus == 1) {
        char *winner = (player % 2 == 0) ? player1 : player2;
        printf(" %s WINS! \n", winner);
    } else {
        printf("It's a DRAW!\n");
    }
    
    return 0;
}