#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

typedef int item;
const item indefinido = -9999;

//Declaracion de las estructuras
typedef struct Nodo
{
    item dato;
    struct Nodo *sigNodo;
}Nodo;

typedef struct
{
    int altura;
    struct Nodo* cabecero;
}Pila;

//Declaracion de funciones
void creaPila(Pila *pila);
bool esPilaVacia(Pila pila);
void Push(Pila *pila, item dato);
void Pop(Pila *pila);
item Top(Pila *pila);
int Altura(Pila *pila);
item Fondo(Pila *pila);
void LiberaPila(Pila *pila);

int main()
{
    Pila *pila;
    creaPila(&pila);
    //Crea la pila vacia

    printf("\n¿Es pila vacia?");
    if(esPilaVacia(*pila))
    {
        printf("\nLa pila es vacia");
    }else
    {
        printf("\nLa pila NO es vacia");
    }
    //Agregando datos
    Push(&pila,10);
    Push(&pila,"Agustin");

    printf("\nPrimer elemento de la pila:\n");
    puts(Top(pila));
    printf("\nUltimo elemento de la pila:\n");
    puts(Fondo(pila));
    
    printf("\n¿Es pila vacia?");
    if(esPilaVacia(*pila))
    {
        printf("\nLa pila es vacia");
    }else
    {
        printf("\nLa pila NO es vacia");
        printf("La pila tiene una altura de %d", Altura(&pila));

    }

    LimpiarPila(&pila);
    return 0;
}

//Definicion de funciones
void creaPila(Pila *pila)
{
    pila->cabecero = NULL;
    pila->altura = 0;
}

bool esPilaVacia(Pila pila)
{
    if(pila.cabecero != NULL)
    {
        return true;
    }
    return false;
}

void Push(Pila *pila, item dato)
{
    Nodo *nodAux = (Nodo *)malloc(sizeof(Nodo));
    //Guardo dinamicamente memoria para el nodo en particular
    nodAux->dato = dato;
    nodAux->sigNodo = pila->cabecero;
    pila->cabecero = nodAux;
    pila->altura += 1;
}

void Pop(Pila *pila)
{
    if(!esPilaVacia(*pila))
    {
        Nodo *nodAux = pila->cabecero;
        pila->cabecero = nodAux->sigNodo;
        pila->altura -= 1;
        free(nodAux);
    }
}

item Top(Pila *pila)
{
    if(!esPilaVacia(*pila))
    {
        return pila->cabecero->dato;
    }
    puts("Pila vacia");
    exit(0);
}

int Altura(Pila *pila)
{
    if(!esPilaVacia(*pila))
    {
        return pila->altura;
    }
    return 0;
}

item Fondo(Pila *pila)
{
    if(!esPilaVacia(*pila))
    {
        Pila *pilAux = pila;
        Nodo *nodAux = pilAux->cabecero;
        while (nodAux->sigNodo != NULL)
        {
            pilAux->cabecero = nodAux->sigNodo;
            nodAux = nodAux->sigNodo;
        }
        return pilAux->cabecero->dato;
    }
    puts("Error, pila vacia");
    exit(0);
}

void LimpiarPila(Pila *pila)
{
    while (!EsPilaVacia(pila))
    {
        Pop(pila);
    }
}