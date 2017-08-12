#include<iostream>
#include<string>

#include<sstream>
using namespace std;
unsigned int StrToDecimal(string str)
{
	stringstream stream;
	unsigned int n;
	stream << str;     //��stream�в����ַ���"1234" 
	stream >> n;     //��stream����ȡ�ղ�����ַ���"1234"  �����丳�����n����ַ�����int��ת�� 
	return n;
}
void unzip(const string input, string &output)
{
	//�ж����������Ƿ񳬹���
	int hash[256] = {0};
	if (input.size() == 0)
	{
		output = "!error";
		return;
	}
	if (input[input.size() - 1] <'a' || input[input.size() - 1]>'z')
	{
		output = "!error";
		return;
	}
	if (input[0] == '0')
	{
		output = "!error";
		return;
	}
	for (string::size_type i = 1; i < input.size() - 1; i++)
	{
		if (input[i] == '0' && (input[i - 1] >= 'a'&&input[i - 1] <= 'z'))
		{
			output = "!error";
			return;
		}
	}
	for (string::size_type i = 0; i < input.size()-2; i++)
	{
		if (input[i] >= '0'&& input[i] <= '9'&&input[i + 1] == input[i + 2])
		{
			output = "!error";
			return;
		}
	}
	for (string::size_type i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0'&& input[i] <= '9'&&input[i + 1] == input[i + 2])
		{
			output = "!error";
			return;
		}
		if (input[i] >= 'a'&&input[i] <= 'z')
		{
			hash[input[i]]++;
		}
	}
	for (int i = 0; i < 256; i++)
	{
		if (hash[i] >= 3)
		{
			output = "!error";
			return;
		}
	}

	string tmp;
	for (string::size_type i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a'&&input[i] <= 'z')
		{
			output += input[i];
		}
		else 
		{
			while (input[i] >= '0'&& input[i] <= '9')
			{
				tmp += input[i];
				i++;
			}
			int size = StrToDecimal(tmp);
			tmp.clear();
			for (int j = 0; j < size; j++)
			{
				output += input[i];
			}
		}
	}
}
int main()
{
	string str;
	string str2;
	while (cin >> str)
	{
		unzip(str, str2);
		cout << str2 << endl;
		str2.clear();
	}
	return 0;
}