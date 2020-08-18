#include "complex.h"
#include <math.h>
#include <stdio.h>

Complex Cadd(Complex a, Complex b)
{
	Complex c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

Complex Csub(Complex a, Complex b)
{
	Complex c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

Complex Cmul(Complex a, Complex b)
{
	Complex c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.im * b.re + a.re * b.im;
	return c;
}

Complex Ccomplex(double re, double im)
{
	Complex c;
	c.re = re;
	c.im = im;
	return c;
}

Complex Cconjg(Complex z)
{
	Complex c;
	c.re = z.re;
	c.im = -z.im;
	return c;
}

Complex Cdiv(Complex a, Complex b)
{
	Complex c;
	double r, den;
	if (fabs(b.re) >= fabs(b.im)) {
		r = b.im / b.re;
		den = b.re + r * b.im;
		c.re = (a.re + r * a.im) / den;
		c.im = (a.im - r * a.re) / den;
	}
	else {
		r = b.re / b.im;
		den = b.im + r * b.re;
		c.re = (a.re * r + a.im) / den;
		c.im = (a.im * r - a.re) / den;
	}
	return c;
}

double Cabs(Complex z)
{
	double x, y, ans, temp;
	x = fabs(z.re);
	y = fabs(z.im);
	if (x == 0.0)
		ans = y;
	else if (y == 0.0)
		ans = x;
	else if (x > y) {
		temp = y / x;
		ans = x * sqrt(1.0 + temp * temp);
	}
	else {
		temp = x / y;
		ans = y * sqrt(1.0 + temp * temp);
	}
	return ans;
}

Complex Csqrt(Complex z)
{
	Complex c;
	double x, y, w, r;
	if ((z.re == 0.0) && (z.im == 0.0)) {
		c.re = 0.0;
		c.im = 0.0;
	}
	else {
		x = fabs(z.re);
		y = fabs(z.im);
		if (x >= y) {
			r = y / x;
			w = sqrt(x) * sqrt(0.5 * (1.0 + sqrt(1.0 + r * r)));
		}
		else {
			r = x / y;
			w = sqrt(y) * sqrt(0.5 * (r + sqrt(1.0 + r * r)));
		}
		if (z.re >= 0.0) {
			c.re = w;
			c.im = z.im / (2.0 * w);
		}
		else {
			c.im = (z.im >= 0.0) ? w : -w;
			c.re = z.im / (2.0 * c.im);
		}
	}
	return c;
}

Complex RCmul(double x, Complex a)
{
	Complex c;
	c.re = x * a.re;
	c.im = x * a.im;
	return c;
}

void print_complex(Complex z)
{
	printf("[%lf, %lf]\n", z.re, z.im);
}