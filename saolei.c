#define _CRT_SECURE_NO_WARNINGS 1

#include "saolei.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1~9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}


	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1]
		+ mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]-8*'0';
}

void Reveal(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col,int *win)
{
	// 边界检查
	if (row <= 0 || row > ROW || col <= 0 || col > COL || show[row][col] != '*') 
	{
		return;
	}

	// 标记当前单元格
	int count = get_mine_count(mine, row, col);

	if (count > 0) 
	{
		show[row][col] = count + '0';
	}
	else 
	{
		show[row][col] = ' ';

		// 递归调用八个方向
		Reveal(mine, show, row - 1, col,win);
		Reveal(mine, show, row + 1, col, win);
		Reveal(mine, show, row, col - 1, win);
		Reveal(mine, show, row, col + 1, win);
		Reveal(mine, show, row - 1, col - 1, win);
		Reveal(mine, show, row - 1, col + 1, win);
		Reveal(mine, show, row + 1, col - 1, win);
		Reveal(mine, show, row + 1, col + 1, win);
	}
	(*win)++;//已经扫的空格计数
}


void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	//找出所有雷
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入扫雷坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//非雷
			else
			{
				//计算周围有多少个雷
				//int count=get_mine_count(mine, x, y);
				//show[x][y] = count + '0';//字符数组
				//DisplayBoard(show, row, col);
				//win++;

				if (show[x][y] == '*') 
				{
					// 如果没有被揭示过
					Reveal(mine, show, x, y,&win);
					DisplayBoard(show, row, col);

				}
			}
		}
		else
		{
			printf("坐标超出范围，请重新输入！\n");
		}
	}
	if (win == row * col - EASY_COUNT)//被炸死也会跳出循环，需要判断
	{
		printf("恭喜排雷成功！\n");
		DisplayBoard(mine, row, col);
	}
	
}


//展开功能 递归 指针
//该坐标不是雷；
//该坐标周围也不是雷