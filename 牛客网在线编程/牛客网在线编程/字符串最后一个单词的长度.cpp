#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		int count = 0;
		int tmp = str.length()-1;
		while (tmp >= 0 &&str[tmp --] != ' ')
		{
			count++;
		}

		cout << count << endl;
	}

}