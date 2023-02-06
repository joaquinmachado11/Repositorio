#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H
#include <archivo.h>
#include <archivoaic.h>
#include <archivopnm.h>
#include <dirent.h>

/**
 * @brief Conoce listas de archivos, para generar tablas LUT o imagenes.
 * @author Machado Joaquin
 */

class GestorDeArchivos
{
public:
    GestorDeArchivos();

    Imagen generarImagen();
    void guardarImagen(string nombreImagen, Imagen& imagen);

    vector<Pixel> generarTablaLUT(int id);

    int getID() const;
    void setID(int newID);

    const string &getRaiz() const;
    void setRaiz(const string &newRaiz);

    const string &getRaizGuardado() const;
    void setRaizGuardado(const string &newRaizGuardado);

    const string &getRuta() const;
    void setRuta(const string &newRuta);

    void generarListadoDeArchivos(string rutaDirectorio);
    void generarListadoDeLUTS(string rutaDirectorioLUTS);

    string getUbicacionArchivo();
    string getNombreArchivo();
    vector <string> &getListadoDeArchivos();

    unsigned int cantidadDeArchivos();

    string getUbicacionLUT(int id_lut);
    string getNombreLUT(int id_lut);
    vector <string> &getListadoDeLUTS();

    const string &getRutaLUT() const;
    void setRutaLUT(const string &newRutaLUT);

    const string &getRaizLUT() const;
    void setRaizLUT(const string &newRaizLUT);

    Imagen generarUltimaImagen();
    void almacenarUltimaImagen(Imagen& imagen);

    string getNombreUltArchivo();

private:
    string reconocerFormato(string pNombre); //reconoce si es pnm o aic
    string ruta, raiz, raizGuardado, raizUltimaImagen; //info que pasara al espacio de trabajo para pedirle un vector con nombres de archivos
    string rutaLUT, raizLUT;
    Archivo *ptrArchivo;
    fstream archivoLUT;
    int ID;
    vector <string> listadoDeArchivos;
    vector <string> listadoDeLUTS;
};

#endif // GESTORDEARCHIVOS_H
