/**
 * author: ciabeta.
 * date: 2018.11.2
 * description: 一个命令行中的贪吃蛇小程序，准备用于讲解C语言进阶和makefile。
 * 操作：wasd实现上下左右移动
 * 实现步骤
 * 1、画地图边界
 * 2、画蛇头，实现移动
 * 3、生成蛋糕
 * 4、蛇吃到蛋糕身体变长
 * 5、碰撞结束
 * 截至2018.11.2 20:59存在问题：
 * 1、检测按键事件不全，例如，当前头部在左，突然按下d则无法吃掉曲奇
 */
#include<stdio.h>

#include<time.h>
//kbhit和getch函数获取用户输入
#include<conio.h>
//用于清屏
#include<windows.h>
#define ROW 20
#define COL 80
#define WAIT 100
/**
 * 初始化全局变量
 */
//整体地图的打印
char map[ROW][COL];
//按键
char key;
//曲奇坐标
struct Cookie{
	int x;
	int y;
}cookie;
//蛇信息
struct Snake{
	int headx, heady;
	//蛇长度由蛇身体数组大小限制
	int lenth;
	//蛇身体的256块的x, y 坐标
	int bodyx[256];
	int bodyy[256];
}snake;
/**
 * 用于初始化地图和蛇原点
 */
int initmap()
{
	int i, j;
	//初始化地图边界
	for(i = 0; i < ROW; i++)
	{
		if(i == 0 || i == ROW -1)
			for(j = 0; j < COL; j++)
				map[i][j] = '#';
		map[i][0] = '#';
		map[i][COL-1] = '#';
	}
	//边界之外暂列为空
	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			if(map[i][j] != '#')
				map[i][j] = ' ';
		}
	}
	//初始化蛇
	snake.headx = COL/2;
	snake.heady = ROW/2;
	snake.lenth = 0;
	//由于已经在printall中进行打印，所以此处可以省略
	//map[snake.heady][snake.headx] = '*';
	return 0;
}
/**判断是否属于蛇头或身体，是则返回1
 */
int ifbelong(int x, int y)
{
	//属于蛇头
	if(y == snake.heady && x == snake.headx)
		return 1;
	//属于蛇身体
	else if(snake.lenth > 0)
	{
		int i;
		for(i = 0; i < snake.lenth; i++)
		{
			if(snake.bodyx[i] == x && snake.bodyy[i] == y)
				return 1;
		}
	}
	return 0;
}
/**
 * 实现合并所有元素，输出图像
 * 此函数内部调用了初始化函数和调用蛇原点
 */
int printall()
{
	system("cls");
	int y, x;
	for(y = 0; y < ROW; y++)
	{
		for(x = 0; x < COL; x++)
		{
			//检测坐标是否有食物或蛇，有则输出，没有则输出空白
			if(ifbelong(x, y))
			{
				printf("*");
			}
			else if(y == cookie.y && x == cookie.x)
			{
				printf("@");
			}
			else
				printf("%c", map[y][x]);
		}
		printf("\n");
	}
	return 0;
}
/**
 * 用于实现输入检测的参数处理
 */
int getkey()
{
	/**
	 * 如果得到了按键输入，则做更改，没有得到按键输入则按照原来的路线继续
	 */
	if(kbhit())
	{
		key = getch();
	}
	if(key == 'w')
		snake.heady--;
	else if(key == 's')
		snake.heady++;
	else if(key == 'a')
		snake.headx--;
	else if(key == 'd')
		snake.headx++;
	return 0;
}
/**
 * 创建一个新的曲奇，不能在蛇身上，不能在地图外
 * 1<=x<=COL-1, 1<=y<=ROW-1
 */
int makecookie()
{
	//创建以时间为输入的随机数
	srand((unsigned)time(NULL));
	//只保证不在蛇头，蛇身暂时没写，归结到蛇整体检测需要新函数，判定返回值
	do{
		cookie.x = (rand() % (COL-2))+1;
	}while(cookie.x == snake.headx);
	do{
		cookie.y = (rand() % (ROW-2))+1;
	}while(cookie.y == snake.heady);
	return 0;
}
/**
 * 吃到曲奇后，需要做个新曲奇，然后完成蛇的位置赋值
 */
int aftereat()
{
	makecookie();
	//将现在的蛇头的位置定义为body[尾巴]坐标
	if(snake.lenth != 0)
	{
		int i = 0;
		while(i < snake.lenth)
		{
			snake.bodyx[snake.lenth] = snake.bodyx[snake.lenth-1];
			snake.bodyy[snake.lenth] = snake.bodyy[snake.lenth-1];
			i++;
		}
	}
	snake.bodyx[0] = snake.headx;
	snake.bodyy[0] = snake.heady;
	snake.lenth++;
	return 1;
}
/**
 * 判断蛇距离曲奇为0，且没有改变方向，则为蛇吃到曲奇
 * 分成四种情况，即
 * 1、key为a且曲奇在蛇左边，
 * 2、key为w且曲奇在蛇上面，
 * 3、key为s且曲奇在蛇下面，
 * 4、key为d且曲奇在蛇右边。
 * 此时做一个新曲奇，蛇身体增加，即曲奇变成蛇头位置
 */
int ifeatcookie()
{
	if(key == 'a' && snake.headx == (cookie.x + 1) && snake.heady == cookie.y)
	{
		return aftereat();
	}
	else if(key == 'w' && snake.headx == cookie.x && snake.heady == (cookie.y + 1))
	{
		return aftereat();
	}
	else if(key == 's' && snake.headx == cookie.x && snake.heady == (cookie.y - 1))
	{
		return aftereat();
	}
	else if(key == 'd' && snake.headx == (cookie.x-1) && snake.heady == cookie.y)
	{
		return aftereat();
	}
	return 0;
}
/**
 * 实现整体运动，头部此时未更改，此时头等于身体1
 * 将头坐标赋值给body[0]，然后依次赋值到body[snake.lenth-1]
 */
int snakemove()
{
	int i;
	if(snake.lenth != 0)
	{
		for(i = (snake.lenth-1); i >= 0; i--)
		{
			if(i >= 1)
			{
				//一个特殊情况，蛇吃到曲奇，此时尾巴和尾巴上一个重合
				snake.bodyx[i] = snake.bodyx[i-1];
				snake.bodyy[i] = snake.bodyy[i-1];
			}
			//如果蛇长度为1，那么直接从头部赋值
			else if(i == 0)
			{
				snake.bodyx[i] = snake.headx;
				snake.bodyy[i] = snake.heady;
			}
		}
	}
}
/**
 * 判断是否撞墙，撞自己
 */
int ifcrack()
{
	if(snake.headx == 0 || snake.heady == 0)
		return 1;
	else if(snake.lenth > 0)
	{
		int i;
		for(i = 0; i < snake.lenth; i++)
		{
			if((snake.bodyx[i]==snake.headx)&&(snake.bodyy[i]==snake.heady))
				return 1;
		}
	}
	return 0;
}
int main()
{
	initmap();
	makecookie();
	while(1)
	{
		getkey();
		printall();
		if(ifcrack())
		{
			printf("game over! Score： %d", snake.lenth);
			break;
		}
		if(!ifeatcookie())
			snakemove();
		Sleep(WAIT);
	}
	getchar();
	return 0;
}