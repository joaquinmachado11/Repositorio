#ifndef MEDIANA_H
#define MEDIANA_H
#include <imagen.h>
#include <filtro.h>
#include <procesadorestadistico.h>

class Mediana : public Filtro
{
public:
    Mediana();
    ~Mediana() override;
    void aplicarFiltro(Imagen &pImagen) override ;

private:
    ProcesadorEstadistico procesador;
};

#endif // MEDIANA_H
