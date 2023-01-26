#include "editor.h"

Editor::Editor()
{

}

void Editor::setImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;
}

void Editor::aumentarBrillo()
{
    Pixel pixelAux;
    int M = ptrImagen->getRangoDinamico();

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for(int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f, c);
            ++pixelAux;

            if (pixelAux.devolverComponente(0)<=M and
                pixelAux.devolverComponente(1)<=M and
                pixelAux.devolverComponente(2)<=M)
            {
                ptrImagen->setPixel(f, c, pixelAux);
            }
        }
    }
}

void Editor::disminuirBrillo()
{
    Pixel pixelAux;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for(int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f, c);
            --pixelAux;

            if (pixelAux.devolverComponente(0)>=0 and
                pixelAux.devolverComponente(1)>=0 and
                pixelAux.devolverComponente(2)>=0)
            {
                ptrImagen->setPixel(f, c, pixelAux);
            }
        }
    }
}

void Editor::aumentarContraste()
{
    procesadorEstadistico.setPtrImagen(ptrImagen);
    int M = ptrImagen->getRangoDinamico();
    Pixel max = procesadorEstadistico.maximo();
    Pixel min = procesadorEstadistico.minimo();
    Pixel pixelAux;
    int componente0, componente1, componente2;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f, c);

            componente0 = (pixelAux.devolverComponente(0) - min.devolverComponente(0))/
                          (max.devolverComponente(0) - min.devolverComponente(0))*M;

            componente1 = (pixelAux.devolverComponente(1) - min.devolverComponente(1))/
                          (max.devolverComponente(1) - min.devolverComponente(1))*M;

            componente2 = (pixelAux.devolverComponente(2) - min.devolverComponente(2))/
                          (max.devolverComponente(2) - min.devolverComponente(2))*M;

            pixelAux.definirPixel(componente0, componente1, componente2);

            ptrImagen->setPixel(f, c, pixelAux);
        }
    }
}

void Editor::disminuirContraste()
{
    procesadorEstadistico.setPtrImagen(ptrImagen);
    int M = ptrImagen->getRangoDinamico();
    Pixel max = procesadorEstadistico.maximo();
    Pixel min = procesadorEstadistico.minimo();
    Pixel pixelAux;
    int componente0, componente1, componente2;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f, c);

            componente0 = pixelAux.devolverComponente(0) *
                          (max.devolverComponente(0) - min.devolverComponente(0))/
                          M + min.devolverComponente(0);

            componente1 = pixelAux.devolverComponente(0) *
                          (max.devolverComponente(0) - min.devolverComponente(0))/
                          M + min.devolverComponente(0);

            componente2 = pixelAux.devolverComponente(0) *
                          (max.devolverComponente(0) - min.devolverComponente(0))/
                          M + min.devolverComponente(0);

            pixelAux.definirPixel(componente0, componente1, componente2);

            ptrImagen->setPixel(f, c, pixelAux);
        }
    }
}

void Editor::negativo()
{
    int M = ptrImagen->getRangoDinamico();
    Pixel pixelAux;

    for (int f=0; f<ptrImagen->getFilas(); f++)
    {
        for (int c=0; c<ptrImagen->getColumnas(); c++)
        {
            pixelAux = ptrImagen->getPixel(f,c);

            pixelAux.definirComponente(0, M-pixelAux.getComponente0());
            pixelAux.definirComponente(1, M-pixelAux.getComponente1());
            pixelAux.definirComponente(2, M-pixelAux.getComponente2());

            ptrImagen->setPixel(f, c, pixelAux);
        }
    }
}

void Editor::ecualizar()
{
    string codigo = ptrImagen->getCodigo();

    if (codigo == "P2" or codigo == "P5")
    {

    }
}
