#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int number;
	set<int> num;
	
	while (cin >> number)
	{
		int tmp = 0;
		for (int i = 0; i < number; i++)
		{
			cin >> tmp;
			num.insert(tmp);
		}

		for (set<int>::iterator it = num.begin(); it != num.end(); it++)
		{
			cout << *it << endl;
		}
		num.clear();
	}
	
	

	return 0;
}

