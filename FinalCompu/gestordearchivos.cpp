#include "gestordearchivos.h"

GestorDeArchivos::GestorDeArchivos()
{

}

Imagen GestorDeArchivos::generarImagen(int pID)
{
    ID=pID;
    Imagen im;
    string extension = reconocerFormato();

    if (extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm")
    {
        ptrArchivo = new ArchivoPNM;
    }
    else
    {
        if (extension == ".aic")
        {
            ptrArchivo = new ArchivoAIC;
        }
        else
        {
            (throw (string) "No se reconoce el archivo. ");
        }
    }

    im = ptrArchivo->leerImagen(espacioDeTrabajo.getListadoDeArchivos(ID));
    delete ptrArchivo;
    return im;
}

void GestorDeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

string GestorDeArchivos::reconocerFormato()
{
    string nombre = espacioDeTrabajo.getListadoDeArchivos(ID);
    return nombre.substr(nombre.find_last_of('.'), nombre.size());
}

const string &GestorDeArchivos::getRuta() const
{
    return ruta;
}

void GestorDeArchivos::setRuta(const string &newRuta)
{
    ruta = newRuta;
}

const string &GestorDeArchivos::getRaiz() const
{
    return raiz;
}

void GestorDeArchivos::setRaiz(const string &newRaiz)
{
    raiz = newRaiz;
}
