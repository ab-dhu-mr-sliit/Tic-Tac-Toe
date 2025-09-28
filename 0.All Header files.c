#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 

// 0.All Header files.c

#ifndef GAME_H
#define GAME_H


// Board setup
char **createBoard(int size);
void initializeBoard(char **board, int size);
void displayBoard(char **board, int size);
void freeBoard(char **board, int size);

// Player moves
void getValidMove(char **board, int size, char symbol, FILE *fp);
void generateRandomMove(char **board, int size, int *row, int *col);

// Game logic
int checkWin(char **board, int size, char symbol);
int isBoardFull(char **board, int size);
int switchPlayer(int currentTurn, int totalPlayers);

// Logging
void logMove(FILE *fp, char player, int row, int col);
void logWins(FILE *fp, char symbols);

#endif