#include<stdio.h>
//#include<stdlib.h>
#define MaxSize 5     //静态链表大小
typedef struct node {           //静态链表结点
	int data;
	int next;
} SNode;
typedef struct {                    //静态链表
	SNode Nodes[MaxSize];
	int newptr;	   //当前可分配空间首地址
} SLinkList;
void InitList(SLinkList *SL) {
	int i;
	(*SL).Nodes[0].next = 1;
	(*SL).newptr = 1;   //当前可分配空间从 1 开始
						//建立带表头结点的空链表
	for (i = 1; i < MaxSize - 1; i++) {
		(*SL).Nodes[i].next = i + 1; //构成空闲链接表
		(*SL).Nodes[i].data = i + 100;//输入数据
	}
	(*SL).Nodes[MaxSize - 1].next = 0; //链表收尾
}

int main()
{
	SLinkList list;
	InitList(&list);
	int p = list.Nodes[0].next;
	while (list.Nodes[p].next != 0) {
		printf("%d\n", list.Nodes[p].data);
		p = list.Nodes[p].next;
	}
	return 0;
}