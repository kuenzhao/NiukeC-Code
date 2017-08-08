#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define N 9 //����Ԫ�ظ���  
int array[N] = { 2, 1, 6, 3, 5, 4, 8, 7, 9 }; //ԭ����  
int B[N]; //�ڶ�̬�滮��ʹ�õ�����,���ڼ�¼�м���,�京����������˵����,��μ����ĵĽ���  
int len; //���ڱ�ʾB�����е�Ԫ�ظ���  

int LIS(int *array, int n); //��������������еĳ���,����B�����Ԫ��,array[]ѭ����һ���,B�ĳ���len��Ϊ����  
int BiSearch(int *b, int len, int w); //�����޸ĵĶ��������㷨  

int main()
{
	printf("LIS: %d\n", LIS(array, N));

	int i;
	for (i = 0; i<len; ++i)
	{
		printf("B[%d]=%d\n", i, B[i]);
	}

	return 0;
}

int LIS(int *array, int n)
{
	len = 1;
	B[0] = array[0];
	int i, pos = 0;

	for (i = 1; i<n; ++i)
	{
		if (array[i] > B[len - 1]) //�������B������Ԫ�أ���ֱ�Ӳ��뵽B����ĩβ  
		{
			B[len] = array[i];
			++len;
		}
		else
		{
			pos = BiSearch(B, len, array[i]); //���ֲ�����Ҫ�����λ��  
			B[pos] = array[i];
		}
	}

	return len;
}

//�޸ĵĶ��ֲ����㷨����������Ԫ����Ҫ�����λ�á�  
int BiSearch(int *b, int len, int w)
{
	int left = 0, right = len - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (b[mid] > w)
			right = mid - 1;
		else if (b[mid] < w)
			left = mid + 1;
		else    //�ҵ��˸�Ԫ�أ���ֱ�ӷ���  
			return mid;
	}
	return left;//����b�в����ڸ�Ԫ�أ��򷵻ظ�Ԫ��Ӧ�ò����λ��  
}