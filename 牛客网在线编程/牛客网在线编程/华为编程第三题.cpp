#include<string> 
#include <iostream>  
using namespace std;
bool IsValidIp(const string &str)
{
	if (&str == NULL)
	{
		return false;
	}
	int a[4];
	if (sscanf_s(str.c_str(), "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]) != 4)
	{
		return false;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (a[i] < 0 || a[i] > 255)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str;
	while (cin >> str)
	{
		cout << IsValidIp(str) << endl;
	}
	return 0;
}