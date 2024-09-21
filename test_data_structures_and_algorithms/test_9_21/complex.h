#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float realpart;
    float imagpart;
} Complex;

void assign(Complex *a, float real, float imag);
void add(Complex *c, Complex a, Complex b);
// void minus(Complex *a, float real, float imag);
// void multiply(Complex *a, float real, float imag);
// void divide(Complex *a, float real, float imag);


#endif