#pragma once
//game.h
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define  ROW  3
#define  COL  3
//��������
void Initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);

//������Ϸ״̬
//���Ӯ - ��x��
//����Ӯ - ��o��
//ƽ�� - ��q��
//���� - ��c��
char iswin(char board[ROW][COL], int row, int col);




//game.c
#include"game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	while (1)
	{
		printf("���������:");
		scanf_s("%d%d", &x, &y);
		//�ж���x��y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("��λ���ѱ�ռ��\n");
			}

		}
		else
		{
			printf("�������");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'o';
			break;
		}
	}
}
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;                 //����0��������û��
			}
		}
	}
	return 1;                             //����1������������
}

char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�ÿһ���Ƿ��н��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//�ж�ÿһ���Ƿ��н��
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�ж������Խ����Ƿ��н��
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (1 == isfull(board, ROW, COL))
	{
		return 'q';
	}
	else
		return 'c';
}



//test.c
#include"game.h"
void menu()
{
	printf("************************************\n");
	printf("***  1.play          0.exit     ****\n");
	printf("************************************\n");
}
//������Ϸ�㷨��ʵ��
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };                   //����-����߳���������Ϣ
	Initboard(board, ROW, COL);                     //��ʼ������
	displayboard(board, ROW, COL);                   //��ӡ����
	//����
	while (1)
	{
		playermove(board, ROW, COL);                //�������
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);               //�ж�����Ƿ�Ӯ
		if (ret != 'c')
		{
			break;
		}
		computermove(board, ROW, COL);              //��������
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);               //�жϵ����Ƿ�Ӯ
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == 'x')
	{
		printf("���ʤ");
		Sleep(2000);
		system("cls");
	}
	else if (ret == 'o')
	{
		printf("����ʤ");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("ƽ��");
		Sleep(2000);
		system("cls");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("�˳���Ϸ\n");
			break;
		}
		default:
		{
			printf("�������������ѡ��\n");
			break;
		}
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}