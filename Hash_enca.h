#include <stdio.h>
#include <stdlib.h>
#define TAMANO 11

typedef struct _clave{
	int year;
	char region[3];
	char month[2];
	int conexiones;
	int identificador;
}Clave;


typedef struct _registro{
	Clave *clave;
	struct Registro *sgt_dato;
}Registro;

typedef struct _nodo{
	Registro *dato;
}Nodo;

Nodo *tabla[TAMANO];

Clave *inicializa_clave(int year, char region[3], char month[2], int conexiones){
	Clave *tmp;
	tmp=malloc(sizeof(Clave));
	tmp->year=year;
	tmp->region[3]=region[3];
	tmp->month[2]=month[2];
	tmp->conexiones=conexiones;
	tmp->identificador=hash(conexiones);
	return(tmp);
}

Nodo *inicializa_tabla(){
	Nodo *aux[TAMANO];
	int contador;
	for(contador=0; contador<TAMANO; contador++){
		aux[contador]=malloc(sizeof(Nodo));
		aux[contador]->dato=NULL;
		printf(" tabla completada %d  \n", contador);
	}
	return(*aux);
}


Nodo *completar_tabla_encadenada(Nodo *aux[TAMANO], Clave *tmp, int k){
	getchar();
	aux[k]->dato->clave=tmp;
	getchar();
	return(aux[k]);
}

int hash(int conexiones){
	int k;
	k=conexiones%TAMANO;
	return(k);
}
