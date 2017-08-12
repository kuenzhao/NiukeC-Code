#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		string tmp;
		for (string::size_type i = 0; i < str.size()-1; i++)
		{
			if (str[i] == '0'&&str[i + 1] == 'x')
			{
				tmp += str[i + 3];
				if (str[i + 2] >= '0'&& str[i + 2] <= '9')
				{
					tmp += str[i + 2];
				}
			}
		}

		cout << tmp<< endl;
	}
	return 0;
}