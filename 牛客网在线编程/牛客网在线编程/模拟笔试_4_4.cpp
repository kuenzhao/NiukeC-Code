/*
ţţ��һ������Ϊn����������s,����Ҫ��ţţ��������ѡ��ͬ������λ��,Ȼ�󽻻�������λ���ϵ�Ԫ�ء�������Ҫ������򽻻�����Եõ��Ĳ�ͬ�����и�����(ע�ⱻ��������Ԫ��ֵ������ͬ)��
������{1, 47},���1.������뽻�����е�����Ԫ��,�õ�����{47, 1}��������뽻��,���ܱ���ԭ�е����С�
{1, 2, 1},���3.����ͨ���������Եõ�{2, 1, 1},{1, 1, 2},{1, 2, 1}���������С�
��������:

�����������,��һ��Ϊһ������n(2 �� n �� 50),�����еĳ��ȡ�
�ڶ���n������,��ʾ���е�ÿ��Ԫ��a_i(1 �� a_i �� 50),�Կո�ָ



�������:

���һ������,��ʾ������Եõ��Ĳ�ͬ�����и���


��������1:

3
1 2 1


�������1:

3
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	

	int num;
	while (cin >> num)
	{
		set<vector<int>> setsize;
		vector<int> arr(num,0);
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}
		setsize.insert(arr);
		for (int i = 0; i < num - 1; i++)
		{
			for(int j = i + 1; j < num; j++)
			{
				//����
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				//����
				setsize.insert(arr);
				//��ԭ
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		cout << setsize.size() << endl;
	}

	return 0;
}