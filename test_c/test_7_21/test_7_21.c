#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int test3()//文件读取结束_二进制形式
{
	FILE* pf = fopen("test.txt", "wb");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}
	char str[12] = "hello world";
	fwrite(str, 1, 12, pf);
	fclose(pf);
	pf = NULL;
	pf = fopen("test.txt", "rb");
	if(!pf)
	{
		perror("fopen");
		return 1;
	}
	char str2[12] = { 0 };
	if (fread(str2, 1, 12, pf) == 12)
	{
		printf("read sucessfully,contents:%s\n",str2);
	}
	else//读取错误
	{
		if (feof(pf))
		{
			printf("Error reading test.bin:unexpected end of file\n");
		}
		else if (ferror(pf))
		{
			printf("Error reading test.bin");
		}
		return 1;
	}
	fclose(pf);
	pf = NULL;
	return 0;

}


int test2()//文件的读取结束_文本形式
{
	FILE* pf = fopen("test.txt", "r");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)//让fgetc读完
	{
		putchar(ch);
	}
	if (ferror(pf))//如果有读取错误的话，fgetc会将error放入ferror中，否则ferror返回零（假）
		printf("I/O error when reading");
	else if (feof(pf))//如果读取成功，fgetc会将eof的指示放入feof中，让其返回非零数
		printf("End of file reached successfully");
	fclose(pf);
	pf = NULL;
	return 0;
}

int test1()
{
	FILE* pf = fopen("test.txt", "wb");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}
	int a = 10000;
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;
	return 0;
}
int main()
{
	test3();
	return 0;
}