#define _CRT_SECURE_NO_WARNINGS 1

#include "saolei.h"

void menu()
{
	printf("**********************\n");
	printf("*********ɨ��*********\n"); 
	printf("***play��1 exit��0****\n");
	printf("**********************\n");
}

void saolei()
{
	//�׵���Ϣ�洢
	//1.�����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.�Ų��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//3.��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//4.��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
	setmine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("�����룺>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			saolei();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default: 
			printf("�����������������!\n");
			break;
		}
		
	} while (input);
}

int main()
{
	test();
	return 0;
}