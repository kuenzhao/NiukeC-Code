
#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		map<int, int> m;
		while (n--) {
			int key, value;
			cin >> key >> value;
			if (!m[key]) {
				m[key] = value;
			}
			else m[key] += value;//������ʱ��ֵ������ʱ�ۼ�
		}
		//map�ڲ�������ǰ���key�Ĵ�С˳����д洢�� 
		for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			cout << it->first << " " << it->second << endl;
		}
	}
	return 0;
}




//#include<iostream>
//using namespace std;
//struct Key_Value_Pair
//{
//	int index;
//	int value;
//};
//int main()
//{
//	Key_Value_Pair Part[1000];
//	int Key_Value_Pairs_Num, i, j, k;
//	cin >> Key_Value_Pairs_Num;
//	for (i = 0; i<Key_Value_Pairs_Num; i++)
//		cin >> Part[i].index >> Part[i].value;
//	for (i = 0; i<Key_Value_Pairs_Num; i++)
//	{
//		for (j = i + 1; j<Key_Value_Pairs_Num; j++)
//		{
//			if (Part[i].index == Part[j].index)
//			{
//				Part[i].value += Part[j].value;//�Եڶ���ֵ��ͣ��ۼ��ڵ�һ�γ��ֵļ�ֵ���ϣ���һ�������ظ�������ɾ������
//				for (k = j; k<Key_Value_Pairs_Num - 1; k++)
//					Part[k] = Part[k + 1];
//				j--;
//				Key_Value_Pairs_Num--;
//			}
//		}
//	}
//	//��������������
//	Key_Value_Pair Temp;//����һ���ṹ�壬��Ϊ�����������м�ֵ
//	for (i = 0; i<Key_Value_Pairs_Num - 1; i++)
//	{
//		for (j = 0; j<Key_Value_Pairs_Num - 1 - i; j++)
//		{
//			if (Part[j].index>Part[j + 1].index)
//			{
//				Temp = Part[j];
//				Part[j] = Part[j + 1];
//				Part[j + 1] = Temp;
//			}
//		}
//	}
//	for (i = 0; i<Key_Value_Pairs_Num; i++)
//		cout << Part[i].index << " " << Part[i].value << endl;
//	return 0;
//}