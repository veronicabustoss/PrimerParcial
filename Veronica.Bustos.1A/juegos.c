#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "utn.h"

static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int inicializarJuegos(eJuegos* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = 0;
    }

    return retorno;

}

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones Juegos-----\n\n");
    printf("1. Alta juego \n");
    printf("2. Modificar juego \n");
    printf("3. Baja  juego \n");
    printf("4. Listar juegos \n");
    printf("-----Menu de opciones Clientes-----\n\n");
    printf("5. Alta cliente\n");
    printf("6. Modificar cliente\n");
    printf("7. Baja cliente\n");
    printf("8. Listar clientes\n");
    printf("-----Menu de opciones Alguileres-----\n\n");
    printf("9. Alta a alquiler \n");
    printf("10. Salir\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int espacioLibreJuegos(eJuegos* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;
}

int mostrarUnJuego(eJuegos* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
            printf("%d\t    %s\t    %f \n\n", lista[indice].codigoJuego, lista[indice].descripcion, lista[indice].importe);
            retorno=0;
        }
    }
    return retorno;

}

int mostrarTodosLosJuegos(eJuegos* lista, int len)
{
    int retorno=-1;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    DESCRIPCION\t    IMPORTE\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnJuego(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int buscarJuegoPorId(eJuegos* lista, int len, int id)
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].codigoJuego == id && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int agregarJuego(eJuegos* lista, int len)
{
    eJuegos auxiliarJuegos;
    int lugarLibre = espacioLibreJuegos(lista, len);
    int retorno=-1;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            getValidString("Ingrese descripcion del Juego: ", "Error, ingrese nuevamente.", auxiliarJuegos.descripcion);//arreglar lo de los espacios
            auxiliarJuegos.importe = getValidFloat("Ingrese importe del juego: ", "Error, ingrese nuevamente.", 1, 10000);
            auxiliarJuegos.codigoJuego = generarNextId();
            auxiliarJuegos.isEmpty=0;
            lista[lugarLibre]=auxiliarJuegos;
            retorno=0;

        }
    }

    return retorno;
}

int removerJuego(eJuegos* lista, int len, int id)
{
    int index;
    int i;
    int retorno=-1;

    if(lista!=NULL)
    {
        printf("Ingrese el id del juego que desa eliminar: ");
        scanf("%d",&id);
        index=buscarJuegoPorId(lista, len, id);

        if(lista[index].isEmpty==0)
        {
            printf("ID\t   DESCRIPCION\t   IMPORTE\n");
            mostrarUnJuego(lista, index);
        }
        //Tendria que preguntar si quiere eliminar la pelicula
        for( i=0 ; i<len ; i++)
        {
            if(index>=0)
            {
                printf("El juego fue eliminado!\n");
                lista[index].isEmpty=1;
                break;
            }
            else
            {
                printf("No existe ese id!! \n");
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}

int modificarJuegos(eJuegos* lista,int len,  int id)
{
    int index;
    int cambiar;
    char nuevaDescripcion[51];
    float nuevoImporte;
    int retorno=-1;
    char continuar='n';

    printf("Ingrese el Id. del juego que desea modificar:\n");
    scanf("%d", &id);
    index=buscarJuegoPorId(lista, len, id);

    if(lista!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("ID\t   DESCRIPCION\t   IMPORTE\n");
                mostrarUnJuego(lista, index);
                //llamar funcion que me muesstra los datos de esa posicion
                printf("\n\nSeleccione la opcion que desea modificar:");
                printf("\n1. Descripcion\n");
                printf("2. Importe\n");
                scanf("%d", &cambiar);
                switch(cambiar)
                {
                case 1:
                    getValidString("Ingrese nueva descripcion del juego:  ", "Error, ingrese nuevamente.",nuevaDescripcion);
                    strcpy(lista[index].descripcion, nuevaDescripcion);
                    break;

                case 2:
                    nuevoImporte= getValidFloat("Ingrese nuevo importe del juego: ","Error,ingrese nuevamente.", 0, 2023);
                    lista[index].importe= nuevoImporte;
                    break;
                default :
                    printf("Dato no valido\n");
                }

                printf("Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&continuar);
                system("pause");
                system("cls");
            }
            while(continuar=='s' || continuar=='S');
        }
        else if(index < 0)
        {
            printf("No existe ese Id. \n");
        }

        retorno=0;

    }

    return retorno;
}

int mostrarJuegos(eJuegos* lista, int len)
{
    int retorno=-1;
    eJuegos auxiliarJuegos;
    int i, j ;
    mostrarTodosLosJuegos(lista, len);
    if(lista!= NULL)
    {
            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {

                    if(lista[j].importe>lista[i].importe)
                    {
                        auxiliarJuegos = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarJuegos;
                    }
                    else if(lista[j].importe==lista[i].importe && (strcmp(lista[j].descripcion,lista[i].descripcion)<0)) /*&& lista[j].sector<lista[i].sector)*/
                    {
                        auxiliarJuegos = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarJuegos;
                    }
                }
            }
            printf("\nOpcion completada con exito.\n");

        retorno=0;
    }

    return retorno;

}
