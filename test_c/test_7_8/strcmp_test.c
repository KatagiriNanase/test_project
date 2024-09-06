#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_strcmp(const char* str1,const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;

	}
	int ret = *str1 - *str2;
	return ret;

}
int main()
{
	char arr1[] = "a  b  c  d ";
	char arr2[] = "a  b  c  d ";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
		printf(">\n");
	else if (ret == 0)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}