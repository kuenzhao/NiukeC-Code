/*
��Ŀ����
�������������������
xcopy /s c:\ d:\��
�����������£�
����1��������xcopy
����2���ַ���/s
����3���ַ���c:\
����4: �ַ���d:\
���дһ��������������ʵ�ֽ������и�����������������
��������
1.�����ָ���Ϊ�ո�
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s 
��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��
������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.����������
4.������������֤��������ֲ�����Ҫ�������

��������:
����һ���ַ����������пո�
�������:
��������������ֽ��Ĳ�����ÿ����������ռһ��
ʾ��1
����
xcopy /s c:\\ d:\\
���
4
xcopy
/s
c:\\
d:\\
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;

	while (getline(cin,str))
	{
		vector<string> output;
		string tmp;
		for (string::size_type i = 0; i <= str.size(); i++)
		{
			if (str[i] == '"')
			{
				while (str[i] == '"')
				{
					tmp += str[i];
					i++;
				}
			}
			else if (str[i] == ' '|| i == str.size())
			{
				output.push_back(tmp);
				tmp.clear();
			}
			else
			{
				tmp += str[i];
			}
		}

		cout << output.size() << endl;
		for (unsigned long i = 0; i < output.size(); i++)
		{
			cout << output[i] << endl;
		}

		output.clear();
	}

	return 0;
}