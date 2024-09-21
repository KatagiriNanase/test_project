#include "complex.h"

int main()
{
    Complex c1, c2, c3;
    assign(&c1, 1, 1);
    assign(&c2, 2, -1);
    add(&c3, c1, c2);
    printf("(%.3f,%.3f)\n", c3.realpart, c3.imagpart);
    system("pause");
    return 0;
}