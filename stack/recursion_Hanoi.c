//递归（recursion）
//定义：若一个对象部分地包含它自己，或用他自己给自己定义，则称这个对象是递归的
#include<stdio.h>
void Hanoi (int n, char X, char Y, char Z) {//解决汉诺塔问题的算法
    if ( n == 1 ) 
		printf (" %c->%c\n", X, Z);	   
	else {
		Hanoi(n - 1, X, Z, Y);
		printf(" %c->%c\n", X, Z);
		Hanoi(n - 1, Y, X, Z);
	}
}
int main()
{
	char a = 'A';
	char b = 'B';
	char c = 'C';
	Hanoi(3, a, b, c);
	return 0;
}