/*初始化相对于第一个版本采用了指针，虽然形式不同
但是最终的结果是一样的*/
/*
顺序线性表的基本操作：
1.建立空表
2.对顺序表进行赋值操作
3.按值查找位置
4.判断元素是否在表中（返回0或者1）
5.求表的长度
6.取表中第i个元素的值
7.寻找x的前驱/后继
8.在第i个位置插入元素
9.删除第i个元素
10.求链表的并/交
*/
#include<stdio.h>
#include<stdlib.h>
#define ListSize 100//最大允许长度
#define Listincrement 10
typedef struct {
	int *data;//储存空间基址
	int length;//当前元素个数
	int listsize;//当前分配的存储容量
}Seqlist;//顺序表类型定义
void InitList(Seqlist *list) {
	list->data = (int*)malloc(ListSize * sizeof(int));
	if (list->data == NULL) {
		printf("存储分配失败!\n");
		exit(1);//程序异常运行导致退出程序，退出前可有提示信息(操作系统提供的函数库)
	}
	list->length = 0;
	list->listsize = ListSize;
}//建立顺序表为空
void creatlist(Seqlist *list) {
	puts("input the length is");
	scanf("%d", &list->length);
	printf("input %d data\n", list->length);
	for (int i = 0; i < list->length; i++)
		scanf("%d", &(list->data[i]));
}//顺序表的建立，赋值
int Find(Seqlist *list, int x) {
	int i = 0;
	while (i < list->length&&list->data[i] != x)
		i++;
	if (i < list->length)
		return i;//计数从0开始
	else 
		return -1;
}//按值查找：找x在表中的位置，若查找成功，返回表项的位置，否则返回-1
int Isin(Seqlist *list, int x) {
	int i = 0;
	int found = 0;
	while (i < list->length && !found)
		if (list->data[i] != x)
			i++;
		else
			found = 1;
	return found;
}//判断x是否在表中，若在返回1，否则返回0
int Length(Seqlist *list) {
	return list->length;
}//求表的长度
int GetData(Seqlist *list, int i) {
	if (i >= 1 && i <= list->length)
		return list->data[i-1];
	else printf("参数i不合理!\n");
}//获取表中的第i个元素的值
int Next(Seqlist *list, int x) {
	int i = Find(list,x);
	if (i >= 0 && i < list->length - 1)
		return i + 1;
	else
		return -1;
}//按值查找：寻找x的后继
int Prior(Seqlist *list, int x) {
	int i = Find(list, x);
	if (i > 0 && i <= list->length - 1)
		return i - 1;
	else
		return -1;
}//按值查找，寻找x的前驱
int Insert(Seqlist *list, int x, int i) {
	int *q, *p, *newbase;
	if (i<1 || i>list->length + 1)
		return 0;//如果插入的位置不再表中结束
	if (list->length >= list->listsize) {
		newbase = (int *)realloc(list->data, (ListSize + Listincrement) * sizeof(int));
		if (newbase == NULL) {
			printf("存储分配失败!\n");
			exit(1);
		}
		list->data = newbase;
		list->listsize += Listincrement;
	}//分配空间
	q = &(list->data[i - 1]);
	for (p = &(list->data[list->length - 1]); p >= q; --p)
		*(p + 1) = *p;//位置i之后的元素后移一位
	*q = x;//插入元素x
	++list->length;//长度+1
	return 1;
}//插入，在表中的第i个位置插入新元素，计数从1起
int Delete(Seqlist *list, int x) {
	int j;
	int i = Find(list, x);//在表中查找x，计数从0起
	if (i >= 0) {
		list->length--;
		for (j = i; j < list->length; j++)
			list->data[j] = list->data[j + 1];
		return 1;//成功删除
	}
	return 0;//删除失败
}
void Union(Seqlist *A, Seqlist *B) {
	int n, m, x, k;
	n = Length(A);
	m = Length(B);
	for (int i = 0; i <= m; i++) {
		x = GetData(B, i);//B中取一元素
		k = Find(A, x);//A中查找
		if (k == -1) {
			Insert(A, x, n);
			n++;//若未找到则插入
		}
	}
}//求两个链表的并集
void Intersection(Seqlist *A, Seqlist *B) {
	int n, m, x, k;
	n = Length(A);
	m = Length(B);
	int i = 0;
	while (i < n) {
		x = GetData(A, i);//在A中取一个元素
		k = Find(B, x);//在B中查找他
		if (k == -1) {
			Delete(A, i);
			n--;
		}
		else i++;//未找到在A中删除它
	}
}//求两个链表的交集
int main()
{
	Seqlist head;
	InitList(&head);
	creatlist(&head);
	/*for (int i = 0; i < head.length; i++) {
		printf("%3d", head.data[i]);
	}//将线性表打印输出
	 //printf("%d",head.data[2]);//输出线性表的第二个元素
	 */
	int numb = Delete(&head, 3);
	return 0;
}
/*
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
	return 0;
}*/
//引用初始化(c语言中并不存在引用的概念)