#ifndef PIXEL_H
#define PIXEL_H
#include <vector>
#include <iostream>

using namespace std;

class Pixel
{
public:
    Pixel();
    Pixel(float, float, float);
    vector <float> devolverPixel();
    void definirPixel(float, float, float);
    float devolverComponente (int componente);
    void definirComponente (int i, int valor);

    Pixel& operator++();
    Pixel& operator--();
    Pixel operator+(Pixel &Pixel2); //devolver pixel 1 modificado (puntero) o crear un nuevo pixel??
    Pixel operator-(Pixel &Pixel2); // si se crea un nuevo pixel hay q crear un constructor al que se le pase una nueva terna
    bool operator==(Pixel &Pixel2);

private:
    vector <float> pixel;
};

#endif // PIXEL_H

