#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"
#include "pipeline.h"

typedef struct control{
	int codigoOP;

}control;

typedef struct buffer{
	
 	char* nombreOP;	//operacion de la instruccion
	char* nombreRd; //registro en rd
	int valorRd;
	char* nombreRt; //registro en rt
    int valorRt;
 	char* nombreRs; //registro en rs
 	int valorRs; 
 	char* nombreOff;	
 	int offset; //inmediato o Adrres dependiendo del caso
 	char nombreOff2[20];
 	int offset2;
 	char* siguiente;
 	control lineasControl;
 	int nLinea;
 	
}buffer;

typedef struct pipeline{
	buffer pipeline[4];	
}pipeline;

//buffer nop o con valores en 0
buffer nop(buffer n){

 	n.nombreOP="nop";	//operacion de la instruccion
	n.nombreRd=""; //registro en rd
	n.valorRd=0;
	n.nombreRt=""; //registro en rt
  	n.valorRt=0;
 	n.nombreRs="";
 	n.valorRs=0; 
 	n.nombreOff="";	
 	n.offset=0;
 	n.offset2=0;
 	n.lineasControl.codigoOP=99;
 	n.siguiente="0";
 	n.nLinea =0;
 	return n;
}



buffer IF(char *instruccion ,int n , buffer b){
	printf("Etapa IF\n");
	//crear palabras
	char* ins;
	char lapa[30]="";
	char label[30]="";
	int i=0;
	strcat(lapa, instruccion);

	//ins=lapa;
	char* d="";
	char* t="";
	char* s="";

	char* rd;//cambio
	char* rt;
	char* rs;



  	ins = strtok (lapa," ,():");   // Aqui deja solo la coma
  	printf("instruccion completa: %s\n",instruccion );

 	if (ins[0] == 'j' || ins[1] =='w' || ins[0] == 'b' || ins[0] =='a' || ins[0] == 'm' || ins[1] =='a' || ins[0] == 'd'){
 	if (ins != NULL){
   		printf ("i:%s\n",ins);     // Aqui deberias guardar tu dato en el array!
    	d = strtok (NULL, " ,()");  // Aca tambien iria solo la coma.!!
 
  	}

  	
 	if (d != NULL && ins[0] != 'j'){
   		printf ("d:%s\n",d);     // Aqui deberias guardar tu dato en el array!
    	t = strtok (NULL, " ,()");  // Aca tambien iria solo la coma.!!
  	}
 	if (t != NULL && ins[0] != 'j' && ins[1] !='a'){
   		printf ("t:%s\n",t);     // Aqui deberias guardar tu dato en el array!
    	s = strtok (NULL, " ,()");  // Aca tambien iria solo la coma.!!
  	}
  	}

  		rd=d;
  		rt=t;
  		rs=s;
  		b.lineasControl.codigoOP = 15;//label:
  		b.nLinea=n;

  		if (instruccion[0]=='j'){
			i=2;
			while(instruccion[i]!='\n'){
				b.nombreOff2[i-2]=instruccion[i];
				i++;
			}
			printf("off2:%s.\n", b.nombreOff2 );
		}

  		if (instruccion[0]=='b'){
			i=14;
			while(instruccion[i]!='\n'){
				b.nombreOff2[i-14]=instruccion[i];
				i++;
			}
			printf("off2:%s.\n", b.nombreOff2 );
		}


  	if (d[1]=='t'){
		if (d[2]=='0'){	rd="$t0";}
		if (d[2]=='1'){	rd="$t1";}
		if (d[2]=='2'){	rd="$t2";}
		if (d[2]=='3'){	rd="$t3";}
		if (d[2]=='4'){	rd="$t4";}
		if (d[2]=='5'){	rd="$t5";}
		if (d[2]=='6'){	rd="$t6";}
		if (d[2]=='7'){	rd="$t7";}
		if (d[2]=='8'){	rd="$t8";}
		if (d[2]=='9'){	rd="$t9";}
	}



	if (d[1]=='a'){
		if (d[2]=='0'){	rd="$a0";}
		if (d[2]=='1'){	rd="$a1";}
		if (d[2]=='2'){	rd="$a2";}
		if (d[2]=='3'){	rd="$a3";}
	}
	if (d[1]=='v'){
		if (d[2]=='0'){	rd="$v0";}
		if (d[2]=='1'){	rd="$v1";}
	}


	if (t[1]=='t'){
		if (t[2]=='0'){	rt="$t0";}
		if (t[2]=='1'){	rt="$t1";}
		if (t[2]=='2'){	rt="$t2";}
		if (t[2]=='3'){	rt="$t3";}
		if (t[2]=='4'){	rt="$t4";}
		if (t[2]=='5'){	rt="$t5";}
		if (t[2]=='6'){	rt="$t6";}
		if (t[2]=='7'){	rt="$t7";}
		if (t[2]=='8'){	rt="$t8";}
		if (t[2]=='9'){	rt="$t9";}
	}
	if (t[1]=='a'){
		if (t[2]=='0'){	rt="$a0";}
		if (t[2]=='1'){	rt="$a1";}
		if (t[2]=='2'){	rt="$a2";}
		if (t[2]=='3'){	rt="$a3";}
	}
	if (t[1]=='v'){
		if (t[2]=='0'){	rt="$v0";}
		if (t[2]=='1'){	rt="$v1";}
	}

	if (t[1]=='z'){ rt="$zero"; }
	if (s[1]=='t'){
		if (s[2]=='0'){	rs="$t0";}
		if (s[2]=='1'){	rs="$t1";}
		if (s[2]=='2'){	rs="$t2";}
		if (s[2]=='3'){	rs="$t3";}
		if (s[2]=='4'){	rs="$t4";}
		if (s[2]=='5'){	rs="$t5";}
		if (s[2]=='6'){	rs="$t6";}
		if (s[2]=='7'){	rs="$t7";}
		if (s[2]=='8'){	rs="$t8";}
		if (s[2]=='9'){	rs="$t9";}
	}
	if (s[1]=='a'){
		if (s[2]=='0'){	rs="$a0";}
		if (s[2]=='1'){	rs="$a1";}
		if (s[2]=='2'){	rs="$a2";}
		if (s[2]=='3'){	rs="$a3";}
	}
	if (s[1]=='v'){
		if (s[2]=='0'){	rs="$v0";}
		if (s[2]=='1'){	rs="$v1";}
	}
	if (s[1]=='z'){ rs="$zero";}



	if(ins[0]=='a' && ins[1]=='d'){
			b.nombreOP = "add";
			b.lineasControl.codigoOP = 0;
			b.nombreRd = rd;
			b.nombreRs = rs;
			b.nombreRt = rt;
		

	if(ins[3] == 'i'){
			b.nombreOP = "addi";
			b.lineasControl.codigoOP = 1;
			b.nombreRd = rd;
			b.nombreRs = rs;
			b.nombreRt = rt;
			b.valorRs=atoi(b.nombreRs);
		}
	
	}

	if (ins[0] == 'm' && ins[1]=='u'){
			b.nombreOP = "mul";
			b.lineasControl.codigoOP =2;
			b.nombreRd = rd;
			b.nombreRs = rs;
			b.nombreRt = rt;
				}
	if (ins[0]=='d' && ins[1]=='i'){
			b.nombreOP = "div";
			b.lineasControl.codigoOP=3;
			b.nombreRd=rd;
			b.nombreOff="hi";
			b.nombreRs = rs;
			b.nombreRt = rt;
	}
	
	

	if (ins[0] == 'm' && ins[1] == 'f'){
		b.nombreRd = rd;
		b.nombreRt="lo";
		b.nombreRs="hi";
		if(ins[2]=='l'){
			b.nombreOP = "mflo";
			b.lineasControl.codigoOP = 4;
		}

		if(ins[2] == 'h'){
			b.nombreOP = "mfhi";
			b.lineasControl.codigoOP = 5;
		}

	}

	if (ins[1]== 'w' ){
		b.nombreRd=rd;
		b.nombreRt=rt;//0
		b.nombreRs=rs;//($rs)

		printf("nombrerd: %s\n", b.nombreRd);
		printf("nombrert: %s\n", b.nombreRt);
		printf("nombrers: %s\n", b.nombreRs);

		if (ins[0]=='l'){ 
			b.nombreOP="lw";
			b.lineasControl.codigoOP=6;
		}
		if (ins[0]=='s'){
			b.nombreOP="sw";
			b.lineasControl.codigoOP=7;
		}
	}

	if (ins[0]== 'l' && ins[1]=='a'){
		b.nombreOP="la";
		b.lineasControl.codigoOP=8;
		b.nombreRd=rd;
		b.nombreOff=rt;//label
	}
	if(ins[0] == 'j'){
		b.nombreOP="j";
		b.lineasControl.codigoOP =9;
		b.nombreRd=b.nombreOff2;
		printf("j=%s.\n",b.nombreOff2);

	}
	if(ins[0] == 'b'){
		b.nombreRt=rd; //r1
		b.nombreRs=rt; //r2
		b.nombreOff=b.nombreOff2; //label
		if (ins[1]=='e'){
			b.nombreOP="beq";
			b.lineasControl.codigoOP=10;
		}
		if (ins[1]=='g'){
			b.nombreOP="bgt";
			b.lineasControl.codigoOP=11;
		}
		if (ins[1]=='l'){
			b.nombreOP="blt";
			b.lineasControl.codigoOP=12;
		}

	}
	
	return b;
}

//asigna valores a los registros
buffer ID(buffer b, registro r){
	printf("Etapa ID op: %d\n", b.lineasControl.codigoOP);


	if (b.lineasControl.codigoOP == 0){
			b.valorRs=obtenerI(r,b.nombreRs);
			b.valorRt=obtenerI(r,b.nombreRt);
			printf("valor RT %s: %d\n", b.nombreRt, b.valorRt);
	}
	if (b.lineasControl.codigoOP == 1){
		b.valorRt=obtenerI(r,b.nombreRt);
		printf("addi = %sla\n",b.nombreRt);

	}
	if (b.lineasControl.codigoOP == 2 || b.lineasControl.codigoOP==3){
		b.valorRs=obtenerI(r,b.nombreRs);
		b.valorRt=obtenerI(r,b.nombreRt);
	}
	if (b.lineasControl.codigoOP==4 || b.lineasControl.codigoOP==5)//mflo y mfhi
	{
		b.valorRt=obtenerI(r,b.nombreRt);//lo
		b.valorRs=obtenerI(r,b.nombreRs);//hi
	}

	if(b.lineasControl.codigoOP==10 || b.lineasControl.codigoOP==11 || b.lineasControl.codigoOP==12){
		b.valorRt = obtenerI(r, b.nombreRt);//r1
		b.valorRs = obtenerI(r, b.nombreRs);//r2

	}

	if (b.lineasControl.codigoOP==6 || b.lineasControl.codigoOP==7)
	{
		b.valorRd=obtenerI(r, b.nombreRd);
		b.valorRt=obtenerI(r, b.nombreRt);
		b.valorRs=obtenerI(r, b.nombreRs);
		printf("rt----%d\n",b.valorRt );
		printf("rs---%d\n",b.valorRs );

	}
	if (b.lineasControl.codigoOP==8){ //la
		
	}

	return b;
}

buffer EX(buffer b){
	printf("Etapa EX op: %d\n", b.lineasControl.codigoOP);

	if(b.lineasControl.codigoOP == 0 || b.lineasControl.codigoOP== 1){
		b.valorRd = (b.valorRt+b.valorRs);
	}
	if(b.lineasControl.codigoOP == 2){
		b.valorRd = (b.valorRs*b.valorRt);
		printf("mul: %d\n", b.valorRd);
	}

	if (b.lineasControl.codigoOP ==3){
		b.valorRd = (b.valorRt/b.valorRs);
		b.offset2 = (b.valorRt%b.valorRs);
	}
	if (b.lineasControl.codigoOP==4){
		b.valorRd=b.valorRt;
	}
	if (b.lineasControl.codigoOP==5){
		b.valorRd=b.valorRs;
	}
	if (b.lineasControl.codigoOP==10 || b.lineasControl.codigoOP==11 || b.lineasControl.codigoOP==12){
		b.valorRd=b.valorRt-b.valorRs;
	}
	if (b.lineasControl.codigoOP==6 || b.lineasControl.codigoOP==7)//Load Word
	{
		b.offset=b.valorRt+b.valorRs;
		printf("valor off: %d\n", b.offset);
	}

	return b;
}


buffer MEM(buffer b,int memoria[]){

	printf("Etapa MEM op: %d\n", b.lineasControl.codigoOP);
	int i=0;

	if(b.lineasControl.codigoOP==10){
		if (b.valorRd==0){
			b.siguiente=b.nombreOff2;
		}
	}
	else if(b.lineasControl.codigoOP==11){
		if (b.valorRd>0){
			b.siguiente=b.nombreOff2;
		}
	}
	else if(b.lineasControl.codigoOP==12){
		if (b.valorRd<0){
			b.siguiente=b.nombreOff2;
		}
	}
	else if (b.lineasControl.codigoOP==9){//j
		b.siguiente = b.nombreOff2;
		printf("\n\nnombre off2: %s\n\n", b.nombreRd);
	}

	else if (b.lineasControl.codigoOP==6){
		b.valorRd=memoria[b.offset];
	}
	else if (b.lineasControl.codigoOP==7){
		memoria[b.offset]=b.valorRd;;
	}

	while(b.nombreOff2[i]!='\0'){
		b.nombreOff2[i] = '\0';
		i++;
	}
	printf("dentrodelMEM:%s.\n" ,b.nombreOff2);

	return b;
}

registro WB(buffer b, registro r){
	printf("Etapa WB op: %d\n", b.lineasControl.codigoOP);

	if (b.lineasControl.codigoOP == 0 || b.lineasControl.codigoOP == 1){
		r = editar(r, b.nombreRd, b.valorRd);
	}
	if (b.lineasControl.codigoOP == 2 ){
		r = editar(r, b.nombreRd, b.valorRd );
	}
	if (b.lineasControl.codigoOP == 3){
		r = editar(r, b.nombreRd, b.valorRd );
		r = editar(r, b.nombreOff, b.offset2);
	}

	if (b.lineasControl.codigoOP==4 || b.lineasControl.codigoOP==5)	{
		r = editar(r, b.nombreRd, b.valorRd);
	}
	if (b.lineasControl.codigoOP==6){
		r = editar(r, b.nombreRd, b.valorRd);
	}

	return r;
}

void imprimirBuffer(buffer b){

printf("operacion a ejecutar: %s\n", b.nombreOP );
printf("registro rd: %s\n", b.nombreRd );
printf("valor rd: %d\n", b.valorRd );
printf("registro rs: %s\n", b.nombreRs);
printf("valor rs: %d\n", b.valorRs );
printf("registro rt: %s\n", b.nombreRt );
printf("valor rt: %d\n\n", b.valorRt );

}