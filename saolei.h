#pragma once
#include <stdio.h>
#define EASY_COUNT 10
#define ROW 9
#define COL 9
extern int revealedCells;

#define ROWS ROW+2
#define COLS COL+2
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);
//这里board[ROWS][COLS]仍然用ROWS COLS，因为DisplayBoard（）实参传入的
//数组就是mine，而mine定义时就是mine[ROWS][COLS]，传入的是几行几列的数组
//接收的形参数组就要是几行几列，需要保持一致。操作时只操作实参ROW和COL行列

void setmine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void Reveal(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int *win);
