#ifndef ALGORITMOPINTOR_H
#define ALGORITMOPINTOR_H
#include <imagen.h>
#include <cmath>

using namespace std;

class AlgoritmoPintor
{
public:
    AlgoritmoPintor();
    void setImagen(Imagen *pImagen);

    void aplicarAlgoritmo(int posY, int posX);
    void detectarArea(int posY, int posX);
    void pintarArea();

    int getAreaDetectada() const;
    void reiniciarArea();

private:
    Imagen *ptrImagen;
    vector < vector <bool> > mascara;
    int filas, columnas;
    int areaDetectada;
    int profundidad;
    int tolerancia;
    Pixel pixelABuscar;

    bool estaEnLaImagen(int x, int y);
    bool dentroDeTolerancia(Pixel &pixAComparar);
};

struct Posicion
{ int y, x; };
const vector < Posicion > movimiento=
{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#endif // ALGORITMOPINTOR_H


