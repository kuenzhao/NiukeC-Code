#include<iostream>
#include<string>

using namespace std;

int main()
{
	double high;
	while (cin >> high)
	{
		double Distance = high;
		for (int i = 1; i < 5; i++)
		{	
			Distance += high;
			high /= 2;
		}
		cout << Distance << endl << high / 2 << endl;
	}
	return 0;
}