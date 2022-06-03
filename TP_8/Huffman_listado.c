#include "ArbolBinario.h" 	//Reemplazar con el nombre de su archivo
#include<stdio.h>
#include<string.h>
#include<conio.h>

typedef struct{
    char letra;
    float Frec;
}letraFrec;

typedef struct{
    AB arbol;
    float frec;
}ABFrec;

typedef struct{  
    char letra;
    char cod[15];
}COD;

void listado(AB a, char arre[], int *cont, COD arresalida[]);
AB Huffman(letraFrec Letras[], ABFrec arboles[]);

int main(){

    letraFrec arreLetras[] = {{'a', 0.110845}, {'b', 0.010895}, {'c', 0.048778}, {'d', 0.049769}, {'e', 0.133336 },
                              {'f', 0.007965}, {'g', 0.011638}, {'h', 0.006108}, {'i', 0.077790}, {'j', 0.002889},
                              {'k', 0.000083}};
    ABFrec arreArboles[100];
	
    char arre[15];		
	COD arresal[26];
	int cont=0;			
	AB ABHuff;

	ABHuff = Huffman(arreLetras, arreArboles);
	listado(ABHuff, &arre[0], &cont, &arresal[0]);
    imprimirPre(ABHuff);

    printf("FIN\n");
	
	return 0;
}

void listado(AB a, char arre[], int *cont, COD arresalida[])
{
	if(!EsABVacio(a)){	
        if(!EsABVacio(HijoIzquierdo(a))){
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
		if(!EsABVacio(HijoDerecho(a))){	
            (*cont)++;
			arre[*cont]='1';
		}
		listado(HijoDerecho(a),&arre[0], cont, &arresalida[0]);
		(*cont)--;
	}
}

AB Huffman(letraFrec letras[], ABFrec arboles[]){
    short posicion1=0, posicion2, cantLetras=11;
    float menor=2, segundoMenor;

    for(int i=0; i< cantLetras;i++){
        arboles[i].arbol = ABArmar(ABVacio(),letras[i].letra,ABVacio());//se crean todas las hojas con el item de arreglo letras
        arboles[i].frec = letras[i].Frec;
    }

    for(int i=0; i<(cantLetras-1); i++){
        //Busca los dos menores
        for(int i=0; i<cantLetras; i++){
            if(arboles[i].frec < menor){
                segundoMenor = menor; //segundoMenor guarda el contenido anterior de menor, ya que menor tiene el menor hasta el momento
                menor = arboles[i].frec;
                posicion2 = posicion1; //Se usa la posicion2 para comparar luego los dos arboles con la frecuencia mas baja
                posicion1 = i; //guardo la posicion para ser usada mas adeltante 
            }else
            {
                if(arboles[i].frec < segundoMenor && (arboles[i].frec != menor))
                { //Bloque para comparar el arbol analizado con el segundo arbol menor
                    segundoMenor = arboles[i].frec;
                    posicion2 = i;
                }
            }
        }
        
        //armar el arbol
        arboles[posicion2].frec= arboles[posicion1].frec + arboles[posicion2].frec; //sumo las frecuencias
        arboles[posicion2].arbol = ABArmar(arboles[posicion1].arbol, '*', arboles[posicion2].arbol);//guardo el arbol en la posicion con el segundo menor valor
        arboles[posicion1].arbol = NULL;//elimino la hoja que use
        arboles[posicion1].frec = 2;// pongo un numero de frecuencia alto para que no esta posicion nunca sea la menor(elimino el primer menor)
        menor=2;//reinicio en menor numero para la proxima iteracion, sigo guarba una menor que ya no existe, pues elimine el primer menor
        
    }
    
    //preOrden(arboles[posicion2].arbol);
    return (arboles[posicion2].arbol);
}