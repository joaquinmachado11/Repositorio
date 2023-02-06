#ifndef REALCEDEBORDES_H
#define REALCEDEBORDES_H
#include <filtro.h>
#include <imagen.h>

/**
 * @brief Aplica el filtro de realce de bordes.
 * @author Machado Joaquin
 */

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
