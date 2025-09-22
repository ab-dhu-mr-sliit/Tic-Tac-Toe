#include <stdio.h>
#include <windows.h>
#include <string.h>

// Board
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Draw board 
void drawBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

// Check for win
int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
    return 0;
}

// Check for draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Main game function
int main() {
    int player = 1; // Player 1 starts
    int choice;
    int gameStatus = 0; // 0 = game ongoing, 1 = win, 2 = draw
    char mark; // X or O
    char player1[50], player2[50];

    // Get player names
    printf("Enter name for Player 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = 0; // remove newline

    printf("Enter name for Player 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = 0; // remove newline

    printf("\nWelcome %s (X) and %s (O) to Tic-Tac-Toe!\n", player1, player2);
    Sleep(1500);

    do {
        // Show the current board
        drawBoard();
        
        player = (player % 2) ? 1 : 2;
        char *currentPlayer = (player == 1) ? player1 : player2;

        printf("%s, enter a number: ", currentPlayer);
        scanf("%d", &choice);
        
        mark = (player == 1) ? 'X' : 'O';
        
        // Validate input and update board
        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = mark;
                player++;
            } else {
                printf("Invalid move! That position is already taken.\n");
                Sleep(1000);
            }
        } else {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            Sleep(1000);
        }
        
        gameStatus = checkWin();
        if (gameStatus == 0) {
            gameStatus = checkDraw() ? 2 : 0;
        }

        if (gameStatus == 0) {
            printf("\nUpdating board...\n");
            Sleep(1000);
            system("Clear screen for next turn"); // Clear screen for next turn
        }
        
    } while (gameStatus == 0);
    
    // Final board after game ends
    drawBoard();
    
    if (gameStatus == 1) {
        // player was incremented after move, so winner is (player % 2) + 1
        char *winner = ((player % 2) + 1 == 1) ? player1 : player2;
        printf("🎉 %s WINS! 🎉\n", winner);
    } else {
        printf("It's a DRAW!\n");
    }
    
    return 0;
}

