#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"
#include "pipeline.h"

typedef struct registro
{
	int $t0;
	int $t1;
	int $t2;
	int $t3;
	int $t4;
	int $t5;
	int $t6;
	int $t7;
	int $t8;
	int $t9;
	
	int $a0;
	int $a1;
	int $a2;
	int $a3;
	int $zero;
	int $v0;
	int $v1;
	int lo;
	int hi;
			
}registro;

registro editar(registro r, char* nombre , int valor){

	if (nombre == "$t0"){ r.$t0 = valor; }
	if (nombre == "$t1"){ r.$t1 = valor; }
	if (nombre == "$t2"){ r.$t2 = valor; }
	if (nombre == "$t3"){ r.$t3 = valor; }
	if (nombre == "$t4"){ r.$t4 = valor; }
	if (nombre == "$t5"){ r.$t5 = valor; }
	if (nombre == "$t6"){ r.$t6 = valor; }
	if (nombre == "$t7"){ r.$t7 = valor; }
	if (nombre == "$t8"){ r.$t8 = valor; }
	if (nombre == "$t9"){ r.$t9 = valor; }

	if (nombre == "$a0"){ r.$a0 = valor; }
	if (nombre == "$a1"){ r.$a1 = valor; }
	if (nombre == "$a2"){ r.$a2 = valor; }
	if (nombre == "$a3"){ r.$a3 = valor; }

	if (nombre == "$v0"){ r.$v0 = valor; }
	if (nombre == "$v1"){ r.$v1 = valor; }
	if(nombre == "hi"){ r.hi = valor; }
	if(nombre == "lo"){ r.lo = valor; }

	return r;
}

int obtenerI(registro r, char nombre[]){

	int valor= 0;

	if (nombre == "$t0"){ valor = r.$t0; }
	else if (nombre == "$t1"){ valor = r.$t1; }
	else if (nombre == "$t2"){ valor = r.$t2; }
	else if (nombre == "$t3"){ valor = r.$t3; }
	else if (nombre == "$t4"){ valor = r.$t4; }
	else if (nombre == "$t5"){ valor = r.$t5; }
	else if (nombre == "$t6"){ valor = r.$t6; }
	else if (nombre == "$t7"){ valor = r.$t7; }
	else if (nombre == "$t8"){ valor = r.$t8; }
	else if (nombre == "$t9"){ valor = r.$t9; }

	else if (nombre == "$a0"){ valor = r.$a0; }
	else if (nombre == "$a1"){ valor = r.$a1; }
	else if (nombre == "$a2"){ valor = r.$a2; }
	else if (nombre == "$a3"){ valor = r.$a3; }

	else if (nombre == "$v0"){ valor = r.$v0; }
	else if (nombre == "$v1"){ valor = r.$v1; }
	else if (nombre == "lo"){ valor = r.lo; }
	else if (nombre == "hi"){ valor = r.hi; }

	else{ valor=atoi(nombre);	}
	
	return valor;
}

registro iniciacion(registro r){
	r.$t0=0;
	r.$t1=0;
	r.$t2=0;
	r.$t3=0;
	r.$t4=0;
	r.$t5=0;
	r.$t6=0;
	r.$t7=0;
	r.$t8=0;
	r.$t9=0;

	r.$a0=0;
	r.$a1=0;
	r.$a2=0;
	r.$a3=0;

	r.$zero=0;
	r.$v0=0;
	r.$v1=0;
	r.lo=0;
	r.hi=0;

	return r;
}

void imprimir(registro r){

	printf("t0: %d\n", r.$t0);
	printf("t1: %d\n", r.$t1);
	printf("t2: %d\n", r.$t2);
	printf("t3: %d\n", r.$t3);
	printf("t4: %d\n", r.$t4);
	printf("t5: %d\n", r.$t5);
	printf("t6: %d\n", r.$t6);
	printf("t7: %d\n", r.$t7);
	printf("t8: %d\n", r.$t8);
	printf("t9: %d\n", r.$t9);
	printf("a0: %d\n", r.$a0);
	printf("a1: %d\n", r.$a1);
	printf("a2: %d\n", r.$a2);
	printf("a3: %d\n", r.$a3);
	printf("v0: %d\n", r.$v0);
	printf("v1: %d\n", r.$v1);
	printf("lo: %d\n", r.lo);
	printf("hi: %d\n", r.hi);

}

void archivoRegistro(registro r){

	FILE * File;
	File = fopen ("END_STATE.txt", "w" );

	char cadena0[30], cadena1[30],cadena2[30],cadena3[30],cadena4[30],cadena5[30],cadena6[30],cadena7[30],cadena8[30],cadena9[30];
	char cadena10[30],cadena11[30],cadena12[30],cadena13[30],cadena14[30],cadena15[30],cadena16[30],cadena17[30];
	
	sprintf(cadena0, "$t0: %d\n", r.$t0); 
	sprintf(cadena1, "$t1: %d\n", r.$t1); 
	sprintf(cadena2, "$t2: %d\n", r.$t2); 
	sprintf(cadena3, "$t3: %d\n", r.$t3); 
	sprintf(cadena4, "$t4: %d\n", r.$t4); 
	sprintf(cadena5, "$t5: %d\n", r.$t5); 
	sprintf(cadena6, "$t6: %d\n", r.$t6); 
	sprintf(cadena7, "$t7: %d\n", r.$t7); 
	sprintf(cadena8, "$t8: %d\n", r.$t8); 
	sprintf(cadena9, "$t9: %d\n", r.$t9);
	sprintf(cadena10, "$a0: %d\n", r.$a0);  
	sprintf(cadena11, "$a1: %d\n", r.$a1); 
	sprintf(cadena12, "$a2: %d\n", r.$a2); 
	sprintf(cadena13, "$a3: %d\n", r.$a3); 
	sprintf(cadena14, "$v0: %d\n", r.$v0); 
	sprintf(cadena15, "$v1: %d\n", r.$v1); 
	sprintf(cadena16, "$lo: %d\n", r.lo); 
	sprintf(cadena17, "$hi: %d\n", r.hi); 

	fputs(cadena0, File);
	fputs(cadena1, File);
	fputs(cadena2, File);
	fputs(cadena3, File);
	fputs(cadena4, File);
	fputs(cadena5, File);
	fputs(cadena6, File);
	fputs(cadena7, File);
	fputs(cadena8, File);
	fputs(cadena9, File);
	fputs(cadena10, File);
	fputs(cadena11, File);
	fputs(cadena12, File);
	fputs(cadena13, File);
	fputs(cadena14, File);
	fputs(cadena15, File);
	fputs(cadena16, File);
	fputs(cadena17, File);

	fclose ( File );	
}