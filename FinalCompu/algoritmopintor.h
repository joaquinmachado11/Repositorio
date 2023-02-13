#ifndef ALGORITMOPINTOR_H
#define ALGORITMOPINTOR_H
#include <imagen.h>
#include <cmath>

using namespace std;

/**
 * @brief Detecta pixeles vecinos con intensidad similar, pintandolos y detectando el area que representan en la imagen
 * @author Machado Joaquin
 */

class AlgoritmoPintor
{
public:
    /**
     * @brief AlgoritmoPintor constructor de la clase AlgoritmoPintor
     */
    AlgoritmoPintor();

    /**
     * @brief setImagen Metodo que define el puntero a imagen y define la mascara
     * @param pImagen Imagen a la que se aplicara el algoritmo de pintor
     */
    void setImagen(Imagen *pImagen);

    /**
     * @brief aplicarAlgoritmo metodo que aplica el algoritmo
     * @param posY coordenada Y en la imagen
     * @param posX coordenada X en la imagen
     */
    void aplicarAlgoritmo(int posY, int posX);

    /**
     * @brief detectarArea metodo que detecta el area pintada
     * @param posY coordenada Y en la imagen
     * @param posX coordenada X en la imagen
     */
    void detectarArea(int posY, int posX);

    /**
     * @brief pintarArea metodo recursivo que pinta el area definida por el algoritmo
     */
    void pintarArea();

    /**
     * @brief getAreaDetectada metodo que devuelve la cantidad de pixeles pintados
     * @return Devuelve un entero de 4 bytes que representa la cantidad de pixeles pintados (area)
     */
    int getAreaDetectada() const;

private:
    Imagen *ptrImagen;                  /**< Puntero a imagen a la que se aplicara el algoritmo */
    vector < vector <bool> > mascara;   /**< mascara del tamaño de la imagen que guardara que pixels
                                             se pintaran */
    int filas;                          /**< filas de la imagen */
    int columnas;                       /**< columnas de la imagen */
    int areaDetectada;                  /**< cantidad de pixeles detectados por el algoritmo */
    int profundidad;                    /**< Profundidad de la llamada al metodo recursivo */
    int tolerancia;                     /**< Diferencia maxima de intensidad entre el pixel bajo analisis y sus vecinos */
    Pixel pixelABuscar;                 /**< Pixel seleccionado por el usuario */

    /**
     * @brief dentroDeTolerancia metodo que devuelve si un pixel esta dentro del
     * rango de tolerancia
     * @param pixAComparar pixel que se comparara con el pixel seleccionado por el usuario
     * @return bool que indica si esta dentro del rango de tolerancia o no
     */
    bool dentroDeTolerancia(Pixel &pixAComparar);
};

struct Vecindad
{ int y, x; };
const vector < Vecindad > movimiento=
{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#endif // ALGORITMOPINTOR_H
