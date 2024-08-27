#define _CRT_SECURE_NO_WARNINGS 1

#include "saolei.h"

void menu()
{
	printf("**********************\n");
	printf("*********扫雷*********\n"); 
	printf("***play：1 exit：0****\n");
	printf("**********************\n");
}

void saolei()
{
	//雷的信息存储
	//1.布置雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.排查雷的信息
	char show[ROWS][COLS] = { 0 };
	//3.初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//4.打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	setmine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			saolei();
			break;
		case 0:
			printf("退出\n");
			break;
		default: 
			printf("输入错误，请重新输入!\n");
			break;
		}
		
	} while (input);
}

int main()
{
	test();
	return 0;
}