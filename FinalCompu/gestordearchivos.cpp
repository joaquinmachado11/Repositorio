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

    im = ptrArchivo->leerImagen(getArchivo(ID));
    delete ptrArchivo;
    return im;
}

void GestorDeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

string GestorDeArchivos::reconocerFormato()
{
    string nombre = getArchivo(ID);
    return nombre.substr(nombre.find_last_of('.'), nombre.size());
}

const string &GestorDeArchivos::getRuta() const
{
    return ruta;
}

void GestorDeArchivos::setRuta(const string &newRuta)
{
    ruta = newRuta;
    //listadoDeArchivos = espacioDeTrabajo.generarListadoDeArchivos(ruta + raiz);
}

void GestorDeArchivos::mostrarArchivos()
{
    vector <string> lista = espacioDeTrabajo.generarListadoDeArchivos(ruta+raiz);
    cout<<"Cantidad total de archivos: "<<lista.size()<<endl;
    for (unsigned int i=0; i<lista.size(); i++)
    {
        cout<<"Archivo "<<i+1<<": ";
        cout<<lista[i]<<endl;
    }
}

const string &GestorDeArchivos::getRaiz() const
{
    return raiz;
}

void GestorDeArchivos::setRaiz(const string &newRaiz)
{
    raiz = newRaiz;
    //listadoDeArchivos=espacioDeTrabajo.generarListadoDeArchivos(ruta + raiz);
}

string GestorDeArchivos::getArchivo(int id)
{
    return listadoDeArchivos[id];
}

vector <string> GestorDeArchivos::getListadoDeArchivos()
{
    return listadoDeArchivos;
}

unsigned int GestorDeArchivos::cantidadDeArchivos()
{
    return listadoDeArchivos.size();
}
