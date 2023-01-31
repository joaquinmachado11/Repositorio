#include "gestordearchivos.h"

GestorDeArchivos::GestorDeArchivos()
{
    raizGuardado = "Ultima imagen/";
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

vector<Pixel> GestorDeArchivos::generarTablaLUT(int id)
{
    archivoLUT.open(getUbicacionLUT(id), ios::in);

    if (!archivoLUT.is_open())
    {
        cout<<"Error al abrir la LUT."<<endl;
    }
    else
    {
        Pixel pixelAux;
        vector <Pixel> tabla;
        tabla.resize(256);

        string primer_linea;
        int index, red, green, blue;

        getline(archivoLUT, primer_linea);

        for (unsigned int m=0; m<tabla.size(); m++)
        {
            archivoLUT >> index >> red >> green >> blue;
            pixelAux.definirPixel(red, green, blue);
            tabla[index] = pixelAux;
        }

        return tabla;
    }
}

string GestorDeArchivos::reconocerFormato()
{
    string nombre = getNombreArchivo();
    return nombre.substr(nombre.find_last_of('.'), nombre.size());
}

const string &GestorDeArchivos::getRaizLUT() const
{
    return raizLUT;
}

void GestorDeArchivos::setRaizLUT(const string &newRaizLUT)
{
    raizLUT = newRaizLUT;
    generarListadoDeLUTS( rutaLUT + raizLUT );
}

void GestorDeArchivos::almacenarUltimaImagen(Imagen& imagen)
{
    if (imagen.getCodigo() == "P2C")
    {
        ptrArchivo = new ArchivoAIC;
    }
    else
    {
        ptrArchivo = new ArchivoPNM;
    }

    ptrArchivo->escribirImagen(imagen, "ultima_imagen", ruta + raizUltimaImagen);
    delete ptrArchivo;
}

const string &GestorDeArchivos::getRutaLUT() const
{
    return rutaLUT;
}

void GestorDeArchivos::setRutaLUT(const string &newRutaLUT)
{
    rutaLUT = newRutaLUT;
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

void GestorDeArchivos::generarListadoDeLUTS(string rutaDirectorioLUTS)
{
    if (!listadoDeLUTS.empty())
        listadoDeLUTS.clear();

    vector<string> lista_de_luts;
    DIR *dir = opendir(rutaDirectorioLUTS.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                lista_de_luts.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
    listadoDeLUTS = lista_de_luts;
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

string GestorDeArchivos::getUbicacionLUT(int id_lut)
{
    return rutaLUT + raizLUT + getNombreLUT(id_lut);
}

string GestorDeArchivos::getNombreLUT(int id_lut)
{
    return listadoDeLUTS[id_lut];
}

vector<string> &GestorDeArchivos::getListadoDeLUTS()
{
    return listadoDeLUTS;
}

unsigned int GestorDeArchivos::cantidadDeArchivos()
{
    return listadoDeArchivos.size();
}
