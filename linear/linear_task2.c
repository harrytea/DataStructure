//多项式的乘法*链表均带有表头节点，计算长度时不算在链表中
/*基本思路是构建两个链表分别储存两个多项式，用第一个多项式的每一项去乘另一个多项式，将得到的m*n个项储存到
第三个链表中，然后将第三个链表进行化简，化简完之后用一个sort函数将指数(exp)进行排序，小的放在链表的前面，
大的放在链表的后面*/
#include<stdio.h>
#include<stdlib.h>
typedef struct term {
	int coef;
	int exp;
	struct term *next;
}LinkList;//定义
LinkList *creat(int n) {//链表的初始化
	LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点
	head = (LinkList*)malloc(sizeof(LinkList));//分配地址
	end = head;              //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		printf("多项式的第%d项的系数和指数分别为", i + 1);
		scanf("%d %d", &node->coef, &node->exp);
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	return head;
}
int Length(LinkList *list) {//求表的长度
	int count = 0;
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count - 1;//剔除表头节点
}
LinkList* simplify(LinkList *list) {
	LinkList *head = list;
	list = list->next;
	LinkList *main_note = list, *note1 = list, *note2 = list->next;
	while (main_note->next != NULL) {
		for (int i = 1; i < Length(head); i++) {
			while (note2 != NULL) {
				if (note2->exp == main_note->exp) {
					main_note->coef += note2->coef;
					note1->next = note2->next;
					LinkList *temp = note2;
					note2 = note2->next;
					free(temp);
				}
				else {
					note1 = note1->next;
					note2 = note2->next;
				}
			}
		}
		main_note = main_note->next;
		note1 = main_note;
		note2 = note1->next;
	}
	return head;
}//化简多项式，将指数相同的项合并
LinkList* multiply(LinkList *list1, LinkList *list2, int len1, int len2) {
	list1 = list1->next;
	list2 = list2->next;
	LinkList *head1 = list1, *head2 = list2;
	LinkList *head3, *list3, *note3;
	head3 = (LinkList*)malloc(sizeof(LinkList));//第三个链表的表头节点
	list3 = head3;
	head3->next = NULL;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			note3 = (LinkList*)malloc(sizeof(LinkList));
			note3->coef = list1->coef*list2->coef;
			note3->exp = list1->exp + list2->exp;//为list3数据域赋值
			head3->next = note3;
			head3 = note3;
			list2 = list2->next;
		}//将第一个链表中内容和第二个链表中的内容相乘并放入到第三个链表中
		list2 = head2;
		list1 = list1->next;
	}
	note3->next = NULL;
	LinkList *list = simplify(list3);//将第三个链表进行化简
	return list;
}//乘积函数，得到相乘之后的多项式
LinkList* sort(LinkList *list) {
	LinkList *head = list;
	list = list->next;
	LinkList *note1 = list;
	LinkList *note2 = list->next;
	int len = Length(head);
	while (note2 != NULL) {
		for (int i = 1; note2 != NULL && i < len; i++) {
			if (note1->exp > note2->exp) {
				int temp = note2->coef;
				note2->coef = note1->coef;
				note1->coef = temp;
				temp = note2->exp;
				note2->exp = note1->exp;
				note1->exp = temp;
			}//如果在前节点的指数大于在后节点的指数，那么二者的节点内容进行交换
			note2 = note2->next;
		}
		note1 = note1->next;
		note2 = note1->next;
	}
	return head;
}//将相乘之后的多项式进行排序，即指数大的节点放到指数小的节点之后
void print(LinkList *list, int len1, int len2) {
	int m1 = len1;
	int m2 = len2;
	puts("两个多项式的乘积为:");
	list = list->next;
	if (list->exp == 0 && list->coef != 0)
		printf("%d", list->coef);
	else if (list->coef == 1 && list->exp == 1)
		printf("x");
	else if (list->coef == -1 && list->exp == 1)
		printf("-x");
	else if (list->coef == 1)
		printf("x^%d", list->exp);
	else if (list->coef == -1)
		printf("-x^%d", list->exp);
	else if (list->coef == 0)
		printf("");
	else
		printf("%dx^%d", list->coef, list->exp);//输出多项式的第一项
	list = list->next;
	while (list != NULL) {
		if (list->coef == 0)
			printf("");
		else if (list->coef == 1 && list->exp == 1)
			printf("+x");
		else if (list->coef == -1 && list->exp == 1)
			printf("-x");
		else if (list->coef > 0 && list->exp == 1)
			printf("+%dx", list->coef);
		else if (list->coef < 0 && list->exp == 1)
			printf("%dx", list->coef);
		else if (list->coef == -1)
			printf("-x^%d", list->exp);
		else if (list->coef == 1)
			printf("+x^%d", list->exp);
		else if(list->coef>0)
			printf("+%dx^%d", list->coef, list->exp);
		else
			printf("%dx^%d", list->coef, list->exp);
		list = list->next;
	}//输出多项式的其余项
}
int main()
{
	int m1, m2;
	LinkList *poly1, *poly2, *poly3, *head;
	puts("请输入第一个多项式的项数");
	scanf("%d", &m1);//输入第一个多项式的项数
	puts("请输入第二个多项式的项数");
	scanf("%d", &m2);//输入第二个多项式的项数
	if (m1 != 0 && m2 != 0) {
		poly1 = creat(m1);
		poly2 = creat(m2);//创建多项式
		poly3 = multiply(poly1, poly2, m1, m2);//将多项式相乘并得出结果
		head = sort(poly3);//利用排序函数将指数小的节点放在指数大的节点之前
		print(head, m1, m2);//利用输出函数输出结果
		printf("\n");
	}
	else
		puts("多项式的乘积为0");
	return 0;
}