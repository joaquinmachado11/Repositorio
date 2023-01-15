#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <vector>
#include <imagen.h>

using namespace std;

class Archivo
{
public:
    virtual ~Archivo();
    Archivo();
    virtual Imagen leerImagen(string pNombreArchivo)=0;
    virtual void escribirImagen(Imagen& imagen, string pNombreArchivo, string directorio)=0;
};

#endif // ARCHIVO_H
