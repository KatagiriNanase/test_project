#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的请编写程序在这样的矩阵中查找某个数字是否存在。要求:时间复杂度小于0(N);
struct point 
{
	int x;
	int y;
};
struct point find_num1(int (*arr)[3], int* row, int* col, int n)//自定义结构体以返回坐标
{
	int i = row-1;
	int j = 0;
	struct point p = {-1,-1};
	while (( i >= 0) && (j < col ))
	{
		int flag = 0;
		if (n < arr[i][j])
		{
			if (flag == 0)
				i -= 1;
			else if (flag == 1)
				return p;
		}

		else if (n > arr[i][j])//j++进来以后 如果再去i-- 就说明找不到了
		{
			j += 1;
			flag = 1;
		}

		else
		{
			p.x = i +1;
			p.y = j + 1;
			return p;
		}
	
	}
	return p;
}
int find_num2(int(*arr)[3], int* row, int* col, int n)//传参指针 返回坐标
{
	int i = *row - 1;
	int j = 0;
	
	while ((i >= 0) && (j < *col))
	{
		int flag = 0;
		if (n < arr[i][j])
		{
			if (flag == 0)
				i -= 1;
			else if (flag == 1)
			{
				*row = -1;
				*col = -1;
				return 0;
			}
				
		}

		else if (n > arr[i][j])//j++进来以后 如果再去i-- 就说明找不到了
		{
			j += 1;
			flag = 1;
		}

		else
		{
			*row = i + 1;
			*col = j + 1;
			return 1;
		}

	}
	*row = -1;
	*col = - 1;
	return 0;
}
void test2()
{
	int arr[3][3] = { 1,2,3,4,5,7,8,9,10 };
	int input = 0;
	scanf("%d", &input);
	int x = 3;
	int y = 3;
	int ret  = find_num2(arr, &x, &y, input);
	printf("%d %d\n",x,y);
}
void test1()
{
	int arr[3][3] = { 1,2,3,4,5,7,8,9,10};
	int input = 0;
	scanf("%d", &input);
	struct point p=find_num1(arr,3,3,input);
	printf("%d %d\n", p.x, p.y);
	
}

int main()
{
	test2();
	return 0;
}