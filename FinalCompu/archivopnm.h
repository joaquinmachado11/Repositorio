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
    void escribirImagen(Imagen& imagen, string pNombreArchivo, string directorio) override;

    const string &getNombreArchivo() const;
    void setNombreArchivo(const string &newNombreArchivo);

private:
    fstream archivo;
    string nombreArchivo;

    void leerTexto(Imagen& pImagen);
    void leerBinario(Imagen& pImagen);

    void escribirP1(Imagen& imagen);
    void escribirP2(Imagen& imagen);
    void escribirP3(Imagen& imagen);
    void escribirP4(Imagen& imagen);
    void escribirP5(Imagen& imagen);
    void escribirP6(Imagen& imagen);

    string definirExtension(string cod);
};

#endif // ARCHIVOPNM_H

//MANEJO DE EXCEPCIONES!!
