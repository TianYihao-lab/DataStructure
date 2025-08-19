#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
������������������Է�Ϊ
	1�������ݹ�
	2��ֱ��ʵ�֣�����ջ��
*/

typedef char E1;
typedef struct TreeNode
{
	E1 e;
	struct TreeNode *left;
	struct TreeNode *right;
} Node, *node;

node A, B, C, D, E, F;

void creat()
{
	A = (Node *)malloc(sizeof(struct TreeNode));
	B = (node)malloc(sizeof(Node));
	C = (node)malloc(sizeof(Node));
	D = (node)malloc(sizeof(Node));
	E = (node)malloc(sizeof(Node));
	F = (node)malloc(sizeof(Node));
	A->e = 'A', B->e = 'B', C->e = 'C', D->e = 'D', E->e = 'E', F->e = 'F';

	A->left = B, A->right = C;
	B->left = D, B->right = E;
	C->left = NULL, C->right = F;
	D->left = D->right = NULL;
	E->left = E->right = NULL;
	F->left = F->right = NULL;
}

void preOrder(node root)
{ // ���õݹ�ʵ���������
	if (root == NULL)
		return;
	printf("%c", root->e);
	preOrder(root->left);
	preOrder(root->right);
}

void test01()
{
	printf("���������������·��:");
	preOrder(A);
}

// ע�͵��Ĳ����ǻ���ջ��ʵ�ֵ��������

// typedef struct Stack{
//	node element;
//	struct Stack* next;
// }SNode,*Snode;
//
//// ������Ҫ�ֶ�ʵ��һ��ջ
// void initStack(Snode node);
// bool push(Snode node,int e);
// node pop(Snode node);
// void printNode(SNode node);
// bool isEmpty(SNode node);
//
// void preorder(node root){  // ����ջֱ��ʵ���������
//	SNode treeStack;
//	initStack(&treeStack);
//	while (root || !isEmpty(treeStack)){   //����������ֻ�е�ջ�ղ��ҽڵ�ΪNULLʱ����ֹѭ��
//         while (root) {    //�������ǵ�˼·���Ȳ��ϱ�����������ֱ��û��Ϊֹ
//             push(&treeStack, root);   //;��ÿ����һ����㣬�ͽ���㶪��ջ��
//             printf("%c", root->e);   //Ȼ���ӡ��ǰ���Ԫ��ֵ
//             root = root->left;  //����������һ�����ӽ��
//         }
//         root = pop(&treeStack);  //����ǰ���ѭ������ȷ������ȫ�������ˣ����ž�����������
//         root = root->right;  //�õ��Һ��ӣ�������Һ��ӣ���һ�ֻ��ظ�����Ĳ��裻���û���Һ�����ô�����root�ͱ���ֵΪNULL�ˣ���һ�ֿ�ʼ��ֱ�����������while��������ջ��һ���������������
//     }
// }
// void test02(){
//	preorder(A);
// }

// ���Բ���
int main()
{
	creat();
	test01();
	printf("\n");
	// test02();
	return 0;
}

// void initStack(Snode node) {
//	node->next = NULL;
// }
// bool push(Snode node, int e) {
//	Snode newNode = (Snode)malloc(sizeof(SNode));
//	if (newNode == NULL)return false;
//	newNode->element = e;
//	newNode->next = node->next;
//	node->next = newNode;
//	return true;
// }
// node pop(Snode _node) {
//	Snode top = _node->next;
//	_node->next = top->next;
//	node e = top->element;
//	free(top);
//	return e;
// }
// void printNode(SNode node) {
//	while (node.next != NULL) {
//		printf("->%c",node.next->element);
//	}
// }
// bool isEmpty(SNode node) {
//	return node.next != NULL;
// }
