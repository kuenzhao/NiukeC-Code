/*
��Ŀ����

��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�




* ͳ�Ƴ�����������
*
* @param monthCount �ڼ�����
* @return ��������

public static int getTotalCount(int monthCount)
{
	return 0;
}




��������:

����int�ͱ�ʾmonth

������� :

�����������int��

ʾ��1
����

9

���

34

*/

//#include <iostream>
//using namespace std;
//
//int main() {
//	int m;
//	while (cin >> m) {
//		int a = 1, b = 0, c = 0;//a:һ������������b����������������c�����������Ӹ���
//		while (--m) {//ÿ��һ�����������仯
//			c += b;
//			b = a;
//			a = c;
//		}
//		cout << a + b + c << endl;
//	}
//}
//
//
//
//#include <stdio.h>
//
//int main()
//{
//	///�ؼ����ҵ�����ʽ f(n)=f(n-1)+f(n-2) (n>=4)
//	///����ʽ�Ľ���:���ڵ�n���µ���������������������ɣ�
//	///һ�������ϸ��µ�����f(n-1)����һ��������3���´������
//	///����һֻ����f(n-2)
//	int arr[100];
//	int i, N;
//	arr[1] = arr[2] = 1;
//	arr[3] = 2;
//	for (i = 4; i<100; i++) {
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	while ((scanf("%d", &N)) != EOF) {
//		printf("%d\n", arr[N]);
//	}
//	return 0;
//}

#include <iostream>  
#include <algorithm> 
#include<vector> 
using namespace std; 
int age; 
void stateTransfer(vector<int> &tuziSet) 
{
	for (int i = age; i >=1; i--)//��1��(2) 
	{ 
		tuziSet[i] = tuziSet[i - 1]; 
	} 
	tuziSet[0] = 0; 
	for (int i = 3; i <= age-1;i++)//(3) 
	{ 
		tuziSet[0] += tuziSet[i]; 
	} 
	int sum = 0;
	for (int i = 0; i < age; i++)
	{
		sum += tuziSet[i];
	}

	cout << sum << endl;
	if (sum>10)//(4)���˴���2������ 
	{ 
		int i = 0,j=age; 
		while (1) 
		{ 
			if (tuziSet[j] > 0)
			{ 
				tuziSet[j]--; i++;
			} 
			else 
				j--; 
			if (i==2) 
			{ 
				break; 
			} 
		} 
	} 
} 
int main() 
{ 
	int n;
	cin >> n>>age; 
	vector<int> tuziSet(age+1,0);//��ʼ״̬����Ϊ0 
	tuziSet[0] = 1;//initialize 
	for (int i = 1; i <= n;i++) 
	{ 
		cout << i << "  ";
		stateTransfer(tuziSet);
	} 
	int num = 0; 
	for (auto x:tuziSet) 
	{
		num += x*2;
	} 
	cout << num; 
	return 0; 
}