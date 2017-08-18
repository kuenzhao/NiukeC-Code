#include<iostream>
#include<string>

using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int a0 = 2;
		int t = 3;

		int an = a0 + (num-1) * t;

		cout << num*(a0 + an) / 2 << endl;
	}
	return 0;
}