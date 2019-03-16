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
int Find(LinkList *list, int length, int x) {//按值查找:找x在节点的位置
	int i = 0;
	while (i < length&&list->score != x) {
		i++;
		list = list->next;
	}
	if (i < length)
		return i;
	else
		return -1;
}
int Prior(LinkList *list, int length, int x) {//寻找x的前驱
	int pos = Find(list, length, x);
	list = list->next;//从空节点指向第一个节点
	if (pos > 1 && pos <= length) {
		int i = 1;
		while (i != pos - 1) {
			i++;
			list = list->next;
		}
		return list->score;//输出x节点的前驱
	}
	else
		return -1;
}
int main()
{
	LinkList *head;
	head = creat(5);
	printf("%d", Prior(head, 5, 3));
	return 0;
}