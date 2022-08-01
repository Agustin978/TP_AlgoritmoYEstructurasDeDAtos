#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


typedef int item;

typedef struct nodo
{
    item dato;
    struct nodo * hi;
    struct nodo * hd;

}nodo;

nodo * ABvacio();
bool ABesVacio(nodo * T);
nodo * ABarmar(nodo * A, item x, nodo * B); 
item raiz(nodo * T);
nodo * izquierdo(nodo * A);
nodo * derecho(nodo * B);
bool Eshoja(nodo *a);
int Altura(nodo *a);
int NdeHojas(nodo *a);
int NdeNodos(nodo *a);
int NdeNodosInternos(nodo *a);
void NodosNivel(nodo *a, int n);
void Inorden(nodo *a);
void Preorden(nodo *a);
void Postorden(nodo *a);
int Suma (nodo *a);
//int SumaMultimpos (nodo *a);
//int Identicos (nodo *a, nodo *a1);

/////////////////////////////////

nodo * ABvacio()
{
    return NULL;
}

bool ABesVacio(nodo * T)
{
    if (T == NULL)
    {
        return true;
    }else
    {
        return false;
    }
}


nodo * ABarmar(nodo * A, item x, nodo * B)
{
    nodo * nn;

    nn = (nodo*) malloc(sizeof(nodo));
    nn->dato = x;
    nn->hi = A;
    nn->hd = B;
    return (nn);
}

item raiz(nodo * T)
{
    if (!ABesVacio(T))
    {
        return T->dato;

    }else
    {
        printf("no hay raiz, el arbol es vacio");
    }
}

nodo * izquierdo(nodo * A)
{
    if (!ABesVacio(A))
    {
        return A->hi;
    }else
    {
        printf("error en Hi \n ");
        return(NULL);
    }
    
}

nodo * derecho(nodo * B)
{
    if (!ABesVacio(B))
    {
        return B->hd;
    }else
    {
        printf("error en Hd \n");
        return(NULL);
    }   
}

bool Eshoja(nodo * a)
{
    if (!ABesVacio(a))
        return( (a->hi == NULL) && a->hd == NULL);
    else
        return (false);
}


int Altura(nodo *a)
{
    if (ABesVacio(a))
        return(0);
    else
    {
    int ai,ad;
    ai = Altura(a->hi);
    ad = Altura(a->hd);
    if (ai < ad)
        return (1 + ad);
    else
    return (1 + ai);
    }
}


int NdeHojas(nodo *a)
{
    if (ABesVacio(a)) 
        return(0);
    else
    return (NdeHojas(a->hi) + NdeHojas(a->hd));
}


int NdeNodos(nodo *a)
{
    if(ABesVacio(a))
        return(0);
    else
        return(1+ NdeNodos(a->hi) + NdeNodos(a->hd));
}

int NdeNodosInternos(nodo *a)
{
    return (NdeNodos(a)-NdeHojas(a));
}

void NodosNivel(nodo *a, int n)
{
    if (a)
    if (n == 1)
        printf("%d\n", a->dato);
    else
    {
        NodosNivel(a->hi,n - 1);
        NodosNivel(a->hd,n - 1);
    }
}

void Inorden(nodo *a)
{
    if (!ABesVacio(a))
    {
        Inorden(a->hi);
        printf("%d", a->dato);
        Inorden(a->hd);
    }
}

void Preorden(nodo *a)
{
    if (!ABesVacio(a))
    {
        printf("%d" , a->dato);
        Preorden(a->hi);
        Preorden(a->hd);
    }
}


void Postorden(nodo *a)
{
    if (!ABesVacio(a))
    {
        Postorden(a->hi);
        Postorden(a->hd);
        printf("%d", a->dato);
    }
}

int Suma (nodo * a)
{
    if(!ABesVacio(a))
        return( a->dato + Suma(a->hi) + Suma(a->hd));
    else
        return(0);
}
/*
int SumaMultimpos (nodo * a)
{
    if(!ABesVacio(a))
        if (a->dato % 3) // CONDICION QUE ME PIDAN PARA LOS QSE DEBEN SUMAR
            return( a->dato + SumaMultiplos(a->hi)+SumaMultiplos(a->hd));
        else
            return( SumaMultimplos(a->hi) + SumaMultiplos(a->hd));
    else
        return(0);
}

int Identicos (nodo *a, nodo * a1)
{
    if (!ABesVacio(a))
        if (!ABesVacio(a1))
            return((a->dato == a1->dato) && Identicos(a->hi,a1->hi && Identicos(a->hd, a1->hd)));
        else // a ≠ NULL y a1 es NULL
            return(0);
    else
    if (a1) // a es NULL y a1 no
        return(0);
    else
        return(1);
}

*/