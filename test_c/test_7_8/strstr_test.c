#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//模拟strstr
char* my_strstr(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* begin2 = (char*)str2;
	while (*str1)
	{
		if (*str1 == *str2)  //如果相同，就开始比较
		{
			const char* begin1 = str1;
			while (*begin2)
			{
				if (*begin1 == *begin2)
				{
					begin1++;
					begin2++;
				}
				else     //遇到不相等的情况就退出比较
					break;
			}
			if (*begin2 == '\0')//是因为str2为\0的原因跳出来的就返回地址
				return str1;
		}
		begin2 = (char*)str2;//重置begin2_cpy
		str1++;
	}
	return NULL;

}


