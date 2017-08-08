#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

string NumberReverse(int Integer)
{
	string str;//
	stringstream s;
	s << Integer;//Êý×Ö×ª×Ö·û´®
	s >> str;
	reverse(str.begin(), str.end());//×Ö·û´®×ªÖÃ
	return str;
}
int main()
{
	int Integer;
	cin >> Integer;
	cout << NumberReverse(Integer) << endl;//Êä³ö×ªÖÃÖ®ºóµÄ×Ö·û´®
	return 0;
}