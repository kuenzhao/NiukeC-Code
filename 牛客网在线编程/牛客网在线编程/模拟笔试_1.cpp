#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;

	while (cin >> str)
	{
		int count = 1;
		int outCount = 0;
		
		for (string::size_type i = 0; i < str.size() - 1; i++)
		{
			if (str[i] == str[i + 1])
			{
				count++;
			}
			else
			{
				outCount += count / 2;
				count = 1;
			}
		}
		outCount += count / 2;
		cout << outCount << endl;
	}
	return 0;
}