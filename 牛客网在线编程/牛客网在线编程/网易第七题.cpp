/*
С����ʦ�Ƿǳ�������,����Ҫ������ѧ���ڽ������ǰ���ų�һ��,������Ҫ��ѧ��������߲��ݼ���˳�����С���һ��,n��ѧ�����жӵ�ʱ��,С����ʦ����ȥ�������ˡ�ѧ���������л��ᷴ����,����ѧ���Ǿ�����һ�η��Ķ���,���Ƕ���һ�����еķ��ֵΪÿ����������ѧ����߲�ľ���ֵ�ܺ͡����ڰ������˳�����еĶ��еķ��ֵ����С��,���ǵ�Ȼ�������շ��ֵ����˳���������жӡ����ڸ���n��ѧ�������,��������Щѧ���жӵ������ܵķ��ֵ��С����ʦ����һ�������ð�����
��������:
�����������,��һ��һ������n(1 �� n �� 50),��ʾѧ��������
�ڶ���Ϊn������h[i](1 �� h[i] �� 1000),��ʾÿ��ѧ�������


�������:
���һ������,��ʾn��ѧ���жӿ��Ի�õ����ķ��ֵ��

��������ʾ:
����������˳����: 25-10-40-5-25, ��߲����ֵ���ܺ�Ϊ15+30+35+20=100��
�������ķ��ֵ�ˡ�

��������1:
5
5 10 25 40 25

�������1:
100
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMax(vector<int> tmp)
{
	int max = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (max < tmp[i])
		{
			max = tmp[i];
		}
	}
	return max;
}
int getMin(vector<int> tmp)
{
	int min = tmp[0];
	for (int i = 0; i < tmp.size(); i++)
	{
		
		if (min > tmp[i])
		{
			min = tmp[i];
		}
	}
	return min;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int tmp = 0;
		vector<int> arr(num,0);
		vector<int> sorted;
		for (int i = 0; i < num;i ++)
		{
			cin >>arr[i];	
		}
		while (arr.size())
		{
			sorted.insert(sorted.begin(), getMax(arr));
			arr.erase(find(arr.begin(), arr.end(), getMax(arr)));
			if (arr.size())
			{
				sorted.push_back(getMin(arr));
				arr.erase(find(arr.begin(), arr.end(), getMin(arr)));
				if (arr.size())
				{
					sorted.insert(sorted.begin(), getMin(arr));
					arr.erase(find(arr.begin(), arr.end(), getMin(arr)));
					if (arr.size())
					{
						sorted.push_back(getMax(arr));
						arr.erase(find(arr.begin(), arr.end(), getMax(arr)));
					}
				}	
			}
			
		}

		tmp += (abs(sorted[0] - sorted[1]) > abs(sorted[0] - sorted[num - 1]) ? abs(sorted[0] - sorted[1]) : abs(sorted[0] - sorted[num - 1]));
		for (int i = 1; i < num-1; i++)
		{	
			tmp += abs(sorted[i + 1] - sorted[i]);
		}

		cout << tmp << endl;
	}
	return 0;
}