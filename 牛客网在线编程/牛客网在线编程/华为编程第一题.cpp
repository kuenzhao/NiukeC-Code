#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<string> splitWords(const string str)
{
	vector<string> EngWords;
	string tmp;
	tmp += str[0];
	for (string::size_type i = 1; i <= str.size(); i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')|| (i == str.size()))
		{
			EngWords.push_back(tmp);
			tmp.clear();
			tmp += str[i];
		}
		else
		{
			tmp += str[i];
		}
	}
	return EngWords;
}

string translateWord(vector<string> EngWords)
{
	string Words[10] = { "Zeros","One","Two","Three","Four","Five","Six","Seven","Eight", "Nine" };
	string Alphabetic[10] = { "Ling","Yi","Er","San","Si","Wu","Liu","Qi","Ba" "Jiu" };
	map<string, string> transMap;
	string outputStr;
	for (int i = 0; i < 10; i++)
	{
		transMap.insert(make_pair(Words[i], Alphabetic[i]));
	}

	for (unsigned int i = 0;i < EngWords.size();i ++)
	{
		if (EngWords[i] == "Double")
		{
			if ((i != EngWords.size() - 1) && transMap.count(EngWords[i+1]))
			{
				i++;	
				outputStr += transMap[EngWords[i]];
				outputStr += transMap[EngWords[i]];	
			}
			else
			{
				outputStr.clear();
				outputStr += "ERROR";
			}
		}
		else
		{
			if (transMap.count(EngWords[i]))
			{
				outputStr += transMap[EngWords[i]];
			}
			else
			{
				outputStr.clear();
				outputStr += "ERROR";
			}
		}	
	}
	return outputStr;
}
int main()
{
	string str;
	while (cin >> str)
	{
		cout << translateWord(splitWords(str)) << endl;;
	}
	return 0;
}