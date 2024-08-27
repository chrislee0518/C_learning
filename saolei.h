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
//����board[ROWS][COLS]��Ȼ��ROWS COLS����ΪDisplayBoard����ʵ�δ����
//�������mine����mine����ʱ����mine[ROWS][COLS]��������Ǽ��м��е�����
//���յ��β������Ҫ�Ǽ��м��У���Ҫ����һ�¡�����ʱֻ����ʵ��ROW��COL����

void setmine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void Reveal(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int *win);
