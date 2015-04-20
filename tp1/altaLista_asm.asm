
; ESTUDIANTE
	global estudianteCrear
	global estudianteBorrar
	global menorEstudiante
	global estudianteConFormato
	global estudianteImprimir
	
; ALTALISTA y NODO
	global nodoCrear
	global nodoBorrar
	global altaListaCrear
	global altaListaBorrar
	;global altaListaImprimir

; AVANZADAS
	global edadMedia
	global insertarOrdenado
	;global filtrarAltaLista
	
; FUNCIONES AUXILIARES	
	global string_longitud
	global string_copiar
	global string_menor
	
; YA IMPLEMENTADAS EN C
	extern string_iguales
	extern insertarAtras
; Funciones de c 
	extern free
	extern malloc
	extern fprintf
	extern fclose
	extern fopen

; /** DEFINES **/    >> SE RECOMIENDA COMPLETAR LOS DEFINES CON LOS VALORES CORRECTOS
	%define NULL 	0
	%define TRUE 	1
	%define FALSE 	0

	%define ALTALISTA_SIZE     		16
	%define OFFSET_PRIMERO 			0
	%define OFFSET_ULTIMO  			8

	%define NODO_SIZE     			24
	%define OFFSET_SIGUIENTE   		0
	%define OFFSET_ANTERIOR   		8
	%define OFFSET_DATO 			16

	%define ESTUDIANTE_SIZE  		20
	%define OFFSET_NOMBRE 			0
	%define OFFSET_GRUPO  			8
	%define OFFSET_EDAD 			16
	
; /** CONSTANTES AUXILIARES PARA IMPRIMIR **/
	;%define FINLINEA_CHAR				db"%s\n"
	;%define TABULACION_FINLINEA_CHAR	db"\t%c\n"
	;%define TABULACION_FINLINEA_INT		db"\t%i\n"
	%define LF 						10 ; fin de linea "\n"
	%define HT 						9  ; tabulacion "\t"
	%define FINSTRING               0  ; ""

section .rodata

	finlinea_char: db'%s', LF, FINSTRING ; "%s\n"
	tabulacion_finlinea_char : db HT,'%s',LF,FINSTRING ; "\t%c\n"
	tabulacion_finlinea_int : db HT,'%d',LF,FINSTRING; "\t%d\n"
	imprimirVacio: db '<vacio>',LF, FINSTRING ; "<vacio>\n" 
	write: db 'w',FINSTRING 
section .data

;Para declarar variables globales no inicializadas,Usamos la pseudo-instrucciones RESB, RESW, RESD, RESQ 
section .bss
pFile resq 1

section .text

;/** FUNCIONES OBLIGATORIAS DE ESTUDIANTE **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;---------------------------------------------------------------------------------------------------------------
	; /** Funcione auxiliares para estudiante **/
	; unsigned char string_longitud( char *s )
	string_longitud:
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		
		xor rbx, rbx ; incrementador inicializado en 0
		xor r12, r12 ; 
		mov r12, rdi ; guardo la dirreccion al string s
	.ciclo:
		cmp byte[r12 + rbx * 1], 0 ; Si el contenido de la posicion es cero 
		je .fin
		inc rbx
		jmp .ciclo
		
	.fin:
		xor rax, rax ; inicializo el registro rax := 0d
		mov eax, ebx;  luego muevo a rax el valor de la longitud
		
		pop r12
		pop rbx
		pop rbp
		ret
		
	; char *string_copiar( char *s );
	string_copiar:
		push rbp
		mov rbp, rsp
		push rbx
		push r12 
		push r13
		push r14 
		
		xor rbx, rbx ; inicalizo rbx tod en cero
		xor r14, r14
		mov rbx, rdi ; me guardo la dirrecion puntero s en rbx		
		call string_longitud ; llamo a la funcion auxiliar y devuelve un unsigned char 1 byte, para guardar la longitud
		;mov r12, rax;
;		and rax , 0x00000000000000ff ; filtro solo la parte byte menos significativo
		xor rdi, rdi
		mov rdi, rax
		inc rdi		; pido un byte mas pra guardar el 0 (fin de string)
		call malloc ; malloc con tamanio rdi
		mov r12, rax ; guardo la dirrecion a donde va ser guardado el nuevo string copia
		xor r13, r13 ; inicalizo la variable indice r13 = 0;
	.copiar:
		cmp byte[rbx + r13 * 1], 0 ; me fijo si es el final del char
						   ; si es cero fin 
		mov r14b, byte[rbx + r13 * 1] ; solo muevo el byte al registro r14l
		mov byte[r12 + r13 * 1], r14b ; copie el el char en mi string copia 
		je .fin
		inc r13					;
		jmp .copiar
	.fin:
		; no modifique rax = dirrecion de la copia 
		pop r14
		pop r13
		pop r12
		pop rbx
		pop rbp
		ret
		
	; bool string_menor( char *s1, char *s2 )	
	string_menor:
		; rdi := s1
		; rsi := s2
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		push r13
		push r14
		push r15
		
		sub rsp, 8 ; alineo la pila
		
		xor rax, rax
		xor rbx, rbx ; inicializo mi indice en CERO
		mov r12, rdi ; guado en r12 la dirrecion a inicio del string s1 
		mov r13, rsi ; guado en r13 la dirrecion a inicio del string s1
		xor r14, r14 ;
		call string_iguales ; si s1[i] == [s2] listo  s1 no es menor a s2 salto a .fin
		cmp rax , 1 ;
		mov rax, 0;  
		je .fin   ; 
	.ciclo:
		mov r14b, byte[r12+ rbx * 1] ; guardo el valor s1[i] en r14b
		cmp r14b, byte[r13 + rbx * 1] ; comparo s1[i] == s2[i] si sin distintos termino ciclo
		
		
		jne .finCiclo
		inc rbx
		jmp .ciclo
	.finCiclo:	
		xor r15, r15
		mov r15b, byte[r13 + rbx * 1] ; guardo el valor s2[i] en r15b
		
		; caso s1[i] == 0 && s2[i] == 0
		cmp r14b, 0  ; veo si s1[i] == 0
		jne .saltar
		cmp r15b, 0
		jne .saltar 
		mov rax, 0 ; devuelvo false
		jne .fin  ; jmp .fin
		 
	.saltar:
		
		mov rax, 0	; devuelvo false 
		je .fin  
		
		; caso si s1[i] == 0 || s2[i] == 0
		cmp r14b, 0	; si s1[i] == 0 
		mov rax, 1 ; devuelvo true pues r14b < r15b (s1[i] < s2[i])	
		je .fin
		; caso si s1[i] == 0 && s2[i] != 0
		cmp r14b, r15b  ; veo si s1[i] == s2[i]  y s1[i] !=0  && s2[i] != 0
		mov rax, 1	; devuelvo false 
		jl .fin 
		mov rax, 0 ; sino devuelvo false
		jne .fin
				
	.fin:
		
		add rsp, 8
		
		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx
		pop rbp
		ret
	; estudiante *estudianteCrear( char *nombre, char *grupo, unsigned int edad );
	estudianteCrear:
		; COMPLETAR AQUI EL CODIGO
		; rdi := *nombre
		; rsi := *grupo
		; edx := edad
		push rbp	; stack frame
		mov rbp, rsp
		
		push rbx
		push r12
		push r13
		push r14
		
		mov rbx, rdi ; preservo rdi = *nombre
		mov r13, rsi	; back up de *grupo
		xor r14, r14	
		mov r14d, edx ; back up de edad
		xor rdi, rdi
		mov rdi, ESTUDIANTE_SIZE ; pido memoria para guardar los datos del estudiante
		call malloc ;
		mov r12, rax ; Guardo la dirrecion a mi struct ESTUDIANTE
		
		xor rdi, rdi 
		mov rdi, rbx
		call string_copiar ; Llamo a la funcion para copiar ; char *string_copiar( char *s )
		mov qword[r12 + OFFSET_NOMBRE], rax ; guarde la copia de *nombre
		
		xor rdi, rdi 
		mov rdi, r13
		call string_copiar ;  char *string_copiar( char *s )
		mov qword[r12 + OFFSET_GRUPO], rax ; guardo la copia de *grupo
		      
		mov dword[r12 + OFFSET_EDAD], r14d ; guarde el edad en la struct estudiante		
		mov rax, r12 ; retorno la posicion de momeria del struct

		pop r14
		pop r13
		pop r12
		pop rbx
		pop rbp
		ret
		
	; void estudianteBorrar( estudiante *e );
	estudianteBorrar:
		; COMPLETAR AQUI EL CODIGO
		; RDI := e
		push rbp ; stack frame
		mov rbp, rsp 
		push rbx

		sub rsp, 8 ; Alineo la pila
 
		xor rbx, rbx
		mov rbx, rdi;
		mov rdi, qword[rbx + OFFSET_NOMBRE] ; obtengo la dirrecion donde esta guardo el nombre del alumno
		call free ; borro nombre de alumno
		mov rdi, qword[rbx + OFFSET_GRUPO] ; obtengo la dirrecion donde esta guadado el nombre del grupo
		call free ; borro nombre de grupo
		mov rdi, rbx ; ahora borro la structura estudiante
		call free 

		add rsp, 8 ;

		pop rbx 
		pop rbp
		ret

	; bool menorEstudiante( estudiante *e1, estudiante *e2 ){
	menorEstudiante:
		; COMPLETAR AQUI EL CODIGO
		; rdi := e1
		; rsi := e2
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		
		mov rbx, rdi; rbx := e1 back de dirreciones
		mov r12, rsi; rbx := e2 back de dirreciones
		mov rdi, qword[rbx + OFFSET_NOMBRE] ; obtengo la dirrecion del nombre del estudiante e1
		mov rsi, qword[r12 + OFFSET_NOMBRE] ; obtengo la dirrecion del nombre del estudiante e2
		call string_iguales 				; llamo a lafuncion  string_iguales(e1->nombre, e2->nombre);
		cmp rax, TRUE
		je .desempate						; call me midifica los flags
		; sino 
		call string_menor ; 		no son string_iguales(e1->nombre, e2->nombre)
		jmp .fin		; pues en rax ya viene la respuesta	
		
	.desempate:
		; si e1->nombre == e2->nombre desempato e1->edad <= e2->edad
		xor rdi, rdi
		mov edi, dword[rbx + OFFSET_EDAD]
		mov esi, dword[r12 + OFFSET_EDAD]
		cmp edi, esi ; comparo e1->edad <= e2->edad
		jle .respuestaTrue
		jmp .respuestaFalse
	.respuestaTrue:
			xor rax, rax 
			mov rax, TRUE
			jmp .fin
	.respuestaFalse:
			xor rax, rax
			mov rax, FALSE
			jmp .fin
			
	.fin:
		pop r12
		pop rbx
		pop rbp
		ret
				
	; void estudianteConFormato( estudiante *e, tipoFuncionModificarString f )
	estudianteConFormato:
		; prototipo de void f(char* s);
		; COMPLETAR AQUI EL CODIGO
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		
		mov rbx, rdi ; backup rbx := e 
		mov r12, rsi ; backup r12 := f
		mov rdi, qword[rbx + OFFSET_NOMBRE]
		call r12				; f(e->nombre)
		mov rdi, qword[rbx + OFFSET_GRUPO]
		call r12				; f(e->grupo)
	
		pop r12
		pop rbx
		pop rbp
		ret
		
	; void estudianteImprimir( estudiante *e, FILE *file )
	estudianteImprimir:
		; COMPLETAR AQUI EL CODIGO
		; rdi = e
		; rsi = file
		; prototipo de fprint : int fprintf(FILE *archivo, const char *formato, argumento, ...);
		push rbp 
		mov rbp, rsp
		push rbx
		push r12
	
		mov rbx, rdi ; backup rbx = e
		mov r12, rsi ; backup r12 = file
		xor rsi, rsi
		mov rdi, r12 					; int fprintf(FILE *archivo, const char *formato, argumento, ...);
		mov rsi, finlinea_char
		mov rdx, qword[rbx + OFFSET_NOMBRE]
		call fprintf						; ; fprintf(file, "%s\n",e->nombre);
		xor rsi, rsi
		mov rdi, r12
		mov rsi, tabulacion_finlinea_char
		mov rdx, qword[rbx + OFFSET_GRUPO];
		call fprintf					; fprintf(file, "\t%s\n",e->grupo);	
		mov rdi, r12
		xor rsi,rsi
		mov rsi, tabulacion_finlinea_int  ; fprintf(file, "\t%s\n",e->grupo);
		xor rdx, rdx
		mov edx, dword[rbx + OFFSET_EDAD];
		call fprintf
		;mov rdi, r12
		;call fclose
		pop r12
		pop rbx
		pop rbp
		ret
		
		
		
;/** FUNCIONES DE ALTALISTA Y NODO **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;--------------------------------------------------------------------------------------------------------

	; nodo *nodoCrear( void *dato )
	nodoCrear:
	; COMPLETAR AQUI EL CODIGO
		push rbp 
		mov rbp, rsp
		push rbx 
		push r12
		; los registros r13,r14,r15 no los utilizo
		
		mov rbx, rdi		; Me guardo la direccion  que apunta al dato
		mov rdi, NODO_SIZE ; Paso en tamanio del nodo, para utilizarla en la funcion malloc
		call malloc
		mov qword[rax + OFFSET_SIGUIENTE], NULL	 ; cargo el puntero a siguiente en NULL
		mov	qword[rax + OFFSET_ANTERIOR], NULL		; cargo el puntero a anterioR en NULL
		mov qword[rax + OFFSET_DATO],rbx 			; Cargo la direccion del dato
		
		pop r12
		pop rbx
		pop rbp
		ret
	; void nodoBorrar( nodo *n, tipoFuncionBorrarDato f )
	nodoBorrar:
		; COMPLETAR AQUI EL CODIGO
		; rdi = n
		; rsi = f
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		
		mov rbx, rdi ; guardo rbx := n dirrecion donde esta guardado el nodo
		mov r12, rsi ; guardo r12 := f
		mov rdi, qword[rbx + OFFSET_DATO] ; RDI := n->dato
		call r12; llamo a la tipoFuncionBorrarDato f que esta guardado a partir de la dirrecion indicada por r12
		mov rdi, rbx  
		call free ; borro la el struct nodo
		
		pop r12
		pop rbx
		pop rbp
		ret
		
	; altaLista *altaListaCrear( void )
	altaListaCrear:
		push rbp	; stack frame 
		mov rbp, rsp
		
		xor rdi, rdi
		mov rdi, ALTALISTA_SIZE ; 
		call malloc ; Pido memoria para guardad mi instancia struct lista, en rax tengo la dirrecion de inicio de memoria
		mov qword[rax + OFFSET_PRIMERO], NULL
		mov qword[rax + OFFSET_ULTIMO], NULL
		
		pop rbp
		ret
	; void altaListaBorrar( altaLista *l, tipoFuncionBorrarDato f )
	altaListaBorrar:
;				nodo *actual = l->primero;
;				nodo *borrar= NULL;
;				l->primero = NULL;
;				l->ultimo = NULL;
;				if ( actual != NULL ){  // si l no es una lista vacia, por ejemplo: primero ----> [5 <-> 7 <-> 8 <-> 9] <---- ultimo
;					while( actual != NULL ){
;						borrar = actual;
;						actual  = actual->siguiente;
;						nodoBorrar(borrar,f);
;					}
;				}
;				free(l);
	
	
	
		; COMPLETAR AQUI EL CODIGO
		; rdi := l 
		; rsi := f 
		push rbp
		mov rbp,rsp
		push rbx
		push r12
		push r13
		push r14
		push r15
		sub rsp, 8 ; alineo la pila 
		 
		mov rbp, rsp
		mov rbx, rdi ; backup rbx := l  puntero a lista
		mov r12, rsi ; backup r12 := f  funocion borrar
		mov r13, qword[rbx + OFFSET_PRIMERO]; me guardo actual:=l->primero
		xor r14, r14
		mov r14, NULL ; borrar := NULL  puntero a nodo a borrar
		mov qword[rbx + OFFSET_PRIMERO], NULL ; l->primero := NULL
		mov qword[rbx + OFFSET_ULTIMO], NULL  ; l->ultimo := NULL
		; Si actual == NULL
		cmp r13, NULL
		je .fin  
	.while:
		cmp r13, NULL
		je .fin
		mov r14, r13; borrar := actual
		mov r15, r13 ; copio r15 := actual
		mov r13, [r15+OFFSET_SIGUIENTE] ; actual := actual->siguiente
		mov rdi, r14 ; rdi := borrar
		mov rsi, r12 ; rsi := f
		call nodoBorrar ; nodoBorrar(borrar,f)
		jmp .while
	.fin:
		mov rdi, rbx; 
		call free; rdi := l
		
		add rsp, 8
		pop r15
		pop r14
		pop r13
		pop r12 
		pop rbx
		pop rbp
		ret


;		mov rdi, qword[rbx + OFFSET_PRIMERO]
;		call r12
;		mov rdi, qword[rbx + OFFSET_ULTIMO]
;		call r12
;		mov rdi, rbx
;		call free
		
		pop r12
		pop rbx
		pop rbp
		ret 
		
		
	; void altaListaImprimir( altaLista *l, char *archivo, tipoFuncionImprimirDato f )
	altaListaImprimir:
		; COMPLETAR AQUI EL CODIGO
			;FILE* pFile;
			;pFile = fopen(archivo, "w");
			;nodo* nodoActual = l->primero;
			;if (nodoActual != NULL){
			;	while(nodoActual != NULL){
			;		f(nodoActual->dato,pFile);//estudianteImprimir(nodoActual->dato);
			;		nodoActual = nodoActual->siguiente;
			;	}
			;}else{
			;	//imprimir <vacia>
			;	fprintf(pFile, "<vacia>\n");
			;}
			;fclose(pFile);
			push rbp
			mov rbp, rsp
			push rbx 
			push r12
			push r13
			push r14
			push r15
			sub rsp, 8 ; alineo la pila
			; rdi := l
			; rsi := archivo 
			; rdx := f
			mov rbx, rdi ; backup altaLista rbx := l
			mov r12, rsi ; backup archivo r12 := archivo
			mov r13, rsi ; backup tipoFuncionImprimir r13 := f
			mov rdi, r12; rdi := archivo 
			xor rsi, rsi;
			mov rsi, write; modo escritura "w"
			call fopen ; prototipo de fopen: FILE *fopen(const char *filename, const char *mode)
			mov [rel pFile], rax ; guardo la dirrecion del archivo a escribir, osea r14= pFile 
			mov r15, qword[rbx + OFFSET_PRIMERO] ; r15 = nodoActual
			cmp r15, NULL
			je .imprimirVacio
		.ciclo:
			cmp r15, NULL ;   
			je .fin
			mov rdi, qword[r15 + OFFSET_DATO] ; rdi := nodoActual->dato
			mov rsi, r14 ;  rsi := pFile
			call r13 ; f(nodoActual->dato, pFile)
			mov r15, [r15 + OFFSET_SIGUIENTE]
			jmp .ciclo
		.imprimirVacio:
			mov rdi, r14
			mov rsi, imprimirVacio
			call fprintf ; fprintf(pFile, "<vacio>" );
		.fin:	
			add rsp, 8
			pop r15
			pop r14
			pop r13
			pop r12
			pop rbx
			pop rbp
			ret
			
			
;/** FUNCIONES AVANZADAS **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;----------------------------------------------------------------------------------------------

	; float edadMedia( altaLista *l )
	edadMedia:
		; COMPLETAR AQUI EL CODIGO
		;				nodo* actual = l->primero;
		;				unsigned int cantEstudiantes = 0;
		;				unsigned int sumaEdades = 0;
		;				estudiante *e = NULL;
		;				if (actual != NULL){
		;					while(actual != NULL){
		;						cantEstudiantes++;
		;						e = actual->dato;
		;						sumaEdades = sumaEdades + e->edad;
		;						actual = actual->siguiente;
		;					}
		;					return (float)sumaEdades/cantEstudiantes;
		;				}
		;				return 0;
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		push r13
		push r14
		push r15
		sub rsp, 8 ; alineo la pila
		; rdi := l
		mov rbx, [rdi + OFFSET_PRIMERO] ; actual := l->primero
		xorpd xmm0, xmm0 ; inicilaizo, osea xmm0 := sumaEdades
		xorpd xmm1, xmm1 ; inicilaizo, osea r13 := cantEstudiantes
		xor r12, r12 ; sumaEdades = 0
		xor r13, r13 ; cantEstudiantes = 0
		cmp rbx, NULL ; si actual == NULL
		je .fin
	.while:       ; caso en que que la lista tiene por lo menos un alumno
		cmp rbx, NULL ; si actual != NULL
		je .calcularPromedio
		inc r13d;					cantEstudiantes++;	
		mov r14, [rbx + OFFSET_DATO] ; e = actual->dato;
		add r12d, dword[r14 + OFFSET_EDAD] ; sumaEdades = sumaEdades + e->edad;
		mov r15, rbx
		mov rbx, [r15+OFFSET_SIGUIENTE] ; actual = actual->siguiente;;
		JMP .while		
	.calcularPromedio:
		movq xmm0, r12 ; xmm0 := sumaEdades
		movq xmm1, r13 ; xmm1 := cantEstudiantes
		cvtdq2ps xmm0, xmm0 ; convierto a float el ENTERO1
		cvtdq2ps xmm1, xmm1 ; convierto al floar el ENTERO2
		divps xmm0, xmm1	
		jmp .fin
	.fin:	
		
		add rsp, 8 ; desalineo la pila 
		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx
		pop rbp
		ret
		
	; void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f )
	insertarOrdenado:
		; COMPLETAR AQUI EL CODIGO
								
;						void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f ){
;							nodo* actual = l->primero; 	
;							nodo* antecesor = NULL;
;							nodo* nuevoNodo = nodoCrear(dato);
;							
;							if (actual == NULL){
;								// Caso en que la lista esta vacia, agrego como primero y ultimo
;								listaVaciaInsertarNodo(l, nuevoNodo);
;							}else if (f(dato,actual->dato)){
;								// Caso en que actual es el primer nodo
;								listaNoVaciaInsertaComoPrimero(l, actual, nuevoNodo);
;							}else{
;								//caso en el que agrego el nuevo nodo en el medio de la lista o en el ultimo nodo
;								// busco donde debo poner el nodo;
;								while (actual != NULL && !f(dato, actual->dato)){
;									antecesor = actual;
;									actual = actual->siguiente;
;								}
;								if ( actual == NULL){
;								// caso agrego a lo ultimo de la lista
;									//actual = l->ultimo;
;									listaNoVaciaInsertaComoultimo( l, antecesor, nuevoNodo);
;								}else{
;									// caso  agrego en medio, osea que dato > actual->dato
;									InsertaEnMedio(antecesor, nuevoNodo, actual);
;								}	
;							}	
;						}

		; rdi := l
		; rsi := dato
		; rdx := f
		
		%define FUNCION_COMPARAR [rbp - 8]
		push rbp 
		mov rbp, rsp
		sub rsp, 8 ;
		push rbx
		push r12
		push r13
		push r14
		push r15
		
		mov qword FUNCION_COMPARAR, rdi; FUNCION_COMPARAR =  [rbp - 8] := f  
		;sub rsp, 8 ; alineo la pila
		
		mov rbx, rdi ;backup de rbx := l
		mov r12, rsi ; backup de r12 := dato
		mov FUNCION_COMPARAR, rdx ; backup de r13 := f	
		mov rdi, r12; rdi := dato
		call nodoCrear ; nodo *nodoCrear( void *dato );
		; rax := nuevoNodo
		mov r13, rax ; backup r13 := nuevoNodo  
		mov r14, qword[rbx + OFFSET_PRIMERO]; R14 := actual
		cmp r14, NULL ; Si la lista es vacia actual != NULL
		je .insertarUnicoNodo 
		mov rdi, r12 ; rdi := dato
		mov rsi, qword[r14 + OFFSET_DATO] ; rsi:= actual->dato 
		call FUNCION_COMPARAR ; bool menorEstudiante(estudiante *e1, estudiante *e2)
		cmp rax, TRUE ; menorEstudiante(dato, actual->dato) == true
		je .insertarComoPrimero
	.while:
		cmp r14, NULL ; actual - NULL
		;jne .insertEnElMedio
		je .insertComoUltimo
		mov rdi, r12 ; rdi := dato
		mov rsi, qword[r14 + OFFSET_DATO] ;
		call FUNCION_COMPARAR  ; !f(dato, actual->dato))
		cmp rax, TRUE ;
		;je .insertComoUltimo
		je .insertEnElMedio
		; Iterar en el while
		mov r15, r14 ; r15 := actual , donde r15 es : antecesor := actual
		mov r14, qword[r15 + OFFSET_SIGUIENTE]; actual = actual->siguiente;
		JMP .while
		
	.insertComoUltimo:
		mov rdi, rbx ; rdi := l
		mov rsi, r15 ; rsi := antecesor
		mov rdx, r13 ; rdx := nuevoNodo
		call listaNoVaciaInsertaComoultimo; prototipo: void listaNoVaciaInsertaComoultimo(altaLista* l, nodo* ult, nodo* nuevo)
		jmp .fin
	.insertEnElMedio:
		mov rdi, r15 ; rdi := antecesor
		mov rsi, r13 ; rsi := nuevo
		mov rdx, r14 ; rdx := posterior
		call InsertaEnMedio ; prototipo; void InsertaEnMedio(nodo* antecesor, nodo* nuevo, nodo* posterior)
		jmp .fin
	.insertarComoPrimero:
		mov rdi, rbx	
		mov rsi, r14	
		mov rdx, r13
		call  listaNoVaciaInsertaComoPrimero; void listaNoVaciaInsertaComoPrimero(l, actual, nuevoNodo);
		jmp .fin
	.insertarUnicoNodo:
		mov rdi, rbx ; rdi := l
		mov rsi, r13 ; rsi := nuevoNodo
		call listaVaciaInsertarNodo ; void listaVaciaInsertarNodo(altaLista* l, nodo* nuevo) 
		jmp .fin
		.fin:
		;add rsp, 8 ; desalineo la pila
		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx
		add rsp, 8 ;
		pop rbp
		ret
			; /****** AUXILIARES DE insertarOdenado ******/	
		
		;Void listaVaciaInsertarNodo(altaLista* l, nodo* nuevo)
	listaVaciaInsertarNodo:
				;l->primero = nuevo;
				;l->ultimo = nuevo;
		push rbp
		mov rbp, rsp
		; rdi := l
		; rsi := nuevo
		mov qword[rdi + OFFSET_PRIMERO], rsi ; l->primero = nuevo;
		mov qword[rdi + OFFSET_ULTIMO], RSI; L->ultimo := nuevo
		pop rbp
		ret 
		
		;void listaNoVaciaInsertaComoPrimero(altaLista* l, nodo* prim, nodo* nuevo)	
	listaNoVaciaInsertaComoPrimero:
				; nuevo->siguiente = prim;
				; prim->anterior = nuevo;
				; l->primero = nuevo;
		
		push rbp
		mov rbp, rsp
		; rdi := L
		; rsi := prim
		; rdx := nuevo
		mov qword[rdx + OFFSET_SIGUIENTE], rsi ; nuevo->siguiente = prim;
		mov qword[rsi + OFFSET_ANTERIOR], rdx ; prim->anterior = nuevo; 
		mov qword[rdi + OFFSET_PRIMERO], rdx ; l->primero = nuevo;
		pop rbp
		ret
			; void listaNoVaciaInsertaComoultimo(altaLista* l, nodo* ult, nodo* nuevo)
	listaNoVaciaInsertaComoultimo:
				; ult->siguiente = nuevo;
				; nuevo->anterior = ult;
				; l->ultimo = nuevo;
		push rbp
		mov rbp, rsp
		; rdi := l
		; rsi := ult
		; rdx := nuevo
		mov qword[rsi + OFFSET_SIGUIENTE], rdx ; ult->siguiente = nuevo;
		mov qword[rdx + OFFSET_ANTERIOR], rsi ; nuevo->anterior = ult;
		mov qword[rdi + OFFSET_ULTIMO], rdx ; ; l->ultimo = nuevo;
		pop rbp
		ret 		
			
			;void InsertaEnMedio(nodo* antecesor, nodo* nuevo, nodo* posterior)
	InsertaEnMedio:
				; nuevo->siguiente = posterior;
				; nuevo->anterior = antecesor;
				; antecesor->siguiente = nuevo;
				; posterior->anterior = nuevo;
		push rbp
		mov rbp, rsp
		; rdi := antecesor
		; rsi := nuevo
		; rdx:= posterior 
		mov qword[rsi + OFFSET_SIGUIENTE], rdx ; nuevo->siguiente = posterior;
		mov qword[rsi + OFFSET_ANTERIOR], rdi ; nuevo->anterior = antecesor;
		mov qword[rdi + OFFSET_SIGUIENTE], rsi ; antecesor->siguiente = nuevo;
		mov qword[rdx + OFFSET_ANTERIOR], rsi ; posterior->anterior = nuevo;
		pop rbp
		ret	
		
			
			
			; /****** FIN AUXILIARES DE insertarOdenado ******/		
		
		
		; void filtrarAltaLista( altaLista *l, tipoFuncionCompararDato f, void *datoCmp )
	filtrarAltaLista:
		; COMPLETAR AQUI EL CODIGO

