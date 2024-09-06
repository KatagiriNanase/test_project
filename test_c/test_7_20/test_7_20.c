#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int test1()//fseek
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//int ch = 0;
	char ch[10] = { 0 };
	int i = 0;
	//fprintf(pf, "%s", "abcdef");
	//fscanf(pf, "%s", ch);
	//定位文件指针
	fseek(pf, 2, SEEK_SET);//定位到c
	int offset = ftell(pf);//3
	i = fgetc(pf);
	fprintf(stdout, "%c ", i);
	fprintf(stdout, "偏移量：%d\n", offset);
	//fseek(pf, 2, SEEK_CUR);//定位到f
	fseek(pf, -1, SEEK_END);
	i = fgetc(pf);
	offset = ftell(pf);//6
	fprintf(stdout, "%c ", i);
	fprintf(stdout, "偏移量：%d\n", offset);

	rewind(pf);//重置指针
	i = fgetc(pf);
	fprintf(stdout, "%c ", i);//a
	fclose(pf);
	pf = NULL;
	return 0;
}


int main()
{
	test1();
	return 0;
}