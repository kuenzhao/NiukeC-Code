/*
СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬����С���ж��ٶ��أ�������أ�



��������:


�����������������ݡ�

����ÿ��������ݣ�

N - �������������n����

a1,a2...an - ��Ҫ���������

��֤:

1<=N<=100000,0<=ai<=INT_MAX.




�������:


����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����


��������1:

6
45 12 45 32 5 6


�������1:

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