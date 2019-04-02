//linked list---单链表(非随机存取)
//每个元素由结点（Node）构成，包括数据域和指针域
//有表头结点
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Linknode;
Linknode *first;//链表头指针
Linknode *creat(int n) {//链表的初始化
	Linknode *head, *node, *end;//定义头节点，普通节点，尾部节点
	head = (Linknode*)malloc(sizeof(Linknode));//分配地址
	end = head;              //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = (Linknode*)malloc(sizeof(Linknode));
		scanf("%d", &node->data);
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	return head;
}
int main()
{
	Linknode *head = creat(5);
	first = head;
	head = head->next;
	Linknode *node = (Linknode*)malloc(sizeof(Linknode));
	node->next = head->next;
	first->next->next = node;
	node->data = 10000;//在第二个元素之前插入一个元素
	while (head != NULL) {
		printf("%3d\n", head->data);
		head = head->next;
	}
	return 0;
}