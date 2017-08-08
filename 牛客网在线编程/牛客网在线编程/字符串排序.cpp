/************************************************************************************************
题目描述
编写一个程序，将输入字符串中的字符按如下规则排序。
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
如，输入： Type   输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
如，输入： BabA   输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。
如，输入： By?e   输出： Be?y
样例：
输入：
A Famous Saying: Much Ado About Nothing(2012/8).
输出：
A  aaAAbc   dFgghh :  iimM   nNn   oooos   Sttuuuy  (2012/8).
输入描述:
输出描述:
示例1
输入
A Famous Saying: Much Ado About Nothing (2012/8).
输出
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*************************************************************************************************/
/************************************************************************************************
解题思路：
1.将大写字母和小写字母分以及字母的索引别存储到不同的优先队列中。
2.依次将字母进行出队操作，比较字母睡小谁出队，如果大小写字母相同比较他们的索引号，谁小谁出队
3.将出队的字母按照原来的字符串顺序赋值给字符串，空格等其他字符位置不变
*************************************************************************************************/
#include<iostream>  
#include<functional>  
#include<queue>  
#include<vector> 
#include<string>
using namespace std;
//定义结构，使用运算符重载,自定义优先级1  
struct LetterCom
{
	char letter;
	int index;
	LetterCom() {}
	LetterCom(char ch, int ind) :letter(ch), index(ind) {}
	bool operator < (const LetterCom &a) const 
	{
		if (letter == a.letter)
		{
			return index > a.index;
		}
		else
		{
			return letter>a.letter;//最小值优先  
		}	
	}
};

int main()
{
	
	string str;
	while (getline(cin, str))
	{
		priority_queue<LetterCom>queLar;//存储大写字母  
		priority_queue<LetterCom>queLit;//存储小写字母
		int count = 0;
		LetterCom letter;
		string::iterator strIt;
		for (strIt = str.begin(); strIt != str.end(); strIt++)
		{
			if (*strIt >= 'a'&&*strIt <= 'z')
			{
				letter.letter = *strIt; letter.index = count;
				queLit.push(letter);
			}
			else if (*strIt >= 'A'&&*strIt <= 'Z')
			{
				letter.letter = *strIt; letter.index = count;
				queLar.push(letter);
			}
			count++;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
			{
				if (!queLit.empty() && !queLar.empty())
				{
					if (queLit.top().letter < (queLar.top().letter - ('A' - 'a')))
					{
						str[i] = queLit.top().letter;
						queLit.pop();
					}
					else if (queLit.top().letter == (queLar.top().letter - ('A' - 'a')))
					{
						if (queLit.top().index < queLar.top().index)
						{
							str[i] = queLit.top().letter;
							queLit.pop();
						}
						else if (queLit.top().index > queLar.top().index)
						{
							str[i] = queLar.top().letter;
							queLar.pop();
						}
					}
					else
					{
						str[i] = queLar.top().letter;
						queLar.pop();
					}
				}
				else if (!queLit.empty())
				{
					str[i] = queLit.top().letter; queLit.pop();
				}
				else if (!queLar.empty())
				{
					str[i] = queLar.top().letter; queLar.pop();
				}
			}
		}
		cout << str << endl;
	}
	


	return 0;
}






//struct cmp2 {
//	bool operator ()(int &a, int &b) {
//		return a<b;//最大值优先  
//	}
//};
////定义结构，使用运算符重载,自定义优先级2  
//struct number1 {
//	int x;
//	bool operator < (const number1 &a) const {
//		return x>a.x;//最小值优先  
//	}
//};
//struct number2 {
//	int x;
//	bool operator < (const number2 &a) const {
//		return x<a.x;//最大值优先  
//	}
//};
//int a[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
//number1 num1[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
//number2 num2[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
//
//int main()
//{
//	priority_queue<int>que;//采用默认优先级构造队列  
//
//	priority_queue<int, vector<int>, cmp1>que1;//最小值优先  
//	priority_queue<int, vector<int>, cmp2>que2;//最大值优先  
//
//	priority_queue<int, vector<int>, greater<int> >que3;//注意“>>”会被认为错误，  
//														//这是右移运算符，所以这里用空格号隔开  
//	priority_queue<int, vector<int>, less<int> >que4;////最大值优先  
//
//	priority_queue<number1>que5;
//	priority_queue<number2>que6;
//
//	int i;
//	for (i = 0; a[i]; i++) {
//		que.push(a[i]);
//		que1.push(a[i]);
//		que2.push(a[i]);
//		que3.push(a[i]);
//		que4.push(a[i]);
//	}
//	for (i = 0; num1[i].x; i++)
//		que5.push(num1[i]);
//	for (i = 0; num2[i].x; i++)
//		que6.push(num2[i]);
//
//
//	printf("采用默认优先关系:\n(priority_queue<int>que;)\n");
//	printf("Queue 0:\n");
//	while (!que.empty()) {
//		printf("%3d", que.top());
//		que.pop();
//	}
//	puts("");
//	puts("");
//
//	printf("采用结构体自定义优先级方式一:\n(priority_queue<int,vector<int>,cmp>que;)\n");
//	printf("Queue 1:\n");
//	while (!que1.empty()) {
//		printf("%3d", que1.top());
//		que1.pop();
//	}
//	puts("");
//	printf("Queue 2:\n");
//	while (!que2.empty()) {
//		printf("%3d", que2.top());
//		que2.pop();
//	}
//	puts("");
//	puts("");
//	printf("采用头文件\"functional\"内定义优先级:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
//	printf("Queue 3:\n");
//	while (!que3.empty()) {
//		printf("%3d", que3.top());
//		que3.pop();
//	}
//	puts("");
//	printf("Queue 4:\n");
//	while (!que4.empty()) {
//		printf("%3d", que4.top());
//		que4.pop();
//	}
//	puts("");
//	puts("");
//	printf("采用结构体自定义优先级方式二:\n(priority_queue<number>que)\n");
//	printf("Queue 5:\n");
//	while (!que5.empty()) {
//		printf("%3d", que5.top());
//		que5.pop();
//	}
//	puts("");
//	printf("Queue 6:\n");
//	while (!que6.empty()) {
//		printf("%3d", que6.top());
//		que6.pop();
//	}
//	puts("");
//	return 0;
//}









