#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test2()//�������룬һ������(2~20)����ʾֱ��������ֱ�Ǳߵĳ��ȣ�����*����������Ҳ��ʾ���������
{
	int input = 0;
	while (scanf("%d", &input) == 1)// scanf���ճɹ��� ����1 ���д��뱣֤�˽��յ�������
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

test1()//С����ϲ�����֣�����ϲ��0��1�������ڵõ���һ���������ÿλ�������0��1�����ĳһλ���������Ͱ������1�������ż������ô�Ͱ������0������ش������õ������Ƕ��١�
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