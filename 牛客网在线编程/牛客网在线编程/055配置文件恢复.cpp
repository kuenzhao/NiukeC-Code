#include<iostream>
#include<string>
#include<sstream>
using namespace std;
bool match(string str, string s) {
	return str.find(s) == 0;
}
int main11()
{
	string cmd[6] = { "reset","reset board", "board add","board delet","reboot backplane", "backplane abort" };
	string res[7] = { "reset what","board fault", "where to add","no board at all","impossible","install first","unkown command" };
	string str;
	while (getline(cin,str))
	{
		//ÅÐ¶ÏÊÇ¼¸¸ö×Ö´®
		string s1, s2, temp1, temp2;
		stringstream ss(str);
		ss >> s1 >> s2;
		int resi = 6;
		if (s2.empty())
		{
			resi = match(cmd[0], s1) ? 0 : 6;
		}
		else
		{
			bool flag = false;
			for (int i = 1; i < 6; i++)
			{
				stringstream allcmd(cmd[i]);
				allcmd >> temp1 >> temp2;
				if (match(temp1, s1) && match(temp2, s2))
				{
					if (!flag)
					{
						resi = i;
						flag = true;
					}
					else
					{
						resi = 6;
						break;
					}
				}
			}
		}
		cout << res[resi] << endl;
	}
	return 0;
}

