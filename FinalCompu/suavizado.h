#ifndef SUAVIZADO_H
#define SUAVIZADO_H
#include <imagen.h>
#include <filtro.h>

/**
 * @brief Aplica el filtro de suavizado.
 * @author Machado Joaquin
 */

class Suavizado : public Filtro
{
public:
    /**
     * @brief Suavizado Metodo constructor de la clase Suavizado
     */
    Suavizado();

    /**
     * @brief ~Suavizado Metodo destructor de la clase Suavizado
     */
    ~Suavizado() override;

    /**
     * @brief aplicarFiltro Aplica el filtro de suavizado
     * @param pImagen Imagen a la que se aplicara el filtro
     */
    void aplicarFiltro(Imagen &pImagen) override;

private:
    vector < float > kernel3p3;  /**< Kernel de filtrado */
};

#endif // SUAVIZADO_H
