#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int item;
const item indefinido = -9999;

struct Nodo
{
    item elemento;
    struct Nodo *nodSiguiente;
};

typedef struct
{
    struct Nodo *frente;
    struct Nodo *final;
    int altura;
}Fila;

//Declaracion de funciones
Fila filaVacia(); //Regresa una fila vacia
Fila enFila(Fila f, item dato); //Ingresa un dato al final de la fila
Fila deFila(Fila f);  //Elimina el elemento del principio de la fila
bool esFilaVacia(Fila f); //Comprueba si la fila esta vacia
int pertenece(Fila f, item dato); //Determina si un elemento pertenece a la fila
item frenteFila(Fila f); //Retorna el frente de la fila
int altura(Fila f);  //Retorna la altura de la fila
void muestra(Fila f); 

void main()
{
    Fila F = filaVacia();
    int pert;

    if(esFilaVacia(F))
    {
        printf("\nLa fila esta vacia.");
    }
    
    muestra(F);
    F = enFila(F, 1);
    F = enFila(F, 2);
    F = enFila(F, 3);
    F = enFila(F, 4);
    F = enFila(F, 3);
    F = enFila(F, 12);
    F = enFila(F, 3);
    muestra(F);

    F = deFila(F);
    printf("\nVuelve a mostrar la fila con el defila realizado");
    muestra(F);

    pert = pertenece(F, 3);
    if(pert > 0)
    {
        printf("\nEl elemento buscado se encontro un total de %d veces", pert);
    }

    printf("\nEl frente actual de la fila es: %d", frenteFila(F));
}

Fila filaVacia()
{
    Fila fnueva;
    fnueva.frente = NULL;
    fnueva.final = NULL;
    fnueva.altura = 0;
    return fnueva;
}

bool esFilaVacia(Fila f)
{
    if(f.altura == 0)
    {
        return true;
    }
    return false;
}

int pertenece(Fila f, item dato)
{
    int contador = 0;
    if(!esFilaVacia(f))
    {
        Fila fAux = f;
        for (int i = 0; i < fAux.altura; i++)
        {
            if(fAux.frente->elemento == dato)
            {
                contador += 1;
            }
            fAux.frente = fAux.frente->nodSiguiente;
        }
    }
    return contador;
}

Fila enFila(Fila f, item dato)
{
    struct Nodo *nuevoNodo;
    nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->elemento = dato;
    nuevoNodo->nodSiguiente = NULL; //Como lo ingreso al final de la fila el siguiente apunta a null
    if(!esFilaVacia(f))
    {
        f.final->nodSiguiente = nuevoNodo; //El final anterior debe apuntar al nuevo nodo que ingreso
        f.final = nuevoNodo;  //Ahora el nodo final es el que ingreso
        f.altura += 1;
    }else
    {
        //Como es el primer nodo ingresado en la fila, tanto frente como final apuntan a este
        f.frente = nuevoNodo;
        f.final = nuevoNodo;
        f.altura += 1;
    }

    return f;
}

Fila deFila(Fila f)
{
    struct Nodo *nodAux;
    
    if (esFilaVacia(f))
    {
        return f;
    }else
    {
        nodAux = f.frente;
        if(f.altura > 1)
        {
            f.altura -= 1;
            f.frente = f.frente->nodSiguiente;
            free(nodAux);
        }else
        {
            f.altura -= 1;
            f.frente = NULL;
            f.final = NULL;
            free(nodAux);
        }
    }
    return f;
}

item frenteFila(Fila f)
{
    if(esFilaVacia(f))
    {
        return indefinido;
    }else
    {
        return f.frente->elemento;
    }
}

int altura(Fila f)
{
    return f.altura;
}

void muestra(Fila f)
{
    if(!esFilaVacia(f))
    {
        Fila filaAuxiliar = f;
        int contador = 0;
        while (filaAuxiliar.frente != NULL)
        {
            contador += 1;
            printf("\n%d -> %d", contador, filaAuxiliar.frente->elemento);
            filaAuxiliar.frente = filaAuxiliar.frente->nodSiguiente;
        }
    }else
    {
        printf("\nLa fila esta vacia. Ingrese algun elemento y vuelva a intentarlo");
    }
}