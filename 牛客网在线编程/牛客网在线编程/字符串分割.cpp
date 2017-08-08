//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string str1;
//	string str2;
//	char outputArray[8];
//	memset(outputArray, '0', 8);
//	while (cin >> str1 >> str2)
//	{
//		int count = 0;
//
//		for (int i = 0; i < str1.size(); i++)
//		{
//			outputArray[count] = str1[i];
//			count++;
//			count = count % 8;
//			if (count == 0)
//			{
//				for (int j = 0; j < 8; j++)
//					cout << outputArray[j];
//				cout << endl;
//				memset(outputArray, '0', 8);
//			}
//		}
//		for (int j = 0; j < 8; j++)
//			cout << outputArray[j];
//		cout << endl;
//		memset(outputArray, '0', 8);
//		count = 0;
//		for (int i = 0; i < str2.size(); i++)
//		{
//			outputArray[count] = str2[i];
//			count++;
//			count = count % 8;
//			if (count == 0)
//			{
//				for (int j = 0; j < 8; j++)
//					cout << outputArray[j];
//				cout << endl;
//				memset(outputArray, '0', 8);
//			}
//		}
//
//		for (int j = 0; j < 8; j++)
//			cout << outputArray[j];
//		cout << endl;
//	}
//	
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
void fuck(string str) {
	if (str == "")
		return;
	if (str.size() <= 8) {
		str.append(8 - str.size(), '0');
		cout << str << endl;
		return;
	}
	cout << str.substr(0, 8) << endl;
	fuck(str.substr(8, str.size()));
}
int main() {
	string str1, str2;
	cin >> str1 >> str2;
	fuck(str1);
	fuck(str2);
	return 0;
}