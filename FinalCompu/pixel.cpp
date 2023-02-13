#include "pixel.h"

Pixel::Pixel(int componente0, int componente1, int componente2)
{
    pixel.resize(3);

    definirPixel(componente0,componente1,componente2);
}

Pixel::~Pixel()
{

}

Pixel::Pixel()
{
    pixel.resize(3);
}

vector<int> Pixel::devolverPixel()
{
    return pixel;
}

void Pixel::definirPixel(int componente0, int componente1, int componente2)
{
    pixel[0] = componente0;
    pixel[1] = componente1;
    pixel[2] = componente2;

    verificarLimites();
}

int Pixel::devolverComponente(int componente)
{
    return pixel[componente];
}

void Pixel::definirComponente(int componente, int valor)
{
    pixel[componente] = valor;

    verificarLimites();
}

Pixel &Pixel::operator++()
{
    pixel[0]++;
    pixel[1]++;
    pixel[2]++;

    verificarLimites();

    return *this;
}

Pixel &Pixel::operator--()
{
    pixel[0]--;
    pixel[1]--;
    pixel[2]--;

    verificarLimites();

    return *this;
}

Pixel Pixel::operator+(Pixel Pixel2)
{
    Pixel aux(pixel[0]+ Pixel2.devolverPixel()[0],
            pixel[1]+ Pixel2.devolverPixel()[1],
            pixel[2]+ Pixel2.devolverPixel()[2]);

    aux.verificarLimites();

    return aux;

}

Pixel Pixel::operator-(Pixel &Pixel2)
{
    Pixel aux(pixel[0] - Pixel2.devolverPixel()[0],
            pixel[1] - Pixel2.devolverPixel()[1],
            pixel[2] - Pixel2.devolverPixel()[2]);

    aux.verificarLimites();

    return aux;
}

Pixel &Pixel::operator+=(Pixel Pixel2)
{
    pixel[0] = pixel[0] + Pixel2.devolverComponente(0);
    pixel[1] = pixel[1] + Pixel2.devolverComponente(1);
    pixel[2] = pixel[2] + Pixel2.devolverComponente(2);

    verificarLimites();

    return *this;
}

Pixel& Pixel::operator*(float factor)
{
    pixel[0] = pixel[0] * factor;
    pixel[1] = pixel[1] * factor;
    pixel[2] = pixel[2] * factor;

    verificarLimites();

    return *this;
}

bool Pixel::operator ==(Pixel &Pixel2)
{   return (pixel[0]==Pixel2.devolverComponente(0) and
            pixel[1]==Pixel2.devolverComponente(1) and
            pixel[2]==Pixel2.devolverComponente(2));
}

void Pixel::verificarIntensidad(int M)
{
    if (pixel[0] > M)
        pixel[0] = M;
    if (pixel[1] > M)
        pixel[1] = M;
    if (pixel[2] > M)
        pixel[2] = M;

    if (pixel[0] < 0)
        pixel[0] = 0;
    if (pixel[1] < 0)
        pixel[1] = 0;
    if (pixel[2] < 0)
        pixel[2] = 0;
}

void Pixel::verificarLimites()
{
    if (pixel[0] > 255)
        pixel[0] = 255;
    if (pixel[1] > 255)
        pixel[1] = 255;
    if (pixel[2] > 255)
        pixel[2] = 255;

    if (pixel[0] < 0)
        pixel[0] = 0;
    if (pixel[1] < 0)
        pixel[1] = 0;
    if (pixel[2] < 0)
        pixel[2] = 0;
}
