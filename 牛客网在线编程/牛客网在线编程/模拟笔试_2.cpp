#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;

	while (cin >> str)
	{
		int count = 0;
		int Maxcount = 0;
		for (string::size_type i = 0; i < str.size(); i++)
		{
			if (str[i] == 'A' || str[i] == 'T' || str[i] == 'C' || str[i] == 'G')
			{
				count++;
			}
			else
			{
				Maxcount = Maxcount > count ? Maxcount : count;
				count = 0;
			}
		}
		Maxcount = Maxcount > count ? Maxcount : count;
		cout << Maxcount << endl;
	}
	return 0;
}