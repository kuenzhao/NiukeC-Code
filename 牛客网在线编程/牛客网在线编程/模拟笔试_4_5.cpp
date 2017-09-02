/*
牛牛喜欢字符串,但是他讨厌丑陋的字符串。对于牛牛来说,一个字符串的丑陋值是字符串中相同连续字符对的个数。比如字符串“ABABAABBB”的丑陋值是3,因为有一对"AA"和两对重叠的"BB"。现在给出一个字符串,字符串中包含字符'A'、'B'和'?'。牛牛现在可以把字符串中的问号改为'A'或者'B'。牛牛现在想让字符串的丑陋值最小,希望你能帮帮他。
输入描述:

输入包括一个字符串s,字符串长度length(1 ≤ length ≤ 50),字符串只包含'A','B','?'三种字符。



输出描述:

输出一个整数,表示最小的丑陋值


输入例子1:

A?A


输出例子1:

0
*/

#include <iostream>
#include<string>
using namespace std;


int main()
{
	string str;
	cin >> str;
	int nSize = str.length();
	if (nSize<2)
	{
		cout << 0 << endl;
		return 0;
	}
	int nCount = 0;
	int ii = 0;
	//处理开头为？的情况
	while (ii<nSize && str[ii] == '?')
		ii++;
	//都是‘？’
	if (ii == nSize)
	{
		cout << 0 << endl;
		return 0;
	}

	for (; ii<nSize - 1; ++ii)
	{
		if (str[ii] == '?')
		{
			str[ii] = str[ii - 1] == 'A' ? 'B' : 'A';
		}
		if (str[ii] == str[ii + 1])
			nCount++;
	}
	cout << nCount << endl;
}