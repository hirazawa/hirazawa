#include <conio.h>
#include <ctype.h>
#include<iostream>
#include<iomanip>
#include<time.h>
#include<cmath>

using namespace std;

const int X = 4;
const int Y = 4;
int g[4][4] = { 0 };
int ch = 0;

void draw()//绘制游戏界面
{
	cout << "欢迎来到2048！\n" << endl;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cout << setw(5) << setfill(' ') << g[i][j];
		}
		cout << endl;
	}
}

void start()//游戏开始
{
	system("cls");
	srand(time(0)); //开局在两个随机位置生成随机的2或4
	int ran = 0, m = 0, n = 0;
	for (int i = 0; i < 2; i++)
	{
		m = rand() % 16;
		while (g[(m) / 4][m % 4] != 0)
		{
			m = rand() % 16;
		}
		n = 1 + rand() % 2;
		g[(m) / 4][m % 4] = pow(2, n);
		draw();
		if (i < 1)
			system("cls");
	}
}

void set_ch()
{
	ch = _getch();//响应键盘上下左右键
	if (ch == 224)
	{
		ch = _getch();
	}
}

void play()//游戏进行
{
	switch (ch)
	{
	case 72://键盘“上”
		system("cls");
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < X; i++)
			{
				for (int j = 0; j < Y; j++)
				{
					if (g[i][j] != 0 && i>0)
					{
						if (g[i - 1][j] == 0)
						{
							g[i - 1][j] = g[i][j];
							g[i][j] = 0;
						}
					}
				}
			}
		}
		break;
	case 80://键盘“下”
		system("cls");
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < X; i++)
			{
				for (int j = 0; j < Y; j++)
				{
					if (g[i][j] != 0 && i < 3)
					{
						if (g[i + 1][j] == 0)
						{
							g[i + 1][j] = g[i][j];
							g[i][j] = 0;
						}
					}
				}
			}
		}
		break;
	case 75://键盘“左”
		system("cls");
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < X; i++)
			{
				for (int j = 0; j < Y; j++)
				{
					if (g[i][j] != 0 && j>0)
					{
						if (g[i][j - 1] == 0)
						{
							g[i][j - 1] = g[i][j];
							g[i][j] = 0;
						}
					}
				}
			}
		}
		break;
	case 77://键盘“右”
		system("cls");
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < X; i++)
			{
				for (int j = 0; j < Y; j++)
				{
					if (g[i][j] != 0 && j < 3)
					{
						if (g[i][j + 1] == 0)
						{
							g[i][j + 1] = g[i][j];
							g[i][j] = 0;
						}
					}
				}
			}
		}
		break;
	}
}

void same_judge()
{
	switch (ch)
	{
	case 72:
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (g[j][i] == g[j + 1][i] && g[j][i] != 0)
				{
					g[j][i] *= 2;
					g[j + 1][i] = 0;
					j = 3;
				}
			}
		}
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (g[i][j] != 0 && i>0)
				{
					if (g[i - 1][j] == 0)
					{
						g[i - 1][j] = g[i][j];
						g[i][j] = 0;
					}
				}
			}
		}
		break;
	case 80:
		for (int i = 0; i < X; i++)
		{
			for (int j = 3; j >= 0; j--)
			{
				if (g[j][i] == g[j - 1][i] && g[j][i] != 0)
				{
					g[j][i] *= 2;
					g[j - 1][i] = 0;
					j = 0;
				}
			}
		}
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < X; i++)
			{
				for (int j = 0; j < Y; j++)
				{
					if (g[i][j] != 0 && i < 3)
					{
						if (g[i + 1][j] == 0)
						{
							g[i + 1][j] = g[i][j];
							g[i][j] = 0;
						}
					}
				}
			}
		}
		break;
	case 75:
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (g[i][j] == g[i][j + 1] && g[i][j] != 0)
				{
					g[i][j + 1] *= 2;
					g[i][j] = 0;
					j = 3;
				}
			}
		}
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (g[i][j] != 0 && j>0)
				{
					if (g[i][j - 1] == 0)
					{
						g[i][j - 1] = g[i][j];
						g[i][j] = 0;
					}
				}
			}
		}
		break;
	case 77:
		for (int i = 0; i < X; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (g[i][j] == g[i][j - 1] && g[i][j] != 0)
				{
					g[i][j - 1] *= 2;
					g[i][j] = 0;
					j = 0;
				}
			}
		}
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < X; i++)
			{
				for (int j = 0; j < Y; j++)
				{
					if (g[i][j] != 0 && j < 3)
					{
						if (g[i][j + 1] == 0)
						{
							g[i][j + 1] = g[i][j];
							g[i][j] = 0;
						}
					}
				}
			}
		}
		break;
	}
}

bool produce_judge()//判断进行一步操作后是否生成新数字
{
	int a[4][4] = { 0 };
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			a[i][j] = g[i][j];
		}
	}
	play();
	same_judge();
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (a[i][j] != g[i][j])
				return 1;
		}
	}
	return 0;
}

void produce_new()//产生新数字
{
	srand(time(0)); //在一个随机位置生成随机的2或4
	int ran = 0, m = 0, n = 0;
	m = rand() % 16;
	while (g[(m) / 4][m % 4] != 0)
	{
		m = rand() % 16;
	}
	n = 1 + rand() % 2;
	g[(m) / 4][m % 4] = pow(2, n);
	system("cls");
	draw();
}

int score()
{
	cout << endl;
	int a = 0;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (g[i][j] != 0)
				a += g[i][j] * (log(g[i][j]) / log(2));
		}
	}
	return a;
}

bool death_judge()//死亡判断
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (g[i][j] == 0 || g[i][j] == g[i + 1][j] || g[i][j] == g[i - 1][j]
				|| g[i][j] == g[i][j + 1] || g[i][j] == g[i][j - 1])
				return 0;
		}
	}
	return 1;
}

bool win_judge()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			if (g[i][j] == 2048)
				return 1;
		}
	}
	return 0;
}

int main()
{
	draw();
	start();
	while (1)
	{
		int a = score();
		cout << "分数：" << a << endl;
		set_ch();
		if (produce_judge())
			produce_new();
		else
			draw();
		if (death_judge())
		{
			cout << "你死了！" << endl;
			break;
		}
		if (win_judge())
		{
			cout << "你赢了！" << endl;
			break;
		}

	}
	system("pause");
	return 0;
}