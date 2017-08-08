/****************************************************************************
题目描述
1、对输入的字符串进行加解密，并输出。
2加密方法为：
当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
其他字符不做变化。
3、解密方法为加密的逆过程。
接口描述：
实现接口，每个接口实现1个基本操作：
void Encrypt (char aucPassword[], char aucResult[])：在该函数中实现字符串加密并输出
说明：
1、字符串以\0结尾。
2、字符串最长100个字符。
int unEncrypt (char result[], char password[])：在该函数中实现字符串解密并输出
说明：
1、字符串以\0结尾。
2、字符串最长100个字符。
输入描述:
输入说明
输入一串要加密的密码
输入一串加过密的密码
输出描述:
输出说明
输出加密后的字符
输出解密后的字符
示例1
输入
abcdefg
BCDEFGH
输出
BCDEFGH
abcdefg
*****************************************************************************/
#include<iostream>
#include<string>

using namespace std;

void Encrypt(string &aucPassword, string &aucResult)
{
	for (int i = 0; i < aucPassword.length(); i++)
	{
		if (aucPassword[i] >= 'A'&&aucPassword[i] < 'Z')
		{
			aucResult += aucPassword[i] + 33;
		}
		else if (aucPassword[i] == 'Z')
		{
			aucResult += 'a';
		}
		else if (aucPassword[i] >= 'a'&&aucPassword[i] < 'z')
		{
			aucResult += aucPassword[i] - 31;
		}
		else if (aucPassword[i] == 'z')
		{
			aucResult += 'A';
		}
		else if (aucPassword[i] >= '0'&&aucPassword[i] < '9')
		{
			aucResult += aucPassword[i] + 1;
		}
		else if (aucPassword[i] == '9')
		{
			aucResult += '0';
		}
	}
}

int unEncrypt(string &result, string &password)
{
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] > 'A'&&result[i] <= 'Z')
		{
			password += result[i] + 31;
		}
		else if (result[i] == 'A')
		{
			password += 'z';
		}
		else if (result[i] > 'a'&&result[i] <= 'z')
		{
			password += result[i] - 33;
		}
		else if (result[i] == 'a')
		{
			password += 'Z';
		}
		else if (result[i] > '0'&&result[i] <= '9')
		{
			password += result[i] - 1;
		}
		else if (result[i] == '0')
		{
			password += '9';
		}
	}
	return 0;
}
int main14()
{
	string str;
	string str1;
	string aucResult;
	string password;
	while (cin >> str >> str1)
	{
		Encrypt(str, aucResult);	
		unEncrypt(str1, password);
		cout << aucResult << endl;
		cout << password << endl;
	}
	return 0;
}