typedef int  item;
const int indefinido=-9999;

typedef struct nodo
{
    int dato;
    struct nodo* sig;
}nodo;

typedef struct Fila
{
     nodo* frente;
     nodo* final;
     int altura;

}Fila;

Fila filaVacia();
bool esFilaVacia(Fila F);
void enFila(Fila * F, item x);
void deFila(Fila * F); 
item frente(Fila F);
void mostrar(Fila F);
int cuentaImpares(Fila * F);
//Fila FilaConMayoresQueFrente(Fila F,item frenteDato, Fila G);
int sumaPositivos(Fila * F);


Fila filaVacia()
{
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    return F;

} // me crea una estructura que tiene dos punteros apuntand a null

bool esFilaVacia(Fila F)
{
    return ( (F.frente == NULL) && (F.final == NULL) );
}

void enFila(Fila * F, item x)
{
    nodo * nuevo; 
    nuevo = (nodo*) malloc(sizeof (nodo));
    nuevo->dato = x;
    nuevo->sig = NULL;

    if (esFilaVacia(*F))
    {
        F->frente = nuevo;
        F->final = nuevo;
        F->altura = F->altura + 1;

    }else
    {
        F->final->sig = nuevo;
        F->final = nuevo;
        F->altura = F->altura + 1;
    }
}

void deFila(Fila * F)
{
  struct nodo* aux;
  aux = F->frente;

  if (F->frente != NULL && F->final!= NULL)
  {
    if (F->frente == F->final)
    {
        F->final = NULL;
        F->frente = NULL;
        free(aux);

    }else
    {
        F->frente = F->frente->sig;
        free(aux);
    } 
  }

}

item frente(Fila F)
{
    if (esFilaVacia(F))
    {
        return indefinido;
    }else
    {
        return F.frente->dato;    
    }
}

void mostrar(Fila F)
{
    nodo* aux = F.frente;

    while (aux != NULL )
    {
        printf("%2d ", aux->dato);
        aux = aux->sig;
    }
}

int cuentaImpares(Fila * F)
{
    if (esFilaVacia(*F))
    {
        return 0;

    }else
    {
        if (frente(*F) % 2 != 0)
        {
            deFila(F);
            return 1 + cuentaImpares(F);

        }else
        {
            deFila(F);
            return cuentaImpares(F);
        }
    }
}


/*Fila FilaConMayoresQueFrente(Fila F,item frenteDato, Fila G)
{
    if (esFilaVacia(F))
    {
        return G;
    }else
    {
        if (frenteDato < F.frente->dato)
        {
            G = enFila(G, F.frente->dato);
            return FilaConMayoresQueFrente(deFila(F),frenteDato,G);
            
        }else
        {
            return FilaConMayoresQueFrente(deFila(F),frenteDato,G);
        }
    }
    
}*/

int sumaPositivos(Fila * F)
{
    if (esFilaVacia(*F))
    {
        return 0;

    }else
    {
        if (frente(*F))
        {
            deFila(F);
            return frente(*F) + sumaPositivos(F);

        }else
        {
            deFila(F);
            return sumaPositivos(F);
        }
    }
}