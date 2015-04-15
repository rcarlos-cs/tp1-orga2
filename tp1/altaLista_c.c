#include "altaLista.h"






/** Funciones Auxiliares ya implementadas en C **/

bool string_iguales( char *s1, char *s2 ){
   int i = 0;
   while( s1[i] == s2[i] ){
      if( s1[i] == 0 || s2[i] == 0 )
         break;
      i++;
   }
   if( s1[i] == 0 && s2[i] == 0 )
      return true;
   else
      return false;
}

void insertarAtras( altaLista *l, void *dato ){
	nodo *nuevoNodo = nodoCrear( dato );
    nodo *ultimoNodo = l->ultimo;
    if( ultimoNodo == NULL )
        l->primero = nuevoNodo;
    else
        ultimoNodo->siguiente = nuevoNodo;
    nuevoNodo->anterior = l->ultimo;
    l->ultimo = nuevoNodo;
}



/*Funciones implementadas en c, a modo de psuedocodigo*/

// Funciones auxiliares
/*
unsigned char string_longitud( char *s ){
	 //  Funcion que retorna la cantidad de caracteres de el string s*
	int i = 0;
	while(s[i] != 0){ // mientras no sea fin del string
		i = i+1;
	}
	return i;
}
*/

/*
char *string_copiar( char *s ){
	// los string se representan 
	//['c','a','r','l','o','s',''] ==[99,97,114,108,111,115,0]
	
	unsigned char n = string_longitud(s) + 1;
	char *copia = (char *)malloc(n * sizeof(char));
	unsigned int i = 0;
	while(s[i] != 0){
		copia[i] = s[i];
		i = i+1;
	}
	copia[i] = s[i]; // pongo en caracter de fin de linea caracter, aunque segun mis tes esta implicito
	//printf("%d \n", copia[i-1]);
	return copia;
}
*/

/*
bool string_menor( char *s1, char *s2 ){
	
	unsigned int i = 0;
	while( s1[i] == s2[i] ){
		if( s1[i] == 0 || s2[i] == 0 )
		break;
		i++;
   }
	if( s1[i] == 0 && s2[i] == 0 ){ // Caso s1 y s2 son ambos iguales, entonces nos son menores
		return false;
	}else if (s1[i] == 0 || s2[i] == 0){ // caso s1 o s2 es menor  en longitud string
		return s1[i]==0;
	}else{ // caso en el que difieren en el caracter s1[i], s2[2]
		return s1[i] < s2[i];
	}	
}
*/

// Funciones de alumno

/*
estudiante *estudianteCrear( char *nombre, char *grupo, unsigned int edad ){
	estudiante *newEstudent = (estudiante*) malloc(sizeof(estudiante)); // pido memoria para el struct estudiante
	
	//printf("struct estrudiante\t%d bytes \n", (int) sizeof(estudiante));
	
	char *nameCopy = string_copiar(nombre);
	newEstudent->nombre = nameCopy;
	char *groupCopy = string_copiar(grupo); 
	newEstudent->grupo = groupCopy;
	newEstudent->edad = edad;
	return newEstudent;
}
*/
/*
void estudianteBorrar( estudiante *e ){
	free(e->nombre);
	free(e->grupo);
	free(e);
}
*/
/*
bool menorEstudiante( estudiante *e1, estudiante *e2 ){
	if ( string_iguales(e1->nombre,e2->nombre) ){ // si e1->nombre == e2->nombre
		// si e1->edad =< e2->edad
		return e1->edad <= e2->edad;
	}else{
			return string_menor(e1->nombre,e2->nombre);
	}
}
*/
/*
void estudianteConFormato( estudiante *e, tipoFuncionModificarString f ){
	
}
*/

// Funciones de lista


/*
nodo *nodoCrear( void *dato ){
	nodo *nuevo =(nodo*)malloc ( sizeof(nodo) );; //sizeof(nodo) == 24
	nuevo->siguiente = NULL;
	nuevo->anterior = NULL;
	nuevo->dato = dato;
	return nuevo;
}
*/
/*
void nodoBorrar( nodo *n, tipoFuncionBorrarDato f ){
	f(n->dato);
	free(n);
}
*/
/*
altaLista *altaListaCrear( void ){
	altaLista* newList = (altaLista*) malloc(sizeof(altaLista));
	newList->primero = NULL;
	newList->ultimo = NULL;
	return newList;
}
*/
/*
void altaListaBorrar( altaLista *l, tipoFuncionBorrarDato f ){
	f(l->primero);
	f(l->ultimo);
	free(l);
}
*/
