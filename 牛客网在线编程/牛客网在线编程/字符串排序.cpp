/************************************************************************************************
��Ŀ����
��дһ�����򣬽������ַ����е��ַ������¹�������
���� 1 ��Ӣ����ĸ�� A �� Z ���У������ִ�Сд��
�磬���룺 Type   ����� epTy
���� 2 ��ͬһ��Ӣ����ĸ�Ĵ�Сдͬʱ����ʱ����������˳�����С�
�磬���룺 BabA   ����� aABb
���� 3 ����Ӣ����ĸ�������ַ�����ԭ����λ�á�
�磬���룺 By?e   ����� Be?y
������
���룺
A Famous Saying: Much Ado About Nothing(2012/8).
�����
A  aaAAbc   dFgghh :  iimM   nNn   oooos   Sttuuuy  (2012/8).
��������:
�������:
ʾ��1
����
A Famous Saying: Much Ado About Nothing (2012/8).
���
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*************************************************************************************************/
/************************************************************************************************
����˼·��
1.����д��ĸ��Сд��ĸ���Լ���ĸ��������洢����ͬ�����ȶ����С�
2.���ν���ĸ���г��Ӳ������Ƚ���ĸ˯С˭���ӣ������Сд��ĸ��ͬ�Ƚ����ǵ������ţ�˭С˭����
3.�����ӵ���ĸ����ԭ�����ַ���˳��ֵ���ַ������ո�������ַ�λ�ò���
*************************************************************************************************/
#include<iostream>  
#include<functional>  
#include<queue>  
#include<vector> 
#include<string>
using namespace std;
//����ṹ��ʹ�����������,�Զ������ȼ�1  
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
			return letter>a.letter;//��Сֵ����  
		}	
	}
};

int main()
{
	
	string str;
	while (getline(cin, str))
	{
		priority_queue<LetterCom>queLar;//�洢��д��ĸ  
		priority_queue<LetterCom>queLit;//�洢Сд��ĸ
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
//		return a<b;//���ֵ����  
//	}
//};
////����ṹ��ʹ�����������,�Զ������ȼ�2  
//struct number1 {
//	int x;
//	bool operator < (const number1 &a) const {
//		return x>a.x;//��Сֵ����  
//	}
//};
//struct number2 {
//	int x;
//	bool operator < (const number2 &a) const {
//		return x<a.x;//���ֵ����  
//	}
//};
//int a[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
//number1 num1[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
//number2 num2[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
//
//int main()
//{
//	priority_queue<int>que;//����Ĭ�����ȼ��������  
//
//	priority_queue<int, vector<int>, cmp1>que1;//��Сֵ����  
//	priority_queue<int, vector<int>, cmp2>que2;//���ֵ����  
//
//	priority_queue<int, vector<int>, greater<int> >que3;//ע�⡰>>���ᱻ��Ϊ����  
//														//������������������������ÿո�Ÿ���  
//	priority_queue<int, vector<int>, less<int> >que4;////���ֵ����  
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
//	printf("����Ĭ�����ȹ�ϵ:\n(priority_queue<int>que;)\n");
//	printf("Queue 0:\n");
//	while (!que.empty()) {
//		printf("%3d", que.top());
//		que.pop();
//	}
//	puts("");
//	puts("");
//
//	printf("���ýṹ���Զ������ȼ���ʽһ:\n(priority_queue<int,vector<int>,cmp>que;)\n");
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
//	printf("����ͷ�ļ�\"functional\"�ڶ������ȼ�:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
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
//	printf("���ýṹ���Զ������ȼ���ʽ��:\n(priority_queue<number>que)\n");
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









