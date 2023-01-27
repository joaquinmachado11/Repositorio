#include "algoritmopintor.h"

AlgoritmoPintor::AlgoritmoPintor()
{

}

void AlgoritmoPintor::setImagen(Imagen *pImagen)
{
    ptrImagen = pImagen;

    filas = ptrImagen->getFilas();
    columnas = ptrImagen->getColumnas();
    areaDetectada = 0;

    mascara.resize(filas, vector<bool>(columnas,false));
}

void AlgoritmoPintor::aplicarAlgoritmo(int posY, int posX)
{
    profundidad = 0;
    pixelABuscar = ptrImagen->getPixel(posX, posY);
    detectarArea(posY, posX);
    pintarArea();
}

void AlgoritmoPintor::detectarArea(int posY, int posX)
{
    profundidad++;
    if (profundidad < 5000 and estaEnLaImagen(posY, posX))
    {
        Pixel pixelAux = ptrImagen->getPixel(posX, posY);
        if (pixelABuscar == pixelAux and mascara[posY][posX] == false)
        {
            areaDetectada++;
            mascara[posY][posX] ==  true;
//            for (unsigned int i=0; i<8; i++)
//            {
//                detectarArea(posX+movimiento[i].x, posY+movimiento[i].y);
//            }
            /*detectarArea(posX-1, posY  );
            detectarArea(posX-1, posY+1);
            detectarArea(posX  , posY+1);
            detectarArea(posX+1, posY+1);
            detectarArea(posX+1, posY  );
            detectarArea(posX+1, posY-1);
            detectarArea(posX  , posY-1);
            detectarArea(posX-1, posY-1);*/

            detectarArea(posY-1, posX  );
            detectarArea(posY-1, posX+1);
            detectarArea(posY  , posX+1);
            detectarArea(posY+1, posX+1);
            detectarArea(posY+1, posX  );
            detectarArea(posY+1, posX-1);
            detectarArea(posY  , posX-1);
            detectarArea(posY-1, posX-1);
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
    //mascara.clear();
}

bool AlgoritmoPintor::estaEnLaImagen(int y, int x)
{
    return (x < filas and y < columnas and
            x >= 0 and y >= 0);
}
