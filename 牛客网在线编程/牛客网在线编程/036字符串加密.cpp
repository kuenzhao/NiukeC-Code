/*********************************************************************************
��Ŀ����
��һ�ּ��ɿ��Զ����ݽ��м��ܣ���ʹ��һ��������Ϊ�����ܳס����������Ĺ���ԭ�����ȣ�
ѡ��һ��������Ϊ�ܳף���TRAILBLAZERS����������а������ظ�����ĸ��ֻ������1��������
�������������ڣ��޸Ĺ����Ǹ�����������ĸ������棬������ʾ��
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
������������ĸ����ʣ�����ĸ����������ڶ���Ϣ���м���ʱ����Ϣ�е�ÿ����ĸ���̶���
�������У������������еĶ�Ӧ��ĸһһȡ��ԭ�ĵ���ĸ(��ĸ�ַ��Ĵ�Сд״̬Ӧ�ñ���)��
��ˣ�ʹ������ܳף�Attack AT DAWN(����ʱ����)�ͻᱻ����ΪTpptad TP ITVH��
��ʵ�������ӿڣ�ͨ��ָ�����ܳ׺����ĵõ����ġ�
��ϸ������
�ӿ�˵��
ԭ�ͣ�
voidencrypt(char * key,char * data,char * encrypt);
���������
char * key���ܳ�
char * data������
���������
char * encrypt������
����ֵ��
void
��������:
������key��Ҫ���ܵ��ַ���
�������:
���ؼ��ܺ���ַ���
ʾ��1
����
nihao
ni
���
le
**********************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string duplicate1(string str)
{
	if (str.size()<2)
		return str;
	string tmp_str("\0");
	tmp_str += str[0];
	string::size_type j;
	for (string::size_type i = 1; i<str.size(); i++)
	{
		for (j = 0; j<tmp_str.size(); j++)
		{
			if (tmp_str[j] == str[i])
				break;
		}
		if (j == tmp_str.size())
			tmp_str += str[i];
	}
	return tmp_str;
}
void duplicate(string &str)//���ù�ϣ��ɾ���ظ����ַ�
{
	if (str.size()<2)
		return;
	int hash[256] = {0};
	
	hash[str[0]] = 1;
	int tail = 1;
	for (string::size_type i = 1; i<str.size(); i++)
	{
		if (hash[str[i]] == 0)
		{
			str[tail++] = str[i];
			hash[str[i]] += 1;
		}
	}
	str = str.substr(0, tail);
}

int main()
{
	string key,s;
	while (cin >> key>>s)
	{
		string R;
		int p[26] = { 0 };
		for (int i = 0; i<key.length(); i++) {
			if (key[i] >= 'a'&&key[i] <= 'z') {
				if (p[key[i] - 'a'] == 0) {
					R += key[i] - 32;
					p[key[i] - 'a'] = 1;
				}
			}
			else {
				if (p[key[i] - 'A'] == 0) {
					R += key[i];
					p[key[i] - 'A'] = 1;
				}
			}
		}
		for (int i = 0; i<26; i++)
			if (p[i] == 0)
				R += 'A' + i;
		for (int i = 0; i<s.length(); i++)
			if (s[i] >= 'a') {
				char c = R[s[i] - 'a'] + 32;
				cout << c;
			}
			else {
				cout << R[s[i] - 'A'];
			}
			cout << endl;

	}
	return 0;
}
