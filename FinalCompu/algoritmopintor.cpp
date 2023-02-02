#include "algoritmopintor.h"

AlgoritmoPintor::AlgoritmoPintor()
{

}

void AlgoritmoPintor::setImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;

    filas = ptrImagen->getFilas();
    columnas = ptrImagen->getColumnas();

    mascara.clear();
    mascara.resize(filas, vector<bool>(columnas,false));
}

void AlgoritmoPintor::aplicarAlgoritmo(int posY, int posX)
{
    areaDetectada = 0;
    profundidad = 0;

    if (ptrImagen->getCodigo() == "P1" or ptrImagen->getCodigo() == "P4")
    {
        tolerancia = 0;
    }
    else
    {
        tolerancia = 10;
    }

    pixelABuscar = ptrImagen->getPixel(posY, posX);
    detectarArea(posY, posX);
    pintarArea();
}

void AlgoritmoPintor::detectarArea(int posY, int posX)
{
    // posY == filas
    // posX == columnas
    profundidad++;
    if (profundidad < 50000 and ptrImagen->estaEnLaImagen(posY, posX))
    {
        Pixel pixelAux = ptrImagen->getPixel(posY, posX);
        if (mascara[posY][posX] == false and dentroDeTolerancia(pixelAux))
        {
            areaDetectada++;
            mascara[posY][posX] =  true;
            for (unsigned int i=0; i<8; i++)
            {
                detectarArea(posY+movimiento[i].y, posX+movimiento[i].x);
            }
        }
    }
    profundidad--;
}

void AlgoritmoPintor::pintarArea() //255,128,0
{
    Pixel pixelResaltado(255,128,0);
    for (int f=0; f<filas; f++)
    {
        for (int c=0; c<columnas; c++)
        {
            if (mascara[f][c] == true)
                ptrImagen->setPixel(f, c, pixelResaltado);
        }
    }
}

int AlgoritmoPintor::getAreaDetectada() const
{
    return areaDetectada;
}

void AlgoritmoPintor::reiniciarArea()
{
    areaDetectada = 0;
}

bool AlgoritmoPintor::dentroDeTolerancia(Pixel &pixAComparar)
{
    int dif0, dif1, dif2;
    dif0 = sqrt((pixelABuscar.devolverComponente(0) - pixAComparar.devolverComponente(0)) * (pixelABuscar.devolverComponente(0) - pixAComparar.devolverComponente(0)));
    dif1 = sqrt((pixelABuscar.devolverComponente(1) - pixAComparar.devolverComponente(1)) * (pixelABuscar.devolverComponente(1) - pixAComparar.devolverComponente(1)));
    dif2 = sqrt((pixelABuscar.devolverComponente(2) - pixAComparar.devolverComponente(2)) * (pixelABuscar.devolverComponente(2) - pixAComparar.devolverComponente(2)));

    return (dif0 <= tolerancia and dif1 <= tolerancia and dif2 <= tolerancia);
}
