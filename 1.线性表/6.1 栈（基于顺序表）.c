#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// ����˳���ʵ��һ��ջ

typedef int E;

typedef struct
{
	E *array;
	int capacity;
	int top; // top��ֵ��ʾ��ǰ��ŵ��ڼ���λ���˸������±���һ�£���Χ��[0,capacity-1]
} Stack, *ArrayStack;

bool initStack(ArrayStack stack)
{
	stack->array = (E *)malloc(sizeof(E) * 10);
	if (stack->array == NULL)
		return false;
	stack->capacity = 10;
	stack->top = -1;
	return true;
}

bool push(ArrayStack stack, E e)
{
	if (stack->top + 1 == stack->capacity)
		return false;
	stack->array[++stack->top] = e;
	return true;
}

int pop(ArrayStack stack)
{
	if (stack->top < 0)
		return;
	return stack->array[stack->top--];
}

void printArray(ArrayStack stack)
{
	for (int i = 0; i < stack->top + 1; i++)
	{
		printf("%d ", stack->array[i]);
	}
	puts("");
}

int sizeArray(ArrayStack stack)
{
	return stack->top + 1;
}

int main()
{
	Stack stack;
	initStack(&stack);
	for (int i = 0; i < 10; i++)
	{
		push(&stack, i + 1);
	}
	printf("ջ����%d��Ԫ��\n", sizeArray(&stack));
	printArray(&stack);
	for (int i = 0; i < 10; i++)
		printf("����Ԫ�أ�%d\n", pop(&stack));
	puts("");
	printf("����Ԫ�غ�ջ����%d��Ԫ��\n", sizeArray(&stack));
	return 0;
}