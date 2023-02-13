#ifndef MEDIANA_H
#define MEDIANA_H
#include <imagen.h>
#include <filtro.h>
#include <procesadorestadistico.h>

/**
 * @brief Aplica el filtro de mediana.
 * @author Machado Joaquin
 */

class Mediana : public Filtro
{
public:
    /**
     * @brief Mediana Metodo constructor de la clase Mediana
     */
    Mediana();


    /**
     * @brief ~Mediana Metodo destructor de la clase Mediana
     */
    ~Mediana() override;
    /**
     * @brief aplicarFiltro Aplica el filtro de mediana
     * @param pImagen Imagen a la que se aplicara el filtro
     */
    void aplicarFiltro(Imagen &pImagen) override ;

private:
    ProcesadorEstadistico procesador; /**< Procesador estadistico para obtener el dato de mediana */
};

#endif // MEDIANA_H
