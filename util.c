#include "util.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define N_END 1
#define FREE_ARG char*

/* Numerical statndard error handler */
void nerror(char error_text[])
{
	fprintf(stderr, "Numerical run-time error...\n");
	fprintf(stderr, "%s\n", error_text);
	fprintf(stderr, "...now exiting to system...\n");
	exit(1);
}

#define TEMPLATE_VECTOR(type,nl,nh,msg)			\
		type* v;								\
		nmalloc(v,type,(nh-nl+1+N_END),msg);	\
		return v-nl+N_END;

/* Create vector */
float* vector(long nl, long nh)
{
	TEMPLATE_VECTOR(float, nl, nh, "allocation failure in vector()");
}

int* ivector(long nl, long nh)
{
	TEMPLATE_VECTOR(int, nl, nh, "allocation failure in ivector()");
}

unsigned char* cvector(long nl, long nh)
{
	TEMPLATE_VECTOR(unsigned char, nl, nh, "allocation failure in cvector()");
}

unsigned long* lvector(long nl, long nh)
{
	TEMPLATE_VECTOR(unsigned long, nl, nh, "allocation failure in lvector()");
}

double* dvector(long nl, long nh)
{
	TEMPLATE_VECTOR(double, nl, nh, "allocation failure in dvector()");
}

/* Release vector */
void free_vector(float* v, long nl, long nh)
{
	free((FREE_ARG)(v + nl - N_END));
}

void free_ivector(int* v, long nl, long nh)
{
	free((FREE_ARG)(v + nl - N_END));
}

void free_cvector(unsigned char* v, long nl, long nh)
{
	free((FREE_ARG)(v + nl - N_END));
}

void free_lvector(unsigned long* v, long nl, long nh)
{
	free((FREE_ARG)(v + nl - N_END));
}

void free_dvector(double* v, long nl, long nh)
{
	free((FREE_ARG)(v + nl - N_END));
}

/* Print vector */
void print_vector(float* v, long nl, long nh)
{
	int i;
	printf("[");
	for (i = nl; i <= nh; i++)
		printf("%f  ", v[i]);
	printf("]\n");
}

void print_ivector(int* v, long nl, long nh)
{
	int i;
	printf("[");
	for (i = nl; i <= nh; i++)
		printf("%d  ", v[i]);
	printf("]\n");
}

void print_cvector(unsigned char* v, long nl, long nh)
{
	int i;
	printf("[");
	for (i = nl; i <= nh; i++)
		printf("%c  ", v[i]);
	printf("]\n");
}

void print_lvector(unsigned long* v, long nl, long nh)
{
	int i;
	printf("[");
	for (i = nl; i <= nh; i++)
		printf("%lo  ", v[i]);
	printf("]\n");
}

void print_dvector(double* v, long nl, long nh)
{
	int i;
	printf("[");
	for (i = nl; i <= nh; i++)
		printf("%lf  ", v[i]);
	printf("]\n");
}

/* Create matrix */
float** matrix(long nrl, long nrh, long ncl, long nch)
{
	long i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	float** m;

	nmalloc(m, float*, nrow + N_END, "allocation failure 1 in matrix()");
	m += N_END;
	m -= nrl;

	nmalloc(m[nrl], float, nrow * ncol + N_END, "allocation failure 2 in matrix()");
	m[nrl] += N_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	return m;
}

double** dmatrix(long nrl, long nrh, long ncl, long nch)
{
	long i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	double** m;

	nmalloc(m, double*, nrow + N_END, "allocation failure 1 in matrix()");
	m += N_END;
	m -= nrl;

	nmalloc(m[nrl], double, nrow * ncol + N_END, "allocation failure 2 in matrix()");
	m[nrl] += N_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	return m;
}

int** imatrix(long nrl, long nrh, long ncl, long nch)
{
	long i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	int** m;

	nmalloc(m, int*, nrow + N_END, "allocation failure 1 in matrix()");
	m += N_END;
	m -= nrl;

	nmalloc(m[nrl], int, nrow * ncol + N_END, "allocation failure 2 in matrix()");
	m[nrl] += N_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	return m;
}

float** submatrix(float** a, long oldrl, long oldrh, long oldcl, long oldch,
	long newrl, long newcl)
{
	long i, j, nrow = oldrh - oldrl + 1, ncol = oldch - oldcl + 1;
	float** m;

	nmalloc(m, float*, nrow + N_END, "allocation failure in submatrix()");
	m += N_END;
	m -= newrl;

	for (i = oldrl, j = newrl; i <= oldrh; i++, j++)
		m[j] = a[i] + ncol;

	return m;
}

float** convert_matrix(float* a, long nrl, long nrh, long ncl, long nch)
{
	long i, j, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	float** m;

	nmalloc(m, float*, nrow + N_END, "allocation faulure in covert_matrix()");
	m += N_END;
	m -= nrl;

	m[nrl] = a - ncl;
	for (i = 1, j = nrl + 1; i < nrow; i++, j++)
		m[j] = m[j - 1] + ncol;

	return m;
}

/* Release matrix */
void free_matrix(float** m, long nrl, long nrh, long ncl, long nch)
{
	free((FREE_ARG)(m[nrl] + ncl - N_END));
	free((FREE_ARG)(m + nrl - N_END));
}

void free_dmatrix(double** m, long nrl, long nrh, long ncl, long nch)
{
	free((FREE_ARG)(m[nrl] + ncl - N_END));
	free((FREE_ARG)(m + nrl - N_END));
}

void free_imatrix(int** m, long nrl, long nrh, long ncl, long nch)
{
	free((FREE_ARG)(m[nrl] + ncl - N_END));
	free((FREE_ARG)(m + nrl - N_END));
}

void free_submatrix(float** b, long nrl, long nrh, long ncl, long nch)
{
	free((FREE_ARG)(b + nrl - N_END));
}

void free_convert_matrix(float** b, long nrl, long nrh, long ncl, long nch)
{
	free((FREE_ARG)(b + nrl - N_END));
}

/* Print matrix */
void print_matrix(float** m, long nrl, long nrh, long ncl, long nch)
{
	int i, j;
	printf("[\n");
	for (i = nrl; i <= nrh; i++) {
		for (j = ncl; j <= nch; j++) {
			printf("%f  ", m[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

void print_dmatrix(double** m, long nrl, long nrh, long ncl, long nch)
{
	int i, j;
	printf("[\n");
	for (i = nrl; i <= nrh; i++) {
		for (j = ncl; j <= nch; j++) {
			printf("%lf  ", m[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

void print_imatrix(int** m, long nrl, long nrh, long ncl, long nch)
{
	int i, j;
	printf("[\n");
	for (i = nrl; i <= nrh; i++) {
		for (j = ncl; j <= nch; j++) {
			printf("%d  ", m[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}


float*** f3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
{
	long i, j, nrow = nrh - nrl + 1, ncol = nch - ncl + 1, ndep = ndh - ndl + 1;
	float*** t;

	nmalloc(t, float**, nrow + N_END, "allocation failure 1 in f3tensor()");
	t += N_END;
	t -= nrl;

	nmalloc(t[nrl], float*, nrow * ncol + N_END, "allocation failure 2 in f3tensor()");
	t[nrl] += N_END;
	t[nrl] -= ncl;

	nmalloc(t[nrl][ncl], float, nrow * ncol * ndep + N_END, "allocation failure 3 in f3tensor()");
	t[nrl][ncl] += N_END;
	t[nrl][ncl] -= ndl;

	for (j = ncl + 1; j <= nch; j++)
		t[nrl][j] = t[nrl][j - 1] + ndep;
	for (i = nrl + 1; i <= nrh; i++) {
		t[i] = t[i - 1] + ncol;
		t[i][ncl] = t[i - 1][ncl] + ncol * ndep;
		for (j = ncl + 1; j <= nch; j++)
			t[i][j] = t[i][j - 1] + ndep;
	}

	return t;
}

void free_f3tensor(float*** t, long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
{
	free((FREE_ARG)(t[nrl][ncl] + ndl - N_END));
	free((FREE_ARG)(t[nrl] + ncl - N_END));
	free((FREE_ARG)(t + nrl - N_END));
}

void print_f3tensor(float*** t, long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
{
	int i, j, k;
	printf("[\n");
	for (i = nrl; i <= nrh; i++) {
		printf("[\n");
		for (j = ncl; j <= nch; j++) {
			for (k = ndl; k <= ndh; k++) {
				printf("%f  ", t[i][j][k]);
			}
			printf("\n");
		}
		printf("]\n");
	}
	printf("]\n");
}