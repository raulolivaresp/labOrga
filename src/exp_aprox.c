#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"
#include "pipeline.h"

typedef struct comando
{
	char linea[50];
	char *l;
	int codigo;

}comando;

typedef struct programa
{
	comando a[50];

}programa;

typedef struct hazzard{
	char* tipo;
	int linea;
}hazzard;

typedef struct hazzardTotal{
	hazzard t[250];
}totalH;

programa leerArchivo(programa p, char* archivo){

	FILE * File;

	comando b;
	char elemento[50];
	int n;

	char separador[] = " ";	
	int i=1;

	File = fopen(archivo, "r");

	//archivo encontrado?
	if(File==NULL){
        printf("Archivo vacio");
        fclose(File);
        return p;
    }
    //si es q encontro el archivo
    else{
    	//inicio lee el archivo
    	n=1;
	   	while(feof(File) == 0){
		  	fgets(b.linea,1000,File);
			if (b.linea[0] != '\n') {

			b.l=b.linea;
		  	b.codigo=n;
			printf("%s\n",b.l );

		  	p.a[i]=b;
		  	i++;
		  	}

		n++;
    	}
		fclose(File);
    	return p;
    }
   
}


void archivoHazzard(totalH h, int largo){

	FILE * File;
	File = fopen ("HAZARDS.txt", "w" );
	char cadena0[30], cadena1[30];
	int i=0;

	while(i!=largo){
	sprintf(cadena0, "tipo: %s\n", h.t[i].tipo); 
	sprintf(cadena1, "linea: %d\n", h.t[i].linea); 
	i++;

	fputs(cadena0, File);
	fputs(cadena1, File);
	}
}

//para los jump y branch
int saltar(programa p,char label[]){
	int code=0;
	int i=0;
	char d[20];	
	char puntos[1];
	puntos[0] = ':';
	puntos[1] = '\n';

	while(i<20){
		d[i]='\0';
		i++;
	}

	i=0;
	while(label[i]!='\0'){
		d[i]=label[i];
		i++;
	}
	d[i]=':';
	d[i+1]='\n';

	printf("\n.%s.\n", label );
	printf("\n.%s.\n", d);

	if (d != ":"){
		i=1;			
		while(p.a[i].codigo!=0){
		
			printf("%s\n", p.a[i].linea);

			if (d[0]==p.a[i].linea[0]){
				code=i;
			}
			i++;

		}
	}
	return code;
}

hazzard hDatos(buffer ID, buffer EX, hazzard h, int l){
	
	if (ID.lineasControl.codigoOP != 99 && EX.nombreOP[0]!='b' ){
		
		if (ID.nombreRt == EX.nombreRd || ID.nombreRs == EX.nombreRd){
			h.tipo="hazard de datos";
			h.linea = EX.nLinea;
		}
	}
	return h;
}

hazzard hControl(buffer ID, hazzard h, int l){

	if (ID.nombreOP[0]=='b' || ID.nombreOP[0]=='j'){
		h.linea =ID.nLinea;
		h.tipo = "hazard de control";
	}

	return h;
}


int main(int argc, char *argv[]){

	//iniciamos memoria ARREGLO
	int ARREGLO[1000];

	//coloca todas los registros en 0
	struct registro t;
	t=iniciacion(t);

	//declara e inicializa los buffers vacios
	buffer bIFID;
	buffer bIDEX;
	buffer bEXMEM;
	buffer bMEMWB;
	bIFID=nop(bIFID);
	bIDEX=nop(bIDEX);
	bEXMEM=nop(bEXMEM);
	bMEMWB=nop(bMEMWB);
	


	//progrma leer instrucciones
	programa p;
	p = leerArchivo(p ,"exp_aprox.asm");

	ARREGLO[0]=5;//asignacion random en la memoria
	int code=0; //linea salto a otro label
	char label[20]="\0";
	int i=1;
	int tamano=1;//tamaño programa

	//tamaño n lineas en el programa
	while(p.a[tamano].codigo!=0){
		tamano++;
	}
	printf("total operaciones: %d\n", tamano );

	//hazzar de datos
	totalH haz;
	hazzard h;
	int nHaz=0;
	int esperas=0;
	int ciclos=1;
	int control=0;

while(p.a[i].codigo!=0 ){


if (esperas==0 && control==0){

if(i==1){
	bIFID=IF(p.a[i].linea, p.a[i].codigo, bIFID);
	printf("wea1\n");

}
else if (i==2){
	bIDEX =ID(bIFID, t);
	bIFID=IF(p.a[i].linea, p.a[i].codigo, bIFID);
	printf("wea2\n");

}
else if (i==3){
	bEXMEM = EX(bIDEX);
	bIDEX =ID(bIFID, t);
	bIFID=IF(p.a[i].linea, p.a[i].codigo, bIFID);
	printf("wea3\n");
	if (bIFID.lineasControl.codigoOP==15){
		i++;
		bIFID=nop(bIFID);
		if (p.a[i].codigo !=0){
			bIFID= IF(p.a[i].linea, p.a[i].codigo, bIFID);//instruccion i+4
		}
	}
}
else if (i==4){
	bMEMWB = MEM(bEXMEM,ARREGLO);
	bEXMEM = EX(bIDEX);
	bIDEX =ID(bIFID, t);
	bIFID=IF(p.a[i].linea, p.a[i].codigo, bIFID);
	printf("wea4\n");
	if (bIFID.lineasControl.codigoOP==15){
		i++;
		bIFID=nop(bIFID);
		if (p.a[i].codigo !=0){
			bIFID= IF(p.a[i].linea, p.a[i].codigo, bIFID);//instruccion i+4
		}
	}
}
else{

t = WB(bMEMWB, t);//i nstruccion i
bMEMWB = MEM(bEXMEM,ARREGLO);//instruccion i+1
bEXMEM = EX(bIDEX);//instruccion i+2
bIDEX =ID(bIFID, t);//instruccion i+3	
bIFID= IF(p.a[i].linea, p.a[i].codigo, bIFID);//instruccion i+4

printf("wea5SS\n");
	if (bIFID.lineasControl.codigoOP==15){
		i++;
		bIFID=nop(bIFID);
		if (p.a[i].codigo !=0){
			bIFID= IF(p.a[i].linea, p.a[i].codigo, bIFID);//instruccion i+4
		}
	}	
}

i++;
}


else if (esperas!=0){

	while(esperas>0){
	t = WB(bMEMWB, t);
	bMEMWB = MEM(bEXMEM,ARREGLO);
	bEXMEM = EX(bIDEX);//instruccion i+2
	bIDEX = nop(bIDEX);
	esperas--;
	}
}
else if (control>0)
{
	while(control>1){
	t = WB(bMEMWB, t);
	bMEMWB = MEM(bEXMEM,ARREGLO);
	bEXMEM = EX(bIDEX);//instruccion i+2
	bIDEX =ID(bIFID, t);
	bIFID= nop(bIFID);
	control--;
	}
	int n=0;
	while(bMEMWB.siguiente[n]!='\0'){
		label[n]=bMEMWB.siguiente[n];
		n++;
	}

	//strcat(label, bMEMWB.siguiente);
	printf("salta?:%s.\n",label);

	code = saltar(p, label);
		printf("bus: %d\n", code);

	if (code!=0){
		i=code+1;
		code=0;
	}
	control=0;

	bMEMWB.siguiente ="";
	n=0;
	while(label[n]!='\0'){
		label[n] = '\0';
		n++;
	}


}
	


	h.linea=0;
	h=hDatos(bIFID, bEXMEM,h,i-4);
	if (h.linea!=0){
		haz.t[nHaz] = h; 
		nHaz++;
		esperas=2;
	}
	h.linea=0;
	h=hDatos(bIFID, bIDEX,h,i-3);
	if (h.linea!=0){
		haz.t[nHaz] = h; 
		nHaz++;
		esperas=3;
	}
	h.linea=0;
	h=hControl(bIFID,h,i);
	if (h.linea!=0){
		haz.t[nHaz] = h; 
		nHaz++;
		control=4;
		printf("eSTO ES UN HAZARD DE CONTROL");
	}
	h.linea=0;
	/*if (i==tamano+1){
		esperas=3;
		i++;
	}*/

printf("valor I: %d\n", i );

printf("ciclos: %d\n", ciclos );
imprimir(t);
ciclos++;

}

printf("ciclos: %d\n", ciclos );
i=0;
while(i<nHaz){

	printf("tipo: %s\n", haz.t[i].tipo);
	printf("linea: %d\n", haz.t[i].linea);
	i++;
}

archivoRegistro(t);
archivoHazzard(haz, nHaz);

	return 0;
}