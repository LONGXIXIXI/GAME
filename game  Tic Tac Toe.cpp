#pragma once
//game.h
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define  ROW  3
#define  COL  3
//函数声明
void Initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);

//四种游戏状态
//玩家赢 - ‘x’
//电脑赢 - ‘o’
//平局 - ‘q’
//继续 - ‘c’
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
	printf("玩家走\n");
	while (1)
	{
		printf("请玩家下棋:");
		scanf_s("%d%d", &x, &y);
		//判断下x，y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("该位置已被占用\n");
			}

		}
		else
		{
			printf("输入错误");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
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
				return 0;                 //返回0代表棋盘没满
			}
		}
	}
	return 1;                             //返回1代表棋盘满了
}

char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断每一行是否有结果
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	//判断每一列是否有结果
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断俩个对角线是否有结果
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
//整个游戏算法的实现
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };                   //数组-存放走出的棋盘信息
	Initboard(board, ROW, COL);                     //初始化数组
	displayboard(board, ROW, COL);                   //打印棋盘
	//下棋
	while (1)
	{
		playermove(board, ROW, COL);                //玩家下棋
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);               //判断玩家是否赢
		if (ret != 'c')
		{
			break;
		}
		computermove(board, ROW, COL);              //电脑下棋
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);               //判断电脑是否赢
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == 'x')
	{
		printf("玩家胜");
		Sleep(2000);
		system("cls");
	}
	else if (ret == 'o')
	{
		printf("电脑胜");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("平局");
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
		printf("请选择：");
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
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新选择\n");
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