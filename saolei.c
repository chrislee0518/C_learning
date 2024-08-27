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
	// �߽���
	if (row <= 0 || row > ROW || col <= 0 || col > COL || show[row][col] != '*') 
	{
		return;
	}

	// ��ǵ�ǰ��Ԫ��
	int count = get_mine_count(mine, row, col);

	if (count > 0) 
	{
		show[row][col] = count + '0';
	}
	else 
	{
		show[row][col] = ' ';

		// �ݹ���ð˸�����
		Reveal(mine, show, row - 1, col,win);
		Reveal(mine, show, row + 1, col, win);
		Reveal(mine, show, row, col - 1, win);
		Reveal(mine, show, row, col + 1, win);
		Reveal(mine, show, row - 1, col - 1, win);
		Reveal(mine, show, row - 1, col + 1, win);
		Reveal(mine, show, row + 1, col - 1, win);
		Reveal(mine, show, row + 1, col + 1, win);
	}
	(*win)++;//�Ѿ�ɨ�Ŀո����
}


void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	//�ҳ�������
	while (win<row*col-EASY_COUNT)
	{
		printf("������ɨ������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//����
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//����
			else
			{
				//������Χ�ж��ٸ���
				//int count=get_mine_count(mine, x, y);
				//show[x][y] = count + '0';//�ַ�����
				//DisplayBoard(show, row, col);
				//win++;

				if (show[x][y] == '*') 
				{
					// ���û�б���ʾ��
					Reveal(mine, show, x, y,&win);
					DisplayBoard(show, row, col);

				}
			}
		}
		else
		{
			printf("���곬����Χ�����������룡\n");
		}
	}
	if (win == row * col - EASY_COUNT)//��ը��Ҳ������ѭ������Ҫ�ж�
	{
		printf("��ϲ���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}
	
}


//չ������ �ݹ� ָ��
//�����겻���ף�
//��������ΧҲ������