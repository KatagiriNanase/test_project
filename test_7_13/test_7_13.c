#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stddef.h>
void test8()//�޸Ķ�����
{
	struct S1
	{
		char c1;
		int i;
		char c2;
	};
	printf("δ�޸Ķ�����ʱ��vsĬ��8��struct S1��С��%d\n", sizeof(struct S1));
#pragma pack(4)
	struct S2
	{
		char c1;
		int i;
		char c2;
	};
#pragma pack()
	printf("�޸Ķ�����Ϊ4ʱ��vsĬ��8��struct S1��С��%d\n", sizeof(struct S2));
#pragma pack(1)
	struct S3
	{
		char c1;
		int i;
		char c2;
	};
#pragma pack()
	printf("δ�����ڴ����ʱ��������Ϊ1ʱ��struct S1��С��%d\n", sizeof(struct S3));
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
		struct S3 s3;//.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ�����������������������
		             //�ṹ��������С����������������(��Ƕ�׽ṹ��Ķ�����)����������
		//struct S3����ṹ�屾�����������Ϊ8 �Ͷ��뵽8����������
		double d;
		//�����ṹ���Сʱ�������еĶ�����������struct S3�Ķ���������������
	};
	printf("���Զ���ṹ��Ĵ�СΪ:%u\n", sizeof(struct S4));
}

void test6()
{
	struct S3
	{
		double d;
		char c;
		int i;

	}s3;
	printf("char = %u\n", offsetof(struct S3, d));//�鿴��Ա������ƫ����
	printf("int = %u\n", offsetof(struct S3, c));
	printf("char = %u\n", offsetof(struct S3, i));
	printf("���Զ���ṹ��Ĵ�СΪ:%u\n", sizeof(struct S3));
}
void test5()
{
	struct S2
	{
		char c1;//1
		char c2;//1
		int i;//4
		
	}s2;
	printf("char = %u\n", offsetof(struct S2, c1));//�鿴��Ա������ƫ����
	printf("int = %u\n", offsetof(struct S2, c2));
	printf("char = %u\n", offsetof(struct S2, i));
	printf("���Զ���ṹ��Ĵ�СΪ:%u\n", sizeof(struct S2));
}
void test4()
{
	struct S1
	{
		char c1;//1
		int i;//4
		char c2;//1
	}s1;
	printf("char = %u\n",offsetof(struct S1, c1));//�鿴��Ա������ƫ����
	printf("int = %u\n", offsetof(struct S1, i));
	printf("char = %u\n", offsetof(struct S1, c2));
    printf("���Զ���ṹ��Ĵ�СΪ:%u\n", sizeof(s1));
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


//�ַ�����ת���
//��Ŀ���� :
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���,
//���� : ����S1 = AABCD��s2 = BCDAA������1����s1 = abcd��s2 = ACBD������0
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
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
		printf("��\n");
	else
		printf("��\n");
}


void test1()//vs2022��strcat�ܹ��Լ�׷���Լ�
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
