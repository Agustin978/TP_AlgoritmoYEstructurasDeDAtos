#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int item;
const int indefinido = -9999;

struct nodo
{
    item dato;
    struct nodo *nodSiguiente;
};

typedef struct nodo *Nodo;

typedef struct
{
    Nodo ventana;
    item tamanio;
}ListaCircular;

//Declaracion de funciones
ListaCircular LCVacia(); //Crea una lista circular vacia
bool EsLCVacia(ListaCircular LC); //Determina se la lista esta vacia
ListaCircular LCInsertar(ListaCircular LC, item dato); //Inserta el nuevo nodo a la LC
ListaCircular LCBorrar(ListaCircular LC); //Elimina el elemento que se encuentra en la ventana de la lista
ListaCircular LCRotar(ListaCircular LC); //Rota la lista circular
item LCLongitud(ListaCircular LC); //Retorna la longitud de la lista circular
void muestraLC(ListaCircular LC);

void main()
{
    ListaCircular LC = LCVacia();

    muestraLC(LC);

    LC = LCInsertar(LC,1);
    LC = LCInsertar(LC,2);
    LC = LCInsertar(LC,3);
    LC = LCInsertar(LC,4);
    LC = LCInsertar(LC,5);
    LC = LCInsertar(LC,1);

    muestraLC(LC);

    printf("\nLa longitud de la LC es: %d", LCLongitud(LC));
}

ListaCircular LCVacia()
{
    ListaCircular LC;
    LC.ventana = NULL;
    LC.tamanio = 0;
    return LC;
}

bool EsLCVacia(ListaCircular LC)
{
    if(LC.tamanio == 0)
    {
        return true;
    }
    return false;
}

ListaCircular LCInsertar(ListaCircular LC, item dato)
{
    Nodo nuevo = (Nodo)malloc(sizeof(struct nodo)); //Reservo memoria para el ingreso del nuevo dato
    nuevo->dato = dato;
    if(EsLCVacia(LC))
    {
        nuevo->nodSiguiente = nuevo;
        LC.ventana = nuevo;
        LC.tamanio += 1;
        //printf("Ingresado dato\n");
    }else
    {
        nuevo->nodSiguiente = LC.ventana;
        LC.ventana = nuevo;
        LC.tamanio += 1;
        printf("Ingresado nuevo dato %d\n", LC.ventana->dato);
    }
    return LC;
}

ListaCircular LCBorrar(ListaCircular LC)
{
    if(EsLCVacia(LC))
    {
        printf("\nNo hay elementos en la lista.\n");
    }else
    {
        Nodo nodAux = LC.ventana->dato;
        LC.ventana = LC.ventana->nodSiguiente;
        LC.tamanio -= 1;
    }
    return LC;
}

ListaCircular LCRotar(ListaCircular LC)
{
    LC.ventana = LC.ventana->nodSiguiente;
    return LC;
}

item LCLongitud(ListaCircular LC)
{
    return LC.tamanio;
}

void muestraLC(ListaCircular LC)
{
    if(EsLCVacia(LC))
    {
        printf("\nLa lista circular esta vacia, no hay nada que mostrar.\n");
    }else
    {
        ListaCircular LCAux = LC;
        int i = 0;
        int cantidad = LCLongitud(LC);
        while (i<cantidad)
        {
            i++;
            printf("->%d->",LCAux.ventana->dato);
            LCAux = LCRotar(LCAux);
        }
    }
}