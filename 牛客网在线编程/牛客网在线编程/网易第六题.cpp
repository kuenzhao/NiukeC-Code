/*

С�׽�n�����Ӱڷ���һ�����޴�������ϡ���i�����ӷ��ڵ�x[i]��y[i]�С�ͬһ������������ö�����ӡ�ÿһ�β���С�׿��԰�һ���������𲢽����ƶ���ԭ���ӵ��ϡ��¡����ҵ�����һ�������С�С����֪��Ҫ�������ϳ�����һ��������������i(1 �� i �� n)����������Ҫ�����ٲ�������.

��������:
�����������,��һ��һ������n(1 �� n �� 50),��ʾ���ӵĸ���
�ڶ���Ϊn�����ӵĺ�����x[i](1 �� x[i] �� 10^9)
������Ϊn�����ӵ�������y[i](1 �� y[i] �� 10^9)


�������:
���n������,��i����ʾ��������һ������������i����������Ҫ�Ĳ�����,�Կո�ָ��ĩ�޿ո�

��������ʾ:
����1������: ����Ҫ����
����2������: ��ǰ�������ӷ���(1, 1)��
����3������: ��ǰ�������ӷ���(2, 1)��
����4������: ���������Ӷ�����(3, 1)��

��������1:
4
1 2 4 9
1 1 1 1

�������1:
0 1 3 10*/

#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;

const int INTMAX = 2147483647;

struct Point
{
	int x = 0;
	int y = 0;
}p[55];

int dis(int x, int y, const Point &b)
{
	return abs(x - b.x) + abs(y - b.y);
}

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> p[i].x;
	}
	for (i = 1; i <= n; ++i)
	{
		cin >> p[i].y;
	}
	vector<vector<int>> min_step;
	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= n; ++y)
		{
			vector<int> tmp;
			for (int k = 1; k <= n; ++k)
			{
				tmp.push_back(dis(p[x].x, p[y].y, p[k]));
			}
			sort(tmp.begin(), tmp.end());
			min_step.push_back(tmp);
		}
	}
	for (i = 1; i <= n; ++i)
	{
		int ans = INTMAX;
		for (j = 0; j < min_step.size(); ++j)
		{
			int temp = 0;
			for (int k = 0; k < i; ++k)
			{
				temp += min_step[j][k];
			}
			ans = min(ans, temp);
		}
		cout << ans;
		if (i != n) cout << " ";
		else cout << endl;
	}
	return 0;
}