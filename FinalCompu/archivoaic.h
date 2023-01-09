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
    ArchivoAIC();
    Imagen cargarImagen(string nombreArchivo){};
    void guardarImagen(Imagen &imagen, string nombreArchivo, string directorio){};

private:
    fstream archivo;
};

#endif // ARCHIVOAIC_H

//MANEJO DE EXCEPCIONES!!
