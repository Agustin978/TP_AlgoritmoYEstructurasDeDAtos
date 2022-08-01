#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>

typedef int item;
const int indefinido = -9999;

typedef struct nodoAB
{
    item dato;
    struct nodoAB *izq;
    struct nodoAB *der;
}nodoAB;

//declaracion de funciones
void ABVacio(nodoAB *arbol);
nodoAB CreaNodo(item dato);
void ArmaAB(nodoAB *I, item dato, nodoAB *D);
bool EsABVacio(nodoAB *arbol);
void recorrePreorden(nodoAB arbol);
item Raiz(nodoAB arbol);

int main()
{
    nodoAB arbol, I, D;
    ABVacio(&arbol);

    if(EsABVacio(&arbol))
    {
        printf("\nEl arbol esta vacio.\n");
    }
    
    I = CreaNodo(2);
    D = CreaNodo(3);
    ArmaAB(&I, 1, &D);

    

    return 0;
}

void ABVacio(nodoAB *arbol)
{
    arbol = NULL;
}

nodoAB CreaNodo(item dato)
{
    nodoAB *nuevo = (nodoAB*)malloc(sizeof(nodoAB));
    nuevo->dato = dato;
    nuevo->der = NULL;
    nuevo->izq = NULL;
}

void ArmaAB(nodoAB *I, item dato, nodoAB *D)
{
    nodoAB nuevo;
    nuevo = CreaNodo(dato);
    nuevo.der = D;
    nuevo.izq = I;
}

bool EsABVacio(nodoAB *arbol)
{
    return arbol == NULL;
}

item Raiz(nodoAB arbol)
{
    if(!EsABVacio(&arbol))
    {
        return arbol.dato;
    }else
    {
        return indefinido;
    }
}

void recorrePreorden(nodoAB arbol)
{
    if(arbol.dato != NULL)
    {
        printf("%d\n", Raiz(arbol));
        recorrePreorden(*arbol.izq);
        recorrePreorden(*arbol.der);
    }
}