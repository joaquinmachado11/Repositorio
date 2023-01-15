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
    Imagen leerImagen(string pNombreArchivo) override;
    void escribirImagen(Imagen& imagen, string pNombreArchivo, string directorio) override {};

    const string &getNombreArchivo() const;
    void setNombreArchivo(const string &newNombreArchivo);

private:
    fstream archivo;
    string nombreArchivo;

    void leerTexto(Imagen& pImagen);
    void leerBinario(Imagen& pImagen);
};

#endif // ARCHIVOPNM_H

//MANEJO DE EXCEPCIONES!!
