#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string StringReverse(string str)
{
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	string str;
	cin >> str;
	cout << StringReverse(str) << endl;
	return 0;
}