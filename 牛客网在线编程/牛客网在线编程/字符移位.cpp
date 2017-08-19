/*
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？
输入描述:
输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
输出描述:
对于每组数据，输出移位后的字符串。
输入例子1:
AkleBiCeilD
输出例子1:

kleieilABCD
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool compare(char a, char b)
{
	return a>b;   //升序排列，如果改为return a>b，则为降序

}
int main()
{
	string str;

	while (cin >> str)
	{
		int tmp = str.size();
		for (string::size_type i = 0; i < tmp; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str += str[i];
			}
		}
		for (string::size_type i = 0; i < tmp; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str.erase(i, 1);
				i--;
				tmp--;
			}
		}
		cout << str << endl;
	}
	
	return 0;
}