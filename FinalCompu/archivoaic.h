#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H
#include <archivo.h>
#include <iostream>
#include <string>
#include <imagen.h>
#include <procesadorestadistico.h>

using namespace std;

/**
 * @brief Permite la lectura y escritura de archivos de tipo AIC
 * @author Machado Joaquin
 */

class ArchivoAIC: public Archivo
{
public:
    /**
     * @brief ArchivoAIC Metodo constructor de la clase ArchivoAIC
     */
    ArchivoAIC();

    /**
     * @brief ~ArchivoAIC Metodo destructor de la clase ArchivoAIC
     */
    ~ArchivoAIC();

    /**
     * @brief leerImagen Metodo que genera una imagen a partir de un archivo tipo AIC
     * @param pNombreArchivo Directorio donde se encuentra el archivo
     * @return imagen generada a partir del archivo leido
     */
    Imagen leerImagen(string pNombreArchivo) override ;

    /**
     * @brief escribirImagen Metodo que crea un archivo a partir de una imagen tipo AIC
     * @param imagen Imagen que contiene los datos a guardar
     * @param pNombreArchivo Nombre con el que se guardara la imagen
     * @param directorio Directorio donde se guardara la imagen
     */
    void escribirImagen(Imagen& imagen, string pNombreArchivo, string directorio) override;

private:
    fstream archivo; /**< Atributo interno que se utilizara para la lectura/escritura de archivos */
};

#endif // ARCHIVOAIC_H
