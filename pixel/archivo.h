#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <vector>
#include <imagen.h>

using namespace std;

class Archivo
{
public:
    Archivo();
    virtual Imagen cargarImagen(string nombreArchivo)=0;
    virtual void guardarImagen(Imagen &imagen, string nombreArchivo, string directorio)=0;
};

#endif // ARCHIVO_H
