#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "Fila_2.h"

//Declaracion de funciones
int maxDigit(int arrEntero[], int cantidadNumeros); //Obtengo la cantidad de digitos que tiene el numero mas grande
void orden(int arrEntero[], Fila arregloFilas[], int cantDigitos, int cantNumeros);
void concatenoOrdenado(Fila arregloFilas[], int cantNumeros, int iteracion);
void muestra(int arregloEnteros[], int cantNumeros, int iteracion);

void main()
{
    int cantDigitos, cantNumeros;
    int arrEntero[] = {679, 345, 78, 126, 209, 508, 295, 63, 195, 230, 19, 721, 147, 345, 410};
    Fila arregloFilas[10]; //Como por cada numero del 0 al 9 requiero de una fila para ingresar el numero correspondiente
    cantNumeros = sizeof(arrEntero)/sizeof(arrEntero[0]);
    

    for(int i = 0; i<10; i++)
    {
        arregloFilas[i] = filaVacia(); //Creo una fila vacia por cada elemento del arreglo
    }

    cantDigitos = maxDigit(arrEntero, cantNumeros);
    orden(arrEntero, arregloFilas, cantDigitos, cantNumeros);
}

int maxDigit(int arrEntero[], int cantNumeros)
{
    int max = 0, cantDigitos = 0;
    
    for(int i = 0; i < cantNumeros; i++)
    {
        if(arrEntero[i] > max)
        {
            max = arrEntero[i];
        }
    }

    //printf("\n%d max", max);

    while (max != 0)
    {
        max = max/10;
        cantDigitos++;
    }
    return cantDigitos;
}

void orden(int arrEntero[], Fila arregloFilas[], int cantDigitos, int cantNumeros)
{
    int numero; //Para ubicar en que posiscion del arreglo de filas ponerlo
    for(int i = 0; i < cantDigitos; i++)
    {
        for(int j = 0; i < cantNumeros; i++)
        {
            numero = (int)(arrEntero[i]/pow(10,i))%10;
            arregloFilas[numero] = enFila(arregloFilas[numero], arrEntero[j]); //Coloco en la posicion correspondiente del arreglo de filas el numero
        }
        concatenoOrdenado(arregloFilas, cantNumeros, i);
    }

    
}

void concatenoOrdenado(Fila arregloFilas[], int cantNumeros, int iteracion)
{
    int arrEnteros[cantNumeros], indice = 0;
    for(int i = 0; i < 10; i++)
    {
        while(!esFilaVacia(arregloFilas[i]))
        {
            arrEnteros[indice] = frenteFila(arregloFilas[i]);
            arregloFilas[i] = deFila(arregloFilas[i]);
            indice += 1;
        }
    }
    muestra(arrEnteros, cantNumeros, iteracion);
}

void muestra(int arregloEnteros[], int cantNumeros, int iteracion)
{
    printf("\n===========Arreglo ordenado iteracion: %d===========\n", iteracion);
    for(int i = 0; i < cantNumeros; i++)
    {
        printf("%d->%d\n", i, arregloEnteros[i]);
    }
}