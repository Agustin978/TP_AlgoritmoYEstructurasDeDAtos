#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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
}fila;

//typedef struct fila* Fila;

//Declaracion de funciones
void CreaFila(fila *F);
bool EsFilaVacia(fila *F);
void Enfila(fila *F, item dato);
void Defila(fila * F);
item Frentefila(fila *F);
void MuestraFila(fila F);

int main()
{
    fila F;
    CreaFila(&F);
    MuestraFila(F);

    Enfila(&F,1);
    Enfila(&F,2);
    Enfila(&F,3);
    Enfila(&F,4);
    Enfila(&F,5);
    Enfila(&F,6);
    Enfila(&F,6);

    printf("\nMuestra 1:\n");
    MuestraFila(F);
    Defila(&F);

    printf("\nMuestra 2: Eliminado 1 dato\n");
    MuestraFila(F);
    Defila(&F);
    Defila(&F);
    Defila(&F);
    Defila(&F);
    Defila(&F);
    Defila(&F);

    printf("\nMuestra 3: Sin Datos\n");
    MuestraFila(F);
    return 0;
}

void CreaFila(fila *F)
{
    F->cabecera = F->final = NULL;
    F->tamanio = 0;
}

bool EsFilaVacia(fila *F)
{
    return F->tamanio == 0;
}

void Enfila(fila *F, item dato)
{
    struct nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if(EsFilaVacia(F))
    {
        F->cabecera = nuevoNodo;
        F->final = nuevoNodo;
        F->tamanio++;
    }else
    {
        F->final->siguiente = nuevoNodo;
        F->final = nuevoNodo;
        F->tamanio++;
    }
}

void Defila(fila *F)
{
    struct nodo* aux;
    aux = F->cabecera;

    if(!EsFilaVacia(F))
    {
        if (F->cabecera == F->final)
        {
            F->cabecera = NULL;
            F->final = NULL;
            free(aux);
        }else
        {
            F->cabecera = F->cabecera->siguiente;
            free(aux);
        }
    }
}

item Frentefila(fila *F)
{
    struct nodo *aux;
    aux = F->cabecera;
    return aux->dato;
}

void MuestraFila(fila F)
{
    if(!EsFilaVacia(&F))
    {
        nodo *aux = F.cabecera;

        while (aux != NULL)
        {
            printf("\n-> %d", aux->dato);
            aux = aux->siguiente;
        }
    }else
    {
    printf("\n\nLa fila esta vacia :v. \nIntente nuevamente luego de ingresar datos pedazo de imbesil.\n");
    }
}