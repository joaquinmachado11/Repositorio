#include "graficador.h"

Graficador::Graficador()
{

}

void Graficador::graficarImagen(int id)
{
    //imagen_aux=ptrGestorDeArchivo.generarImagen(id);
}

void Graficador::setGestorDeArchivos(GestorDeArchivos &gestorDeArchivos)
{
    ptrGestorDeArchivos=&gestorDeArchivos;
}
