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
    struct nodo * siguiente;
} nodo;

//PROTOTIPADO
persona cargarPersona();
void cargarArchivo(FILE *archi, char nombre[]);
void mostrarArchivo(FILE* archi, char nombre[]);
nodo* inicLista();
void tomarPersona(FILE* archi, char nombre[], nodo* lista);
nodo* recorreArchivo(persona personita);
nodo* mostrarNodo(nodo* aux);

int main()
{
    //VARIABLES
    int opc;
    char nombre[] = {"miArchivo,bin"};
    FILE* archi;
    nodo* lista;

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
      /*  cargarArchivo(archi, nombre);
        mostrarArchivo(archi, nombre); */

        lista = inicLista;
        tomarPersona(archi, nombre, lista);

        recorreLista(lista);



        break;

    case 2:

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


void cargarArchivo(FILE *archi, char nombre[])
{

    persona aux;
    char opc;
    archi = fopen(nombre, "a+b");
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

void mostrarArchivo(FILE* archi, char nombre[])
{
    persona aux;
    int i = 1;
    archi = fopen(nombre, "r+b");
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

nodo* inicLista()
{
    return NULL;
}

void tomarPersona(FILE* archi, char nombre[], nodo* lista){

    persona aux;
    nodo* nuevo;
    archi = fopen(nombre, "rb");
    if(archi != NULL){
        while(!feof(archi)){
                fread(&aux, sizeof(persona) , 1, archi);
            if(!feof(archi)){
                nuevo = recorreArchivo(aux);
                lista = agregarPpio(lista,nuevo); //CREAR FUNCION DE AGREGAR UN NODO AL PRINCIPIO DE LA LISTA
            }
        }
        fclose(archi);
    }
    else{
        printf("\n\nError al abrir el archivo!\n");
        exit(0);
    }
return lista;

}

nodo* recorreArchivo(persona personita)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = personita;
    aux->siguiente = NULL;

    return aux;
}


nodo* mostrarNodo(nodo* aux)
{
    persona personita;
    printf("\n-----NODO-----");
    printf("\nNOMBRE: %s", aux->dato.nombre);
    printf("\nEDAD: %i \n", aux->dato.edad);

    return aux;
}

void recorreLista(nodo* lista){

    nodo* aux = lista;
    while ((aux->siguiente)!= NULL){
        aux=mostrarNodo(aux);
    }
}
