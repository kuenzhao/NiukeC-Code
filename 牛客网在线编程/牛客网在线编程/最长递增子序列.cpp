#include <iostream>
#include<vector>
using namespace std;
#define len(a) (sizeof(a) / sizeof(a[0])) //���鳤��  
int lis(int arr[], int len)
{
	vector<int> longest;
	longest.push_back(1);
	for (int j = 1; j<len; j++) {
		longest.push_back(1);
		for (int i = 0; i<j; i++) {
			if (arr[i]<arr[j] && longest[j]<longest[i] + 1) { //ע��longest[j]<longest[i]+1�������������ʡ�ԡ�  
				longest[j] = longest[i] + 1; //������arr[j]��β�����е�����������г���  
			}
		}
	}

	int max = 0;
	for (int j = 0; j<len; j++) {
		cout << "longest[" << j << "]=" << longest[j] << endl;
		if (longest[j] > max) max = longest[j];  //��longest[j]���ҳ����ֵ  
	}
	return max;
}

int main()
{
	int arr[] = { 1, 4, 5, 6, 2, 3, 8 }; //��������  
	int ret = lis(arr, len(arr));
	cout << "max increment substring len=" << ret << endl;
	return 0;
}