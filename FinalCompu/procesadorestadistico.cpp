#include "procesadorestadistico.h"

ProcesadorEstadistico::ProcesadorEstadistico()
{

}

void ProcesadorEstadistico::setPtrImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;
}

Pixel ProcesadorEstadistico::minimo()
{
    int M = ptrImagen->getRangoDinamico();
    Pixel min (M, M, M);
    Pixel pixelAUX;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for(int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAUX = ptrImagen->getPixel(f,c);

            if (pixelAUX.devolverComponente(0) < min.devolverComponente(0))
                min.definirComponente(0, pixelAUX.devolverComponente(0));

            if (pixelAUX.devolverComponente(1) < min.devolverComponente(1))
                min.definirComponente(1, pixelAUX.devolverComponente(1));

            if (pixelAUX.devolverComponente(2) < min.devolverComponente(2))
                min.definirComponente(2, pixelAUX.devolverComponente(2));
        }
    }

    return min;
}

Pixel ProcesadorEstadistico::maximo()
{
    Pixel max (0,0,0);
    Pixel pixelAUX;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for(int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAUX = ptrImagen->getPixel(f,c);

            if (pixelAUX.devolverComponente(0) > max.devolverComponente(0))
                max.definirComponente(0, pixelAUX.devolverComponente(0));

            if (pixelAUX.devolverComponente(1) > max.devolverComponente(1))
                max.definirComponente(1, pixelAUX.devolverComponente(1));

            if (pixelAUX.devolverComponente(2) > max.devolverComponente(2))
                max.definirComponente(2, pixelAUX.devolverComponente(2));
        }
    }

    return max;
}


