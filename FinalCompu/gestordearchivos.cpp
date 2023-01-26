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
            (throw (string) "No se reconoce el archivo.");
        }
    }

    im = ptrArchivo->leerImagen(getUbicacionArchivo());
    delete ptrArchivo;
    return im;
}

void GestorDeArchivos::guardarImagen(string nombreImagen, Imagen &imagen)
{
    if (imagen.getCodigo() == "P2C")
    {
        ptrArchivo = new ArchivoAIC;
    }
    else
    {
        ptrArchivo = new ArchivoPNM;
    }

    ptrArchivo->escribirImagen(imagen, nombreImagen, ruta + raizGuardado);
    delete ptrArchivo;
}

string GestorDeArchivos::reconocerFormato()
{
    string nombre = getNombreArchivo();
    return nombre.substr(nombre.find_last_of('.'), nombre.size());
}

const string &GestorDeArchivos::getRaizGuardado() const
{
    return raizGuardado;
}

void GestorDeArchivos::setRaizGuardado(const string &newRaizGuardado)
{
    raizGuardado = newRaizGuardado;
}

int GestorDeArchivos::getID() const
{
    return ID;
}

void GestorDeArchivos::setID(int newID)
{
    ID = newID;
}

const string &GestorDeArchivos::getRuta() const
{
    return ruta;
}

void GestorDeArchivos::setRuta(const string &newRuta)
{
    ruta = newRuta;
}

void GestorDeArchivos::mostrarArchivos()
{
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
    generarListadoDeArchivos( ruta + raiz );
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
