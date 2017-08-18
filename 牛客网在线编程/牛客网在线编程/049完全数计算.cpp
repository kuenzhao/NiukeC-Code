#include<iostream>
#include<string>

using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		
		int count = 0;
		for (int i = 2; i <= num; i++)
		{
			int tmp = 1;
			for (int j = 2; j < i/2 + 1; j++)
			{
				if (i % j == 0)
				{
					tmp += j;
				}
			}
			if (tmp == i)
			{
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}