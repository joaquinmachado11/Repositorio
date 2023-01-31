#include "suavizado.h"

Suavizado::Suavizado()
{
    kernel3p3.resize(9, (float)1/9);
}

Suavizado::~Suavizado()
{

}

void Suavizado::aplicarFiltro(Imagen &pImagen)
{
    Pixel pixelAux;
    Pixel nuevoPixel;

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
    }
}

