/*
��Ŀ����

��������[-2��31�η�, 2��31�η�]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��


��������:

�����1�и���������T(<=10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���



�������:

��ÿ�������������һ���������Case #X: true�����A+B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����


��������:

4

1 2 3

2 3 4

2147483647 0 2147483646

0 -2147483648 -2147483647


�������:

Case #1: false

Case #2: true

Case #3: true

Case #4: false
*/

#include<iostream>
#include<vector>
using namespace std;
struct ABC
{
	long long A;
	long long B;
	long long C;
};
int main()
{
	int num;
	ABC abc;
	cin >> num;
	vector<ABC> arr;
	for (int i = 0; i < num; i++)
	{
		cin >> abc.A >> abc.B >> abc.C;
		arr.push_back(abc);
	}
	for (int i = 0; i < num; i++)
	{
		if (arr[i].A + arr[i].B > arr[i].C)
		{
			cout << "Case #" << i+1 << ": true" << endl;
		}
		else
		{
			cout << "Case #" << i+1 << ": false" << endl;
		}
	}
	
	return 0;
}
