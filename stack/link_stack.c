//栈的链式表示
//链式栈无满栈的问题，空间可扩充，插入删除仅在栈顶执行
//链式栈的栈顶在链头
/*常用操作
1.栈顶和栈结点指针
2.栈的初始化
3.入栈
4.出栈
5.取栈顶
6.判断栈是否为空
*/
#include<stdio.h>
#include<stdlib.h>
typedef int StackData;
typedef struct node {
	StackData data;//结点
	struct node *link;//链指针
}StackNode;
typedef struct{
	StackNode *top;
}LinkStack;//栈顶指针
void InitStack(LinkStack *s) {
	s->top = NULL;
}//初始化
int StackEmpty(LinkStack *s) {
	return s->top == NULL;
}//判断栈是否为空
int push(LinkStack *s, StackData x) {
	StackNode *p = (StackNode*)malloc(sizeof(StackNode));
	p->data = x;
	p->link = s->top;
	s->top = p;
	return 1;
}//入栈
int Pop(LinkStack *s, StackData *x) {
	if (StackEmpty(s))
		return 0;
	StackNode *p = s->top;
	s->top = p->link;
	*x = p->data;
	free(p);
	return 1;
}//出栈
int GetTop(LinkStack *s, StackData *x) {
	if (StackEmpty(s))
		return 0;
	*x = s->top->data;
	return 1;
}//取栈顶
int MakeEmpty(LinkStack *s) {
	while (s->top != NULL) {
		StackNode *p = s->top;
		s->top = s->top->link;
		free(p);
	}
}//置栈空
int main()
{
	LinkStack stack;
	InitStack(&stack);
	push(&stack, 3);
	int a = StackEmpty(&stack);
	printf("%d", a);
	return 0;
}