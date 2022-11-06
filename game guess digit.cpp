#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void menu()
{
	printf("**********************************\n");
	printf("*  1.play         0.exit      ****\n");
	printf("**********************************\n");
}
void game()
{                          //生成一个随机数
	int guess=0;          //用guess接收猜的数字
	int ret=0; 
	ret=rand()%100+1;      //生成1-100之间的数字          
	while(1)
	{
		printf("请猜数:");
		scanf("%d",&guess);
		if(guess>ret)
		{
			printf("猜大了\n");
		}
		else if(guess<ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
	Sleep(5000);
	system("cls");        //清空屏幕

}
int main()
{
	srand((unsigned int)time(NULL));      //拿时间戳来设置随机数的生成起始点
	int intput=0;                         //time_t time(time_t *timer)  NULL代表空指针
	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&intput);
		switch(intput)
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
					printf("输入错误\n");
					break;
				}
		}
	}while(intput);
	return 0;
}