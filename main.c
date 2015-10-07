#include <stdio.h>
#include <stdlib.h>
//#include "Hash_enca.h"
#include "Hash_dir.h"

int main(){
	Clave *clave;
//	Nodo *tabla[TAMANO];//hash_enca
	Registro *tabla[TAMANO];//hash_dir
	int k;//hash_enca
	clave=inicializa_clave(6);
	tabla[TAMANO]=inicializa_tabla();
//	k=hash(clave);//hash_enca
	k=hash(tabla,clave, 0);//hash_dir
//	tabla[k]->dato=clave;//hash_dir
//	tabla[k]->dato->clave=clave;//hash_enca
	printf("%i\n",k);
	//llenar_tabla(tabla[TAMANO],clave,k);
}
