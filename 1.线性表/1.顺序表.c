#include<stdio.h>
#include<stdlib.h>

typedef int E;

struct List {
	//E arry[10];
	E* array;
	int capacity;    // 顺序表的最大长度
	int size;        // 当前表内已经存放了几个数
};
typedef struct List List,*ArryList;

void initList(ArryList list) {  // 初始化操作
	list->array = (E*)malloc(sizeof(E) * 10);
	if (list->array == NULL) {
		printf("内存申请失败!");
		return;
	}
	list->capacity = 10;
	list->size = 0;
}

void insertList(ArryList list, E element, int index) {  // 在数组list的第index个位置上插入一个元素element
	// 碰到插入位置不对
	if (index < 1 || index > list->size + 1)return; 

	// 碰到顺序表空间不够用
	if (list->size == list->capacity) {
		int newCapacity = list->capacity * 2; // 申请原来空间大小两倍的新空间来存放老数据和新数据
		E* newArray = realloc(list->array, newCapacity * sizeof(E));
		if (newArray == NULL)return;
		list->array = newArray;
		list->capacity = newCapacity;
	}

	for (int i = list->size;i > index - 1;i--) {
		list->array[i] = list->array[i - 1];
	}
	list->array[index - 1] = element;
	list->size++;
}

void deleteList(ArryList list, int index) {        // 删除指定位置上的元素
	if (index < 1 || index >= list->size)return;

	for (int i = index - 1 ;i < list->size;i++) {
		list->array[i] = list->array[i + 1];
	}
	list->size--;
}
void printList(ArryList list) {  // 打印顺序表
	for (int i = 0;i < list->size;i++) {
		printf("%d ", list->array[i]);
	}puts("");
}
E* getList(ArryList list, int index) {  // 获得指定位置上的元素
	if (index >list->size || index < 1)return NULL;  // 这里index的范围是[1,list->size]

	return &list->array[index - 1];  // 注意顺序表中元素的下表和数组中元素的下表不完全相同，总保持顺序表元素的下表比数组中存放的大1
}
 
int findList(ArryList list,E e) {   // 寻找元素e在数组中的位序
	for (int i = 0;i < list->size;i++) {
		if (list->array[i] == e)return i+1;  // i是e在数组中存放的位置
	}
	return -1;  // 如果返回-1，说明元素e不在顺序表内
}

int sizeList(ArryList list) {  // 获得顺序表的长度
	return list->size;
}

void test01() {
	List list;
	initList(&list);
	insertList(&list, 666, 1);
	printList(&list);
	insertList(&list, 667, 1);
	printList(&list);
	insertList(&list, 668, 2);
	printList(&list);
}
void test02() {
	List list;
	initList(&list);
	for (int i = 0;i < 30;i++) {
		insertList(&list, i * 10, i + 1);
	}
	//deleteList(&list, 10);
	printList(&list), printf("%d\n", list.capacity);
	deleteList(&list, 10);
	printList(&list);
	deleteList(&list, 1);
	deleteList(&list, 1);
	printList(&list);
	printf("%d\n", *getList(&list, 2));
	//printf("%d", *getList(&list, -1)); // err
	printf("%d\n", findList(&list, 30));
}
int main() {
	test01();
	//test02();
	
	return 0;
}
