#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif 


#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE "pause"
    #define SLEEP(ms) Sleep(ms)
#else
    #define CLEAR "clear"
    #define PAUSE "read -p \"Press Enter to continue...\""
    #define SLEEP(ms) usleep((ms) * 1000)
#endif

// 0.All Header files.c

// Board setup
char **createBoard(int size);
void initializeBoard(char **board, int size);
void displayBoard(char **board, int size);
void freeBoard(char **board, int size);

// Player moves
int tryMode(FILE *fp);
int trySize(FILE *fp);
void getValidMove(char **board, int size, char symbol, FILE *fp);
void generateRandomMove(char **board, int size, int *row, int *col);

// Game logic
int checkWin(char **board, int size, char symbol);
int isBoardFull(char **board, int size);
int switchPlayer(int currentTurn, int totalPlayers);

// Logging
void logMove(FILE *fp, char player, int row, int col);
void logMode(FILE *fp, int mode);
void logisValidMode(FILE *fp, int mode);
void logSize(FILE *fp, int size);
void logisValidSize(FILE *fp, int size);
void logisValidMove(FILE *fp, int row, int col);
void logWins(FILE *fp, char symbols);
void logComputerWin(FILE *fp);
void logdisplayBoard(FILE *fp, char **board, int size);
