//双向循环链表double_circle_linklist
/*
1.初始化first空函数Createdlinklist
2.长度函数Length
3.直接定位指针i函数Locate
4.插入函数Insert
5。删除函数Remove
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct dnode {//双向循环链表的定义
    int data;                          
    struct dnode * prior, * next;     
} Dlinknode;
typedef Dlinknode* Dfirst;   
Dfirst first = (Dlinknode *)malloc(sizeof(Dlinknode));
void Createdlinklist(Dfirst first) {//建立空的双向循环链表
	if (first == NULL)
	{
		printf("存储分配错!\n"); 
		exit(1);
	}
	first->prior = first->next = first;//表头结点的链指针指向自己
}
int Length(Dlinknode* first) {//计算带表头结点的双向循环链表的长度
	Dlinknode *p = first->next;
	int count = 0;
	while (p != first)
	{
		p = p->next;  
		count++;
	}
	return count;
}
Dlinknode* Locate(Dlinknode* first,int i) {
	Dlinknode* p = first;
	int k = 0;
	while (k < i) {
		p = p->next;
		k++;
	}
	return p;
}
int Insert(Dlinknode* first, int i, int x) {//双向链表的插入
	if (i >= 1 && i <= Length(first) + 1) {
		Dlinknode *p = Locate(first, i - 1);//指针定位于插入位置
		Dlinknode *q = (Dlinknode *)malloc(sizeof(Dlinknode));//分配结点
		q->data = x;
		q->prior = p;
		q->next = p->next;
		p->next = q;
		q->next->prior = q;
		return 1;
	}
	else {
		printf("无效的插入位置！");
		return 0;
	}
}
int Remove(Dlinknode* first, int i){//双向链表的删除
	if (i >= 1 && i <= Length(first)) {
		Dlinknode *p = Locate(first, i);//指针定位于删除结点位置
		p->next->prior = p->prior;
		p->prior->next = p->next;//删除结点 p
		free(p);	//释放
		return 1;
	}
	else
		return 0;
}
int main()
{
	Createdlinklist(first);
	Insert(first, 1, 1);
	Insert(first, 2, 2);
	Insert(first, 3, 3);
	Insert(first, 4, 4);
	Remove(first, 3);
	printf("%d", Length(first));
	return 0;
}
