#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaIngreso;
    int isEmpty;

}eAlquileres;

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eAlquileres Puntero del array de alquileres
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */
int inicializarAlquiler(eAlquileres* lista, int len);

/** \brief Indica que posicion del array esta vacia
 * \param lista* eAlquileres Puntero del array de alquileres
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */
int espacioLibreAlquiler(eAlquileres* lista, int len);

int altaAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );

int elegirJuego(eJuegos* listaJuegos, int len);

int elegirCliente(eCliente* listaCliente, int len);

#endif
