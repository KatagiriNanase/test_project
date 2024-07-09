#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t num) //模拟memcpy
{
	void* begin = dest;
	assert(dest && src);
	while (num--) //num先用于while的判断后再减减
	{
		*(char*)dest = *(char*)src;

		dest = (char*)dest +1;
		src = (char*)src+1;

		  /*((char*) dest)++; //这种强转类型的临时变量对其进行加加和减减没有太大的意义 最好不要用这种方式写
		   ((char*) src)++;*/  //而应该是对原有函数参数上进行加减

		
	}
	return begin;

}
void* my_memmove(void* dest, const void* src, size_t num)//模拟memmove
{
	void* begin = dest;
	assert(dest && src);
	if ((char*)dest - (char*)src < 0)//从前往后交换
	{
		while (num--) 
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else//从后往前交换
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);//num判断过后进行减减 已经自减了
		}
		//自己写的 belove
		//dest = ((char*)dest) + num-1; //起始位置跳过num-1 个字节来到数组中的最后一个字节
		//src = ((char*)src) + num-1;
		//while (num--)
		//{
		//	*(char*)dest = *(char*)src;
		//	dest = (char*)dest - 1;
		//	src = (char*)src - 1;
		//}
	}
	return begin;
}
void test7()
{
	char arr1[5] = "";
	memset(arr1, 'x', 4);
	printf("%s\n", arr1);
}


void test6()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = {1,3,2};
	printf("%d\n", memcmp(arr1, arr2,4));
}

void test5()
{
	int arr1[] = {1,2,3,4,5,6,7,8,9,10};
	my_memmove(arr1 + 2, arr1, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
}

int main()
{
	test7();
	return 0;
}

void test4()
{
	float arr1[5] = { 1.0,2.0,3.0,4.0,5.0 };
	float arr2[5] = { 0 };
	//my_memcpy(arr2, arr1, sizeof(arr1));
	memcpy(arr2, arr1, 20);
	for (int i = 0; i < 5; i++)
	{
		printf("%.1f ", arr2[i]);
	}
}


void test3()
{
	printf("%c\n", tolower(20));
	printf("%c\n", toupper(20));

}

void test2()
{
	int a = isspace('n');
	printf("%d\n", a);
}

int test1()
{
	FILE* pf=fopen("text.txt", "r"); //打开成功 返回有效地址 打开失败 返回空指针
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		//
	}
	return 0;
}