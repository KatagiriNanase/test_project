#define _CRT_SRCURE_NO_WARNINGS 1
#include <stdio.h>
test4()
{
	struct test
	{
		int data[100];
	}test;
	printf("%u\n", sizeof(test.data));
	printf("%u\n", sizeof(struct test));
}
test3()
{
	printf("接下来去实现下我的简易版内存通讯录了\n");
}
test2()//位段
{
	struct bit
	{
		int _a : 2;
		int _b : 5;
		int _c : 10;
		int _d : 30;
	};
	printf("%d ", sizeof(struct bit));
}
struct S
{
	int data[1000];
	int num;
}s;

void print1(const struct S* ps)//通过结构体指针传参
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n%d", ps->num);
}

void print2(struct S s)//结构体传值
{
	for (int i = 0; i < 3; i++)
		printf("%d ", s.data[i]);
	printf("\n%d", s.num);
}
void test1()//结构体传参
{
	struct S s = { {1,2,3},10 };
	print1(&s);//传址调用
	print2(s);//传值调用

}

int main()
{
	test4();
	return 0;
}