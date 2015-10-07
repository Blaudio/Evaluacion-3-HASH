#include <stdio.h>
#include <stdlib.h>
//#include "Hash_enca.h"
#include "Hash_dir.h"
//#define TAMANO 9

int main(){
	Clave *clave;
//	Nodo *tabla[TAMANO];//hash_enca
	Registro *tabla[TAMANO];//hash_dir
	int k;
	clave=inicializa_clave();
	tabla[TAMANO]=inicializa_tabla();
//	k=hash(clave);//hash_enca
	k=hash(tabla[TAMANO],clave, 0);//hash_dir
	printf("%i\n",k);
	//llenar_tabla(tabla[TAMANO],clave,k);
}
