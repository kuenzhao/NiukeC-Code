/*********************************************************
��Ŀ����
��Ŀ˵��
���ξ�������1��ʼ����Ȼ���������гɵ�һ�������������Ρ�
��������
5
�������
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
�ӿ�˵��
ԭ��
void GetResult(int Num, char * pResult);
���������
int Num�������������N
���������
int * pResult��ָ�������ξ�����ַ���ָ��
ָ��ָ����ڴ�����֤��Ч
����ֵ��
void
�������� :
����������N��N������100��
������� :
���һ��N�е����ξ���
ʾ��1
����
4
���
1 3 6 10
2 5 9
4 8
7
*****************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void GetResult(int Num, char * pResult)
{
	int **arr = new int *[Num];
	for (int i = 0; i < Num; i++)
	{
		arr[i] = new int[Num];
	}

	for (int i = 0; i < Num; i++)
	{
		for (int j = 0; j < Num-i; j++)
		{
			if (i == 0)
			{
				arr[i][j] = (j + 1)*(j + 2) / 2;
				if (j == 0)
				{
					cout << arr[i][j];
				}
				else
				{
					cout << " " << arr[i][j] ;
				}			
			}
			else
			{
				arr[i][j] = arr[i - 1][j + 1] - 1;
				if (j == 0)
				{
					cout << arr[i][j];
				}
				else
				{
					cout << " " << arr[i][j];
				}
			}	
		}
		cout << endl;
	}
}
int main()
{
	char *result = NULL;
	int Num;
	while (cin >> Num)
	{
		GetResult(Num, result);
	}

	
	return 0;
}