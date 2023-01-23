#include "pixel.h"

Pixel::Pixel(float componente0, float componente1, float componente2)
{
    pixel.resize(3);
    definirPixel(componente0,componente1,componente2);
}

Pixel::Pixel()
{
    pixel.resize(3);
}

vector<float> Pixel::devolverPixel()
{
    return pixel;
}

void Pixel::definirPixel(float componente0, float componente1, float componente2)
{
    pixel[0]=componente0;
    pixel[1]=componente1;
    pixel[2]=componente2;
}

float Pixel::devolverComponente(int componente)
{
    return pixel[componente];
}

void Pixel::definirComponente(int componente, float valor)
{
    if (componente<3)
    {
        pixel[componente]=valor;
    }
}

float Pixel::getComponente0()
{
    return pixel[0];
}

float Pixel::getComponente1()
{
    return pixel[1];
}
float Pixel::getComponente2()
{
    return pixel[2];
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
