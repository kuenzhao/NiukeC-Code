/****************************************************************************************
题目描述
计算最少出列多少位同学，使得剩下的同学排成合唱队形
说明：
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   
则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入描述:
整数N
输出描述:
最少需要几位同学出列
示例1
输入
8
186 186 150 200 160 130 197 200
输出
4
*****************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calIncSub(vector<int> quene, vector<int> &Num) 
{
	for (int i = 1; i<quene.size(); i++)
		for (int j = i - 1; j >= 0; j--)
			if (quene[j]<quene[i] && Num[i]<Num[j] + 1)//找到前面比当前小的，且【能获得的最大子串计数】
				Num[i] = Num[j] + 1;
}

int main() {
	int n;
	int h;

	while (cin >> n) {
		vector<int> quene;
		vector<int> incNum(n, 1);//初始化为n个1
		vector<int> decNum(n, 1);
		vector<int> totalNum;
		for (int i = 0; i<n; i++) {
			cin >> h;
			quene.push_back(h);
		}
		calIncSub(quene, incNum);//找递增子串计数
		reverse(quene.begin(), quene.end()); //翻转，即找反向的子串计数
		calIncSub(quene, decNum);
		reverse(decNum.begin(), decNum.end());//反向递增即正向递减
		int max = 0;
		for (int i = 0; i<n; i++) {
			totalNum.push_back(incNum[i] + decNum[i]);
			if (totalNum[i]>max)
				max = totalNum[i];
		}
		cout << n - max + 1 << endl;
	}
	return 0;
}