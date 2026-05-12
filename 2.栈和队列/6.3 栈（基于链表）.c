#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

typedef struct LNode
{
	int element;
	struct LNode *next;
} LNode, *Node;

void initStack(Node node)
{
	node->next = NULL;
}
bool push(Node node, E e)
{
	Node newnode = (LNode *)malloc(sizeof(LNode));
	if (newnode == NULL)
		return false;
	newnode->element = e;
	newnode->next = node->next;
	node->next = newnode; // ���ǰ��½ڵ����ͷ���ĺ���
	return true;
}
int pop(Node node)
{
	if (node->next == NULL)
		return;
	int temp = node->next->element;
	Node tem = node->next;
	node->next = node->next->next;
	free(tem);
	return temp;
}
bool isEmpty(Node node)
{
	if (node->next == NULL)
		return true;
	return false;
}
int sizeStack(Node node)
{
	int cnt = 0;
	while (node->next != NULL)
	{
		cnt++;
		node = node->next;
	}
	return cnt;
}
void printStack(Node node)
{
	node = node->next; // ͷ�ڵ㲻��ӡ
	while (node != NULL)
	{
		printf("%d ", node->element);
		node = node->next;
	}
	puts("");
}

void test01()
{
	LNode node;
	initStack(&node);
	for (int i = 0; i < 3; i++)
	{
		push(&node, i + 1);
	}
	printf("ջ�е�Ԫ�ظ���Ϊ��%d\n", sizeStack(&node));
	printStack(&node);
	printf("Ԫ��%d��ջ\n", pop(&node));
	printf("Ԫ��%d��ջ\n", pop(&node));
	printf("ջ�е�Ԫ�ظ���Ϊ��%d\n", sizeStack(&node));
	printStack(&node);
}
void test02()
{
	LNode node;
	initStack(&node);
	for (int i = 0; i < 3; i++)
	{
		push(&node, i + 1);
	}
	printf("ջ�е�Ԫ�ظ���Ϊ��%d\n", sizeStack(&node));
	printStack(&node);
	while (!isEmpty(&node))
	{
		printf("Ԫ��%d��ջ\n", pop(&node));
	}
	printf("ջ�е�Ԫ�ظ���Ϊ��%d\n", sizeStack(&node));
	printStack(&node);
}
int main()
{
	// test01();
	test02();
	return 0;
}