#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define _maxSize 100

int array[_maxSize];

/*
	���ݶ������ĵ��������� ������һ�������������������Ľṹ
*/

void test01() {
	// ��������ʵ�ֶ�����	
	for (int i = 1;i <= 5;i++) {
		array[i] = i;
	}
	printf("%d\n", array[5]);
	int a = 1;   // ������Ҫ����a��������ҽ���ֵ
	printf("%d\n", array[2 * (2 * a) + 1]);
}



typedef struct TreeNode {
	int e;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*node;		// ʹ�û�������Ķ���������Ҫ�ȴ�����Ӧ����

void test02() {
	// ��������ʵ�ֶ�����
	TreeNode* A = (TreeNode*)malloc(sizeof(struct TreeNode));
	node B = (node)malloc(sizeof(TreeNode));
	node C = (node)malloc(sizeof(TreeNode));
	node D = (node)malloc(sizeof(TreeNode));
	node E = (node)malloc(sizeof(TreeNode));
	A->e = 1,B->e = 2, C->e = 3, D->e = 4, E->e = 5;

	A->left = B, A->right = C;
	B->left = D, B->right = E;
	C->left = NULL, C->right = NULL;
	D->left = D->right = NULL;
	E->left = E->right = NULL;

	printf("%d\n", E->e);
	printf("%d", A->left->right->e);
}

int main() {
	test01();
	test02();
	return 0;
}
