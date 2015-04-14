
; ESTUDIANTE
;	global estudianteCrear
	global estudianteBorrar
	global menorEstudiante
	global estudianteConFormato
	global estudianteImprimir
	
; ALTALISTA y NODO
	global nodoCrear
	global nodoBorrar
	global altaListaCrear
	global altaListaBorrar
	global altaListaImprimir

; AVANZADAS
	global edadMedia
	global insertarOrdenado
	global filtrarAltaLista
	
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


section .rodata


section .data


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
		mov r12, rdi ; base del string
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
		and rax , 0x00000000000000ff ; filtro solo la parte byte menos significativo
		mov rdi, rax
		call malloc ; malloc con tamanio rdi
		mov r12, rax ; guardo la dirrecion a donde va ser guardado el nuevo string copia
		xor r13, r13 ; inicalizo la variable indice r13 = 0;
	.copiar:
		cmp byte[rbx + r13 * 1], 0 ; me fijo si es el final del char
		je .fin				   ; si es cero fin 
		mov r14b, byte[rbx + r13 * 1] ; solo muevo el byte al registro r14l
		mov byte[r12 + r13 * 1], r14b ; copie el el char en mi string copia 
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
		
		xor rax, rax
		xor rbx, rbx ; inicializo mi indice en CERO
		mov r12, rdi ; guado en r12 la dirrecion a inicio del string s1 
		mov r13, rsi ; guado en r13 la dirrecion a inicio del string s1
		xor r14, r14 ;
	.ciclo:
		mov r14b, byte[r12+ rbx * 1] ; guardo el valor s1[i] en r14b
		cmp r14b, byte[r13 + rbx * 1]
		
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
;		push rbp	; stack frame
;		mov rbp, rsp
;		
;		push rbx
;		push r12
;		push r13
;		push r14
		
;		mov rbx, rdi ; preservo rdi = *nombre
;		mov r13, rsi	; back up de *grupo
;		xor r14, r14	
;		mov r14d, edx ; back up de edad
;		xor rdi, rdi
;		mov edi, ESTUDIANTE_SIZE ; pido memoria para guardar los datos del estudiante
;		call malloc ;
;		mov r12, rax ; Guardo la dirrecion a mi struct ESTUDIANTE
		
;		xor rdi, rdi 
;		mov rdi, rbx
;		call string_copiar ; Llamo a la funcion para copiar ; char *string_copiar( char *s )
;		mov qword[r12 + OFFSET_NOMBRE], rbx ; guarde la cipia de *nombre
		
;		xor rdi, rdi 
;		mov rdi, r13
;		call string_copiar ;  char *string_copiar( char *s )
;		mov qword[r12 + OFFSET_GRUPO], rax ; guardo la copia de *grupo
;		      
;		mov qword[r12 + OFFSET_EDAD], r14 ; guarde el edad   
;		call string_copiar ; char *string_copiar( char *s )
		
;		mov rax, r12 ; retorno la posicion de momeria del struct
		
;		pop r12
;		pop rbx
;		pop rbp
;		ret
		
	; void estudianteBorrar( estudiante *e );
	estudianteBorrar:
		; COMPLETAR AQUI EL CODIGO
		; RDI := e
		push rbp ; stack frame
		mov rbp, rsp 
		push rbx
		
		mov rbx, rdi;
		mov rdi, qword[rbx + OFFSET_NOMBRE] ; obtengo la dirrecion donde esta guardo el nombre del alumno
		call free ; borro nombre de alumno
		mov rdi, qword[rbx + OFFSET_GRUPO] ; obtengo la dirrecion donde esta guadado el nombre del grupo
		call free ; borro nombre de grupo
		mov rdi, rbx ; ahora borro la structura estudiante
		call free 
		pop rbx 
		pop rbp
		ret

	; bool menorEstudiante( estudiante *e1, estudiante *e2 ){
	menorEstudiante:
		; COMPLETAR AQUI EL CODIGO

	; void estudianteConFormato( estudiante *e, tipoFuncionModificarString f )
	estudianteConFormato:
		; COMPLETAR AQUI EL CODIGO
	
	; void estudianteImprimir( estudiante *e, FILE *file )
	estudianteImprimir:
		; COMPLETAR AQUI EL CODIGO


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
		mov qword[rax + OFFSET_SIGUIENTE], 0	 ; cargo el puntero a siguiente en NULL
		mov	qword[rax + OFFSET_ANTERIOR], 0		; cargo el puntero a anterioR en NULL
		mov qword[rax + OFFSET_DATO],rbx 			; Cargo la direccion del dato
		
		pop r12
		pop rbx
		pop rbp
		ret
	; void nodoBorrar( nodo *n, tipoFuncionBorrarDato f )
	nodoBorrar:
		; COMPLETAR AQUI EL CODIGO

	; altaLista *altaListaCrear( void )
	altaListaCrear:
		; COMPLETAR AQUI EL CODIGO

	; void altaListaBorrar( altaLista *l, tipoFuncionBorrarDato f )
	altaListaBorrar:
		; COMPLETAR AQUI EL CODIGO

	; void altaListaImprimir( altaLista *l, char *archivo, tipoFuncionImprimirDato f )
	altaListaImprimir:
		; COMPLETAR AQUI EL CODIGO


;/** FUNCIONES AVANZADAS **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;----------------------------------------------------------------------------------------------

	; float edadMedia( altaLista *l )
	edadMedia:
		; COMPLETAR AQUI EL CODIGO

	; void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f )
	insertarOrdenado:
		; COMPLETAR AQUI EL CODIGO

	; void filtrarAltaLista( altaLista *l, tipoFuncionCompararDato f, void *datoCmp )
	filtrarAltaLista:
		; COMPLETAR AQUI EL CODIGO

