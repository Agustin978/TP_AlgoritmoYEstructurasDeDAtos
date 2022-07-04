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
void imprimirPos(AB T);
void imprimirSimertrico(AB T);
AB HijoIzquierdo(AB T);
AB HijoDerecho(AB T);
itemAB Raiz(AB T);
bool EsABHoja(AB T);

int main()
{
    //AB Arbol = ABVacio();
    AB I,D, Arbol = ABVacio(), raiz1;
    itemAB *dato = "A", *dato1 = "B", *dato2 = "C", *dato3 = "D", *dato4 = "E";

    if(EsABVacio(Arbol))
    {
        printf("\nEl arbol esta vacio");
    }else
    {
        printf("\nEl Arbol No esta vacio");
    }
    

    I = CreaNodoAB(*dato3);
    D = CreaNodoAB(*dato4);
    raiz1 = ABArmar(I, *dato1, D);
    Arbol = ABArmar(raiz1, *dato, CreaNodoAB(*dato2));

    if(EsABVacio(Arbol))
    {
        printf("\nEl arbol esta vacio");
    }else
    {
        printf("\nEl Arbol No esta vacio");
    }

    printf("\n====Muestro el arbol en Preorden====\n");
    imprimirPre(Arbol);

    printf("\n===Muestro Hijo Derecho===\n");
    printf("%c", Raiz(HijoDerecho(Arbol)));
    printf("\n===Muestro Hijo Izquierdo===\n");
    printf("%c", Raiz(HijoIzquierdo(Arbol)));

    if(EsABHoja(Arbol))
    {
        printf("\nEs un arbol hoja");
    }else
    {
        printf("\nNo es un arbol hoja");
    }

    if(EsABHoja(I))
    {
        printf("\nLa rama izquierda es una hoja");
    }else
    {
        printf("\nLa rama izquierda No es una hoja");
    }

    printf("\n====Muestro el arbol en Posorden====\n");
    imprimirPos(Arbol);

    printf("\n\n====Muestro el arbol en orden Simetrico====\n");
    imprimirSimertrico(Arbol);
    
    return 0;
}

AB  ABVacio()
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
        imprimirPre(T->izq);
        imprimirPre(T->der);
    }
}

void imprimirPos(AB T)
{
    if(T)
    {
        imprimirPos(T->izq);
        imprimirPos(T->der);
        printf("%c\n", Raiz(T));
    }
}

void imprimirSimertrico(AB T)
{
    if(T)
    {
        imprimirSimertrico(T->izq);
        printf("%c\n", Raiz(T));
        imprimirSimertrico(T->der);
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