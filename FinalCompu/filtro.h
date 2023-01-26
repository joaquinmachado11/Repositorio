#ifndef FILTRO_H
#define FILTRO_H
#include <imagen.h>

class Filtro //filtradoEspacial
{
public:
    Filtro();
    virtual void aplicarFiltro(Imagen &pImagen) = 0;
};

#endif // FILTRO_H

/*
filtrado espacial serian:
 - Pasabajos o suavizado
 - Pasaaltos o realce de bordes
 - Mediana
*/
