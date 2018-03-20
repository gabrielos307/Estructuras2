#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#define HILOS 2

void prodPunto(double *a, double *b, int n, double *prodpunto);
double *creaVect(int n);
void llenaVect(double *vect, int n);
void imprimeVect(double *vect, int n);
main(){
        double *a, *b, *c;
	int n = 5;
	a = creaVect(n);
	b = creaVect(n);
	//c = creaVect(n);
	llenaVect(a,n);
	llenaVect(b,n);
	prodPunto(a,b,n,c);
	imprimeVect(c, n);
		
}

double *creaVect(int n){
	double *p=(double *)malloc(n*sizeof(double));
	return p;
}
void llenaVect(double *vect, int n){
	int i;
	for(i = 0; i<n; i++){
		vect[i] = 1;
	}
}
void imprimeVect(double *vect, int n){
	int i;
	for(i=0;i<n;i++)
		printf("%f\n",vect[i]);
}

void prodPunto(double *a, double *b, int n, double *prodpunto){
	double res[HILOS];
	int i, id;
	#pragma omp parallel
	{
		id = omp_get_thread_num();
		#pragma omp for 
			for(i = 0; i<n; i++)
				res[id]+= a[i]*b[i];	
		for(i=0; i<HILOS; i++)
			*prodpunto += res[i]; 
	}
}

