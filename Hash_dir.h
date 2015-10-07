#include <stdio.h>
#include <stdlib.h>
#define TAMANO 9

typedef struct _clave{
	int identificador;
}Clave;

typedef struct Registro{
	Clave *dato;
	int archivo;
}Registro;

Registro *tabla[TAMANO];

Clave *inicializa_clave(int k){
	Clave *tmp;
	tmp=malloc(sizeof(Clave));
	tmp->identificador=k;
	return(tmp);
}

Registro *inicializa_tabla(){
	Registro *tmp[TAMANO];
	int i;
	for(i=0;i<=TAMANO; i+1){
		tmp[i]=malloc(sizeof(Registro));
		tmp[i]->archivo=0;
		tmp[i]->dato=NULL;
	}
	return(tmp[TAMANO]);
}

//Registro hash(Registro *tabla[TAMANO], Clave *tmp, int i){
//	int k;
//	k=hash2(tmp)+i;
//	  if(tabla[k]->archivo == 0){
//		return(tabla[k]->clave=tmp);
//	}
//	return(hash(tabla[TAMANO],tmp,i+1));
//}

int hash(Registro *aux[TAMANO], Clave *tmp, int i){
	int k;
	k=hash2(tmp)+i;
	  if(aux[k]->dato!=NULL){
		return(k);
	}
	return(hash(aux, tmp, i++));
}

int hash2(Clave *tmp){
	int k;
	k=tmp->identificador;
	return(k%TAMANO);
}

