/******************************************************************************************
��Ŀ����
����һ��int�͵����������������int���������ڴ��д洢ʱ1�ĸ�����
��������:
����һ��������int���ͣ�
�������:
�����ת����2���ƺ����1�ĸ���
ʾ��1
����
5
���
2
*******************************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int inputNumber;
	cin >> inputNumber;
	int count = 0;
	while (inputNumber)
	{
		if (inputNumber % 2 != 0)
		{
			count++;
		}
		inputNumber /= 2;
	}
	cout << count << endl;
	return 0;
}