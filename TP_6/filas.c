#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

typedef int item;
const int indefinido = -9999;

struct nodo
{
    item dato;
    struct nodo* siguiente;
};


typedef struct 
{
    struct nodo* frente;
    struct nodo* final;

}fila;

fila filaVAcia();
bool esFilaVacia(fila F);
fila enFila(fila F, item x);
void mostrar(fila F);
fila deFilo(fila F);
item frente(fila F);
fila ordenarFilas(fila F1, fila F2, fila F3);

int main()
{
    fila F1,F2,F3;

    F1 = filaVAcia();
    F2 = filaVAcia();
    F3 = filaVAcia();

    /*if (esFilaVacia(F))
    {
        printf("es vacia");
    }else
    {
        printf("no es vacia");
    }*/

    F1 = enFila(F1,1);
    F1 = enFila(F1,5);
    F1 = enFila(F1,7);

    F2 = enFila(F2,3);
    F2 = enFila(F2,4);
    F2 = enFila(F2,9);

    mostrar(F1);
    printf("----------------\n");
    mostrar(F2);
    printf("----------------\n");

    F3 = ordenarFilas(F1,F2,F3);
    printf("-------ORDENADAS---------\n");
    mostrar(F3);
    return 0;
}

fila filaVAcia() // O(1)
{
    fila F;
    F.final = NULL;
    F.frente = NULL;

    return F;
}

bool esFilaVacia(fila F) //O(1)
{
    if (F.frente == NULL && F.final == NULL)
    {
        return true;

    }else
    {
        return false;
    }
    
}

fila enFila(fila F, item x) // O(1)
{
    struct nodo *nuevo = (struct nodo*) malloc(sizeof(struct nodo));

    nuevo->dato = x;
    nuevo->siguiente = NULL;

    if (esFilaVacia(F))
    {
        F.final = nuevo;
        F.frente = nuevo;   
        return F; 

    }else
    {
        F.final->siguiente = nuevo; // enlazo penultimo con ultimo (nuevo)
        F.final = nuevo; // el final apuntando al ultimo q agrego
        return F ;
    }
    
    
}

item frente(fila F) //O(1)
{
    if (esFilaVacia(F))
    {
        return indefinido;
    }else
    {
        return F.frente->dato;    
    }
    
}

fila deFilo(fila F) //O(1)
{
    struct nodo* aux ;
    aux = F.frente ;
    
    if (F.frente == F.final)
    {
        F.final=NULL;
        F.frente=NULL;
        free(aux);
        return F;
    }else
    {
        F.frente = F.frente->siguiente;
        free(aux);
        return F;   
    }
}

void mostrar(fila F)
{
    while (F.frente != NULL)
    {
        printf("%d \n", F.frente->dato);
        F.frente = F.frente->siguiente;
    }
    
}

fila ordenarFilas(fila F1, fila F2, fila F3)
{
    if (esFilaVacia(F1) && esFilaVacia(F2))
    {
        return F3;
    }else
    {
        if (esFilaVacia(F1) && !esFilaVacia(F2))
        {
            return ordenarFilas(F1,deFilo(F2),enFila(F3,frente(F2)));
        }else
        {
            if (esFilaVacia(F2) && !esFilaVacia(F1))
            {
                return ordenarFilas(F2,deFilo(F1),enFila(F3,frente(F1)));

            }else
            {
                if (frente(F1) > frente(F2))
                {
                    return ordenarFilas (F1,deFilo(F2),enFila(F3,frente(F2)));
                }else
                {
                    return ordenarFilas(F2,deFilo(F1),enFila(F3,frente(F1)));
                }
            }
        
        }
        
    }
    
}

