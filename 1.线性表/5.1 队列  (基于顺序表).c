#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int E;
typedef struct Queue {
    E* array;
    int capacity;
    int front, rear;
}Queue, *ArrayQueue;

bool initQueue(ArrayQueue queue) {
    queue->capacity = 20;
    queue->front = queue->rear = -1;
    queue->array = (E*)malloc(sizeof(E) * 20);
    if (queue->array == NULL) return false;
    return true;
}

bool push(ArrayQueue queue, E e) {
    if ((queue->rear + 1) % queue->capacity == queue->front) return false;
    int temp = (queue->rear + 1) % queue->capacity;     // ����Ϊn�Ķ��У���Ԫ���±�ķ�Χ��[0,n-1]
    queue->array[temp] = e;
    queue->rear = temp;
    return true;
}

bool isEmpty(ArrayQueue queue) {
    return queue->front == queue->rear;
}

E pop(ArrayQueue queue) {
    if (isEmpty(queue)) return -1;
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

int sizeQueue(Queue queue) {
    return (queue.rear - queue.front + queue.capacity) % queue.capacity;
}

void printQueue(Queue queue) {
    for (int i = (queue.front + 1) % queue.capacity; i != (queue.rear + 1) % queue.capacity; i = (i + 1) % queue.capacity) {
        printf("%d ", queue.array[i]);
    }
    puts("");
}

void test01() {
    Queue queue;
    initQueue(&queue);
    isEmpty(&queue)? printf("������ʱΪ��\n") : printf("���в�Ϊ��\n");
    puts("");
    for (int i = 0; i < 10; i++) {
        push(&queue, (i + 1) * 10);
    }
    isEmpty(&queue)? printf("������ʱΪ��\n") : printf("���в�Ϊ��\n");
    printf("�����е�Ԫ�ظ���Ϊ��%d\n", sizeQueue(queue));
    printQueue(queue);
    puts("");
    while (!isEmpty(&queue)) {
        printf("Ԫ��%d����\n", pop(&queue));
    }
    isEmpty(&queue)? printf("������ʱΪ��\n") : printf("���в�Ϊ��\n");
    printf("�����е�Ԫ�ظ���Ϊ��%d\n", sizeQueue(queue));
    printQueue(queue);
}
void test02() {
    Queue queue;
    initQueue(&queue);
    isEmpty(&queue) ? printf("������ʱΪ��\n") : printf("���в�Ϊ��\n");
    puts("");
    for (int i = 0; i < 20; i++) {              // Ϊ������ `�ӿ�` �� `����`,��һ�����Ԫ�صĿռ䱻�˷��� 
        push(&queue, (i + 1) * 10);
    }
    isEmpty(&queue) ? printf("������ʱΪ��\n") : printf("���в�Ϊ��\n");
    printf("�����е�Ԫ�ظ���Ϊ��%d\n", sizeQueue(queue));
    printQueue(queue);
}
int main() {
   test01();
   // test02();
    return 0;
}