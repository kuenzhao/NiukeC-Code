/*

题目描述
Tracking Area Identity（TAI）是跟踪区标识=，其中PLMN为三个字节的BCD码，TAC是长度为2个字节的数字。
现需要实现一个功能，输入若干个TAI范围，合并成一个TAI LIST输出。 输出按照TAI排序，并去除相同TAI。
BCD码是一种用4位二进制数来表示1位十进制数中的0~9这10个数码的数字编码形式。待编码的数字从高到低以逐个存放，先存在低字节，再存在高字节，不足时用F补齐。
如，460001的BCD码为 64 00 01，46001BCD码为 64 00 1F
PLMN大小比较规则
460001<64 00 10> 小于 460002<64 00 20>
460002<64 00 20> 小于 460011<64 00 11>
46000 <64 00 F0> 小于 460000<64 00 00>
TAC比较规则
按数值大小比较
输入的BCD码保证都是合法的,且tac_begin小于等于tac_end
例 输入5个Tai范围
<64 00 10><0x00>:<0x03>
<64 00 10><0xff00>:<0xff00>
<64 00 20><0x02>:<0x02>
<55 00 10><0x02>:<0x02>
<64 00 10><0x02>:<0x04>
输出8个Tai
<64 00 10><0x00>
<64 00 10><0x01>
<64 00 10><0x02>
<64 00 10><0x03>
<64 00 10><0x04>
<64 00 10><0xff00>
<64 00 20><0x02>
<55 00 10><0x02>
//tai_range range_num tai范围列表，及个数
//tailist tai_num 输出结果，tailist内存由考生malloc，调用者负责释放。
//成功返回 0 失败返回-1
int CalcTaiList(const S_TAI_RANGE *tai_range, int range_num, S_TAI **tailist, int *tai_num);
输入描述:
tai范围
输出描述:
tai列表
示例1
输入

{{0x64, 0x00, 0x10},0x00,0x03},                               
{{0x64, 0x00, 0x10},0xff00,0xff00},
{{0x64, 0x00, 0x20},0x02,0x02},
{{0x55, 0x00, 0x10},0x02,0x02},
{{0x64, 0x00, 0x10},0x02,0x04},
输出

{{0x64, 0x00, 0x10},0x00},
{{0x64, 0x00, 0x10},0x01},
{{0x64, 0x00, 0x10},0x02},
{{0x64, 0x00, 0x10},0x03},
{{0x64, 0x00, 0x10},0x04},
{{0x64, 0x00, 0x10},0xff00},
{{0x64, 0x00, 0x20},0x02},
{{0x55, 0x00, 0x10},0x02}
*/

#include<iostream>
#include<string>

#include<sstream>
using namespace std;
unsigned int StrToDecimal(string str)
{
	stringstream stream;
	unsigned int n;
	stream << str;     //向stream中插入字符串"1234" 
	stream >> n;     //从stream中提取刚插入的字符串"1234"  并将其赋予变量n完成字符串到int的转换 
	return n;
}

int main()
{
	string str;
	while (getline(cin,str))
	{
		string tmp;
		for (string::size_type i = 0; i < str.size() - 1; i++)
		{
			while (str[i] != '}')
			{
				if (str[i] == '0'&&str[i + 1] == 'x')
				{
					tmp += str[i + 3];
					if (str[i + 2] >= '0'&& str[i + 2] <= '9')
					{
						tmp += str[i + 2];
					}
				}
			}
			while (str[i] != '}')
			{
				if (str[i] == ',')
				{
					int size = StrToDecimal(tmp);
				}
				else
				{
					if (str[i] == '0'&&str[i + 1] == 'x')
					{
						tmp += str[i + 3];
						if (str[i + 2] >= '0'&& str[i + 2] <= '9')
						{
							tmp += str[i + 2];
						}
					}
				}
				
			}
		}

		cout << tmp << endl;
	}

	return 0;
}