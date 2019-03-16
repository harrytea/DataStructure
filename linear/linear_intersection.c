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
int Length(LinkList *list) {//求表的长度
	int count = 0;
	list = list->next;
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count;
}
int Find(LinkList *list,int x) {//按值查找:找x在节点的位置
	int i = 1;
	LinkList *note = list;
	list = list->next;
	while (i <= Length(note) && list->score != x) {
		i++;
		list = list->next;
	}
	if (i <= Length(note))
		return i;
	else
		return -1;
}
int GetData(LinkList *list, int n) {//提取第n个元素的值
	int i = 1;
	LinkList *note = list;
	list = list->next;
	if (n >= 1 && n <= Length(note)) {
		while (i != n) {
			i++;
			list = list->next;
		}
		return list->score;
	}
	else
		puts("参数不合理!");
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
void Intersection(LinkList *A, LinkList *B) {
	int la, lb,x,k,i=1;
	la = Length(A);
	lb = Length(B);
	while (i <= la) {
		x = GetData(A, i);
		k = Find(B, x);
		if (k == -1) {
			delet(A, i);
			la--;
		}
		else
			i++;
	}
}
int main()
{
	LinkList *note1,*note2;
	note1 = creat(1);
	note2 = creat(2);
	Intersection(note1, note2);
	note1 = note1->next;
	if (note1 != NULL) {
		while (note1 != NULL) {
			printf("%2d", note1->score);
			note1 = note1->next;
		}
	}
	return 0;
}