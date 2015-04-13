#include "altaLista.h"
#include <stdio.h>
void tests_string_longitud();
void tests_string_copiar();
void tests_string_menor();

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
	//char copia = string_copiar(c1);
	//printf(" string 1 : %s, string 2: %s", c1, copia);
 
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



