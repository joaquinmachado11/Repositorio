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

bool Imagen::estaEnLaImagen(int f, int c)
{
    return (f < filas    and f >= 0 and
            c < columnas and c >= 0);
}

Pixel Imagen::getPixel(int fila, int columna)
{
    return imagen[fila][columna];
}

void Imagen::setPixel(int fila, int columna, Pixel pixel)
{
    imagen[fila][columna] = pixel;
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

void Imagen::definirCodigoDeGuardado(int opcion)
{
    string nuevoCodigo;

    if (opcion == 1 and (codigo == "P4" or codigo == "P5" or codigo == "P6"))
        nuevoCodigo = codigo;

    if (opcion == 2 and (codigo == "P1" or codigo == "P2" or codigo == "P3"))
        nuevoCodigo = codigo;


    if (opcion == 1 and codigo == "P1")
        nuevoCodigo = "P4";

    if (opcion == 1 and codigo == "P2")
        nuevoCodigo = "P5";

    if (opcion == 1 and codigo == "P3")
        nuevoCodigo = "P6";


    if (opcion == 2 and codigo == "P4")
        nuevoCodigo = "P1";

    if (opcion == 2 and codigo == "P5")
        nuevoCodigo = "P2";

    if (opcion == 2 and codigo == "P6")
        nuevoCodigo = "P3";


    if (opcion == 3 and (codigo != "P3" and codigo != "P6"))
        nuevoCodigo = "P2C";

    codigo = nuevoCodigo;
}

int Imagen::getRangoDinamico() const
{
    return rangoDinamico;
}

void Imagen::setRangoDinamico(int newRangoDinamico)
{
    rangoDinamico = newRangoDinamico;
}
