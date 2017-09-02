#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void HunguryNum(vector<int> &sugar, vector<int> &Combat,vector<int> &BearHungry)
{
	sort(sugar.begin(), sugar.end());
	while (Combat.size())
	{
		int maxCombat = 0;
		int count = 0;
		
		for (int i = 0; i < Combat.size(); i++)
		{
			maxCombat = maxCombat > Combat[i] ? maxCombat : Combat[i];
			count = maxCombat > Combat[i] ? count : i;
		}
		
		for (int j = sugar.size() - 1; j >= 0; j--)
		{
			if (BearHungry[count] >= sugar[j])
			{	
				BearHungry[count] -= sugar[j];
				sugar.erase(sugar.begin()+j);
			}
		}
		cout << BearHungry[count] << endl;
		Combat.erase(Combat.begin() +count);
		BearHungry.erase(BearHungry.begin() + count);
	}

}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> sugar(m, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> sugar[i];
	}
	vector<int> Bear(n,0); 
	vector<int> Combat(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> Bear[i] >> Combat[i];
	}
	HunguryNum(sugar, Bear, Combat);

	return 0;
}