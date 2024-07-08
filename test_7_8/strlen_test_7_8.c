#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//Ä£Äâstrlen
size_t my_strlen(const char* str)
{

	const char* begin = str;
	assert(str != NULL);
	while ((*str) != '\0')
	{
		str++;
	}
	const char* end = str;
	return end - begin;
}


int main()
{
	char arr[] = "abcdef";
	unsigned int len = my_strlen(arr);
	printf("%u\n", len);

	return 0;
}

