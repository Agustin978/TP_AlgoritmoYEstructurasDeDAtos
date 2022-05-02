#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

typedef int item;
const item indefinido = -9999;

typedef struct Nodo
{
    item dato; //Dato ingresado a la pila (Puede ser de cualquier tipo)
    struct Nodo *nodoSig;
}Nodo;

typedef struct
{
    struct Nodo *cabecera;  //Apunta siempre al ultimo elemento ingrezado en la pila
    int altura; //Para obtener el tamaño de la pila sin implementar bucles
}Pila;

//typedef struct Pila *Pila;

//Declaracion de funciones
void creaPila(Pila *pila);  //Constructora
bool EsPilaVacia(Pila pila);  //Constructora
item Top(Pila *pila); //Obtengo el primer elemento de la pila
Pila *Push(Pila *pila, item dato);  //Agrego un elemento a la cabecera de la pila
Pila *Pop(Pila *pila); //Quito el primer elemento de la pila
int Altura(Pila *pila); //Devuelve la altura de la pila
int menu(); //Menu interactivo
void limpiaPila(Pila *pila);
/*
int main()
{
    Pila *pila;
    creaPila(pila);

    int op;

    do
    {
        op = menu();

        switch (op)
        {
            case 1:
                if(EsPilaVacia(*pila))
                {
                    printf("\nLa pila si esta vacia.");
                }else
                {
                    printf("\nLa pila no esta vacia.");
                }
                break;
            
            case 2:
                item dato;
                printf("\nIngrese el dato que desea ingresar a la pila: ");
                gets(dato);
                fflush(stdin);
                Push(pila, dato);
                break;
            
            case 3:
                if(!EsPilaVacia(*pila))
                {
                    Pop(pila);
                    printf("\nPrimer elemento de la pila eliminado.");
                }else
                {
                    printf("\nError.. La pila esta vacia.");
                    printf("\nIngrese algun dato a la pila y vuelva a intentarlo.");
                }
                break;
            
            case 4:
                printf("\nEl dato que se encuentra al principio de la pila es: ");
                puts(Top(pila));
                break;
            
            case 5:
                printf("\nEl tamaño de la pila actualmente es de %d elementos.", Altura(pila));
                break;
            
            default:
                limpiaPila(pila);
                printf("Muchas gracias por usar el programa :)");
                break;
        }
        
    }while (op!=6);
    

    return 0;
}*/

int main()
{
    Pila pila;
    creaPila(&pila);

    printf("\n¿Es pila vacia?");
    if(EsPilaVacia(pila))
    {
        printf("\nLa pila es vacia.");
    }else
    {
        printf("\nLa pila no es vacia.");
    }

    printf("\nIngresando dato numerico 10");
    Push(&pila, 10);
    printf("\n¿Ahora la pila es vacia?");
    if(EsPilaVacia(pila))
    {
        printf("\nLa pila es vacia.");
        printf("\nEl primer elemento de la pila es:");
        puts(Top(&pila));
    }else
    {
        printf("\nLa pila no es vacia.");
    }

    printf("\nIngresando dato string Auto");
    Push(&pila, "Auto");
    printf("\n¿Ahora la pila es vacia?");
    if(EsPilaVacia(pila))
    {
        printf("\nLa pila es vacia.");
        printf("\nEl primer elemento de la pila es:");
        puts(Top(&pila));
    }else
    {
        printf("\nLa pila no es vacia.");
    }

    printf("\nTamaño de la pila: %d", Altura(&pila));

    limpiaPila(&pila);
    return 0;
}

void creaPila(Pila *pila)
{
    pila->cabecera = NULL;
    pila->altura=0;
}

bool EsPilaVacia(Pila pila)
{
    if(pila.altura==0)
    {
        return true;
    }
    return false;
}

item Top(Pila *pila)
{
    if(EsPilaVacia(*pila))
    {
        puts("Pila vacia.");
        exit(0);
    }
    return pila->cabecera->dato;
}

Pila *Push(Pila *pila, item dato)
{
    Nodo *nodoAux = (Nodo*)malloc(sizeof(Nodo)); //Reservo dinamicamente la memoria
    nodoAux->dato = dato;
    nodoAux->nodoSig = pila->cabecera;
    pila->cabecera = nodoAux;
    pila->altura += 1;
}

Pila *Pop(Pila *pila)
{
    if(!EsPilaVacia(*pila))
    {
        struct Nodo *nodoSeguidor = pila->cabecera;
        //El nodo auxiliar apuntara al nodo al que apunta la cabecera
        pila->cabecera = pila->cabecera->nodoSig;
        pila->altura -= 1; //Resto uno a la altura
        //Hago que la cabecera de la pila apunte al nodo que le sigue a la cabecera
        free(nodoSeguidor);
        //Limpio la memoria del nodo que quite de la lista
    }
}

int Altura(Pila *pila)
{
    if(!EsPilaVacia(*pila))
    {
        return pila->altura;
    }
    return 0;
}

void limpiaPila(Pila *pila)
{
    while (!EsPilaVacia(*pila))
    {
        Pop(pila); //Libero nodo a nodo la pila
    }
}

int menu()
{
    int respuesta;
    printf("\n\n--------Menu Pilas--------\n");
    do
    {
        printf("1- Verificar si es una pila vacia.\n");
        printf("2- Ingresar un nuevo dato a la pila creada.\n");
        printf("3- Eliminar primer elemento de la pila.\n");
        printf("4- Obtener el primer elemento que se encuentra en la pila.\n");
        printf("5- Obtener el tamaño de la pila.\n");
        printf("6- Salir del programa.\n");
        printf("*Ingresar una opcion: ");
        scanf("%d", &respuesta);
        fflush(stdin);
    } while (respuesta<=0 || respuesta>6);
    return respuesta;
}