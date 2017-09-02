#include<iostream>
#include<string>
#include<set>
#include<stack>
using namespace std;

int main()
{
	string str;

	while (cin >> str)
	{
		set<int> outPut;
		stack<int> out;
		for (string::size_type i = 0; i < str.size(); i++)
		{
			outPut.insert(str[i] - '0');
		}

		for (set<int>::iterator it = outPut.begin() ; it != outPut.end(); it++)
		{
			out.push(*it);
		}

		while (!out.empty())
		{
			cout << out.top();
			out.pop();
		}
		cout << endl;
	}

	return 0;
}