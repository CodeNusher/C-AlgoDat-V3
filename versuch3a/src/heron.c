/*
 * heron.c
 *
 *  Created on: 28.09.2019
 *      Author: pliss
 *
 *
 *      Quadratwurzel einer positiven Ganzzahl
 */

#include <stdio.h>
#include "heron.h"

double myAbs(double val){
	return (val < 0) ? -val : val;
}

double heron(unsigned n)
{
	int i = 0;
	double resultOld = n, result = 1.;
	while(myAbs((result - resultOld)) >= EPSILON && i <= 30)
	{
		resultOld = result;
		result = (resultOld + (n / resultOld)) * 0.5;
		++i;
		printf("\nIteration %d : %f -> %f", i, resultOld, result);
		fflush(stdout);
	}
	return result;
}

int main(void)
{
	unsigned n;
	printf("\nEingabe von n: ");
	fflush(stdout);
	while(scanf("%u", &n) > 0)
	{
		printf("\nQuadratwurzel von %d ist %f", n, heron(n));
		printf("\nEingabe von n: ");
		fflush(stdout);
	}

	return 0;
}

