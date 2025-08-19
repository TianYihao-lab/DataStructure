#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct ListNode
{
	E element;
	struct ListNode *next;
} ListNode, *Node;

void initList(Node node)
{ // ��ʼ������
	node->next = NULL;
	// ��һ���ڵ�����׽ڵ㣬��û��element
	node->element = 0; // Ҳ���Գ�ʼ��element��ԱΪ0
}

_Bool insertList(Node node, E e, int index)
{ // �ڹ̶�λ���ϲ���Ԫ��e
	if (index < 1)
		return 0; // ����λ�ò��Ϸ������һ��

	while (--index)
	{
		node = node->next;
		if (node == NULL)
			return 0; // ����λ�ò��Ϸ����������
	}

	Node newnode = (ListNode *)malloc(sizeof(ListNode));
	if (newnode == NULL)
		return 0;
	newnode->element = e;
	newnode->next = node->next;
	node->next = newnode;
	return 1;
}

_Bool deleteList(Node node, int index)
{ // ɾ���涨λ���ϵ�Ԫ��
	if (index < 1)
		return 0;
	while (--index)
	{ // �ҵ�Ҫɾ���ڵ��ǰһ��λ��
		node = node->next;
		if (node == NULL)
			return 0;
	}
	if (node->next == NULL)
		return 0; //
	Node tempnode = node->next;
	node->next = tempnode->next;
	free(tempnode);
	return 1;
}

E *getList(Node node, int index)
{ // �������е�index��λ���ϵ�ֵ

	if (index < 1)
		return 0;
	while (index--)
	{
		if (node == NULL)
			return 0;

		node = node->next;
	}
	return &node->element;
}
// E * getList(Node node, int index) {
//	int cnt = 0;
//	if (index < 1)return 0;
//	while (node != NULL) {
//		if (cnt == index)
//			return &node->element;
//		node = node->next;
//		cnt++;
//	}
//	return 0;
// }

// E* getList(Node head, int index) {
//	if (index < 1) return NULL;   //���С��0�ǿ϶����Ϸ�������NULL
//	do {
//		head = head->next;  //��Ϊ����ͷ��㣬����ʹ��do-while���
//		if (head == NULL) return NULL;  //����Ѿ����������ǿ϶�Ҳ����
//	} while (--index);  //����index�ͽ���
//	return &head->element;
// }

int findList(Node node, E e)
{ // ��������ֵΪe��Ԫ�ص��±�
	int cnt = 0;
	while (node != NULL)
	{
		if (node->element == e)
			return cnt;

		node = node->next;
		cnt++;
	}
	return -1;
}

int sizeList(Node node)
{
	int cnt = 0; // ��0��ʼ
	while (node->next)
	{ // �����һ��ΪNULL�Ǿ�ֹͣ
		node = node->next;
		cnt++; // ÿ�����һ����+1
	}
	return cnt;
}

void printList(Node node)
{					   // ��ӡ����
	node = node->next; // �׽ڵ㲻��Ҫ��ӡ����
	while (node != NULL)
	{
		printf("%d ", node->element);
		node = node->next;
	}
	puts("");
}

void test01()
{
	ListNode node;
	initList(&node);
	for (int i = 1; i <= 3; i++)
	{
		insertList(&node, i, i);
	}
	printf("�б���Ϊ:%d\n", sizeList(&node));
	printList(&node);
	deleteList(&node, 1);
	printf("�б���Ϊ:%d\n", sizeList(&node));
	printList(&node);
}

void test02()
{
	ListNode node;
	initList(&node);
	for (int i = 1; i <= 3; i++)
	{
		insertList(&node, i, i);
	}
	printList(&node);
	// printf("%d ", *getList(&node, -1));    // ����δ����ʼ���Ŀռ���Σ����Ϊ
	printf("%d ", *getList(&node, 1));
	printf("%d ", *getList(&node, 3));
	// printf("%d ", *getList(&node, 31));    // ����δ����ʼ���Ŀռ���Σ����Ϊ
	puts("");
	printf("%d ", findList(&node, 10));
	printf("%d ", findList(&node, 1));
	printf("%d ", findList(&node, 2));
	printf("%d ", findList(&node, 3));
}

int main()
{
	test01();
	// test02();
	return 0;
}