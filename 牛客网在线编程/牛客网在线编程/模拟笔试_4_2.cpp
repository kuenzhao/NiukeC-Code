/*
牛牛变得黑化了,想要摧毁掉地球。但他忘记了开启地球毁灭器的密码。牛牛手里有一个字符串S,牛牛还记得从S中去掉一个字符就恰好是正确的密码,请你帮牛牛求出他最多需要尝试多少次密码。
如样例所示S = "ABA",3个可能的密码是"BA", "AA", "AB".
当S = "A", 牛牛唯一可以尝试的密码是一个空的密码,所以输出1.
输入描述:

输入包括一个字符串S,字符串长度length(1 ≤ length ≤ 50),其中都是从'A'到'Z'的大写字母。



输出描述:

输出一个整数,表示牛牛最多需要尝试的密码次数。


输入例子1:

ABA


输出例子1:

3
*/
#include <iostream>
#include<string>
using  namespace std;
int main()
{
	string str;
	cin >> str;
	int count = 1;
	for (string::size_type i = 0; i < str.size() - 1; i++)
	{
		if (str[i] != str[i + 1])
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}