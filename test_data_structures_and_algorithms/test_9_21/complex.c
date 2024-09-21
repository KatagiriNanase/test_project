#include "complex.h"


void assign(Complex *a, float real, float imag)
{
    a->realpart = real;
    a->imagpart = imag;
}

void add(Complex *c, Complex a, Complex b)
{
    c->realpart = a.realpart + b.realpart;
    c->imagpart = a.imagpart + b.imagpart;
}
