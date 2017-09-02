/*
牛牛以草料为食。牛牛有一天依次遇到n堆被施展了魔法的草料,牛牛只要遇到一堆跟他当前相同大小的草料,它就会把草料吃完,而使自己的大小膨胀一倍。一开始牛牛的大小的是A,然后给出牛牛依次遇到的n堆草料的大小。请计算牛牛最后的大小。
输入描述:
输入包括两行,第一行包含两个整数n和A(1 ≤ n ≤ 200, 1 ≤ A ≤ 1,000,000,000)
第二行包括n个整数,表示牛牛依次遇到的草料堆大小a_i(1 ≤ a_i ≤ 1,000,000,000)
输出描述:
输出一个整数,表示牛牛最后的大小。
输入例子1:
5 1
2 1 3 1 2
输出例子1:
4
*/

#include<iostream>

using namespace std;

int main()
{
	int num,origin;
	while (cin >> num >> origin)
	{
		int forage[200] = { 0 };

		for (int i = 0; i < num; i++)
		{
			cin >> forage[i];
			if (origin == forage[i])
			{
				origin *= 2;
			}
		}
		cout << origin << endl;
	}
	
	return 0;
}
