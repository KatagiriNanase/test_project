#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int test6()//realloc
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			*(p + i) = 1 + i;
		}
		//扩容
		int* p2=(int*)realloc(p, 80);
		if (p2 != NULL)//realloc successed
		{
			p = p2;
			p2 = NULL;
		}
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
		free(p);
		p = NULL;
	}
	return 0;
}

int test5()//calloc:clear allocation
{
	//开辟10个元素，大小为整型的空间
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
		free(p);
		p = NULL;
		return 0;
	}
	
}

void test4()//无节制开辟空间！
{
	while (1) 
	{
		malloc(1);
	}
}
int test3()//动态内存分配
{
	int arr[10] = { 0 };
	int* p = (int*)malloc(40);//内存开辟
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else//使用
	{
		for (int i = 0; i < 10; i++)
		{
			*(p + i) = i+1;
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	return 0;
}

void test1()
{
	union Un
	{
		char arr[5];
		int i;
	}u;
	printf("%u", sizeof(u));
}

int main()
{
	test6();
	return 0;
}