#include"ListaCircular.h"

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

    return 0;
}
