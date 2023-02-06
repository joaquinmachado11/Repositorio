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
    Pixel();
    ~Pixel();
    Pixel(int componente0, int componente1, int componente2);
    vector <int> devolverPixel();
    void definirPixel(int componente0, int componente1, int componente2);
    float devolverComponente (int componente);
    void definirComponente (int componente, int valor);

    Pixel& operator++();
    Pixel& operator--();
    Pixel operator+(Pixel Pixel2); //devolver pixel 1 modificado (puntero) o crear un nuevo pixel??
    Pixel operator-(Pixel &Pixel2); // si se crea un nuevo pixel hay q crear un constructor al que se le pase una nueva terna
    Pixel& operator+=(Pixel Pixel2);
    Pixel& operator*(float factor);
    //Pixel& operator*(int factor);
    bool operator==(Pixel &Pixel2);

private:
    void verificarLimites();
    vector <int> pixel;
};

#endif // PIXEL_H

