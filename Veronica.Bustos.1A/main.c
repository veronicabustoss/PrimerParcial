#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#define JUE 100
#include "clientes.h"
#define CLI 1000
#include "alquileres.h"
#define ALQ 1000
int main()
{
    char seguir  = 's';

    eJuegos juegosInfantiles[JUE];
    eCliente clientes[CLI];
    eAlquileres alquileres[ALQ];
    int lugarLibreJuegos;
    int lugarLibreCliente;
    int flagJuegos=0;
    int flagClientes=0;
    inicializarJuegos(juegosInfantiles, JUE);
    incializarClientes(clientes, CLI);
    inicializarAlquiler(alquileres, ALQ);

    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            flagJuegos=1;
            lugarLibreJuegos=espacioLibreJuegos(juegosInfantiles, JUE );
            if(lugarLibreJuegos!=-1)
            {
                agregarJuego(juegosInfantiles, JUE);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 2:
            if(flagJuegos==1)
            {
                modificarJuegos(juegosInfantiles, JUE, lugarLibreJuegos);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flagJuegos==1)
            {
                removerJuego(juegosInfantiles, JUE, lugarLibreJuegos);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flagJuegos==1)
            {
                mostrarJuegos(juegosInfantiles, JUE);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            flagClientes=1;
            lugarLibreCliente=espacioLibreCliente(clientes, CLI );
            if(lugarLibreCliente!=-1)
            {
                agregarCliente(clientes, CLI);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 6:
            if(flagClientes==1)
            {
                modificarCliente(clientes, CLI, lugarLibreCliente);

            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if(flagClientes==1)
            {
                removerCliente(clientes, CLI, lugarLibreCliente);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            if(flagClientes==1)
            {
                mostrarCliente(clientes, CLI);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            if(flagClientes==1 && flagJuegos==1)
            {
               altaAlquileres(alquileres, ALQ, juegosInfantiles, JUE, clientes, CLI);
            }
            else
            {
                printf("No hay datos que mostrar!\n");
            }
            system("pause");
            system("cls");
            break;
        case 10:
            seguir  = 'n';
            break;
        default:
            printf("Se ingresaron mal los datos\n");
        }

    }
    while(seguir == 's');

    return 0;
}
