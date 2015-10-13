#include <stdio.h>
#include <stdlib.h>
#ifndef hash_h
#include "Hash_enca.h"
#define hash_h
#endif

void imprimir(Nodo *tabla[TAMANO]){
	int contador,flag;
	Nodo *aux;
	FILE* fichero;
	char columna[80] = "C:\\datos.txt";
	char fila[2000];
	fichero = fopen ("C:\\datos.txt", "r+");
	for(contador=0; contador<TAMANO; contador++){
		impresion(tabla);
		flag=0;
		aux=tabla[contador];
		while(flag =0){
			if(aux->clave==NULL){
				flag=1;
			}else{
				fprintf(fichero, "%i %s %s %i %i\n",tabla[contador]->clave->year, tabla[contador]->clave->region, tabla[contador]->clave->month, tabla[contador]->clave->conexiones, tabla[contador]->clave->identificador);
				aux=aux->sgt_dato;
			}
		}
	}
	fclose(fichero);
}

int main(){
	Clave *clave;
	Nodo *tabla[TAMANO];
	*tabla=inicializa_tabla();
	int aux_year, aux_conexiones, aux_conexiones2, aux_hash;
	char aux_region[3], aux_month[2], basura;
	char fila[80];
	FILE* fichero;
	fichero = fopen ("C:\\conexiones2.txt", "r");
	while (feof(fichero)==0){
		fgets(fila, 80, (fichero));
		fscanf(fichero,"%i	%s %s %d %c %d",&aux_year,&aux_region,&aux_month,&aux_conexiones,&basura,&aux_conexiones2);
		aux_conexiones=aux_conexiones*1000+aux_conexiones2;
		aux_hash=hash(aux_conexiones);
		clave=inicializa_clave(aux_year, aux_region, aux_month, aux_conexiones, aux_hash);
		tabla[aux_hash]=completar_tabla_encadenada(tabla,clave,aux_hash);
		}
	fclose(fichero);
	imprimir(tabla);
}
