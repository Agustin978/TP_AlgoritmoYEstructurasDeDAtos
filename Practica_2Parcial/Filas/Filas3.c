#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef int  item;
const int indefinido=-9999;

typedef struct nodo
{
    int dato;
    struct nodo* sig;
}nodo;

typedef struct Fila
{
     nodo* frente;
     nodo* final;
     int altura;

}Fila;

Fila filaVacia();
bool esFilaVacia(Fila F);
void enFila(Fila * F, item x);
void deFila(Fila * F); 
item frente(Fila F);
void mostrar(Fila F);
int cuentaImpares(Fila * F);
//Fila FilaConMayoresQueFrente(Fila F,item frenteDato, Fila G);
int sumaPositivos(Fila * F);

int main()
{
    Fila fila = filaVacia();

    if(esFilaVacia(fila))
    {
        printf("La fila esta vacia.");
    }

    enFila(&fila,1);
    enFila(&fila,2);
    enFila(&fila,3);
    enFila(&fila,4);
    enFila(&fila,5);
    enFila(&fila,6);
    enFila(&fila,6);

    printf("\nMuestra 1:\n");
    mostrar(fila);
    deFila(&fila);
    printf("\nMuestra 2:\n");
    mostrar(fila);

    deFila(&fila);
    deFila(&fila);
    deFila(&fila);
    deFila(&fila);
    deFila(&fila);
    deFila(&fila);
    mostrar(fila);

    return 0;
}

Fila filaVacia()
{
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    return F;

} // me crea una estructura que tiene dos punteros apuntand a null

bool esFilaVacia(Fila F)
{
    return ( (F.frente == NULL) && (F.final == NULL) );
}

void enFila(Fila * F, item x)
{
    nodo * nuevo; 
    nuevo = (nodo*) malloc(sizeof (nodo));
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (esFilaVacia(*F))
    {
        F->frente = nuevo;
        F->final = nuevo;
        F->altura = F->altura + 1;

    }else
    {
        F->final->sig = nuevo;
        F->final = nuevo;
        F->altura = F->altura + 1;
    }
}

void deFila(Fila * F)
{
  struct nodo* aux;
  aux = F->frente;

  if (F->frente != NULL && F->final!= NULL)
  {
    if (F->frente == F->final)
    {
        F->final = NULL;
        F->frente = NULL;
        free(aux);

    }else
    {
        F->frente = F->frente->sig;
        free(aux);
    } 
  }

}

item frente(Fila F)
{
    if (esFilaVacia(F))
    {
        return indefinido;
    }else
    {
        return F.frente->dato;    
    }
}

void mostrar(Fila F)
{
    nodo* aux = F.frente;

    if(!esFilaVacia(F))
    {
        while (aux != NULL )
        {
            printf("%2d ", aux->dato);
            aux = aux->sig;
        }
    }else
    {
        printf("\nLa fila esta vacia imbesil.\n");
    }
}

int cuentaImpares(Fila * F)
{
    if (esFilaVacia(*F))
    {
        return 0;

    }else
    {
        if (frente(*F) % 2 != 0)
        {
            deFila(F);
            return 1 + cuentaImpares(F);

        }else
        {
            deFila(F);
            return cuentaImpares(F);
        }
    }
}

int sumaPositivos(Fila * F)
{
    if (esFilaVacia(*F))
    {
        return 0;

    }else
    {
        if (frente(*F))
        {
            deFila(F);
            return frente(*F) + sumaPositivos(F);

        }else
        {
            deFila(F);
            return sumaPositivos(F);
        }
    }
}