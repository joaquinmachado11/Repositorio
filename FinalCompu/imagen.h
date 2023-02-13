#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <iostream>
#include <pixel.h>

using namespace std;

/**
 * @brief Guarda la informacion a graficar.
 * @author Machado Joaquin
 */

class Imagen
{
public:
    /**
     * @brief Imagen Metodo constructor de imagen
     */
    Imagen();

    /**
     * @brief ~Imagen Metodo destructor de imagen
     */
    ~Imagen();

    /**
     * @brief getFilas Metodo que devuelve la cantidad de filas (alto) de la imagen
     * @return Devuelve un entero de 4 bytes que representa la cantidad de filas
     */
    int getFilas() const;
    /**
     * @brief setFilas Metodo que define la cantidad de filas que tendra la imagen
     * @param newFilas Filas de la imagen
     */
    void setFilas(int newFilas);

    /**
     * @brief getColumnas Metodo que devuelve la cantidad de columnas (ancho) de la imagen
     * @return Devuelve un entero de 4 bytes que representa la cantidad de columnas
     */
    int getColumnas() const;
    /**
     * @brief setColumnas Metodo que define la cantidad de columnas que tendra la imagen
     * @param newColumnas Columnas de la imagen
     */
    void setColumnas(int newColumnas);

    /**
     * @brief getRangoDinamico Metodo que devuelve elrango dinamico de la imagen
     * @return Devuelve un entero de 4 bytes que representa el rango dinamico de la imagen
     */
    int getRangoDinamico() const;
    /**
     * @brief setRangoDinamico Metodo que define el rango dinamico de la imagen
     * @param newRangoDinamico Rango dinamico de la imagen
     */
    void setRangoDinamico(int newRangoDinamico);

    /**
     * @brief dimensionar Metodo que dimensiona la imagen con el tamaño de sus filas y columnas
     */
    void dimensionar();

    /**
     * @brief estaEnLaImagen Metodo que devuelve si una posicion esta en la imagen
     * @param f Fila a chequear
     * @param c Columna a chequear
     * @return Retorna un booleano que indica si se encuentra o no dentro de la imagen
     */
    bool estaEnLaImagen(int f, int c);

    /**
     * @brief getPixel Metodo que devuelve un pixel de la imagen
     * @param fila Fila donde esta el pixel
     * @param columna Columna donde esta el pixel
     * @return Pixel de la fila y columna seleccionada
     */
    Pixel getPixel(int fila, int columna); //ver si esta bien escrito
    /**
     * @brief setPixel Metodo que define un nuevo pixel en la imagen
     * @param fila Fila donde ira el nuevo pixel
     * @param columna Columna donde ira el nuevo pixel
     * @param pixel Nuevo pixel
     */
    void setPixel (int fila, int columna, Pixel pixel);

    /**
     * @brief getCodigo Metodo que devuelve el codigo de la imagen
     * @return String con el codigo de la imagen
     */
    const string &getCodigo() const;
    /**
     * @brief setCodigo Metodo que define el codigo de la imagen
     * @param newCodigo String con el codigo de la imagen
     */
    void setCodigo(const string &newCodigo);

    /**
     * @brief setDescripcion Metodo que define la descripcion de la imagen
     * @param newDescripcion string con la descripcion de la imagen
     */
    void setDescripcion(const string &newDescripcion);
    /**
     * @brief getDescripcion Metodo que devuelve la descripcion de la imagen
     * @return String con la descripcion de la imagen
     */
    const string &getDescripcion() const;

    /**
     * @brief definirCodigoDeGuardado Metodo que define un nuevo codigo a la imagen segun la forma con la que se quiera guardar
     * @param opcion Forma en la que se quiere guardar la imagen
     */
    void definirCodigoDeGuardado(int opcion);

    /**
     * @brief getExtension Metodo que define la extension de la imagen segun su codigo
     * @return String con la extension correspondiente al codigo
     */
    string getExtension();

    /**
     * @brief estaCorrupta Metodo que define la imagen como corrupta
     */
    void estaCorrupta();

    /**
     * @brief esCorrupta Metodo que devuelve si la imagen es o no corrupta
     * @return Bool que define si la imagen es corrupta
     */
    bool esCorrupta();

private:
    vector < vector < Pixel >> imagen; /**< Matriz del tamaño de la imagen que aloja los pixeles */
    int filas; /**< Filas de la imagen */
    int columnas; /**< Columnas de la imagen */
    int rangoDinamico; /**< Rango dinamico de la imagen */
    string descripcion; /**< Descripcion de la imagen */
    string codigo; /**< Codigo de la imagen */
    bool corrupta;  /**< Bool que define si la imagen es corrupta */
};

#endif // IMAGEN_H
