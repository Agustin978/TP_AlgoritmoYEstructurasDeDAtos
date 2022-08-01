typedef int item;
const indefinido -9999;

typedef struct 
{
    item dato;
    struct nodo * siguiente;

}nodo;


typedef struct 
{
    nodo* frente;
    nodo* final;

}fila;

fila FilaVacia();
bool EsFilaVacia(fila f);
fila EnFila(fila f, item i);
fila DeFila(fila f);

// Constructora primitiva - crea una fila vacia
fila FilaVacia()
{
    fila f;
    f.final = NULL;
    f.frente = NULL;
    return f;
}
// Test - Si estq vacia una fila o no
bool EsFilaVacia(fila f)
{
    if (f.final == NULL && f.frente=NULL)
    {
        return true;
    }else
    {
        return false;
    }
}

// Constructora primitiva - agrega un nodo a la fila

fila EnFila(fila f, item i)
{
    nodo nuevo; 
    nuevo.siguiente = f.final;
    f.final = &nuevo;
    nuevo.dato = i; 
    return f; 
}

// DeFilo 


fila DeFila(fila f)
{
    if (!EsFilaVacia(f))
    {
        fila aux;
        aux.final = f.final;
        while (aux.final->siguiente != f.frente)
        {
            aux.final = aux.final->siguiente; 
        }

        free(aux.final->siguiente);
        
    }else
    {
        printf("La fila eta vacia, no hay elementos para borrar");
        return f;
    }
    
    
}



