#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test7()//ͨ���ṹ���ڵ�ָ��ȥ����
{
	struct S
	{
		int i;
		int* arr;
	};
	//Ϊ���ñ������ڶ���
	struct S* ps2 = (struct S*)malloc(sizeof(struct S));
	if (ps2 == NULL)
		return 1;
	ps2->i = 1;
	 ps2->arr = (int*)calloc(10, sizeof(int));
	 if (ps2->arr == NULL)
		 return 1;
	 for (int i = 0; i < 10; i++)
	 {
		 ps2->arr[i] = i;
		 printf("%d ", ps2->arr[i]);
	 }
	 //����
	 int* ptr =(int*)realloc(ps2->arr, 2 * sizeof(int));
	 if (ptr != NULL)
	 {
		 ps2->arr = ptr;
		 ptr = NULL;
	 }
	 //��������ʹ��

	 //�ͷ�
	 free(ps2->arr);
	 free(ps2);
	 return 0;
}


int test6()//��������
{
	struct S
	{
		int i;
		int arr[];
	};
	//struct S s;
	struct S* ps1 = (struct S*)malloc(sizeof(struct S) + 40);
	if (ps1 == NULL)
		return 1;
	ps1->i = 1;
	for (int i = 0; i < 10; i++)
	{
		ps1->arr[i] = i;
		printf("%d ", ps1->arr[i]);
	}
	struct S* ptr=(struct S*)realloc(ps1, sizeof(struct S) + 80);//���Ե����֣���realloc����
	if (ptr != NULL)
	{
		ps1 = ptr;
		ptr = NULL;
	}
	//��������
	//�ͷ�
	free(ps1);
	ps1 = NULL;
	return 0;
}

void GetMemory(char** p)
{
	*p = (char*)malloc(15);	
}

void test5()//���������1
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello World");
	printf(str);
	char* p = "Hello World";
	free(str);
	str = NULL;
}


int test4()//�������������ڴ�й¶
{
	int* p = (int*)malloc(40);
	if (p == NULL)
		return 1;
	//��������
	int flag = 0;
	scanf("%d ", &flag);
	if (flag == 5)
		return 0;

	//��������

	free(p);
	p = NULL;
	return 0;
}

int test3()//��ͬһ�鶯̬�����ڴ���������ͷ�
{
	char* p = (char*)malloc(10);
	if (p == NULL)
		return 1;
	//ʹ�á�������
	
	//�ͷ�
	free(p);
	p = NULL;
	//��������
	free(p);
	return 0;

}

int test2()//ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
{
	int* p = (int*)malloc(40);
	if (p == NULL)
		return 1;
	for (int i = 0; i < 10; i++)
	{
		*p = i;
		p++;//�ı���pָ��ָ���λ�� 
	}
	free(p);//��������free��ʱ��p�����������ռ䶼�ͷ�
	        //��ʵ���ϣ�freeֻ�ܽ����⶯̬�����ڴ�ռ����ʼλ�ã���Ȼ����ͻ������
	p = NULL;
	return 0;
}

void test1()//�ԷǶ�̬���ٵ��ڴ�ʹ��free�ͷ�
{
	int a = 10;
	int* p = &a;
	//����
	free(p);
	p = NULL;
}

int main()
{
	test7();

	return 0;
}