#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"

static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int inicializarAlquiler(eAlquileres* lista, int len)
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


int espacioLibreAlquiler(eAlquileres* lista, int len)
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

int altaAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    eAlquileres auxiliarAlquiler;
    int retorno=-1;
    int estaLibre=espacioLibreAlquiler(listaAlquileres, lenAlquileres);
    if(estaLibre==-1)
    {
        printf("No hay espacio libre");
    }
    if(estaLibre!=-1)
    {
        auxiliarAlquiler.codigoJuego = elegirJuego(listaJuegos, lenJuegos);

        if(auxiliarAlquiler.codigoJuego==-1)
        {
            printf("No existe ese Id.\n");
        }
        else
        {
            auxiliarAlquiler.codigoCliente=elegirCliente(listaCliente, lenCliente);
            if(auxiliarAlquiler.codigoCliente==-1)
            {
                printf("No existe ese Id.\n");
                system("pause");
            }
            else
            {
                auxiliarAlquiler.fechaIngreso.dia= getValidInt("Ingrese dia: ","Error, dia no valido.", 1, 31);
                auxiliarAlquiler.fechaIngreso.mes = getValidInt("Ingrese mes: ","Error, mes no valido.", 1, 12);
                auxiliarAlquiler.fechaIngreso.anio = getValidInt("Ingrese anio: ","Error, anio no valido.", 1000, 2018);
                auxiliarAlquiler.codigoAlquiler=generarNextId();
                listaAlquileres[estaLibre] = auxiliarAlquiler;

                printf("Se alquilo el juego:  ");
                mostrarUnJuego(listaJuegos, auxiliarAlquiler.codigoJuego);
                printf("Y el cliente que lo alquilo fue: ");
                mostrarUnCliente(listaCliente, auxiliarAlquiler.codigoCliente); //No me esta tomando el cliente
                printf("En el dia de la fecha : %d/%d/%d", auxiliarAlquiler.fechaIngreso.dia,auxiliarAlquiler.fechaIngreso.mes, auxiliarAlquiler.fechaIngreso.anio);

                auxiliarAlquiler.isEmpty=0;
                printf("Alquiler logrado con exito!\n");
                retorno=0;
            }
        }
    }
    return retorno;

}

int elegirJuego(eJuegos* listaJuegos, int len)
{
    int retorno=-1;
    int i;
    int idJuegos;
    printf("\nJuegos\n\n");
    mostrarTodosLosJuegos(listaJuegos, len);
    printf("\nSeleccione Juego: ");
    scanf("%d", &idJuegos);
    for( i=0; i<len ; i++)
    {
        if(listaJuegos[i].codigoJuego==idJuegos && listaJuegos[i].isEmpty==0)
        {
            retorno=idJuegos;
            break;
        }
        if (listaJuegos[i].codigoJuego!=idJuegos && listaJuegos[i].isEmpty==0)
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int elegirCliente(eCliente* listaCliente, int len)
{
    int retorno=-1;
    int idClientes;
    int i;
    printf("\nClientes\n\n");
    mostrarTodosLosClientes(listaCliente, len);
    printf("\nSeleccione cliente :  ");
    scanf("%d",&idClientes);
    for(i=0; i < len; i++)
    {
        if(listaCliente[i].codigoCliente == idClientes && listaCliente[i].isEmpty==0)
        {
            retorno=idClientes;
            break;
        }
        if (listaCliente[i].codigoCliente!=idClientes && listaCliente[i].isEmpty==0)
        {
            retorno=-1;
            break;
        }

    }

    return retorno;
}


