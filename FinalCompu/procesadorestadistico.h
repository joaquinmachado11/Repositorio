#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H
#include<imagen.h>
#include <gestordearchivos.h>

class ProcesadorEstadistico
{
public:
    ProcesadorEstadistico();
    void setPtrImagen(Imagen *pImagen);

    float promedio();

    Pixel minimo();
    Pixel maximo();

    int moda ();
    float desvioEstandar();
    int area(); //este metodo se relaciona con alg pintor
    //histograma



private:
    Imagen *ptrImagen;
};

#endif // PROCESADORESTADISTICO_H
