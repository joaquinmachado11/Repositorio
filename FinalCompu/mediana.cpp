#include "mediana.h"

Mediana::Mediana()
{

}

Mediana::~Mediana()
{

}

void Mediana::aplicarFiltro(Imagen &pImagen)
{
    procesador.setPtrImagen(&pImagen);
    vector<Pixel> datos;
    Pixel pixelAux;
    Pixel nuevoPixel;

    for (int fila=0; fila<pImagen.getFilas(); fila++)
    {
        for (int columna = 0; columna<pImagen.getColumnas(); columna++)
        {
            for (int i=0; i<9; i++)
            {
                if (pImagen.estaEnLaImagen(fila+recorrido[i].f, columna+recorrido[i].c))
                {
                    pixelAux = pImagen.getPixel(fila+recorrido[i].f, columna+recorrido[i].c);
                    datos.push_back(pixelAux);
                }
            }
            nuevoPixel = procesador.mediana(datos);
            pImagen.setPixel(fila, columna, nuevoPixel);
        }
    }
}
