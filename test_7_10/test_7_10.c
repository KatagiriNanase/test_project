#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test2()//多组输入，一个整数(2~20)，表示直角三角形直角边的长度，即“*”的数量，也表示输出行数。
{
	int input = 0;
	while (scanf("%d", &input) == 1)// scanf接收成功后 返回1 这行代码保证了接收到了输入
	{
		for (int i = 0; i < input + 1; i++)
		{
			for (int j = 0; j < input - i + 1; j++)
				printf("  ");
			for (int j = 0; j < i; j++)
				printf("* ");
			printf("\n");
			printf("\n");

		}
	}
	
}

test1()//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。
{
	int input = 0;
	scanf("%d", &input);
	int n = 10;
	int sum = 0;
	while (input)
	{
		if ((input % n) % 2 == 1)
			sum = sum + n/10;
		n *= 10;
		input /= 10;
	}
	
	printf("%d\n", sum);
}

int main()
{
	test2();
	return 0;
}