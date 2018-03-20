#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NRA 1000 //renglon
#define NCA 1000 //columna
#define NCB 1000 //no se

int **creaMatriz(int r, int c);
void llenaMatriz(int **m, int r, int c);
void multMatriz(int r, int c, int re, int **A, int **B,int **C);
void imprimeMatriz(int **m, int r, int c);
void libera(int **m, int r, int c);

int main(){
	int **A, **B, **C;
	A = creaMatriz(NRA, NCA);
	B = creaMatriz(NRA, NCA);
	C = creaMatriz(NRA, NCA);
	llenaMatriz(A, NRA, NCA);
	llenaMatriz(B, NRA, NCA);
    multMatriz(NRA, NCA, NCB, A, B, &*C);
    //libera(A, NRA, NCA);
    //libera(B, NRA, NCA);
    //libera(C, NRA, NCA);

    return 0;
}
void imprimeMatriz(int **m, int r, int c){
    int i, j;
    for(i=0; i<r; i++){
		for(j=0; j<c; j++)
			printf("%d", m[i][j]);
    }
}
int **creaMatriz(int r, int c){
	int i;
	int **p;
	p =(int **)malloc(r*sizeof(int *));
	for(i=0; i<r; i++)
		p[i] = (int *)malloc(c*sizeof(int));
	return p;
}

void llenaMatriz(int **m, int r, int c){
	int i, j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			m[i][j]=i;
        }
	}
}
void multMatriz(int r, int c, int re, int **A, int **B,int **C){
	int i, j, k;
	double empezar, terminar;
	//int **C;
	//#pragma omp parallel private(i,j)
	//{
		empezar = omp_get_wtime();
		//#pragma omp for
		for(i=0; i<r; i++){
			for(j=0; j<c; j++)
				for(k=0; k<re; k++)
					C[i][j] += A[i][k] * B[k][j];
		}
		terminar = omp_get_wtime();
		printf("Tiempo=%lf\n",empezar-terminar);
	//}
	//return C;
}
void libera(int **m, int r, int c){
   free(m);
}