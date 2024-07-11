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
    k %= len;   //��kС���ַ�������ĳ��� ���ó����˷�ʱ��
    while (k--)
    {
        while (*(str+1))
        {
            char tmp = *str;//��������������ȥ
            *str = *(str + 1);
            *(str + 1) = tmp;
            str++;
        }
        str = mark;
    }
    return mark;
}
void test3()                              /*ʵ��һ�����������������ַ����е�k���ַ���
                                                  ����:
                                                 ABCD����һ���ַ��õ�BCDA
                                                 ABCD���������ַ��õ�CDAB*/
{
    char str1[] = "ABCD";
    int k = 0;
    scanf("%d", &k);
    left_rotate2(str1, k);
    printf("%s\n", str1);
}

void test2()                                                            /*�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ��
                                                                              ����Ϊ4�����ɷ��Ĺ��� :
                                                                              A˵:�����ҡ�              killer != 'a'
                                                                              B˵ : ��C��                 killer =='c'
                                                                              C˵ : ��D��                killer == 'd'
                                                                              D˵ : C�ں�˵             killer !='d'
                                                                              ��֪3����˵���滰��1����˵���Ǽٻ�          �ж����Ϊ3           */
{
    for (char killer = 'a'; killer <= 'd'; killer++)
    {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer !=  'd')  == 3)
            printf("%c\n", killer);
    }
}

void test1()                                           /*5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������:
                                                               Aѡ��˵:B�ڶ����ҵ���;
                                                               Bѡ��˵:�ҵڶ���E����;
                                                               Cѡ��˵:�ҵ�һ��D�ڶ�;
                                                               Dѡ��˵:C����ҵ���;
                                                               Eѡ��˵:�ҵ��ģ�A��һ;
                                                               ����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�*/
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