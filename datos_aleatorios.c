#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	FILE *archivo;
	int numero,i;
	srand(time(0));
	numero = 1000000;
	printf("%d\n",numero);
	archivo = fopen("datos/aleatorio.txt",  "wt");
	int r_num;
	for (i=0; i< numero; i++)
		//printf("%d\n",rand()%100000);
		fprintf(archivo, "%d\n", rand()%1000000);
	fclose(archivo);
	printf("Fin del programa \n");
	return 0;
}