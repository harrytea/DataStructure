#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	int score;
	struct student *next;
}LinkList;//定义
		  /*
		  typedef struct student LinkList;
		  struct student{
		  int score;
		  LinkList *next;
		  };另一种定义方式
		  */
LinkList *creat(int n) {//链表的初始化
	LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点
	head = (LinkList*)malloc(sizeof(LinkList));//分配地址
	end = head;              //将尾节点指向头节点
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->score);
		end->next = node;
		end = node;
	}//创建链表
	end->next = NULL;//结束创建
	return head;
}
int Length(LinkList *list) {
	int count = 0;
	while (list != NULL) {
		list = list->next;
		count++;
	}
	return count - 1;//剔除头指针(空节点)
}//求表的长度
int GetData(LinkList *list, int n) {//提取第n个元素的值
	int i = 1;
	list = list->next;//指向第一个节点而不是空节点
	if (n >= 1 && n <= Length(list) + 1) {
		while (i != n) {
			i++;
			list = list->next;
		}
		return list->score;
	}
	else
		puts("参数不合理!");
}//若提取的元素n比链表的长度大，输出参数不合理，反之返回第n个参数
void Find_insert(LinkList *list, int insert_numb) {//
	LinkList *t = list, *in;
	LinkList *note = list;
	if (t->next != NULL) {//排除了链表A为空的情况
		t = t->next;//指向链表A的第一个元素
		while (1) {//进行一个循环，直到被插入元素插入到A中时，跳出循环
			if (t == NULL) {
				in = (LinkList*)malloc(sizeof(LinkList));
				in->score = insert_numb;
				in->next = t;
				note->next = in;
				break;
			}//在链表的尾部插入
			else if (t->score >= insert_numb) {
				in = (LinkList*)malloc(sizeof(LinkList));
				in->score = insert_numb;
				in->next = t;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
				note->next = in;//填充t节点的指针域，把t的指针域重新指向in
				break;
			}//在链表A的中间某个位置插入
			else {
				t = t->next;
				note = note->next;
			}
		}
	}
	else {
		in = (LinkList*)malloc(sizeof(LinkList));
		in->score = insert_numb;
		in->next = NULL;
		t->next = in;
	}//考虑链表A为空的情况，直接在A中插入
}
LinkList* Union(LinkList *A, LinkList *B) {
	int lb, x;
	LinkList *head = A;
	lb = Length(B);
	for (int i = 1; i <= lb; i++) {//遍历链表b(即遍历链表)
		x = GetData(B, i);//查看B中的第i个元素
		Find_insert(A, x);
	}
	return head;
}//取A、B的并集并返回头指针
int main()
{
	int m1, m2;
	LinkList *note1, *note2;
	scanf("%d", &m1);//输入第一个链表的长度
	scanf("%d", &m2);//输入第二个链表的长度
	note1 = creat(m1);
	note2 = creat(m2);//创建链表
	LinkList *above = Union(note1, note2);//合并链表
	above = above->next;
	if (above != NULL) {
		while (above != NULL) {
			printf("%5d", above->score);
			above = above->next;
		}
	}
	else {
		puts("AB链表均为空");
		printf("NULL\n");
	}//将链表输出，若AB均为空集，则输出NULL；否则将合并后的链表输出
	return 0;
}