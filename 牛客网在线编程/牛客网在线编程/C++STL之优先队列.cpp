/****************************************************************************************
优先队列再<queue>中的定义如下：
template<class _Ty,//类型
	class _Container = vector<_Ty>,//容器
	class _Pr = less<typename _Container::value_type> >//比较
	class priority_queue

*****************************************************************************************/
/****************************************************
使用默认的 优先队列，元素的输出顺序由大到小
*****************************************************/
//#include<queue>
//#include<iostream>
//using namespace std;
//int main()
//{
//	priority_queue<char> pqueue;
//	pqueue.push('a');
//	pqueue.push('b');
//	pqueue.push('c');
//	pqueue.push('d');
//	pqueue.push('e');
//	pqueue.push('f');
//
//	while (!pqueue.empty())
//	{
//		cout << pqueue.top() << " ";
//		pqueue.pop();
//	}
//	cout << endl;
//}
/****************************************************
使用自己定义的容器deque的优先队列，元素的输出顺序由大到小
*****************************************************/
//#include<queue>
//#include<deque>
//#include<iostream>
//#include<vector>
//#include<functional>
//using namespace std;
//int main()
//{
//	priority_queue<char,deque<char>> pqueue;//注意这里不一样使用的容器不是一样的了
//	pqueue.push('a');
//	pqueue.push('b');
//	pqueue.push('c');
//	pqueue.push('d');
//	pqueue.push('e');
//	pqueue.push('f');
//
//	while (!pqueue.empty())
//	{
//		cout << pqueue.top() << " ";
//		pqueue.pop();
//	}
//	cout << endl;
//}
/****************************************************
使用自己定义的排序准则的优先队列，元素的输出顺序由小到大
*****************************************************/
//#include<queue>
//#include<deque>
//#include<iostream>
//#include<vector>
//#include<functional>
//using namespace std;
//int main()
//{
//	priority_queue<char, deque<char>,greater<char>> pqueue;//注意这里不一样使用的排序方式是自己定义的
//	pqueue.push('f');
//	pqueue.push('e');
//	pqueue.push('d');
//	pqueue.push('c');
//	pqueue.push('b');
//	pqueue.push('a');
//	
//	while (!pqueue.empty())
//	{
//		cout << pqueue.top() << " ";
//		pqueue.pop();
//	}
//	cout << endl;
//}

/************************************************************************
使用运算符重载自定义结构 : 最小值优先
*************************************************************************/
//#include<queue>
//#include<deque>
//#include<iostream>
//#include<vector>
//#include<functional>
//using namespace std;
//
//struct LetterCom
//{
//	char letter;
//	int index;
//	LetterCom(char ch, int ind) :letter(ch), index(ind) {}
//	bool operator < (const LetterCom &a) const 
//	{
//		return letter>a.letter;//最小值优先  
//	}
//};
//int main()
//{
//	priority_queue<LetterCom> pqueue;//最小值优先
//	pqueue.push(LetterCom('f', 1));
//	pqueue.push(LetterCom('e', 1));
//	pqueue.push(LetterCom('d', 1));
//	pqueue.push(LetterCom('c', 1));
//	pqueue.push(LetterCom('b', 1));
//	pqueue.push(LetterCom('a', 1));
//	
//	while (!pqueue.empty())
//	{
//		cout << pqueue.top().letter << " ";
//		pqueue.pop();
//	}
//	cout << endl;
//}
/************************************************************************
另外一种使用运算符重载自定义结构 : 最小值优先
*************************************************************************/
#include<queue>
#include<deque>
#include<iostream>
#include<vector>
#include<functional>
using namespace std;
struct cmp1 {
	bool operator ()(char &a, char &b) {
		return a>b;//最小值优先  
	}
};
int main()
{
	//priority_queue<char, vector<char>, cmp1>que1;//最小值优先  
	priority_queue<char, deque<char>, cmp1> pqueue;//注意这里不一样使用的排序方式是自己定义的
	pqueue.push('f');
	pqueue.push('e');
	pqueue.push('d');
	pqueue.push('c');
	pqueue.push('b');
	pqueue.push('a');
	
	while (!pqueue.empty())
	{
		cout << pqueue.top() << " ";
		pqueue.pop();
	}
	cout << endl;
}










#include<stdio.h>  
#include<functional>  
#include<queue>  
#include<vector>  
using namespace std;
//定义结构，使用运算符重载,自定义优先级1  
struct cmp1 {
	bool operator ()(int &a, int &b) {
		return a>b;//最小值优先  
	}
};
struct cmp2 {
	bool operator ()(int &a, int &b) {
		return a<b;//最大值优先  
	}
};
//定义结构，使用运算符重载,自定义优先级2  
struct number1 {
	int x;
	bool operator < (const number1 &a) const {
		return x>a.x;//最小值优先  
	}
};
struct number2 {
	int x;
	bool operator < (const number2 &a) const {
		return x<a.x;//最大值优先  
	}
};
int a[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number1 num1[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number2 num2[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };

int main()
{
	priority_queue<int>que;//采用默认优先级构造队列  

	priority_queue<int, vector<int>, cmp1>que1;//最小值优先  
	priority_queue<int, vector<int>, cmp2>que2;//最大值优先  

	priority_queue<int, vector<int>, greater<int> >que3;//注意“>>”会被认为错误，  
														//这是右移运算符，所以这里用空格号隔开  
	priority_queue<int, vector<int>, less<int> >que4;////最大值优先  

	priority_queue<number1>que5;
	priority_queue<number2>que6;

	int i;
	for (i = 0; a[i]; i++) {
		que.push(a[i]);
		que1.push(a[i]);
		que2.push(a[i]);
		que3.push(a[i]);
		que4.push(a[i]);
	}
	for (i = 0; num1[i].x; i++)
		que5.push(num1[i]);
	for (i = 0; num2[i].x; i++)
		que6.push(num2[i]);


	printf("采用默认优先关系:\n(priority_queue<int>que;)\n");
	printf("Queue 0:\n");
	while (!que.empty()) {
		printf("%3d", que.top());
		que.pop();
	}
	puts("");
	puts("");

	printf("采用结构体自定义优先级方式一:\n(priority_queue<int,vector<int>,cmp>que;)\n");
	printf("Queue 1:\n");
	while (!que1.empty()) {
		printf("%3d", que1.top());
		que1.pop();
	}
	puts("");
	printf("Queue 2:\n");
	while (!que2.empty()) {
		printf("%3d", que2.top());
		que2.pop();
	}
	puts("");
	puts("");
	printf("采用头文件\"functional\"内定义优先级:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
	printf("Queue 3:\n");
	while (!que3.empty()) {
		printf("%3d", que3.top());
		que3.pop();
	}
	puts("");
	printf("Queue 4:\n");
	while (!que4.empty()) {
		printf("%3d", que4.top());
		que4.pop();
	}
	puts("");
	puts("");
	printf("采用结构体自定义优先级方式二:\n(priority_queue<number>que)\n");
	printf("Queue 5:\n");
	while (!que5.empty()) {
		printf("%3d", que5.top());
		que5.pop();
	}
	puts("");
	printf("Queue 6:\n");
	while (!que6.empty()) {
		printf("%3d", que6.top());
		que6.pop();
	}
	puts("");
	return 0;
}