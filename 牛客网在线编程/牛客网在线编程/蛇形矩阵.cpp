/*********************************************************
题目描述
题目说明
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
样例输入
5
样例输出
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
接口说明
原型
void GetResult(int Num, char * pResult);
输入参数：
int Num：输入的正整数N
输出参数：
int * pResult：指向存放蛇形矩阵的字符串指针
指针指向的内存区域保证有效
返回值：
void
输入描述 :
输入正整数N（N不大于100）
输出描述 :
输出一个N行的蛇形矩阵。
示例1
输入
4
输出
1 3 6 10
2 5 9
4 8
7
*****************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void GetResult(int Num, char * pResult)
{
	int **arr = new int *[Num];
	for (int i = 0; i < Num; i++)
	{
		arr[i] = new int[Num];
	}

	for (int i = 0; i < Num; i++)
	{
		for (int j = 0; j < Num-i; j++)
		{
			if (i == 0)
			{
				arr[i][j] = (j + 1)*(j + 2) / 2;
				if (j == 0)
				{
					cout << arr[i][j];
				}
				else
				{
					cout << " " << arr[i][j] ;
				}			
			}
			else
			{
				arr[i][j] = arr[i - 1][j + 1] - 1;
				if (j == 0)
				{
					cout << arr[i][j];
				}
				else
				{
					cout << " " << arr[i][j];
				}
			}	
		}
		cout << endl;
	}
}
int main()
{
	char *result = NULL;
	int Num;
	while (cin >> Num)
	{
		GetResult(Num, result);
	}

	
	return 0;
}