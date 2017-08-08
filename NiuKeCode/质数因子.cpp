/****************************************************************************************
����:����һ�������������մ�С�����˳����������������������ӣ���180����������Ϊ2 2 3 3 5 ��
���һ��������ҲҪ�пո�

��ϸ������

�����ӿ�˵����
public String getResult(long ulDataInput)
���������
long ulDataInput�������������
����ֵ��
String


��������:
	����һ��long������
�������:
	���մ�С�����˳����������������������ӣ��Կո���������һ��������ҲҪ�пո�
ʾ��1
	����
	180
	���
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
	//�����жϸ����Ƿ�Ϊ����
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