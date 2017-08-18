/*

小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。
输入描述:
输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。


输出描述:
在一行中输出操作n次之后的b序列,以空格分割,行末无空格。

输入例子1:
4
1 2 3 4

输出例子1:
4 2 1 3
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr(2 * 100000,0);
int main()
{
	int num;
	while (cin >> num)
	{
		
		int tmp;
		int count1, count2;
		if (num % 2 == 0)
		{
			count1 = num / 2;
			count2 = num / 2 - 1;
			for (int i = 0; i < num; i++)
			{
				cin >> tmp;
				if (i % 2 == 0)
				{
					
					arr[count1] = tmp;
					count1++;
				}
				else
				{
					
					arr[count2] = tmp;
					count2--;
				}

			}
		}
		else
		{
			count2 = num / 2;
			count1 = num / 2 + 1;
			for (int i = 0; i < num; i++)
			{
				cin >> tmp;
				
				if (i % 2 == 1)
				{	
					arr[count1] = tmp;
					count1++;
				}
				else
				{	
					arr[count2] = tmp;
					count2--;
				}

			}
		}
		
		cout << arr[0];
		for (int i = 1; i < num; i++)
		{
			cout << " " << arr[i];
		}
		cout << endl;
	}

	return 0;
}