#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H
#include<imagen.h>
#include <gestordearchivos.h>
#include <cmath>
#include <tuple>

/**
 * @brief Procesa los datos de la imagen para devolver datos estadisticos.
 * @author Machado Joaquin
 */

class ProcesadorEstadistico
{
public:
    /**
     * @brief ProcesadorEstadistico Metodo constructor de la clase ProcesadorEstadistico
     */
    ProcesadorEstadistico();
    /**
     * @brief setPtrImagen Metodo que define el puntero a la imagen que se quiere procesar
     * @param pImagen Imagen que se quiere procesar
     */
    void setPtrImagen(Imagen *pImagen);

    /**
     * @brief promedio Metodo que calcula el promedio de cada componente
     * @return Vector con el promedio de cada componente
     */
    vector<float> promedio();
    /**
     * @brief mediana Metodo que devuelve la mediana en una zona de 3x3 pixeles
     * @param datos vector que contiene los pixeles de una zona
     * @return Pixel con la mediana de cada componente en esa zona
     */
    Pixel mediana(vector <Pixel> datos);

    /**
     * @brief minimo Metodo que calcula el minimo para cada componente de la imagen
     * @return Pixel con los valores minimos de cada componente
     */
    Pixel minimo();
    /**
     * @brief maximo Metodo que calcula el maximo para cada componente de la imagen
     * @return Pixel con los valores maximos de cada componente
     */
    Pixel maximo();

    /**
     * @brief modaGrises Metodo que obtiene la moda de imagenes monocromaticas y/o de intensidad
     * @param datosDeFrecuencia vector con la frecuencia de las distintas intensidades
     */
    void modaGrises(vector <int> &datosDeFrecuencia);
    /**
     * @brief modaRGB Metodo que obtiene la moda de imagenes RGB
     * @param datosDeFrecuencia matriz con la frecuencia de las distintas intensidades de cada componente
     */
    void modaRGB(vector <vector <int>> &datosDeFrecuencia);

    /**
     * @brief desvioEstandar Metodo que calcula el desvio estandar de los pixeles en la imagen
     * @return vector con el desvio estandar para cada componente
     */
    vector <float> desvioEstandar();

    /**
     * @brief obtenerDatosPixelesRGB Metodo que procesa la frecuencia de los valores RGB en la imagen
     * @return matriz con la frecuencia de las distintas intensidades de cada componente
     */
    vector <vector <int>> obtenerDatosPixelesRGB(); //cambiar nombre a algo relacionado con frecuencia
    /**
     * @brief obtenerDatosPixelesMonocGrises Metodo que procesa la frecuencia de las distintas intensidades de la imagen
     * @return vector con la frecuencia de las distintas intensidades
     */
    vector <int> obtenerDatosPixelesMonocGrises();

    /**
     * @brief getMayorFrecuencia Metodo que devuelve la mayor frecuencia observada en la imagen
     * @return Devuelve un entero de 4 bytes que representa la mayor frecuencia en una imagen
     */
    int getMayorFrecuencia() const;

private:
    Imagen *ptrImagen; /**< Puntero a objeto imagen, la cual se quiere procesar */
    int mayorFrecuencia; /**< Mayor frecuencia observada en la imagen */


};

#endif // PROCESADORESTADISTICO_H
