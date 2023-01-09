#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H
#include <archivo.h>
#include <iostream>
#include <string>
#include <imagen.h>

using namespace std;

class ArchivoPNM: public Archivo
{
public:
    ArchivoPNM();
    Imagen cargarImagen(string nombreArchivo);
    void guardarImagen(Imagen &imagen, string nombreArchivo, string directorio){};

private:
    fstream archivo;
};

#endif // ARCHIVOPNM_H

//MANEJO DE EXCEPCIONES!!