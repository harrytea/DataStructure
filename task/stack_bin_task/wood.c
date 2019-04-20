#include<stdio.h>
#define m_m 10
#define n_n 2*m_m-1
typedef struct{
	int node;//代表结点的木头长度
	int parent;
	int lchild;
	int rchild;
}HTree,Huffmantree[n_n+1];
void select(Huffmantree HT, int n, int *s1, int *s2) {
	int temp1, temp2;
	int min = 1000;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && HT[i].node < min) {
			min = HT[i].node;
			temp1 = i;
		}
	}//寻找第一个最小值
	*s1 = temp1;
	min = 1000;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0 && HT[i].node < min&& i != *s1) {
			min = HT[i].node;
			temp2 = i;
		}
	}//寻找第二个最小值
	*s2 = temp2;
}//求哈夫曼树中最小的两项以合并
void CreatHTree(Huffmantree HT, int money[], int n) {
	for (int i = 1; i <= n; i++) {
		HT[i].node = money[i];
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}//初始化霍夫曼树的前n项
	int m = 2 * n - 1;
	for (int i = n + 1; i <= m; i++) {
		HT[i].node = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}//将霍夫曼树的后n-1项初始化
	int s1, s2;
	for (int i = n + 1; i <= m; i++) {
		select(HT, i - 1, &s1, &s2);
		HT[i].node = HT[s1].node + HT[s2].node;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
	}//构建霍夫曼树
}//初始化霍夫曼树
int main() {
	int N,money[m_m];
	scanf("%d",&N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &money[i]);//输入切割后每个木头的长度
	Huffmantree HT;
	CreatHTree(HT, money, N);
	printf("haffman树的结构为:\n");
	for (int i = 1; i <= 2 * N - 1; i++) 
		printf("%d %d %d %d\n", HT[i].node, HT[i].parent, HT[i].lchild, HT[i].rchild);
	int sum = 0;
	for (int i = 2 * N - 1; i >= N + 1; i--) {
		printf("将%d切分为%d和%d\n", HT[i].node, HT[(HT[i].lchild)].node, HT[(HT[i].rchild)].node);
		sum += HT[i].node;
	}//输出切割过程
	printf("总花费为%d\n", sum);
	return 0;
}