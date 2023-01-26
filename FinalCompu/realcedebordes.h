#ifndef REALCEDEBORDES_H
#define REALCEDEBORDES_H
#include <filtro.h>

class RealceDeBordes : public Filtro
{
public:
    RealceDeBordes();
    void aplicarFiltro(Imagen &pImagen) override;
};

#endif // REALCEDEBORDES_H
