//line editor
/*EOF为全文结束符，只有当ch为-1的时候结束操作，但是ASCII
范围为0~255因此windows输入ctrl+z结束，linux输入ctrl+d*/
/*在用户输入一行的过程中，允许  用户输入出差错，并在发现有误时可以及时更正。
	设立一个输入缓冲区，用以接受用户输入的一行字符，然后逐行存入用户数据区; 并假设“#”为退格符，“@”为退行符。
假设从终端接受两行字符：
 	whli##ilr#e（s#*s) 
          outcha@putchar(*s=#++);
实际有效行为：
        while (*s)
          putchar(*s++);*/
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char StackData;
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
void ClearStack(SeqStack *s) {
	while (!StackEmpty(s))
		(s->top)--;
}
void LineEdit(SeqStack *s) {
	InitStack(s);
	char ch,c;
	ch = getchar();
	while (ch != EOF) { //EOF为全文结束符
		while (ch != EOF && ch != '\n') {
			switch (ch) {
			case '#': Pop(s, &c); break;
			case '@': ClearStack(s); break;// 重置S为空栈
			default: Push(s, ch);  break;
			}
			ch = getchar();  // 从终端接收下一个字符将从栈底到栈顶的字符传送至调用过程的数据区
		}
		while (!StackEmpty(s)) {
			Pop(s, &c);
			printf("%c", c);
		}
		printf("\n");
		ClearStack(s);//重置S为空栈
		if (ch != EOF)
			ch = getchar();
	}
	free(s);
}
int main()
{
	SeqStack *stack;
	stack = (SeqStack *)malloc(sizeof(SeqStack));
	LineEdit(stack);
	return 0;
}