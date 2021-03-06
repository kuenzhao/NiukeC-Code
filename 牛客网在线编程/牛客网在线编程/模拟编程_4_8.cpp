/*
牛牛在农场饲养了n只奶牛,依次编号为0到n-1, 牛牛的好朋友羊羊帮牛牛照看着农场.有一天羊羊看到农场中逃走了k只奶牛,但是他只会告诉牛牛逃走的k只奶牛的编号之和能被n整除。你现在需要帮牛牛计算有多少种不同的逃走的奶牛群。因为结果可能很大,输出结果对1,000,000,007取模。
例如n = 7 k = 4:
7只奶牛依次编号为0到6, 逃走了4只
编号和为7的有:{0, 1, 2, 4}
编号和为14的有:{0, 3, 5, 6}, {1, 2, 5, 6}, {1, 3, 4, 6},{2, 3, 4, 5}
4只牛的编号和不会大于18,所以输出5.
输入描述:

输入包括一行,两个整数n和k(1 ≤ n ≤ 1000),(1 ≤ k ≤ 50),以空格分割。



输出描述:

输出一个整数表示题设所求的种数。


输入例子1:

7 4


输出例子1:

5
*/


/*
解题思路：求c(m,n)的组合数，并且组合数的和是n的倍数
*/

#include<iostream>
using namespace std;
#define N 100
int a[N];
int total = 0;

int comb2(int m, int k)//(C(m,k)) 
{    
	int i, j;
	for (i = m; i >= k; i--)
	{
		a[k] = i;
		if (k>1)
		{
			comb2(i - 1, k - 1);
		}
		else
		{
			total++;
			for (j = a[0]; j>0; j--)
			{
				cout << a[j];
			}
			cout << ",";

		}
	}

	return total;
}

int main()
{
	int num, runaway;
	while (cin >> num >> runaway)
	{
		comb2(7, 4);
		

		

		//cout << count << endl;
	}

	return 0;
}