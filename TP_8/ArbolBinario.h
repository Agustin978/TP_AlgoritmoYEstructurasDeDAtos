#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef char itemAB;

typedef struct nodoAB
{
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
}nodoAB;

typedef struct nodoAB *AB;

//Declaracion de funciones
AB ABVacio();
AB CreaNodoAB(itemAB dato);
AB ABArmar(AB I, itemAB dato, AB D);
bool EsABVacio(AB T);
bool Pertenece(AB T, itemAB dato);
void imprimirPre(AB T);
AB HijoIzquierdo(AB T);
AB HijoDerecho(AB T);
itemAB Raiz(AB T);
bool EsABHoja(AB T);

//Desarrollo de funciones
AB ABVacio()
{
    return NULL;
}

AB CreaNodoAB(itemAB dato)
{
    AB nuevo = (AB)malloc(sizeof(nodoAB));
    nuevo->raiz = dato;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

AB ABArmar(AB I, itemAB dato, AB D) 
{
    AB nuevo;
    nuevo = CreaNodoAB(dato);
    nuevo->izq = I;
    nuevo->der = D;
    return nuevo;
}

bool EsABVacio(AB T)
{
    return T == NULL;
}

AB HijoDerecho(AB a)
{
    if(!EsABVacio(a))
    {
        return a->der;
    }else
    {
        printf("Error en hijo derecho.\n");
        return NULL;
    }
}

AB HijoIzquierdo(AB a)
{
    if(!EsABVacio(a))
    {
        return a->izq;
    }else
    {
        printf("Error en hijo izquierdo.\n");
        return NULL;
    }
}

void imprimirPre(AB T)
{
    if(T)
    {
        printf("%c\n", Raiz(T));
        imprimirPre(T->der);
        imprimirPre(T->izq);
    }
}

itemAB Raiz(AB T)
{
    return T->raiz;
}

bool EsABHoja(AB T)
{
    if(T)
    {
        return(T->izq == NULL && T->der == NULL);
    }else
    {
        return (0);
    }
}