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
	double res = 0;
	int i;
	//#pragma omp parallel num_threads(HILOS) for reduction(+:res)
	//{
	for(i=0;i<n;i++)
		res+=a[i]*b[i];
	*prodpunto = res;
	//}
}
