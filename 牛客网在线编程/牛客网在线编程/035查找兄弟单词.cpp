/****************************************************************************
��Ŀ������
	ʵ��һ���ɴ洢���ɸ����ʵ��ֵ䡣�û����ԣ�
���ֵ��м��뵥�ʣ�����ָ�����������ֵ����ֵܵ��ʸ���������ָ�����ʵ�ָ����ŵ�
�ֵܵ��ʣ�ָ�����ָ�ֵ����ֵܵ��ʰ��ֵ�˳����������š�����ֵ������е��ʡ�
���壬��ʽ˵��
����
	��СдӢ����ĸ��ɣ����������ַ���
�ֵܵ���
	����һ������X,���ͨ�����⽻����������ĸ��λ�õõ���ͬ�ĵ���Y����ô����Y��X���ֵܵ���
�ֵ�˳��
	�������ʣ����Ե�һ����ĸ��Ϊ����Ļ�׼�������һ����ĸ��ͬ�����õڶ�����ĸ��Ϊ��׼������ڶ�����ĸ��ͬ
	�Ե�������ĸΪ��׼���������ƣ������ĳ����ĸ����ͬ����ĸ˳����ǰ���Ǹ�����˳����ǰ������̵����ǳ�����
	������ĸ��ʼ������һ���֣��̵���˳����ǰ��
������
	bca��abc�ֵܵ��ʣ�abc��abc����ͬ���ʣ������ֵܵ��ʡ�
����������
	�������ֵ��е��ʵĸ�����������n��������Ϊ�ֵ䵥�ʣ�
	����һ�����ʣ����������ֵ����ֵܵ��ʵĸ���
	����������n
���������
	�������룬������ҵ��ֵܵ��ʵĸ���
*****************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
//������������������

//�ж����������Ƿ�Ϊ�ֵܵ��� 
bool isBrotherWord(string str1, string str2)
{
	if (str1 != str2 && str1.size() == str2.size())
	{
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		return str1 == str2;
	}
	return false;
}
//�洢���е��ֵܵ��ʣ�set���洢

//����ֵܵ��ʵĸ������Լ������ĵڼ����ֵܵ���
int main11()
{
	int  count = 0;
	while (cin >> count)
	{
		string str;
		vector<string> dictionary;
		for (int i = 0; i < count; i++)
		{
			cin >> str;
			dictionary.push_back(str);
		}
		sort(dictionary.begin(), dictionary.end());
		cin >> str;
		cin >> count;
		vector<string>::iterator it;
		set<string> Brother;
		int tmpcount = 0;
		string tmpstr;
		for (it = dictionary.begin(); it != dictionary.end(); it++)
		{
			//������ֵܵ��ʣ�����set�У�����Ƚ���һ��
			if (isBrotherWord(str, *it))
			{
				tmpcount++;
				if (tmpcount == count)
				{
					tmpstr = *it;
				}
			}
		}
		cout << tmpcount << endl;
		if (tmpcount >= count)
		{
			cout << tmpstr << endl;
		}
	}
	return 0;
}