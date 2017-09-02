/*
牛牛有n张卡片排成一个序列.每张卡片一面是黑色的,另一面是白色的。初始状态的时候有些卡片是黑色朝上,有些卡片是白色朝上。牛牛现在想要把一些卡片翻过来,得到一种交替排列的形式,即每对相邻卡片的颜色都是不一样的。牛牛想知道最少需要翻转多少张卡片可以变成交替排列的形式。
输入描述:

输入包括一个字符串S,字符串长度length(3 ≤ length ≤ 50),其中只包含'W'和'B'两种字符串,分别表示白色和黑色。整个字符串表示卡片序列的初始状态。



输出描述:

输出一个整数,表示牛牛最多需要翻转的次数。


输入例子1:

BBBW


输出例子1:

1
*/

#include <iostream>
#include<string>
using  namespace std;


/***********************
1.定义四个变量
nEvenWhite: 偶数位置白色个数
nEvenBlack: 偶数位置黑色个数
nOddWhite:  奇数位置白色个数
nOddBlack:  奇数位置黑色个数
2.则最终
把偶数位置的白色变为黑色，奇数位置黑色变成白色
把奇数位置的白色变成黑色，偶数位置的黑色变成白色
3.结果即是上树两种结果最小值
************************/
int main()
{

	string str;
	cin >> str;
	int  nCount = str.length();
	int nEvenWhite = 0;
	int nEvenBlack = 0;
	int nOddWhite = 0;
	int nOddBlack = 0;
	for (int i = 0; i<nCount; ++i)
	{
		if (i % 2)
		{
			if (str[i] == 'W')
			{
				nOddWhite++;
			}
			else
			{
				nOddBlack++;
			}
		}
		else
		{
			if (str[i] == 'W')
			{
				nEvenWhite++;
			}
			else
			{
				nEvenBlack++;
			}

		}
	}
	int ans = nEvenWhite + nOddBlack >nEvenBlack + nOddWhite ? nEvenBlack + nOddWhite : nEvenWhite + nOddBlack;

	cout << ans << endl;

}