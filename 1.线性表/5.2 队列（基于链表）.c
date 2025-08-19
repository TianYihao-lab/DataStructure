#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int E;
typedef struct LNode {
	E elment;
	struct LNode* next;
}LNode,*Node;
typedef struct Queue {
	Node front, rear;
}Queue,*LinkQueue;

bool initQueue(LinkQueue queue) {
	Node node = (Node)malloc(sizeof(LNode));
	if (node == NULL)return false;
	node->next = NULL;
	queue->front = queue->rear = node;
	return true;
}
bool push(LinkQueue queue,E e) {
	Node newnode = (Node)malloc(sizeof(LNode));
	if (newnode == NULL)return false;
	newnode->elment = e;
	newnode->next = NULL;
	queue->rear->next = newnode;
	queue->rear = newnode;
	return true;
}
E pop(LinkQueue queue) {
	E e = queue->front->next->elment;
	Node node = queue->front->next;
	queue->front->next = queue->front->next->next;  //ֱ����ͷ���ָ�����¸����
	if (queue->rear == node) queue->rear = queue->front;   //�����β���Ǵ����ӵĽ�㣬��ô��β�ص�����λ����
	free(node);   //�ͷ��ڴ�
	return e;
}
bool isEmpty(Queue queue) {
	return queue.front == queue.rear;
}
int sizeQueue(Queue queue) {
	Node q = queue.front;
	int cnt = 0;
	while (q != queue.rear) {
		cnt++;
		q = q->next;
	}
	return cnt;
}
void printQueue(Queue* queue) {
	if (queue->front == queue->rear) {
		printf("<<< >>>");
		return;
	}
	printf("<<< ");
	Node node = queue->front->next;
	while (true) {    //ע�ⲻ��ֱ���пգ���Ϊǰ������û���ǣ�Ҳ��û���½��next�趨ΪNULL
		printf("%d ", node->elment);
		if (node == queue->rear) break;    //���Ѿ���ӡ���һ��Ԫ�غ��ٽ���
		else node = node->next;
	}
	printf(">>>\n");
}
void test01() {
	Queue queue;
	initQueue(&queue);
	for (int i = 0;i < 10;i++) {
		push(&queue, (i + 1) * 10);
	}
	printf("�����е�Ԫ�ظ�����%d\n", sizeQueue(queue));
	printQueue(&queue);
	while (!isEmpty(queue)) {
		printf("Ԫ��%d����\n", pop(&queue));
	}
	printf("�����е�Ԫ�ظ�����%d\n", sizeQueue(queue));
	printQueue(&queue);
}

int main() {
	test01();
	return 0;
}