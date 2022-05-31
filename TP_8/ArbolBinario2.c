#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoElemento;

struct nodo
{
    TipoElemento el;
    struct nodo *hi, *hd;
};

typedef struct nodo Nodo;

//DEclara funciones
Nodo* CrearNodo(TipoElemento el);
Nodo* Construir(TipoElemento el, Nodo * hi, Nodo * hd);
Nodo* Hi( Nodo * a);
Nodo* Hd( Nodo * a);
int EsVacioA(Nodo *a);
int Eshoja(Nodo *a);
void Preorden(Nodo *a);

int main()
{
    Nodo *I, *D, *Arbol;

    //I = Construir(2, NULL, NULL);
    //D = Construir(3, NULL, NULL);
    I = CrearNodo(2);
    D = CrearNodo(3);
    Arbol = Construir(5, I, D);

    printf("\nMuestra el arbol:\n");
    Preorden(Arbol);

    return 0;
}

Nodo* CrearNodo(TipoElemento el)
{
    Nodo* t;
    t = (Nodo*) malloc(sizeof(Nodo));
    t -> el = el;
    t ->hi = t -> hd = NULL;
    return t;
}

Nodo* Construir(TipoElemento el, Nodo * hi, Nodo * hd)
{
    Nodo *nn;
    nn = CrearNodo(el);
    nn->hi = hi;
    nn->hd = hd;
    return( nn );
}

Nodo* Hi( Nodo * a)
{
    if(a)
    {
        return(a->hi);
    }else
    {
        printf("error en Hi \n");
        return(NULL);
    }
}
Nodo* Hd( Nodo * a)
{
    if(a)
    {
        return(a->hd);
    }else
    {
        printf("error en Hd \n");
        return(NULL);
    }
}

int EsVacioA(Nodo *a)
{
    return(a == NULL);
}

int Eshoja(Nodo *a)
{
    if(a)
    {
        return((a->hi == NULL)&& a->hd == NULL);
    }else
    {
        return (0);
    }
}

void Preorden(Nodo *a)
{
    if(a)
    {
        printf("%d\n", a->el);
        Preorden(a->hi);
        Preorden(a->hd);
    }
}