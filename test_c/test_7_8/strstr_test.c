#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//ģ��strstr
char* my_strstr(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* begin2 = (char*)str2;
	while (*str1)
	{
		if (*str1 == *str2)  //�����ͬ���Ϳ�ʼ�Ƚ�
		{
			const char* begin1 = str1;
			while (*begin2)
			{
				if (*begin1 == *begin2)
				{
					begin1++;
					begin2++;
				}
				else     //��������ȵ�������˳��Ƚ�
					break;
			}
			if (*begin2 == '\0')//����Ϊstr2Ϊ\0��ԭ���������ľͷ��ص�ַ
				return str1;
		}
		begin2 = (char*)str2;//����begin2_cpy
		str1++;
	}
	return NULL;

}


