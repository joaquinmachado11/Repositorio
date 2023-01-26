#ifndef MEDIANA_H
#define MEDIANA_H
#include <imagen.h>
#include <filtro.h>

class Mediana : public Filtro
{
public:
    Mediana();
    void aplicarFiltro(Imagen &pImagen) override;
};

#endif // MEDIANA_H
