#ifndef PIXEL_H
#define PIXEL_H
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Guarda informacion de los pixel de la imagen, permite operaciones entre ellos.
 * @author Machado Joaquin
 */

class Pixel
{
public:
    /**
     * @brief Pixel Metodo constructor vacio de la clase Pixel
     */
    Pixel();

    /**
     * @brief ~Pixel Metodo destructor de la clase Pixel
     */
    ~Pixel();

    /**
     * @brief Pixel Metodo constructor de la clase Pixel
     * @param componente0 Primer componente
     * @param componente1 Segunda componente
     * @param componente2 Tercera componente
     */
    Pixel(int componente0, int componente1, int componente2);

    /**
     * @brief devolverPixel Metodo que devuelve el contenido del atributo pixel
     * @return Vector de enteros con las componentes del pixel
     */
    vector <int> devolverPixel();

    /**
     * @brief definirPixel Metodo que define al pixel
     * @param componente0 Primer componente
     * @param componente1 Segunda componente
     * @param componente2 Tercera componente
     */
    void definirPixel(int componente0, int componente1, int componente2);

    /**
     * @brief devolverComponente Metodo que devuelve una componente del pixel
     * @param componente Componente que se quiere conocer
     * @return Entero que representa la intensidad de la componente elegida
     */
    int devolverComponente (int componente);

    /**
     * @brief definirComponente Metodo que define una componente del pixel
     * @param componente Componente a definir
     * @param valor Intensidad que tendra la componente
     */
    void definirComponente (int componente, int valor);

    /**
     * @brief operator ++ Metodo sobrecarga operador ++, aumenta en 1 la intensidad de todos los componentes del pixel
     * @return Pixel modificado por la operacion
     */
    Pixel& operator++();

    /**
     * @brief operator -- Metodo sobrecarga operador --, disminuye en 1 la intensidad de todos los componentes del pixel
     * @return Pixel modificado por la operacion
     */
    Pixel& operator--();

    /**
     * @brief operator + Metodo que suma las intensidades para cada componente
     * @param Pixel2 Pixel cuyas intensidades de sus componentes se le suman a las del primer pixel
     * @return Retorna un pixel con el resultado de la operacion
     */
    Pixel operator+(Pixel Pixel2);

    /**
     * @brief operator - Metodo que resta las intensidades para cada componente
     * @param Pixel2 Pixel cuyas intensidades de sus componentes se le restan a las del primer pixel
     * @return Retorna un pixel con el resultado de la operacion
     */
    Pixel operator-(Pixel &Pixel2);

    /**
     * @brief operator += Metodo que suma y acumula las intensidades para cada componente
     * @param Pixel2 Pixel cuyas intensidades de sus componentes se le suman a las del primer pixel
     * @return Pixel modficado por la operacion
     */
    Pixel& operator+=(Pixel Pixel2);

    /**
     * @brief operator * Metodo que multiplica las intensidades para cada componente
     * @param factor Factor por el que se multiplicara cada componente
     * @return Pixel modificado por la operacion
     */
    Pixel& operator*(float factor);

    /**
     * @brief operator == Metodo que verifica la igualdad de intensidades para cada componente
     * @param Pixel2 Pixel cuyas intensidades de sus componentes se compararan a las del primer pixel
     * @return Bool que define si los pixeles son iguales o no
     */
    bool operator==(Pixel &Pixel2);

    /**
     * @brief verificarIntensidad Metodo que verifica que el pixel se encuentre dentro del rango dinamico
     * @param M Rango dinamico de la imagen en la que se encuentra el pixel
     */
    void verificarIntensidad (int M);

private:
    /**
     * @brief verificarLimites Metodo que verifica que el pixel tome valores entre 0 y 255
     */
    void verificarLimites();

    vector <int> pixel; /**< Pixel de 3 componentes */
};

#endif // PIXEL_H
