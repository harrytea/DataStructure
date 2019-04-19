#include<stdio.h>
#include<stdlib.h>
#define S1 3
#define S2 4
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
void InitStack(SeqStack *s, int n) {
	s->base = (StackData *)malloc(n * sizeof(StackData));
	if (!s->base) exit;
	s->top = s->base;
	s->stacksize = n;
}//初始化栈并置空栈
void Convert(SeqStack *s1, SeqStack *s2) {
	while (s1->top != s1->base) {
		int temp;
		(s1->top)--;
		temp = *(s1->top);
		*(s2->top) = temp;
		(s2->top)++;
	}
}//若s2为空并且s1不为空，则将s1中的内容传给s2
void Push(SeqStack *s1,SeqStack *s2,StackData x) {
	if (StackFull(s1)) {
		if (StackEmpty(s2))   //若s1满栈，则判断s2是否为空，若为空则将s1中的内容
			Convert(s1, s2);  //转到s2当中，否则输出栈满
		else {
			printf("栈已满(s2不为空）\n");
			return;
		}
	}
	*(s1->top) = x;
	(s1->top)++;
}//进栈，插入元素x为新的栈顶元素
int Pop(SeqStack *s1,SeqStack *s2, StackData *x) {
	if (StackEmpty(s2)) {
		if (!StackEmpty(s1)) { //若s2为空栈，则判断s1是否为空，若s1不为空，则将s1的
			Convert(s1, s2);   //内容转移到s2当中，否则输出栈空
			(s2->top)--;
			*x = *(s2->top);
		}
		else {
			printf("栈已空（s1为空）\n");
			return 0;
		}
	}
	else {
		(s2->top)--;
		*x = *(s2->top);
	}
	printf("%d\n", *x);
	return 1;
}//出栈，若栈空返回0，否则栈顶元素推出到x并返回1
int main()
{
	SeqStack stack1,stack2;
	InitStack(&stack1,S1);
	InitStack(&stack2,S2);//初始化栈s1和s2
	char ch;
	while (scanf("%c", &ch) != EOF) {
		if (ch == 'I') {//若标志字符ch为‘I'则入栈
			int number1;
			scanf("%d", &number1);
			Push(&stack1,&stack2,number1);
			getchar();
		}
		else if (ch == 'O') {//若标志字符ch为'O'则出栈
			int number2;
			Pop(&stack1,&stack2,&number2);
			getchar();
		}
		else
			printf("输入错误，请重新输入\n");
	}
	return 0;
}