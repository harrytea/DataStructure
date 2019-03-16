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
int main()
{
	LinkList *head = creat(5);
	change(head);
	head = head->next;
	while (head != NULL) {
		printf("%3d", head->score);
		head = head->next;
	}
	return 0;
}