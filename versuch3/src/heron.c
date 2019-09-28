/*
 * heron.c
 *
 *  Created on: 27.09.2019
 *      Author: pliss
 *
 *  Quadratwurzel einer positiven Ganzzahl
 */


#include <stdio.h>
#include "heron.h"

double myAbs(double val){
	return (val < 0) ? -val : val;
}

double heron(unsigned n){
	myAbs(n);
	unsigned resultOld = n, result = 1;
	int i = 0;
	while((resultOld - result) > EPSILON && (i <= 20)){
		resultOld = result;
		result = (resultOld + n/resultOld) / 2;
		++i;
		printf("\nIteration %d : %.6f -> %.6f", i, resultOld, result);
	}
	return result;
}

int main(void){

	int n;
	printf("Eingabe von n: ");
	fflush(stdout);
	while(scanf("%d", &n) > 0){
		printf("\nQuadratwurzel von %d = %f", n, heron(n));
	}

	return 0;
}
