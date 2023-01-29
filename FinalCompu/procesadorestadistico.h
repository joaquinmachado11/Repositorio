#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H
#include<imagen.h>
#include <gestordearchivos.h>
#include <cmath>
#include <tuple>

class ProcesadorEstadistico
{
public:
    ProcesadorEstadistico();
    void setPtrImagen(Imagen *pImagen);

    vector<float> promedio();

    Pixel minimo();
    Pixel maximo();

    void modaGrises(vector <int> &datosDeFrecuencia);
    void modaRGB(vector <vector <int>> &datosDeFrecuencia); //valor dentro del conjunto de datos que más se repite, el que tiene mayor frecuencia.

    vector <float> desvioEstandar();

    vector <vector <int>> obtenerDatosPixelesRGB(); //cambiar nombre a algo relacionado con frecuencia
    vector <int> obtenerDatosPixelesMonocGrises();

    int getMayorFrecuencia() const;

private:
    Imagen *ptrImagen;
    int mayorFrecuencia;


};

#endif // PROCESADORESTADISTICO_H
