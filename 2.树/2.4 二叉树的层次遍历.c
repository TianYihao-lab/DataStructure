#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// 二叉树的层序遍历是借助队列实现的

typedef char E1;
typedef struct TreeNode {
	E1 e;
	struct TreeNode* left;
	struct TreeNode* right;
}Node, * node;

node A, B, C, D, E, F;

void creat();


void test01(){
	
}

int main(){
	test01();
	return 0;
}


void creat() {
	A = (Node*)malloc(sizeof(struct TreeNode));
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
