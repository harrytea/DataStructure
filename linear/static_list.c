//static_linklist（静态链表）
//带有表头结点
/*
1.初始化为空的静态链表Initlist
2.查找给定值的节点并且返回位置Find
3.查找第i个节点并且返回位置Locate
4.在静态链表的第i个位置插入一个元素Insert
5.在静态链表的第i个位置删除一个元素Remove
*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100       //静态链表大小
typedef struct node {     //静态链表结点
    int data;
    int next;
} SNode;
typedef struct {          //静态链表
    SNode Nodes[MaxSize];
    int newptr;	          //当前可分配空间首地址
} Slinklist;
void Initlist(Slinklist *list) {
	int i;
	(*list).Nodes[0].next = 1;
	(*list).newptr = 1;   //当前可分配空间从1开始,建立带表头结点的空链表
	for (i = 1; i < MaxSize - 1; i++)
		(*list).Nodes[i].next = i + 1;   //构成空闲链接表
	(*list).Nodes[MaxSize - 1].next = -1; //链表收尾
}
int Find (Slinklist list, int x ) {//在静态链表中查找具有给定值的结点
     int p = list.Nodes[0].next;   //指针 p 指向链表第一个结点
	 while ( p != -1 )             //逐个查找有给定值的结点
         if ( list.Nodes[p].data != x)
             p = list.Nodes[p].next;
         else 
			 break;
	return p;
}
int Locate(Slinklist list, int i) {//在链表中查找第i个结点
	int j, p;
	if (i < 0) 
		return -1;//参数不合理
	j = 1; 
	p = list.Nodes[0].next;
	while (p != -1 && j < i) {//循环查找第 i 号结点
		p = list.Nodes[p].next;
		j++;
	}
	if (i == 0) return 0;
	return p;
}
int Insert(Slinklist *list, int i, int x) {//在静态链表的第i个结点处插入一个新结点
	int p, q;
	p = Locate(*list, i - 1);
	if (p == -1)
		return 0;               //找不到结点
	q = (*list).newptr;         //分配结点
	(*list).newptr = (*list).Nodes[(*list).newptr].next;
	(*list).Nodes[q].data = x;
	(*list).Nodes[q].next = (*list).Nodes[p].next;
	(*list).Nodes[p].next = q;           //插入
	return 1;
}
int Remove(Slinklist *list, int i) {//在静态链表中释放第i个结点
	int p = Locate(*list, i - 1);
	if (p == -1) return 0;       //找不到结点
	int q = (*list).Nodes[p].next;    //第 i 号结点
	(*list).Nodes[p].next = (*list).Nodes[q].next;
	(*list).Nodes[q].next = (*list).newptr;    //释放
	(*list).newptr = q;
	return 1;
}
int main()
{
	Slinklist list;
	Initlist(&list);
	int k = 0;
	for (int i = 1; i <= 10; i++) {
		list.Nodes[list.newptr].data = 100 + i;
		list.newptr = list.Nodes[i].next;
	}
	Insert(&list, 8, 888);
	Remove(&list, 9);
}