#include "lut.h"

LUT::LUT()
{

}

void LUT::setGestor(GestorDeArchivos *pGestor)
{
    ptrGestorDeArchivos = pGestor;
}

void LUT::aplicarLUT(int opcion, Imagen &pImagen)
{
    tablaLUT = ptrGestorDeArchivos->generarTablaLUT(opcion-1);

    Pixel pixelAux;
    int intensidad;

    for (int f=0; f<pImagen.getFilas(); f++)
    {
        for (int c=0; c<pImagen.getColumnas(); c++)
        {
            pixelAux = pImagen.getPixel(f,c);
            intensidad = pixelAux.devolverComponente(0);
            pixelAux = tablaLUT[intensidad];

            pImagen.setPixel(f,c,pixelAux);
        }
    }
}
