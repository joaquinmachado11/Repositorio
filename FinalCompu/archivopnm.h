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
    ~ArchivoPNM();
    ArchivoPNM();
    Imagen leerImagen(string nombreArchivo) override;
    void escribirImagen(Imagen& imagen, string nombreArchivo, string directorio) override {};

private:
    fstream archivo;
};

#endif // ARCHIVOPNM_H

//MANEJO DE EXCEPCIONES!!
