//digital_conversion(数制转换)
//10进制-->8进制
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int StackData;
typedef struct {//顺序栈定义
	StackData *base;//栈底指针
	StackData *top;//栈顶指针
	int stacksize;//当前已分配的存储空间
}SeqStack;
int StackEmpty(SeqStack *s) {
	if (s->top == s->base)
		return 1;
	else
		return 0;
}//判断栈是否为空
int StackFull(SeqStack *s) {
	if (s->top - s->base >= s->stacksize)
		return 1;//判栈满，返回1
	else
		return 0;//否则返回0
}//判断栈是否满
void InitStack(SeqStack *s) {
	s->base = (StackData *)malloc(STACK_INIT_SIZE * sizeof(StackData));
	if (!s->base) exit;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
}//置空栈
void Push(SeqStack *s, StackData x) {
	if (StackFull(s)) {
		s->base = (StackData*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(StackData));//s->base可能改动
		if (!s->base) exit(1);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;//追加存储空间
	}
	*(s->top) = x;
	(s->top)++;
}//进栈，插入元素x为新的栈顶元素
int Pop(SeqStack *s, StackData *x) {
	if (StackEmpty(s))
		return 0;
	(s->top)--;
	*x = *(s->top);
	return 1;
}//出栈，若栈空返回0，否则栈顶元素推出到x并返回1
int main()
{
	int N, e;
	SeqStack *stack;
	stack = (SeqStack *)malloc(sizeof(SeqStack));
	InitStack(stack);
	printf("input the N");
	scanf("%d", &N);
	while (N) {
		Push(stack, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(stack)) {
		Pop(stack, &e);
		printf("%d\n", e);
	}
	for (int i = 0; i < 5; i++)
		Push(stack, i);
	return 0;
}