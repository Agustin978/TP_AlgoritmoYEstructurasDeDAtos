
//Lic. Mar�a Cristina Werenitzky Curia
/*

La funcion Listado se encarga de recuperar los c�digos de Huffman para cada letra.

  PARAMETROS: 
			 - a: Arbol de Huffman
			 - arre[]: arreglo de caracteres que se usa para almacenar el c�digo provisoriamente
			 - cont: entero que indica la posici�n del �ltimo valor almacenado en arre
			 - arresalida[]: arreglo del tipo COD que contiene en cada posici�n una letra y el c�digo de Huffman correpondiente


  Invocaci�n de la funci�n Listado:

    char arre[15];		//Contiene el c�digo provisorio dentro del Listado
	COD arresal[26];	//Contiene la letra y su codigo 
	int cont=0;			//Mantiene el �ndice del arreglo arre
	AB ABHuff;
	....
	ABHuff=Huffman( ... );
	listado(ABHuff, &arre[0], &cont, &arresal[0]);
	....

  Para recuperar el c�digo de una letra determinada deben escribir:
																	arresal[letra-96].cod


*/
//#include "ArbolBinario.h" 	//Reemplazar con el nombre de su archivo
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ArbolBinario.h>

//Struct para ingresar en un arreglo las letras con sus respectivas frecuencias
typedef struct
{
	char letra;
	float frecuencia;
}letraFrec;

//Struct para ingresar en el arreglo los arboles que se vallan formando con sus respectivas frecuencias
typedef struct
{
	AB Arbol;
	float frecuencia;
}ABFrecuencia;

struct COD{  char letra;
			 char cod[15];
			};
//Declaracion de funciones
void listado(AB a, char arre[], int *cont, COD arresalida[]);
AB Arbol_Huffman(letraFrec Letras[], ABFrecuencia arboles[]);

int main()
{


	return 0;
}

void listado(AB a, char arre[], int *cont, COD arresalida[])
{
	if(!EsABVacio(a))
	{	
		if(!EsABVacio(HijoIzquierdo(a)))
		{       
			(*cont)++;
			arre[*cont]='0';
		}
		listado(HijoIzquierdo(a),&arre[0], cont, &arresalida[0]);
		if(EsABHoja(a)){	
			char car=Raiz(a);
			arre[(*cont)+1]='\x0';
			arresalida[car-96].letra=car;
			strcpy(arresalida[car-96].cod,&arre[1]);
			printf("%s --> %c\n",arresalida[car-96].cod,arresalida[car-96].letra); //Esto permite ver por pantalla el c�digo generado 
                        getch();												   //para la letra que se encuentra en la raiz de la hoja	
		}
		if(!EsABVacio(HijoDerecho(a)))
		{	(*cont)++;
			arre[*cont]='1';
		}
		listado(HijoDerecho(a),&arre[0], cont, &arresalida[0]);
		(*cont)--;
	}
}

AB Arbol_Huffman(letraFrec letras[], ABFrecuencia arboles[])
{
	int posicion1 = 0, posicion2, cantLetras = 26;
	double menor = 2, segundoMenor; //Segundo menor para poder armar el arreglo de arboles

	for(int i = 0; i < cantLetras; i++)
	{
		//Armo un arreglo con todas las letras en forma de hoja de un arbol
		arboles[i].Arbol = ABArmar(ABVacio(), letras[i].letra, ABVacio()); 
		arboles[i].frecuencia = letras[i].frecuencia; //Les asigno la frecuencia de la letra
	}

	for(int j = 0; j < (cantLetras-1); i++)
	{
		
	}
}