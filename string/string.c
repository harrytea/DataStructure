//串（string）
//串(String)是零个或多个字符组成的有限序列。
/*双引号括起来的字符序列是串值，ai(1≦i≦n)可以是字母、数字或其它字符
空串：长度为零的串称为空串(Empty String)，它不包含任何字符
空格串：将仅由一个或多个空格组成的串称为空格串(Blank String)*/
#include<stdio.h>
#include<assert.h>
int strlen(const char* str) {//求字符串的长度
	assert(str != NULL);
	int len = 0;
	while (*str++ != '\0')
		++len;
	return len;
}
char* strcpy(char* strDes, const char* strSrc) {
	assert((strDes != NULL) && (strSrc != NULL));
	char* address = strDes;
	while ((*strSrc)!='\0')
		*strDes++ = *strSrc++;
	return address;
}//串复制，将src复制到des中
char* strcat(char* strDes, const char *strSrc) {
	assert((strDes != NULL)&(strSrc != NULL));
	char* address = strDes;
	while (*strDes != '\0')
		++strDes;
	while ((*strSrc) != '\0')
		*strDes++ = *strSrc++;
	return address;
}//连接将src复制到des的末尾，返回一个指向des的指针
int strcmp(const char* s, const char* t) {
	assert(s != NULL && t != NULL);
	while (*s&&*t&&*s == *t) {
		++s;
		++t;
	}
	return (*s - *t);
}//比较s和t的大小，返回s和t第一个不同的字符的差值
char* strstr(const char* strSrc, const char* str) {
	assert(strSrc != NULL && str != NULL);
	const char* s = strSrc;
	const char* t = str;
	for (; *t != '\0'; ++strSrc) {
		for (s = strSrc, t = str; *t != '\0'&&*s == *t; ++s, ++t)
			NULL;
		if (*t == '\0')
			return (char*)strSrc;
	}
	return NULL;
}//在src中招str，如果搜索到，返回指针指向src第一次出现的位置；否则返回NULL
int main()
{
	const char* str1 = "I am a boy";
	printf("%d", strlen(str1));//字符串的长度
	char str2[100] = "hello world,nihao,shijie";
	char* str= strcpy(str2, str1);
	printf("%s",str2);
	puts("");
	strcat(str2, str1);
	printf("%s", str2);
	puts("");
	printf("%d", strcmp(str1, str2));
	puts("");
	const char* stra = "ok,I am a boy,you know";
	const char* strb = "I am a boy";
	const char* str_str = strstr(stra, strb);
	puts(str_str);
	return 0;
}