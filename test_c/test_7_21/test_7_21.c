#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int test3()//�ļ���ȡ����_��������ʽ
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
	else//��ȡ����
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


int test2()//�ļ��Ķ�ȡ����_�ı���ʽ
{
	FILE* pf = fopen("test.txt", "r");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)//��fgetc����
	{
		putchar(ch);
	}
	if (ferror(pf))//����ж�ȡ����Ļ���fgetc�Ὣerror����ferror�У�����ferror�����㣨�٣�
		printf("I/O error when reading");
	else if (feof(pf))//�����ȡ�ɹ���fgetc�Ὣeof��ָʾ����feof�У����䷵�ط�����
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