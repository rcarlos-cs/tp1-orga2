#include "altaLista.h"
#include <stdio.h>
#include <stdlib.h>

// FUNCIONES TESTS PROPIOS

void tests_string_longitud();
void tests_string_copiar();
void tests_string_menor();
void tests_estudianteCrear();
void tests_estudianteBorrar();
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
	tests_string_longitud();
	tests_string_copiar();
	tests_string_menor();
	tests_estudianteCrear(); 
	tests_estudianteBorrar();
	return 0;
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

	res = res && *copy1 == *c1 && copy1 !=c1;
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
	free(copy1); free(copy2); free(copy3); free(copy4); free(copy5); free(copy6); free(copy7); free(copy8);
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
	bool res = true;
	res = res && string_menor(c1,c2); // (merced < mercurio) == true
	res = res && string_menor(c3,c4); // (perro < zorro) == true
	res = res && string_menor(c5,c6); // (senior < seniora) == true
	res = res && string_menor(c7,c8); // (caZa < casa) == true
	res = res && !string_menor(c9,c10); // !(hola < hola) == true
	res = res && !string_menor(c6,c5); // !(seniora < senior) == true
	if (res){
		printf("tests_string_menor ----> %s \n", "ok");
	}else{
		printf("tests_string_menor ----> %s \n", "error tests");
	}	
}

void tests_estudianteCrear(){
	char *fede = "fede";
	char *medio = "medio";
	unsigned int ed = 19;
	estudiante *e = estudianteCrear( fede, medio,ed);
	bool res = true;
	//printf("Nombre %s, grupo %s, edad%d \n", e->nombre, e->grupo, e->edad);
	
	res = res && string_iguales(fede,e->nombre) && string_iguales(medio, e->grupo) && ed == e->edad;
	if (res){
		printf("tests_estudiante_crear ----> %s \n", "ok");
	}else{
		printf("tests_estudiante_crear ----> %s \n", "error tests");
	}
	//BORRO AL ESTUDIANTE DE LA MEMORIA DINAMICA UTILIZADA EN ESTE TEST
	estudianteBorrar(e);	
}

void tests_estudianteBorrar(){
	char *fede = "fede";
	char *medio = "medio";
	unsigned int ed = 19;
	estudiante *e = estudianteCrear( fede, medio,ed);
	estudianteBorrar(e);
	//printf("Nombre %s, grupo %s, edad%d \n", e->nombre, e->grupo, e->edad);
	// OBSERVACION: segun valgrin toda la memoria dinamica fue desalojada
}
