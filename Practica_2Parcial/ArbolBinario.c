#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char item;
const int indefinido = -9999;

struct nodoAB
{
    item raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};

typedef struct nodoAB *AB;

//Declaracion de funciones
AB ABVacio(); //Retorna un arbol vacio
AB CreaNodoAB(item raiz); //Crea una "hoja" para ingresar al arbol
AB ArmarAB(AB izq, item raiz, AB der);
bool EsABVacio(AB arbol); //Determina si el arbol esta vacio
bool EsABHoja(AB arbol);  //Determina si el arbol que le paso es hoja o no
item Izquierdo(AB arbol); //Retorna el valor del hijo izquierdo
item Derecho(AB arbol);  //Retorna el valor del hijo izquierdo
item Raiz(AB arbol); //Retorna la raiz del arbol
int Pertenece(AB arbol, item dato); //Determina si un elemento pertenece al arbol o no
int preordenYBusca(AB arbol, item busca, int n); //Recorre la lista y busca la cantidad de veces que se encontro un determinado elemento
void recorrePreorden(AB arbol);

void main()
{
    AB arbol = ABVacio(), I, D;

    if(EsABVacio(arbol))
    {
        printf("\nEl arbol esta vacio.\n");
    }

    recorrePreorden(arbol);

    I = CreaNodoAB(*"B");
    D = CreaNodoAB(*"C");
    arbol = ArmarAB(I,*"A",D);
    
    recorrePreorden(arbol);
    
    if(EsABHoja(I))
    {
        printf("\nEl arbol izquierdo es hoja.");
    }

    printf("\nEn la rama izquierda el valor es: %c", Izquierdo(arbol));
    printf("\nEn la rama derecha el valor es: %c", Derecho(arbol));

    if(Pertenece(arbol, *"C"))
    {
        printf("\nSe encontro el elemento C");
    }
}

AB ABVacio()
{
    return NULL;
}

AB CreaNodoAB(item raiz)
{
    AB nuevo = (AB)malloc(sizeof(struct nodoAB)); //Reserva de memoria para el nuevo elemento del arbol
    nuevo->der = NULL;
    nuevo->izq = NULL;
    nuevo->raiz = raiz;
    return nuevo;
}

AB ArmarAB(AB I, item dato, AB D)
{
    AB nuevo;
    nuevo = CreaNodoAB(dato);//Creo el nuevo nodo con la raiz y sus hijos vacios
    nuevo->der = D; //La rama derecha que estaba nula en la creacion del nodo toma al valor D que le paso a la funcion
    nuevo->izq = I; //Idem al anterior
    return nuevo;
}

bool EsABVacio(AB arbol)
{
    return arbol == NULL; //Si el primer nodo es nulo, significa que el arbol esta vacio
}

bool EsABHoja(AB arbol)
{
    if(arbol->izq == NULL && arbol->der == NULL)
    {
        return true;
    }
    return false;
}

item Izquierdo(AB arbol)
{
    if(!EsABVacio(arbol) && !EsABHoja(arbol))
    {
        if(!EsABVacio(arbol->izq))
        {
            return arbol->izq->raiz;
        }else
        {
            return indefinido; //En caso que el arbol de la izquierda no exista
        }
    }
    return indefinido; //En caso que sea arbol hoja o que sea arbol vacio
}

item Derecho(AB arbol)
{
    if(!EsABVacio(arbol) && !EsABHoja(arbol))
    {
        if(!EsABVacio(arbol->der))
        {
            return arbol->der->raiz;
        }else
        {
            return indefinido; //En caso que el arbol de la izquierda no exista
        }
    }
    return indefinido; //En caso que sea arbol hoja o que sea arbol vacio
}

item Raiz(AB arbol)
{
    if(!EsABVacio(arbol))
    {
        return arbol->raiz;
    }
    return indefinido;  //En caso que el arbol sea vacio
}


int Pertenece(AB arbol, item dato)
{
    AB arbolAux = arbol;
    if(!EsABVacio(arbolAux))
    {
        return (Raiz(arbolAux) == dato || Pertenece(arbolAux->izq, dato) || Pertenece(arbolAux->der, dato));
    }
    return 0;
}


void recorrePreorden(AB arbol)
{
    if(arbol)
    {
        printf("%c\n", Raiz(arbol));
        recorrePreorden(arbol->izq);
        recorrePreorden(arbol->der);
    }
}