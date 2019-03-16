#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	int score;
	struct student *next;
}LinkList;
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
void insert(LinkList *list, int n) {//增加链表
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in = (LinkList*)malloc(sizeof(LinkList));
		puts("输入要插入的值");
		scanf("%d", &in->score);
		in->next = t->next;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
		t->next = in;//填充t节点的指针域，把t的指针域重新指向in
	}
	else {
		puts("节点不存在");
	}
}
int main()
{
	LinkList *head = creat(5);
	insert(head, 2);
	head = head->next;
	while (head != NULL) {
		printf("%3d", head->score);
		head = head->next;
	}
	return 0;
}