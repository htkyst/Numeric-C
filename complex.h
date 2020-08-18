#ifndef _Complex_H_
#define _Complex_H_

typedef struct Complex
{
	double re, im;
} 
Complex;

inline Complex complex(double re, double im)
{
	Complex c;
	c.re = re;
	c.im = im;
	return c;
}

/* Complex number addition */
Complex Cadd(Complex a, Complex b);

/* Complex number subtraction */
Complex Csub(Complex a, Complex b);

/* Complex number multiplication */
Complex Cmul(Complex a, Complex b);

/* Create Complex */
Complex Ccomplex(double re, double im);

/* Complex conjugate */
Complex Cconjg(Complex z);

/* Complex number division */
Complex Cdiv(Complex a, Complex b);

/* Absolute Complex */
double Cabs(Complex z);

/* Square Complex */
Complex Csqrt(Complex z);

/* Multiplication real and Complex numbers */
Complex RCmul(double x, Complex a);

/* Print Complex number */
void print_complex(Complex z);

#endif // _Complex_H_