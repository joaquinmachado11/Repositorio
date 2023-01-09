#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <iostream>
#include <pixel.h>

using namespace std;

class Imagen
{
public:
    Imagen();

    int getFilas() const;
    void setFilas(int newFilas);

    int getColumnas() const;
    void setColumnas(int newColumnas);

    int getRangoDinamico() const;
    void setRangoDinamico(int newRangoDinamico);

    void dimensionar();
    Pixel getPixel (int fila, int columna); //ver si se pasa como puntero

private:
    vector < vector < Pixel >> imagen;
    int filas;
    int columnas;
    int rangoDinamico;
};

#endif // IMAGEN_H
