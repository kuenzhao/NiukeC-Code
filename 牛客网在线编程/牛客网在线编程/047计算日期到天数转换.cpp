/*
��Ŀ����

������������ڣ���������һ��ĵڼ��졣��

��ϸ������

����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��
�ӿ���Ƽ�˵����

*****************************************************************************
Description   : ����ת��
Input Param   : year �������
Month �����·�
Day ������

Output Param  :
Return Value  : �ɹ�����0��ʧ�ܷ���-1���磺���ݴ���
*****************************************************************************
public static int iConverDateToDay(int year, int month, int day)
{
	 ������ʵ�ֹ��ܣ��������������������
	return 0;
}

*****************************************************************************
Description   :
Input Param   :

Output Param  :
Return Value  : �ɹ�:����outDay��������ĵڼ���;
ʧ��:����-1
*****************************************************************************
public static int getOutDay()
{
	return 0;
}
��������:

�������У��ֱ����꣬�£���

������� :

�ɹ�:����outDay��������ĵڼ���;
ʧ��:���� - 1
	ʾ��1
	����
	2012
	12
	31
	���
	366
*/

#include<iostream>
using namespace std;

bool is_LeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	int year, month, day;
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> year >> month >> day)
	{
		int days = 0;
		
		for (int i = 0; i < month - 1;i ++)
		{
			days += months[i];
		}
		days += day;

		if (is_LeapYear(year) && month > 2)
		{
			cout << days + 1 << endl;
		}
		else
		{
			cout << days << endl;
		}
	}

	return 0;
}