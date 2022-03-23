#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Nodo
{
    int dato;
    struct Nodo* siguiente;
};
typedef struct Nodo* Lista;

//int menu(); /*Menu del programa*/
Lista crearLista(); /*Creacion de la lista*/
Lista insertarDato(Lista L, int n); /*Agrega un nuevo elemento a la lista*/
bool esVacia(Lista L); /*Determina si la lista esta vacia o no*/
void mostrar(Lista L); /*Muestra la lista por pantalla*/
int primerElemento(Lista L); /*Retorna unicamente el primer elemento de la lista*/
int ultimoElemento(Lista L); /*Retorna unicamente el ultimo elemento de la lista*/
int longitud(Lista L); /*Retorna la cantidad de nodos que contiene la lista*/
bool pertenece(Lista L, int n); /*Determina si un elemento dado pertenece a la lista*/
Lista eliminaPrimerElemento(Lista L); /*Elimina el primer elemento de la lista*/
Lista eliminaElemento(Lista L, int n); /*Elimina un elemento especifico de la lista*/

int main()
{
    bool resp;
    //int respuesta;
    //respuesta = menu();
    Lista L = crearLista(); //Creacion de la lista
    printf("\n\n=======Inicio del programa=======\n\n");
    printf("\nDir: %p\n", L);
    //printf("Direccion de memoria: %p", &L);

    //Lista elemento1 = (Lista) malloc(sizeof(Lista));
    L = insertarDato(L, 2);
    L = insertarDato(L, 15);
    L = insertarDato(L, 254);
    L = insertarDato(L, 24);
    L = insertarDato(L, 4);
    L = insertarDato(L, 75);
    //printf("Dir: %p\n", L);

    resp = esVacia(L);
    printf("¿La lista es vacia?\n");
    if(resp == false)
    {
        printf("La lista no es vacia\n\n");
    }else
    {
        printf("La lista si es vacia\n\n");
    }
    
    printf("Elementos de la lista:\n");
    mostrar(L);

    printf("\nEl primer elemento de la lista actualmente es: %d\n", primerElemento(L));
    printf("El ultimo elemento de la lista actualmente es: %d\n", ultimoElemento(L));

    printf("\nLa longitud de la lista es: %d\n", longitud(L));

    int n = 15;
    resp = pertenece(L, n);
    printf("\n¿El numero %d pertenece a la lista?\n", n);
    if(resp == true)
    {
        printf("El numero %d SI pertenece a la lista.\n", n);
    }else
    {
        printf("El numero %d NO pertenece a la lista.\n", n);
    }

    L = eliminaPrimerElemento(L);
    printf("\nPrimer elemento eliminado\n");
    printf("\nElementos de la lista:\n");
    mostrar(L);

    L = eliminaElemento(L, n);
    printf("\nElemento %d eliminado\n", n);
    printf("\nElementos de la lista:\n");
    mostrar(L);
    //int respuesta;
    //respuesta = menu();
    return 0;
}

Lista crearLista()
{
    return NULL;
}

Lista insertarDato(Lista L, int X){

    Lista nuevo = (Lista) malloc(sizeof(Lista));
    nuevo->dato=X;
    nuevo->siguiente=L;
    L = nuevo;
    return L;
}

bool esVacia(Lista L)
{
    struct Nodo *seg = L;
    int cont = 0;

    while (seg != NULL)
    {
        seg = seg->siguiente;
        cont++;
    }

    if(cont>0)
    {
        return false;
    }else
    {
        return true;
    }
    
}

void mostrar(Lista L)
{
    struct Nodo *seguidor = L;
    int contador = 1;
    while (seguidor != NULL)
    {
        printf("Elemento %d: %d\n", contador, seguidor->dato);
        seguidor = seguidor->siguiente;
        contador++;
    }
}

int primerElemento(Lista L)
{
    struct Nodo *seguidor = L;
    int dato, contador = 0;
    while (seguidor != NULL && contador != 1)
    {
        dato = seguidor->dato;
        seguidor = seguidor->siguiente;
        contador++;
    }
    
    return dato;
}

int ultimoElemento(Lista L)
{
    struct Nodo *seguidor = L;
    int dato;

    while (seguidor!=NULL)
    {
        dato = seguidor->dato;
        seguidor = seguidor->siguiente;
    }

    return dato;
}

int longitud(Lista L)
{
    struct Nodo *seguidor = L;
    int contador=0;
    while (seguidor!=NULL)
    {
        seguidor = seguidor->siguiente;
        contador++;
    }
    return contador;
}

bool pertenece(Lista L, int n)
{
    struct Nodo *seguidor = L;
    while (seguidor!=NULL)
    {
        if (seguidor->dato == n)
        {
            return true;
        }
        
        seguidor = seguidor->siguiente;
    }

    return false;
}

Lista eliminaPrimerElemento(Lista L)
{
    struct Nodo* seguidor = L;
    //int contador = 0;
    L = L->siguiente;
    //printf("%d // %d", seguidor->dato, seguidor->siguiente);
    free(seguidor);
    //printf("%d", L->dato);
    return L;
}

Lista eliminaElemento(Lista L, int n)
{
    struct Nodo *seguidor = L;
    struct Nodo *ant;
    while (seguidor != NULL && seguidor->dato!=n)
    {
        ant = seguidor;
        seguidor = seguidor->siguiente;
    }

    if(seguidor!=NULL)
    {
        ant->siguiente = seguidor->siguiente;
        free(seguidor);
    }
    return L;
}

/*
int menu()
{
    int resp;
    while (resp <= 0 || resp > 9)
    {
        printf("======Menu del Programa======\n");
        printf("1) Crear una nueva lista.\n");
        printf("2) Verificar si la lista esta vacia.\n");
        printf("3) Mostrar el contenido de la lista.\n");
        printf("4) Mostrar el primer elemento de la lista.\n");
        printf("5) Insertar un nuevo elemento a la lista.\n");
        printf("6) Borrar el elemento del comienzo de la lista.\n");
        printf("7) Conocer la cantidad de elementos que contiene la lista.\n");
        printf("8) Determinar si un elemento pertenece a la lista.\n");
        printf("9) Borrar elementos.\n");
        printf("Ingrese una opcion del menu: ");
        scanf("%p", resp);
    }
    return resp;
}*/