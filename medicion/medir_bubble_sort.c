#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

//Probemos de Algoritmo de Ordenamiento Bubble Sort

#define N 1000000

void Bubble_Sort(int arr[], int size);

void Inicializar_Arreglo(int arr[], int size, const char *filename);

int main(){


	struct timeval t_0, t_1;
	struct timeval tf_0, tf_1;
	
	gettimeofday(&tf_0, NULL);

	int arr[N];
	FILE *resultados;
	double time_elapsed;

	//Leer archivo de datos y guardar los datos en un array de enteros

	Inicializar_Arreglo(arr, N, "datos/descendente.txt");

	resultados = fopen("resultados/bubble_sort_invertido.csv", "wt");

	char so[] = "Linux";
	char algoritmo[] = "Bubble Sort";
	char forma_datos[] = "Invertido";

	printf("S.0;%s\n", so);
	fprintf(resultados, "S.0;%s\n", so);

	printf("Algoritmo;%s\n", algoritmo);
	fprintf(resultados, "Algoritmo;%s\n", algoritmo);

	printf("Forma Datos;%s\n", forma_datos);
	fprintf(resultados, "Forma Datos;%s\n", forma_datos);

	fprintf(resultados, "Elementos;Tiempo\n");

	for (int size_part = 10000; size_part < N; size_part += 10000)
	{
		gettimeofday(&t_0, NULL);
		Bubble_Sort(arr, size_part);
		gettimeofday(&t_1, NULL);
		time_elapsed = (t_1.tv_sec - t_0.tv_sec)*1000 + (t_1.tv_usec - t_0.tv_usec)/1000;
		printf("Para %d datos, transcurrió %g segundos.\n",  size_part, time_elapsed/1000);
		fprintf(resultados, "%d;%g\n", size_part, time_elapsed/1000); 
	}
	
	fclose(resultados);

	gettimeofday(&tf_1, NULL);

	double execution_time = (tf_1.tv_sec - tf_0.tv_sec)*1000 + (tf_1.tv_usec - tf_0.tv_usec)/1000;
	printf("Fin de ejecución.\n");
	printf("Tiempo de ejecución: %g segundos", execution_time/1000);
	return 0;
}

void Inicializar_Arreglo(int arr[], int size, const char *filename){
	printf("Iniciar Funcion.\n");

	FILE *entrada;
	char linea[100];
	int i = 0;
	entrada = fopen(filename, "r");
	for (i = 0; i < N; i++){
		int numero;
        fscanf(entrada,"%d",&numero);
        arr[i] = numero;
    }
	fclose(entrada);
}

void Bubble_Sort(int arr[], int size){
	int i,j,aux;
	for(i = 0; i < size-1; i++){
		for(j = 0; j < size-i-1; j++){
			if(arr[j+1] < arr[j]){
				aux = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = aux;
			}
		}
	} 
}