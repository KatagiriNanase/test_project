#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int test7()//�Զ����ƶ���
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = { "sorakado",18,165 };
	FILE* pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "rb");
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

int test6()//�Զ�����д��
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = { "sorakado",18,165};
	FILE* pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "wb");
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


int test5()//��ʽ�����뺯��
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = { 0 };

	FILE* pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fscanf(pf, "%s %d %d\n", s.name, &(s.age), &(s.height));//��ȡ����
	//printf("%s %d %d\n", s.name, s.age, s.height);
	fprintf(stdout, "%s %d %d\n", s.name,s.age, s.height);

	fclose(pf);
	pf = NULL;
	return 0;
}


int test4()//��ʽ���������
{
	struct S
	{
		char name[20];
		int age;
		int height;
	}s = {"sorakado",18,165};
	
	FILE* pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "w");
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



int test3()//��һ������
{
	FILE* pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "r");
	if (pf == NULL)
	{
		//printf("%s\n", strerror(errno));
		perror("fopen");
		return 1;
	}
	//������
	char str[20] = { 0 };
	fgets(str, 20, pf);
	printf(str);



	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

int test2()//дһ������
{
	FILE* pf=fopen("C:\\Users\\�r��\\Desktop\\test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//д����
	fputs("Hello World\n", pf);
	fputs("Hello World\n", pf);



	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

int test1()//���ļ�����д�ַ�
{
	FILE* pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "w");
	//FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//����������
	//д�ļ�
	char i = 'a';
	for (i = 'a'; i <= 'z'; i++)
		fputc(i, pf);
	fclose(pf);
	pf = NULL;
	//���ļ�
	pf = fopen("C:\\Users\\�r��\\Desktop\\test.txt", "r");
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
		printf("%c", ch);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}

int main()
{
	test7();
	return 0;
}