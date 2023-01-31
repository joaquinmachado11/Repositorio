#include "realcedebordes.h"

RealceDeBordes::RealceDeBordes()
{
    kernel3p3 = {5, -1, 0, -1, 0,-1 ,0, -1, 0};
}

RealceDeBordes::~RealceDeBordes()
{

}

void RealceDeBordes::aplicarFiltro(Imagen &pImagen)
{
    Pixel pixelAux;
    Pixel nuevoPixel;
/*
    for (int fila = 0; fila<pImagen.getFilas(); fila++)
    {
        for (int columna = 0; columna<pImagen.getColumnas(); columna++)
        {
            nuevoPixel.definirPixel(0, 0, 0);

            for (int i=0; i<9; i++)
            {
                if (pImagen.estaEnLaImagen(fila+recorrido[i].f, columna+recorrido[i].c))
                {
                    pixelAux = pImagen.getPixel(fila+recorrido[i].f, columna+recorrido[i].c);
                    nuevoPixel += (pixelAux * kernel3p3[i]) ;
                }
            }

            pImagen.setPixel(fila, columna, nuevoPixel);
        }
    }*/

    int auxR=0, auxG=0, auxB=0;
    for (int fila = 0; fila<pImagen.getFilas(); fila++)
    {
        for (int columna = 0; columna<pImagen.getColumnas(); columna++)
        {
            pixelAux = pImagen.getPixel(fila,columna);
             auxR += pixelAux.devolverComponente(0)*5;
             auxG += pixelAux.devolverComponente(1)*5;
             auxB += pixelAux.devolverComponente(2)*5;

            if (pImagen.estaEnLaImagen(fila+1, columna))
            {
                pixelAux = pImagen.getPixel(fila+1,columna);
                 auxR += pixelAux.devolverComponente(0)*(-1);
                 auxG += pixelAux.devolverComponente(1)*(-1);
                 auxB += pixelAux.devolverComponente(2)*(-1);
            }
            if (pImagen.estaEnLaImagen(fila+1, columna+1))
            {
                pixelAux = pImagen.getPixel(fila+1,columna+1);
                 auxR += pixelAux.devolverComponente(0)*0;
                 auxG += pixelAux.devolverComponente(1)*0;
                 auxB += pixelAux.devolverComponente(2)*0;
            }
            if (pImagen.estaEnLaImagen(fila, columna+1))
            {
                pixelAux = pImagen.getPixel(fila,columna+1);
                 auxR += pixelAux.devolverComponente(0)*(-1);
                 auxG += pixelAux.devolverComponente(1)*(-1);
                 auxB += pixelAux.devolverComponente(2)*(-1);
            }
            if (pImagen.estaEnLaImagen(fila-1, columna+1))
            {
                pixelAux = pImagen.getPixel(fila-1,columna+1);
                 auxR += pixelAux.devolverComponente(0)*0;
                 auxG += pixelAux.devolverComponente(1)*0;
                 auxB += pixelAux.devolverComponente(2)*0;
            }
            if (pImagen.estaEnLaImagen(fila-1, columna))
            {
                pixelAux = pImagen.getPixel(fila-1,columna);
                 auxR += pixelAux.devolverComponente(0)*(-1);
                 auxG += pixelAux.devolverComponente(1)*(-1);
                 auxB += pixelAux.devolverComponente(2)*(-1);
            }
            if (pImagen.estaEnLaImagen(fila-1, columna-1))
            {
                pixelAux = pImagen.getPixel(fila-1,columna-1);
                 auxR += pixelAux.devolverComponente(0)*0;
                 auxG += pixelAux.devolverComponente(1)*0;
                 auxB += pixelAux.devolverComponente(2)*0;
            }
            if (pImagen.estaEnLaImagen(fila, columna-1))
            {
                pixelAux = pImagen.getPixel(fila,columna-1);
                 auxR += pixelAux.devolverComponente(0)*(-1);
                 auxG += pixelAux.devolverComponente(1)*(-1);
                 auxB += pixelAux.devolverComponente(2)*(-1);
            }
            if (pImagen.estaEnLaImagen(fila+1, columna-1))
            {
                pixelAux = pImagen.getPixel(fila+1,columna-1);
                 auxR += pixelAux.devolverComponente(0)*0;
                 auxG += pixelAux.devolverComponente(1)*0;
                 auxB += pixelAux.devolverComponente(2)*0;
            }

            pixelAux.definirPixel(auxR, auxG, auxB);
            pImagen.setPixel(fila,columna, pixelAux);
        }
    }

}
