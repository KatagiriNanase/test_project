#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int test7()//以二进制读入
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = { "sorakado",18,165 };
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fread(&s, sizeof(struct S), 1, pf);
	printf("%s %d %d\n", s.name, s.age, s.height);
	fclose(pf);
	pf = NULL;
	return 0;
}

int test6()//以二进制写入
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = { "sorakado",18,165};
	FILE* pf = fopen("test.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fwrite(&s, sizeof(struct S), 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}


int test5()//格式化输入函数
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = { 0 };

	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fscanf(pf, "%s %d %d\n", s.name, &(s.age), &(s.height));//读取数据
	//printf("%s %d %d\n", s.name, s.age, s.height);
	fprintf(stdout, "%s %d %d\n", s.name,s.age, s.height);

	fclose(pf);
	pf = NULL;
	return 0;
}


int test4()//格式化输出函数
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = {"sorakado",18,165};
	
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fprintf(pf, "%s %d %d\n", s.name, s.age, s.height);

	fclose(pf);
	pf = NULL;
	return 0;
}



int test3()//读一行数据
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		//printf("%s\n", strerror(errno));
		perror("fopen");
		return 1;
	}
	//读数据
	char str[20] = { 0 };
	fgets(str, 20, pf);
	printf(str);



	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

int test2()//写一行数据
{
	FILE* pf=fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//写数据
	fputs("Hello World\n", pf);
	fputs("Hello World\n", pf);



	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

int test1()//打开文件、读写字符
{
	FILE* pf = fopen("test.txt", "w");
	//FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//…………、
	//写文件
	char i = 'a';
	for (i = 'a'; i <= 'z'; i++)
		fputc(i, pf);
	fclose(pf);
	pf = NULL;
	//读文件
	pf = fopen("test.txt", "r");
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
		printf("%c", ch);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

int main()
{
	test7();
	return 0;
}
