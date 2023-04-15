#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int numero,i;
	srand(time(0));
	FILE* archivo = fopen("datos/ascendente.txt", "wt");
	numero=1000000;
	printf("%d\n",numero);
	for (i=0; i< numero; i++)
		//printf("%d\n",i);
		fprintf(archivo, "%d\n", i);
	fclose(archivo);
	return 0;
}