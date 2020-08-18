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

float* vector(long nl, long nh)
{
	float* v;
	v = (float*)malloc((size_t)((nh - nl + 1 + N_END) * sizeof(float)));
	if (!v) nerror("allocation failure in vector()");
	return v - nl + N_END;
}

