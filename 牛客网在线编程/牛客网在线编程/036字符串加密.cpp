/*********************************************************************************
题目描述
有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，
选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，只保留第1个，其余
几个丢弃。现在，修改过的那个单词属于字母表的下面，如下所示：
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于
顶上那行，并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。
因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。
请实现下述接口，通过指定的密匙和明文得到密文。
详细描述：
接口说明
原型：
voidencrypt(char * key,char * data,char * encrypt);
输入参数：
char * key：密匙
char * data：明文
输出参数：
char * encrypt：密文
返回值：
void
输入描述:
先输入key和要加密的字符串
输出描述:
返回加密后的字符串
示例1
输入
nihao
ni
输出
le
**********************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string duplicate1(string str)
{
	if (str.size()<2)
		return str;
	string tmp_str("\0");
	tmp_str += str[0];
	string::size_type j;
	for (string::size_type i = 1; i<str.size(); i++)
	{
		for (j = 0; j<tmp_str.size(); j++)
		{
			if (tmp_str[j] == str[i])
				break;
		}
		if (j == tmp_str.size())
			tmp_str += str[i];
	}
	return tmp_str;
}
void duplicate(string &str)//利用哈希表删除重复的字符
{
	if (str.size()<2)
		return;
	int hash[256] = {0};
	
	hash[str[0]] = 1;
	int tail = 1;
	for (string::size_type i = 1; i<str.size(); i++)
	{
		if (hash[str[i]] == 0)
		{
			str[tail++] = str[i];
			hash[str[i]] += 1;
		}
	}
	str = str.substr(0, tail);
}

int main()
{
	string key,s;
	while (cin >> key>>s)
	{
		string R;
		int p[26] = { 0 };
		for (int i = 0; i<key.length(); i++) {
			if (key[i] >= 'a'&&key[i] <= 'z') {
				if (p[key[i] - 'a'] == 0) {
					R += key[i] - 32;
					p[key[i] - 'a'] = 1;
				}
			}
			else {
				if (p[key[i] - 'A'] == 0) {
					R += key[i];
					p[key[i] - 'A'] = 1;
				}
			}
		}
		for (int i = 0; i<26; i++)
			if (p[i] == 0)
				R += 'A' + i;
		for (int i = 0; i<s.length(); i++)
			if (s[i] >= 'a') {
				char c = R[s[i] - 'a'] + 32;
				cout << c;
			}
			else {
				cout << R[s[i] - 'A'];
			}
			cout << endl;

	}
	return 0;
}
