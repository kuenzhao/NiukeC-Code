#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int count = 0;
		for(string::size_type i = 0;i < str.size();i ++)
		{
			
			if (str[i] >= 'A'&& str[i] <= 'Z')
			{
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}