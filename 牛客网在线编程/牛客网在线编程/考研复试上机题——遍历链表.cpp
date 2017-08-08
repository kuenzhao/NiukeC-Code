/******************************************************************
��Ŀ����
����һ�������������������
��������:

�����ÿ�������е�һ�а���1��������n(1<=n<=1000)����������һ�а���n��������

�������:

�����ж���������ݣ�����ÿ�����ݣ�
��n������������������֮��������������

ʾ��1
����

4
3 5 7 9

���

3 5 7 9
*******************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef void LinkList;//����ľ�� 
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

typedef struct _tag_LinkList
{
	LinkListNode header;//����ָ����ڵ�  
	int     length;//ͷ����������Ϣ  
}TLinkList;
typedef struct _Number
{
	LinkListNode node;//����ָ����ڵ�  
					  //������ҵ����  
	int          number;
}Number;
//��������
LinkList* LinkList_Create()  //O(1)  
{
	TLinkList *tmp = NULL;

	tmp = (TLinkList *)malloc(sizeof(TLinkList));//����һ��ͷ���ռ�  
	if (tmp == NULL)
	{
		printf("func LinkList_Create() err \n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TLinkList));
	tmp->length = 0;//������ĳ�����Ϊ0  
	tmp->header.next = NULL; //����ͷ����ָ����ָ��NULL  
	return tmp;//����ͷ���  
}
//�������
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)  //O(n)  
{
	int             i = 0;
	LinkListNode    *current = NULL;
	TLinkList       *tList = NULL;

	tList = (TLinkList *)list;

	if (list == NULL || node == NULL || pos<0)
	{
		return -1;
	}
	current = &(tList->header);//��ǰ�ڵ�ָ��ͷ���ָ����  
	for (i = 0; i<pos; i++)//current�ڵ�����Ҫ����ڵ��ͷһ�����  
	{
		current = current->next;
	}
	//�½�� ���� �������  
	node->next = current->next;//node�Ľڵ��ָ����ָ��current�ڵ����һ���ڵ�  
	//ǰ������� ���� �½��  
	current->next = node;//current�ڵ��ָ����ָ��node�ڵ�  
	tList->length++;//����ĳ��ȼ�һ  
	return 0;
}
//����ɾ��
void LinkList_Destroy(LinkList* list)  //O(1)  
{
	if (list == NULL)//����ڵ�����������ɵ����߸���Ҳ����main()�����������������ֻ���ͷ�ͷ���ռ�  
	{
		return;
	}
	free(list);//�ͷ�ͷ���ռ�  
	return;
}
//��������
LinkListNode* LinkList_Get(LinkList* list, int pos)  //O(n)  
{
	int             i = 0;
	LinkListNode    *current = NULL;
	TLinkList       *tList = NULL;

	tList = (TLinkList *)list;

	if (list == NULL || pos<0)
	{
		return NULL;
	}

	current = &(tList->header); //��ֵָ�������ʼ��  
	for (i = 0; i<pos; i++)
	{
		current = current->next;//currentָ�������  
	}
	return current->next;//����currentָ��ڵ����һ���ڵ��  
}

int main()
{
	int count;;
	int number;
	vector<int> arr;
	while (cin >> count)
	{
		for (int i = 0; i < count; i++)
		{
			cin >> number;
			arr.push_back(number);
		}

		sort(arr.begin(), arr.end());

		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << endl;
		}
	}
}