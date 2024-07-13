#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stddef.h>
void test8()//修改对齐数
{
	struct S1
	{
		char c1;
		int i;
		char c2;
	};
	printf("未修改对齐数时（vs默认8）struct S1大小：%d\n", sizeof(struct S1));
#pragma pack(4)
	struct S2
	{
		char c1;
		int i;
		char c2;
	};
#pragma pack()
	printf("修改对齐数为4时（vs默认8）struct S1大小：%d\n", sizeof(struct S2));
#pragma pack(1)
	struct S3
	{
		char c1;
		int i;
		char c2;
	};
#pragma pack()
	printf("未进行内存对齐时（对齐数为1时）struct S1大小：%d\n", sizeof(struct S3));
}

void test7()
{
	struct S3
	{
		double d;
		char c;
		int i;

	}s3;
	
	struct S4
	{
		char c1;
		struct S3 s3;//.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
		             //结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍。
		//struct S3这个结构体本身的最大对齐数为8 就对齐到8的整数倍处
		double d;
		//最后算结构体大小时，是所有的对齐数，包括struct S3的对齐数的整数倍。
	};
	printf("此自定义结构体的大小为:%u\n", sizeof(struct S4));
}

void test6()
{
	struct S3
	{
		double d;
		char c;
		int i;

	}s3;
	printf("char = %u\n", offsetof(struct S3, d));//查看成员变量的偏移量
	printf("int = %u\n", offsetof(struct S3, c));
	printf("char = %u\n", offsetof(struct S3, i));
	printf("此自定义结构体的大小为:%u\n", sizeof(struct S3));
}
void test5()
{
	struct S2
	{
		char c1;//1
		char c2;//1
		int i;//4
		
	}s2;
	printf("char = %u\n", offsetof(struct S2, c1));//查看成员变量的偏移量
	printf("int = %u\n", offsetof(struct S2, c2));
	printf("char = %u\n", offsetof(struct S2, i));
	printf("此自定义结构体的大小为:%u\n", sizeof(struct S2));
}
void test4()
{
	struct S1
	{
		char c1;//1
		int i;//4
		char c2;//1
	}s1;
	printf("char = %u\n",offsetof(struct S1, c1));//查看成员变量的偏移量
	printf("int = %u\n", offsetof(struct S1, i));
	printf("char = %u\n", offsetof(struct S1, c2));
    printf("此自定义结构体的大小为:%u\n", sizeof(s1));
}

void test3_total()
{
	typedef struct Node2
	{
		int data;
		struct Node2* next;
	}Node;

	struct Node1
	{
		int data;
		struct Node1* next;
	};


	struct
	{
		char name[20];
		int age;
	}stu1;
	struct
	{
		char name[20];
		int age;
	}*p;

		p = &stu1;
	
}


//字符串旋转结果
//题目内容 :
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串,
//例如 : 给定S1 = AABCD和s2 = BCDAA，返回1给定s1 = abcd和s2 = ACBD，返回0
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
int is_left_move(char* str1, const char* str2)
{
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	strncat(str1, str1, len1);
	char* ret=strstr(str1, str2);
	if (ret == NULL)
		return 0;
	else
		return 1;
	
}
void test2()
{
	char str1[20] = "abcdefabcdef";
	char str2[] = "cdefab";
	int ret=is_left_move(str1, str2);
	if (ret == 1)
		printf("是\n");
	else
		printf("否\n");
}


void test1()//vs2022的strcat能够自己追加自己
{
	char str1[20] = "abcdef";
	strcat(str1, str1);
	printf("%s\n", str1);
}

int main()
{
	test8();
	return 0;
}
