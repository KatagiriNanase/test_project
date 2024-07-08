#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//Ä£Äâstrcpy
char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* begin = dest;
	while (*dest++ = *src++)
		;

	*dest = *src;
	return begin;
}
int main()
{
	char des[20] = "";
	char src[] = "sorakado";
	my_strcpy(des, src);
	printf("%s\n", des);
	return 0;
}
