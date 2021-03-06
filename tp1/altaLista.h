#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  /* malloc, free, rand */


/** Tipos altaLista, nodo y estudiante **/

	typedef struct lista_t {
		struct nodo_t	*primero;    			// size = 8  => offset = 0
		struct nodo_t	*ultimo;	 			// size = 8  =>offset = 8
	} __attribute__((__packed__)) altaLista; // size_struct = 16 => offset = 16

	typedef struct nodo_t {
		struct nodo_t	*siguiente;			// size = 8 => offset = 0
		struct nodo_t	*anterior;			// size = 8 => offset = 8
		void			*dato;				// size = 8 => offset = 16
	} __attribute__((__packed__)) nodo;	// size_struct = 24 => offset = 24

	typedef struct estudiante_t {
		char			*nombre;				// size = 8 => offset = 0
		char			*grupo;					// size = 8 => offset = 8
		unsigned int	edad; 					// size =  4 => offset = 16
	} __attribute__((__packed__)) estudiante;   // size_struct = 20 => offset = 20


/** Definiciones de punteros a funciones **/

	typedef void (*tipoFuncionBorrarDato) (void*);
	typedef void (*tipoFuncionImprimirDato) (void*, FILE*);
	typedef bool (*tipoFuncionCompararDato) (void*, void*);
	typedef void (*tipoFuncionModificarString) (char*);


/** Funciones de estudiante **/

	estudiante *estudianteCrear( char *nombre, char *grupo, unsigned int edad );
	void estudianteBorrar( estudiante *e );
	bool menorEstudiante( estudiante *e1, estudiante *e2 );
	void estudianteConFormato( estudiante *e, tipoFuncionModificarString f );
	void estudianteImprimir( estudiante *e, FILE *file );


/** Funciones de altaLista y nodo **/

	nodo *nodoCrear( void *dato );
	void nodoBorrar( nodo *n, tipoFuncionBorrarDato f );
	altaLista *altaListaCrear( void );
	void altaListaBorrar( altaLista *l, tipoFuncionBorrarDato f );
	void altaListaImprimir( altaLista *l, char *archivo, tipoFuncionImprimirDato f );

/** Funciones Avanzadas **/

	float edadMedia( altaLista *l );
	void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f );
		
			/*****  AUXILIARES DE insertarOdenado *****/

			void listaVaciaInsertarNodo(altaLista* l, nodo* nuevo);
			void listaNoVaciaInsertaComoPrimero(altaLista* l, nodo* prim, nodo* nuevo);
			void listaNoVaciaInsertaComoultimo(altaLista* l, nodo* ult, nodo* nuevo);
			void InsertaEnMedio(nodo* anterior, nodo* nuevo, nodo* posterior);
			/*****  FIN AUXILIARES DE insertarOdenado *****/
			
	void filtrarAltaLista( altaLista *l, tipoFuncionCompararDato f, void *datoCmp );

			/*****  AUXILIARES DE filtrarAltaLista *****/
			
			void deletearNodoDeLista(altaLista *l, nodo* borrar);
			void aislarNodoDelMedioDeLaLista(nodo *ailar);
			/*****  FIN AUXILIARES DE filtrarAltaLista*****/

/** Funciones Auxiliares Sugeridas **/

	unsigned char string_longitud( char *s );
	char *string_copiar( char *s );
	bool string_menor( char *s1, char *s2 );


/** Funciones Auxiliares ya implementadas en C **/

	bool string_iguales( char *s1, char *s2 );											
	void insertarAtras( altaLista *l, void *dato );
