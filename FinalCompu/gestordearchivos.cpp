#include "gestordearchivos.h"

GestorDeArchivos::GestorDeArchivos()
{

}

Imagen GestorDeArchivos::generarImagen(int pID)
{
    ID=pID;
    reconocerFormato();
    //archivo->leerImagen(espacioDeTrabajo.getListadoDeArchivos(ID));
}

void GestorDeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

void GestorDeArchivos::reconocerFormato() //lleva control de error
{
    espacioDeTrabajo.getListadoDeArchivos(ID);//devuelve un string
                                              //tomar las ultimas 3 letras y ver que objeto se crea
                                              //crear el archivo correspondiente
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
