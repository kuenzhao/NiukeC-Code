/****************************************************************************************
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格

详细描述：

函数接口说明：
public String getResult(long ulDataInput)
输入参数：
long ulDataInput：输入的正整数
返回值：
String


输入描述:
	输入一个long型整数
输出描述:
	按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
示例1
	输入
	180
	输出
	2 2 3 3 5
*****************************************************************************************/

#include<iostream>
#include<string>
#include <sstream>
using namespace std;

bool isPrimeNumber(long number)
{
	int tmp = sqrt(number);
	for (int i = 2; i <= tmp; i++)
	{
		if (number%i == 0)
		{
			return false;
		}
	}
	return true;
}

long PrimeNumber(long number)
{
	int tmp = sqrt(number);
	for (int i = 2; i <= tmp; i++)
	{
		if (number%i == 0)
		{
			return i;
		}
	}
	return number;
}
string num2str(long i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}

long str2num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}
string getResult(long ulDataInput)
{
	string str;
	//首先判断该数是否为质数
	while(!isPrimeNumber(ulDataInput))
	{
		str += num2str(PrimeNumber(ulDataInput));
		str += ' ';
		ulDataInput /= PrimeNumber(ulDataInput);
	}
	str += num2str(ulDataInput);
	str += ' ';
	return str;
}

int main()
{
	cout << getResult(180) << endl;
	return 0;
}