#include<iostream>
#include<string>

using namespace std;

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}		
	return false;
}

int main()
{
	int N;
	cin >> N;
	int daysCount[7] = { 0 };
	int addDays[13] = {0,3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
	daysCount[2] = 1;
	int tmp = 0;
	
	for (int i = 2017; i <= 2017 + N - 1; i++)
	{
		if (isLeapYear(i))
		{
			addDays[2] = 1;
		}
		else
		{
			addDays[2] = 0;
		}
		if (i != 2017)
		{
			tmp = tmp + addDays[12];
			daysCount[(tmp + 2) % 7]++;
			//cout << (tmp + 2) % 7 << endl;
		}
		for (int j = 2; j <= 12; j++)
		{
			tmp = tmp + addDays[j - 1];
			daysCount[(tmp + 2) % 7]++;
			//cout << (tmp + 2) % 7 << endl;
		}
	}
	cout << daysCount[1] << " ";
	for (int i = 1; i < 7; i++)
	{
		cout << " " << daysCount[(i + 1) % 7];
	}
	cout << endl;
	return 0;
}