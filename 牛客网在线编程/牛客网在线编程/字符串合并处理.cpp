/*********************************************************************************************
题目描述
按照指定规则对输入的字符串进行处理。
详细描述：
将输入的两个字符串合并。
对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标
意思是字符在字符串中的位置。对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’
或者‘a’——‘f’，则对他们所代表的16进制的数进行BIT倒序的操作，并转换为相应的大写字符。如字符为
‘4’，为0100b，则翻转后为0010b，也就是2。转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为
1110b，也就是e。转换后的字符为大写‘E’。
举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，分别对“dca”和“efb”进行排序，
排序后为“abcedf”，转换后为“5D37BF”
接口设计及说明：
功能:字符串处理
输入:两个字符串,需要异常处理
输出:合并处理后的字符串，具体要求参考文档
返回:无
void ProcessString(char* str1, char *str2, char * strOutput)
{

}
输入描述:
输入两个字符串
输出描述 :
输出转化后的结果
示例1
输入
dec fab
输出
5D37BF
**************************************************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char BitReverse(int a)
{
	int result = 0;
	int tmp = 8;
	int tmp2 = 1;
	for (int i = 0; i < 4; i++)
	{
		if ((a & tmp))
		{
			result += tmp2;
		}	
		tmp = tmp >> 1;
		tmp2 = tmp2 << 1;
	}

	if (result >= 0 && result <= 9)
	{
		return '0' + result;
	}
	else
	{
		return 'A' + result - 10;
	}
}
/*
功能:字符串处理
输入:两个字符串,需要异常处理
输出:合并处理后的字符串，具体要求参考文档
返回:无
*/

void ProcessString(string &str1, string &str2, string &strOutput)
{
	string tmp1, tmp2, tmp3;
	tmp1 = str1 + str2;
	for (int i = 0; i < tmp1.size(); i+=2)
	{
		tmp2 += tmp1[i];
	}
	for (int i = 1; i < tmp1.size(); i += 2)
	{
		tmp3 += tmp1[i];
	}
	sort(tmp2.begin(), tmp2.end());
	sort(tmp3.begin(), tmp3.end());
	
	
	for (unsigned long i = 0; i < tmp3.size(); i++)
	{
		strOutput += tmp2[i];
		strOutput += tmp3[i];
	}
	if (tmp1.size() % 2 != 0)
	{
		strOutput += tmp2[tmp2.size() - 1];
	}
	

	for (unsigned long i = 0; i < strOutput.size(); i++)
	{
		if (strOutput[i] >= '0' && strOutput[i] <= '9')
		{
			strOutput[i] = BitReverse(strOutput[i] - '0');
		}
		else if (strOutput[i] >= 'a' && strOutput[i] <= 'f')
		{
			strOutput[i] = BitReverse(strOutput[i] - 'a'+ 10);
		}
		else if (strOutput[i] >= 'A' && strOutput[i] <= 'F')
		{
			strOutput[i] = BitReverse(strOutput[i] - 'A' + 10);
		}
	}
}
int main15()
{
	string str1,str2,strOutput;

	while (cin >> str1 >> str2)
	{
		ProcessString(str1, str2, strOutput);
		cout << strOutput <<endl;
		strOutput.clear();
	}
	
	return 0;
}