#include "pixel.h"

Pixel::Pixel(float primerValor, float segundoValor, float tercerValor)
{
    pixel.resize(3);
    definirPixel(primerValor,segundoValor,tercerValor);
}

Pixel::Pixel()
{
    pixel.resize(3);
}

vector<float> Pixel::devolverPixel()
{
    return pixel;
}

void Pixel::definirPixel(float primerValor, float segundoValor, float tercerValor)
{
    pixel[0]=primerValor;
    pixel[1]=segundoValor;
    pixel[2]=tercerValor;
}

float Pixel::devolverComponente(int componente)
{
    return pixel[componente];
}

void Pixel::definirComponente(int i, int valor)
{
    if (i<3)
    {
        pixel[i]=valor;
    }
}

Pixel &Pixel::operator++()
{
    pixel[0]++;
    pixel[1]++;
    pixel[2]++;
    return *this;
}

Pixel &Pixel::operator --()
{
    pixel[0]--;
    pixel[1]--;
    pixel[2]--;
    return *this;
}

Pixel Pixel::operator+(Pixel &Pixel2)
{
    pixel[0]=pixel[0]+ Pixel2.devolverComponente(0);
    pixel[1]=pixel[1]+ Pixel2.devolverComponente(1);
    pixel[2]=pixel[2]+ Pixel2.devolverComponente(2);
    return *this;

    /*
    return Pixel(pixel[0]+ Pixel2.devolverPixel()[0],
                 pixel[1]+ Pixel2.devolverPixel()[1],
                 pixel[2]+ Pixel2.devolverPixel()[2])
    */
}

Pixel Pixel::operator-(Pixel &Pixel2)
{
    pixel[0]=pixel[0] - Pixel2.devolverComponente(0);
    pixel[1]=pixel[1] - Pixel2.devolverComponente(1);
    pixel[2]=pixel[2] - Pixel2.devolverComponente(2);
    return *this;
}

bool Pixel::operator ==(Pixel &Pixel2)
{   return (pixel[0]==Pixel2.devolverComponente(0) and
            pixel[1]==Pixel2.devolverComponente(1) and
            pixel[2]==Pixel2.devolverComponente(2));
}
