#ifndef PIXEL_H
#define PIXEL_H
#include <vector>
#include <iostream>

using namespace std;

class Pixel
{
public:
    Pixel();
    Pixel(int componente0, int componente1, int componente2);
    vector <int> devolverPixel();
    void definirPixel(int componente0, int componente1, int componente2);
    float devolverComponente (int componente);
    void definirComponente (int componente, int valor);

    int getComponente0();
    int getComponente1();
    int getComponente2();

    Pixel& operator++();
    Pixel& operator--();
    Pixel operator+(Pixel &Pixel2); //devolver pixel 1 modificado (puntero) o crear un nuevo pixel??
    Pixel operator-(Pixel &Pixel2); // si se crea un nuevo pixel hay q crear un constructor al que se le pase una nueva terna
    bool operator==(Pixel &Pixel2);

private:
    vector <int> pixel;
};

#endif // PIXEL_H

