/*
题目描述

题目描述

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。


输入

每个用例包含二个整数M和N。0 <= m <= 10，1 <= n <= 10。


样例输入

7 3


样例输出

8




* 计算放苹果方法数目


* 输入值非法时返回-1

* 1 <= m,n <= 10

* @param m 苹果数目

* @param n 盘子数目数

* @return 放置方法总数

*

public static int count(int m, int n)

输入描述:

输入两个int整数

输出描述 :

输出结果，int型

示例1
输入
7 3
输出
8
*/

#include<iostream>
#include<string>
using namespace std;
int getcounts(int num1, int num2)
{	
	if (num1<0)
		return 0;
	if (num1 == 1 || num2 == 1)
		return 1;
	return getcounts(num1, num2 - 1) + getcounts(num1 - num2, num2);
}

int main()
{
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		if (num1 >= 1 && num1 <= 10 && num2 >= 1 && num2 <= 10)
		{
			cout << getcounts(num1, num2) << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int M, N;
	while (cin >> M >> N) {
		if (M < 1 || M>10 || N < 1 || N>10) {
			cout << -1 << endl;
			continue;
		}
		vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++) dp[0][i] = 1;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				dp[i][j] = dp[i][j - 1] + (i < j ? 0 : dp[i - j][j]);
		cout << dp[M][N] << endl;
	}
}
