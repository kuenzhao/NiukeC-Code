/**********************************************************************************
��Ŀ����
���ַ����е����е��ʽ��е��š�
˵����
1��ÿ����������26����д��СдӢ����ĸ���ɣ�
2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
4��ÿ�������20����ĸ��
��������:
����һ���Կո����ָ��ľ���
�������:
������ӵ�����
ʾ��1
����
I am a student
���
student a am I
***********************************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string TranslateSpace(string &str)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if ((!(str[i] >= 'a'&&str[i] <= 'z')) && (!(str[i] >= 'A' && str[i] <= 'Z')))
		{
			str[i] = ' ';
		}
	}
	return str;
}
vector<string> sentenceSplitter(string str)
{
	vector<string> Rstr;
	string tmp;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			tmp += str[i];
		}
		else
		{
			if (tmp.size())
			{
				Rstr.push_back(tmp);
				tmp.clear();
			}
		}
	}
	if (tmp.size())
	{
		Rstr.push_back(tmp);
		tmp.clear();
	}
	return Rstr;
}

void PrintReSentence(vector<string> str)
{
	string outStr;
	vector<string>::iterator it = str.begin();
	outStr += *it;
	for (it = str.begin() + 1; it != str.end(); it++)
	{
		outStr += (' '+*it);
	}
	cout << outStr << endl;
}
int main11()
{

	string str;

	while (getline(cin, str))
	{
		TranslateSpace(str);
		vector<string> Rstr = sentenceSplitter(str);
		reverse(Rstr.begin(), Rstr.end());
		PrintReSentence(Rstr);
	}
	return 0;
}

