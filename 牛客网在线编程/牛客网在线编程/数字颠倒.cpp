#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

string NumberReverse(int Integer)
{
	string str;//
	stringstream s;
	s << Integer;//����ת�ַ���
	s >> str;
	reverse(str.begin(), str.end());//�ַ���ת��
	return str;
}
int main()
{
	int Integer;
	cin >> Integer;
	cout << NumberReverse(Integer) << endl;//���ת��֮����ַ���
	return 0;
}