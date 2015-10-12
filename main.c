#include <stdio.h>
#include <stdlib.h>
//#include "Hash_enca.h"
//#include "Archivos.h"
#ifndef hash_h
#include "Hash_enca.h"
#define hash_h
#endif

int main(){
	Clave *clave;
	Nodo *tabla[TAMANO];
	*tabla=inicializa_tabla();
	int aux_year, aux_conexiones, aux_conexiones2;
	char aux_region[3], aux_month[2], basura;
	char fila[80];
	FILE* fichero;
	fichero = fopen ("D:\\conexiones.txt", "r");
	while (feof(fichero)==0){
		fgets(fila, 80, (fichero));
		fscanf(fichero,"%i	%s %s %d %c %d",&aux_year,&aux_region,&aux_month,&aux_conexiones,&basura,&aux_conexiones2);
		aux_conexiones=aux_conexiones*1000+aux_conexiones2;
		//printf("  conexiones    = %d  solo bromeo estoy aburrido\n\n", aux_conexiones);
		clave=inicializa_clave(aux_year, aux_region, aux_month, aux_conexiones);
		*tabla=completar_tabla_encadenada(*tabla, clave, aux_conexiones);
		//printf("  conexiones    = %d  solo bromeo estoy aburrido\n\n", clave->conexiones);
		getchar();
		//*tabla[]=completar_tabla_encadenada(*tabla, clave, aux_conexiones);
		//*tabla=completar_tabla_encadenada(*tabla, clave, aux_conexiones);
		printf("  conexiones    = %d  solo bromeo estoy aburrido\n\n", tabla[1]->dato->clave->identificador);
		}
	fclose(fichero);
}
