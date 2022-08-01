#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>

typedef int item;
const int indefinido = -9999;

typedef struct nodo
{
    item dato;
    struct nodo *siguiente;
}nodo;

typedef struct listaC
{
    nodo *ventana;
    int tamanio;
}listaC;

//Declaracion de funciones
void CreaLista(listaC *lc);
bool EsLCVacia(listaC lc);
void InsertaEnLista(listaC *lc, item dato);
void Borrar(listaC *lc);

void CreaLista(listaC *lc)
{
    lc->ventana = NULL;
    lc->tamanio = 0;
}

bool EsLCVacia(listaC lc)
{
    return lc.tamanio == 0;
}

void InsertaEnLista(listaC *lc, item dato)
{
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    if(!EsLCVacia(*lc))
    {
        nuevoNodo->siguiente = lc->ventana;
        lc->ventana = nuevoNodo;
        lc->tamanio++;
    }else
    {
        nuevoNodo->siguiente = nuevoNodo;
        lc->ventana = nuevoNodo;
        lc->tamanio++;
    }
}

void Borrar(listaC *lc)
{
    if(!EsLCVacia(*lc))
    {
        nodo *aux = lc->ventana;
        if(lc->tamanio > 1)
        {
            lc->ventana = lc->ventana->siguiente;
        }else
        {
            lc->ventana = NULL
        }
        lc->tamanio-=1;
        free(aux);
    }   
}