#ifndef SUAVIZADO_H
#define SUAVIZADO_H
#include <imagen.h>
#include <filtro.h>

class Suavizado : public Filtro
{
public:
    Suavizado();
    ~Suavizado() override;
    void aplicarFiltro(Imagen &pImagen) override;

private:
    vector < float > kernel3p3;
};

#endif // SUAVIZADO_H
