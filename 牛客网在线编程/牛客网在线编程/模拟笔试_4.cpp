#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;

	while (cin >> str)
	{
		char hash[26] = { 0 };
		int count = 0;
		
		for (string::size_type i = 0; i < str.size(); i++)
		{
			hash[str[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (hash[i] > 0 && hash[i] % 2 == 1)
			{
				count++;
			}
		}
		
		if (count == 0)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << count << endl;
		}

	}

	return 0;
}