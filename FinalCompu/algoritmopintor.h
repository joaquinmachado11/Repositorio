#ifndef ALGORITMOPINTOR_H
#define ALGORITMOPINTOR_H
#include <imagen.h>

using namespace std;

class AlgoritmoPintor
{
public:
    AlgoritmoPintor();
    void setImagen(Imagen *pImagen);

    void aplicarAlgoritmo(int posX, int posY);
    void detectarArea(int posX, int posY);
    void pintarArea();

    int getAreaDetectada() const;
    void reiniciarArea();

private:
    Imagen *ptrImagen;
    vector < vector <bool> > mascara;
    int filas, columnas;
    int areaDetectada;
    int profundidad;
    Pixel pixelABuscar;

    bool estaEnLaImagen(int x, int y);
};

struct Posicion
{ int x, y; };
const vector < Posicion > movimiento=
{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#endif // ALGORITMOPINTOR_H


