#include <stdio.h>
#include <omp.h>

long long num_steps= 100000;
double step;
double empezar, terminar;
int main(int argc, char *argv[]){
	int id = omp_get_thread_num();
	int nth = omp_get_num_threads();
	double x, pi, sum=0.0;
	int i;	
	step = 1.0/(double)num_steps;
	empezar=omp_get_wtime();
	#pragma omp parallel private(x)
	{
		printf("Numero de hilos%d\n", nth);
		printf("El hilo %d \n", id);
		for (i=0; i<num_steps; i++)
		{
			x = (i + 0.5)*step;
			sum = sum + 4.0/(1.+ x*x);
		}

	pi = sum*step;
	terminar=omp_get_wtime();
	}
	printf("El valor de PI es %15.12f\n", pi);
	printf("El tiempo de calculo del numero pi es: %lf segundos", terminar-empezar);
	printf("El hilo %d \n", id);
	return 0;
}
