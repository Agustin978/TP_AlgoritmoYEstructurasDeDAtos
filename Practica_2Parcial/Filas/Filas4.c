#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int item;
const int indefinido = -9999;

typedef struct nodo
{
    item dato;
    struct nodo* siguiente;
}nodo;

typedef struct fila
{
    nodo* cabecera;
    nodo* final;
    int tamanio;
}Fila;

//Declaracion de funciones
void CreaFila(Fila *f);
bool EsFilaVacia(Fila *f);
void EnFila(Fila *f, item dato);
void DeFila(Fila *f);
void MuestraFila(Fila f);

int main()
{
    Fila F;
    CreaFila(&F);

    printf("\nMuestra 0:\n");
    MuestraFila(F);

    EnFila(&F,1);
    EnFila(&F,2);
    EnFila(&F,3);
    EnFila(&F,4);
    EnFila(&F,5);
    EnFila(&F,6);
    EnFila(&F,7);

    printf("\nMuestra 1:\n");
    MuestraFila(F);

    DeFila(&F);
    DeFila(&F);
    DeFila(&F);

    printf("\nMuestra 2:\n");
    MuestraFila(F);

    DeFila(&F);
    DeFila(&F);
    DeFila(&F);
    DeFila(&F);

    printf("\nMuestra 3:\n");
    MuestraFila(F);

    return 0;
}

void CreaFila(Fila *f)
{
    f->cabecera = NULL;
    f->final = NULL;
    f->tamanio = 0;
}

bool EsFilaVacia(Fila *f)
{
    return f->tamanio == 0;
}

void EnFila(Fila *f, item dato)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if(EsFilaVacia(f))
    {
        f->cabecera = nuevoNodo;
        f->final = nuevoNodo;
        f->tamanio++;
    }else
    {
        f->final->siguiente = nuevoNodo;
        f->final = nuevoNodo;
        f->tamanio++;
    }
}

void DeFila(Fila *f)
{
    if(!EsFilaVacia(f))
    {
        struct nodo* borrar;
        borrar = f->cabecera;
        if(f->cabecera == f->final)
        {
            f->cabecera = NULL;
            f->final = NULL;
            f->tamanio -= 1;
            free(borrar);
        }else
        {
            f->cabecera = f->cabecera->siguiente;
            f->tamanio -= 1;
            free(borrar);
        }
    }
}

void MuestraFila(Fila f)
{
    if (!EsFilaVacia(&f))
    {
        nodo *aux = f.cabecera;
        while (aux != NULL)
        {
            printf("\n-> %d", aux->dato);
            aux = aux->siguiente;
        }
    }else
    {
        printf("\nLa lista esta vacia imbesil.\n");
    }
    
}