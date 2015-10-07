#include <stdio.h>
#include <stdlib.h>
#define TAMANO 9

typedef struct _clave{
	int identificador;
}Clave;

typedef struct Registro{
	Clave clave;
	int archivo;
}Registro;

Registro *tabla[TAMANO];

Clave *inicializa_clave(){
	Clave *tmp;
	tmp=malloc(sizeof(Clave));
	tmp->identificador=0;
	return(tmp);
}

Registro *inicializa_tabla(){
	Registro *tmp[TAMANO];
	tmp[TAMANO]=malloc(sizeof(Registro));
	tmp[TAMANO]->archivo=0;
//	tmp[TAMANO]->clave=NULL;
	return(tmp[TAMANO]);
}

int hash(Registro *tabla[TAMANO], Clave *tmp, int i){
	int k;
	//k=clave->identificador;
	if(tabla[hash2(tmp)]->archivo == 0){
		return(hash2(tmp));
	}
	return(hash(tabla[TAMANO],tmp,i+1));
}

int hash2(Clave *tmp){
	int k;
	k=tmp->identificador;
	return(k%TAMANO);
}
