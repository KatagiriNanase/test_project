#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//模拟strcat
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* begin = dest;
	while (*dest)
		dest++;
	while (*dest++ = *src++)
		;

	return begin;
}


//实现可自我追加的strcat
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* begin = dest;
	char* cpy_dest = dest;
	char* cpy_src = (char*)src;
	int count1 = 0;
	int count2 = 0;
	while (*dest)
	{
		dest++;
		count1++;
	}
	while (*src)
	{
		src++;
		count2++;
	}
	if (cpy_dest == cpy_src && count1 == count2)
	{
		for (int i = 0; i < count1; i++)
		{
			*dest++ = *cpy_src++;
		}
		*++dest = '\0';

	}
	else
		while (*cpy_dest++ = *cpy_src++)
			;

	return begin;
}
