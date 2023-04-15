#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int numero,i;
	srand(time(0));
	FILE* archivo = fopen("datos/descendente.txt", "wt");
	numero=1000000;
	printf("%d\n",numero);
	for (i=numero; i>0; i--)
		//printf("%d\n",i);
		fprintf(archivo, "%d\n", i);
	fclose(archivo);
	return 0;
}