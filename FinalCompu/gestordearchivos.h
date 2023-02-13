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
    /**
     * @brief GestorDeArchivos Metodo constructor de la clase GestorDeArchivos
     */
    GestorDeArchivos();

    /**
     * @brief generarImagen Metodo que genera una imagen
     * @return Objeto imagen
     */
    Imagen generarImagen();

    /**
     * @brief guardarImagen Metodo que guarda como archivo una imagen
     * @param nombreImagen Nombre con el que se guardara el archivo
     * @param imagen Imagen a guardar
     */
    void guardarImagen(string nombreImagen, Imagen& imagen);

    /**
     * @brief generarTablaLUT Metodo que genera una tabla LUT
     * @param id ID de la tabla LUT que se quiere obtener
     * @return Vector de pixeles RGB para cada intensidad
     */
    vector<Pixel> generarTablaLUT(int id);

    /**
     * @brief getID Metodo que devuelve el ID de la ultima imagen generada
     * @return ID de la imagen
     */
    int getID() const;
    /**
     * @brief setID Metodo que define el ID de la imagen generada
     * @param newID Nuevo ID  de la imagen generada
     */
    void setID(int newID);

    /**
     * @brief getRaiz Metodo que devuelve la raiz donde se encuentran los archivos de imagen
     * @return String con la raiz donde se encuentran los archivos de imagen
     */
    const string &getRaiz() const;
    /**
     * @brief setRaiz Metodo que define la raiz donde se encuentran los archivos de imagen
     * @param newRaiz String con raiz donde se encuentran los archivos de imagen
     */
    void setRaiz(const string &newRaiz);

    /**
     * @brief getRaizGuardado Metodo que devuelve la raiz donde se guardaran los archivos de imagen
     * @return String con la raiz donde se guardaran los archivos de imagen
     */
    const string &getRaizGuardado() const;
    /**
     * @brief setRaizGuardado Metodo que define la raiz donde se guardaran los archivos de imagen
     * @param newRaizGuardado String con raiz donde se guardaran los archivos de imagen
     */
    void setRaizGuardado(const string &newRaizGuardado);

    /**
     * @brief getRuta Metodo que devuelve la ruta a la carpeta donde estan los archivos de imagen
     * @return String con la ruta a la carpeta
     */
    const string &getRuta() const;
    /**
     * @brief setRuta Metodo que define la ruta a la carpeta donde se encuentran los archivos de imagen
     * @param newRuta String con la ruta a la carpeta
     */
    void setRuta(const string &newRuta);

    /**
     * @brief generarListadoDeArchivos Metodo que define listadoDeArchivos con los nombres de los archivos de imagen
     * @param rutaDirectorio Directorio donde se encuentran los archivos de imagen
     */
    void generarListadoDeArchivos(string rutaDirectorio);

    /**
     * @brief generarListadoDeLUTS Metodo que define listadoDeLUTS con los nombres de archivos lut
     * @param rutaDirectorioLUTS Directorio donde se encuentran los archivos lut
     */
    void generarListadoDeLUTS(string rutaDirectorioLUTS);

    /**
     * @brief getUbicacionArchivo Metodo que devuelve el directorio completo donde se encuentra el archivo de imagen
     * @return String de directorio donde se encuentra el archivo de imagen
     */
    string getUbicacionArchivo();

    /**
     * @brief getNombreArchivo Metodo que devuelve el nombre de un archivo de imagen
     * @return String con el nombre de archivo de imagen
     */
    string getNombreArchivo();

    /**
     * @brief getListadoDeArchivos Metodo que devuelve el contenido del atributo listadoDeArchivos
     * @return Vector de string con el nombre de archivos de imagen
     */
    vector <string> &getListadoDeArchivos();

    /**
     * @brief cantidadDeArchivos Metodo que devuelve la cantidad de archivos en el directorio
     * @return Entero sin signo que representa la cantidad de archivos de imagen
     */
    unsigned int cantidadDeArchivos();

    /**
     * @brief getUbicacionLUT Metodo que devuelve el directorio completo donde se encuentra el archivo de lut
     * @param id_lut ID de la lut que se quiere obtener la direccion
     * @return String con la ubicacion de la lut
     */
    string getUbicacionLUT(int id_lut);

    /**
     * @brief getNombreLUT Metodo que devuelve el nombre de la lut
     * @param id_lut ID de la lut
     * @return String con el nombre de la lut
     */
    string getNombreLUT(int id_lut);

    /**
     * @brief getListadoDeLUTS Metodo que devuelve el contenido del atributo listadoDeLUTS
     * @return Vector de strings con el nombre de los archivos lut
     */
    vector <string> &getListadoDeLUTS();

    /**
     * @brief getRutaLUT Metodo que devuelve la ruta a la carpeta donde estan los archivos de lut
     * @return String con la ruta a la carpeta
     */
    const string &getRutaLUT() const;
    /**
     * @brief setRutaLUT Metodo que define la ruta a la carpeta donde se encuentran los archivos de lut
     * @param newRutaLUT String con la ruta a la carpeta
     */
    void setRutaLUT(const string &newRutaLUT);

    /**
     * @brief getRaizLUT Metodo que devuelve la raiz donde se encuentran los archivos lut
     * @return String con la raiz donde se encuentran los archivos lut
     */
    const string &getRaizLUT() const;
    /**
     * @brief setRaizLUT Metodo que define la raiz donde se encuentran los archivos lut
     * @param newRaizLUT String con raiz donde se encuentran los archivos lut
     */
    void setRaizLUT(const string &newRaizLUT);

    /**
     * @brief generarUltimaImagen Metodo que genera la ultima imagen abierta en la ejecucion anterior del programa
     * @return Objeto imagen
     */
    Imagen generarUltimaImagen();

    /**
     * @brief almacenarUltimaImagen Metodo que genera un archivo de imagen luego de cerrar la ventana que muestra la imagen
     * @param imagen Imagen a guardar
     */
    void almacenarUltimaImagen(Imagen& imagen);

    /**
     * @brief getNombreUltArchivo Devuelve el nombre del ultimo archivo abierto en el programa
     * @return String con el nombre del ultimo archivo abierto
     */
    string getNombreUltArchivo();

private:
    /**
     * @brief reconocerFormato Metodo que reconoce la extension de un archivo
     * @param pNombre Nombre del archivo
     * @return String con el formato reconocido
     */
    string reconocerFormato(string pNombre);

    string ruta; /**< Ruta */
    string raiz; /**< Raiz */
    string raizGuardado; /**< Raiz de guardado */
    string raizUltimaImagen; /**< Raiz de la ultima imagen */
    string rutaLUT; /**< Ruta de LUT */
    string raizLUT; /**< Raiz de LUT */
    Archivo *ptrArchivo; /**< Puntero a archivo */
    fstream archivoLUT; /**< Atributo para manejar archivos */
    int ID; /**< ID del archivo */
    vector <string> listadoDeArchivos; /**< Listado de nombres de archivos de imagen */
    vector <string> listadoDeLUTS; /**< Listado de nombres de archivos de lut */
};

#endif // GESTORDEARCHIVOS_H
