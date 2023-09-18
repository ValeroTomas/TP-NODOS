#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct
{
    persona dato;
    struct nodo* siguiente;
} nodo;

//PROTOTIPADO
persona cargarPersona();
void cargarArchivo(char nombre[]);
void mostrarArchivo(char nombre[]);
nodo* inicLista();
nodo* listarPersona(char nombre[], nodo* lista);
nodo* agregarPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* crearNodo(persona personita);
void mostrarNodo(nodo* aux);
void muestraLista(nodo* lista);
nodo* ordenaLista(nodo* lista, nodo* nuevoNodo);

int main()
{
    //VARIABLES
    int opc;
    char nombre[] = {"miArchivo,bin"};
    FILE* archi;
    nodo* lista = inicLista(lista);

    //MENU

    printf("================MENU================\n");
    printf(" -Punto 1             -Punto 2\n");
    printf(" -Punto 3             -Punto 4\n");
    printf(" -Punto 5             -Punto 6\n");
    printf(" -Punto 7             -Salir\n");
    printf("====================================");
    fflush(stdin);
    printf("\nIngrese una opcion: \n");
    scanf("%i", &opc);



    switch(opc)
    {

    case 1: //Hacer un programa que lea de un archivo datos y los inserte en una lista
        //cargarArchivo(nombre);
        //mostrarArchivo(nombre);


        lista = listarPersona(nombre, lista);
        printf("LISTA SIN ORDENAR: ");

        muestraLista(lista);

        break;

    case 2: //Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada




        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    case 6:

        break;

        return 0;
    }
}

persona cargarPersona()
{

    persona aux;
    printf("\nNombre: ");
    fflush(stdin);
    gets(&aux.nombre);
    printf("\nEdad: ");
    fflush(stdin);
    scanf("%d", &aux.edad);

    return aux;
}


void cargarArchivo(char nombre[])
{

    persona aux;
    char opc;
    FILE* archi = fopen(nombre, "a+b");
    if(archi!=NULL)
    {
        do
        {
            aux = cargarPersona();
            fwrite(&aux, sizeof(persona), 1, archi);
            printf("\n Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c", &opc);
        }
        while(opc == 's');
        fclose(archi);
    }
    else
    {
        printf("\n Error al abrir el archivo!\n");
        exit(1);
    }
}

void mostrarArchivo(char nombre[])
{
    persona aux;
    int i = 1;

    FILE* archi = fopen(nombre, "r+b");
    if(archi != NULL)
    {
        do
        {
            fread(&aux, sizeof(persona), 1, archi);
            if (!feof(archi))
            {
                printf("\n--------------------------");
                printf("\n-PERSONA %i-", i);
                printf("\nNombre: %s", aux.nombre);
                printf("\nEdad: %d", aux.edad);
                printf("\n--------------------------\n");
                i++;
            }
        }
        while(!feof(archi));
        fclose(archi);
    }
    else
    {
        printf("\n\nError al abrir el archivo!");
        exit(1);
    }
}

nodo* inicLista(nodo* lista)
{
    lista = NULL;
    return lista;
}

nodo* listarPersona(char nombre[], nodo* lista)
{

    persona aux;
    nodo* nuevo;
    FILE* archi = fopen(nombre, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(persona), 1, archi);
            if(!feof(archi))
            {
                nuevo = crearNodo(aux);

                //lista = agregarPrincipio(lista,nuevo); //CREAR FUNCION DE AGREGAR UN NODO AL PRINCIPIO DE LA LISTA
                lista = ordenaLista(lista, nuevo);
            }
        }
        fclose(archi);
    }
    else
    {
        printf("\n\nError al abrir el archivo!\n");
        exit(0);
    }
    return lista;

}

nodo* crearNodo(persona personita)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = personita;
    aux->siguiente = NULL;

    return aux;
}

nodo* agregarPrincipio(nodo* lista, nodo* nuevoNodo)
{
    if (lista!=NULL)
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}





void mostrarNodo(nodo* aux)
{
    persona personita;
    printf("\n-----NODO-----");
    printf("\nNOMBRE: %s", aux->dato.nombre);
    printf("\nEDAD: %i \n", aux->dato.edad);

}

void muestraLista(nodo* lista)
{

    nodo* aux = lista;

    while (aux != NULL)
    {
        mostrarNodo(aux);
        aux = aux->siguiente;
    }
}

nodo* ordenaLista(nodo* lista, nodo* nuevoNodo)
{
    nodo* ante;
    nodo* seg;
    if (lista!=NULL)
    {
        if (strcmp(nuevoNodo->dato.nombre, lista->dato.nombre)<0)
        {
            lista = agregarPrincipio(lista, nuevoNodo);
        }
        else
        {
            ante = lista;
            seg = lista->siguiente;

            while((seg != NULL)&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
        nuevoNodo->siguiente = seg;
        ante->siguiente = nuevoNodo;
        }


    }
    else
    {
        lista = nuevoNodo;
    }


    return lista;
}
