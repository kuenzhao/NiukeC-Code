/*
��Ŀ����

���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
��������:

��������������

�������:

���ؽ��

ʾ��1
����

2
2

���

6
*/

#include <iostream>

using namespace std;

int func(int m, int n) {
	if (m == 0 || n == 0) {
		return 1;
	}
	return func(m, n - 1) + func(m - 1, n);
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		cout << func(m, n) << endl;
	}

	return 0;
}