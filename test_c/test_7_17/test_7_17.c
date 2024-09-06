#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test7()//通过结构体内的指针去开辟
{
	struct S
	{
		int i;
		int* arr;
	};
	//为了让变量都在堆区
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
	 //扩容
	 int* ptr =(int*)realloc(ps2->arr, 2 * sizeof(int));
	 if (ptr != NULL)
	 {
		 ps2->arr = ptr;
		 ptr = NULL;
	 }
	 //…………使用

	 //释放
	 free(ps2->arr);
	 free(ps2);
	 return 0;
}


int test6()//柔性数组
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
	struct S* ptr=(struct S*)realloc(ps1, sizeof(struct S) + 80);//柔性的体现：用realloc扩容
	if (ptr != NULL)
	{
		ps1 = ptr;
		ptr = NULL;
	}
	//…………
	//释放
	free(ps1);
	ps1 = NULL;
	return 0;
}

void GetMemory(char** p)
{
	*p = (char*)malloc(15);	
}

void test5()//经典笔试题1
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello World");
	printf(str);
	char* p = "Hello World";
	free(str);
	str = NULL;
}


int test4()//操作不当导致内存泄露
{
	int* p = (int*)malloc(40);
	if (p == NULL)
		return 1;
	//…………
	int flag = 0;
	scanf("%d ", &flag);
	if (flag == 5)
		return 0;

	//…………

	free(p);
	p = NULL;
	return 0;
}

int test3()//对同一块动态开辟内存进行两次释放
{
	char* p = (char*)malloc(10);
	if (p == NULL)
		return 1;
	//使用…………
	
	//释放
	free(p);
	p = NULL;
	//…………
	free(p);
	return 0;

}

int test2()//使用free释放一块动态开辟内存的一部分
{
	int* p = (int*)malloc(40);
	if (p == NULL)
		return 1;
	for (int i = 0; i < 10; i++)
	{
		*p = i;
		p++;//改变了p指针指向的位置 
	}
	free(p);//导致这里free的时候，p并不是整个空间都释放
	        //但实际上，free只能接收这动态开辟内存空间的起始位置，不然程序就会崩溃。
	p = NULL;
	return 0;
}

void test1()//对非动态开辟的内存使用free释放
{
	int a = 10;
	int* p = &a;
	//……
	free(p);
	p = NULL;
}

int main()
{
	test7();

	return 0;
}