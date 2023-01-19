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
    ~Imagen();

    int getFilas() const;
    void setFilas(int newFilas);

    int getColumnas() const;
    void setColumnas(int newColumnas);

    int getRangoDinamico() const;
    void setRangoDinamico(int newRangoDinamico);

    void dimensionar();

    Pixel& getPixel (int fila, int columna); //ver si esta bien escrito
    void setPixel (int fila, int columna, Pixel pixel);

    const string &getCodigo() const;
    void setCodigo(const string &newCodigo);

    void setDescripcion(const string &newDescripcion);
    const string &getDescripcion() const;

private:
    vector < vector < Pixel >> imagen;
    int filas;
    int columnas;
    int rangoDinamico;
    string descripcion;
    string codigo;
};

#endif // IMAGEN_H
