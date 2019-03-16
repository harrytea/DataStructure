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
int Length(LinkList *list) {//求表的长度
	int count = 0;
	list = list->next;
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count;
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
int main()
{
	LinkList *head;
	head = creat(5);
	printf("%d", GetData(head, 5));
	return 0;
}