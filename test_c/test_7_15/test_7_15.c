#include <stdio.h>
#define N 100

test4()
{

}

int check_sys_by_union()
{
	union //��������
	{
		int i;
		char c;
	}u;
	u.i = 1;
	return u.c;
}

int check_sys_by_pointer()
{
	int a = 0x00000001;
	return *(char*)(&a);
}
test3()//�жϴ�С��
{
	//int a = 0x00000001;
	//00 00 00 01
	//��----------�� ���ڴ��ַ��
	//01 00 00 00    ��С�ˣ�
	//00 00 00 01    ����ˣ�
	int ret = check_sys_by_union();
	if (ret)
		printf("С��");
	else
		printf("���");
}

test2()
{
	union Un
	{
		int a;
		char b;
	}un;
	un.a = 0x11223344;
	un.b = 0x00;
	//printf("%u", sizeof(union Un));
	/*printf("%p\n", &un);
	printf("%p\n", &un.a);
	printf("%p\n", &un.b);*/


}
test1()
{
	enum Day
	{
		Mon=1,//1
		Tues,//2
		Wed,//3
		Thur,
		Fri,
		Sat,			
		Sun
	};
	enum Day d = Fri;
	printf("%d ", Mon);
	printf("%d ", Tues);
	printf("%d ", Wed);
}

int main()
{
	test3();
	return 0;
}