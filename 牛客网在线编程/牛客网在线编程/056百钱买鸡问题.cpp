#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct chicken
{
	int CockNum;
	int HenNUm;
	int ChickNUm;
};

int GetResult(vector<chicken> &list)
{
	chicken ck;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 34; j++)
		{
			for (int k = 0; k < 100; k += 3)
			{
				if ((i * 5 + j * 3 + k / 3 == 100) && (i + j + k == 100))
				{
					ck.CockNum = i;
					ck.HenNUm = j;
					ck.ChickNUm = k;
					list.push_back(ck);
				}
			}
		}
	}
	return 0;
}

int main()
{
	vector<chicken> list;
	GetResult(list);
	int num;
	while(cin >> num)
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i].CockNum << " " << list[i].HenNUm << " " << list[i].ChickNUm << endl;
	}
	
	return 0;
}