/*��Ŀ����

1

1  1  1

1  2  3  2  1

1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��


����n(n <= 1000000000)
��������:

����һ��int����

������� :

������ص�intֵ

ʾ��1
����

4

���

3
*/

#include<iostream>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		if (num == 1 || num == 2)
		{
			cout << -1 << endl;
		}
		else if (num % 2 == 1)
		{
			cout << 2 << endl;
		}
		else if(num %4 == 0)
		{
			cout << 3 << endl;
		}
		else if (num % 4 == 2)
		{
			cout << 4 << endl;
		}

		
	}
	return 0;
}

//˼·��1.�ҹ��ɣ����֣�����������ʾ�Ļ�����1�е�1������������ߣ������ڵ�n��Ԫ��λ�ã�n�����кţ�
//     2.��n�е�Ԫ�صĵ�һ�������һ����Ҫ��ǰ��ֵΪ1.�����е�Ԫ�أ�����һ���⣬���չ�ʽ
//      a[i][j]=a[i][j-1]+a[i][j]+a[i][j+1];
#include<iostream>
#include<vector>
using namespace std;
void printYH(int n)
{

	vector<vector<int> >a(n, vector<int>(2 * n - 1, 0));
	a[0][n - 1] = a[n - 1][0] = a[n - 1][2 * n - 2] = 1;
	if (n<2)
	{
		cout << "-1" << endl;
		return;
	}
	for (int i = 1; i<n; ++i)
		for (int j = 1; j<2 * n - 2; ++j)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1];
	for (int i = 0; i<2 * n - 1; ++i)
		if (a[n - 1][i] != 0 && (a[n - 1][i] % 2 == 0))
		{
			cout << i + 1 << endl;
			return;
		}
	return;
}
int main()
{
	int n;
	while (cin >> n)
	{
		printYH(n);
	}
	return 0;
}