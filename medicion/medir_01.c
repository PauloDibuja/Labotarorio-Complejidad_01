#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Probemos de Algoritmo de Ordenamiento Bubble Sort

#define N 1000000

void Inicializar_Arreglo(int *arr, int size, const char *filename);

int main(){
	printf("LOL");
	int arr[N];
	//FILE* simple;
	printf("Antes de iniciar Funcion.\n");
	Inicializar_Arreglo(arr, N, "datos/simple.txt");
	printf("Fin");
	//fclose(simple);
	return 0;
}

void Inicializar_Arreglo(int *arr, int size, const char *filename){
	printf("Iniciar Funcion.\n");

	FILE *entrada;
	char linea[100];
	int i = 0;

	entrada = fopen("filename", "r");
	while (fgets(linea, sizeof(linea), entrada) != NULL){
		int number;
		if(sscanf(linea, "%d", &number) == 1){
			arr[i] = number;
			if(i >= N){
				printf("Limite del array!\n");
				break;
			}
		} else {
			printf("Error en la linea: '%s'", linea);
		}
	}
	fclose(entrada);
}