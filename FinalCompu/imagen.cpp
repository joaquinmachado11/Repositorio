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

Imagen::~Imagen()
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

void Imagen::setPixel(int fila, int columna, Pixel pixel)
{
    imagen[fila][columna]=pixel;
}

const string &Imagen::getCodigo() const
{
    return codigo;
}

void Imagen::setCodigo(const string &newCodigo)
{
    codigo = newCodigo;
}

void Imagen::setDescripcion(const string &newDescripcion)
{
    descripcion = newDescripcion;
}

const string &Imagen::getDescripcion() const
{
    return descripcion;
}

int Imagen::getRangoDinamico() const
{
    return rangoDinamico;
}

void Imagen::setRangoDinamico(int newRangoDinamico)
{
    rangoDinamico = newRangoDinamico;
}
