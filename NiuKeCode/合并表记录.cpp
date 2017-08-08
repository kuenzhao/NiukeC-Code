
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
			else m[key] += value;//不存在时赋值，存在时累加
		}
		//map内部本身就是按照key的大小顺序进行存储的 
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
//				Part[i].value += Part[j].value;//对第二键值求和，累加在第一次出现的键值项上，下一步进行重复索引的删除操作
//				for (k = j; k<Key_Value_Pairs_Num - 1; k++)
//					Part[k] = Part[k + 1];
//				j--;
//				Key_Value_Pairs_Num--;
//			}
//		}
//	}
//	//下面进行排序操作
//	Key_Value_Pair Temp;//定义一个结构体，作为交换操作的中间值
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