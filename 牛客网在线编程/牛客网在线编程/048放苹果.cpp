/*
��Ŀ����

��Ŀ����

��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���


����

ÿ������������������M��N��0 <= m <= 10��1 <= n <= 10��


��������

7 3


�������

8




* �����ƻ��������Ŀ


* ����ֵ�Ƿ�ʱ����-1

* 1 <= m,n <= 10

* @param m ƻ����Ŀ

* @param n ������Ŀ��

* @return ���÷�������

*

public static int count(int m, int n)

��������:

��������int����

������� :

��������int��

ʾ��1
����
7 3
���
8
*/

#include<iostream>
#include<string>
using namespace std;
int getcounts(int num1, int num2)
{	
	if (num1<0)
		return 0;
	if (num1 == 1 || num2 == 1)
		return 1;
	return getcounts(num1, num2 - 1) + getcounts(num1 - num2, num2);
}

int main()
{
	int num1, num2;
	while (cin >> num1 >> num2)
	{
		if (num1 >= 1 && num1 <= 10 && num2 >= 1 && num2 <= 10)
		{
			cout << getcounts(num1, num2) << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int M, N;
	while (cin >> M >> N) {
		if (M < 1 || M>10 || N < 1 || N>10) {
			cout << -1 << endl;
			continue;
		}
		vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++) dp[0][i] = 1;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				dp[i][j] = dp[i][j - 1] + (i < j ? 0 : dp[i - j][j]);
		cout << dp[M][N] << endl;
	}
}
