/*
题目描述
现有一组砝码，重量互不相等，分别为m1,m2,m3…mn； 每种砝码对应的数量为x1,x2,x3...xn。
现在要用这些砝码去称物体的重量，问能称出多少中不同的重量。
注：
称重重量包括0
方法原型： public   static   int  fama( int  n,  int [] weight,  int [] nums)
输入描述:
输入包含多组测试数据。
对于每组测试数据：
第一行：n --- 砝码数(范围[1,10])
第二行：m1 m2 m3 ... mn --- 每个砝码的重量(范围[1,2000])
第三行：x1 x2 x3 .... xn --- 每个砝码的数量(范围[1,6])
输出描述:
利用给定的砝码可以称出的不同的重量数
示例1
输入
2
1 2
2 1
输出
5
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;
void combination(int fama[],int n, int m);
int k, *a;
set<int> Types;
int main()
{
	int n;
	while (cin >> n)
	{
		int *famaType = new int[n];
		int *famaNum = new int[n];
		int tmp;
		int Number=0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			famaType[i] = tmp;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			famaNum[i] = tmp;
			Number += tmp;
		}

		int *fama = new int[Number];
		a = new int[Number];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < famaNum[i]; j++)
			{
				fama[count] = famaType[i];
				count++;
			}
		}
		for (int i = 0; i <= Number; i++)
		{
			k = i;
			combination(fama, Number, 0);
		}
		cout << Types.size() << endl;
		Types.clear();
		delete a;
		delete famaType;
		delete famaNum;
		delete fama;
	}
	return 0;
}

void combination(int fama[] ,int n, int m)
{
	int i;
	if (m<k)
	{
		for (i = n; i >= k - m; i--)  //首先这个for循环很重要，再次，k-m的控制是很合理的。
		{
			a[m] = i;
			combination(fama,i - 1, m + 1);
		}
	}
	else
	{
		int tmp = 0;
		for (i = 0; i < k; i++)
		{
			tmp += fama[a[i] - 1];
		}
		Types.insert(tmp);
		//cout << tmp << endl;
	}
}

/*
1 求出从1—n所有的组合数，并且将砝码求和的值存入到set集合中，最后输出集合的大小即可
*/


//
//
//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//
//}