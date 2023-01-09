#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H
#include<imagen.h>


class ProcesadorEstadistico
{
public:
    ProcesadorEstadistico();
    float promedio(Imagen);
    int minimo (Imagen);
    int maximo (Imagen);
    int moda (Imagen);
    float desvioEstandar(Imagen);
    int area(Imagen); //este metodo se relaciona con alg pintor
};

#endif // PROCESADORESTADISTICO_H
