/*****************************************************************************************************
��Ŀ����
ʵ��ɾ���ַ����г��ִ������ٵ��ַ���������ַ����ִ���һ������ɾ�������ɾ����Щ���ʺ���ַ������ַ�
���������ַ�����ԭ����˳��
��������:
�ַ���ֻ����СдӢ����ĸ, �����ǷǷ����룬������ַ�������С�ڵ���20���ֽڡ�
�������:
ɾ���ַ����г��ִ������ٵ��ַ�����ַ�����
ʾ��1
����
abcdd
���
dd
******************************************************************************************************/
/*****************************************************************************************************
����˼·��
	ͳ��ÿ���ַ����ֵĴ�������ͳ�ƺ��ַ�ѹ��ջ�У�Ȼ����б���ɾ�����ַ����Ժ�ÿ��ͳ�Ƶ��ַ���������ջ�е�
�ַ�������Ƚϣ����ջ�е��ַ��ĸ������ڵ�ǰͳ�Ƶ��ַ��������ջ����ǰ�ַ���ջ��������ֱ����ջ�����
����ֱ�ӽ�����һ���ַ���ͳ�ơ�ֱ���ַ����е�����Ϊ�ա�Ȼ����ַ��������ջ�к��е�����Ԫ�ء�
******************************************************************************************************/

#include<iostream>
#include<string>
#include<stack>

using namespace std;
struct LetterRecord
{
	char Letter;
	int count;
};
//ɾ���ַ�����ָ�����ַ�
string deleteLetter(string &str, char c)
{
	string::iterator it;
	string tmp;
	for(it = str.begin();it != str.end();it ++)
	{
		if (*it != c)
		{
			tmp += *it;
		}
	}
	return tmp;
}
string DeleteLeastSymobl(string &str)
{
	string::iterator it;
	string tmp = str;
	LetterRecord Lre;//
	stack<LetterRecord> stackLre;
	while (tmp.size())
	{
		Lre.count = 1;
		Lre.Letter = tmp[0];
		for (it = tmp.begin() + 1; it != tmp.end(); it++)
		{
			if (tmp[0] == *it)
			{
				Lre.count++;
			}
		}
		//ջ�д洢����ĸ�ĸ������Ϊ����Ļ��������ǵĸ�����ͬ������ֻ����һ����ĸ
		if (!stackLre.empty())
		{
			if (stackLre.top().count > Lre.count)
			{
				while (!stackLre.empty())//���ջ��Ԫ��
				{
					stackLre.pop();
				}
				stackLre.push(Lre);//��������С��ѹ��ջ��
			}
			else if (stackLre.top().count == Lre.count)//��������ȵ�ѹ��ջ��
			{
				stackLre.push(Lre);
			}	
		}
		else
		{
			stackLre.push(Lre);//�����ʼ��Ԫ��ѹ��ջ��
		}

		//ɾ��tmp�в��Ҽ������Ǹ�Ԫ��
		tmp = deleteLetter(tmp, tmp[0]);
	}
	while (!stackLre.empty())
	{
		str = deleteLetter(str, stackLre.top().Letter);
		stackLre.pop();
	}
	return str;
}

int main()
{

	string str;
	while (cin >> str)
	{
		cout << DeleteLeastSymobl(str)<<endl;
	}
	return 0;
}