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
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count - 1;
}
int GetData(LinkList *list, int n) {//提取第i个元素的值
	list = list->next;//第一个节点为空节点
	int i = 1;
	if (n >= 1 && n <= Length(list)) {
		while (i != n) {
			i++;
			list = list->next;
		}
		return list->score;
	}
	else
		puts("参数不合理！");
}
int main()
{
	LinkList *head;
	head = creat(5);
	printf("%d", GetData(head, 3));
	return 0;
}