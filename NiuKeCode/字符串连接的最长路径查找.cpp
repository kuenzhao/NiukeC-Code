
/****************************************************************************************************
��Ŀ����
����n���ַ��������n���ַ��������ֵ������С�
�������� :
�����һ��Ϊһ��������n(1��n��1000), ����n��Ϊn���ַ���(�ַ������ȡ�100), �ַ�����ֻ���д�Сд��ĸ��
������� :
�������n�У�������Ϊ�����ֵ������е��ַ�����
ʾ��1
����

9
cap
to
cat
card
two
too
up
boat
boot
���

boat
boot
cap
card
cat
to
too
two
up
********************************************************************************************************/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> tmp;
	string str;
	int count;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> str;
		tmp.push_back(str);
	}
	sort(tmp.begin(), tmp.end());
	for (vector<string>::iterator it = tmp.begin(); it != tmp.end()-1; it++)
	{
		cout << *it << endl;
	}
	return 0;
}