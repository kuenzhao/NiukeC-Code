#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string> maxSubstr(const string &str)
{
	set<string> outStr;
	string maxStr;
	string tmpStr;

	for (string::size_type i = 0; i < str.size()-1; i++)
	{
		tmpStr.clear();
		tmpStr += str[i];
		for (unsigned int j = i + 1; j <= str.size(); j++)
		{
			if ((tmpStr.find(str[j])==string::npos) && (j != str.size()))
			{
				tmpStr += str[j];
			}
			else 
			{
				if (maxStr.size() < tmpStr.size())
				{
					outStr.clear();
					maxStr = tmpStr;
					outStr.insert(maxStr);
				}
				else if(maxStr.size() == tmpStr.size())
				{
					maxStr = tmpStr;
					outStr.insert(maxStr);
				}
				
				break;
			}
		}
	}
	return outStr;
}

int main()
{
	string str;
	while (cin >> str)
	{
		set<string> outStr;
		outStr = maxSubstr(str);

		for (set<string>::iterator it = outStr.begin(); it != outStr.end(); it++)
		{
			cout << *it << endl;
		}
	}
	
	return 0;
}