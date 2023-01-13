#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H
#include<imagen.h>


class ProcesadorEstadistico
{
public:
    ProcesadorEstadistico();
    float promedio(Imagen& imagen);
    int minimo (Imagen& imagen);
    int maximo (Imagen& imagen);
    int moda (Imagen& imagen);
    float desvioEstandar(Imagen& imagen);
    int area(Imagen& imagen); //este metodo se relaciona con alg pintor
    //histograma
};

#endif // PROCESADORESTADISTICO_H
