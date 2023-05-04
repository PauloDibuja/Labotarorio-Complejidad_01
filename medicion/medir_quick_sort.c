#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

//Probemos de Algoritmo de Ordenamiento Bubble Sort

#define N 1000000

void Ordenar(int arr[], char *data_file, char *algoritmo_str, char *os_str, char *tipo_orden_str);

void swap(int* a, int* b);

int particion (int arr[], int bajo, int alto);

void quickSort(int arr[], int bajo, int alto);

void Inicializar_Arreglo(int arr[], int size, const char *filename);

int main(){
	printf("init");
	char so[] = "Linux";
	char algoritmo[] = "Quick Sort";
	char *forma_datos[3] = {"Ordenado", "Inverso", "Aleatorio"};
	char *data_files[3] = {"ascendente.txt", "descendente.txt", "aleatorio.txt"};

	struct timeval tf_0, tf_1; //Comentairo
	
	

	int arr[N];
	//Leer archivo de datos y guardar los datos en un array de enteros
	
	for (int i = 0; i < 3; i++){
		gettimeofday(&tf_0, NULL);
		Ordenar(arr, data_files[i], algoritmo, so, forma_datos[i]);
		gettimeofday(&tf_1, NULL);
		double execution_time = (tf_1.tv_sec - tf_0.tv_sec)*1000 + (tf_1.tv_usec - tf_0.tv_usec)/1000;
		printf("Fin del proceso de ordenamiento. [%s - %s]\n", algoritmo, forma_datos[i]);
		printf("Tiempo de ejecución: %g segundos\n\n", execution_time/1000);
	}
	printf("Fin\n");
	
	return 0;
}



void Ordenar(int arr[], char *data_file, char *algoritmo_str, char *os_str, char *tipo_orden_str){
	FILE *resultados;
	struct timeval t_0, t_1;
	double time_elapsed;
	char *data_path = "datos/";
	strcat(data_path, data_file);
	
	Inicializar_Arreglo(arr, N, data_path);

	char *path = "resultados/Quick_Sort_";
	char *csv_ext = ".csv";
	strcat(path, tipo_orden_str);
	strcat(path, csv_ext);

	resultados = fopen(path, "wt");

	printf("S.0;%s\n", os_str);
	fprintf(resultados, "S.0;%s\n", os_str);

	printf("Algoritmo;%s\n", algoritmo_str);
	fprintf(resultados, "Algoritmo;%s\n", algoritmo_str);

	printf("Forma Datos;%s\n", tipo_orden_str);
	fprintf(resultados, "Forma Datos;%s\n", tipo_orden_str);

	fprintf(resultados, "Elementos;Tiempo\n");

	for (int size_part = 10000; size_part < N; size_part += 10000)
	{
		gettimeofday(&t_0, NULL);
		quickSort(arr, 0, size_part);
		gettimeofday(&t_1, NULL);
		time_elapsed = (t_1.tv_sec - t_0.tv_sec)*1000 + (t_1.tv_usec - t_0.tv_usec)/1000;
		printf("Para %d datos, transcurrió %g segundos.\n",  size_part, time_elapsed/1000);
		fprintf(resultados, "%d;%g\n", size_part, time_elapsed/1000); 
	}
	
	fclose(resultados);
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

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int particion (int arr[], int bajo, int alto){
	int pivote, i, j;
	pivote = arr[alto];
	i = (bajo - 1);
	for (j = bajo; j <= alto- 1; j++){
		if (arr[j] <= pivote){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[alto]);
	return (i + 1);
}


void quickSort(int arr[], int bajo, int alto){
	int pi;
	if (bajo < alto){
		pi = particion(arr, bajo, alto);
		quickSort(arr, bajo, pi - 1);
		quickSort(arr, pi + 1, alto);
	}
}
