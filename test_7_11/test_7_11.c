#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse(char* left, char* right)
{
    while (right > left)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        right--;
        left++;
    }
}

void left_rotate2(char* str, int k)
{
    assert(str);
    unsigned int len = strlen(str);
    k %= len;
    reverse(str, (str + k - 1));
    reverse(str + k, str + len - 1);
    reverse(str, str + len - 1);
}

char* left_rotate1(char* str, int k)
{
    assert(str);
    char* mark = str;
    unsigned int  len = strlen(str);
    k %= len;   //让k小于字符串本身的长度 不让程序浪费时间
    while (k--)
    {
        while (*(str+1))
        {
            char tmp = *str;//两个两个交换过去
            *str = *(str + 1);
            *(str + 1) = tmp;
            str++;
        }
        str = mark;
    }
    return mark;
}
void test3()                              /*实现一个函数，可以左旋字符串中的k个字符。
                                                  例如:
                                                 ABCD左旋一个字符得到BCDA
                                                 ABCD左旋两个字符得到CDAB*/
{
    char str1[] = "ABCD";
    int k = 0;
    scanf("%d", &k);
    left_rotate2(str1, k);
    printf("%s\n", str1);
}

void test2()                                                            /*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个
                                                                              以下为4个嫌疑犯的供词 :
                                                                              A说:不是我。              killer != 'a'
                                                                              B说 : 是C。                 killer =='c'
                                                                              C说 : 是D。                killer == 'd'
                                                                              D说 : C在胡说             killer !='d'
                                                                              已知3个人说了真话，1个人说的是假话          判断相加为3           */
{
    for (char killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer !=  'd')  == 3)
            printf("%c\n", killer);
    }
}

void test1()                                           /*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果:
                                                               A选手说:B第二，我第三;
                                                               B选手说:我第二，E第四;
                                                               C选手说:我第一，D第二;
                                                               D选手说:C最后，我第三;
                                                               E选手说:我第四，A第一;
                                                               比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。*/
{ 
    int a = 0;
    int b = 0; 
    int c = 0;
    int d = 0;
    int e = 0;
    for (int a = 1; a <=5; a++)
    {
        for (int b = 1; b <=5; b++)
        {
            for (int c = 1; c <= 5; c++)
            {
                for (int d = 1; d <= 5; d++)
                {
                    for (int e = 1; e <=5; e++)
                    {
                        if (   ((b == 2) + (a == 3) == 1)
                            && ((b == 2) + (e == 4) == 1)
                            && ((c == 1) + (d == 2) == 1)
                            && ((c == 5) + (d == 3) == 1)
                            && ((e == 4) + (a == 1) == 1))
                        {
                            if (a * b * c * d * e == 120)
                                printf("%d %d %d %d %d\n", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }

}


int main()
{
	test3();
	return 0;
}