#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Filas.h"

//Declaracion de funciones
int CantDigit(int numOrdenar[]); //Recibe el arreglo de numeros a ordenar y retorna la maxima cantidad de digitos
void RadixSort(int numOrdenar[], Fila arrFilas[], int numElementos);
void concatenar(int numOrdenar[], Fila arrFilas[], int numElementos); //Funcion para concatenar los elementos del arreglo
void muestraArr(int numOrdenar[], int numElementos); //Muestra el arreglo

void main()
{
    int numAOrdenar[] = {230, 410, 721, 63, 345, 295, 195, 345, 126, 147, 78, 508, 679, 209, 19};
    Fila arrFilas[10];
    int numElementos;

    for(int i = 0; i < 10; i++)
    {
        arrFilas[i] = FilaVacia(); //Creo una fila para cada celda del arreglo
    }

    

    //printf("\nLa cantidad maxima de digitos es: %d", CantDigit(numAOrdenar));
    numElementos = (sizeof(numAOrdenar) / sizeof(numAOrdenar[0]));

    muestraArr(numAOrdenar,numElementos);

    printf("\nCantidad de elementos en el arreglo: %d", numElementos);

    RadixSort(numAOrdenar, arrFilas, numElementos);
    
    printf("\n");
    muestraArr(numAOrdenar, numElementos);
}

int CantDigit(int numOrdenar[])
{
    int numero, contador = 0, max = 0;
    int cantNumeros = sizeof(numOrdenar)/sizeof(numOrdenar[0]); //Obtengo la longitud del arreglo
    for(int i = 0; i < cantNumeros; i++)
    {   
        if(numOrdenar[i] > max)
        {
            max = numOrdenar[i];
        }
    }

    while (max != 0)
    {
        max = max / 10;
        contador++;
    }
    return contador;
}

void RadixSort(int numOrdenar[], Fila arrFilas[], int numElementos)
{
    int cantDigitos, numero;
    cantDigitos = CantDigit(numOrdenar); //Obtengo la cantidad de digitos maxima
    //numElementos = sizeof(numOrdenar)/sizeof(numOrdenar[0]); //Obtengo la longitud del arreglo
    //printf("\n->%d\n", numElementos);
    for(int i = 0; i < cantDigitos; i++) //Aumenta para trabajar con los distintos digitos de un numero, iniciando desde el de mas atras
    {
        for(int j = 0; j < numElementos; j++)  //Aumenta para trabajar con todos los elementos del arreglo de numeros
        {
            numero = (int)(numOrdenar[j] / pow(10,i))%10; //Determino en que posicion del arreglo de filas se guardara el elemento
            arrFilas[numero] = EnFila(arrFilas[numero], numOrdenar[j]);  //Agrego en el arreglo de filas 
        }
        concatenar(numOrdenar, arrFilas, numElementos);
    }
}

void concatenar(int numOrdenar[], Fila arrFilas[], int numElementos)
{
    int indice = 0;

    for(int i = 0; i < 10; i++)
    {
        while (!EsFilaVacia(arrFilas[i]))
        {
            numOrdenar[indice] = FrenteFila(arrFilas[i]);
            arrFilas[i] = DeFila(arrFilas[i]);
            indice++;
        }
    }
    //muestraArr(numOrdenar, numElementos);
}

void muestraArr(int numOrdenar[], int numElementos)
{
    //printf("\nIteracion %d", iteracion);
    for(int i = 0; i < numElementos; i++)
    {
        printf(" %d /", numOrdenar[i]);
    }
}