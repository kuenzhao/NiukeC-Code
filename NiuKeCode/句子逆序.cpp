#include<iostream>
#include<string>
#include<vector>

using namespace std;

string SentenceReverse(string str)
{
	vector<string> word;
	string tmp;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it != ' ')
		{
			tmp += *it;		
		}
		else
		{
			//tmp += *it;
			word.push_back(tmp);
			tmp.clear();
		}
		
	}
	word.push_back(tmp);
	str.clear();
	//reverse(word.begin(), word.end());
	for (int i = word.size()-1;i > 0;i --)
	{
		str += (word[i] + ' ');
	}
	str += word[0];
	return str;
}

int main()
{
	string str;
	getline(cin, str);

	cout << SentenceReverse(str) << endl;

	return 0;
}