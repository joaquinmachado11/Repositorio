#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <vector>
#include <imagen.h>

using namespace std;

/**
 * @brief Clase abstracta que permitira la lectura y escritura de archivos de distinto tipo
 * @author Machado Joaquin
 */

class Archivo
{
public:
    /**
     * @brief Archivo metodo constructor de la clase Archivo
     */
    Archivo();
    /**
     * @brief ~Archivo metodo destructor de la clase archivo
     */
    virtual ~Archivo();
    /**
     * @brief leerImagen metodo virtual que genera una imagen a partir de su direccion
     * @param pNombreArchivo directorio donde se encuentra el archivo
     * @return imagen generada a partir del archivo leido
     */
    virtual Imagen leerImagen(string pNombreArchivo)=0;
    /**
     * @brief escribirImagen metodo virtual que crea un archivo a partir de una imagen
     * @param imagen imagen que contiene los datos a guardar
     * @param pNombreArchivo nombre con el que se guardara la imagen
     * @param directorio directorio donde se guardara la imagen
     */
    virtual void escribirImagen(Imagen& imagen, string pNombreArchivo, string directorio)=0;
};

#endif // ARCHIVO_H
