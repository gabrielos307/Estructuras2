//fibo.c
#include <stdio.h>
//#include <omp.h>
#include <stdlib.h>

long fibo(int n);

int main(int argv, char *argc[]){
	int n;
	long fi;
	printf("Dime hasta que numero quieres que calcule la serie: ");
	scanf("%d",&n);
	fi = fibo(n);
	printf("la serie es: %.2ld\n", fi);
	return 0;
}

long fibo(int n){
	if(n<=1)
		return n;
	else
		return fibo(n-1)+fibo(n-2);
}