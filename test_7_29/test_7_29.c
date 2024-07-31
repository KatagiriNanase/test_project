#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#define __DEBUG__ 1
#define DEBUG_PRINT printf("file:%s\tline:%d\tdate:%s\ttime:%s\t",\
__FILE__,__LINE__,\
__DATE__,__TIME__)
#define SQURE(X) ((X)*(X))
#define PRINT(N,TYPE) printf("the value of "#N" is "TYPE"\n",N)
#define CAT(NAME,NUM) NAME##NUM
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MALLOC(ELEMENT,TYPE) (TYPE*)malloc((ELEMENT)*sizeof(TYPE))
void test1()
{
	
	DEBUG_PRINT;
	int a = SQURE(3 + 1);
	//printf("%d ", a);
	printf("hello ""world\n");
	float b = 3.14f;
	PRINT(a, "%d");
	PRINT(b, "%f");
}
void test2()
{
	char namenum[] = "sorakado33";
	printf("%s\n", CAT(name, num));
	printf("%s\n", namenum);
}
void test3()
{
	printf("%d\n",MAX(1 + 2, 45)); 
}
void test4()//试一下变长数组
{
	int input = 0;
	while (scanf("%d", &input))
	{
		int* parr = MALLOC(input, int);
		int i = 0;
		for (i; i < input; i++)
		{
			scanf("%d", (parr + i));
		}
		for (int i = 0; i < input; i++)
		{
			printf("%d ", parr[i]);
		}
	};
	
	

}
void test5()
{
#define M 100
	printf("%d ", M);
#undef M
	//printf("%d ", M);
}

void test6()//条件编译
{
	int input = 0;
	scanf("%d", &input);
	int* parr = MALLOC(input, int);
	int i = 0;
	for (i; i < input; i++)
	{
		scanf("%d", (parr + i));
	}
#ifdef __DEBUG__
	for (int i = 0; i < input; i++)
	{
		printf("%d ", parr[i]);//为了观察赋值的情况而打印，我们不需要的话就可以直接将定义的__DEBUG__注释掉就好
	}
#endif //__DEBUG__
}

void test7()//多分支条件编译
{
#ifdef __DEBUG__
	#define M 5
	#if M>5
		printf("hello world\n");
	#elif M==5
		printf("be happy every day!\n");
	#else
		printf("smile to the fucking life!\n");
	#endif
#endif//__DEBUG__
}


void test8()//判断是否被定义
{
//#define M 10
#if defined(M)
	printf("%d \n", M);
#endif //defined(M)

#ifdef M
	printf("%d \n", M);
#endif //ifdef M

#if !defined(N)
	printf("no defined\n");
#endif//!defined(N)

#ifndef N
	printf("no defined\n");
#endif //ifndef N
}

void test9()//模拟实现offsetof
{
	typedef struct S
	{
		char a;
		int b;
		char c;
	}S;
	S s = { "a",2 };
//#define OFFSETOF(STRCUT,NUM) ((size_t)((char*p2=STRCUT s.NUM)-(char*p1=(STRCUT s))))
#define OFFSETOF(STRCUT,NUM) (size_t)(&(((STRCUT*)0)->NUM))
	/*printf("%d ", offsetof(S, a));
	printf("%d ", offsetof(S, b));
	printf("%d ", offsetof(S, c));*/
	printf("%u ",OFFSETOF(S, a));
	printf("%u ", OFFSETOF(S, b));
	printf("%u ", OFFSETOF(S, c));
	

}
int main()
{
	
	test9();
	return 0;
}