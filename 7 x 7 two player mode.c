#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Display board - shows two-digit numbers
char showboard_7[7][7][3] = {
    {"01", "02", "03", "04", "05", "06", "07"},
    {"08", "09", "10", "11", "12", "13", "14"},
    {"15", "16", "17", "18", "19", "20", "21"},
    {"22", "23", "24", "25", "26", "27", "28"},
    {"29", "30", "31", "32", "33", "34", "35"},
    {"36", "37", "38", "39", "40", "41", "42"},
    {"43", "44", "45", "46", "47", "48", "49"}
};

// Internal board - stores single characters for logic
char board_7[7][7] = {
    {'1', '2', '3', '4', '5', '6', '7'},
    {'8', '9', 'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'J', 'K', 'L'},
    {'M', 'N', 'P', 'Q', 'R', 'S', 'T'},  // Skip O
    {'U', 'V', 'W', 'Y', 'Z', '[', ']'},   // Skip X and O
    {'^', '_', '`', 'a', 'b', 'c', 'd'},
    {'e', 'f', 'g', 'h', 'i', 'j', 'k'}
};

// Draw board with two-digit display
void drawboard_7() {
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf(" %s | %s | %s | %s | %s | %s | %s ", 
               showboard_7[i][0], showboard_7[i][1], showboard_7[i][2], 
               showboard_7[i][3], showboard_7[i][4], showboard_7[i][5],
               showboard_7[i][6]);
        if (i < 6) {
            printf("\n----|----|----|----|----|----|----\n");
        }
    }
    printf("\n\n");
}

// Update display board based on internal board
void updateDisplayBoard_7() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board_7[i][j] == 'X') {
                strcpy(showboard_7[i][j], " X");
            } else if (board_7[i][j] == 'O') {
                strcpy(showboard_7[i][j], " O");
            } else {
                // For empty positions, show the original two-digit numbers
                switch(i * 7 + j + 1){
                    case 1: strcpy(showboard_7[i][j], "01"); break;
                    case 2: strcpy(showboard_7[i][j], "02"); break;
                    case 3: strcpy(showboard_7[i][j], "03"); break;
                    case 4: strcpy(showboard_7[i][j], "04"); break;
                    case 5: strcpy(showboard_7[i][j], "05"); break;
                    case 6: strcpy(showboard_7[i][j], "06"); break;
                    case 7: strcpy(showboard_7[i][j], "07"); break;
                    case 8: strcpy(showboard_7[i][j], "08"); break;
                    case 9: strcpy(showboard_7[i][j], "09"); break;
                    case 10: strcpy(showboard_7[i][j], "10"); break;
                    case 11: strcpy(showboard_7[i][j], "11"); break;
                    case 12: strcpy(showboard_7[i][j], "12"); break;
                    case 13: strcpy(showboard_7[i][j], "13"); break;
                    case 14: strcpy(showboard_7[i][j], "14"); break;
                    case 15: strcpy(showboard_7[i][j], "15"); break;
                    case 16: strcpy(showboard_7[i][j], "16"); break;
                    case 17: strcpy(showboard_7[i][j], "17"); break;
                    case 18: strcpy(showboard_7[i][j], "18"); break;
                    case 19: strcpy(showboard_7[i][j], "19"); break;
                    case 20: strcpy(showboard_7[i][j], "20"); break;
                    case 21: strcpy(showboard_7[i][j], "21"); break;
                    case 22: strcpy(showboard_7[i][j], "22"); break;
                    case 23: strcpy(showboard_7[i][j], "23"); break;
                    case 24: strcpy(showboard_7[i][j], "24"); break;
                    case 25: strcpy(showboard_7[i][j], "25"); break;
                    case 26: strcpy(showboard_7[i][j], "26"); break;
                    case 27: strcpy(showboard_7[i][j], "27"); break;
                    case 28: strcpy(showboard_7[i][j], "28"); break;
                    case 29: strcpy(showboard_7[i][j], "29"); break;
                    case 30: strcpy(showboard_7[i][j], "30"); break;
                    case 31: strcpy(showboard_7[i][j], "31"); break;
                    case 32: strcpy(showboard_7[i][j], "32"); break;
                    case 33: strcpy(showboard_7[i][j], "33"); break;
                    case 34: strcpy(showboard_7[i][j], "34"); break;
                    case 35: strcpy(showboard_7[i][j], "35"); break;
                    case 36: strcpy(showboard_7[i][j], "36"); break;
                    case 37: strcpy(showboard_7[i][j], "37"); break;
                    case 38: strcpy(showboard_7[i][j], "38"); break;
                    case 39: strcpy(showboard_7[i][j], "39"); break;
                    case 40: strcpy(showboard_7[i][j], "40"); break;
                    case 41: strcpy(showboard_7[i][j], "41"); break;
                    case 42: strcpy(showboard_7[i][j], "42"); break;
                    case 43: strcpy(showboard_7[i][j], "43"); break;
                    case 44: strcpy(showboard_7[i][j], "44"); break;
                    case 45: strcpy(showboard_7[i][j], "45"); break;
                    case 46: strcpy(showboard_7[i][j], "46"); break;
                    case 47: strcpy(showboard_7[i][j], "47"); break;
                    case 48: strcpy(showboard_7[i][j], "48"); break;
                    case 49: strcpy(showboard_7[i][j], "49"); break;
                }
                //int position = i * 7 + j + 1;
                //if (position < 10) {
                //    sprintf(showboard_7[i][j], "0%d", position);
                //} else {
                //    sprintf(showboard_7[i][j], "%d", position);
            }
        }
    }
}


// Check for win (5 in a row for 7x7 board)
int checkWin_7_7() {
    // Check rows
    for (int i = 0; i < 7; i++) {
        if (board_7[i][0] != ' ' && 
            board_7[i][0] == board_7[i][1] && 
            board_7[i][1] == board_7[i][2] && 
            board_7[i][2] == board_7[i][3] && 
            board_7[i][3] == board_7[i][4] && 
            board_7[i][4] == board_7[i][5] &&
            board_7[i][5] == board_7[i][6]) {
            return 1;
        }
        
    }
    
    // Check columns
    for (int i = 0; i < 7; i++) {
        if (board_7[0][i] != ' ' && 
            board_7[0][i] == board_7[1][i] && 
            board_7[1][i] == board_7[2][i] && 
            board_7[2][i] == board_7[3][i] && 
            board_7[3][i] == board_7[4][i] && 
            board_7[4][i] == board_7[5][i] &&
            board_7[5][i] == board_7[6][i]) {
            return 1;
        }
        
    }
    
    // Check diagonals (top-left to bottom-right)
    if (board_7[0][0] != ' ' && 
        board_7[0][0] == board_7[1][1] && 
        board_7[1][1] == board_7[2][2] && 
        board_7[2][2] == board_7[3][3] &&
        board_7[3][3] == board_7[4][4] &&
        board_7[4][4] == board_7[5][5] &&
        board_7[5][5] == board_7[6][6]) {
        return 1;
    }
    
        
    // Check diagonals (top-right to bottom-left)
    if (board_7[6][0] != ' ' && 
        board_7[6][0] == board_7[5][1] && 
        board_7[5][1] == board_7[4][2] && 
        board_7[4][2] == board_7[3][3] &&
        board_7[3][3] == board_7[2][4] &&
        board_7[2][4] == board_7[1][5] &&
        board_7[1][5] == board_7[0][6]) {
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board_7[i][j] != 'X' && board_7[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Find position on board based on user input (1-49)
void findPosition_7(int choice_7, int *row_7, int *col_7) {
    char target;
    if (choice_7 >= 1 && choice_7 <= 9) {
        target = '0' + choice_7;
    } else if (choice_7 >= 10 && choice_7 <= 23) {
        target = 'A' + (choice_7 - 10);
    } else if (choice_7 >= 24 && choice_7 <= 49) {
        // Map numbers 36-49 to the remaining characters in the board
        switch(choice_7) {
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
            case 36: target = '^'; break;
            case 37: target = '_'; break;
            case 38: target = '`'; break;
            case 39: target = 'a'; break;
            case 40: target = 'b'; break;
            case 41: target = 'c'; break;
            case 42: target = 'd'; break;
            case 43: target = 'e'; break;
            case 44: target = 'f'; break;
            case 45: target = 'g'; break;
            case 46: target = 'h'; break;
            case 47: target = 'i'; break;
            case 48: target = 'j'; break;
            case 49: target = 'k'; break;
            default: target = ' '; break;
        }    
    } else {
        *row_7 = -1;
        *col_7 = -1;
        return;
    }
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board_7[i][j] == target) {
                *row_7 = i;
                *col_7 = j;
                return;
            }
        }
    }
    *row_7 = -1;
    *col_7 = -1;
}

int main() {
    int player = 1;
    int choice_7;
    int gameStatus = 0;
    char mark;
    char player1[50], player2[50];

    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    printf("\nWelcome %s (X) and %s (O) to 7x7 Tic-Tac-Toe!\n", player1, player2);
    printf("Use numbers 1-49 to make your moves. You need 5 in a row_7 to win!\n");
    Sleep(2500);

    // Initialize display board with proper two-digit numbers
    updateDisplayBoard_7();

    do {
        system("cls");
        drawboard_7();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number (1-49): ", currentPlayer);
        if (scanf("%d", &choice_7) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            Sleep(1000);
            continue;
        }
        
        while (getchar() != '\n');
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice_7 >= 1 && choice_7 <= 49) {
            int row_7, col_7;
            findPosition_7(choice_7, &row_7, &col_7);
            
            if (row_7 != -1 && col_7 != -1) {
                if (board_7[row_7][col_7] != 'X' && board_7[row_7][col_7] != 'O') {
                    board_7[row_7][col_7] = mark;
                    updateDisplayBoard_7();
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
            printf("Invalid input! Please enter a number between 1 and 49.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin_7();
        if (gameStatus == 0) {
            gameStatus = checkDraw() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
        }
        
    } while (gameStatus == 0);
    
    system("cls");
    drawboard_7();
    
    if (gameStatus == 1) {
        char *winner = (player % 2 == 0) ? player1 : player2;
        printf(" %s WINS! \n", winner);
    } else {
        printf("It's a DRAW!\n");
    }
    
    return 0;
}