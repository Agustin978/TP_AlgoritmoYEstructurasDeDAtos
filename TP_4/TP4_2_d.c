#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

struct Alumno
{
    char apellido;
    struct Alumno* siguiente;
};
typedef struct Alumno* Alumno;

//Declaracion de funciones
Alumno creaComision(); //Crea una comision vacia
Alumno AltaAlumno(Alumno comision, char apellido); //Da de alta un nuevo alumno
bool EstaVacia(Alumno comision); //Determina si esta vacia
int Cantidad(Alumno comision); //Devuelve la longitud de la lista
Alumno BajaAlumno(Alumno comision, char apellido); //Da de baja un alumno dado
Alumno BajaUltimo(Alumno comision);  //Da de baja el ultimo alumno ingresado
char UltimoInscripto(Alumno comision);  //Devuelve el nombre y apellido del ultimo alumno inscripto en la lista
bool Esta(Alumno comision, char apellido);  //Determina si un alumno solicitado se encuentra en la lista o no
bool HayComunes(Alumno comision, Alumno comision_2);  //Determina si dos comisiones tiene alumnos en comun

int main()
{
    Alumno comision = creaComision();

    return 0;
}

Alumno creaComision()
{
    return NULL;
}

Alumno AltaAlumno(Alumno comision, char apellido)
{
    Alumno nuevo = (Alumno)malloc(sizeof(Alumno));
    nuevo->apellido = apellido;
    nuevo->siguiente = comision;
    comision = nuevo;
    return comision;
}

bool EstaVacia(Alumno comision)
{
    Alumno seguidor = comision;
    int contador = 0;

    while (seguidor != NULL)
    {
        seguidor = seguidor->siguiente;
        contador++;
    }

    if(contador>0)
    {
        return false;
    }else
    {
        return true;
    }
}

int Cantidad(Alumno comision)
{
    Alumno seguidor = comision;
    int contador = 0;

    while (seguidor != NULL)
    {
        seguidor = seguidor->siguiente;
        contador++;
    }
    
    return contador;
}

char UltimoInscripto(Alumno comision)
{
    Alumno seguidor = comision;
    char apellido;

    if(!EstaVacia(comision))
    {
        while (seguidor != NULL)
        {
            apellido = seguidor->apellido;
            seguidor = seguidor->siguiente;
        }
    }
    return apellido;
}

bool Esta(Alumno comision, char apellido)
{
    Alumno seguidor = comision;

    if(!EstaVacia(comision))
    {
        while (seguidor != NULL)
        {
            if(seguidor->apellido == apellido)
            {
                return true;
            }
            seguidor = seguidor->siguiente;
        }
    }

    return false;
}

Alumno BajaUltimo(Alumno comision)
{
    Alumno seguidor = comision;
    Alumno anterior;
    if(!EstaVacia(seguidor))
    {
        while (seguidor!=NULL)
        {
            anterior = seguidor;
            if(seguidor->siguiente == NULL)
            {
                fflush(stdin);
                free(seguidor);
                anterior->siguiente = NULL;
            }
            seguidor = seguidor->siguiente;
        } 
    }
    return comision;
}

Alumno BajaAlumno(Alumno comision, char apellido)
{
    Alumno seguidor = comision;
    Alumno anterior;

    if(!EstaVacia(comision) && Esta(comision, apellido))
    {
        while (seguidor != NULL && seguidor->apellido != apellido)
        {
            anterior = seguidor;
            seguidor = seguidor->siguiente;
        }

        if(seguidor!=NULL)
        {
            fflush(stdin);
            anterior = seguidor->siguiente;
            free(seguidor);
            printf("Alumno %s dado de baja.", apellido);
        }
        
    }
    return comision;
}

bool HayComunes(Alumno comision, Alumno comision_2)
{
    if(!EstaVacia(comision))
    {
        while (comision_2!=NULL)
        {
            if(Esta(comision, comision_2->apellido))
            {
                return true;
            }
            
            comision_2 = comision_2->siguiente;
        }
    }
    return false;
}