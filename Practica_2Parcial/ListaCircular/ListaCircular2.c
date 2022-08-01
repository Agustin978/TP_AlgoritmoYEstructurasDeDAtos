 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<stdbool.h>

 typedef int item;
 const int indefinido = -9999;

 typedef struct nodo
 {
    item dato;
    struct nodo *siguiente;
 }nodo;

 typedef struct listaC
 {
    nodo *ventana;
    int tamanio;
 }listaC;

 //Declaracion de funciones
 void ListaVacia(listaC *lc);
 bool EsLCVacia(listaC *lc);
 void LCInsertar(listaC *lc, item dato);
 item LCValor(listaC lc);
 void LCBorrar(listaC *lc);
 void rotar(listaC *lc);
 void Mostrar(listaC lc);
 int Pertenece(listaC lc, item dato);
 void LiberaMemoria(listaC *lc);

int main()
{
    listaC lc;
    ListaVacia(&lc);

    printf("\nMuestra 1:");
    Mostrar(lc);

    LCInsertar(&lc, 1);
    LCInsertar(&lc, 2);
    LCInsertar(&lc, 3);
    LCInsertar(&lc, 4);
    LCInsertar(&lc, 5);
    LCInsertar(&lc, 6);
    LCInsertar(&lc, 1);

    printf("\nMuestra 2:");
    Mostrar(lc);

    printf("\n\nEl elemento 1 se hallo en la lista un total de %d veces.", Pertenece(lc, 1));
    printf("\n\nEl elemento 4 se hallo en la lista un total de %d veces.", Pertenece(lc, 4));
    printf("\n\nEl elemento 11 se hallo en la lista un total de %d veces.", Pertenece(lc, 11));

    LCBorrar(&lc);
    LCBorrar(&lc);

    printf("\nMuestra 3:");
    Mostrar(lc);

    LiberaMemoria(&lc);

    printf("\nMuestra 4:");
    Mostrar(lc);

    return 0;
}

 void ListaVacia(listaC *lc)
 {
    lc->ventana = NULL;
    lc->tamanio = 0;
 }

 bool EsLCVacia(listaC *lc)
 {
    return lc->tamanio == 0;
 }

 void LCInsertar(listaC *lc, item dato)
 {
    struct nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    if(EsLCVacia(lc))
    {
        lc->ventana = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        lc->tamanio++;
    }else
    {
        nuevoNodo->siguiente = lc->ventana;
        lc->ventana = nuevoNodo;
        lc->tamanio++;
    }
 }

 item LCValor(listaC lc)
 {
    return lc.ventana->dato;
 }

 void LCBorrar(listaC *lc)
 {
    if(!EsLCVacia(lc))
    {
        struct nodo *aux = lc->ventana;
        if(lc->tamanio > 1)
        {
            lc->ventana = lc->ventana->siguiente;
        }else
        {
            lc->ventana = NULL;
        }
        lc->tamanio -= 1;
        free(aux);
    }
 }

 void rotar(listaC *lc)
 {
    if(!EsLCVacia(lc))
    {
        lc->ventana = lc->ventana->siguiente;
    }
 }

 void Mostrar(listaC lc)
 {
    listaC aux = lc;
    if(!EsLCVacia(&lc))
    {
        for(int i = 0; i < aux.tamanio; i++)
        {
            printf("%d ->", aux.ventana->dato);
            rotar(&aux);
        }
    }else
    {
        printf("\nLa lista esta vacia.\n");
    }
 }

 int Pertenece(listaC lc, item dato)
 {
    if(!EsLCVacia(&lc))
    {
        nodo *aux = lc.ventana;
        int contador = 0;
        for(int i = 0; i < lc.tamanio; i++)
        {
            if(aux->dato == dato)
            {
                contador++;
            }
            aux = aux->siguiente;
        }
        return contador;
    }else
    {
        return 0;
    }
 }
 
 void LiberaMemoria(listaC *lc)
 {
    while(!EsLCVacia(lc))
    {
        LCBorrar(lc);
    }
 }