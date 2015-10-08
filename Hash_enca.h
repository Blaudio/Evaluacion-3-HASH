#include <stdio.h>
#include <stdlib.h>
#define TAMANO 501

//typedef struct _clave{
//	int año;
//	char region;
//	char mes;
//	int conexiones;
//}Clave;

//typedef struct _clave{
//	int identificador;
//}Clave;

typedef struct _clave{
	int year;
	char region;
	char month;
	int conexiones;
	int identificador;
}Clave;

//typedef struct _registro{
//	Clave *clave;
//}Registro;

typedef struct _registro{
	Clave *clave;
	struct Registro *sgt_dato
}Registro;

typedef struct _nodo{
	Registro *dato;
	//struct Nodo *sgt_dato;
}Nodo;

Nodo *tabla[TAMANO];

Clave *inicializa_clave(int year, char region, char month, int conexiones){
	Clave *tmp;
	tmp=malloc(sizeof(Clave));
	tmp->year=year;
	tmp->region=region;
	tmp->month=month;
	tmp->conexiones=conexiones;
	tmp->identificador=hash(conexiones);
	return(tmp);
}

//int año, char region, char mes, int conexiones

//Nodo *inicializa_tabla(){
//	Nodo *aux[TAMANO];
//	aux[TAMANO]=malloc(sizeof(Nodo));
//	aux[TAMANO]->dato=NULL;
//	aux[TAMANO]->sgt_dato=NULL;
//	return(aux[TAMANO]);
//}

Nodo *inicializa_tabla(){
	Nodo *aux[TAMANO];
	aux[TAMANO]=malloc(sizeof(Nodo));
	aux[TAMANO]->datos=NULL;
//	aux[TAMANO]->sgt_dato=NULL;
	return(aux[TAMANO]);
}

//Nodo *completar_tabla(Nodo *aux[TAMANO], Clave *tmp){
//	int k;//realizado;
//	k=tmp->identificador;
//	realizado=0;
//	if(aux[k]->dato==NULL){
//		aux[k]->dato->clave=tmp;
//		return(aux[TAMANO]);
//	}else{
//		//return(completar_tabla(aux[k]->sgt_dato,tmp))
//	}
//}

Nodo *completar_tabla_encadenada(Nodo *aux[TAMANO], Clave *tmp, int k){
	
}

int hash(int conexiones){
	int k;
	k=conexiones%TAMANO;
	return(k);
}
