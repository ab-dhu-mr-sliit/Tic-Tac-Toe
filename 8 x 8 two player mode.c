#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Display board - shows two-digit numbers
char showboard_8[8][8][3] = {
    {"01", "02", "03", "04", "05", "06", "07", "08"},
    {"09", "10", "11", "12", "13", "14", "15", "16"},
    {"17", "18", "19", "20", "21", "22", "23", "24"},
    {"25", "26", "27", "28", "29", "30", "31", "32"},
    {"33", "34", "35", "36", "37", "38", "39", "40"},
    {"41", "42", "43", "44", "45", "46", "47", "48"},
    {"49", "50", "51", "52", "53", "54", "55", "56"},
    {"57", "58", "59", "60", "61", "62", "63", "64"}
};

// Internal board - stores single characters for logic
char board_8[8][8] = {
    {'1', '2', '3', '4', '5', '6', '7', '8'},
    {'9', 'A', 'B', 'C', 'D', 'E', 'F', 'G'},
    {'H', 'I', 'J', 'K', 'L', 'M', 'N', 'P'},  // Skip O
    {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y'},  // Skip X and O
    {'Z', '[', ']', '^', '_', '`', 'a', 'b'},
    {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'p', 'q', 'r', 's'},  // Skip o
    {'t', 'u', 'v', 'w', 'x', 'y', '{', '}'}
};

// Draw board with two-digit display
void drawboard_8() {
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf(" %s | %s | %s | %s | %s | %s | %s | %s ", 
               showboard_8[i][0], showboard_8[i][1], showboard_8[i][2], 
               showboard_8[i][3], showboard_8[i][4], showboard_8[i][5],
               showboard_8[i][6], showboard_8[i][7]);
        if (i < 7) {
            printf("\n----|----|----|----|----|----|----|----\n");
        }
    }
    printf("\n\n");
}

// Update display board based on internal board
void updateDisplayBoard_8() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board_8[i][j] == 'X') {
                strcpy(showboard_8[i][j], " X");
            } else if (board_8[i][j] == 'O') {
                strcpy(showboard_8[i][j], " O");
            } else {
                switch(i * 8 + j + 1){
                    case 1: strcpy(showboard_8[i][j], "01"); break;
                    case 2: strcpy(showboard_8[i][j], "02"); break;
                    case 3: strcpy(showboard_8[i][j], "03"); break;
                    case 4: strcpy(showboard_8[i][j], "04"); break;
                    case 5: strcpy(showboard_8[i][j], "05"); break;
                    case 6: strcpy(showboard_8[i][j], "06"); break;
                    case 7: strcpy(showboard_8[i][j], "07"); break;
                    case 8: strcpy(showboard_8[i][j], "08"); break;
                    case 9: strcpy(showboard_8[i][j], "09"); break;
                    case 10: strcpy(showboard_8[i][j], "10"); break;
                    case 11: strcpy(showboard_8[i][j], "11"); break;
                    case 12: strcpy(showboard_8[i][j], "12"); break;
                    case 13: strcpy(showboard_8[i][j], "13"); break;
                    case 14: strcpy(showboard_8[i][j], "14"); break;
                    case 15: strcpy(showboard_8[i][j], "15"); break;
                    case 16: strcpy(showboard_8[i][j], "16"); break;
                    case 17: strcpy(showboard_8[i][j], "17"); break;
                    case 18: strcpy(showboard_8[i][j], "18"); break;
                    case 19: strcpy(showboard_8[i][j], "19"); break;
                    case 20: strcpy(showboard_8[i][j], "20"); break;
                    case 21: strcpy(showboard_8[i][j], "21"); break;
                    case 22: strcpy(showboard_8[i][j], "22"); break;
                    case 23: strcpy(showboard_8[i][j], "23"); break;
                    case 24: strcpy(showboard_8[i][j], "24"); break;
                    case 25: strcpy(showboard_8[i][j], "25"); break;
                    case 26: strcpy(showboard_8[i][j], "26"); break;
                    case 27: strcpy(showboard_8[i][j], "27"); break;
                    case 28: strcpy(showboard_8[i][j], "28"); break;
                    case 29: strcpy(showboard_8[i][j], "29"); break;
                    case 30: strcpy(showboard_8[i][j], "30"); break;
                    case 31: strcpy(showboard_8[i][j], "31"); break;
                    case 32: strcpy(showboard_8[i][j], "32"); break;
                    case 33: strcpy(showboard_8[i][j], "33"); break;
                    case 34: strcpy(showboard_8[i][j], "34"); break;
                    case 35: strcpy(showboard_8[i][j], "35"); break;
                    case 36: strcpy(showboard_8[i][j], "36"); break;
                    case 37: strcpy(showboard_8[i][j], "37"); break;
                    case 38: strcpy(showboard_8[i][j], "38"); break;
                    case 39: strcpy(showboard_8[i][j], "39"); break;
                    case 40: strcpy(showboard_8[i][j], "40"); break;
                    case 41: strcpy(showboard_8[i][j], "41"); break;
                    case 42: strcpy(showboard_8[i][j], "42"); break;
                    case 43: strcpy(showboard_8[i][j], "43"); break;
                    case 44: strcpy(showboard_8[i][j], "44"); break;
                    case 45: strcpy(showboard_8[i][j], "45"); break;
                    case 46: strcpy(showboard_8[i][j], "46"); break;
                    case 47: strcpy(showboard_8[i][j], "47"); break;
                    case 48: strcpy(showboard_8[i][j], "48"); break;
                    case 49: strcpy(showboard_8[i][j], "49"); break;
                    case 50: strcpy(showboard_8[i][j], "50"); break;
                    case 51: strcpy(showboard_8[i][j], "51"); break;
                    case 52: strcpy(showboard_8[i][j], "52"); break;
                    case 53: strcpy(showboard_8[i][j], "53"); break;
                    case 54: strcpy(showboard_8[i][j], "54"); break;
                    case 55: strcpy(showboard_8[i][j], "55"); break;
                    case 56: strcpy(showboard_8[i][j], "56"); break;
                    case 57: strcpy(showboard_8[i][j], "57"); break;
                    case 58: strcpy(showboard_8[i][j], "58"); break;
                    case 59: strcpy(showboard_8[i][j], "59"); break;
                    case 60: strcpy(showboard_8[i][j], "60"); break;
                    case 61: strcpy(showboard_8[i][j], "61"); break;
                    case 62: strcpy(showboard_8[i][j], "62"); break;
                    case 63: strcpy(showboard_8[i][j], "63"); break;
                    case 64: strcpy(showboard_8[i][j], "64"); break;
                }
            }
        }
    }
}

// Check for win (5 in a row for 8x8 board)
int checkWin_8() {
    // Check rows
    for (int i = 0; i < 8; i++) {
        if (board_8[i][0] != ' ' && 
            board_8[i][0] == board_8[i][1] && 
            board_8[i][1] == board_8[i][2] && 
            board_8[i][2] == board_8[i][3] && 
            board_8[i][3] == board_8[i][4] && 
            board_8[i][4] == board_8[i][5] &&
            board_8[i][5] == board_8[i][6] &&
            board_8[i][6] == board_8[i][7]) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 8; i++) {
        if (board_8[0][i] != ' ' && 
            board_8[0][i] == board_8[1][i] && 
            board_8[1][i] == board_8[2][i] && 
            board_8[2][i] == board_8[3][i] && 
            board_8[3][i] == board_8[4][i] && 
            board_8[4][i] == board_8[5][i] &&
            board_8[5][i] == board_8[6][i] &&
            board_8[6][i] == board_8[7][i]) {
            return 1;
        }
    }
    
    // Check diagonals (top-left to bottom-right)
    if (board_8[0][0] != ' ' && 
        board_8[0][0] == board_8[1][1] && 
        board_8[1][1] == board_8[2][2] && 
        board_8[2][2] == board_8[3][3] &&
        board_8[3][3] == board_8[4][4] &&
        board_8[4][4] == board_8[5][5] &&
        board_8[5][5] == board_8[6][6] &&
        board_8[6][6] == board_8[7][7]) {
        return 1;
    }
    
    // Check diagonals (top-right to bottom-left)
    if (board_8[7][0] != ' ' && 
        board_8[7][0] == board_8[6][1] && 
        board_8[6][1] == board_8[5][2] && 
        board_8[5][2] == board_8[4][3] &&
        board_8[4][3] == board_8[3][3] &&
        board_8[3][4] == board_8[2][5] &&
        board_8[2][5] == board_8[1][6] &&
        board_8[1][6] == board_8[0][7]) {
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board_8[i][j] != 'X' && board_8[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Find position on board based on user input (1-64)
void findPosition_8(int choice_8, int *row_8, int *col_8) {
    char target;
    if (choice_8 >= 1 && choice_8 <= 9) {
        target = '0' + choice_8;
    } else if (choice_8 >= 10 && choice_8 <= 23) {
        target = 'A' + (choice_8 - 10);
    } else if (choice_8 >= 24 && choice_8 <= 64) {
        // Map numbers 36-64 to the remaining characters in the board
        switch(choice_8) {
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
            case 50: target = 'l'; break;
            case 51: target = 'm'; break;
            case 52: target = 'n'; break;
            case 53: target = 'p'; break;
            case 54: target = 'q'; break;
            case 55: target = 'r'; break;
            case 56: target = 's'; break;
            case 57: target = 't'; break;
            case 58: target = 'u'; break;
            case 59: target = 'v'; break;
            case 60: target = 'w'; break;
            case 61: target = 'x'; break;
            case 62: target = 'y'; break;
            case 63: target = '{'; break;
            case 64: target = '}'; break;
            default: target = ' '; break;
        }    
    } else {
        *row_8 = -1;
        *col_8 = -1;
        return;
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board_8[i][j] == target) {
                *row_8 = i;
                *col_8 = j;
                return;
            }
        }
    }
    *row_8 = -1;
    *col_8 = -1;
}

int main() {
    int player = 1;
    int choice_8;
    int gameStatus = 0;
    char mark;
    char player1[50], player2[50];

    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    printf("\nWelcome %s (X) and %s (O) to 8x8 Tic-Tac-Toe!\n", player1, player2);
    printf("Use numbers 1-64 to make your moves. You need 5 in a row_8 to win!\n");
    Sleep(2500);

    // Initialize display board with proper two-digit numbers
    updateDisplayBoard_8();

    do {
        system("cls");
        drawboard_8();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number (1-64): ", currentPlayer);
        if (scanf("%d", &choice_8) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            Sleep(1000);
            continue;
        }
        
        while (getchar() != '\n');
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice_8 >= 1 && choice_8 <= 64) {
            int row_8, col_8;
            findPosition_8(choice_8, &row_8, &col_8);
            
            if (row_8 != -1 && col_8 != -1) {
                if (board_8[row_8][col_8] != 'X' && board_8[row_8][col_8] != 'O') {
                    board_8[row_8][col_8] = mark;
                    updateDisplayBoard_8();
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
            printf("Invalid input! Please enter a number between 1 and 64.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin_8();
        if (gameStatus == 0) {
            gameStatus = checkDraw() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
        }
        
    } while (gameStatus == 0);
    
    system("cls");
    drawboard_8();
    
    if (gameStatus == 1) {
        char *winner = (player % 2 == 0) ? player1 : player2;
        printf(" %s WINS! \n", winner);
    } else {
        printf("It's a DRAW!\n");
    }
    
    return 0;
}