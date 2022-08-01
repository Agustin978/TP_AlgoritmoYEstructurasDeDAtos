#define indefinido -9999
typedef int item;

typedef struct nodo
{
    item dato;
    struct nodo* siguiente;

}nodo;

typedef struct LC
{
    nodo* cabecera;
    int longitud;

}LC;

LC LCvacia();
LC LCinsertar(LC L, item x);
bool LCesVacia(LC L);
LC LCborrar(LC L);
item LCvalor(LC L);
LC LCrotar(LC L);
void LCmostrar(LC L);
int LClongitud(LC L);
bool LCpertenece(LC L, LC Laux, item x);
LC LCborrarK(LC L, item k);
//int LClongitudRecursiva(LC L);

LC LCvacia()
{
    LC L;
    L.cabecera = NULL;
    L.longitud = 0;
    return L;
}

LC LCinsertar(LC L, item x)
{
    nodo* nuevo;
    nuevo = (nodo*) malloc(sizeof(nodo));

    nuevo->dato = x;

    if (L.cabecera == NULL)
    {
        L.cabecera = nuevo;
        nuevo->siguiente = nuevo;
        L.longitud++;

    }else
    {
        nuevo->siguiente = L.cabecera->siguiente;
        L.cabecera->siguiente = nuevo;
        L.longitud++;
    }
    
    return L;
}

bool LCesVacia(LC L)
{
    return L.cabecera == NULL;
}

LC LCborrar(LC L)
{
    if (L.cabecera==NULL)
    {
        return L;

    }else
    {
        nodo * aux = L.cabecera->siguiente;
        L.cabecera->siguiente = L.cabecera->siguiente->siguiente;
        free(aux);
        L.longitud--;
        return L;
    }
}

item LCvalor(LC L)
{
    if (L.cabecera == NULL) 
    {
        return indefinido;
    }else
    {
        return L.cabecera->siguiente->dato;
    }   
}

LC LCrotar(LC L)
{
    if (L.cabecera == NULL || L.longitud ==1 )
    {
        return L;

    }else
    {
        L.cabecera = L.cabecera->siguiente;
        return L;   
    }
}


void LCmostrar(LC L)
{
    int largo = L.longitud;

    if (!LCesVacia(L))
    {
        while (largo != 0)
        {
            printf("%2d ", L.cabecera->siguiente->dato);
            L = LCrotar(L);
            largo--;
        }    
    }
}

//forma iterativa
int LClongitud(LC L)
{
    int longitud = 0;

    if (L.cabecera != NULL)
    {
        nodo * aux = L.cabecera;
        do
        {
          longitud++;
          L = LCrotar(L);  

        } while (aux != L.cabecera);
    }

    free(aux);
    return longitud;
}

//forma recursiva
/*int LClongitudRecursiva(LC L)  
{
    
    if (!LCesVacia(L))
    {
        return 0;

    }else
    {
        return 1 + LC(longitudRecursiva( LCborrar(L));
    }
}*/

bool LCpertenece(LC L, LC Laux, item x) // al comienzo L.cabecera = Laux.cabecera
{
    if (Laux.cabecera->siguiente == L.cabecera )
    {
        if (Laux.cabecera->dato == x)
        {
            return true;
        }else
        {
            return false;
        }
    }else
    {
        return ( Laux.cabecera->dato == x ) || ( LCpertenece( L , LCrotar(Laux), x ) );
    }
}

LC LCborrarK(LC L, item k)
{
    if (!LCesVacia(L))
    {
        nodo * aux;
        aux = L.cabecera;
        do
        {
            if (L.cabecera->dato == k)
            {
                L = LCborrar(L);
            }
        
            L = LCrotar(L);

        } while (L.cabecera != aux);

        free(aux);
    }

    return L;
}


