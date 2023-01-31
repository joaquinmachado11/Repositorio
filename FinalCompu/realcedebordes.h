#ifndef REALCEDEBORDES_H
#define REALCEDEBORDES_H
#include <filtro.h>
#include <imagen.h>

class RealceDeBordes : public Filtro
{
public:
    RealceDeBordes();
    ~RealceDeBordes() override;
    void aplicarFiltro(Imagen &pImagen) override;

private:
    vector <int> kernel3p3;
};


#endif // REALCEDEBORDES_H
