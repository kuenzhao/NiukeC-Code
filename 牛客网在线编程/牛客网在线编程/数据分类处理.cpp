/****************************************************************************************************
题目描述
信息社会，有海量的数据需要分析处理，比如公安局分析身份证号码、 QQ 用户、手机号码、银行帐号等信息及活动记录。
采集输入大数据和分类规则，通过大数据分类处理程序，将大数据分类输出。﻿
输入描述:
﻿一组输入整数序列I和一组规则整数序列R，I和R序列的第一个整数为序列的个数（个数不包含第一个整数）；整数范围为
0~0xFFFFFFFF，序列个数不限
输出描述:
﻿从R依次中取出R<i>，对I进行处理，找到满足条件的I<j>：
I<j>整数对应的数字需要连续包含R<i>对应的数字。比如R<i>为23，I<j>为231，那么I<j>包含了R<i>，条件满足 。
按R<i>从小到大的顺序:
(1)先输出R<i>；
(2)再输出满足条件的I<j>的个数；
(3)然后输出满足条件的I<j>在I序列中的位置索引(从0开始)；
(4)最后再输出I<j>。
附加条件：
(1)R<i>需要从小到大排序。相同的R<i>只需要输出索引小的以及满足条件的I<j>，索引大的需要过滤掉
(2)如果没有满足条件的I<j>，对应的R<i>不用输出
(3)最后需要在输出序列的第一个整数位置记录后续整数序列的个数(不包含“个数”本身)
序列I：15,123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123（第一个15表明后续有15个整数）
序列R：5,6,3,6,3,0（第一个5表明后续有5个整数）
输出：30, 3,6,0,123,3,453,7,3,9,453456,13,453,14,123,6,7,1,456,2,786,4,46,8,665,9,453456,11,456,12,786
说明：
30----后续有30个整数
3----从小到大排序，第一个R<i>为0，但没有满足条件的I<j>，不输出0，而下一个R<i>是3
6--- 存在6个包含3的I<j>
0--- 123所在的原序号为0
123--- 123包含3，满足条件
示例1
输入
15 123 456 786 453 46 7 5 3 665 453456 745 456 786 453 123
5 6 3 6 3 0
输出
30 3 6 0 123 3 453 7 3 9 453456 13 453 14 123 6 7 1 456 2 786 4 46 8 665 9 453456 11 456 12 786
*****************************************************************************************************/
/****************************************************************************************************
解题思路：
1.首先R(i)首先存储到一个set中，自动去重排序。
2.将数字和索引放入一个map中，这样避免了数字的重复。
3.将要查询的数字和map组成一个结构体存入到vector中。
4.将所有的数字全部转换成字符串，将是否连续包含该数字转换成是否包含指定的子串。查找子串是用str.find()函数
*****************************************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<set>

using namespace std;
//首先数字转字符串

struct Iset
{
	string str;
	int index;
	Iset() {}
	Iset(string Str, int Index) :str(Str), index(Index) {}
};

struct OutSet
{
	string number;//被包含的数字
	vector<Iset> OutNum;//要输出的数字和索引
};

bool isContained(const string &Istr, const string &Rstr)
{
	string::size_type idx = Istr.find(Rstr);
	if (idx != string::npos)
	{
		return true;
	}
	return false;
}
string NumToString(int num)
{
	stringstream ss;
	ss << num;
	return ss.str();
}
int main()
{
	string str;
	int number;
	int tmp;
	set<int>  Rset;//存储R集合
	vector<string> RIset;
	vector<Iset> iSet;//存储I数据集合，存储的是字符串和索引，如果相同值存储索引较小的
	Iset tmpNum;

	vector<OutSet> Output;
	OutSet outSet;
	set<int>::iterator Sit;
	vector<string>::iterator it;
	vector<Iset>::iterator Iit;
	vector<OutSet>::iterator Oit;
	//接收I集合数据
	while (cin >> number)
	{
		iSet.clear();
		Rset.clear();
		RIset.clear();
		Output.clear();
		outSet.OutNum.clear();
		for (int i = 0; i < number; i++)
		{
			cin >> tmpNum.str;
			tmpNum.index = i;
			iSet.push_back(tmpNum);
		}
		//接收R集合数据
		cin >> number;
		for (int i = 0; i < number; i++)
		{
			cin >> tmp;
			Rset.insert(tmp);
		}
		for (Sit = Rset.begin(); Sit != Rset.end(); Sit++)
		{
			//数字转字符串
			RIset.push_back(NumToString(*Sit));
		}

		
		//进行分类
		int totalNum = 0;
		for (it = RIset.begin(); it != RIset.end(); it++)
		{
			outSet.number = *it;
			for (Iit = iSet.begin(); Iit != iSet.end(); Iit++)
			{
				if (isContained(Iit->str, *it))
				{
					tmpNum.str = Iit->str;
					tmpNum.index = Iit->index;
					outSet.OutNum.push_back(tmpNum);
				}
			}
			if (outSet.OutNum.size() != 0)
			{
				totalNum += (outSet.OutNum.size() * 2) + 2;//计算总个数
				Output.push_back(outSet);
				outSet.OutNum.clear();
			}
		}
		//打印输出
		cout << totalNum ;
		
		for (Oit = Output.begin(); Oit != Output.end(); Oit++)
		{
			cout << " " << Oit->number << " " << Oit->OutNum.size() ;
			for (Iit = Oit->OutNum.begin(); Iit != Oit->OutNum.end(); Iit++)
			{
				cout << " " << Iit->index << " " << Iit->str ;
			}
		}
		cout << endl;
	}
	return 0;
}