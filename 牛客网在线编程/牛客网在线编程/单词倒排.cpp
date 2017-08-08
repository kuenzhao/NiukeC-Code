/**********************************************************************************
题目描述
对字符串中的所有单词进行倒排。
说明：
1、每个单词是以26个大写或小写英文字母构成；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；
输入描述:
输入一行以空格来分隔的句子
输出描述:
输出句子的逆序
示例1
输入
I am a student
输出
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

