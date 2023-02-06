#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H
#include <archivo.h>
#include <iostream>
#include <string>
#include <imagen.h>

using namespace std;

/**
 * @brief Permite la lectura y escritura de archivos de tipo PNM
 * @author Machado Joaquin
 */

class ArchivoPNM: public Archivo
{
public:
    /**
     * @brief ArchivoPNM Metodo constructor de la clase ArchivoPNM
     */
    ArchivoPNM();
    /**
     * @brief ~ArchivoPNM Metodo destructor de la clase ArchivoPNM
     */
    ~ArchivoPNM();
    /**
     * @brief leerImagen Metodo que genera una imagen a partir de un archivo tipo PNM
     * @param pNombreArchivo Directorio donde se encuentra el archivo
     * @return Imagen generada a partir del archivo leido
     */
    Imagen leerImagen(string pNombreArchivo) override;
    /**
     * @brief escribirImagen Metodo que crea un archivo a partir de una imagen tipo PNM
     * @param imagen Imagen que contiene los datos a guardar
     * @param pNombreArchivo Nombre con el que se guardara la imagen
     * @param directorio Directorio donde se guardara la imagen
     */
    void escribirImagen(Imagen& imagen, string pNombreArchivo, string directorio) override;

private:
    fstream archivo; /**< Atributo interno que se utilizara para la lectura/escritura de archivos */

    /**
     * @brief leerTexto Metodo que leera un archivo en formato de texto
     * @param pImagen Imagen donde se guardara la informacion del archivo
     */
    void leerTexto(Imagen& pImagen);
    /**
     * @brief leerBinario Metodo que leera un archivo binario
     * @param pImagen Imagen donde se guardara la informacion del archivo
     */
    void leerBinario(Imagen& pImagen);

    /**
     * @brief escribirP1 Metodo que escribira un archivo a partir de una imagen de codigo P1
     * @param imagen Imagen con la informacion a escribir
     */
    void escribirP1(Imagen& imagen);
    /**
     * @brief escribirP2 Metodo que escribira un archivo a partir de una imagen de codigo P2
     * @param imagen Imagen con la informacion a escribir
     */
    void escribirP2(Imagen& imagen);
    /**
     * @brief escribirP3 Metodo que escribira un archivo a partir de una imagen de codigo P3
     * @param imagen Imagen con la informacion a escribir
     */
    void escribirP3(Imagen& imagen);
    /**
     * @brief escribirP4 Metodo que escribira un archivo a partir de una imagen de codigo P4
     * @param imagen Imagen con la informacion a escribir
     */
    void escribirP4(Imagen& imagen);
    /**
     * @brief escribirP5 Metodo que escribira un archivo a partir de una imagen de codigo P5
     * @param imagen Imagen con la informacion a escribir
     */
    void escribirP5(Imagen& imagen);
    /**
     * @brief escribirP6 Metodo que escribira un archivo a partir de una imagen de codigo P6
     * @param imagen Imagen con la informacion a escribir
     */
    void escribirP6(Imagen& imagen);

    /**
     * @brief definirExtension Metodo que genera la extension que tendra la imagen a partir de su codigo
     * @param cod Codigo de la imagen
     * @return String con la extension correspondiente a la imagen
     */
    string definirExtension(string cod);

};

#endif // ARCHIVOPNM_H

//MANEJO DE EXCEPCIONES!!
