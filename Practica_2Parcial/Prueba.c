#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int archivo;
const int indefinido = -9999;

struct nodo
{
    archivo dato;
    struct nodo *nodSiguiente;
};

typedef struct nodo *Nodo;

typedef struct
{
    Nodo ventana;
    archivo tamanio;
}SPOOLER;

typedef struct LC * ListaCircular;

//Declaracion de funciones
Nodo nuevoNod();
void LCVacio(SPOOLER *lc);  //SpoolerVacio
bool EsLCVacio(SPOOLER *lc);  //Esvacio
void LCAgregar(SPOOLER *lc, archivo dato); //Agregar
int tamanioLC(SPOOLER *lc); //Cantidad
void RotarLC(SPOOLER *lc);
void muestraLC(SPOOLER *lc);
archivo proximo(SPOOLER *lc);
void borrar(SPOOLER *lc); //eliminar
bool incluido(SPOOLER *lc, archivo dato);
void vaciarSpooler(SPOOLER *lc);


int main(){

    printf("\nINICIO DEL PROGRAMA DE PRUEBA\n");

	SPOOLER *lc;
    LCVacio(&lc);
    
    if(EsLCVacio(&lc))
    {
        printf("La lista circular esta vacia");
    }else
    {
        printf("Hiciste cualquiera ._.");
    }


    LCAgregar(&lc, 1);
    LCAgregar(&lc, 2);
    LCAgregar(&lc, 3);
    LCAgregar(&lc, 4);
    LCAgregar(&lc, 5);
    LCAgregar(&lc, 6);


	printf("\nTamanio de la lista circular: %d\n", tamanioLC(&lc));

    muestraLC(&lc);

    printf("\nProximo dato de la lista: %d\n", proximo(&lc));

    printf("\nBorro el elemento de la ventana de la lista");
    borrar(&lc);
    muestraLC(&lc);
   
    if(incluido(&lc, 5))
    {
        printf("\nEl dato buscado si se encuentra en la lista.");
    }else
    {
        printf("\nEl dato buscado NO se encuentra en la lista.");
    }
    
    vaciarSpooler(&lc);

    muestraLC(&lc);

    printf("\nFIN DEL PROGRAMA DE PRUEBA\n");

    
    return 0;
}

Nodo nuevoNod()
{
    return NULL;
}

void LCVacio(SPOOLER *lc)
{
    lc->ventana = nuevoNod();
    lc->tamanio = 0;
}

bool EsLCVacio(SPOOLER *lc)
{
    return lc->ventana == NULL;
}

void LCAgregar(SPOOLER *lc, archivo dato)
{
    Nodo nuevo = (Nodo)malloc(sizeof(struct nodo)); //Almacenado de memoria
    nuevo->dato = dato;
    //printf("\n %d \n", nuevo->dato);

    if(EsLCVacio(&lc))
    {
        nuevo->nodSiguiente = nuevo;
        lc->ventana = nuevo;
        lc->tamanio++;
        printf("\nIngresa dato %d", lc->ventana->dato);
    }else
    {
        nuevo->nodSiguiente = lc->ventana;
        lc->ventana = nuevo;
        lc->tamanio++;
        printf("\nIngresa dato %d", lc->ventana->dato);
    }
}

int tamanioLC(SPOOLER *lc) //Tamanio o cantidad
{
    return lc->tamanio;
}

void RotarLC(SPOOLER *lc)
{
    if(!EsLCVacio(&lc))
    {
        lc->ventana = lc->ventana->nodSiguiente;
        //return lc;
    }
    //return lc;
}

void muestraLC(SPOOLER *lc)
{
    if(!EsLCVacio(&lc))
    {
        SPOOLER lcAux = *lc;
        int i = 0;
        //printf("\n%d\n",tamanioLC(&lcAux));
        while(i < tamanioLC(&lcAux))
        {
            i++;
            printf("-> %d  ", lcAux.ventana->dato);
            RotarLC(&lcAux);
        }
    }else
    {
        printf("\nLa lista esta vacia.");
    }
}

archivo proximo(SPOOLER *lc)
{
    if(!EsLCVacio(&lc))
    {
        SPOOLER lcAux = *lc;
        RotarLC(&lcAux);
        return lcAux.ventana->dato;
    }else
    {
        printf("No hay elementos en la lista.");
        return indefinido;
    }
}

void borrar(SPOOLER *lc)
{
    //printf("\n%d", tamanioLC(&lc));
    if(!EsLCVacio(&lc))
    {
        Nodo aux = lc->ventana;
        if(tamanioLC(&lc)==1)
        {
            lc->ventana = NULL;
        }else
        {
            lc->ventana = lc->ventana->nodSiguiente;
        }
        lc->tamanio--;
        free(aux);
    }
}

bool incluido(SPOOLER *lc, archivo dato)
{
    SPOOLER lcAux = *lc;
    if(!EsLCVacio(&lcAux))
    {
        //printf("._.");
        printf("\n%d / %d\n", lcAux.ventana->dato, dato);
        if(lcAux.ventana->dato == dato)
        {
            //printf("\nSe encontro el numero");
            //muestraLC(&lcAux);
            return true;
        }else
        {
            borrar(&lcAux);
            incluido(&lcAux, dato);
        }
    }
    return false;
}

void vaciarSpooler(SPOOLER *lc)
{
    while (!EsLCVacio(&lc))
    {
        Nodo nodoElimina = lc->ventana;
        free(nodoElimina);
        lc->tamanio--;
    }
}