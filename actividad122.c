#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int *creaVect(int n);
void llenaVect(int *vect, int n);
void buscaMaximo(int *a, int n, int *maximo);

int main(){
	int *a;
	int *mats;
	int n = 10;
	a = creaVect(n);
	llenaVect(a, n);
	buscaMaximo(a,n,mats);
	printf("Maximo %d", *mats);
}


int *creaVect(int n){
	int *p=(int *)malloc(n*sizeof(int));
	return p;
}
void llenaVect(int *vect, int n){
	int i;
	for(i = 0; i<n; i++){
		vect[i] = 1;
	}
}
void buscaMaximo(int *a, int n, int *maximo){
		int max,i;	
		max=a[0];
		#pragma omp parallel
		{
			for(i=1;i<n;i++) {
				if(a[i]>max)
				max=a[i];
			}
		*maximo= max;
		printf("\nEl hilo %d modifica i a: %d", omp_get_thread_num(), i);
		}
}
		
