#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int item;
const int indefinido = -9999;

typedef struct nodo
{
    item dato;
    struct nodo *siguiente;
}nodo;

typedef struct fila
{
    nodo *cabecera;
    nodo *final;
    int tamanio;
}Fila;

//Declaracion de funciones
void CreaFila(Fila *f);
bool EsFilaVacia(Fila f);
void EnFila(Fila *f, item dato);
void DeFila(Fila *f);
void MuestraFila(Fila f);
void LiberaMemoria(Fila *f);
void EnFilan(Fila *f, item dato, int k);
int Pertenece(Fila f, item dato);

int main()
{
    Fila f;
    CreaFila(&f);

    printf("\nMuestra 1:");
    MuestraFila(f);

    EnFila(&f, 1);
    EnFila(&f, 2);
    EnFila(&f, 3);
    EnFila(&f, 4);
    EnFila(&f, 5);
    EnFila(&f, 6);
    EnFila(&f, 7);

    printf("\nMuestra 2:");
    MuestraFila(f);

    EnFilan(&f, 35, 12);

    printf("\nEl numero 35 se encontro en la lista un total de %d veces.", Pertenece(f, 35));
    printf("\nEl numero 4 se encontro en la lista un total de %d veces.", Pertenece(f, 4));

    DeFila(&f);

    printf("\nEl numero 1 se encontro en la lista un total de %d veces.", Pertenece(f, 1));
    
    printf("\nMuestra 3:");
    MuestraFila(f);

    LiberaMemoria(&f);
    printf("\nMuestra 4:");
    MuestraFila(f);

    return 0;
}

void CreaFila(Fila *f)
{
    f->cabecera = NULL;
    f->final = NULL;
    f->tamanio = 0;
}

bool EsFilaVacia(Fila f)
{
    return f.tamanio == 0;
}

void EnFila(Fila *f, item dato)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if(EsFilaVacia(*f))
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
    if(!EsFilaVacia(*f))
    {
        nodo *aux = f->cabecera;
        if(f->tamanio > 1)
        {
            f->cabecera = f->cabecera->siguiente;
        }else
        {
            f->cabecera = NULL;
            f->final = NULL;
        }
        f->tamanio -= 1;
        free(aux);
    }
}

void MuestraFila(Fila f)
{
    if(!EsFilaVacia(f))
    {
        nodo *aux = f.cabecera;
        while (aux != NULL)
        {
            printf("\n-> %d", aux->dato);
            aux = aux->siguiente;
        }
    }else
    {
    printf("\nLa fila esta vacia.\n");
    }
}

void LiberaMemoria(Fila *f)
{
    while (!EsFilaVacia(*f))
    {
        DeFila(f);
    }
}

void EnFilan(Fila *f, item dato, int k)
{
    for (int i = 0; i < k; i++)
    {
        EnFila(f,dato);
    }
}

int Pertenece(Fila f, item dato)
{
    if(!EsFilaVacia(f))
    {
        nodo *aux = f.cabecera;
        int contador = 0;
        while (aux != NULL)
        {
            if(aux->dato == dato)
            {
                contador++;
            }
            aux = aux->siguiente;
        }
        return contador;
        
    }else
    {
        return 0;
    }
}