#ifndef FILTRO_H
#define FILTRO_H
#include <imagen.h>

class Filtro //filtradoEspacial
{
public:
    Filtro();
    virtual ~Filtro();
    virtual void aplicarFiltro(Imagen &pImagen) = 0;
};

struct Espacio
{ int f, c; };
const vector < Espacio > recorrido=
{{0,0},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#endif // FILTRO_H

/*
filtrado espacial serian:
 - Pasabajos o suavizado
 - Pasaaltos o realce de bordes
 - Mediana
*/
