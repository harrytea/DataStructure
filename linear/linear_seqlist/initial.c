#include<stdio.h>
#include<stdlib.h>
#define ListSize 100//最大允许长度
#define Listincrement 10
typedef struct {
	int *data;//储存空间基址
	int length;//当前元素个数
	int listsize;//当前分配的存储容量
}Seqlist;//顺序表类型定义
void InitList(Seqlist &list) {
	list.data = (int*)malloc(ListSize * sizeof(int));
	if (list.data == NULL) {
		printf("存储分配失败!\n");
		exit(1);
	}
	list.length = 0;
	list.listsize = ListSize;
}//顺序表初始化，形参为引用的形式
void creatlist(Seqlist &list) {
	puts("input the length is");
	scanf("%d", &list.length);
	printf("input %d data\n", list.length);
	for (int i = 0; i < list.length; i++) 
		scanf("%d", &(list.data[i]));
}//顺序表的建立，赋值
int main()
{
	Seqlist head;
	InitList(head);
	creatlist(head);
	for (int i = 0; i < head.length; i++) {
		printf("%3d", head.data[i]);
	}//将线性表打印输出
	//printf("%d",head.data[2]);//输出线性表的第二个元素
	return 0;
}