#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Probemos de Algoritmo de Ordenamiento Bubble Sort

#define N 1000000

void Inicializar_Arreglo(int arr[], int size, const char *filename);

int main(){
	printf("LOL");
	int arr[N];
	//FILE* simple;
	printf("Antes de iniciar Funcion.\n");
	Inicializar_Arreglo(arr, N, "datos/aleatorio.txt");
	printf("Fin");
	//fclose(simple);
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
		printf("%d\n", numero);
        arr[i] = numero;
    }
	fclose(entrada);
}