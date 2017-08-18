///*
//��Ŀ����
//
//��Pi��ʾ��i�����������θ�����������M <= N <= 10000�������PM��PN������������
//
//
//��������:
//
//������һ���и���M��N������Կո�ָ���
//
//
//
//�������:
//
//�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
//
//
//��������:
//
//5 27
//
//
//�������:
//
//11 13 17 19 23 29 31 37 41 43
//
//47 53 59 61 67 71 73 79 83 89
//
//97 101 103
//*/
//
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int min =  0 , max = 0;
	vector<int> prime;
	int count = 2;
	cin >> min >> max;
	while (prime.size() < max)
	{
		if (isPrime(count))
		{
			prime.push_back(count);
		}
		count++;
	}
	int count1 = 1;
	for (int i = min; i <= max; i++)
	{
		if (count1 == 10 || i == max)
		{
			cout << prime[i - 1] << endl;
			count1 = 0;
		}
		else
		{
			cout << prime[i - 1] << " ";
		}
		count1++;
	}
	return 0;
}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	using namespace std;
//	int m, n, count = 0;
//	cin >> m >> n;
//	for (int i = 2; count <= n; i++)
//	{
//		int temp = 0;
//		for (int j = 2; j <= sqrt(i); j++)
//			if (i % j == 0)
//				++temp;
//		if (temp == 0)
//			++count;
//		if (count >= m && count <= n && temp == 0)
//		{
//			cout << i;
//			if ((count - m) % 10 == 9)
//				cout << endl;
//			else if (count != n)
//				cout << " ";
//		}
//	}
//	cout << endl;
//	return 0;
//}