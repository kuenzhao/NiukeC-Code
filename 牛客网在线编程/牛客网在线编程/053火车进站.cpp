//#include<iostream>
//#include<vector>
//using namespace std;
//
//void swap(int &a, int &b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void perm(int list[], int low, int high) {
//	if (low == high) {   //当low==high时,此时list就是其中一个排列,输出list
//		for (int i = 0; i <= low; i++)
//			cout << list[i]<< " ";
//		cout << endl;
//	}
//	else {
//		for (int i = low; i <= high; i++) {//每个元素与第一个元素交换
//			swap(list[i], list[low]);
//			perm(list, low + 1, high); //交换后,得到子序列,用函数perm得到子序列的全排列
//			swap(list[i], list[low]);//最后,将元素交换回来,复原,然后交换另一个元素
//		}
//	}
//}
//int main()
//{
//	int num;
//	int train[10] = { 0 };
//	while (cin >> num)
//	{
//		for (int i = 0; i < num; i++)
//		{
//			cin >> train[i];
//		}
//		int tmp = 0;
//		for (int i = 0; i < num-1; i++)
//		{
//			for (int j = i + 1; j < num; j++)
//			{
//				if (train[i] > train[j])
//				{
//					tmp = train[i];
//					train[i] = train[j];
//					train[j] = tmp;
//				}
//			}
//		}
//
//		perm(train, 0, num - 1);
//	}
//
//	return 0;
//}

//针对全排列找出正确的出战顺序

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOutNum(int *push, int *pop, int len)//判断pop是不是push的出栈序列
{
	if (push == NULL || pop == NULL || len <= 0)
		return false;
	stack<int> Stack;
	int i = 0, j = 0;
	for (i = 0; i<len; i++)//依次把push中的数入栈
	{
		Stack.push(push[i]);
		while (j<len && Stack.size() != 0 && pop[j] == Stack.top())//依次判断pop序列每个值是否与栈顶相等
		{
			Stack.pop();
			j++;
		}
	}
	return Stack.empty();
}
int main()
{
	int N;
	while (cin >> N)
	{
		int pushNum[10];
		int popNum[10];
		for (int i = 0; i<N; i++)
		{
			cin >> pushNum[i];
			popNum[i] = pushNum[i];
		}
		sort(popNum, popNum + N);
		do
		{
			if (isOutNum(pushNum, popNum, N))//如果该排列正确，则输出
			{
				for (int i = 0; i<N - 1; i++)
					cout << popNum[i] << " ";
				cout << popNum[N - 1] << endl;
			}
		} while (next_permutation(popNum, popNum + N));//获取下一个排列       
	}
	return 0;
}