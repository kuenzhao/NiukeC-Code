/*

��Ŀ����
Tracking Area Identity��TAI���Ǹ�������ʶ=������PLMNΪ�����ֽڵ�BCD�룬TAC�ǳ���Ϊ2���ֽڵ����֡�
����Ҫʵ��һ�����ܣ��������ɸ�TAI��Χ���ϲ���һ��TAI LIST����� �������TAI���򣬲�ȥ����ͬTAI��
BCD����һ����4λ������������ʾ1λʮ�������е�0~9��10����������ֱ�����ʽ������������ִӸߵ����������ţ��ȴ��ڵ��ֽڣ��ٴ��ڸ��ֽڣ�����ʱ��F���롣
�磬460001��BCD��Ϊ 64 00 01��46001BCD��Ϊ 64 00 1F
PLMN��С�ȽϹ���
460001<64 00 10> С�� 460002<64 00 20>
460002<64 00 20> С�� 460011<64 00 11>
46000 <64 00 F0> С�� 460000<64 00 00>
TAC�ȽϹ���
����ֵ��С�Ƚ�
�����BCD�뱣֤���ǺϷ���,��tac_beginС�ڵ���tac_end
�� ����5��Tai��Χ
<64 00 10><0x00>:<0x03>
<64 00 10><0xff00>:<0xff00>
<64 00 20><0x02>:<0x02>
<55 00 10><0x02>:<0x02>
<64 00 10><0x02>:<0x04>
���8��Tai
<64 00 10><0x00>
<64 00 10><0x01>
<64 00 10><0x02>
<64 00 10><0x03>
<64 00 10><0x04>
<64 00 10><0xff00>
<64 00 20><0x02>
<55 00 10><0x02>
//tai_range range_num tai��Χ�б�������
//tailist tai_num ��������tailist�ڴ��ɿ���malloc�������߸����ͷš�
//�ɹ����� 0 ʧ�ܷ���-1
int CalcTaiList(const S_TAI_RANGE *tai_range, int range_num, S_TAI **tailist, int *tai_num);
��������:
tai��Χ
�������:
tai�б�
ʾ��1
����

{{0x64, 0x00, 0x10},0x00,0x03},                               
{{0x64, 0x00, 0x10},0xff00,0xff00},
{{0x64, 0x00, 0x20},0x02,0x02},
{{0x55, 0x00, 0x10},0x02,0x02},
{{0x64, 0x00, 0x10},0x02,0x04},
���

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
	stream << str;     //��stream�в����ַ���"1234" 
	stream >> n;     //��stream����ȡ�ղ�����ַ���"1234"  �����丳�����n����ַ�����int��ת�� 
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