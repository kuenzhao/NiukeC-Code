/*
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？



输入描述:


输入包含多组测试数据。

对于每组测试数据：

N - 本组测试数据有n个数

a1,a2...an - 需要计算的数据

保证:

1<=N<=100000,0<=ai<=INT_MAX.




输出描述:


对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。


输入例子1:

6
45 12 45 32 5 6


输出例子1:

1 2
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		vector<int> arr(num,0);
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}
		int min = INFINITY, max = 0;
		vector<int> mincount;
		vector<int> maxcount;
		
		for (int i = 0; i < num-1; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				if (min > abs(arr[i] - arr[j]))
				{
					mincount.clear();
					min = abs(arr[i] - arr[j]);
					mincount.push_back(min);
				}
				else if(min == abs(arr[i] - arr[j]))
				{
					mincount.push_back(min);
				}

				else if (max < abs(arr[i] - arr[j]))
				{
					maxcount.clear();
					max = abs(arr[i] - arr[j]);
					maxcount.push_back(max);
				}
				else if (max == abs(arr[i] - arr[j]))
				{
					maxcount.push_back(max);
				}
			}
		}

		cout << mincount.size() << " " << maxcount.size() << endl;
	}
	
	return 0;
}