#include "gestordearchivos.h"

GestorDeArchivos::GestorDeArchivos()
{

}

Imagen GestorDeArchivos::generarImagen()
{
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

    im = ptrArchivo->leerImagen(getUbicacionArchivo());
    delete ptrArchivo;
    return im;
}

void GestorDeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{

}

string GestorDeArchivos::reconocerFormato()
{
    string nombre = getNombreArchivo();
    return nombre.substr(nombre.find_last_of('.'), nombre.size());
}

int GestorDeArchivos::getID() const
{
    return ID;
}

void GestorDeArchivos::setID(int newID)
{
    ID = newID-1;
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
    generarListadoDeArchivos(ruta + raiz); //o raiz + ruta
    cout<<"Cantidad total de archivos: "<<listadoDeArchivos.size()<<endl;
    for (unsigned int i=0; i<listadoDeArchivos.size(); i++)
    {
        cout<<"Archivo "<<i+1<<": ";
        cout<<listadoDeArchivos[i]<<endl;
    }
}

void GestorDeArchivos::generarListadoDeArchivos(string rutaDirectorio)
{
    if (!listadoDeArchivos.empty())
        listadoDeArchivos.clear();

    vector<string> lista_de_archivos;
    DIR *dir = opendir(rutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                lista_de_archivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
    listadoDeArchivos = lista_de_archivos;
}

void GestorDeArchivos::setListaArch(string pRuta)
{
    generarListadoDeArchivos(pRuta);
    vector<string> Lista = listadoDeArchivos;
    string extension;
    string nombre;

    for(unsigned int i=0 ; i<Lista.size() ; i++)
    {
        nombre = Lista[i];
        extension = nombre.substr(nombre.find_last_of('.'), nombre.size());
        if(extension == ".pbm" or  extension == ".pgm" or  extension == ".ppm" or  extension == ".pnm" or extension == ".aic")
        {
            listadoDeArchivos.push_back(nombre);
        }
    }
}

string GestorDeArchivos::getUbicacionArchivo()
{
    return ruta + raiz + getNombreArchivo();
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

string GestorDeArchivos::getNombreArchivo()
{
    return listadoDeArchivos[ID];
}

vector<string> &GestorDeArchivos::getListadoDeArchivos()
{
    return listadoDeArchivos;
}

unsigned int GestorDeArchivos::cantidadDeArchivos()
{
    return listadoDeArchivos.size();
}
