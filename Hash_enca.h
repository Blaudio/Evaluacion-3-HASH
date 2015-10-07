#include <stdio.h>
#include <stdlib.h>
#define TAMANO 9

typedef struct _clave{
	int identificador;
}Clave;

typedef struct _registro{
	Clave clave;
}Registro;

typedef struct _nodo{
	Registro datos;
	struct Nodo *sgt_dato;
}Nodo;

Nodo *tabla[TAMANO];

Clave *inicializa_clave(){
	Clave *tmp;
	tmp=malloc(sizeof(Clave));
	tmp->identificador=0;
	return(tmp);
}

Nodo *inicializa_tabla(){
	Nodo *tmp[TAMANO];
	tmp[TAMANO]=malloc(sizeof(Nodo));
	//tmp[TAMANO]->datos=NULL;
	tmp[TAMANO]->sgt_dato=NULL;
	return(tmp[TAMANO]);
}

int hash(Clave *tmp){
	int k;
	k=tmp->identificador;
	return(k%TAMANO);
}
