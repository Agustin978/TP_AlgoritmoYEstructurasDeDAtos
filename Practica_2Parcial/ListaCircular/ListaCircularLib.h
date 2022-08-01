#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int item;
const int indefinido = -9999;

typedef struct nodo
{
    item dato;
    struct nodo *nodSiguiente;
}nodo;

typedef struct listaC
{
    nodo *ventana;
    int tamanio;
}listaC;

//Declaracion de funciones
void ListaVacia(listaC *lc);
bool EsLCVacia(listaC lc);
void LCInsertar(listaC *lc, item dato);
item LCValor(listaC lc);
void LCBorrar(listaC *lc);
void Rotar(listaC *lc);
void MuestraLista(listaC lc);
int Pertenece(listaC lc, item dato);
void LiberaMemoria(listaC *lc);

void ListaVacia(listaC *lc)
{
    lc->ventana = NULL;
    lc->tamanio = 0;
}

bool EsLCVacia(listaC lc)
{
    return lc.tamanio == 0;
}

void LCInsertar(listaC *lc, item dato)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = dato; 
    if(!EsLCVacia(*lc))
    {
        nuevoNodo->nodSiguiente = lc->ventana;
        lc->ventana = nuevoNodo;
        lc->tamanio++;
    }else
    {
        nuevoNodo->nodSiguiente = nuevoNodo;
        lc->ventana = nuevoNodo;
        lc->tamanio++;
    }
}

item LCValor(listaC lc)
{
    return lc.ventana->dato;
}

void LCBorrar(listaC *lc)
{
    if(!EsLCVacia(*lc))
    {
        nodo *aux = lc->ventana;
        if(lc->tamanio > 1)
        {
            lc->ventana = lc->ventana->nodSiguiente;
        }else
        {
            lc->ventana = NULL;
        }
        lc->tamanio -= 1;
        free(aux);
    }
}

void Rotar(listaC *lc)
{
    if(!EsLCVacia(*lc))
    {
        lc->ventana = lc->ventana->nodSiguiente;
    }
}

void MuestraLista(listaC lc)
{
    listaC aux = lc;
    if(!EsLCVacia(lc))
    {
        for(int i = 0; i < lc.tamanio; i++)
        {
            printf("%d -> ", aux.ventana->dato);
            Rotar(&aux);
        }

    }else
    {
        printf("La lista esta vacia.\n");
    }
}

int Pertenece(listaC lc, item dato)
{
    if(!EsLCVacia(lc))
    {
        nodo *aux = lc.ventana;
        int contador = 0;
        for(int i = 0; i<lc.tamanio;i++)
        {
            if(aux->dato == dato)
            {
                contador++;
            }
            aux = aux->nodSiguiente;
        }
        return contador;
    }else
    {
        return 0;
    }
}

void LiberaMemoria(listaC *lc)
{
    if(!EsLCVacia(*lc))
    {
        LCBorrar(lc);
    }
}