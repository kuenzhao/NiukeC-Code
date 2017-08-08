/******************************************************************
题目描述
建立一个升序链表并遍历输出。
输入描述:

输入的每个案例中第一行包括1个整数：n(1<=n<=1000)，接下来的一行包括n个整数。

输出描述:

可能有多组测试数据，对于每组数据，
将n个整数建立升序链表，之后遍历链表并输出。

示例1
输入

4
3 5 7 9

输出

3 5 7 9
*******************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef void LinkList;//链表的句柄 
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

typedef struct _tag_LinkList
{
	LinkListNode header;//包含指针域节点  
	int     length;//头结点自身的信息  
}TLinkList;
typedef struct _Number
{
	LinkListNode node;//包含指针域节点  
					  //下面是业务域  
	int          number;
}Number;
//创建链表
LinkList* LinkList_Create()  //O(1)  
{
	TLinkList *tmp = NULL;

	tmp = (TLinkList *)malloc(sizeof(TLinkList));//申请一个头结点空间  
	if (tmp == NULL)
	{
		printf("func LinkList_Create() err \n");
		return NULL;
	}
	memset(tmp, 0, sizeof(TLinkList));
	tmp->length = 0;//将链表的长度置为0  
	tmp->header.next = NULL; //链表头结点的指针域指向NULL  
	return tmp;//返回头结点  
}
//链表插入
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
	current = &(tList->header);//当前节点指向头结点指针域  
	for (i = 0; i<pos; i++)//current节点跳到要插入节点的头一个结点  
	{
		current = current->next;
	}
	//新结点 连接 后继链表  
	node->next = current->next;//node的节点的指针域指向current节点的下一个节点  
	//前面的链表 连接 新结点  
	current->next = node;//current节点的指针域指向node节点  
	tList->length++;//链表的长度加一  
	return 0;
}
//链表删除
void LinkList_Destroy(LinkList* list)  //O(1)  
{
	if (list == NULL)//链表节点的生命周期由调用者负责，也就是main()函数负责，链表的销毁只需释放头结点空间  
	{
		return;
	}
	free(list);//释放头结点空间  
	return;
}
//遍历链表
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

	current = &(tList->header); //赋值指针变量初始化  
	for (i = 0; i<pos; i++)
	{
		current = current->next;//current指针向后跳  
	}
	return current->next;//返回current指向节点的下一个节点的  
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