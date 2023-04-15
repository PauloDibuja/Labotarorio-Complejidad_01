#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Probemos de Algoritmo de Ordenamiento Bubble Sort

#define MAX 1000000


int main(){
	int arr[MAX];
	FILE* datos_random = fopen("datos/aleatorio.txt", "r");
	FILE* datos_asc = fopen("datos/ascendente.txt", "r");
	FILE* datos_des = fopen("datos/descendente.txt", "r");
	FILE* resultados = fopen("medicion_primer_algoritmo.txt", "w");

	return 0;
}

