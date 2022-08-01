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
}fila;

//Declaracion de funciones
void CreaFila(fila *f);
bool EsFilaVacia(fila *f);
void EnFila(fila *f, item dato);
void DeFila(fila *f);
void MuestraFila(fila f);
void LiberaMemoria(fila *f);
item PrimerElemento(fila f);
item Final(fila f);
void EnFilan(fila *f, item dato, int cantidad);
int Pertenece(fila f, item dato);
fila Mezclar(fila f1, fila f2, fila f3);

int main()
{
    fila fila, f1, f2, f3;
    CreaFila(&fila);

    printf("\nMuestra 1:");
    MuestraFila(fila);

    EnFila(&fila, 1);
    EnFila(&fila, 2);
    EnFila(&fila, 3);
    EnFila(&fila, 4);
    EnFila(&fila, 5);
    EnFila(&fila, 6);
    EnFila(&fila, 7);
    EnFila(&fila, 5);

    printf("\n\nEl primer elemento de la fila es: %d", PrimerElemento(fila));
    printf("\nEl ultimo elemento de la fila es: %d\n", Final(fila));

    printf("\nMuestra 2:");
    MuestraFila(fila);

    DeFila(&fila);
    DeFila(&fila);
    DeFila(&fila);

    printf("\nMuestra 3:");
    MuestraFila(fila);

    EnFilan(&fila, 1, 3);
    MuestraFila(fila);

    printf("\n\nEl numero 1 se encontro en la fila un total de %d veces.\n", Pertenece(fila, 1));
    printf("\nEl numero 5 se encontro en la fila un total de %d veces.\n", Pertenece(fila, 5));
    printf("\nEl numero 17 se encontro en la fila un total de %d veces.\n", Pertenece(fila, 17));

    LiberaMemoria(&fila);
    
    printf("\nMuestra 4:");
    MuestraFila(fila);

    printf("\n\nEl primer elemento de la fila es: %d", PrimerElemento(fila));
    printf("\nEl ultimo elemento de la fila es: %d\n", Final(fila));

    printf("\n\n===========Funcion recursiva para mezclar dos filas===========\n");

    CreaFila(&f1);
    CreaFila(&f2);
    CreaFila(&f3);

    EnFilan(&f1, 1, 2);
    EnFila(&f1, 2);
    EnFila(&f1, 4);
    EnFila(&f1, 8);

    EnFilan(&f2, 3, 4);
    EnFila(&f2, 5);
    EnFila(&f2, 8);
    EnFila(&f2, 10);
    EnFila(&f2, 11);
    EnFila(&f2, 12);

    f3 = Mezclar(f1, f2, f3);

    MuestraFila(f3);

    //LiberaMemoria(&f1);
    //LiberaMemoria(&f2);
    LiberaMemoria(&f3);
    return 0;
}

void CreaFila(fila *f)
{
    f->cabecera = NULL;
    f->final = NULL;
    f->tamanio = 0;
}

bool EsFilaVacia(fila *f)
{
    return f->tamanio == 0;
}

void EnFila(fila *f, item dato)
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if(!EsFilaVacia(f))
    {
        f->final->siguiente = nuevoNodo;
        f->final = nuevoNodo;
        f->tamanio++;
    }else
    {
        f->cabecera = nuevoNodo;
        f->final = nuevoNodo;
        f->tamanio++;
    }
}

void DeFila(fila *f)
{
    if(!EsFilaVacia(f))
    {
        struct nodo *aux = f->cabecera;
        if(f->cabecera == f->final)
        {
            f->cabecera = NULL;
            f->final = NULL;
            f->tamanio -= 1;
            free(aux);
        }else
        {
            f->cabecera = f->cabecera->siguiente;
            f->tamanio -= 1;
            free(aux);
        }
    }
}

void MuestraFila(fila f)
{
    if(!EsFilaVacia(&f))
    {
        struct nodo *seguidor = f.cabecera;
        
        while (seguidor != NULL)
        {
            printf("\n-> %d", seguidor->dato);
            seguidor = seguidor->siguiente;
        }
    }else
    {
        printf("\nLa fila esta vacia.");
    }
}

void LiberaMemoria(fila *f)
{
    while (!EsFilaVacia(f))
    {
        DeFila(f);
    }
}

item PrimerElemento(fila f)
{
    if(!EsFilaVacia(&f))
    {
        return f.cabecera->dato;
    }else
    {
        return indefinido;
    }
}

item Final(fila f)
{
    if(!EsFilaVacia(&f))
    {
        struct nodo *seguidor = f.cabecera;
        
        for(int i = 0; i < f.tamanio-1; i++)
        {
            seguidor = seguidor->siguiente;
        }
        return seguidor->dato;
    }else
    {
        return indefinido;
    }
}

void EnFilan(fila *f, item dato, int cantidad)
{
    for(int i = 0; i < cantidad; i++)
    {
        EnFila(f, dato);
    }
}

int Pertenece(fila f, item dato)
{
    if(!EsFilaVacia(&f))
    {
        struct nodo *seguidor = f.cabecera;
        int contador = 0;
        while (seguidor !=  NULL)
        {
            if(seguidor->dato == dato)
            {
                contador++;
            }
            seguidor = seguidor->siguiente;
        }
        return contador;
    }else
    {
        return 0;
    }
    
}

fila Mezclar(fila f1, fila f2, fila f3)
{
    if(EsFilaVacia(&f1) && EsFilaVacia(&f2))
    {
        return f3;
    }else
    {
        if(EsFilaVacia(&f1) && !EsFilaVacia(&f2))
        {
            EnFila(&f3, PrimerElemento(f2));
            DeFila(&f2);
            return Mezclar(f1, f2, f3);
        }else
        {
            if(!EsFilaVacia(&f1) && EsFilaVacia(&f2))
            {
                EnFila(&f3, PrimerElemento(f1));
                DeFila(&f1);
                return Mezclar(f1, f2, f3);
            }else
            {
                if(PrimerElemento(f1) > PrimerElemento(f2))
                {
                    EnFila(&f3, PrimerElemento(f1));
                    DeFila(&f1);
                    return Mezclar(f1, f2, f3);
                }else if(PrimerElemento(f1) < PrimerElemento(f2))
                {
                    EnFila(&f3, PrimerElemento(f2));
                    DeFila(&f2);
                    return Mezclar(f1, f2, f3);
                }
            }
        }
    }
}