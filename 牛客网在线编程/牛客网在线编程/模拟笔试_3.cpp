#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		str.erase(str.size() - 1);
		while (1)
		{
			string s1 = str.substr(0, str.size() / 2);
			string s2 = str.substr(str.size() / 2);
			if (s1 == s2)
			{
				cout << str.size() << endl;
				break;
			}
			else
			{
				str.erase(str.size() - 1);
			}
		}
		
	}

	return 0;
}