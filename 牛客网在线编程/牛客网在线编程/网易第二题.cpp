/*
���һ������S����������еĺϷ���i,����S[i + 1] = S[i] + d, �����dҲ�����Ǹ�������,���Ǿͳ�����SΪ�Ȳ����С�
С��������һ������Ϊn������x,С�����x��Ϊһ���Ȳ����С�С����������������������������λ�õ���ֵ�Ĳ���,���ҽ���������������Ρ�������Щ����ͨ���������ǲ��ܱ�ɵȲ�����,С����Ҫ�б�һ�������Ƿ���ͨ������������ɵȲ�����
��������:
�����������,��һ�а�������n(2 �� n �� 50),�����еĳ��ȡ�
�ڶ���n��Ԫ��x[i](0 �� x[i] �� 1000),�������е�ÿ��������


�������:
������Ա�ɵȲ��������"Possible",�������"Impossible"��

��������1:
3
3 1 2

�������1:
Possible
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int num;
	
	while (cin >> num)
	{
		bool flag = false;
		vector<int> arr;
		int tmp;
		for (int i = 0; i < num; i++)
		{
			cin >> tmp;
			arr.push_back(tmp);
		}

		sort(arr.begin(), arr.end());
		tmp = arr[1] - arr[0];
		for (int i = 1; i < num-1; i++)
		{
			if (arr[i + 1] - arr[i] != tmp)
			{
				cout << "Impossible" << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Possible" << endl;
		}	
	}

	return 0;
}