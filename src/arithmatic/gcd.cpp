/*
 * gcd.c
 * GILANG SATRIA PRAYOGA 23512153
 */

#include <stdio.h>
#include "gcd.h"

int gcd(int a,int b){
	int q,r;
	if(b>a){
		return 0;
	}
	while(b>0){
		q=a/b;
		r=a-(q*b);
		a=b;
		b=r;
	}
	return a;
}
