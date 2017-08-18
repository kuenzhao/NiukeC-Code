#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string num2str(int i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int tmp = num * num;
		tmp = tmp - num + 1;
		string str;
		str = num2str(tmp);
		for (int i = 0; i < num-1; i++)
		{
			tmp += 2;
			str += '+';
			str += num2str(tmp);
		}
		cout << str << endl;
	}
}