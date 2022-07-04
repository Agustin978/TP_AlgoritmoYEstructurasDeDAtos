#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Fila.h"
#define max 100

int obtenerDigitos(int arre[], int cantidad);
void ordenar(int arre[], int cantidaDigitos,int n, Fila arregloFila[]);
void concatenar(int arre[], int n, Fila arregloFila[]);
void mostrarArreglo(int arre[], int n);
void mostrarFilas(Fila arregloFila[]);

int main(){
    int cantDigitos, n=7;
    int arre[] = {2, 145, 25, 96, 4, 552, 6};
    Fila arregloFila[10];

    for(int h=0; h<10; h++){
        arregloFila[h] = FilaVacia();
    }

    cantDigitos = obtenerDigitos(arre, n);

    ordenar(arre, cantDigitos, n, arregloFila);

    mostrarArreglo(arre, n);

    return 0;    
}


int obtenerDigitos(int arre[], int cantidad){
    int contador=0, anterior=0;  //contador lleva la cuenta de la cantidad de digitos que tiene un numero
    int numero;

    for(int i=0; i<cantidad; i++){
        
        numero = arre[i]; //asigno cada valor a una variable para no modificar los valores del arreglo
        
        while(numero!=0){
            numero = numero/10;
            contador++;
        }

        if(contador > anterior){
            anterior = contador;  //anterior guarda la mayor cantidad de digitos que se encontro entre los elementos del arreglo
        }
        
        contador = 0; //reinicio el cantodor para leer un nuevo numero con otra cantidad de digitos distinta
    }    
    return anterior;
}

void ordenar(int arre[], int cantidaDigitos,int n, Fila arregloFila[]){
    int numero;
    for(int j=0; j<cantidaDigitos; j++){                         //aumenta segun si trabaja con la unidad, decena, centena, etc.
        for(int i=0; i<n; i++){                     //aumenta para recorrer todos los elementos del arreglo
            numero = (int)(arre[i]/pow(10,j))%10;   //PREGUNTAR si esta bien hacer el casteo      
            arregloFila[numero] = Enfila(arregloFila[numero], arre[i]);
        }
        concatenar(arre, n, arregloFila);
    }
}

void concatenar(int arre[], int n, Fila arregloFila[]){
    int indice = 0;
    for(int i=0; i<10; i++){
        while(!EsFilaVacia(arregloFila[i])){
            
            arre[indice] = Frente(arregloFila[i]);
            arregloFila[i] = Desfila(arregloFila[i]);
            indice++;
        }    

    }
}
/* NOTA: probar con una variable que incremente a medida que incrementa el for de lista, esta seria el indice del arreglo*/

void mostrarArreglo(int arre[], int n){
    for(int i=0; i<n; i++){
        printf("%d - ", arre[i]);
    }
}





void mostrarFilas(Fila arregloFila[]){
    for(int i=0; i<10; i++){
        mostrarFila(arregloFila[i]);
        printf("\n");
    }
}