#include "altaLista.h"
#include <stdio.h>
#include <stdlib.h>

// FUNCIONES TESTS PROPIOS
void tests_string_iguales();
void tests_string_longitud();
void tests_string_copiar();
void tests_string_menor();
// TESTS ESTUDIANTES
void tests_estudianteCrear();
void tests_estudianteBorrar();
void tests_memorEstudiante();
void tests_funcion_estudianteConFormato();

/* funciones para probar estudiante con formato*/
    void f( char* s ){
		s = s;
	}
    void g( char *s ){ 
		char x = 'X';
		if( s[0] != 0 ) s[0] = x; 
	}

/* fin de funciones para probar estudiante con formato*/

void tests_funcion_estudianteImprimir();
// TESTS LISTA DOBLEMENTE ENLAZADA
void tests_funcion_nodo_crear();
void tests_funcion_nodoBorrar();
void tests_funcion_altaListaCrearYBorrar();	
void tests_crear_una_lista_y_agregarle_un_elemento();
void tests_funcion_edadMedia();
void tests_funcion_insertarOrdenado();
void tests_funcion_filtrarAltaLista();
// FUNCIONES EXTERNA QUE IMPLEMENTAMOS EN ASM

//extern unsigned char string_longitud( char *s );

int main (void){
	// COMPLETAR AQUI EL CODIGO
	
	// funcione implementadas en c, archivo altaLisa_c.c
/*	
	int n = 10;
	nodo* nuevo  = nodoCrear(n);
	printf("\n siguiente: %p, anterior: %p, dato: %d \n", nuevo->siguiente, nuevo->anterior, (nuevo->dato));	
	int m = 45 ; 
	nodo* nuevo1  = nodoCrear(m);
	printf("\n siguiente: %p, anterior: %p, dato: %d \n", nuevo1->siguiente, nuevo1->anterior, (nuevo1->dato));	
*/
// TESTS DE FUNCIONES AUXILIARES
	tests_string_longitud(); // No pierde memoria
	tests_string_copiar();  // No pierde memoria
	tests_string_iguales();
	tests_string_menor();	// No pierde memoria
// TESTS DE ESTUDIANTE
	tests_estudianteCrear(); // No pierde memoria 
	tests_estudianteBorrar();
	tests_memorEstudiante();
	tests_funcion_estudianteImprimir();
	tests_funcion_estudianteConFormato();
// TESTS DE LISTA DOBLEMENTE ENLAZADA
	tests_funcion_nodo_crear();
	tests_funcion_nodoBorrar();
	
	tests_funcion_altaListaCrearYBorrar();
	tests_crear_una_lista_y_agregarle_un_elemento();
	tests_funcion_edadMedia();
	tests_funcion_insertarOrdenado();
	tests_funcion_filtrarAltaLista();
	return 0;
}

// TESTS DE FUNCIONES AUXILIARES
void	tests_string_iguales(){
	bool res  = true;
	char* c1 = "";
	char* copy1 = "";
	char* c2 = "c";
	char* copy2 = "c";
	char* c3 = "ca";
	char* copy3 = "ca";
	char* c4 = "car";
	char* copy4 = "car";
	
	// uso esto para verificar si mi funcion string_copiar es correcta
	char* copia1 = string_copiar(c1);
	char* copia2 = string_copiar(c2);
	char* copia3 = string_copiar(c3);
	char* copia4 = string_copiar(c4);
	
	res = res && string_iguales(c1,copy1);
	res = res && string_iguales(c2,copy2);
	res = res && string_iguales(c3,copy3);
	res = res && string_iguales(c4,copy4);
	
	
	res = res && string_iguales(c1,copia1);
	res = res && string_iguales(c2,copia2);
	res = res && string_iguales(c3,copia3);
	res = res && string_iguales(c4,copia4);
	
	
	if (res){
		printf("tests_string:iguales ----> %s \n", "ok");
	}else{
		printf("tests_string_iguales ----> %s \n", "error tests");
	}
	free(copia1);
	free(copia2);
	free(copia3);
	free(copia4);
}

void tests_string_longitud(){
	bool res = true;
	char *c1 = "";
	char *c2 = "c";
	char *c3 = "ca";
  	char *c4 = "car"; 
	char *c5 = "carl";
	char *c6 = "carlo";
	char *c7 = "carlos";
	char *c8 = "holaMundo";
	res = res && string_longitud(c1) == 0;
	res = res && string_longitud(c2) == 1;
	res = res && string_longitud(c3) == 2;
	res = res && string_longitud(c4) == 3;
	res = res && string_longitud(c5) == 4;
	res = res && string_longitud(c6) == 5;
	res = res && string_longitud(c7) == 6;
	res = res && string_longitud(c8) == 9;
	
	if (res){
		printf("tests_longitud_de_string ----> %s \n", "ok");
	}else{
		printf("tests_longitud_de_string ----> %s \n", "error tests");
	}
}

void tests_string_copiar(){
	bool res = true;
	char *c1 = "";
	char *c2 = "c";
	char *c3 = "ca";
  	char *c4 = "car"; 
	char *c5 = "carl";
	char *c6 = "carlo";
	char *c7 = "carlos";
	char *c8 = "holaMundo";
	char *copy1 = string_copiar(c1);
	char *copy2 = string_copiar(c2);
	char *copy3 = string_copiar(c3);
	char *copy4 = string_copiar(c4);
	char *copy5 = string_copiar(c5);
	char *copy6 = string_copiar(c6);
	char *copy7 = string_copiar(c7);
	char *copy8 = string_copiar(c8);

	//res = res && *copy1 == *c1 && copy1 !=c1;
	res = res && *copy2 == *c2 && copy2 !=c2;
	res = res && *copy3 == *c3 && copy3 !=c3;
	res = res && *copy4 == *c4 && copy4 !=c4;
	res = res && *copy5 == *c5 && copy5 !=c5;
	res = res && *copy6 == *c6 && copy6 !=c6;
	res = res && *copy7 == *c7 && copy7 !=c7;
	res = res && *copy8 == *c8 && copy8 !=c8;
	//printf("string_1_original: %s, string_2_copia: %s \n", c8, copy8);
	//printf("string_1_posicion: %p, string_2_posicion: %p\n", c8, copy8);
	if (res){
		printf("tests_copia_de_string ----> %s \n", "ok");
	}else{
		printf("tests_copia_de_string ----> %s \n", "error tests");
	}
	
	// libero esta memoria dinamica solicitada en este tests
	free(copy1); 
	free(copy2); 
	free(copy3); 
	free(copy4); 
	free(copy5); 
	free(copy6); 
	free(copy7); 
	free(copy8);
}

void tests_string_menor(){
	char *c1 = "merced";
	char *c2 = "mercurio";
	char *c3 = "perro";
	char *c4 = "zorro";
	char *c5 = "senior";
	char *c6 = "seniora";
	char *c7 = "caZa";
	char *c8 = "casa";
	char *c9 = "hola";
	char *c10 = "hola";
	char *c11 = "holamundo";
	char *c12 = "";
	bool res = true;
	res = res && string_menor(c1,c2); // (merced < mercurio) == true
	res = res && string_menor(c3,c4); // (perro < zorro) == true
	res = res && string_menor(c5,c6); // (senior < seniora) == true
	res = res && string_menor(c7,c8); // (caZa < casa) == true
	res = res && !string_menor(c9,c10); // !(hola < hola) == true
	res = res && !string_menor(c6,c5); // !(seniora < senior) == true
	res = res && !string_menor(c11,c10); // !(holamundo < hola) == true
	res = res && !string_menor(c12,c12); // !("" < "") == true
	
	if (res){
		printf("tests_string_menor ----> %s \n", "ok");
	}else{
		printf("tests_string_menor ----> %s \n", "error tests");
	}	
}
// TESTS DE ESTUDIANTE
void tests_estudianteCrear(){
	char *fede = "fede";
	char *medio = "medio";
	unsigned int ed = 19;
	estudiante *e = estudianteCrear( fede, medio,ed);
	bool res = true;
	//printf("Nombre %s, grupo %s, edad%d \n", e->nombre, e->grupo, e->edad);
	
	res = res && string_iguales(fede,e->nombre) && string_iguales(medio, e->grupo) && ed == e->edad;
	estudianteBorrar(e);

	if (res){
		printf("tests_estudiante_crear ----> %s \n", "ok");
	}else{
		printf("tests_estudiante_crear ----> %s \n", "error tests");
	}
	//BORRO AL ESTUDIANTE DE LA MEMORIA DINAMICA UTILIZADA EN ESTE TEST
}

void tests_estudianteBorrar(){
	char *fede = "fede";
	char *medio = "medio";
	unsigned int ed = 19;
	estudiante *e = estudianteCrear(fede, medio,ed);
	estudianteBorrar(e);
	if (true){
		printf("tests_borrar_estudiante ----> %s \n", "ok");
	}else{
		printf("tests_borrar_estudiante ----> %s \n", "error tests");
	}
	//printf("Nombre %s, grupo %s, edad%d \n", e->nombre, e->grupo, e->edad);
	// OBSERVACION: segun valgrin toda la memoria dinamica fue desalojada
}

void tests_memorEstudiante(){
	bool res = true;
	// Caso estudiantes distinto nombre
	char *fede = "fede";
	char *medio = "medio";
	unsigned int ed1 = 19;
	estudiante *e1 = estudianteCrear(fede, medio,ed1);

	char *miguel = "miguel";
	char *lomito = "lomito";
	unsigned int ed2 = 19;
	estudiante *e2 = estudianteCrear(miguel, lomito,ed2);
	
	// Caso estudiantes con igual nombre
	
	char *walter1 = "walter";
	char *bofe1 = "bofe";
	unsigned int ed3 = 22;
	estudiante *e3 = estudianteCrear(walter1, bofe1,ed3);
	
	char *walter2 = "walter";
	char *bofe2 = "bofe";
	unsigned int ed4 = 20;
	estudiante *e4 = estudianteCrear(walter2, bofe2,ed4);
	
	res = res && menorEstudiante(e1,e2); // distinto nombre
	res = res && !menorEstudiante(e2,e1);
	res = res && !menorEstudiante(e3,e4); // igual nombre, desempate por edad
	res = res && menorEstudiante(e4,e3);  
	
	
	if (res){
		printf("tests_funcion_menorEstudiante ----> %s \n", "ok");
	}else{
		printf("tests_funcion_menorEstudiante ----> %s \n", "error tests");
	}
	estudianteBorrar(e1);
	estudianteBorrar(e2);
	estudianteBorrar(e3);
	estudianteBorrar(e4);
}

void tests_funcion_estudianteImprimir(){
	estudiante *miEstudiante = estudianteCrear("Walter","Bofe",20);
	FILE *file ;
	file = fopen("estudianteImprimirTestsCarlos.txt","w");
	estudianteImprimir(miEstudiante, file);
	fclose(file);
	estudianteBorrar(miEstudiante);
	
	printf("tests_funcion_estudianteImprimir ----> %s \n", "ok");
}


void tests_funcion_estudianteConFormato(){
	estudiante* miEstudiante = estudianteCrear("david", "salchicha", 34);

	//void f( char* s ){}
	
	
    //printf("tests_funcion_estudianteConFormato_antes ----> %s \n", miEstudiante->nombre);
    //printf("tests_funcion_estudianteConFormato_antes ----> %s \n", miEstudiante->grupo);
    
    estudianteConFormato( miEstudiante, f );
    //printf("tests_funcion_estudianteConFormato_despues ----> %s \n", miEstudiante->nombre);
    //printf("tests_funcion_estudianteConFormato_despues ----> %s \n", miEstudiante->grupo);
    
    //void g( char *s ){ if( s[0] != 0 ) s[0] = ’X’; }
	
	estudianteConFormato( miEstudiante, g );
	
	printf("tests_funcion_estudianteConFormato_despues ----> %s \n", miEstudiante->nombre);
    printf("tests_funcion_estudianteConFormato_despues ----> %s \n", miEstudiante->grupo);
	
	estudianteBorrar(miEstudiante);

}

// TESTS DE LISTA DOBLEMENTE ENLAZADA
void tests_funcion_nodo_crear(){
	bool res = true;
	// Estudiante 1
	estudiante *e1 = estudianteCrear("nahuel", "salchicha", 23);
	nodo *n1 = nodoCrear(e1);
	estudiante *student1 = n1->dato;
	// Estudiante 2
	estudiante* e2 = estudianteCrear("ximena", "cuadril", 24);
	nodo *n2 = nodoCrear(e2);
	estudiante *student2 = n2->dato;  
	// Estudiante 3
	estudiante* e3 = estudianteCrear("faby", "asado", 18);
	nodo *n3 = nodoCrear(e3);
	estudiante *student3 = n3->dato;  
	// estudiante 4
		estudiante* e4 = estudianteCrear("emilia", "bifeDeChirizo", 18);
	nodo *n4 = nodoCrear(e4);
	estudiante *student4 = n4->dato;  

	res = res && string_iguales(student1->nombre, e1->nombre) && string_iguales(student1->grupo, e1->grupo) && student1->edad == e1->edad;
	res = res && string_iguales(student2->nombre, e2->nombre) && string_iguales(student2->grupo, e2->grupo) && student2->edad == e2->edad;
	res = res && string_iguales(student3->nombre, e3->nombre) && string_iguales(student3->grupo, e3->grupo) && student3->edad == e3->edad;
	res = res && string_iguales(student4->nombre, e4->nombre) && string_iguales(student4->grupo, e4->grupo) && student4->edad == e4->edad;
	if (res){
		printf("tests_funcion_nodoCrear ----> %s \n", "ok");
	}else{
		printf("tests_funcion_nodoCrear----> %s \n", "error tests");
	}
	nodoBorrar(n1, (tipoFuncionBorrarDato)estudianteBorrar );
	nodoBorrar(n2, (tipoFuncionBorrarDato)estudianteBorrar );
	nodoBorrar(n3, (tipoFuncionBorrarDato)estudianteBorrar );
	nodoBorrar(n4, (tipoFuncionBorrarDato)estudianteBorrar );
}
void tests_funcion_nodoBorrar(){
	bool res = true;
	estudiante *miEstudiante1 = estudianteCrear("nahuel", "salchicha", 23);
	nodo *miNodo1 = nodoCrear(miEstudiante1); // creo mi nodo com miEstudiante
	nodoBorrar( miNodo1, (tipoFuncionBorrarDato)estudianteBorrar );
	if (res){
		printf("tests_funcion_nodoBorrar ----> %s \n", "ok");
	}else{
		printf("tests_funcion_nodoCrear----> %s \n", "error tests");
	}
}
void tests_funcion_altaListaCrearYBorrar(){
	bool res = true;
	altaLista *newList = altaListaCrear();
	altaListaBorrar(newList, (tipoFuncionBorrarDato)free);
	if (res){
		printf("tests_funcion_altaListaCrearYBorrar ----> %s \n", "ok");
	}else{
		printf("tests_funcion_altaListaCrearYBorrar ----> %s \n", "error tests");
	}
}

void tests_crear_una_lista_y_agregarle_un_elemento(){
	
	altaLista *miAltaLista = altaListaCrear();
	altaLista *miAltaListaVacia = altaListaCrear();
	altaLista *miAltaListaConUnElemento = altaListaCrear();
	// iserto de manera ordenada los estudiantes
	
	insertarAtras( miAltaListaConUnElemento, estudianteCrear( "eduardo", "chinchulin", 46 ) );
	
	insertarAtras( miAltaLista, estudianteCrear( "eduardo", "chinchulin", 46 ) );
	insertarAtras( miAltaLista, estudianteCrear( "juan", "salchicha", 45 ) );
	insertarAtras( miAltaLista, estudianteCrear( "juanita", "bife", 78 ) );
	insertarAtras( miAltaLista, estudianteCrear( "leila", "entrania", 26 ) );
	insertarAtras( miAltaLista, estudianteCrear( "marcela", "rueda", 45 ) );
	insertarAtras( miAltaLista, estudianteCrear( "mariana", "vacio", 1 ) );
	insertarAtras( miAltaLista, estudianteCrear( "mario", "asado", 23 ) );
	insertarAtras( miAltaLista, estudianteCrear( "miguel", "entrania", 2 ) );
	insertarAtras( miAltaLista, estudianteCrear( "tomas", "molleja", 14 ) );
	
	char *salidaTestListaNoVacia = "salidaTestListaNoVacia.txt";
	char *salidaTestListaVacia = "salidaTestListaVacia.txt";
	char *salidaTestListaConUnElemento = "salidaTestListaConUnElemento.txt";
	
	altaListaImprimir( miAltaListaVacia, salidaTestListaVacia, (tipoFuncionImprimirDato)estudianteImprimir );
	altaListaImprimir( miAltaLista, salidaTestListaNoVacia, (tipoFuncionImprimirDato)estudianteImprimir );
	altaListaImprimir( miAltaListaConUnElemento, salidaTestListaConUnElemento, (tipoFuncionImprimirDato)estudianteImprimir );
	printf("tests_crear_una_lista_y_agregarle_un_elemento ----> %s \n", "ok");	
	altaListaBorrar( miAltaLista, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	altaListaBorrar( miAltaListaVacia, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	altaListaBorrar( miAltaListaConUnElemento, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
}
void tests_funcion_edadMedia(){
	bool res = true;
	altaLista *miAltaLista = altaListaCrear();
	altaLista *miAltaListaVacia = altaListaCrear();
	altaLista *miAltaListaConUnElemento = altaListaCrear();
	// iserto de manera ordenada los estudiantes
	
	insertarAtras( miAltaListaConUnElemento, estudianteCrear( "eduardo", "chinchulin", 5 ) );
	
	insertarAtras( miAltaLista, estudianteCrear( "eduardo", "chinchulin", 46 ) );
	insertarAtras( miAltaLista, estudianteCrear( "juan", "salchicha", 45 ) );
	insertarAtras( miAltaLista, estudianteCrear( "juanita", "bife", 78 ) );
	insertarAtras( miAltaLista, estudianteCrear( "leila", "entrania", 27  ) );
	insertarAtras( miAltaLista, estudianteCrear( "marcela", "rueda", 45 ) );
	//insertarAtras( miAltaLista, estudianteCrear( "mariana", "vacio", 1 ) );
	//insertarAtras( miAltaLista, estudianteCrear( "mario", "asado", 23 ) );
	//insertarAtras( miAltaLista, estudianteCrear( "miguel", "entrania", 2 ) );
	//insertarAtras( miAltaLista, estudianteCrear( "tomas", "molleja", 14 ) );
	
		
	res = res && edadMedia(miAltaListaVacia) == 0;
	res = res && edadMedia(miAltaListaConUnElemento) == 5;
	res = res && edadMedia(miAltaLista) == 48.2f; // 241/5 == 48.2
	//printf( "edadMedia = %2.5f\n", edadMedia(miAltaLista ) );
	if (res) {
		printf("tests_funcion_edadMedia ----> %s \n", "ok");	
	}else{
		printf("tests_funcion_edadMedia ----> %s \n", "error");	
	}	
	//printf( "edadMedia = %2.5f\n", edadMedia( miAltaLista ) );
	altaListaBorrar( miAltaLista, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	altaListaBorrar( miAltaListaVacia, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	altaListaBorrar( miAltaListaConUnElemento, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista

}

void tests_funcion_insertarOrdenado(){
	//bool res = true;
	altaLista *miAltaLista = altaListaCrear();
	//altaLista *miAltaListaVacia = altaListaCrear();
	altaLista *miAltaListaConUnElemento = altaListaCrear();
	// iserto de manera ordenada los estudiantes
	
	insertarOrdenado( miAltaListaConUnElemento, estudianteCrear( "eduardo", "chinchulin", 5 ), (tipoFuncionCompararDato)menorEstudiante );

	altaListaImprimir(miAltaListaConUnElemento, "InsertarOdenadoConUnSoloEstudiante.txt", (tipoFuncionImprimirDato)estudianteImprimir );

	insertarOrdenado( miAltaLista, estudianteCrear( "miguel", "entrania", 2 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "leila", "entrania", 27  ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "mario", "asado", 23 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "juanita", "bife", 78 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "marcela", "rueda", 45 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "juan", "salchicha", 45 ), (tipoFuncionCompararDato)menorEstudiante );	
	insertarOrdenado( miAltaLista, estudianteCrear( "tomas", "molleja", 14 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "eduardo", "chinchulin", 46), (tipoFuncionCompararDato)menorEstudiante);
	insertarOrdenado( miAltaLista, estudianteCrear( "mariana", "vacio", 1 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "mariana", "vacio", 8 ), (tipoFuncionCompararDato)menorEstudiante );

	altaListaImprimir(miAltaLista, "InsertarOdenadoConUnMasDeUnEstudiante.txt", (tipoFuncionImprimirDato)estudianteImprimir );


	altaListaBorrar( miAltaLista, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	//altaListaBorrar( miAltaListaVacia, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	altaListaBorrar( miAltaListaConUnElemento, (tipoFuncionBorrarDato)estudianteBorrar ); // aca borro la lista
	printf("tests_funcion_isertarOrdenado ----> %s \n", "ok");
}

void tests_funcion_filtrarAltaLista(){

	altaLista *miAltaListaConUnElemento = altaListaCrear();
	altaLista *miAltaLista = altaListaCrear();

	estudiante *Leila = estudianteCrear( "leila", "entrania", 21 );
	estudiante *Laura = estudianteCrear( "laura", "provoletta", 23 );

	// Lista con un solo elemento
	insertarOrdenado( miAltaListaConUnElemento, Leila, (tipoFuncionCompararDato)menorEstudiante );
	filtrarAltaLista( miAltaListaConUnElemento, (tipoFuncionCompararDato)menorEstudiante, Laura );
	// Lista con dos elementos 
	insertarOrdenado( miAltaLista, estudianteCrear( "miguel", "entrania", 2 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "leila", "entrania", 23  ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "mario", "asado", 23 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "juanita", "bife", 78 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "marcela", "rueda", 45 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "juan", "salchicha", 45 ), (tipoFuncionCompararDato)menorEstudiante );	
	insertarOrdenado( miAltaLista, estudianteCrear( "tomas", "molleja", 14 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "eduardo", "chinchulin", 46), (tipoFuncionCompararDato)menorEstudiante);
	insertarOrdenado( miAltaLista, estudianteCrear( "mariana", "vacio", 1 ), (tipoFuncionCompararDato)menorEstudiante );
	insertarOrdenado( miAltaLista, estudianteCrear( "mariana", "vacio", 8 ), (tipoFuncionCompararDato)menorEstudiante );
	filtrarAltaLista( miAltaLista, (tipoFuncionCompararDato)menorEstudiante, Laura );

    altaListaImprimir(miAltaLista, "filtrarAltaListaPorLaura.txt", (tipoFuncionImprimirDato)estudianteImprimir );
	altaListaBorrar(miAltaListaConUnElemento, (tipoFuncionBorrarDato)estudianteBorrar );
	altaListaBorrar(miAltaLista, (tipoFuncionBorrarDato)estudianteBorrar );
	//altaListaBorrar(miAltaListaConTresElementos, (tipoFuncionBorrarDato)estudianteBorrar );
	//altaListaBorrar(miAltaListaConCuatroElementos, (tipoFuncionBorrarDato)estudianteBorrar );

	printf("tests_funcion_filtraAltaLista ----> %s \n", "ok");

	//estudianteBorrar(Leila);
	estudianteBorrar(Laura);

}

	//altaLista *miAltaListaConTresElementos = altaListaCrear();
	//altaLista *miAltaListaConCuatroElementos = altaListaCrear();
	//estudiante *Miguel = estudianteCrear( "miguel", "mortadela", 21 );
	//estudiante *Andres = estudianteCrear( "andres", "provoletta", 25 );
	//estudiante *Ramon = estudianteCrear( "ramon", "provoletta", 19 );
	//estudiante *Ale = estudianteCrear( "ale", "provoletta", 19 );


	//insertarOrdenado( miAltaListaConDosElementos, Leila, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConDosElementos, Ale, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConDosElementos, Andres, (tipoFuncionCompararDato)menorEstudiante );
	//filtrarAltaLista( miAltaListaConDosElementos, (tipoFuncionCompararDato)menorEstudiante, Laura );
	// Lista con tres elementos
	//insertarOrdenado( miAltaListaConTresElementos, Leila, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConTresElementos, Andres, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConTresElementos, Ramon, (tipoFuncionCompararDato)menorEstudiante );
	//filtrarAltaLista( miAltaListaConTresElementos, (tipoFuncionCompararDato)menorEstudiante, Laura );
	// Lista con cuatro elementos
	//insertarOrdenado( miAltaListaConCuatroElementos, Leila, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConCuatroElementos, Ramon, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConCuatroElementos, Miguel, (tipoFuncionCompararDato)menorEstudiante );
	//insertarOrdenado( miAltaListaConCuatroElementos, Andres, (tipoFuncionCompararDato)menorEstudiante );
	//filtrarAltaLista( miAltaListaConCuatroElementos, (tipoFuncionCompararDato)menorEstudiante, Laura );
