/*

С����һ������Ϊn����������,a_1,...,a_n��Ȼ������һ��������b�Ͻ���n�����²���:
1����a_i����b���е�ĩβ
2������b����
С����Ҫ������������n��֮���b���С�
��������:
�����������,��һ�а���һ������n(2 �� n �� 2*10^5),�����еĳ��ȡ�
�ڶ��а���n������a_i(1 �� a_i �� 10^9),������a�е�ÿ������,�Կո�ָ


�������:
��һ�����������n��֮���b����,�Կո�ָ�,��ĩ�޿ո�

��������1:
4
1 2 3 4

�������1:
4 2 1 3
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr(2 * 100000,0);
int main()
{
	int num;
	while (cin >> num)
	{
		
		int tmp;
		int count1, count2;
		if (num % 2 == 0)
		{
			count1 = num / 2;
			count2 = num / 2 - 1;
			for (int i = 0; i < num; i++)
			{
				cin >> tmp;
				if (i % 2 == 0)
				{
					
					arr[count1] = tmp;
					count1++;
				}
				else
				{
					
					arr[count2] = tmp;
					count2--;
				}

			}
		}
		else
		{
			count2 = num / 2;
			count1 = num / 2 + 1;
			for (int i = 0; i < num; i++)
			{
				cin >> tmp;
				
				if (i % 2 == 1)
				{	
					arr[count1] = tmp;
					count1++;
				}
				else
				{	
					arr[count2] = tmp;
					count2--;
				}

			}
		}
		
		cout << arr[0];
		for (int i = 1; i < num; i++)
		{
			cout << " " << arr[i];
		}
		cout << endl;
	}

	return 0;
}