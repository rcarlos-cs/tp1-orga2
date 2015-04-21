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
	f(e->nombre);
	f(e->grupo);
}
*/

/*
void estudianteImprimir( estudiante *e, FILE *file ){
	//(...)
	//Paula [LF]
	//	[HT]asado [LF]
	//	[HT] 21 [LF]
	
		//FILE *file;
		//file = fopen(f, "w");
		//
		//if (file==NULL) {fputs ("File error",stderr); exit (1);}
		
		fprintf(file, "%s\n",e->nombre);
		fprintf(file, "\t%s\n",e->grupo);
		fprintf(file, "\t%d\n",e->edad);
		fclose(file);	
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
	nodo *actual = l->primero;
	nodo *borrar= NULL;
	l->primero = NULL;
	l->ultimo = NULL;
	if ( actual != NULL ){  // si l no es una lista vacia, por ejemplo: primero ----> [5 <-> 7 <-> 8 <-> 9] <---- ultimo

		//nodo *proximo  = l->primero->siguiente;
		while( actual != NULL ){
			borrar = actual;
			actual  = actual->siguiente;
			nodoBorrar(borrar,f);
		}
	}
	free(l);
}
*/


void altaListaImprimir( altaLista *l, char *archivo, tipoFuncionImprimirDato f ){
	FILE* pFile;
	pFile = fopen(archivo, "w");
	nodo* nodoActual = l->primero;
	if (nodoActual != NULL){
		while(nodoActual != NULL){
			f(nodoActual->dato,pFile);//estudianteImprimir(nodoActual->dato);
			nodoActual = nodoActual->siguiente;
		}
	}else{
		//imprimir <vacia>
		fprintf(pFile, "<vacia>\n");
	}
	fclose(pFile);
}
/*
float edadMedia( altaLista *l ){
	nodo* actual = l->primero;
	//float res = 0;
	unsigned int cantEstudiantes = 0;
	unsigned int sumaEdades = 0;
	estudiante *e = NULL;
	if (actual != NULL){
		while(actual != NULL){
			cantEstudiantes++;
			e = actual->dato;
			sumaEdades = sumaEdades + e->edad;
			actual = actual->siguiente;
		}
		//res = (float)sumaEdades/cantEstudiantes;
		//return res;
		return (float)sumaEdades/cantEstudiantes;
	}
	return 0;
}
*/
/*
void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f ){
	nodo* actual = l->primero; 	
	nodo* antecesor = NULL;
	nodo* nuevoNodo = nodoCrear(dato);
	
	if (actual == NULL){
		// Caso en que la lista esta vacia, agrego como primero y ultimo
		l->primero = nuevoNodo;
		l->ultimo = nuevoNodo;
	}else if (f(dato,actual->dato)){
		// Caso en que actual es el primer nodo
		nuevoNodo->siguiente = actual;
		actual->anterior = nuevoNodo;
		l->primero = nuevoNodo;
	}else{
		//caso en el que agrego el nuevo nodo en el medio de la lista
		// busco donde debo poner el nodo;
		while (actual != NULL && !f(dato, actual->dato)){
			antecesor = actual;
			actual = actual->siguiente;
		}
		if ( actual == NULL){
		// caso agrego a lo ultimo de la lista
			//actual = l->ultimo;
			antecesor->siguiente = nuevoNodo ;
			nuevoNodo->anterior = antecesor;
			l->ultimo = nuevoNodo ;
		}else{
			// caso  agrego en medio, osea que dato > actual->dato
			nuevoNodo->siguiente = actual;
			nuevoNodo->anterior = antecesor;
			antecesor->siguiente = nuevoNodo;
			actual->anterior = nuevoNodo;
		}	
	}	
}
*/

/*
void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f ){
	nodo* actual = l->primero; 	
	nodo* antecesor = NULL;
	nodo* nuevoNodo = nodoCrear(dato);
	
	if (actual == NULL){
		// Caso en que la lista esta vacia, agrego como primero y ultimo
		listaVaciaInsertarNodo(l, nuevoNodo);
	}else if (f(dato,actual->dato)){
		// Caso en que actual es el primer nodo
		listaNoVaciaInsertaComoPrimero(l, actual, nuevoNodo);
	}else{
		//caso en el que agrego el nuevo nodo en el medio de la lista o en el ultimo nodo
		// busco donde debo poner el nodo;
		while (actual != NULL && !f(dato, actual->dato)){
			antecesor = actual;
			actual = actual->siguiente;
		}
		if ( actual == NULL){
		// caso agrego a lo ultimo de la lista
			//actual = l->ultimo;
			listaNoVaciaInsertaComoultimo( l, antecesor, nuevoNodo);
		}else{
			// caso  agrego en medio, osea que dato > actual->dato
			InsertaEnMedio(antecesor, nuevoNodo, actual);
		}	
	}	
}

// *****  AUXILIARES DE insertarOdenado ***** /

void listaVaciaInsertarNodo(altaLista* l, nodo* nuevo){
	// pre: la lista debe estar vacia
	l->primero = nuevo;
	l->ultimo = nuevo;
	// post: devuelve la lista con un solo elemento
}
void listaNoVaciaInsertaComoPrimero(altaLista* l, nodo* prim, nodo* nuevo){
	// pre: la lista no esta vacia, nuevo se inserta como primer nodo de la lista , donde prim = l->primero
	nuevo->siguiente = prim;
	prim->anterior = nuevo;
	l->primero = nuevo;
	// post: la lista tiene como primer nodo a nuevo
} 
void listaNoVaciaInsertaComoultimo(altaLista* l, nodo* ult, nodo* nuevo){
	// pre: la lista no esta vacia, nuevo se inserta como ultmimo nodo de la lista , donde ult = l->ultimo
	ult->siguiente = nuevo;
	nuevo->anterior = ult;
	l->ultimo = nuevo;
}
void InsertaEnMedio(nodo* antecesor, nodo* nuevo, nodo* posterior){
	nuevo->siguiente = posterior;
	nuevo->anterior = antecesor;
	antecesor->siguiente = nuevo;
	posterior->anterior = nuevo;
}

*/

void filtrarAltaLista( altaLista *l, tipoFuncionCompararDato f, void *datoCmp ){
	nodo* actual = l->primero; 	
	nodo *borrar = NULL;
	if ( actual != NULL ) { // si la lista no es vacia, borrar todos los elementos que no cumplan con f
		
		while( actual != NULL ){ // avanzar en la lista y filtrar a los nodos con la funcion f
			
			if ( ! f( actual, datoCmp) ){ // no pasa que   actual < datoCmp
				borrar = actual;
				actual = actual->siguiente; 
				deletearNodoDeLista(l,borrar); // donde borrar borra el nodo borrar y hace las uniones que hagan falta para restablecer el invariante de lista
			}else{
				actual = actual->siguiente;
			}	
		}
	
	}
}
		/****** AUXILIARES DE LA FUNCION filtrar alta lista *****/
void deletearNodoDeLista(altaLista *l, nodo* borrar){
	if (borrar->anterior == NULL && borrar->siguiente){ // caso en el que tengo que borrar el unico nodo de la lista
		l->primero = NULL;
		l->ultimo = NULL;
	}else if ( borrar->anterior == NULL) { // Caso en el que la lista tiene mas de un elemento y el elemento a borrar es el primero
		l->primero = borrar->siguiente;
	}else if (borrar->siguiente == NULL){ // Caso en el que la lista tiene mas de un elemento y el elemento a borrar es el ultimo
		l->ultimo = borrar->anterior;
	}else { // caso en el que la lista tiene mas de 3 elementos y elemento a borrar se encuentre en medio de la lista
		aislarNodoDelMedioDeLaLista(borrar);
	}
	nodoBorrar(borrar,(tipoFuncionBorrarDato)estudianteBorrar); 
}
void aislarNodoDelMedioDeLaLista(nodo *aislar){
	// Pre: Lista como minimo de 3 elementos
	nodo *antecesor =  aislar->anterior;
	nodo *sucesor = aislar->siguiente;
	antecesor->siguiente = sucesor;
	sucesor->anterior = antecesor;
	// Post: Lista esta igual solo que le sacamos el nodo aislar que se encontraba en algun lado de medio de la lista
}

	// si la lista es vacia, no modifico la lista

/*	
	if (actual == NULL){
		// si la lista es vacia, no hacemos nunguna comparacion y no se modifica la lista
	}else if (f(datoCmp,actual->dato)){
		// Caso en que actual es el primer nodo
		listaNoVaciaInsertaComoPrimero(l, actual, nuevoNodo);
	}else{
		//caso en el que agrego el nuevo nodo en el medio de la lista o en el ultimo nodo
		// busco donde debo poner el nodo;
		while (actual != NULL && !f(dato, actual->dato)){
			antecesor = actual;
			actual = actual->siguiente;
		}
		if ( actual == NULL){
		// caso agrego a lo ultimo de la lista
			//actual = l->ultimo;
			listaNoVaciaInsertaComoultimo( l, antecesor, nuevoNodo);
		}else{
			// caso  agrego en medio, osea que dato > actual->dato
			InsertaEnMedio(antecesor, nuevoNodo, actual);
		}	
	}	
}
*/
