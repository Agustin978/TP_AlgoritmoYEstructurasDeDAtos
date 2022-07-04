#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item indefinido = -9999;

struct nodo{
    item elemento;
    struct nodo* siguente;
};

typedef struct{
    struct nodo* Frente;
    struct nodo* Final;
    item altura;
}Fila;

Fila FilaVacia();
bool EsFilaVacia(Fila F);
Fila Enfila(Fila F, item x);
Fila Desfila(Fila F);
int Frente(Fila F);

void mostrarFila(Fila F);



Fila FilaVacia(){
    Fila F;
    F.Final = NULL;
    F.Frente = NULL;
    F.altura = 0;
    return F;
}

bool EsFilaVacia(Fila F){
    if(F.Final == NULL && F.Frente == NULL){
        return true;
    }else{
        return false;
    }
}

Fila Enfila(Fila F, item x){
    struct nodo* nuevoNodo;
    nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoNodo->elemento = x;
    nuevoNodo->siguente = NULL;
    if(EsFilaVacia(F)){
        F.Frente = nuevoNodo;
        F.Final = nuevoNodo;
        F.altura = F.altura +1; 
    }else{
        F.Final->siguente = nuevoNodo;//El ultimo nodo apunta al nuevo nodo
        F.Final = nuevoNodo;//el final apunta al nuevo ultimo nodo
        F.altura = F.altura +1;
    }

    return F;
}


void mostrarFila(Fila F){
    Fila Faux;
    Faux = F;
    while(Faux.Frente != NULL){
        printf("->");
        printf("%d", Faux.Frente->elemento);
        Faux.Frente = Faux.Frente->siguente;
    }
    if(Faux.Frente == Faux.Final){
        printf("Es Fila vacia");
    }
}


int Frente(Fila F){
    if(F.altura == 0){
        return indefinido;
    }else{
        return F.Frente->elemento;
    }
}


Fila Desfila(Fila F){
    struct nodo* auxiliar;
    if(EsFilaVacia(F)){
        return F;
    }

    if(F.altura > 1){
        auxiliar = F.Frente;
        F.altura = F.altura - 1;
        F.Frente = F.Frente->siguente;
        free(auxiliar);        
    }else{
        auxiliar = F.Frente;
        F.Frente = NULL;
        F.Final = NULL;
        F.altura = 0;
        free(auxiliar); 
    }

    return F;
}
