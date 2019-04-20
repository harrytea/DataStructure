#include<stdio.h>
#include<stdlib.h>
//#define NDEBUG
//#include<assert.h>
#define m_m 10
#define n_n 2*m_m-1
typedef struct {
	char letter, *code;//字符，编码
	int node;
	int parent;
	int lchild;
	int rchild;
}HTree, Huffmantree[n_n + 1];
int strlen(char* str) {//求字符串的长度
	//assert(str != NULL);
	int len = 0;
	while (*str++ != '\0')
		++len;
	return len;
}
/*char* strcpy(char* strDes, char* strSrc) {
	assert((strDes != NULL) && (strSrc != NULL));
	char* address = strDes;
	while ((*strDes) != '\0')
		*strDes++ = *strSrc;
	return address;
}//串复制，将src复制到des中*/
int strcmp(char* s, char* t) {
	//assert(s != NULL && t != NULL);
	while (*s&&*t&&*s == *t) {
		++s;
		++t;
	}
	return (*s - *t);
}//比较s和t的大小，返回s和t第一个不同的字符的差值
void select(Huffmantree HT, int n, int *s1, int *s2) {
	int temp1, temp2;
	int min = 10000;
	for (int i = 0; i < n; i++) {
		if (HT[i].parent == 0 && HT[i].node < min) {
			min = HT[i].node;
			temp1 = i;
		}
	}//寻找第一个最小值
	*s1 = temp1;
	min = 10000;
	for (int i = 0; i < n; i++) {
		if (HT[i].parent == 0 && HT[i].node < min&& i != *s1) {
			min = HT[i].node;
			temp2 = i;
		}
	}//寻找第二个最小值
	*s2 = temp2;
}//求哈夫曼树中最小的两项以合并
void CreatHTree(Huffmantree HT, int s[],char ss[], int n) {
	for (int i = 0; i < n; i++) {
		HT[i].letter = ss[i];
		HT[i].node = s[i];
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}//将霍夫曼树的前n项初始化
	int m = 2 * n - 1;
	for (int i = n ; i < m; i++) {
		HT[i].letter = '#';
		HT[i].node = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	}//将霍夫曼的后n-1项初始化
	int s1, s2;
	for (int i = n ; i < m; i++) {
		select(HT, i, &s1, &s2);
		HT[i].node = HT[s1].node + HT[s2].node;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
	}//构建霍夫曼树
}//初始化霍夫曼树
void CreatHTreecode(Huffmantree HT,int n) {
	char **cd = (char**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; i++)
		cd[i] = (char*)malloc(sizeof(char)*n);
	int i;
	int start;
	for (i = 0; i < n; i++){
		cd[i][n - 1] = '\0';   //从右向左存放编码
		start = n - 1;
		int c = i;
		int p = HT[i].parent;
		while (p != 0){
			--start;
			if (HT[p].lchild == c) 
				cd[i][start] = '0';
			else 
				cd[i][start] = '1';
			c = p;
			p = HT[p].parent;
		}//存放霍夫曼编码后的值
		int j,k=0;
		HT[i].code = (char*)malloc(sizeof(char)*n);
		for (j = start; cd[i][j] != '\0'; j++) {
			HT[i].code[k++] = cd[i][j];
			printf("%c", cd[i][j]);
		}//将霍夫曼编码后的值对应放到霍夫曼树中
		HT[i].code[k] = '\0';
		printf("\n");
	}
	return;
}//霍夫曼编码
void HuffmanTree_decode(Huffmantree HT, char ss[], int n,int sum) {
	char sen[100];
	char temp[50];
	//char voidstr[] = " ";       //空白字符串
	int t = 0;
	int s = 0;
	int pos = 0;
	for (int i = 0; i<sum-1; i++) {
		temp[t++] = ss[i];     //读取字符
		temp[t] = '\0';        //有效字符串结束
		for (int j = 0; j<n; j++) {        //依次与所有字符编码开始匹配
			if (!strcmp(HT[j].code, temp)) { //匹配成功
				sen[s++] = HT[j].letter;    //将编码对应字符保存到sen中
				pos += t;
				//strcpy(temp, voidstr);    //将TEMP置空
				t = 0;          //t置空
				break;
			}
		}
	}
	if (t == 0) {     //t如果被置空了，表示都匹配出来了，打印译码
		sen[s] = '\0';
		puts("译码为：");
		printf("%s\n", sen);
	}
	else                             //t如果没有被置空 ， 源码无法被完全匹配
		printf("输入的二进制源码有错误，从第%d位开始",pos + 1);
}//霍夫曼解码
int main() {
	char str[100];//存放要编码的字符串
	char ss[10];//存放字符串中的统计项
	int s[10];//存放字符串中字符的权值
	int n=0,j;
	gets_s(str);//输入字符串
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		for (j = 0; j < n; j++) {
			if (ss[j] == str[i]) {
				s[j] += 1; break;
			}
		}
		if (j >= n) {
			ss[n] = str[i];
			s[n] = 1;
			n++;
		}
	}//统计字符和对应的权值
	for (int i = 0; i<n; i++){
		printf("字符：%c，权值：%d\n", ss[i], s[i]);
	}//打印字符及对应的权值
	Huffmantree HT;
	CreatHTree(HT,s,ss,n);//构建霍夫曼树
	CreatHTreecode(HT, n);//对霍夫曼树进行编码
	printf("huffman树的结构为:\n");
	for (int i = 0; i <2 * n - 1; i++)//打印huffman_tree
		printf("%c %d %d %d %d\n",HT[i].letter, HT[i].node, HT[i].parent, HT[i].lchild, HT[i].rchild);
	puts("huffman树的编码为：");
	for (int i = 0; i < n; i++)
		printf("%c %s\n", HT[i].letter, HT[i].code);//输出huffman编码
	while (1) {
		puts("请输入译码的二进制字符串并以‘#’结束");
		int sign = 1;//判断是否输入正确的字符‘1’‘0’或‘#’
		int sum = 0;//计数输入的总字符数
		int symbol = 1;//判断是否输入结束
		char string[100];
		while (symbol) {
			char sss;
			scanf("%c", &sss);
			string[sum++] = sss;
			if (sss != '1'&&sss != '0'&&sss != '#')
				sign = 0;
			if (sss == '#') {
				symbol = 0;
			}
		}
		string[sum] = '\0';
		if (sign == 1)
			HuffmanTree_decode(HT, string,n, sum);
		else
			puts("输入有误");
		getchar();//接受换行符
	}
	return 0;
}
