#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

bool isExist(set<int> &collect, int num)
{
	if (collect.count(num))
	{
		return true;
	}
	return false;
}
long groupPower(set<int> &collect, int *strength)
{
	if (strength == NULL)
	{
		return 0;
	}
	int power = 0;
	for (set<int>::iterator it = collect.begin(); it != collect.end(); it++)
	{
		power += strength[*it-1];
	}
	return power;
}
long calculatePower(int numOfKids, int carDrawn, int **studentPair, int *strength)
{

	int MaxPower = 0;
	set<int> collect;
	bool flag = false;
	if (numOfKids == 0 || carDrawn == 0 || studentPair == NULL || strength == NULL)
	{
		return -1;
	}
	while (1)
	{
		for (int i = 0; i < carDrawn; i++)
		{
			if (studentPair[i][0] != 0 && flag == false)//每次分组第一次进入
			{
				collect.insert(studentPair[i][0]);
				studentPair[i][0] = 0;
				collect.insert(studentPair[i][1]);
				studentPair[i][1] = 0;
				flag = true;
			}
			else if(studentPair[i][0] != 0)
			{
				if (isExist(collect, studentPair[i][0]))
				{
					collect.insert(studentPair[i][1]);
					studentPair[i][1] = 0;
					studentPair[i][0] = 0;
				}
				else if (isExist(collect, studentPair[i][1]))
				{
					collect.insert(studentPair[i][0]);
					studentPair[i][1] = 0;
					studentPair[i][0] = 0;
				}
			}
		}
		if (collect.size() == 0)
		{
			break;
		}
		//三目运算符，得到最大值
		MaxPower = MaxPower > groupPower(collect, strength) ? MaxPower : groupPower(collect, strength);
		collect.clear();
		flag = false;
	}
	return MaxPower;
}

int main()
{
	int numOfKids;
	int carDrawn;
	int **studentPair;
	int *strength;

	cin >> numOfKids >> carDrawn;
	studentPair = new int *[carDrawn];
	for (int i = 0; i < carDrawn; i++)
	{
		studentPair[i] = new int[2];
	}
	strength = new int[numOfKids];
	for (int i = 0; i < carDrawn; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> studentPair[i][j];
		}
	}
	for (int i = 0; i < numOfKids; i++)
	{
		cin >> strength[i];
	}
	cout << calculatePower(numOfKids, carDrawn, studentPair, strength)<<endl ;
	if (strength != NULL)
	{
		delete[] strength;
	}
	if (studentPair != NULL)
	{
		for (int i = 0; i < carDrawn; i++)
		{
			delete[] studentPair[i];
		}
		delete[]studentPair;
	}
	return 0;
}