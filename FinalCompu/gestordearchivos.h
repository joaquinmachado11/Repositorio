#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <archivo.h>
#include <archivoaic.h>
#include <archivopnm.h>
#include <dirent.h>

class GestorDeArchivos
{
public:
    GestorDeArchivos();

    Imagen generarImagen();
    void guardarImagen(string nombreImagen, Imagen& imagen);

    int getID() const;
    void setID(int newID);

    const string &getRaiz() const;
    void setRaiz(const string &newRaiz);

    const string &getRaizGuardado() const;
    void setRaizGuardado(const string &newRaizGuardado);

    const string &getRuta() const;
    void setRuta(const string &newRuta);

    void generarListadoDeArchivos(string rutaDirectorio);

    string getUbicacionArchivo();
    string getNombreArchivo();
    vector <string> &getListadoDeArchivos();

    unsigned int cantidadDeArchivos();
    void mostrarArchivos();

private:
    string reconocerFormato();                      //reconoce si es pnm o aic
    string ruta, raiz, raizGuardado;                  //info que pasara al espacio de trabajo para pedirle un vector con nombres de archivos
    Archivo *ptrArchivo;
    int ID;
    vector <string> listadoDeArchivos;
};

#endif // GESTORDEARCHIVOS_H
