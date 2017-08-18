/****************************************************************************
题目描述
Catcher 是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，
ABA，A，123321，但是他们有时会在开始或结束时加入一些无关的字符以防止别国破解。比如进
行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。因为截获的串太长了，而且存在多
种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，他
只能向电脑高手求助，你能帮Catcher找出最长的有效密码串吗？
输入描述:
输入一个字符串
输出描述:
返回有效密码串的最大长度
示例1
输入
ABBA
输出
4
*****************************************************************************/
#include<iostream>
#include<string>
using namespace std;
int findLongestPalindrome(string &s)
{
	const int length = s.size();
	int maxlength = 0;
	int start;

	for (int i = 0; i<length; i++)//长度为奇数  
	{
		int j = i - 1, k = i + 1;
		while (j >= 0 && k<length&&s.at(j) == s.at(k))
		{
			if (k - j + 1>maxlength)
			{
				maxlength = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}

	for (int i = 0; i<length; i++)//长度为偶数  
	{
		int j = i, k = i + 1;
		while (j >= 0 && k<length&&s.at(j) == s.at(k))
		{
			if (k - j + 1>maxlength)
			{
				maxlength = k - j + 1;
				start = j;
			}
			j--;
			k++;
		}
	}
	
	return maxlength;
}
int main()
{
	string str;
	while (cin >> str)
	{
		cout << findLongestPalindrome(str) << endl;
	}
	return 0;
}
