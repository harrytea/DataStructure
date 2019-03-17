#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	int score;
	struct student *next;
}LinkList;//定义
/*
typedef struct student LinkList;
 struct student{
 int score;
 LinkList *next;
 };
*/
LinkList *creat(int n) {//链表的初始化
	LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点
	head = (LinkList*)malloc(sizeof(LinkList));//分配地址
	end = head;              //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->score);
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	return head;
}
int Find(LinkList *list, int length, int x) {//按值查找:找x在节点的位置
	int i = 1;
	list = list->next;
	while (i <= length&&list->score != x) {
		i++;
		list = list->next;
	}
	if (i <= length)
		return i;
	else
		return -1;
}
int Length(LinkList *list) {//求表的长度
	int count = 0;
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count-1;//剔除头指针(空节点)
}
int GetData(LinkList *list, int n) {//提取第n个元素的值
	int i=1;
	list = list->next;
	if (n >= 1 && n <= Length(list)+1) {
		while (i != n) {
			i++;
			list = list->next;
		}
		return list->score;
	}
	else
		puts("参数不合理!");
}
void change(LinkList *list) {//修改链表节点值，n为第n个节点
	LinkList *t = list;
	int n;
	puts("请输入你要修改的节点位置");
	scanf("%d", &n);
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		puts("输入要修改的值");
		scanf("%d", &t->score);
	}
	else {
		puts("节点不存在");
	}
}
void delet(LinkList *list, int n) {//删除链表
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in->next = t->next;
		free(t);
	}
	else {
		puts("节点不存在");
	}
}
void insert(LinkList *list, int n, int m) {//增加链表(n*后*位置，m值）
	LinkList *t = list, *in;
	int i = 1;
	t = t->next;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in = (LinkList*)malloc(sizeof(LinkList));
		in->score = m;
		in->next = t->next;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
		t->next = in;//填充t节点的指针域，把t的指针域重新指向in
	}
	else {
		puts("节点不存在");
	}
}
int Next(LinkList *list, int length, int x) {//寻找x的后继
	int pos=Find(list,length,x);
	list = list->next;//从空节点指向第一个节点
	if (pos >= 1 && pos < length) {
		int i = 1;
		while (i < pos) {
			i++;
			list = list->next;
		}
		return list->next->score;//输出x节点的后继
	}
	else
		return -1;
}
int Prior(LinkList *list, int length, int x) {//寻找x的前驱
	int pos = Find(list, length, x);
	list = list->next;//从空节点指向第一个节点
	if (pos > 1 && pos <= length) {
		int i = 1;
		while (i != pos-1) {
			i++;
			list = list->next;
		}
		return list->score;//输出x节点的前驱
	}
	else
		return -1;
}
LinkList* Union(LinkList *A, LinkList *B) {
	int la, lb, x, k;
	LinkList *head=A;
	lb = Length(B);
	for (int i = 1; i <= lb; i++) {
		x = GetData(B, i);
		la = Length(A);
		k = Find(A, la,x);
		if (k == -1) {
			insert(A, la, x);
		}
	}
	return head;
}//取A、B的并集并返回头指针
int main()
{
	LinkList *note1,*note2;
	note1 = creat(5);
	note2 = creat(6);
	LinkList *above = Union(note1, note2);
	above = above->next;
	while (above != NULL) {
		printf("%2d", above->score);
		above = above->next;
	}
	return 0;
}