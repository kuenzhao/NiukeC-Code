/*
��Ŀ����
����һ�����룬����������ȣ��ֱ�Ϊm1,m2,m3��mn�� ÿ�������Ӧ������Ϊx1,x2,x3...xn��
����Ҫ����Щ����ȥ����������������ܳƳ������в�ͬ��������
ע��
������������0
����ԭ�ͣ� public   static   int  fama( int  n,  int [] weight,  int [] nums)
��������:
�����������������ݡ�
����ÿ��������ݣ�
��һ�У�n --- ������(��Χ[1,10])
�ڶ��У�m1 m2 m3 ... mn --- ÿ�����������(��Χ[1,2000])
�����У�x1 x2 x3 .... xn --- ÿ�����������(��Χ[1,6])
�������:
���ø�����������ԳƳ��Ĳ�ͬ��������
ʾ��1
����
2
1 2
2 1
���
5
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;
void combination(int fama[],int n, int m);
int k, *a;
set<int> Types;
int main()
{
	int n;
	while (cin >> n)
	{
		int *famaType = new int[n];
		int *famaNum = new int[n];
		int tmp;
		int Number=0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			famaType[i] = tmp;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			famaNum[i] = tmp;
			Number += tmp;
		}

		int *fama = new int[Number];
		a = new int[Number];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < famaNum[i]; j++)
			{
				fama[count] = famaType[i];
				count++;
			}
		}
		for (int i = 0; i <= Number; i++)
		{
			k = i;
			combination(fama, Number, 0);
		}
		cout << Types.size() << endl;
		Types.clear();
		delete a;
		delete famaType;
		delete famaNum;
		delete fama;
	}
	return 0;
}

void combination(int fama[] ,int n, int m)
{
	int i;
	if (m<k)
	{
		for (i = n; i >= k - m; i--)  //�������forѭ������Ҫ���ٴΣ�k-m�Ŀ����Ǻܺ���ġ�
		{
			a[m] = i;
			combination(fama,i - 1, m + 1);
		}
	}
	else
	{
		int tmp = 0;
		for (i = 0; i < k; i++)
		{
			tmp += fama[a[i] - 1];
		}
		Types.insert(tmp);
		//cout << tmp << endl;
	}
}

/*
1 �����1��n���е�����������ҽ�������͵�ֵ���뵽set�����У����������ϵĴ�С����
*/


//
//
//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int main()
//{
//
//}