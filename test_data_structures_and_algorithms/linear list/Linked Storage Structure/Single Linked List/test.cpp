#include <iostream>
#include<cstdlib>
#include "type_definition.hpp"
using namespace std;

typedef struct stu
{
    int num;
    string name;
    stu* next;
}*pstu;

int main()
{
    pstu q,p2,p1 = new stu;
    p1->name = "sorakado";
    p1->num = 33;
    p1->next = NULL;
    p2 = p1->next;
    int i = 3, j = 0;
    if (!(p1) || !(p1->next) || j > i - 1)
        return ERROR;
    else
    {
        q = p1->next->next;
        delete p1->next;
        p1->next = q;
        return OK;
    }
    cout << p1->name << endl << p1->num << endl;
    if (!p2)
        cout << "null!" << endl;
    else
        cout << "not null!" << endl;
    system("pause");
    return 0;
}//main
