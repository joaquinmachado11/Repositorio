#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H
#include <archivo.h>
#include <iostream>
#include <string>
#include <imagen.h>

using namespace std;

class ArchivoAIC: public Archivo
{
public:
    ~ArchivoAIC();
    ArchivoAIC();
    Imagen leerImagen(string nombreArchivo) override {};
    void escribirImagen(Imagen& imagen, string nombreArchivo, string directorio) override {};

private:
    fstream archivo;
};

#endif // ARCHIVOAIC_H

//MANEJO DE EXCEPCIONES!!
