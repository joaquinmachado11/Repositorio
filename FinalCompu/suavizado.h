#ifndef SUAVIZADO_H
#define SUAVIZADO_H
#include <imagen.h>
#include <filtro.h>

class Suavizado : public Filtro
{
public:
    Suavizado();
    void aplicarFiltro(Imagen &pImagen) override{};
};

#endif // SUAVIZADO_H
