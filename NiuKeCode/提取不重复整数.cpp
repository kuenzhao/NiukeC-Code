#include<iostream>
#include<string>
#include<map>
using namespace std;

int takeNumber(int number)
{
	map<int,int> tmp;
	int OutNumber = 0;
	while (number)
	{
		if (!tmp[number % 10])
		{
			tmp[number % 10] = number % 10;
			OutNumber = OutNumber * 10 + number % 10;
		}
		number /= 10;
	}
	return OutNumber;
}

int main()
{
	int number;
	cin >> number;
	
	cout << takeNumber(number) << endl;
	
	
	return 0;
}