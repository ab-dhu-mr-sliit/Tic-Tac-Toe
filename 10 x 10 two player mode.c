#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// Display board - shows two-digit numbers
char showboard_10[10][10][4] = {
    {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"},
    {"11", "12", "13", "14", "15", "16", "17", "18", "19", "20"},
    {"21", "22", "23", "24", "25", "26", "27", "28", "29", "30"},
    {"31", "32", "33", "34", "35", "36", "37", "38", "39", "40"},
    {"41", "42", "43", "44", "45", "46", "47", "48", "49", "50"},
    {"51", "52", "53", "54", "55", "56", "57", "58", "59", "60"},
    {"61", "62", "63", "64", "65", "66", "67", "68", "69", "70"},
    {"71", "72", "73", "74", "75", "76", "77", "78", "79", "80"},
    {"81", "82", "83", "84", "85", "86", "87", "88", "89", "90"},
    {"91", "92", "93", "94", "95", "96", "97", "98", "99", "100"}
};

// Internal board - stores single characters for logic
char board_10[10][10] = {
    {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A'},
    {'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'},
    {'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},  // Skip O
    {'W', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},  // Skip X
    {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},  // Include lowercase o
    {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!'},  // Include lowercase x
    {'"', '#', '$', '%', '&', '\'', '(', ')', '*', '+'},
    {',', '-', '.', '/', ':', ';', '<', '=', '>', '?'},
    {'@', '[', '\\', ']', '^', '_', '`', '{', '|', '}'},
    {'~', ' ', '\t', '\n', '\r', '\v', '\f', '\b', '\a', '0'}  // 0 in last position
};

// Draw board with two-digit display
void drawboard_10() {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf(" %s | %s | %s | %s | %s | %s | %s | %s | %s | %s ", 
               showboard_10[i][0], showboard_10[i][1], showboard_10[i][2], 
               showboard_10[i][3], showboard_10[i][4], showboard_10[i][5],
               showboard_10[i][6], showboard_10[i][7], showboard_10[i][8], showboard_10[i][9]);
        if (i < 9) {
            printf("\n----|----|----|----|----|----|----|----|----|----\n");
        }
    }
    printf("\n\n");
}

// Update display board based on internal board
void updateDisplayBoard_10() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board_10[i][j] == 'X') {
                strcpy(showboard_10[i][j], " X");
            } else if (board_10[i][j] == 'O') {
                strcpy(showboard_10[i][j], " O");
            } else {
                switch(i * 10 + j + 1){
                    case 1: strcpy(showboard_10[i][j], "01"); break;
                    case 2: strcpy(showboard_10[i][j], "02"); break;
                    case 3: strcpy(showboard_10[i][j], "03"); break;
                    case 4: strcpy(showboard_10[i][j], "04"); break;
                    case 5: strcpy(showboard_10[i][j], "05"); break;
                    case 6: strcpy(showboard_10[i][j], "06"); break;
                    case 7: strcpy(showboard_10[i][j], "07"); break;
                    case 8: strcpy(showboard_10[i][j], "08"); break;
                    case 9: strcpy(showboard_10[i][j], "09"); break;
                    case 10: strcpy(showboard_10[i][j], "10"); break;
                    case 11: strcpy(showboard_10[i][j], "11"); break;
                    case 12: strcpy(showboard_10[i][j], "12"); break;
                    case 13: strcpy(showboard_10[i][j], "13"); break;
                    case 14: strcpy(showboard_10[i][j], "14"); break;
                    case 15: strcpy(showboard_10[i][j], "15"); break;
                    case 16: strcpy(showboard_10[i][j], "16"); break;
                    case 17: strcpy(showboard_10[i][j], "17"); break;
                    case 18: strcpy(showboard_10[i][j], "18"); break;
                    case 19: strcpy(showboard_10[i][j], "19"); break;
                    case 20: strcpy(showboard_10[i][j], "20"); break;
                    case 21: strcpy(showboard_10[i][j], "21"); break;
                    case 22: strcpy(showboard_10[i][j], "22"); break;
                    case 23: strcpy(showboard_10[i][j], "23"); break;
                    case 24: strcpy(showboard_10[i][j], "24"); break;
                    case 25: strcpy(showboard_10[i][j], "25"); break;
                    case 26: strcpy(showboard_10[i][j], "26"); break;
                    case 27: strcpy(showboard_10[i][j], "27"); break;
                    case 28: strcpy(showboard_10[i][j], "28"); break;
                    case 29: strcpy(showboard_10[i][j], "29"); break;
                    case 30: strcpy(showboard_10[i][j], "30"); break;
                    case 31: strcpy(showboard_10[i][j], "31"); break;
                    case 32: strcpy(showboard_10[i][j], "32"); break;
                    case 33: strcpy(showboard_10[i][j], "33"); break;
                    case 34: strcpy(showboard_10[i][j], "34"); break;
                    case 35: strcpy(showboard_10[i][j], "35"); break;
                    case 36: strcpy(showboard_10[i][j], "36"); break;
                    case 37: strcpy(showboard_10[i][j], "37"); break;
                    case 38: strcpy(showboard_10[i][j], "38"); break;
                    case 39: strcpy(showboard_10[i][j], "39"); break;
                    case 40: strcpy(showboard_10[i][j], "40"); break;
                    case 41: strcpy(showboard_10[i][j], "41"); break;
                    case 42: strcpy(showboard_10[i][j], "42"); break;
                    case 43: strcpy(showboard_10[i][j], "43"); break;
                    case 44: strcpy(showboard_10[i][j], "44"); break;
                    case 45: strcpy(showboard_10[i][j], "45"); break;
                    case 46: strcpy(showboard_10[i][j], "46"); break;
                    case 47: strcpy(showboard_10[i][j], "47"); break;
                    case 48: strcpy(showboard_10[i][j], "48"); break;
                    case 49: strcpy(showboard_10[i][j], "49"); break;
                    case 50: strcpy(showboard_10[i][j], "50"); break;
                    case 51: strcpy(showboard_10[i][j], "51"); break;
                    case 52: strcpy(showboard_10[i][j], "52"); break;
                    case 53: strcpy(showboard_10[i][j], "53"); break;
                    case 54: strcpy(showboard_10[i][j], "54"); break;
                    case 55: strcpy(showboard_10[i][j], "55"); break;
                    case 56: strcpy(showboard_10[i][j], "56"); break;
                    case 57: strcpy(showboard_10[i][j], "57"); break;
                    case 58: strcpy(showboard_10[i][j], "58"); break;
                    case 59: strcpy(showboard_10[i][j], "59"); break;
                    case 60: strcpy(showboard_10[i][j], "60"); break;
                    case 61: strcpy(showboard_10[i][j], "61"); break;
                    case 62: strcpy(showboard_10[i][j], "62"); break;
                    case 63: strcpy(showboard_10[i][j], "63"); break;
                    case 64: strcpy(showboard_10[i][j], "64"); break;
                    case 65: strcpy(showboard_10[i][j], "65"); break;
                    case 66: strcpy(showboard_10[i][j], "66"); break;
                    case 67: strcpy(showboard_10[i][j], "67"); break;
                    case 68: strcpy(showboard_10[i][j], "68"); break;
                    case 69: strcpy(showboard_10[i][j], "69"); break;
                    case 70: strcpy(showboard_10[i][j], "70"); break;
                    case 71: strcpy(showboard_10[i][j], "71"); break;
                    case 72: strcpy(showboard_10[i][j], "72"); break;
                    case 73: strcpy(showboard_10[i][j], "73"); break;
                    case 74: strcpy(showboard_10[i][j], "74"); break;
                    case 75: strcpy(showboard_10[i][j], "75"); break;
                    case 76: strcpy(showboard_10[i][j], "76"); break;
                    case 77: strcpy(showboard_10[i][j], "77"); break;
                    case 78: strcpy(showboard_10[i][j], "78"); break;
                    case 79: strcpy(showboard_10[i][j], "79"); break;
                    case 80: strcpy(showboard_10[i][j], "80"); break;
                    case 81: strcpy(showboard_10[i][j], "81"); break;
                    case 82: strcpy(showboard_10[i][j], "82"); break;
                    case 83: strcpy(showboard_10[i][j], "83"); break;
                    case 84: strcpy(showboard_10[i][j], "84"); break;
                    case 85: strcpy(showboard_10[i][j], "85"); break;
                    case 86: strcpy(showboard_10[i][j], "86"); break;
                    case 87: strcpy(showboard_10[i][j], "87"); break;
                    case 88: strcpy(showboard_10[i][j], "88"); break;
                    case 89: strcpy(showboard_10[i][j], "89"); break;
                    case 90: strcpy(showboard_10[i][j], "90"); break;
                    case 91: strcpy(showboard_10[i][j], "91"); break;
                    case 92: strcpy(showboard_10[i][j], "92"); break;
                    case 93: strcpy(showboard_10[i][j], "93"); break;
                    case 94: strcpy(showboard_10[i][j], "94"); break;
                    case 95: strcpy(showboard_10[i][j], "95"); break;
                    case 96: strcpy(showboard_10[i][j], "96"); break;
                    case 97: strcpy(showboard_10[i][j], "97"); break;
                    case 98: strcpy(showboard_10[i][j], "98"); break;
                    case 99: strcpy(showboard_10[i][j], "99"); break;
                    case 100: strcpy(showboard_10[i][j], "100"); break;
                }
            }
        }
    }
}

// Check for win (5 in a row for 10x10 board)
int checkWin_10() {
    // Check rows
    for (int i = 0; i < 10; i++) {
        if (board_10[i][0] != ' ' && 
            board_10[i][0] == board_10[i][1] && 
            board_10[i][1] == board_10[i][2] && 
            board_10[i][2] == board_10[i][3] && 
            board_10[i][3] == board_10[i][4] && 
            board_10[i][4] == board_10[i][5] &&
            board_10[i][5] == board_10[i][6] &&
            board_10[i][6] == board_10[i][7] &&
            board_10[i][7] == board_10[i][8] &&
            board_10[i][8] == board_10[i][9]) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 10; i++) {
        if (board_10[0][i] != ' ' && 
            board_10[0][i] == board_10[1][i] && 
            board_10[1][i] == board_10[2][i] && 
            board_10[2][i] == board_10[3][i] && 
            board_10[3][i] == board_10[4][i] && 
            board_10[4][i] == board_10[5][i] &&
            board_10[5][i] == board_10[6][i] &&
            board_10[6][i] == board_10[7][i] &&
            board_10[7][i] == board_10[8][i] &&
            board_10[8][i] == board_10[9][i]) {
            return 1;
        }
    }
    
    // Check diagonals (top-left to bottom-right)
    if (board_10[0][0] != ' ' && 
        board_10[0][0] == board_10[1][1] && 
        board_10[1][1] == board_10[2][2] && 
        board_10[2][2] == board_10[3][3] &&
        board_10[3][3] == board_10[4][4] &&
        board_10[4][4] == board_10[5][5] &&
        board_10[5][5] == board_10[6][6] &&
        board_10[6][6] == board_10[7][7] &&
        board_10[7][7] == board_10[8][8] &&
        board_10[8][8] == board_10[9][9]) {
        return 1;
    }
    
    // Check diagonals (top-right to bottom-left)
    if (board_10[9][0] != ' ' && 
        board_10[9][0] == board_10[8][1] && 
        board_10[8][1] == board_10[7][2] && 
        board_10[7][2] == board_10[6][3] &&
        board_10[6][3] == board_10[5][4] &&
        board_10[5][4] == board_10[4][4] &&
        board_10[4][5] == board_10[3][6] &&
        board_10[3][6] == board_10[2][7] &&
        board_10[2][7] == board_10[1][8] &&
        board_10[1][8] == board_10[0][9]) {
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board_10[i][j] != 'X' && board_10[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Find position on board based on user input (1-100)
void findPosition_10(int choice_10, int *row_10, int *col_10) {
    char target;
    if (choice_10 >= 1 && choice_10 <= 9) {
        target = '0' + choice_10;
    } else if (choice_10 >= 10 && choice_10 <= 23) {
        target = 'A' + (choice_10 - 10);
    } else if (choice_10 >= 24 && choice_10 <= 100) {
        // Map numbers 36-100 to the remaining characters in the board
        switch(choice_10) {
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

            case 34: target = 'a'; break;
            case 35: target = 'b'; break;
            case 36: target = 'c'; break;
            case 37: target = 'd'; break;
            case 38: target = 'e'; break;
            case 39: target = 'f'; break;
            case 40: target = 'g'; break;
            case 41: target = 'h'; break;
            case 42: target = 'i'; break;
            case 43: target = 'j'; break;
            case 44: target = 'k'; break;
            case 45: target = 'l'; break;
            case 46: target = 'm'; break;
            case 47: target = 'n'; break;
            case 48: target = 'o'; break;
            case 49: target = 'p'; break;
            case 50: target = 'q'; break;
            case 51: target = 'r'; break;
            case 52: target = 's'; break;
            case 53: target = 't'; break;
            case 54: target = 'u'; break;
            case 55: target = 'v'; break;
            case 56: target = 'w'; break;
            case 57: target = 'x'; break;
            case 58: target = 'y'; break;
            case 59: target = 'z'; break;

            case 60: target = '!'; break;
            case 61: target = '"'; break;
            case 62: target = '#'; break;
            case 63: target = '$'; break;
            case 64: target = '%'; break;
            case 65: target = '&'; break;
            case 66: target = '\''; break;
            case 67: target = '('; break;
            case 68: target = ')'; break;
            case 69: target = '*'; break;
            case 70: target = '+'; break;
            case 71: target = ','; break;
            case 72: target = '-'; break;
            case 73: target = '.'; break;
            case 74: target = '/'; break;
            case 75: target = ':'; break;
            case 76: target = ';'; break;
            case 77: target = '<'; break;
            case 78: target = '='; break;
            case 79: target = '>'; break;
            case 80: target = '?'; break;
            case 81: target = '@'; break;
            case 82: target = '['; break;
            case 83: target = '\\'; break;
            case 84: target = ']'; break;
            case 85: target = '^'; break;
            case 86: target = '_'; break;
            case 87: target = '`'; break;
            case 88: target = '{'; break;
            case 89: target = '|'; break;
            case 90: target = '}'; break;
            case 91: target = '~'; break;
            case 92: target = ' '; break;
            case 93: target = '\t'; break;
            case 94: target = '\n'; break;
            case 95: target = '\r'; break;
            case 96: target = '\v'; break;
            case 97: target = '\f'; break;
            case 98: target = '\b'; break;
            case 99: target = '\a'; break;
            case 100: target = '0'; break;
            default: target = ' '; break;
        }    
    } else {
        *row_10 = -1;
        *col_10 = -1;
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board_10[i][j] == target) {
                *row_10 = i;
                *col_10 = j;
                return;
            }
        }
    }
    *row_10 = -1;
    *col_10 = -1;
}

int main() {
    int player = 1;
    int choice_10;
    int gameStatus = 0;
    char mark;
    char player1[50], player2[50];

    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0;

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0;

    printf("\nWelcome %s (X) and %s (O) to 10x10 Tic-Tac-Toe!\n", player1, player2);
    printf("Use numbers 1-100 to make your moves. You need 5 in a row_10 to win!\n");
    Sleep(2500);

    // Initialize display board with proper two-digit numbers
    updateDisplayBoard_10();

    do {
        system("cls");
        drawboard_10();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number (1-100): ", currentPlayer);
        if (scanf("%d", &choice_10) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            Sleep(1000);
            continue;
        }
        
        while (getchar() != '\n');
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice_10 >= 1 && choice_10 <= 100) {
            int row_10, col_10;
            findPosition_10(choice_10, &row_10, &col_10);
            
            if (row_10 != -1 && col_10 != -1) {
                if (board_10[row_10][col_10] != 'X' && board_10[row_10][col_10] != 'O') {
                    board_10[row_10][col_10] = mark;
                    updateDisplayBoard_10();
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
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin_10();
        if (gameStatus == 0) {
            gameStatus = checkDraw() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
        }
        
    } while (gameStatus == 0);
    
    system("cls");
    drawboard_10();
    
    if (gameStatus == 1) {
        char *winner = (player % 2 == 0) ? player1 : player2;
        printf(" %s WINS! \n", winner);
    } else {
        printf("It's a DRAW!\n");
    }
    
    return 0;
}