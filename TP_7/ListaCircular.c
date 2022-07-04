#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int item;
const item indefinido = -9999;

struct nodo{
    item dato;
    struct nodo* siguiente;
};

typedef struct{
    struct nodo* cabecera;
    item longitud;
}ListaCircular;

ListaCircular LCVACIA();
bool ESLCVACIA(ListaCircular lc);
ListaCircular LCINSERTAR(ListaCircular lc, item x);
ListaCircular LCROTAR(ListaCircular lc);
item LCVALOR(ListaCircular lc);
ListaCircular LCBorrar(ListaCircular lc);
void mostrarLC(ListaCircular lc, item cantidad);
bool LCPertenece(ListaCircular lc, item x);
item LCLongitud(ListaCircular lc);
ListaCircular LCBorrarK(ListaCircular lc, item x);
item LCContarK(ListaCircular lc, item x, item n);

int main(){
    ListaCircular lc;
    lc=LCVACIA();

    if(ESLCVACIA(lc)){
        printf("Se creo la lista vacia\n");
    }else{
        printf("NO se creo la lista");
    }

    lc = LCINSERTAR(lc,1);
    lc = LCINSERTAR(lc,2);
    lc = LCINSERTAR(lc,3);
    lc = LCINSERTAR(lc,2);


    //PRUEBA FUNCION PERTENECE
    
    //if(LCPertenece(lc,2)){
    //    printf("Si TA\n");
    //};
    //mostrarLC(lc, lc.longitud);

    //PRUEBA LCCONTARK
    //printf("\n%d", LCContarK(lc,2,LCLongitud(lc)));

    //PRUEBA DE LCVALOR
    //printf("\nEL VALOR EN VENTANA ES: %d\n", LCVALOR(lc));

    //PRUEBA LCBORRAR
    //lc = LCBorrar(lc);
    //mostrarLC(lc, lc.longitud);
    //printf("\nEL VALOR EN VENTANA ES: %d\n", LCVALOR(lc));
    
    //PRUEBA LCROTAR
    //lc = LCROTAR(lc);
    //mostrarLC(lc, lc.longitud);
    //printf("\nEL VALOR EN VENTANA ES: %d", LCVALOR(lc));

    return 0;

}

ListaCircular LCVACIA(){
    ListaCircular lc;
    lc.cabecera = NULL;
    lc.longitud = 0;
    return lc;
}

bool ESLCVACIA(ListaCircular lc){
    if(lc.cabecera==NULL){
        return true;
    }else{
        return false;
    }
}


ListaCircular LCINSERTAR(ListaCircular lc, item x){
    struct nodo* nuevoNodo;
    nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoNodo->dato = x;
    if(ESLCVACIA(lc)){
        lc.cabecera = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        lc.longitud++;
    }else{
        nuevoNodo->siguiente = lc.cabecera->siguiente;
        lc.cabecera->siguiente = nuevoNodo;
        lc.longitud++;
    }
    return lc;
}

ListaCircular LCROTAR(ListaCircular lc){
    lc.cabecera = lc.cabecera->siguiente;
    return lc;
}

item LCVALOR(ListaCircular lc){
    return lc.cabecera->siguiente->dato;
}

ListaCircular LCBorrar(ListaCircular lc){
    struct nodo* nodoAuxiliar;

    nodoAuxiliar = lc.cabecera->siguiente;
    lc.cabecera->siguiente = lc.cabecera->siguiente->siguiente;
    lc.longitud--;
    free(nodoAuxiliar);
    return lc;
}

bool LCPertenece(ListaCircular lc, item x){
    if(ESLCVACIA(lc)){
        return false;
    }else{
        if(LCVALOR(lc)==x){
            return true;
        }else{
            return LCPertenece(LCROTAR(lc), x);
        }
    }
}

item LCLongitud(ListaCircular lc){
    return lc.longitud;
}

ListaCircular LCBorrarK(ListaCircular lc, item x){
    //ListaCircular lcAux;
    //lcAux = lc;
    if(!ESLCVACIA(lc) && LCLongitud(lc)!=0){
        if(LCVALOR(lc)==x){
            lc = LCBorrar(lc);
            LCBorrarK(lc,x);
        }else{
            LCBorrarK(LCROTAR(lc),x);
        }    
    }

}

item LCContarK(ListaCircular lc, item x, item n){
    if(ESLCVACIA(lc) || n==0){
        return 0;
    }else{
        if(LCVALOR(lc)==x){
            return 1 + LCContarK(LCROTAR(lc),x,n-1);
        }else{
            return LCContarK(LCROTAR(lc),x,n-1);
        }
    }
}

void mostrarLC(ListaCircular lc, item cantidad){
    if(cantidad !=0){
        printf("->%d", lc.cabecera->siguiente->dato);
        mostrarLC(LCROTAR(lc), cantidad-1);
        return;
    }else{
        return;
    }
}
