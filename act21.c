
#include <stdio.h>
#include <omp.h>

void tareaGenerada(){
	printf(" Soy hilo %d y realizo la tarea tarea generada generare tarea 2 \n", omp_get_thread_num() );

	#pragma omp task
	{
		printf("Soy hilo %d y genere la tarea 2 \n ", omp_get_thread_num() );
	}
}

int main(){

	int i;

	#pragma omp parallel 
	{

		#pragma omp simple
		{
			printf("Soy hilo %d y genero una tarea\n ", omp_get_thread_num() );

			#pragma omp task
			{
				tareaGenerada();
			}
		}
	}
}