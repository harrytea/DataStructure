//二叉树，链式定义
#include<stdio.h>
#include<stdlib.h>
typedef char Treedata;//结点数据类型
typedef struct node {
	Treedata data;
	struct node *leftchild, *rightchild;
}Treenode;
typedef Treenode* Treeroot;
Treenode* Create() {//先序二叉树的建立
	Treedata ch;
	Treeroot root;
	scanf("%c", &ch);
	if (ch == '#')
		root = NULL;
	else {
		root = (Treenode*)malloc(sizeof(Treenode));
		root->data = ch;
		root->leftchild = Create();
		root->rightchild = Create();
	}
	return root;
}
void Preorder(Treeroot root) {//先序遍历二叉树
	if (root) {
		printf("%c", root->data);
		Preorder(root->leftchild);
		Preorder(root->rightchild);
	}
}
void Midorder(Treeroot root) {//中序遍历二叉树
	if (root) {
		Midorder(root->leftchild);
		printf("%c", root->data);
		Midorder(root->rightchild);
	}
}
void Postorder(Treeroot root) {//后序遍历二叉树
	if (root) {
		Postorder(root->leftchild);
		Postorder(root->rightchild);
		printf("%c", root->data);
	}
}
int Count(Treeroot root) {//计算二叉树结点个数
	if (root == NULL)
		return 0;
	else return 1 + Count(root->leftchild) + Count(root->rightchild);
}
int Leaf_Count(Treeroot root) {//计算叶子结点个数
	if (!root)
		return 0;
	else if (!root->leftchild && !root->rightchild)
		return 1;
	else
		return Leaf_Count(root->leftchild) + Leaf_Count(root->rightchild);
}
int Height(Treeroot root) {//求树的高度
	if (root == NULL)
		return 0;
	else {
		int m = Height(root->leftchild);
		int n = Height(root->rightchild);
		return (m > n) ? m + 1 : n + 1;
	}
}
void Print(Treeroot root,int h) {//打印二叉树
	if (root == NULL)return;
	Print(root->rightchild, h + 1);
	for (int i = 0; i < h; i++)
		printf("   ");
	printf("%c\n", root->data);
	Print(root->leftchild, h + 1);
}
int main()
{
	Treeroot root = Create();
	printf("%d", Count(root));
	return 0;
}
