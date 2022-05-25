#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

typedef int item;
const item indefinido = -9999;

typedef struct nodo
{
    item dato;
    struct nodo *siguiente;
}nodo;

typedef struct
{
    struct nodo *cabecera;
    int longitud;
}ListaC;

//Declaracion de funciones
ListaC LCcrear();
bool EsLCVacia(ListaC LC);
ListaC LCInsertar(ListaC LC, item k);
ListaC LCBorrar(ListaC LC);
ListaC LCBorrarK(ListaC LC, item k);
ListaC LCRotar(ListaC LC);
item LCValor(ListaC LC);
int ContarK(ListaC LC, item k);

int main()
{
    return 0;
}

ListaC LCcrear()
{
    ListaC LC;
    LC.cabecera->siguiente = NULL;
    LC.longitud = 0;
    return LC;
}

bool EsLCVacia(ListaC LC)
{
    if (LC.longitud == 0)
    {
        return true;
    }
    return false;
}

ListaC LCInsertar(ListaC LC, item k)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));

    nuevo->dato = k;
    if(EsLCVacia(LC))
    {
        nuevo->siguiente = nuevo;
        
    }
    
}

