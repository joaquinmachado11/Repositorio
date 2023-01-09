#include "imagen.h"

int Imagen::getFilas() const
{
    return filas;
}

void Imagen::setFilas(int newFilas)
{
    filas = newFilas;
}

int Imagen::getColumnas() const
{
    return columnas;
}

void Imagen::setColumnas(int newColumnas)
{
    columnas = newColumnas;
}

Imagen::Imagen()
{

}

void Imagen::dimensionar()
{
    imagen.resize(filas);
    for (unsigned int i=0; i<filas; i++)
    {
        imagen[i].resize(columnas);
    }
}

Pixel Imagen::getPixel(int fila, int columna)
{
    return imagen[fila][columna];
}

int Imagen::getRangoDinamico() const
{
    return rangoDinamico;
}

void Imagen::setRangoDinamico(int newRangoDinamico)
{
    rangoDinamico = newRangoDinamico;
}
