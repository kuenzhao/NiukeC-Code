/*****************************************************************************************************
题目描述
实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符
串中其它字符保持原来的顺序。
输入描述:
字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。
输出描述:
删除字符串中出现次数最少的字符后的字符串。
示例1
输入
abcdd
输出
dd
******************************************************************************************************/
/*****************************************************************************************************
解题思路：
	统计每个字符出现的次数，将统计后字符压入栈中，然后从列表中删除该字符，以后每次统计的字符个数都与栈中的
字符个数相比较，如果栈中的字符的个数大于当前统计的字符数，清空栈，当前字符入栈。如果相等直接入栈，如果
大于直接进行下一个字符的统计。直到字符串中的数据为空。然后从字符串中清空栈中含有的所有元素。
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
//删除字符串中指定的字符
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
		//栈中存储的字母的个数如果为多个的话，则他们的个数相同，否则只存在一个字母
		if (!stackLre.empty())
		{
			if (stackLre.top().count > Lre.count)
			{
				while (!stackLre.empty())//清空栈中元素
				{
					stackLre.pop();
				}
				stackLre.push(Lre);//将计数最小的压入栈中
			}
			else if (stackLre.top().count == Lre.count)//将计数相等的压入栈中
			{
				stackLre.push(Lre);
			}	
		}
		else
		{
			stackLre.push(Lre);//将最初始的元素压入栈中
		}

		//删除tmp中查找计数的那个元素
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