//单链表(非随机存取)链表无表头结点
/*
1.第一个结点前，结点之间，最后一个结点之后插入
2.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {//链表结点
	int data;//结点数据域
	struct node* next;//结点链域
}ListNode;
typedef ListNode* LinkList;
LinkList first;//链表头指针
int Insert(LinkList &first, int x, int i) {
	ListNode* p = first;  
	int k = 0;
	while (p != NULL && k < i - 1){
		p = p->next; 
		k++;
	}//找第 i-1个结点 
	if (p == NULL && first != NULL) {
		printf("无效的插入位置!\n");//终止插入
		return 0;
	}//first不为空表，但是p指向了NULL(即表尾)
	ListNode* newnode = (ListNode *)malloc(sizeof(ListNode)); //创建新结点
	newnode->data = x;
	if (first == NULL || i == 1) { //插入空表或非空表第一个结点之前
		newnode->next = first;//新结点成为第一个结点
		if (first == NULL)
			last = newnode;//若是空表，表尾指针指向新结点
		first = newnode;
	}
	else {//插在表中间或末尾
		newnode->next = p->next;
		if (p->next == NULL)
			last = newnode;
		p->next = newnode;
	}
	return 1;
}//在链表第i个结点前插入新元素x
int Delete(LinkList& first, int i) {
	//在链表中删除第 i 个结点
	ListNode *p, *q;
	if (i == 0)  //删除表中第 1 个结点
	{
		q = first;  first = first->next;
	}
	else {
		p = first;  int k = 0;
		while (p != NULL && k < i - 1)
		{
			p = p->next; k++;
		} //找第 i-1个结点
		if (p == NULL || p->next == NULL) {//找不到第
			i - 1个结点
				printf(“无效的删除位置!\n”);
			return 0;
		}
		else {//删除中间结点或尾结点元素
			q = p->next;
			p->next = q->next;
		}
		if (q == last)  last = p;//删除表尾结点
		k = q->data; free(q); return k; //取出被删结点数据并释放q
	}
}
int main()
{

}