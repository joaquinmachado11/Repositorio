#include "gestordearchivos.h"

GestorDeArchivos::GestorDeArchivos()
{

}

Imagen GestorDeArchivos::generarImagen(int pID)
{
    ID=pID-1;
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

    im = ptrArchivo->leerImagen(espacioDeTrabajo.getArchivo(ID));
    delete ptrArchivo;
    return im;
}

void GestorDeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

string GestorDeArchivos::reconocerFormato()
{
    string nombre = espacioDeTrabajo.getArchivo(ID);
    return nombre.substr(nombre.find_last_of('.'), nombre.size());
}

const string &GestorDeArchivos::getRuta() const
{
    return ruta;
}

void GestorDeArchivos::setRuta(const string &newRuta)
{
    ruta = newRuta;
    espacioDeTrabajo.setListadoDeArchivos(raiz + ruta);
}

void GestorDeArchivos::mostrarArchivos()
{
    for (unsigned int i=0; i<espacioDeTrabajo.getListadoDeArchivos().size(); i++)
    {
        cout<<"Archivo "<<i+1<<": ";
        cout<<espacioDeTrabajo.getArchivo(i)<<endl;
    }
}

const string &GestorDeArchivos::getRaiz() const
{
    return raiz;
}

void GestorDeArchivos::setRaiz(const string &newRaiz)
{
    raiz = newRaiz;
    //espacioDeTrabajo.setListadoDeArchivos(raiz + ruta);
}
