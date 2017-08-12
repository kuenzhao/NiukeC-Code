/****************************************************************************
题目描述：
	实现一个可存储若干个单词的字典。用户可以：
在字典中加入单词，查找指定单词在在字典中兄弟单词个数。查找指定单词的指定序号的
兄弟单词，指定序号指字典中兄弟单词按字典顺序排序后的序号。清空字典中所有单词。
定义，格式说明
单词
	由小写英文字母组成，不含其它字符。
兄弟单词
	给定一个单词X,如果通过任意交换单词中字母的位置得到不同的单词Y，那么定义Y是X的兄弟单词
字典顺序：
	两个单词，先以第一个字母作为排序的基准，如果第一个字母相同，就用第二个字母作为基准。如果第二个字母相同
	以第三个字母为基准，依次类推，如果到某个字母不相同，字母顺序在前的那个单词顺序在前。如果短单词是长单词
	从首字母开始连续的一部分，短单词顺序在前。
举例：
	bca是abc兄弟单词，abc与abc是相同单词，不是兄弟单词。
输入描述：
	先输入字典中单词的个数，在输入n个单词作为字典单词，
	输入一个单词，查找其在字典中兄弟单词的个数
	再输入数字n
输出描述：
	根据输入，输出查找到兄弟单词的个数
*****************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
//将两个单词重新排序

//判断两个单词是否为兄弟单词 
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
//存储所有的兄弟单词（set）存储

//输出兄弟单词的个数，以及排序后的第几号兄弟单词
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
			//如果是兄弟单词，加入set中，否则比较下一个
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