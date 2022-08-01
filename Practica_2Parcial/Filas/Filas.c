#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int item;
const int indefinido = -9999;

struct nodo
{
    item dato;
    struct nodo *siguiente;
};

typedef struct nodo * Nodo;

typedef struct
{
    Nodo frente;
    Nodo final;
    item altura;
}Fila;

//Declaracion de funciones
Fila FilaVacia(); //Crea la fila
bool EsFilaVacia(Fila F); //Determina si la fila esta vacia
Fila EnFila(Fila F, item dato); //Ingresa elementos a la fila
Fila DeFila(Fila F); //Elimina el primer elemento de la fila
item FrenteFila(Fila F); //Retorna el frente de la fila
void MuestraFila(Fila F); //Muestra la fila

void main()
{
    Fila f = FilaVacia(); //Creacion de la fila
    
    MuestraFila(f);

    f = EnFila(f,1);
    f = EnFila(f,2);
    f = EnFila(f,3);
    f = EnFila(f,11);
    f = EnFila(f,152);

    MuestraFila(f);

    f = DeFila(f);
    f = DeFila(f);

    MuestraFila(f);

    printf("\nAhora el frente de la fila es: %d", FrenteFila(f));
}

Fila FilaVacia()
{
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    F.altura = 0;
    return F;
}

bool EsFilaVacia(Fila F)
{
    if(F.altura == 0)
    {
        return true;
    }
    return false;
}

Fila EnFila(Fila F, item dato)
{
    Nodo nuevoNodo = (Nodo)malloc(sizeof(struct nodo)); //Reservo memoria para el nuevo nodo
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if(EsFilaVacia(F))
    {
        F.frente = nuevoNodo;
        F.final = nuevoNodo;
        F.altura += 1; //Incremento en uno la altura de la fila
    }else
    {
        F.final->siguiente = nuevoNodo; //El nodo final de antes apuntara al nuevo nodo
        F.final = nuevoNodo; //Ahora el nuevo nodo es el nodo del final
        F.altura += 1;
    }
    return F;
}

Fila DeFila(Fila F)
{
    Nodo nodoAux; //Creo un nodo auxiliar para eliminar el primero de la lista
    if(!EsFilaVacia(F))
    {
        nodoAux = F.frente;
        F.frente = F.frente->siguiente;
        F.altura -= 1;
        free(nodoAux);
        /* No esta bien
        nodoAux = F.frente->dato; //El nodo auxiliar toma el valor del nodo del frente
        F.frente = F.frente->siguiente; //El nuevo nodo del frente es el siguiente
        free(nodoAux); //Libero la memoria del nodo del fente que es el que quiero eliminar
        */
    }else
    {
        printf("\nLa fila esta vacia, no es posible eliminar ningun elemento :v\n");
    }
    return F;
}

item FrenteFila(Fila F)
{
    if(EsFilaVacia(F))
    {
        printf("\nLa fila esta vacia.");
        return indefinido;
    }else
    {
        return F.frente->dato;
    }
}

void MuestraFila(Fila F)
{
    printf("\nMuestro la fila:\n");
    Fila fAux = F; //Utilizo una fila auxiliar para recorrerla en ves de usar la original para evitar problemas con el apintado al nodo luego
    if(EsFilaVacia(fAux))
    {
        printf("La fila esta vacia\n");
    }else
    {
        while (fAux.frente != NULL)
        {
            printf("%d -> %d\n",fAux.altura, fAux.frente->dato);
            fAux.frente = fAux.frente->siguiente;
        }
    }
}