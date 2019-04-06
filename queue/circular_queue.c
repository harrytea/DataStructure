//循环队列（circular_queue）
/*顺序队列—队列的顺序存储表示
用一组地址连续的存储单元依次存放从队列头到队列尾的元素
指针front和rear分别指示队头元素和队尾元素的位置
在非空队列中，头指针始终指向队列头元素，而尾指针始终指向队列尾元素的下一个位置。
队满时再进队将溢出，顺序队列为一个环状的空间，形成循环(环形)队列*/
/*队头指针进1:front = (front+1) %maxsize;
队尾指针进1:rear = (rear+1) % maxsize;
队列初始化：front = rear = 0;
队空条件：front == rear;
队满条件：(rear+1) % maxsize == front; */
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef  int  QueueData;
typedef struct {
	QueueData *data;
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue *Q) {//初始化队列，构造空队列
	Q->data = (QueueData *)malloc(MAXSIZE * sizeof(QueueData));
	if (!Q->data)exit;
	Q->rear = Q->front = 0;
}
int QueueEmpty(SeqQueue *Q) {//判队空
	return Q->rear == Q->front;
}
int QueueFull(SeqQueue *Q) {//判队满
	return (Q->rear + 1) % MAXSIZE == Q->front;
}
int EnQueue(SeqQueue *Q, QueueData x) {//入队
	if (QueueFull(Q)) return 0;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}
int DeQueue(SeqQueue *Q, QueueData *x) {//出队
	if (QueueEmpty(Q)) return 0;
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}
int GetFront(SeqQueue *Q, QueueData *x) {//取队头
	if (QueueEmpty(Q)) return 0;
	*x = Q->data[Q->front];
	return 1;
}
int main()
{
	SeqQueue* Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	int x;
	DeQueue(Q, &x);
	EnQueue(Q, 5);
	return 0;
}
