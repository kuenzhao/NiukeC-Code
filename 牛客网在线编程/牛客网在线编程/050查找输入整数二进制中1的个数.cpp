/*
��Ŀ����

��ʵ�����½ӿ�

public   static   int  findNumberOf1( int num)

{

��ʵ��  

return  0;

	} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2



	�漰֪ʶ�㣺
		�������� :

	����һ������

		������� :

	����������������1�ĸ���

		ʾ��1
		����

		5

		���

		2


*/
#include<iostream>
using namespace std;
int BitCount2(unsigned int n)
{
	unsigned int c = 0;
	for (c = 0; n; ++c)
	{
		n &= (n - 1); // ������λ��1
	}
	return c;
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << BitCount2(num) << endl;
	}
	return 0;
}