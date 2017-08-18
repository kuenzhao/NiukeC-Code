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
//	if (low == high) {   //��low==highʱ,��ʱlist��������һ������,���list
//		for (int i = 0; i <= low; i++)
//			cout << list[i]<< " ";
//		cout << endl;
//	}
//	else {
//		for (int i = low; i <= high; i++) {//ÿ��Ԫ�����һ��Ԫ�ؽ���
//			swap(list[i], list[low]);
//			perm(list, low + 1, high); //������,�õ�������,�ú���perm�õ������е�ȫ����
//			swap(list[i], list[low]);//���,��Ԫ�ؽ�������,��ԭ,Ȼ�󽻻���һ��Ԫ��
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

//���ȫ�����ҳ���ȷ�ĳ�ս˳��

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool isOutNum(int *push, int *pop, int len)//�ж�pop�ǲ���push�ĳ�ջ����
{
	if (push == NULL || pop == NULL || len <= 0)
		return false;
	stack<int> Stack;
	int i = 0, j = 0;
	for (i = 0; i<len; i++)//���ΰ�push�е�����ջ
	{
		Stack.push(push[i]);
		while (j<len && Stack.size() != 0 && pop[j] == Stack.top())//�����ж�pop����ÿ��ֵ�Ƿ���ջ�����
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
			if (isOutNum(pushNum, popNum, N))//�����������ȷ�������
			{
				for (int i = 0; i<N - 1; i++)
					cout << popNum[i] << " ";
				cout << popNum[N - 1] << endl;
			}
		} while (next_permutation(popNum, popNum + N));//��ȡ��һ������       
	}
	return 0;
}