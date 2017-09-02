#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
using namespace std;

string strToNum(const string input)
{
	string m_num;
	m_num = input;
	int length = input.size();
	unsigned int sum = m_num[0] - 'a' + 1;
	for (int i = 1; i < length; i++)
	{
		sum = sum * 26 + (m_num[i] - 'a' + 1);
	}
	return to_string(sum);
}

string numToStr(const string input)
{
	string m_num;
	m_num = input;
	string tmp;
	unsigned int num = atoi(m_num.c_str());
	if (num <= 26)
	{
		tmp = 'a' + num - 1;
		return tmp;
	}
	else
	{
		vector<int> remainder;
		while (num)
		{
			int a = num % 26;
			remainder.push_back(a);
			num /= 26;
		}
		for (unsigned int i = 0; i < remainder.size(); i++)
		{
			if (remainder[i] == 0)
			{
				tmp += 'z';
				i++;
				tmp += ('a' + remainder[i] - 2);
			}
			else
			{
				tmp += ('a' + remainder[i] - 1);
			}
		}
		reverse(tmp.begin(), tmp.end());	
	}
	return tmp;
}

bool strRight(const string input)
{
	string m_num;
	m_num = input;
	for (string::size_type i = 1; i < m_num.size(); i++)
	{
		if (m_num[i] < 'a' || m_num[i] > 'z')
		{
			cout << "ERROR" << endl;
			return false;
		}
	}
	return true;
}

bool numRight(const string input)
{
	string m_num;
	m_num = input;
	if (m_num.size() == 1 && m_num[0] == '0')
	{
		cout << "ERROR" << endl;
		return false;
	}
	for (string::size_type i = 1; i < m_num.size(); i++)
	{
		if (m_num[i] < '0' || m_num[i] > '9')
		{
			cout << "ERROR" << endl;
			return false;
		}
	}
	return true;
}

void convertTo26(const string input, string &output)
{
	string m_num;
	m_num = input;
	if (m_num.size() == 0)
	{
		cout<< "ERROR" << endl;
	}
	else
	{
		if (m_num[0] >= 'a' && m_num[0] <= 'z'&&strRight(input))
		{
			cout << strToNum(input)<< endl;
		}
		else if (m_num[0] >= '0' && m_num[0] <= '9'&&numRight(input))
		{
			cout << numToStr(input) << endl;
		}
		else
		{
			cout << "ERROR" << endl;
			return;
		}
	}
	return;
}
int main()
{
	string input;
	while (cin >> input)
	{
		string output;
		convertTo26(input, output);
		cout << output;
	}
	return 0;
}