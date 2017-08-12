/*
题目描述

有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？




* 统计出兔子总数。
*
* @param monthCount 第几个月
* @return 兔子总数

public static int getTotalCount(int monthCount)
{
	return 0;
}




输入描述:

输入int型表示month

输出描述 :

输出兔子总数int型

示例1
输入

9

输出

34

*/

//#include <iostream>
//using namespace std;
//
//int main() {
//	int m;
//	while (cin >> m) {
//		int a = 1, b = 0, c = 0;//a:一个月兔子数，b：两个月兔子数，c：三个月兔子个数
//		while (--m) {//每过一个月兔子数变化
//			c += b;
//			b = a;
//			a = c;
//		}
//		cout << a + b + c << endl;
//	}
//}
//
//
//
//#include <stdio.h>
//
//int main()
//{
//	///关键是找到递推式 f(n)=f(n-1)+f(n-2) (n>=4)
//	///递推式的解释:对于第n个月的兔子数量：有两部分组成，
//	///一部分是上个月的兔子f(n-1)，另一部是满足3个月大的兔子
//	///会生一只兔子f(n-2)
//	int arr[100];
//	int i, N;
//	arr[1] = arr[2] = 1;
//	arr[3] = 2;
//	for (i = 4; i<100; i++) {
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	while ((scanf("%d", &N)) != EOF) {
//		printf("%d\n", arr[N]);
//	}
//	return 0;
//}

#include <iostream>  
#include <algorithm> 
#include<vector> 
using namespace std; 
int age; 
void stateTransfer(vector<int> &tuziSet) 
{
	for (int i = age; i >=1; i--)//（1）(2) 
	{ 
		tuziSet[i] = tuziSet[i - 1]; 
	} 
	tuziSet[0] = 0; 
	for (int i = 3; i <= age-1;i++)//(3) 
	{ 
		tuziSet[0] += tuziSet[i]; 
	} 
	int sum = 0;
	for (int i = 0; i < age; i++)
	{
		sum += tuziSet[i];
	}

	cout << sum << endl;
	if (sum>10)//(4)猎人带走2对兔子 
	{ 
		int i = 0,j=age; 
		while (1) 
		{ 
			if (tuziSet[j] > 0)
			{ 
				tuziSet[j]--; i++;
			} 
			else 
				j--; 
			if (i==2) 
			{ 
				break; 
			} 
		} 
	} 
} 
int main() 
{ 
	int n;
	cin >> n>>age; 
	vector<int> tuziSet(age+1,0);//初始状态数量为0 
	tuziSet[0] = 1;//initialize 
	for (int i = 1; i <= n;i++) 
	{ 
		cout << i << "  ";
		stateTransfer(tuziSet);
	} 
	int num = 0; 
	for (auto x:tuziSet) 
	{
		num += x*2;
	} 
	cout << num; 
	return 0; 
}