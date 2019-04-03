//循环链表circular_linklist
//每个元素由结点（Node）构成，包括数据域和指针域
/*
1.插入函数Insert
2.删除函数Delete
3.长度函数Length
4.清空函数makeEmpty
5.查找函数Find
6.查找位置函数Locate
*/
//有表头结点
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}Linknode;
typedef Linknode* Linklist;
Linklist first = (Linknode *)malloc(sizeof(Linknode));//链表头指针
int Length(Linknode* first) {//求链表的长度
	Linknode *p = first;
	int count = 0;
	while (p->next != first) {  //逐个结点检测
		p = p->next;
		count++;
	}
	return count;
}
int Insert(Linklist &first, int x, int i) {//在链表第i个结点前插入新元素x,当i=length+1时在表尾插入
	Linknode* p = first;
	Linknode* newnode = (Linknode *)malloc(sizeof(Linknode));//创建新结点
	if (i == 1) {//插入空表或非空表第一个结点之前
		newnode->next = first->next;//插入第一个节点之前
		first->next = newnode;
	}
	else if (i <= 0 || i > Length(first)+1)
		return -1;//如果插入的位置比表的长度大
	else {
		int k = 0;
		while (k < i - 1) {
			p = p->next;
			k++;
		}
		newnode->next = p->next;
		p->next = newnode;
	}
	newnode->data = x;
	return 1;
}
int Delete(Linklist& first, int i) {//删除第i个结点
	Linknode *p, *q;
	if (first->next == first) {
		printf("链表为空，无结点需删除");
		return 0;
	}
	else {
		if (i <= 0 || i > Length(first)) {
			printf("输入的结点不存在！");
			return -1;
		}//若删除的结点超出了链表的长度，则返回-1
		else{
			p = first;
			int k = 0;
			while (k < i - 1) {
				p = p->next;
				k++;
			} //找第 i-1个结点
			q = p->next;
			p->next = p->next->next;
			free(q);
			return 1;
		}//删除链表中第i位元素
	}
}
void makeEmpty(Linknode* first) {//删去链表中除表头结点外的所有其它结点
	Linknode *q;
	while (first->next != first) {//当链不空时，循环逐个删去所有结点
		q = first->next;
		first->next = q->next;
		free(q);        //释放 
	}
}
Linknode* Find(Linknode* first, int value) {//在链表中从头搜索其数据值为value的结点 
	Linknode* p;
	p = first->next;//指针p指示第一个结点
	while (p != NULL && p->data != value)
		p = p->next;
	if (p == NULL) {
		printf("链表中不存在该值");
		return NULL;
	}
	else
		return p;
}
Linknode* Locate(Linknode* first, int i) {//返回表中第 i 个元素的地址
	Linknode* p;
	int k;
	if (i <= 0)
		return NULL;
	p = first;
	k = 0;
	while (p != NULL && k < i)
	{
		p = p->next;
		k++;
	}	   //找第 i 个结点 
	if (k == i)
		return p; //返回第 i 个结点地址
	else
		return NULL;
}
int main()
{
	first->next = first;
	Insert(first, 1, 1);
	Insert(first, 2, 2);
	Insert(first, 3, 3);
	Insert(first, 4, 4);
	Delete(first, 3);
	//Linknode* point = Locate(first, 3);
	//printf("%d", point->data);
	Linknode* p = first;
	first = first->next;
	while (first != first) {
		printf("%3d\n", first->data);
		first = first->next;
	}
	Linknode* q = Find(p, 2);
	printf("%3d\n", q->data);
	Linknode* q2 = Locate(p, 2);
	printf("%3d\n", q2->data);
	return 0;
}