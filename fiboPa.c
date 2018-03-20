//fiboPa.c
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

long fibo(int n);

int main(int argc, char *argv[]){
	int n;
	long fi;
	printf("Dime hasta que numero quieres que calcule la serie: ");
	scanf("%d",&n);
	#pragma omp parallel
	{
		fi = fibo(n);
	}
	if(fi==-1){
		return 0;
	}else
		printf("la serie es: %.2ld\n", fi);
	return 0;
}

long fibo(int n){
	long f1, f2;
	if(n<=1)
		return n;
	if(n<36){
		#pragma omp task shared(f1)
			f1=fibo(n-1);
		#pragma omp task shared(f2)
			f2 =fibo(n-2);
		#pragma omp taskwait 
			return f1 + f2;
	}else{
		printf("Awantaaaaa :,(\n");
		return -1;
	}
}