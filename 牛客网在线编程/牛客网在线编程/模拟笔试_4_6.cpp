/*
ţ��ׯ�׶�԰Ϊ��ף61��ͯ�ھٰ���ף�,��ף�����һ����Ŀ��С������Χ��һ��ԲȦ���衣ţ��ʦ��ѡ��n��С���Ѳ��������Ŀ,��֪ÿ��С���ѵ����h_i��Ϊ�����赸��������г,ţ��ʦ��Ҫ�������ԲȦ����������С���ѵ���߲�����ֵ��С,ţ��ʦ������,ϣ�����ܰ������
��������ʾ:
��ԲȦ���鰴��100,98,103,105˳ʱ�����е�ʱ�������߲�Ϊ5,�������в���õ����ŵĽ�
��������:

�����������,��һ��Ϊһ��������n(3 �� n �� 20)
�ڶ���Ϊn������h_i(80 �� h_i �� 140),��ʾÿ��С���ѵ���ߡ�



�������:

���һ������,��ʾ���������µ�����С������߲�����ֵ��


��������1:

4
100 103 98 105


�������1:

5
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
		vector<int> arr(num,0);
		vector<int> cacl;
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		for (int i = arr.size() - 1; i >= 0;)
		{
			cacl.push_back(arr[i]);
			i--;
			if (i >= 0)
			{
				cacl.insert(cacl.begin(), arr[i]);
				i--;
			}	
		}

		int max = 0;

		for (int i = 0; i < num-1; i++)
		{
			max = max > abs(cacl[i] - cacl[i + 1]) ? max : abs(cacl[i] - cacl[i + 1]);
		}

		cout << max << endl;
	}

	return 0;
}
