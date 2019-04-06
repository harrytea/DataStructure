//队列（queue_link）
//只允许在表的一端进行插入，而在另一端删除元素的线性表
//无队满问题，但有队空问题//
#include<stdio.h>
#include<stdlib.h>
typedef int QueueData;
typedef struct node {
	QueueData data;	         //队列结点数据
	struct node *link;       //结点链指针
} QueueNode;
typedef struct {
	QueueNode *rear, *front;
} LinkQueue;
int QueueEmpty(LinkQueue *Q) {
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}
void InitQueue(LinkQueue *Q) {//链队列初始化
	Q->rear = Q->front = (QueueNode *)malloc(sizeof(QueueNode));
	if(!Q->front)exit;
	Q->front->link = NULL;
}
int GetFront(LinkQueue *Q, QueueData *x) {//取队头元素
	if (QueueEmpty(Q)) return 0;
	(*x) = Q->front->link->data; 
	return 1;
}
int EnQueue(LinkQueue *Q, QueueData x) {//入队
	QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
	p->data = x;  
	p->link = NULL;
	Q->rear->link = p; 
	Q->rear = p;
	return 1;
}
int DeQueue(LinkQueue *Q, QueueData *x) {//出队
	if (Q->rear == Q->front) return 0;	//判队空
	QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
	p = Q->front->link;
	*x = p->data;	//保存队头的值
	Q->front->link = p->link; 	//新队头
	if (Q->rear == p)
		Q->rear = Q->front;
		free(p);
	return 1;
}
int main()
{
	LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));
	InitQueue(Q);
	for(int i=0;i<6;i++)
	EnQueue(Q, i);
	int a;
	GetFront(Q, &a);
	printf("%d", a);
	return 0;
}