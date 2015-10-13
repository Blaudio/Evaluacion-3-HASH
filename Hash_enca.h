#include <stdio.h>
#include <stdlib.h>
#define TAMANO 501

typedef struct _clave{
	int year;
	char region[3];
	char month[2];
	int conexiones;
	int identificador;
}Clave;

typedef struct _nodo{
	Clave *clave;
	struct Nodo *sgt_dato;
}Nodo;

Nodo *tabla[TAMANO];


Clave *inicializa_clave(int year, char region[3], char month[2], int conexiones, int aux_hash){
	Clave *tmp;
	tmp=malloc(sizeof(Clave));
	tmp->year=year;
	tmp->region[0]=region[0];
	tmp->region[1]=region[1];
	tmp->region[2]=region[2];
	tmp->region[3]=region[3];
	tmp->month[0]=month[0];
	tmp->month[1]=month[1];
	tmp->month[2]=month[2];
	tmp->conexiones=conexiones;
	tmp->identificador=aux_hash;
	return(tmp);
}

Nodo *inicializa_tabla(){
	Nodo *aux[TAMANO];
	int contador;
	for(contador=0; contador<TAMANO; contador++){
		aux[contador]=malloc(sizeof(Nodo));
		aux[contador]->clave=NULL;
		aux[contador]->sgt_dato=NULL;
	}
	return(*aux);
}


Nodo *completar_tabla_encadenada(Nodo *aux, Clave *tmp, int k){
	if(aux->clave!=NULL){
		aux->clave=tmp;
		return(aux);
	}else{
		return(aux->sgt_dato=completar_tabla_encadenada(aux->sgt_dato,tmp,k));
	}
}

int hash(int conexiones){
	int k;
	k=conexiones%TAMANO;
	return(k);
}
