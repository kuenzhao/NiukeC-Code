#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	char ch;
	while (cin >>str >> ch)
	{
		int count = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ch || str[i] + 32 == ch || str[i] - 32 == ch)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	char ch;

	while (cin >> str >> ch)
	{

		if (ch >= 'a'&&ch <= 'z')
			cout << (count(str.begin(), str.end(), ch) + count(str.begin(), str.end(), (char)(ch - 32))) << endl;
		else if (ch >= 'A'&&ch <= 'Z')
			cout << (count(str.begin(), str.end(), ch) + count(str.begin(), str.end(), (char)(ch + 32))) << endl;
		else
			cout << count(str.begin(), str.end(), ch) << endl;

	}

	return 0;
}