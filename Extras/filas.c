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
int sumaPositivos(fila F1);

int main()
{
    fila F1;
    
    F1 = enFila(F1,1);
    F1 = enFila(F1,-5);
    F1 = enFila(F1,7);
    F1 = enFila(F1,-1);

    printf("La cantidad de numeros positivos en la fila es :%d",sumaPositivos(F1));

    fila f1, f2, f3;

    f1 = filaVAcia();
    f2 = filaVAcia();
    f3 = filaVAcia();

    f1 = enFila(f1, 1);
    f1 = enFila(f1, 5);
    f1 = enFila(f1, 7);

    f2 = enFila(f2, 3);
    f2 = enFila(f2, 4);
    f2 = enFila(f2, 9);
    f2 = enFila(f2, 120);

    f3 = ordenarFilas(f1, f2, f3);

    mostrar(f3);

    return 0;
}

int sumaPositivos(fila F1)
{
    if (esFilaVacia(F1))
    {
        return 0;
    }else
    {
        if (F1.frente->dato >=0)
        {
            return 1 + sumaPositivos(deFilo(F1));
        }else
        {
            return sumaPositivos(deFilo(F1));
        }
    }
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

