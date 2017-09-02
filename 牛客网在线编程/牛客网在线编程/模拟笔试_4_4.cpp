/*
牛牛有一个长度为n的整数序列s,羊羊要在牛牛的序列中选择不同的两个位置,然后交换这两个位置上的元素。现在需要求出羊羊交换后可以得到的不同的序列个数。(注意被交换的两元素值可能相同)。
如序列{1, 47},输出1.羊羊必须交换仅有的两个元素,得到序列{47, 1}。羊羊必须交换,不能保留原有的序列。
{1, 2, 1},输出3.羊羊通过交换可以得到{2, 1, 1},{1, 1, 2},{1, 2, 1}这三个序列。
输入描述:

输入包括两行,第一行为一个整数n(2 ≤ n ≤ 50),即序列的长度。
第二行n个整数,表示序列的每个元素a_i(1 ≤ a_i ≤ 50),以空格分割。



输出描述:

输出一个整数,表示羊羊可以得到的不同的序列个数


输入例子1:

3
1 2 1


输出例子1:

3
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	

	int num;
	while (cin >> num)
	{
		set<vector<int>> setsize;
		vector<int> arr(num,0);
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}
		setsize.insert(arr);
		for (int i = 0; i < num - 1; i++)
		{
			for(int j = i + 1; j < num; j++)
			{
				//交换
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				//插入
				setsize.insert(arr);
				//还原
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		cout << setsize.size() << endl;
	}

	return 0;
}